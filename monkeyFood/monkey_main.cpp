/*******************************************************************************
Programmer:  Stacy Bridges
Description: This program reads user-input data on how many pounds of food is 
             consumed weekly by the three monkeys at the Taylor zoo. The 
             program also prints a summary tabular report displaying the user 
             data, along with select statistics based on the data.
*******************************************************************************/
#include "monkey_head.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

// begin main
int main(){
// declare two-dimensional array to hold user-entered food data
    const int COLS = 7,             
              ROWS = 3;               
    float monkeyFood[ROWS][COLS];    

// create struct object to hold avg/min/max values
    FoodStats stats;                
    
// print program header describing the program
    cout << "----------------------------------------------------------------" << endl;
    cout << "            TAYLOR ZOO - MONKEY FOOD TRACKER                    " << endl;
    cout << "   This program tracks weekly data and stats for monkey food:   " << endl;
    cout << "----------------------------------------------------------------" << endl;
    cout << endl;

// call program modules
    getFoodData(monkeyFood, ROWS);                         // read food data from kb
    stats.avgAmtEaten = getAvgAmtEaten(monkeyFood, ROWS);  // get avg and store in stats
    stats.minAmtEaten = getMinAmtEaten(monkeyFood, ROWS);  // get min and store in stats
    stats.maxAmtEaten = getMaxAmtEaten(monkeyFood, ROWS);  // get max and store in stats
    printFoodReport(monkeyFood, ROWS, stats);              // print food report
    
    cout << endl << endl;
    return EXIT_SUCCESS;
// end main
}
