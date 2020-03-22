

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

int Group::countAllFormsPoints(Group *group){
    int n = 0;
    for (auto &fg : group->formsGeoCollection) {
        int pointsForm = fg->getNPoint();
        n = n + pointsForm * 3;
    }
    
    
    int result = n;
    for (auto &g : group->groups) {
        result += countAllFormsPoints(g);
    }
    return result;
}


void Group::fillArray(Group *group, float *vertexes, int * new_vertex) {
    
    for(auto &form: group->formsOperations)
        form->transform();
    
    for (auto &fg : group->formsGeoCollection) {
        for (auto &point : *(fg->getVector())) {
            vertexes[(*new_vertex)++] = point->getX();
            vertexes[(*new_vertex)++] = point->getY();
            vertexes[(*new_vertex)++] = point->getZ();
        }
    }
    
    for (auto &g : group->groups) {
        fillArray(g, vertexes, new_vertex);
    }
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


void Group::draw() {
    glGenBuffers(1, this->buffer);
    glBindBuffer(GL_ARRAY_BUFFER, this->buffer[0]);
    size_t n = 0;
    
    int allpoints = countAllFormsPoints(this);
    
    float *vertexes =  (float *) malloc(sizeof(float) * allpoints);
    
    int new_vertex = 0;
    
    glPushMatrix();

    
    fillArray(this, vertexes, &new_vertex);
         
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * allpoints , vertexes, GL_STATIC_DRAW);
    
    glVertexPointer(3, GL_FLOAT, 0, 0);
    
    glDrawArrays(GL_TRIANGLES, 0, allpoints);
    
    glPopMatrix();
    
    free(vertexes);
}

std::vector<FormaGeo *>* Group::getFormaGeo(){
    return &(this->formsGeoCollection);
}


void Group::addGroup(Group *newGroup){
    groups.push_back(newGroup);
}
