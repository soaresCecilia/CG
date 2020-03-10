


#include "../headers/nFormasGeo.h"
#include "../headers/FormaGeo.h"
#include <vector>


nFormasGeo::nFormasGeo() {
}

nFormasGeo::~nFormasGeo() {

        for (auto &fg : this->formaGeo)
                delete fg;

}

void nFormasGeo::addFormaGeo(FormaGeo *m) {
        formaGeo.push_back(m);
}

void nFormasGeo::draw(int tam) {
    glGenBuffers(1, this->buffer);
    glBindBuffer(GL_ARRAY_BUFFER, this->buffer[0]);
    size_t n = 0;
    
    for (auto &fg : this->formaGeo) {
        int pointsForm = fg->getNPoint();
        n = n + pointsForm * 3;
        
    }
    float *vertexes =  (float *) malloc(sizeof(float) * n);
    int new_vertex = 0;
         
       for (int i = 0; i <tam; i++) {
           for (auto &fg : this->formaGeo) {
               for (auto &point : *(fg->getVector())) {
                   vertexes[new_vertex++] = point->getX();
                   vertexes[new_vertex++] = point->getY();
                   vertexes[new_vertex++] = point->getZ();
               }
           }
       }
         
         glBufferData(GL_ARRAY_BUFFER, sizeof(float) * n , vertexes, GL_STATIC_DRAW);
         glVertexPointer(3, GL_FLOAT, 0, 0);
    
        glDrawArrays(GL_TRIANGLES, 0, n);
    
    
         free(vertexes);

}

std::vector<FormaGeo *>* nFormasGeo::getFormaGeo(){
    return &(this->formaGeo);
}
