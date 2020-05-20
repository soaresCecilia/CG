#ifndef __GROUP_H__
#define __GROUP_H__

#include <string>
#include <vector>
#include "FormaGeo.h"
#include "Operation.h"
#include "Lights.h"


class Group {
    private:
        std::vector<FormaGeo *> formsGeoCollection;
        std::vector<Operation *> formsOperations;
        std::vector<Lights *> lights;
        std::vector<Group *> groups;

    public:
        Group();
        ~Group();
        void addFormaGeo(FormaGeo *fg);
        std::vector<FormaGeo *>* getFormaGeo();
        void saveOperation(Operation *op);
        void addGroup(Group *newGroup);
        void addLights(Lights *light);
        void drawSub();

   
};
#endif
