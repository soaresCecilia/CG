
void drawPlane() {


	//est‡ ainda a divis‹o inteira
	Point* c = new Point(-dim / 2, 0.0f, dim / 2); /*1.¼ e œltimo*/
	Point* b = new Point(dim / 2, 0.0f, dim / 2);
	Point* a = new Point(dim / 2, 0.0f, -dim / 2); /*2x seguidas*/
	Point* d = new Point(-dim / 2, 0.0f, -dim / 2);


	//push_back - Add element at the end of the vector
	points->push_back(c);
	points->push_back(b);
	points->push_back(a);
	points->push_back(a);
	points->push_back(d);
	points->push_back(c);
}

void coneToFile(char* filename) {

	std::ofstream myfile;
	myfile.open(filename);
	drawPlane();

	int vectorLenght = this->points->size();

	myfile << vectorLenght << std::endl;
	for (int i = 0; i < vectorLenght; i++) {
		myfile << *(*points)[i];
	}

	myfile.close();

}
