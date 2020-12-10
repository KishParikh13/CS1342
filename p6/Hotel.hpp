#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

#ifndef Hotel_hpp
#define Hotel_hpp

#include <stdio.h>
#include "Room.hpp"

//hotel class
class Hotel {
 
    public:

    Hotel ();
    std::vector<Room *> allRooms;
    string hotelName;
};

#endif
