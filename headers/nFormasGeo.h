#ifndef __NFORMASGEO_H__
#define __NFORMASGEO_H__

#include <string>
#include <vector>
#include "FormaGeo.h"


//em que é que consiste um agrupamento de formas geometricas
class nFormasGeo {
    private:
        std::vector<FormaGeo *> formaGeo;

    public:
        GLuint buffer[1];
        nFormasGeo();
        ~nFormasGeo();
        void addFormaGeo(FormaGeo *fg);
        void draw(int);
        std::vector<FormaGeo *>* getFormaGeo();
};
#endif
