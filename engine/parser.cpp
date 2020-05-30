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
#include "../headers/scale.h"
#include "../headers/color.h"
#include "../headers/catmull.h"
#include "../headers/lights.h"


using namespace tinyxml2;
using namespace std;

FormaGeo * parseFile(const XMLElement *);
Translation * parseTranslate(XMLElement *pElement);
Rotation* parseRotate(XMLElement *pElement);
Scale* parseScale(XMLElement* pElement);
Color* parseColor(XMLElement* pElement);
Catmull* parseCatmull(XMLElement *ptrElement);
Lights *parseLight(XMLElement *ptrElement);


Parser::Parser() {
}

void parseDoc(Group *ptrGroup, XMLNode *ptrN) {
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
            
            
            if (!strcmp(ptrElement->Name(), "color")) {
                Color *cor = parseColor(ptrElement);
                ptrGroup->saveOperation(cor);
            }
            
            
            if (!strcmp(ptrElement->Name(), "translate")) {
                if (ptrElement->Attribute("time")) {
                    Catmull *catm = parseCatmull(ptrElement);
                    ptrGroup->saveOperation(catm);
                } else {
                    Translation *trans = parseTranslate(ptrElement);
                    ptrGroup->saveOperation(trans);
                }
            }

            
            if (!strcmp(ptrElement->Name(), "rotate")) {
                Rotation* rot = parseRotate(ptrElement);
                ptrGroup->saveOperation(rot);
            }

           
			if (!strcmp(ptrElement->Name(), "scale")) {
				Scale* scal = parseScale(ptrElement);
				ptrGroup->saveOperation(scal);
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
            
            /*
            if (!strcmp(ptrElement->Name(), "light")) {
                Lights *light = parseLight(ptrElement);
                //ptrGroup->addLight(light);
            }
            */
        }

}

void Parser::ReadXML(Group *ptrGroup, const char *xml) {
        XMLDocument xmlDoc;
        XMLError result = xmlDoc.LoadFile(xml);

        if (result != XML_SUCCESS) {
                cerr << "Error:" << result << endl;
                exit(1);
        }

    
        XMLNode *ptrRoot = xmlDoc.FirstChild();

        if (ptrRoot == nullptr) {
                cout << "Warning: Malformed XML file" << endl;
                exit(1);
        }
        else {
        
                parseDoc(ptrGroup, ptrRoot);
        }
}


