//
//  Operation.cpp
//  
//
//  Created by Cecilia Soares on 21/03/2020.
//

#include "../headers/Operation.h"

Operation::Operation(Point *point): p(point) {}

Operation::~Operation() {
    delete p;
}

Point *Operation::getPoint() {
    return p;
}
