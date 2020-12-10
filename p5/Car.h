#ifndef Car_hpp
#define Car_hpp

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

class Car {
   public:
    
    Car ();
    
    Car (string modelIn, double mpgIn, int cylIn, double dispIn, int hpIn, double dratIn, double wtIn, double qsecIn, int vsIn, int amIn, int gearIn, int carbIn);
    
    string model;
    double mpg, disp, drat, wt, qsec;
    int cyl, hp, vs, am, gear, carb;
    
    std::ifstream dataFile;
    string fileName;
    std::vector <Car> cars;
    
    void openFile();
    void getData();
    
    //Model
    void setModel(string modelIn);
    string getModel();

    //Miles/(US) gallon
    void setMpg(double mpgIn);
    double getMpg();

    //Displacement (cu.in.)
    void setDisp(double dispIn);
    double getDisp();

    //Rear axle ratio
    void setDrat(double dratIn);
    double getDrat();

    //Weight (1000 lbs)
    void setWt(double wtIn);
    double getWt();

    //Weight (1000 lbs)
    void setQsec(double qsecIn);
    double getQsec();
    
    //Number of cylinders
    void setCyl(int cylIn);
    int getCyl();
    
    //Gross horsepower
    void setHp(int hpIn);
    int getHp();
    
    //Engine (0 = V-shaped, 1 = straight)
    void setVs(int vsIn);
    int getVs();
    
    //Transmission (0 = automatic, 1 = manual)
    void setAm(int amIn);
    int getAm();
    
    //Number of forward gears
    void setGear(int gearIn);
    int getGear();
    
    //Number of carburetors
    void setCarb(int carbIn);
    int getCarb();
    
    //display method
    void display();
};

#endif
