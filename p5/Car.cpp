#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

#include "Car.h"

std::ifstream dataFile;
string fileName;
std::vector <Car> cars;

Car::Car () {}
    
Car::Car (string modelIn, double mpgIn, int cylIn, double dispIn, int hpIn, double dratIn, double wtIn, double qsecIn, int vsIn, int amIn, int gearIn, int carbIn) {
    
    model = modelIn;
    mpg = mpgIn;
    disp = dispIn;
    drat = dratIn;
    wt = wtIn;
    qsec = qsecIn;
    cyl = cylIn;
    hp = hpIn;
    vs = vsIn;
    am = amIn;
    gear = gearIn;
    carb = carbIn;
}

void Car::openFile() {
    
    cout << "Open what file? ";
    cin >> fileName;
    
    dataFile.open (fileName);
    
    if (!dataFile.is_open()) {
        cout << "Bad file name, try again" << endl;
        Car::openFile();
    } else {
        Car::getData();
    }
}

void Car::getData() {
    
    string skipFirstLine;
    dataFile >> skipFirstLine;
    
    string inputLine;
    string inputLinep1;
    string inputLinep2;
    while (!dataFile.eof()) {
        dataFile >> inputLinep1;
        dataFile >> inputLinep2;
        inputLine = inputLinep1 + " " + inputLinep2;
        
        //cout << inputLine << endl;
        
        string::size_type modelLength = inputLine.find(',');
        string modelIn = inputLine.substr(0, modelLength);
        inputLine.replace(0, modelLength+1, "");
        
        string::size_type mpgLength = inputLine.find(',');
        string mpgString = inputLine.substr(0, mpgLength);
        inputLine.replace(0, mpgLength+1, "");
        stringstream Mpg(mpgString);
        double mpgIn;
        Mpg >> mpgIn;

        string::size_type cylLength = inputLine.find(',');
        string cylString = inputLine.substr(0, cylLength);
        inputLine.replace(0, cylLength+1, "");
        stringstream Cyl(cylString);
        int cylIn;
        Cyl >> cylIn;
            

        string::size_type dispLength = inputLine.find(',');
        string dispString = inputLine.substr(0, dispLength);
        inputLine.replace(0, dispLength+1, "");
        stringstream Disp(dispString);
        double dispIn;
        Disp >> dispIn;
            
        
        string::size_type hpLength = inputLine.find(',');
        string hpString = inputLine.substr(0, hpLength);
        inputLine.replace(0, hpLength+1, "");
        stringstream Hp(hpString);
        int hpIn;
        Hp >> hpIn;
            
        
        string::size_type dratLength = inputLine.find(',');
        string dratString = inputLine.substr(0, dratLength);
        inputLine.replace(0, dratLength+1, "");
        stringstream Drat(dratString);
        double dratIn;
        Drat >> dratIn;

        string::size_type wtLength = inputLine.find(',');
        string wtString = inputLine.substr(0, wtLength);
        inputLine.replace(0, wtLength+1, "");
        stringstream Wt(wtString);
        double wtIn;
        Wt >> wtIn;

        string::size_type qsecLength = inputLine.find(',');
        string qsecString = inputLine.substr(0, qsecLength);
        inputLine.replace(0, qsecLength+1, "");
        stringstream Qsec(qsecString);
        double qsecIn;
        Qsec >> qsecIn;
     
        string::size_type vsLength = inputLine.find(',');
        string vsString = inputLine.substr(0, vsLength);
        inputLine.replace(0, vsLength+1, "");
        stringstream Vs(vsString);
        int vsIn;
        Vs >> vsIn;
            

        string::size_type amLength = inputLine.find(',');
        string amString = inputLine.substr(0, amLength);
        inputLine.replace(0, amLength+1, "");
        stringstream Am(amString);
        int amIn;
        Am >> amIn;
            

        string::size_type gearLength = inputLine.find(',');
        string gearString = inputLine.substr(0, gearLength);
        inputLine.replace(0, gearLength+1, "");
        stringstream Gear(gearString);
        int gearIn;
        Gear >> gearIn;
            

        string::size_type carbLength = inputLine.find(',');
        string carbString = inputLine.substr(0, carbLength);
        inputLine.replace(0, carbLength+1, "");
        stringstream Carb(carbString);
        int carbIn;
        Carb >> carbIn;
        
        cars.push_back(Car(modelIn, mpgIn, cylIn, dispIn, hpIn, dratIn, wtIn, qsecIn, vsIn, amIn, gearIn, carbIn));
    }
    
}

//Model
void Car::setModel(string modelIn) {
    model = modelIn;
}
string Car::getModel() {
    return model;
}

//Miles/(US) gallon
void Car::setMpg(double mpgIn) {
    mpg = mpgIn;
}
double Car::getMpg() {
    return mpg;
}

//Displacement (cu.in.)
void Car::setDisp(double dispIn) {
    disp = dispIn;
}
double Car::getDisp() {
    return disp;
}

//Rear axle ratio
void Car::setDrat(double dratIn) {
    drat = dratIn;
}
double Car::getDrat() {
    return drat;
}

//Weight (1000 lbs)
void Car::setWt(double wtIn) {
    wt = wtIn;
}
double Car::getWt() {
    return wt;
}

//Weight (1000 lbs)
void Car::setQsec(double qsecIn) {
    qsec = qsecIn;
}
double Car::getQsec() {
    return qsec;
}

//Number of cylinders
void Car::setCyl(int cylIn) {
    cyl = cylIn;
}
int Car::getCyl() {
    return cyl;
}

//Gross horsepower
void Car::setHp(int hpIn) {
    hp = hpIn;
}
int Car::getHp() {
    return hp;
}

//Engine (0 = V-shaped, 1 = straight)
void Car::setVs(int vsIn) {
    vs = vsIn;
}
int Car::getVs() {
    return vs;
}

//Transmission (0 = automatic, 1 = manual)
void Car::setAm(int amIn) {
    am = amIn;
}
int Car::getAm() {
    return am;
}

//Number of forward gears
void Car::setGear(int gearIn) {
    gear = gearIn;
}
int Car::getGear() {
    return gear;
}

//Number of carburetors
void Car::setCarb(int carbIn) {
    carb = carbIn;
}
int Car::getCarb() {
    return carb;
}

//display method
void Car::display() {
    
    cout << Car::getModel() << endl << Car::getMpg() << endl << Car::getMpg() << endl << Car::getCyl() << endl << Car::getDisp() << endl << Car::getHp() << endl << Car::getDrat() << endl << Car::getWt() << endl << Car::getQsec() << endl << Car::getVs() << endl << Car::getAm() << endl << Car::getGear() << endl << Car::getCarb() << endl;
}
    

