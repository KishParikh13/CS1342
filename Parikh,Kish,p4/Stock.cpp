#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
#include "Stock.h"

    // default constructor
    Stock::Stock (string stockName, string dateIn, int yearIn, int monthIn, double openingValueIn, double highValueIn, double lowValueIn, double closingValueIn, double closeValueIn, int volumeIn) {
     
         stockSymbol = stockName;
         date = dateIn;
         month  = monthIn;
         year = yearIn;
         openingValue = openingValueIn;
         highValue = highValueIn;
         lowValue = lowValueIn;
         closingValue = closingValueIn;
         closeValue = closeValueIn;
         volume = volumeIn;
         highMonthName = "";
         highMonthValue = 0;
         lowMonthName = "";
         lowMonthValue = 0;
    }

    //openingValue
    void Stock::setOpeningValue (double averageOpeningValue) { //openingValue mutator
        openingValue = averageOpeningValue;
    }

    double Stock::getOpeningValue () { //openingValue accesor
        return openingValue;
    }

    //highValue
    void Stock::setHighValue (double averageHighValue) { //highValue mutator
        highValue = averageHighValue;
    }

    double Stock::getHighValue () { //highValue accesor
        return highValue;
    }

    //lowValue
    void Stock::setLowValue (double averageLowValue) { //lowValue mutator
        lowValue = averageLowValue;
    }

    double Stock::getLowValue () { //lowValue accesor
        return lowValue;
    }

    //closingValue
    void Stock::setClosingValue (double averageClosingValue) { //closingValue mutator
        closingValue = averageClosingValue;
    }

    double Stock::getClosingValue () { //closingValue accesor
        return closingValue;
    }
    
    //closeValue
    void Stock::setCloseValue (double averageCloseValue) { //openingValue mutator
        closeValue = averageCloseValue;
    }

    double Stock::getCloseValue () { //openingValue accesor
        return closeValue;
    }

    //volume
    void Stock::setVolume(double averageVolume) {
        volume = averageVolume;
    }

    int Stock::getVolume() {
        return volume;
    }

    //determine low and high months and their amounts
    void Stock::setHighestOpeningMonth (int month) {
        if (month == 1) {
            highMonthName = "January";
        } else if (month == 2) {
            highMonthName = "February";
        } else if (month == 3) {
            highMonthName = "March";
        } else if (month == 4) {
            highMonthName = "April";
        } else if (month == 5) {
            highMonthName = "May";
        } else if (month == 6) {
            highMonthName = "June";
        } else if (month == 7) {
            highMonthName = "July";
        } else if (month == 8) {
            highMonthName = "August";
        } else if (month == 9) {
            highMonthName = "September";
        } else if (month == 10) {
            highMonthName = "October";
        } else if (month == 11) {
            highMonthName = "November";
        } else if (month == 12) {
            highMonthName = "December";
        }
    }
    string Stock::getHighestOpeningMonth () {
        return highMonthName;
    }

    void Stock::setHighestOpeningMonthValue (double highMonthAverage) {
        highMonthValue = highMonthAverage;
    }
    double Stock::getHighestOpeningMonthValue() {
        return highMonthValue;
    }

    void Stock::setLowestClosingMonth(int month) {
        if (month == 1) {
            lowMonthName = "January";
        } else if (month == 2) {
            lowMonthName = "February";
        } else if (month == 3) {
            lowMonthName = "March";
        } else if (month == 4) {
            lowMonthName = "April";
        } else if (month == 5) {
            lowMonthName = "May";
        } else if (month == 6) {
            lowMonthName = "June";
        } else if (month == 7) {
            lowMonthName = "July";
        } else if (month == 8) {
            lowMonthName = "August";
        } else if (month == 9) {
            lowMonthName = "September";
        } else if (month == 10) {
            lowMonthName = "October";
        } else if (month == 11) {
            lowMonthName = "November";
        } else if (month == 12) {
            lowMonthName = "December";
        }
    }
    string Stock::getLowestClosingMonth() {
        return lowMonthName;
    }

    void Stock::setLowestClosingMonthValue (double lowMonthAverage) {
        lowMonthValue = lowMonthAverage;
    }
    double Stock::getLowestClosingMonthValue() {
        return lowMonthValue;
    }

    void Stock::display (int year) { //display method

        cout << endl << "Here are the averages of " << Stock::stockSymbol << " for year " << year << endl;
        
        cout << "Opening    Closing    High       Low         Close      Volume" << endl;
        cout << Stock::getOpeningValue() << "    " << getClosingValue() << "    " << Stock::getHighValue() << "    " << Stock::getLowValue() << "    " << getCloseValue() << "    " << Stock::getVolume() << endl;

        cout << endl;

        cout << "The month with the highest opening value was " << Stock::getHighestOpeningMonth() << " with " << Stock::getHighestOpeningMonthValue() << endl;
        cout << "The month with the lowest closing value was " << Stock::getLowestClosingMonth() << " with " << Stock::getLowestClosingMonthValue() << endl << endl;
    }
