void drawBox() {
	float div_increment_x = x / div;
	float div_increment_y = y / div;
	float div_increment_z = y / div;

	x = x / 2;
	y = y / 2;
	z = z / 2;



	for (int i = 0; i < div; i++) {
		for (int j = 0; j < div; j++) {
			//up
			Point* a = new Point(-x + (div_increment_x * i), y, -z + (div_increment_z * j)); //A
			points->push_back(a);
			Point* b = new Point(-x + (div_increment_x * i), y, -z + (div_increment_z * (j + 1))); //B
			points->push_back(b);
			Point* c = new Point(-x + (div_increment_x * (i + 1)), y, -z + (div_increment_z * j)); //C
			points->push_back(c);
			Point* d = new Point(-x + (div_increment_x * (i + 1)), y, -z + (div_increment_z * j)); //C
			points->push_back(d);
			Point* e = new Point(-x + (div_increment_x * i), y, -z + (div_increment_z * (j + 1))); //B
			points->push_back(e);
			Point* f = new Point(-x + (div_increment_x * (i + 1)), y, -z + (div_increment_z * (j + 1))); //D
			points->push_back(f);

			// down
			Point* a2 = new Point(-x + (div_increment_x * i), -y, -z + (div_increment_z * j)); //A
			points->push_back(a2);
			Point* b2 = new Point(-x + (div_increment_x * (i + 1)), -y, -z + (div_increment_z * j)); //C
			points->push_back(b2);
			Point* c2 = new Point(-x + (div_increment_x * i), -y, -z + (div_increment_z * (j + 1))); //B
			points->push_back(c2);
			Point* d2 = new Point(-x + (div_increment_x * i), -y, -z + (div_increment_z * (j + 1))); //B
			points->push_back(d2);
			Point* e2 = new Point(-x + (div_increment_x * (i + 1)), -y, -z + (div_increment_z * j)); //C
			points->push_back(e2);
			Point* f2 = new Point(-x + (div_increment_x * (i + 1)), -y, -z + (div_increment_z * (j + 1))); //D
			points->push_back(f2);

			// right:
			Point* a3 = new Point(x, -y + (div_increment_y * i), -z + (div_increment_z * j)); //D
			points->push_back(a3);
			Point* b3 = new Point(x, -y + (div_increment_y * (i + 1)), -z + (div_increment_z * j)); //C
			points->push_back(b3);
			Point* c3 = new Point(x, -y + (div_increment_y * i), -z + (div_increment_z * (j + 1))); //B
			points->push_back(c3);
			Point* d3 = new Point(x, -y + (div_increment_y * i), -z + (div_increment_z * (j + 1))); //B
			points->push_back(d3);
			Point* e3 = new Point(x, -y + (div_increment_y * (i + 1)), -z + (div_increment_z * j)); //C
			points->push_back(e3);
			Point* f3 = new Point(x, -y + (div_increment_y * (i + 1)), -z + (div_increment_z * (j + 1))); //A
			points->push_back(f3);

			// left
			Point* a4 = new Point(-x, -y + (div_increment_y * i), -z + (div_increment_z * j)); //D
			points->push_back(a4);
			Point* b4 = new Point(-x, -y + (div_increment_y * i), -z + (div_increment_z * (j + 1))); //B
			points->push_back(b4);
			Point* c4 = new Point(-x, -y + (div_increment_y * (i + 1)), -z + (div_increment_z * j)); //C
			points->push_back(c4);
			Point* d4 = new Point(-x, -y + (div_increment_y * (i + 1)), -z + (div_increment_z * j)); //C
			points->push_back(d4);
			Point* e4 = new Point(-x, -y + (div_increment_y * i), -z + (div_increment_z * (j + 1))); //B
			points->push_back(e4);
			Point* f4 = new Point(-x, -y + (div_increment_y * (i + 1)), -z + (div_increment_z * (j + 1))); //A
			points->push_back(f4);

			// front
			Point* a5 = new Point(-x + (div_increment_x * i), -y + (div_increment_y * i), z); //C
			points->push_back(a5);
			Point* b5 = new Point(-x + (div_increment_x * (i + 1)), -y + (div_increment_y * i), z); //D
			points->push_back(b5);
			Point* c5 = new Point(-x + (div_increment_x * i), -y + (div_increment_y * (i + 1)), z); //A
			points->push_back(c5);
			Point* d5 = new Point(-x + (div_increment_x * i), -y + (div_increment_y * (i + 1)), z); //A
			points->push_back(d5);
			Point* e5 = new Point(-x + (div_increment_x * (i + 1)), -y + (div_increment_y * i), z); //D
			points->push_back(e5);
			Point* f5 = new Point(-x + (div_increment_y * (i + 1)), -y + (div_increment_z * (j + 1)), z); //B
			points->push_back(f5);

			// back
			Point* a6 = new Point(-x + (div_increment_x * i), -y + (div_increment_y * i), -z); //C
			points->push_back(a6);
			Point* b6 = new Point(-x + (div_increment_x * i), -y + (div_increment_y * (i + 1)), -z); //A
			points->push_back(b6);
			Point* c6 = new Point(-x + (div_increment_x * (i + 1)), -y + (div_increment_y * i), -z); //D
			points->push_back(c6);
			Point* d6 = new Point(-x + (div_increment_x * (i + 1)), -y + (div_increment_y * i), -z); //D
			points->push_back(d6);
			Point* e6 = new Point(-x + (div_increment_x * i), -y + (div_increment_y * (i + 1)), -z); //A
			points->push_back(e6);
			Point* f6 = new Point(-x + (div_increment_y * (i + 1)), -y + (div_increment_z * (j + 1)), -z); //B
			points->push_back(f6);

		}
	}

}

void coneToFile(char* filename) {

	std::ofstream myfile;
	myfile.open(filename);
	drawBox();

	int vectorLenght = this->points->size();

	myfile << vectorLenght << std::endl;
	for (int i = 0; i < vectorLenght; i++) {
		myfile << *(*points)[i];
	}

	myfile.close();

}
