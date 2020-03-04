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
        nFormasGeo();
        ~nFormasGeo();
        void addFormaGeo(FormaGeo *fg);
        void draw();
};
#endif
