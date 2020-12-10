#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

#include "Room.hpp"
#include "Queen.hpp"

//child queen room class

Queen::Queen (string numberIn, string nameIn, string emailIn, string addon1In, string addon2In)  {
    
    //room information
    roomNumber = numberIn + ":  Queen     ";
    name = nameIn;
    email = emailIn;
    addon1 = addon1In;
    addon2 = addon2In;
    addOn1Cost = 0;
    addOn2Cost = 0;
    
    //total price calculations
    baseRate = 100;
    roomSpecificRate = 200;
    setAddOnPrices();
    setTotalPrice();
}

void Queen::setAddOnPrices () { //set add on prices
    if (addon1 == "Y") {
        addOn1Cost = 25;
        addon1 = "With Large Room        ";
    } else if (addon1 == "N") {
        addOn1Cost = 0;
        addon1 = "Without Large Room     ";
    }
    
    if (addon2 == "Y") {
        addOn2Cost = 20;
        addon2 = "With Parking Garage         ";
    } else if (addon2 == "N") {
        addOn2Cost = 0;
        addon2 = "Without Parking Garage      ";
    }
}

void Queen::setTotalPrice () { //calculate total price
    totalPrice = baseRate + roomSpecificRate + addOn1Cost + addOn2Cost;
}
