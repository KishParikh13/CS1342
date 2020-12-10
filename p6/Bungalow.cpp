#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

#include "Room.hpp"
#include "Bungalow.hpp"


Bungalow::Bungalow (string numberIn, string nameIn, string emailIn, string addon1In, string addon2In)  {

    //room information
    roomNumber = numberIn + ":  Bungalow  ";
    name = nameIn;
    email = emailIn;
    addon1 = addon1In;
    addon2 = addon2In;
    addOn1Cost = 0;
    addOn2Cost = 0;
    
    //total price calculations
    baseRate = 100;
    roomSpecificRate = 500;
    setAddOnPrices();
    setTotalPrice();
}

void Bungalow::setAddOnPrices () {  //set add on prices
    if (addon1 == "B") {
        addOn1Cost = 50;
        addon1 = "Beach View             ";
    } else if (addon1 == "G") {
        addOn1Cost = 0;
        addon1 = "Garden View            ";
    }
    
    if (addon2 == "H") {
        addOn2Cost = 75;
        addon2 = "With Honeyroom Package      ";
    } else if (addon2 == "X") {
        addOn2Cost = 0;
        addon2 = "Without Honeyroom Package   ";
    }
}


void Bungalow::setTotalPrice () { //calculate total price
    totalPrice = baseRate + roomSpecificRate + addOn1Cost + addOn2Cost;
}

