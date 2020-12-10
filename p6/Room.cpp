#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

#include "Room.hpp"

Room::Room () {}
Room::Room (string numberIn, string nameIn, string emailIn, string addon1In, string addon2In) {
    
    //room information
    roomNumber = numberIn;
    name = nameIn;
    email = emailIn;
    addon1 = addon1In;
    addon2 = addon2In;
    addOn1Cost = 0;
    addOn2Cost = 0;
    
    //total price calculations
    baseRate = 100;
    roomSpecificRate = 0;
    setAddOnPrices();
    setTotalPrice();
}

void Room::setAddOnPrices () { //set add on prices - implemented in child classes
}

void Room::setTotalPrice () { //calculate total price
    totalPrice = baseRate + roomSpecificRate + addOn1Cost + addOn2Cost;
}

float Room::getTotalPrice() { // return total price
    return totalPrice;
}
