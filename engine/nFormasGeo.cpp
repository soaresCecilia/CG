


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

void nFormasGeo::draw() {

        for (auto &fg : this->formaGeo)
                fg->draw();

}

std::vector<FormaGeo *>* nFormasGeo::getFormaGeo(){
    return &(this->formaGeo);
}
