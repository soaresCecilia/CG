#include "../headers/bezierPatch.h"
#include <iostream>
#include <fstream>


#define _USE_MATH_DEFINES
#include <cmath>
#include <math.h>
#include <sstream>

void BezierPatch::getTrianglesToDraw(int nPatches, int** indicesPatches, int** pontosControlo) {

	std::ostringstream os;
	
	float incTesselation = 1 / tesselation;

	// colocar as contas

	// passar para o ficheiro os pontos resultantes das contas
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
			pontosControlo[i][j] = stoi(subString);
			std::cerr << "li o primeiro valor da substring : " << stoi(subString) << "\n";
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

	readInFile(&nPatches, &indices, &nPControl, &ptControl);

	//std::ofstream myfile;
	//myfile.open(outputFile);
	
}