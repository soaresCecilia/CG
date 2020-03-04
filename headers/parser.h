  
#ifndef __PARSER_H__
#define __PARSER_H__


#include "nFormasGeo.h"

class Parser {
    public:
        Parser();
        void ReadXML(nFormasGeo *, const char *);
};
#endif
