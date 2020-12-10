#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

#include "Hotel.hpp"
#include "Room.hpp"

Hotel::Hotel () {
    
    std::vector<Room *> allRooms;
    hotelName = "Marriot";
}
