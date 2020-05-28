#include "../headers/cone.h"
#include "../headers/point.h"
#include <iostream>
#include <fstream>


#define _USE_MATH_DEFINES
#include <cmath>
#include <math.h>

void Cone::generateCone() {


	const float _alpha = (2 * M_PI) / slices;  //angulo de cada slice
	float alpha = 0.0;                         // angulo acumulativo a cada interacao

	float px_base;					           // ponto x a partir de um ponto e um angulo para base
	float pz_base;							   // ponto z a partir de um ponto e de um angulo para base		

	float px_base_ant = 0.0;                   // ponto anterior para saber o px
	float pz_base_ant = radius;                // ponto anterior para saber o pz

	float const _stack = height / stacks;      // a altura de cada stack

	const float theta = radius / stacks; // valor do raio a cada stack, começando por cima

	std::vector<float> normalDownV{ 0.0f, -1.0f, 0.0f };  //vetor normal da base
	std::vector<float> vector{ 0,0,0 };
	int k = stacks;
	for (int i = 0; i < stacks; i++) {// y
		for (int j = 0; j < slices; j++) {//x
			
			alpha = _alpha * (j + 1);

			px_base = radius * sin(alpha);
			pz_base = radius * cos(alpha);

			float px = (radius - (theta * i)) * sin(_alpha * j);
			float pz = (radius - (theta * i)) * cos(_alpha * j);


			float incTex = 0.5 / stacks;


			float buscaXAntCima = 0.5 + (incTex * (k - 1)) * cosf(_alpha * j);
			float buscaYAntCima = 0.5 + (incTex * (k - 1)) * sinf(_alpha * j);
			float buscaXAnt = 0.5 + (incTex * (k)) * cosf(_alpha * j);
			float buscaYAnt = 0.5 + (incTex * k) * sinf(_alpha * (j));
			float buscaX = (0.5) + (incTex * k) * cosf(_alpha * (j + 1));
			float buscaY = 0.5 + (incTex * k) * sinf(_alpha * (j + 1));
			float buscaXCima = 0.5 + (incTex * (k - 1)) * cosf(_alpha * (j + 1));
			float buscaYCima = 0.5 + (incTex * (k - 1)) * sinf(_alpha * (j + 1));
			
			if (!i) {
				// desenhar a base;
               

				Point* d = new Point(px_base_ant, 0.0, pz_base_ant,normalDownV,0.5 +0.5*cosf(_alpha*j),0.5+0.5*sinf(_alpha*j));
				points.push_back(d);

				Point* e = new Point(0.0, 0.0, 0.0,normalDownV,0.5,0.5);
				points.push_back(e);


				Point* f = new Point(px_base, 0.0, pz_base,normalDownV, 0.5 + 0.5 * cosf(_alpha * (j + 1)) , 0.5 + 0.5 * sinf( _alpha * ( j + 1)));
				points.push_back(f);
			}

			if (i == stacks - 1) {
				// desenhar a ultima stack, que é so um triangulo
				
				Point* a = new Point(0.0, height, 0.0,vector,0.5,0.5);
				a->normalizeCoordPoint();
				points.push_back(a);

				Point* b = new Point((radius - (theta * i)) * sin(_alpha * j), i * _stack, (radius - (theta * i)) * cos(_alpha * j),vector,buscaXAnt,buscaYAnt);
				b->normalizeCoordPoint();
				points.push_back(b);


				Point* c = new Point((radius - (theta * i)), i * _stack, (radius - (theta * i)) * cos(_alpha * (j + 1)),vector,buscaX,buscaY);
				c->normalizeCoordPoint();
				points.push_back(c);
			}

			else {
				// desenhar a ultima stack, que é so um triangulo
				
				
				//A
				Point* g = new Point((radius - (theta * i)) * sin(_alpha * j), i * _stack, (radius - (theta * i)) * cos(_alpha * j), vector,buscaXAnt , buscaYAnt);
				g->normalizeCoordPoint();
				points.push_back(g);
				//D
				Point* h = new Point((radius - (theta * (i))) * sin(_alpha * (j + 1)), i * _stack, (radius - (theta * (i))) * cos(_alpha * (j + 1)), vector, buscaX, buscaY);
				h->normalizeCoordPoint();
				points.push_back(h);
				//c
				Point* k = new Point((radius - (theta * (i + 1))) * sin(_alpha * (j + 1)), (i + 1) * _stack, (radius - (theta * (i + 1))) * cos(_alpha * (j + 1)), vector, buscaXCima, buscaYCima);
				k->normalizeCoordPoint();
				points.push_back(k);


				//c
			//	Point* l = new Point((radius - (theta * (i + 1))) * sin(_alpha * (j + 1)), (i + 1) * _stack, (radius - (theta * (i + 1))) * cos(_alpha * (j + 1)), vector, 0, 0);
			//	l->normalizeCoordPoint();
				points.push_back(k);
				//B
				Point* m = new Point((radius - (theta * (i + 1))) * sin(_alpha * (j)), (i + 1) * _stack, (radius - (theta * (i+1))) * cos(_alpha * (j)), vector, buscaXAntCima, buscaYAntCima);
				m->normalizeCoordPoint();
				points.push_back(m);
				//A
			//	Point* n = new Point((radius - (theta * i)) * sin(_alpha * j), i * _stack, (radius - (theta * i)) * cos(_alpha * j), vector, 0, 0);
			//	n->normalizeCoordPoint();
				points.push_back(g);
				k--;
			}

			float px_ant = px;
			float pz_ant = pz;


			px_base_ant = px_base;
			pz_base_ant = pz_base;
		}
	}
}

void Cone::coneToFile(char* filename) {

	std::ofstream myfile;
	myfile.open(filename);
	generateCone();

	int vectorLenght = this->points.size();

	myfile << vectorLenght << std::endl;
	for (int i = 0; i < vectorLenght; i++) {
		myfile << *(points[i]);
	}

	myfile.close();

}
