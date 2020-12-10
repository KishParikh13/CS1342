#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

#ifndef Bungalow_hpp
#define Bungalow_hpp

#include <stdio.h>
#include "Room.hpp"

//child bungalow room class

class Bungalow: public Room {
    
    public:
    
    Bungalow (string numberIn, string nameIn, string emailIn, string addon1In, string addon2In);
    
    void setAddOnPrices();
    float getAddOn1Price();
    float getAddOn2Price();
    void setTotalPrice ();
    float getTotalPrice();
};

#endif
