
#ifndef animateTanslation_h
#define animateTanslation_h

#include <stdio.h>
#include "Operation.h"
#include <vector>

class animateTranslation {
    private:
        float time;
        std::vector<float> coordinates;

    public:
        animateTranslation();
        ~animateTranslation();
        void transform();
};

#endif /* translation_h */