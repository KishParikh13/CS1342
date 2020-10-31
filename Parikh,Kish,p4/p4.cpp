#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

#include "Stock.h"
#include "Portfolio.h"

int main () {
    Portfolio portfolio;

    portfolio.openFile();

    cout << "Press 1 to Start Over" << endl << "Press 0 to Quit " << endl;
    int restartPrompt;
    cin >> restartPrompt;
    if (restartPrompt == 1) {
        main();
    } else if (restartPrompt == 0) {
        return 0;
    }
}
