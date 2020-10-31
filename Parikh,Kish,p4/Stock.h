#ifndef STOCKH
#define STOCKH

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class Stock {
   public:
    
    Stock (string stockName, string dateIn, int yearIn, int monthIn, double openingValueIn, double highValueIn, double lowValueIn, double closingValueIn, double closeValueIn, int volumeIn);
    
    string stockSymbol, date, highMonthName, lowMonthName;
    double openingValue, highValue, lowValue, closingValue, closeValue, highMonthValue, lowMonthValue;
    int year, volume, month;

    //openingValue
    void setOpeningValue(double averageOpeningValue);
    double getOpeningValue();

    //highValue
    void setHighValue(double averageHighValue);
    double getHighValue();

    //lowValue
    void setLowValue(double averageLowValue);
    double getLowValue();

    //closingValue
    void setClosingValue(double averageClosingValue);
    double getClosingValue();

    //closeValue
    void setCloseValue(double averageCloseValue);
    double getCloseValue();

    //volume
    void setVolume(double averageVolume);
    int getVolume();

    //determine low and high months and their amounts
    void setHighestOpeningMonth(int month);
    string getHighestOpeningMonth();

    void setHighestOpeningMonthValue (double highMonthAverage);
    double getHighestOpeningMonthValue();

    void setLowestClosingMonth(int month);
    string getLowestClosingMonth();

    void setLowestClosingMonthValue (double highMonthAverage);
    double getLowestClosingMonthValue();

    //display method
    void display(int year);
};

#endif
