#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

//#include "Room.hpp"
#include "Bungalow.hpp"
#include "King.hpp"
#include "Queen.hpp"
// #include "Hotel.hpp"

std::ifstream dataFile;
string date;
std::vector <Room> rooms;
// Hotel hotel;

void getData () {
    //open data file
    dataFile.open("Reservations.txt");
    
    //get date
    dataFile >> date;
    
    //begin inputting data
    string inputLine;
    while (!dataFile.eof()) {
        
        //get room type
        dataFile >> inputLine;
        string roomType = inputLine.substr(0, 1);
        
        //get room number
        string::size_type roomNumLength = inputLine.find(',');
        string roomNum = inputLine.substr(0, roomNumLength);
        inputLine.replace(0, roomNumLength+1, "");
        
        //get name
        string firstname = inputLine;
        dataFile >> inputLine;
        string::size_type lastnameLength = inputLine.find(',');
        string lastname = inputLine.substr(0, lastnameLength);
        inputLine.replace(0, lastnameLength+1, "");
        string fullname = firstname + " " + lastname;
        
        //get email
        string::size_type emailLength = inputLine.find(',');
        string email = inputLine.substr(0, emailLength);
        inputLine.replace(0, emailLength+1, "");
        
        //get the value of the first add on
        string addOn1 = inputLine.substr(0,1);
        inputLine.replace(0, 2, "");
        
        //get the value of the second add on
        string addOn2 = inputLine;
        inputLine.replace(0, 1, "");
        
        //create room object based on room type
        if (roomType == "B") {
            rooms.push_back(Bungalow(roomNum, fullname, email, addOn1, addOn2));
           //  hotel.allRooms.push_back(new Bungalow(roomNum, fullname, email, addOn1, addOn2));
        } else if (roomType == "D") {
            rooms.push_back(King(roomNum, fullname, email, addOn1, addOn2));
           //  hotel.allRooms.push_back(new King(roomNum, fullname, email, addOn1, addOn2));
            
        } else if (roomType == "Q") {
            rooms.push_back(Queen(roomNum, fullname, email, addOn1, addOn2));
           //  hotel.allRooms.push_back(new Queen(roomNum, fullname, email, addOn1, addOn2));
        }
    }
}

//display prices
void displayPrices() {
    // cout << "Room Prices in " << hotel.hotelName << " for " << date << endl << endl;
    for (int i = 0; i < rooms.size(); i++) {  //iterate through all items of list and print their room number, addons, and total price
        cout << rooms.at(i).roomNumber << " ";
        cout << rooms.at(i).addon1 << " " << rooms.at(i).addon2 << " ";
        cout << "$" << rooms.at(i).getTotalPrice() << endl;
    }
}

