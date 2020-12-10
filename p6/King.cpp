#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

#include "Room.hpp"
#include "King.hpp"

King::King (string numberIn, string nameIn, string emailIn, string addon1In, string addon2In)  {

    //room information
    roomNumber = numberIn + ": King      ";
    name = nameIn;
    email = emailIn;
    addon1 = addon1In;
    addon2 = addon2In;
    addOn1Cost = 0;
    addOn2Cost = 0;
    
    //total price calculations
    baseRate = 100;
    roomSpecificRate = 300;
    setAddOnPrices();
    setTotalPrice();
}

void King::setAddOnPrices () { //set add on prices
    if (addon1 == "Y") {
        addOn1Cost = 50;
        addon1 = "On Concierge Floor     ";
    } else if (addon1 == "N") {
        addOn1Cost = 0;
        addon1 = "Not On Concierge Floor ";
    }
    
    if (addon2 == "Y") {
        addOn2Cost = 20;
        addon2 = "With Parking Garage         ";
    } else if (addon2 == "N") {
        addOn2Cost = 0;
        addon2 = "Without Parking Garage      ";
    }
}

void King::setTotalPrice () { //calculate total price
    totalPrice = baseRate + roomSpecificRate + addOn1Cost + addOn2Cost;
}

