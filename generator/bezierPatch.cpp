#include "../headers/bezierPatch.h"
#include <iostream>
#include <fstream>


#define _USE_MATH_DEFINES
#include <cmath>
#include <math.h>
#include <sstream>

void BezierPatch::getTrianglesToDraw(int nPatches, int* indicesPatches, int* pontosControlo) {

	std::ostringstream os;
	
	float incTesselation = 1 / tesselation;

	// colocar as contas

	// passar para o ficheiro os pontos resultantes das contas
}

void BezierPatch::generateCurve() {

	//abrir ficheiro e criar stream para ler do ficheiro
	std::ifstream infile;
	infile.open(filenameIn);

	if (!infile) {
		std::cerr << "Cannot open input file.\n";
		exit(1);
	}

	// ler numero de patch's
	std::string line;
	std::getline(infile, line);
	int nPatches = stoi(line);

	// ler indices dos patches
	int indicesPatches[nPatches][16];

	for (int i = 0; i < nPatches; i++) {

		getline(infile, line);
		std::stringstream ss;
		ss.str(line);
		
		for(int j=0; j<16;j++){
			std::string subString;
			getline(ss, subString, ',');
			indicesPatches[i][j] = stoi(subString);
		}

	}


	//numero de pontos de controlo
	std::getline(infile, line);
	int nPontosControlo = stoi(line);

	//lê numero de pontos de controlo

	int pontosControlo[nPontosControlo][3];

	for (int i = 0; i < nPontosControlo; i++) {

		getline(infile, line);
		std::stringstream ss;
		ss.str(line);

		for (int j = 0; j < 3; j++) {
			std::string subString;
			getline(ss, subString, ',');
			pontosControlo[i][j] = stoi(subString);
		}

	}

	//teste
	for (int i = 0; i < nPatches; i++) {

		for(int j=0;j<16;j++)
			std::cout << indicesPatches[i][j];
	}

	for (int i = 0; i < nPontosControlo; i++) {

		for (int j = 0; j < 3; j++)
			std::cout << pontosControlo[i][j];
	}

	infile.close();

	getTrianglesToDraw(nPatches, indicesPatches, pontosControlo );
}

void BezierPatch :: curveToFile(){

	std::ofstream myfile;
	myfile.open(filenameOut);
	generateCurve();
}