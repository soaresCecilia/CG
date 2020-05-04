#include "../headers/bezierPatch.h"
#include <iostream>
#include <fstream>


#define _USE_MATH_DEFINES
#include <cmath>
#include <math.h>
#include <sstream>


void multMatrixVector(float* m, float* v, float* res) {

	for (int j = 0; j < 4; ++j) {
		res[j] = 0;
		for (int k = 0; k < 4; ++k) {
			res[j] += v[k] * m[j * 4 + k];
		}
	}

}

void multVectorMatrix(float* v, float* m, float* res) {

	for (int j = 0; j < 4; ++j) {
		res[j] = 0;
		for (int k = 0; k < 4; ++k) {
			res[j] += v[k] * m[k * 4 + j];
		}
	}

}

void multPointsVector(float points[4][4][4], float* v, float res[4][4]) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				res[i][k] += points[i][j][k] * v[j];
			}
		}
	}
}

void multVectorPoints(float* v, float points[4][4], float res[4]) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			res[i] += points[j][i] * v[j];
		}
	}
}

void BezierPatch ::  calcPoint(float pts[4][4][4], float u, float v, int ts) {

	// bezier matrix
	float m[4][4] = { {-1.0f,  3.0f, -3.0f,  1.0f},
					  { 3.0f, -6.0f,  3.0f,  0.0f},
					  {-3.0f,  3.0f,  0.0f,  0.0f},
					  { 1.0f,  0.0f,  0.0f,  0.0f} };

	float U[4] = { powf(u,3), powf(u,2), u, 1 };
	float V[4] = { powf(v,3), powf(v,2), v, 1 };


	float vecRes1[4] = { 0,0,0,1 };
	float vecRes2[4][4] = { {0,0,0,1},{0,0,0,1},{0,0,0,1},{0,0,0,1} };
	float vecRes3[4] = { 0,0,0,1 };
	float point[4] = { 0,0,0,1 };

	multMatrixVector(*m, V, vecRes1);
	multPointsVector(pts, vecRes1, vecRes2);
	multVectorMatrix(U, *m, vecRes3);
	multVectorPoints(vecRes3, vecRes2, point);

	//Point 
	float x = (point[0]);
	float y = (point[1]);
	float z = (point[2]);
	Point *a = new Point(x, y, z);
	points.push_back(a);

}


void BezierPatch :: calcPoints2Write(float points[4][4][4], int ts) {

	float inc = (float)1.0f / (float)ts;
	for (int i = 0; i < ts; i++) {
		for (int j = 0; j < ts; j++) {
			float u = (float)inc * i;
			float v = (float)inc * j;

			calcPoint(points, u, v, ts);
			calcPoint(points, u, (v + inc), ts);
			calcPoint(points, (u + inc), (v + inc), ts);
			calcPoint(points, u, v, ts);
			calcPoint(points, (u + inc), (v + inc), ts);
			calcPoint(points, (u + inc), v, ts);

		}
	}
}

int BezierPatch :: drawBezier(int tessellation, int* nPatches, int* nPtsControl, int*** indicesPatches, float*** ptsControl) {

	int nrPoints2Write = ((tessellation) * (tessellation)*(*nPatches) * 6);

	//Calcula pontos e escreve
	for (int patch = 0; patch < (*nPatches); patch++) {
		float patchCtrlPoints[4][4][4];

		int p = 0;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				patchCtrlPoints[i][j][0] = (*ptsControl)[(*indicesPatches)[patch][p]][0];
				patchCtrlPoints[i][j][1] = (*ptsControl)[(*indicesPatches)[patch][p]][1];
				patchCtrlPoints[i][j][2] = (*ptsControl)[(*indicesPatches)[patch][p]][2];
				patchCtrlPoints[i][j][3] = 1;
				p++;
			}
		}

		calcPoints2Write(patchCtrlPoints, tessellation);

	}

	return nrPoints2Write;

}

void BezierPatch::readInFile(int* nPatches, int*** indicesPatches, int* nPtsControl, float*** ptsControl) {

	//abrir ficheiro e criar stream para ler do ficheiro
	std::ifstream infile;
	infile.open(inputFile);

	if (!infile) {
		std::cerr << "Cannot open input file.\n";
		exit(1);
	}

	std::cerr << "abri ficheiro\n";

	// ler numero de patch's
	std::string line;
	std::getline(infile, line);
	*nPatches = stoi(line);

	std::cerr << "li numero de patch que existem"<< *nPatches << "\n";
	// ler indices dos patches

	int** valIndPatches = new int* [*nPatches];


	for (int i = 0; i < *nPatches; i++) {
		valIndPatches[i] = new int[16];

		getline(infile, line);
		std::stringstream ss;
		ss.str(line);

		std::cerr << "comecei a ler os indices \n" << "indice :" << i <<"\n";
		
		for(int j=0; j<16;j++){

			std::string subString;
			getline(ss, subString, ',');

			std::cerr << "li o primeiro valor da substring : " << stoi(subString) << "\n" ;
			
			valIndPatches[i][j] = stoi(subString);
			std::cerr << "coloquei bem\n";
			
		}

		std::cerr << "sai do ciclo de leitrua da linha de cada patch\n";
	}

	*indicesPatches = valIndPatches;

	std::cerr << "Vou comecar a ler os potnso de controlo \n";
	//numero de pontos de controlo
	std::getline(infile, line);
	*nPtsControl = stoi(line);
	std::cerr << "N pontos controlo: "<< *nPtsControl << "\n";
	float** pontosControlo = new float* [*nPtsControl];

	//lê numero de pontos de controlo
	for (int i = 0; i < *nPtsControl; i++) {

		pontosControlo[i] = new float[3];

		getline(infile, line);
		std::stringstream ss;
		ss.str(line);

		for (int j = 0; j < 3; j++) {
			std::string subString;
			getline(ss, subString, ',');
			pontosControlo[i][j] = stof(subString);
			std::cerr << "li o primeiro valor da substring : " << stof(subString) << "\n";
			std::cerr << "coloquei bem\n";
		}
		std::cerr << "sai do ciclo de leitrua da linha de cada ponto controlo\n";
	}
	std::cerr << "sai do ciclo de leitrua dos pontos controlo\n";
	*ptsControl = pontosControlo;

	infile.close();

	std::cerr << "Leitura do ficheiro esta OK.\n";
}

void BezierPatch :: curveToFile(){
	int nPatches, nPControl;
	int** indices;
	float** ptControl;
	int nr;
	readInFile(&nPatches, &indices, &nPControl, &ptControl);
	
	std::ofstream myfile;

	myfile.open(outputFile);
	nr = drawBezier(tesselation, &nPatches, &nPControl, &indices, &ptControl);
	int vectorLenght = this->points.size();

	myfile << nr << std::endl;
	for (int i = 0; i < vectorLenght; i++) {
		myfile << *(points[i]) ;
	}

	myfile.close();
	
}