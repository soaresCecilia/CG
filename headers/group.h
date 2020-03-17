#ifndef __GROUP_H__
#define __GROUP_H__

#include <string>
#include <vector>
#include "FormaGeo.h"


//em que é que consiste um agrupamento de formas geometricas
class Group {
    private:
        std::vector<FormaGeo *> formsGeoCollection;
        std::vector<Translation *> formsTranslations;
        std::vector<Group *> groups;
    

    public:
        GLuint buffer[1];
        Group();
        ~Group();
        void addFormaGeo(FormaGeo *fg);
        void draw(int);
        std::vector<FormaGeo *>* getFormaGeo();
        void saveTranslation(Translation *translate);
        void addGroup(Group *newGroup);
    
    private:
        int countAllFormsPoints(Group *groups);
        void fillArray(Group *groups, float * arrayVertex, int *vertex);
};
#endif
