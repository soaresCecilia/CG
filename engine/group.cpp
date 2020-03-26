

#include "../headers/group.h"
#include "../headers/FormaGeo.h"
#include <vector>

int static i = 0.0;

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


void Group::drawSub() {
    glPushMatrix();
    //float colour[5] = {0.4,1,0.3,0.2,0.0};

    for(auto &form: this->formsOperations)
        form->transform();
    
    for(auto &formGeo: this->formsGeoCollection)
        formGeo->draw();
    
    for(auto &g : this->groups) {
        //glColor3f(1, colour[i++%5], colour[i++%5]);

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
