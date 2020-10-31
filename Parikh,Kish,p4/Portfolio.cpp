#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
#include "Portfolio.h"
#include "Stock.h"
    
    //Portfolio::Portfolio() {}

    std::ifstream dataFile;
    std::vector <Stock> stocks;

    void Portfolio::openFile () {
        string fileName;
        string stockName;

        cout << "Open what file? ";
        cin >> fileName;
        
        stockName = fileName.substr(0,4);

        dataFile.open (fileName);
        
        if (!dataFile.is_open()) {
            cout << "Bad file name, try again" << endl;
            Portfolio::openFile();
        } else {
            Portfolio::get_data_list(stockName);
        }
    }

    void Portfolio::get_data_list (string stockName) {
        
        string throwAwayFirstLine;
        dataFile >> throwAwayFirstLine;
        dataFile >> throwAwayFirstLine;
        
        string inputLine;
         while (!dataFile.eof()) {
             dataFile >> inputLine;
             
             string::size_type dateLength = inputLine.find(',');
             string::size_type monthLength = inputLine.find('/');
             string monthString = inputLine.substr(0, monthLength);
             stringstream Month(monthString);
             int month;
             Month >> month;
             string dateString = inputLine.substr(0, dateLength);
             inputLine.replace(0, dateLength+1, "");
             string yearString = dateString.substr(dateString.length()-4);
             stringstream Year(yearString);
             double year;
             Year >> year;
             
             string::size_type openLength = inputLine.find(',');
             string openString = inputLine.substr(0, openLength);
             inputLine.replace(0, openLength+1, "");
             stringstream Open(openString);
             double open;
             Open >> open;

             string::size_type highLength = inputLine.find(',');
             string highString = inputLine.substr(0, highLength);
             inputLine.replace(0, highLength+1, "");
             stringstream High(highString);
             double high;
             High >> high;
             
             string::size_type lowLength = inputLine.find(',');
             string lowString = inputLine.substr(0, lowLength);
             inputLine.replace(0, lowLength+1, "");
             stringstream Low(lowString);
             double low;
             Low >> low;
             
             string::size_type closeLength = inputLine.find(',');
             string closeString = inputLine.substr(0, closeLength);
             inputLine.replace(0, closeLength+1, "");
             stringstream Close(closeString);
             double close;
             Close >> close;
             
             string::size_type adjLength = inputLine.find(',');
             string adjString = inputLine.substr(0, adjLength);
             inputLine.replace(0, adjLength+1, "");
             stringstream Adj(adjString);
             double adj;
             Adj >> adj;
             
             string volumeString = inputLine;
             stringstream Volume(volumeString);
             double volume;
             Volume >> volume;
             
             stocks.push_back(Stock(stockName, dateString, year, month, open, high, low, close, adj, volume));
         }
        cout << "What year do you want averaged? ";
        Portfolio::average_data();
    }

    void Portfolio::average_data () {
        int userYear;
        cin >> userYear;

        if (userYear < 2010 || userYear > 2020) {
            cout << "That is not a valid year, reenter ";
            Portfolio::average_data();
        } else {
            int numOfStocksPerYear = 0;
            int referenceStock = 0;
            double totalOpeningValue = 0;
            double totalHighValue = 0;
            double totalLowValue = 0;
            double totalClosingValue = 0;
            double totalCloseValue = 0;
            double totalVolume = 0;
            
            for (int i = 0; i < stocks.size(); i++) {
                if (stocks.at(i).year == userYear) {
                    numOfStocksPerYear++;
                    referenceStock = i;
                    
                    totalOpeningValue = totalOpeningValue + stocks.at(i).openingValue;
                    totalHighValue = totalHighValue + stocks.at(i).highValue;
                    totalLowValue = totalLowValue + stocks.at(i).lowValue;
                    totalClosingValue = totalClosingValue + stocks.at(i).closingValue;
                    totalCloseValue = totalCloseValue + stocks.at(i).closeValue;
                    totalVolume = totalVolume + stocks.at(i).volume;
                }
            }
            
            stocks.at(referenceStock).setOpeningValue(totalOpeningValue/numOfStocksPerYear);
            stocks.at(referenceStock).setHighValue(totalHighValue/numOfStocksPerYear);
            stocks.at(referenceStock).setLowValue(totalLowValue/numOfStocksPerYear);
            stocks.at(referenceStock).setClosingValue(totalClosingValue/numOfStocksPerYear);
            stocks.at(referenceStock).setCloseValue(totalCloseValue/numOfStocksPerYear);
            stocks.at(referenceStock).setVolume(totalVolume/numOfStocksPerYear);
            
            int daysPerMonthOfHighestStock = 0;
            double OpeningValueofMonth = 0;
            double highestOpeningMonthAverage = 0;
            double ClosingValueofMonth = 0;
            double lowestClosingMonthAverage = 100000;
            
            int highMonth = 0;
            int lowMonth = 0;
            
            for (int monthCounter = 1; monthCounter < 13; monthCounter++) {
                for (int i = 1; i < stocks.size(); i++) {
                    if ((stocks.at(i).year == userYear) && (stocks.at(i).month == monthCounter)) {
                        daysPerMonthOfHighestStock++;
                        
                        OpeningValueofMonth = OpeningValueofMonth + stocks.at(i).openingValue;
                        ClosingValueofMonth = ClosingValueofMonth + stocks.at(i).closingValue;
                        
                        if ((OpeningValueofMonth/daysPerMonthOfHighestStock) > highestOpeningMonthAverage) {
                            highestOpeningMonthAverage = (OpeningValueofMonth/daysPerMonthOfHighestStock);
                            highMonth = monthCounter;
                        }
                        if ((OpeningValueofMonth/daysPerMonthOfHighestStock) < lowestClosingMonthAverage) {
                            lowestClosingMonthAverage = (ClosingValueofMonth/daysPerMonthOfHighestStock);
                            lowMonth = monthCounter;
                        }
                    }
                }
            }
            //set the highest opening month
            stocks.at(referenceStock).setHighestOpeningMonth(highMonth);
            stocks.at(referenceStock).setHighestOpeningMonthValue(highestOpeningMonthAverage);
            
            //set the lowest closing month
            stocks.at(referenceStock).setLowestClosingMonth(lowMonth);
            stocks.at(referenceStock).setLowestClosingMonthValue(lowestClosingMonthAverage);
            
            stocks.at(referenceStock).display(userYear);
        }
    }
