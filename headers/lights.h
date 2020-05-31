#ifndef LIGTHS_H
#define LIGTHS_H

#include <stdio.h>
#include "point.h"

/**
 private:
        Point pos;
        int i;
        float color[4];
        float amb[4];
        int state;
    public:
        Light();
        ~Light();
        virtual void draw() = 0;
        void setColor(float *);
        void setAmb(float *);
        void setIndex(int);
        void setPos(float *);
        int getState();
        void turnOn();
        void turnOff();
        Point POS() {
                return pos;
        }
        float *COLOR() {
                return color;
        }
        int INDEX() {
                return i;
        }
        float *AMB() {
                return amb;
        }


*/


class Lights {
    private:
        int i;
        Point pos;
        float colour[4];

        //point light
        float quad_att;
        //directional light

        
    
    public:
        Lights();
        ~Lights();
        virtual void draw() = 0;
        void setIndex(int i);
        int getIndex();


        void setPos(float x, float y, float z) {
            pos.setX(x);
            pos.setY(y),
            pos.setZ(z);
        }

        Point getPos() {
            return pos;
        }

        void Lights::setColour(float c[4]) {
            for (int i{ 0 }; i < 4; i++)
                this->colour[i] = c[i];
        }

        float* getColour() {
            return colour;
        }

        //point light
        void setQuad_att(float x) {
            quad_att = x;
        }

        float getQuad_att() {
            return quad_att;
        }

    
};



#endif /* lights_h */