FormaGeo * parseFile(const XMLElement *ptrElement) {
        string namefile = ptrElement->Attribute("file");
        ifstream infile(namefile);
        float x, y, z, xl, yl, zl, xt, yt;
        

        if (!infile) {
                cerr << "Cannot open input file.\n";
                exit(1);
        }

        string line;
        getline(infile, line);
        int nVertices = stoi(line);
    
        FormaGeo *formaGeo = new FormaGeo(nVertices);

        while (getline(infile, line)) {
            sscanf(line.c_str(),"(%f, %f, %f, %f, %f, %f, %f, %f)", &x, &y, &z, &xl, &yl, &zl, &xt, &yt);
            printf("li o ponto: %f,%f,%f, %f,%f,%f, %f,%f\n", x, y, z, xl, yl, zl, xt, yt);
            Point p(x,y,z,xl,yl,zl,xt,yt);
  
            formaGeo->addCoordinates(p);
            formaGeo->addLigthNormals(p);
            formaGeo->addVerticesTexture(p);

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
	float angle = 0, x = 0, y = 0, z = 0, time = 0;

	if (ptrElement->Attribute("angle"))
		tinyxml2::XMLUtil::ToFloat(ptrElement->Attribute("angle"), &angle);

	if (ptrElement->Attribute("axisX"))
		tinyxml2::XMLUtil::ToFloat(ptrElement->Attribute("x"), &x);

	if (ptrElement->Attribute("axisY"))
		tinyxml2::XMLUtil::ToFloat(ptrElement->Attribute("y"), &y);

	if (ptrElement->Attribute("axisZ"))
		tinyxml2::XMLUtil::ToFloat(ptrElement->Attribute("z"), &z);

    if(ptrElement->Attribute("time"))
        time = fabs(stof(ptrElement->Attribute("time")));

	Rotation* rot = new Rotation(new Point(x, y, z),angle, time);
	return rot;
}




Scale* parseScale(XMLElement* ptrElement) {
	float x = 0, y = 0, z = 0;

	if (ptrElement->Attribute("x"))
		tinyxml2::XMLUtil::ToFloat(ptrElement->Attribute("x"), &x);

	if (ptrElement->Attribute("y"))
		tinyxml2::XMLUtil::ToFloat(ptrElement->Attribute("y"), &y);

	if (ptrElement->Attribute("z"))
		tinyxml2::XMLUtil::ToFloat(ptrElement->Attribute("z"), &z);


	Scale* scal = new Scale(new Point(x, y, z));
	return scal;
}



Color* parseColor(XMLElement* ptrElement) {
    float r = 0, g = 0, b = 0;
    
    if (ptrElement->Attribute("R"))
    tinyxml2::XMLUtil::ToFloat(ptrElement->Attribute("R"), &r);
    
    if (ptrElement->Attribute("G"))
    tinyxml2::XMLUtil::ToFloat(ptrElement->Attribute("G"), &g);
    
    if (ptrElement->Attribute("B"))
    tinyxml2::XMLUtil::ToFloat(ptrElement->Attribute("B"), &b);
        
    Color* cor = new Color(new Point(r, g, b));
    
    return cor;
}


Catmull* parseCatmull(XMLElement *ptrElement) {
    Catmull *t = new Catmull() ;
    float time;
    
    if (ptrElement->Attribute("time")) {
        float time = fabs(stof(ptrElement->Attribute("time")));
        t->addTime(time);
    }
    
    XMLNode *ptrNodeFirst = ptrElement->FirstChild();
    float x = 0;
    float y = 0;
    float z = 0;
    
    for (; ptrNodeFirst; ptrNodeFirst = ptrNodeFirst->NextSibling()) {
        XMLElement *ptrElement1 = ptrNodeFirst->ToElement();
        
        if (!strcmp(ptrElement1->Name(), "point")) {
            if (ptrElement1->Attribute("x"))
                tinyxml2::XMLUtil::ToFloat(ptrElement1->Attribute("x"), &x);
            
            if (ptrElement1->Attribute("y"))
                tinyxml2::XMLUtil::ToFloat(ptrElement1->Attribute("y"), &y);
            
            if (ptrElement1->Attribute("z"))
                tinyxml2::XMLUtil::ToFloat(ptrElement1->Attribute("z"), &z);
            
            Point *p = new Point(x, y, z);
            t->addPoint(p);
        }
    }
    
    return t;
}


Lights *parseLight(XMLElement *ptrElement) {
    float posX = 0;
    float posY = 0;
    float posZ = 0;
    
    if (ptrElement->Attribute("type")) {
        if(!strcmp(ptrElement->Attribute("type" , "POINT"), "POINT")){
            if (ptrElement->Attribute("posX"))
                tinyxml2::XMLUtil::ToFloat(ptrElement->Attribute("posX"), &posX);
                
            printf("PX_________>>>>>> %d\n", posX);
            
            if (ptrElement->Attribute("posY"))
                tinyxml2::XMLUtil::ToFloat(ptrElement->Attribute("posY"), &posY);

            printf("PX_________>>>>>> %d\n", posX);
            
            if (ptrElement->Attribute("posZ"))
                tinyxml2::XMLUtil::ToFloat(ptrElement->Attribute("posZ"), &posZ);
            printf("PX_________>>>>>> %d\n", posX);
        }

        /*
        if (!strcmp(ptrElement->Attribute("type", " DIRECTIONAL"), " DIRECTIONAL")) {
            if (ptrElement->Attribute("posX"))
                tinyxml2::XMLUtil::ToFloat(ptrElement->Attribute("posX"), &posX);

            if (ptrElement->Attribute("posY"))
                tinyxml2::XMLUtil::ToFloat(ptrElement->Attribute("posY"), &posY);

            if (ptrElement->Attribute("posZ"))
                tinyxml2::XMLUtil::ToFloat(ptrElement->Attribute("posZ"), &posZ);
        }
        

        if (!strcmp(ptrElement->Attribute("type", "SPOT"), "SPOT")) {
            if (ptrElement->Attribute("posX"))
                tinyxml2::XMLUtil::ToFloat(ptrElement->Attribute("posX"), &posX);

            if (ptrElement->Attribute("posY"))
                tinyxml2::XMLUtil::ToFloat(ptrElement->Attribute("posY"), &posY);

            if (ptrElement->Attribute("posZ"))
                tinyxml2::XMLUtil::ToFloat(ptrElement->Attribute("posZ"), &posZ);
        }
        */


    }
    
    Point *pointLight = new Point(posX, posY, posZ);
    
    float colour[4] = {0,0,0,0};
    
    Lights *light = new Lights(pointLight, colour);
    
    return light;
}
