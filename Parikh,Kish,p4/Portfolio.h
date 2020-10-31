#ifndef PORTFOLIOH
#define PORTFOLIOH

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
#include "Stock.h"

class Portfolio {
    public:
    
        std::ifstream dataFile;
        std::vector<Stock> stocks;

        void openFile();

        void get_data_list(string stockName);

        void average_data();
};

#endif