//bonus feature to t->st a combo
void testACombo () {
    
    //promt whether they want to do this
    cout << "Would you like to test a combo? Enter Yes or No" << endl;
    string input;
    cin >> input;
    
    //if yes
    if ((input == "Yes") || (input == "yes")) {
        
        //choose a type of room
        cout << "Okay, what kind of room? Enter Bungalow, King, or Queen." << endl;
        string roomType;
        cin >> roomType;
        //retry if incorrect input
        if (!((roomType == "Bungalow") || (roomType == "King") || (roomType == "Queen") || (roomType == "bungalow") || (roomType == "king") || (roomType == "queen"))) {
            cout << "Invalid Input – Enter Bungalow, King, or Queen" << endl;
            cin >> roomType;
        }
        
        //get add ons
        string testAddOn1;
        string testAddOn2;
            //if room type is beach
            if ((roomType == "Bungalow") || (roomType == "bungalow")) {
                cout << "Would you like a beach or garden view? Enter Beach or Garden" << endl;
                cin >> testAddOn1;
            //retry if incorrect input
            if (!((testAddOn1 == "Beach") || (testAddOn1 == "beach") || (testAddOn1 == "Garden") || (testAddOn1 == "garden"))) {
                cout << "Invalid Input – Enter Beach or Garden" << endl;
                cin >> roomType;
            } else {
                if ((testAddOn1 == "Beach") || (testAddOn1 == "beach")) {
                    testAddOn1 = "B";
                } else if ((testAddOn1 == "Garden") || (testAddOn1 == "garden")) {
                    testAddOn1 = "G";
                }
                cout << "Would you like the Honeyroom Package? Enter Yes or No" << endl;
                cin >> testAddOn2;
                if (!((testAddOn2 == "Yes") || (testAddOn2 == "yes") || (testAddOn2 == "No") || (testAddOn2 == "no"))) {
                        cout << "Invalid Input – Enter Yes or No" << endl;
                        cin >> roomType;
                } else {
                    if ((testAddOn2 == "Yes") || (testAddOn2 == "yes")) {
                        testAddOn2 = "H";
                    } else if ((testAddOn2 == "No") || (testAddOn2 == "no")) {
                        testAddOn2 = "X";
                    }
                }
                rooms.push_back(Bungalow("Your estimate", "OK", "OK", testAddOn1, testAddOn2));
            }
            }
        
            //if room type is king
            if ((roomType == "King") || (roomType == "king")) {
                cout << "Would you like to be on Concierge Floor? Enter Yes or No" << endl;
                cin >> testAddOn1;
            if (!((testAddOn1 == "Yes") || (testAddOn1 == "yes") || (testAddOn1 == "No") || (testAddOn1 == "no"))) {
                cout << "Invalid Input – Enter Yes or No" << endl;
                cin >> roomType;
            } else {
                if ((testAddOn1 == "Yes") || (testAddOn1 == "yes")) {
                    testAddOn1 = "Y";
                } else if ((testAddOn1 == "No") || (testAddOn1 == "no")) {
                    testAddOn1 = "N";
                }
                cout << "Would you like a parking garage? Enter Yes or No" << endl;
                cin >> testAddOn2;
                if (!((testAddOn2 == "Yes") || (testAddOn2 == "yes") || (testAddOn2 == "No") || (testAddOn2 == "no"))) {
                        cout << "Invalid Input – Enter Yes or No" << endl;
                        cin >> roomType;
                } else {
                    if ((testAddOn2 == "Yes") || (testAddOn2 == "yes")) {
                        testAddOn2 = "Y";
                    } else if ((testAddOn2 == "No") || (testAddOn2 == "no")) {
                        testAddOn2 = "N";
                    }
                }
                rooms.push_back(King("Your estimate", "OK", "OK", testAddOn1, testAddOn2));
            }
            }
        
            //if room type is queen
            if ((roomType == "Queen") || (roomType == "queen")) {
                cout << "Would you like a large room? Enter Yes or No" << endl;
                cin >> testAddOn1;
            if (!((testAddOn1 == "Yes") || (testAddOn1 == "yes") || (testAddOn1 == "No") || (testAddOn1 == "no"))) {
                cout << "Invalid Input – Enter Yes or No" << endl;
                cin >> roomType;
            } else {
                if ((testAddOn1 == "Yes") || (testAddOn1 == "yes")) {
                    testAddOn1 = "Y";
                } else if ((testAddOn1 == "No") || (testAddOn1 == "no")) {
                    testAddOn1 = "N";
                }
                cout << "Would you like a parking garage? Enter Yes or No" << endl;
                cin >> testAddOn2;
                if (!((testAddOn2 == "Yes") || (testAddOn2 == "yes") || (testAddOn2 == "No") || (testAddOn2 == "no"))) {
                        cout << "Invalid Input – Enter Yes or No" << endl;
                        cin >> roomType;
                } else {
                    if ((testAddOn2 == "Yes") || (testAddOn2 == "yes")) {
                        testAddOn2 = "Y";
                    } else if ((testAddOn2 == "No") || (testAddOn2 == "no")) {
                        testAddOn2 = "N";
                    }
                }
                rooms.push_back(Queen("Your estimate", "OK", "OK", testAddOn1, testAddOn2));
            }
            }
        
        //display details of chosen combo
        cout << endl;
        cout << rooms.at(rooms.size()-1).roomNumber << " ";
        cout << rooms.at(rooms.size()-1).addon1 << " " << rooms.at(rooms.size()-1).addon2 << " ";
        cout << "$" << rooms.at(rooms.size()-1).getTotalPrice() << endl;
        cout << endl;
        
        //prompt to go again
        testACombo();
        
    } else if ((input == "No") || (input == "no")) {
        //if no - ends program
    } else {
        //if neither yes or no - try again
        cout << "Try Again" << endl;
        testACombo();
    }
}

//main function
int main () {
    getData();
    displayPrices();
    cout << endl;
    testACombo();
   
}
