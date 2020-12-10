#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

#ifndef Room_hpp
#define Room_hpp

#include <stdio.h>

//parent room class
class Room {
    
    public:
    
    Room ();
    Room (string numberIn, string nameIn, string emailIn, string addon1In, string addon2In);
    
    string roomNumber;
    string name;
    string email;
    string addon1;
    string addon2;
    
    float baseRate;
    float roomSpecificRate;
    float addOn1Cost;
    float addOn2Cost;
    float totalPrice;
    
    void setAddOnPrices();
    void setTotalPrice();
    float getTotalPrice();

};

#endif
