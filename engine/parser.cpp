
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <random>
#include <cstdio>


#include "../headers/parser.h"
#include "../headers/FormaGeo.h"
#include "../headers/nFormasGeo.h"
#include "../headers/tinyxml2.h"
#include "../headers/point.h"

using namespace tinyxml2;
using namespace std;

void parseDoc(nFormasGeo *, XMLNode *);
FormaGeo *parseFile(const XMLElement *);

Parser::Parser() {
}

void parseDoc(nFormasGeo *ptrFgeo, XMLNode *ptrN) {
    XMLNode *ptrNode = ptrN->FirstChild();

        if (ptrNode == nullptr)
                exit(0);

        for (; ptrNode; ptrNode = ptrNode->NextSibling()) {
            XMLElement *ptrElement = ptrNode->ToElement();

                if (!strcmp(ptrElement->Name(), "model")) {
                        if (ptrElement->Attribute("file")) {
                                FormaGeo *formageo = parseFile(ptrElement);
                                ptrFgeo->addFormaGeo(formageo);
                        }
                }
        }

}

void Parser::ReadXML(nFormasGeo *ptrFgeo, const char *xml) {
        XMLDocument xmlDoc;
        XMLError result = xmlDoc.LoadFile(xml);

        if (result != XML_SUCCESS) {
                cerr << "Error:" << result << endl;
                exit(1);
        }

        XMLNode *ptrRoot = xmlDoc.FirstChild();

        if (ptrRoot == nullptr) {
                cout << "Warning: Malformed XML file" << endl;
                exit(0);
        } else {
                parseDoc(ptrFgeo, ptrRoot);
        }
}


FormaGeo *parseFile(const XMLElement *ptrElement) {
        string namefile = ptrElement->Attribute("file");
        ifstream infile(namefile);
        float x, y, z;

        if (!infile) {
                cerr << "Cannot open input file.\n";
                exit(1);
        }

        string line;
        getline(infile, line);
        int nVertices = stoi(line);
    
        FormaGeo *formaGeo = new FormaGeo(nVertices);

        while (getline(infile, line)) {
            sscanf(line.c_str(),"(%f, %f, %f)", &x, &y, &z);
            formaGeo->addVertexPoint(new Point(x,y,z));
            printf("Saida %f, %f, %f\n", x, y, z);
        }
    
        infile.close();

        return formaGeo;
}

