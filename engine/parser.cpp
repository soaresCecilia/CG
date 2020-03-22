#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <random>
#include <cstdio>


#include "../headers/parser.h"
#include "../headers/FormaGeo.h"
#include "../headers/group.h"
#include "../headers/tinyxml2.h"
#include "../headers/point.h"
#include "../headers/Operation.h"
#include "../headers/translation.h"
#include "../headers/rotation.h"

using namespace tinyxml2;
using namespace std;

FormaGeo * parseFile(const XMLElement *);
Translation * parseTranslate(XMLElement *pElement);
Rotation* parseRotate(XMLElement *pElement);

Parser::Parser() {
}

void parseDoc(Group *ptrGroup, XMLNode *ptrN) {
    //Aqui estou no translate
    XMLNode *ptrNode = ptrN->FirstChild();

        if (ptrNode == nullptr)
                exit(0);

        for (; ptrNode; ptrNode = ptrNode->NextSibling()) {
            XMLElement *ptrElement = ptrNode->ToElement();
            
            if (!strcmp(ptrElement->Name(), "group")) {
                Group *newGroup = new Group();
                parseDoc(newGroup, ptrNode);
                ptrGroup->addGroup(newGroup);
            }
            
    
            if (!strcmp(ptrElement->Name(), "translate")) {
                    Translation *trans = parseTranslate(ptrElement);
                    ptrGroup->saveOperation(trans);
            }
            

            if (!strcmp(ptrElement->Name(), "models")) {
                parseDoc(ptrGroup, ptrNode);
            }
            
            if (!strcmp(ptrElement->Name(), "model")) {
                if (ptrElement->Attribute("file")) {
                        FormaGeo *formageo = parseFile(ptrElement);
                        formageo->buffering();
                        ptrGroup->addFormaGeo(formageo);
                }
            }

			if (!strcmp(ptrElement->Name(), "rotate")) {
				Rotation* rot = parseRotate(ptrElement);
				ptrGroup->saveOperation(rot);
			}

        }

}

void Parser::ReadXML(Group *ptrGroup, const char *xml) {
        XMLDocument xmlDoc;
        XMLError result = xmlDoc.LoadFile(xml);

        if (result != XML_SUCCESS) {
                cerr << "Error:" << result << endl;
                exit(1);
        }

        //Aqui estou no scene
        XMLNode *ptrRoot = xmlDoc.FirstChild();

        if (ptrRoot == nullptr) {
                cout << "Warning: Malformed XML file" << endl;
                exit(1);
        }
        else {
           /*
            //Aqui estou no group
            XMLNode *ptrNode = ptrRoot->FirstChild();
            
            if (ptrNode == nullptr) {
                cerr << "Warning: No models found" << endl;
                exit(1);
            }
            else
            */
                parseDoc(ptrGroup, ptrRoot);
        }
}


FormaGeo * parseFile(const XMLElement *ptrElement) {
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

Translation * parseTranslate(XMLElement *ptrElement) {
    float x = 0, y = 0, z = 0;
    
    if (ptrElement->Attribute("x"))
        tinyxml2::XMLUtil::ToFloat(ptrElement->Attribute("x"), &x);
    
    if (ptrElement->Attribute("y"))
        tinyxml2::XMLUtil::ToFloat(ptrElement->Attribute("y"), &y);
    
    if (ptrElement->Attribute("z"))
        tinyxml2::XMLUtil::ToFloat(ptrElement->Attribute("z"), &z);


    Translation *trans = new Translation(new Point(x, y, z));
    return trans;
}

Rotation* parseRotate(XMLElement* ptrElement) {
	float angle = 0, x = 0, y = 0, z = 0;

	if (ptrElement->Attribute("angle"))
		tinyxml2::XMLUtil::ToFloat(ptrElement->Attribute("angle"), &angle);

	if (ptrElement->Attribute("x"))
		tinyxml2::XMLUtil::ToFloat(ptrElement->Attribute("x"), &x);

	if (ptrElement->Attribute("y"))
		tinyxml2::XMLUtil::ToFloat(ptrElement->Attribute("y"), &y);

	if (ptrElement->Attribute("z"))
		tinyxml2::XMLUtil::ToFloat(ptrElement->Attribute("z"), &z);


	Rotation* rot = new Rotation(new Point(x, y, z),angle);
	return rot;
}
