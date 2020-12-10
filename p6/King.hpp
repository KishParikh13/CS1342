#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

#ifndef King_hpp
#define King_hpp

#include <stdio.h>
#include "Room.hpp"

//child king room class

class King: public Room {
    
    public:
    
    King (string numberIn, string nameIn, string emailIn, string addon1In, string addon2In);
    
    void setAddOnPrices();
    void setTotalPrice ();
    float getTotalPrice();
};

#endif
