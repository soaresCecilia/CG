#include "../headers/Operation.h"

Operation::Operation(Point *point): p(point) {}

Operation::~Operation() {
    delete p;
}

Point *Operation::getPoint() {
    return p;
}
