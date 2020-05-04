
#ifndef animateTanslation_h
#define animateTanslation_h

#include <stdio.h>
#include "Operation.h"
#include <vector>
#include "FormaGeo.h"

class animateTranslation {
    private:
        float time;
        std::vector<float> coordinates;

    public:
        animateTranslation();
        void addCoordinates(const Point& p);
        void addTime(float t);

        ~animateTranslation();
        void transform();
};

#endif /* translation_h */