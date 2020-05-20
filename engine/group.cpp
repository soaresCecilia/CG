#include "../headers/group.h"
#include "../headers/FormaGeo.h"
#include <vector>


Group::Group() {
}

Group::~Group() {
    for (auto &fg : this->formsGeoCollection)
            delete fg;
    
    for (auto &op : this->formsOperations)
            delete op;
    
    for (auto &grps : this->groups)
            delete grps;
}

void Group::addFormaGeo(FormaGeo *fg) {
        formsGeoCollection.push_back(fg);
}

void Group::saveOperation(Operation *op) {
    formsOperations.push_back(op);
}

void Group::addLights(Lights *light) {
    lights.push_back(light);
}

void Group::drawSub() {
    glPushMatrix();
    
    
    for(auto &form: this->formsOperations)
        form->transform();
    
    for(auto &formGeo: this->formsGeoCollection)
        formGeo->draw();
    
    for(auto &g : this->groups) {
        g->drawSub();
    }
    
    glPopMatrix();

}


std::vector<FormaGeo *>* Group::getFormaGeo(){
    return &(this->formsGeoCollection);
}


void Group::addGroup(Group *newGroup){
    groups.push_back(newGroup);
}
