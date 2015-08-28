/*******************************************************************************
Programmer:    Stacy Bridges
Course:        COSC-1337-007: Programming Fundamentals II (36583) 
Assignment:    Assignment 6 - Monkey Food
Completed :    10/21/2013
Status    :    Complete

Description:    This program reads user-input data on how many pounds of food is 
                consumed weekly by the three monkeys at the Taylor zoo. The 
                program also prints a summary tabular report displaying the user 
                data, along with select statistics based on the data.
*******************************************************************************/
// include library links   
#include <iostream>
#include <iomanip>
using namespace std;

// struct declarations 

struct FoodStats{
    float   avgAmtEaten,  // variable for avg amount eaten
            minAmtEaten,  // variable for min amount eaten    
            maxAmtEaten;  // variable for max amount eaten
};

// function prototypes
void  getFoodData(float [][7], int size);
float getAvgAmtEaten(float [][7], int size);
float getMinAmtEaten(float [][7], int size);
float getMaxAmtEaten(float [][7], int size);
void  printFoodReport(float [][7], int size, FoodStats);

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
    system("pause");
    return 0;
// end main
}

// function definitions
/******************************************************************************
*   function: getFoodData()
*
*   purpose:  this module prompts/reads user entry of pounds of food consumed
*             per monkey per day of the week and stores that info in 
*             monkeyFood[][] via the local alias data[][]
******************************************************************************/
void getFoodData(float data[][7], int size){
    string day;    // local variable to hold day of week
    
// use nested loops to control user entry of food data;
// the outer loop controls which monkey's data is being entered
    for(int monkey = 0; monkey < size; monkey++){
    // the inner loop controls which day's data is being entered
        for(int dayCount = 0; dayCount < 7; dayCount++){
        // the switch statement determines name of the day
            switch(dayCount){ 
                case 0:
                    day = "Mon";
                    break;
                case 1:
                    day = "Tue";
                    break;
                case 2:
                    day = "Wed";
                    break;
                case 3:
                    day = "Thu";
                    break;
                case 4:
                    day = "Fri";
                    break;
                case 5:
                    day = "Sat";
                    break;
                case 6:
                    day = "Sun";
                    break;
                default:
                    cout << "Program error - contact IT to debug.";
            } // end switch
        
        // prompt/read # of lbs of food eaten by the monkey 
        // and store that info in data[][]
            cout    << "Enter pounds of food eaten by monkey " 
                    << monkey + 1 << " on " << day << ": ";
            cin     >> data[monkey][dayCount];
            
        // use a while loop to reject negative values
            while(data[monkey][dayCount] < 0)
            {
                cout    << "Negative values are invalid!" << endl;
                cout    << "Enter pounds of food eaten by monkey " 
                        << monkey + 1 << " on " << day << ": ";
                cin     >> data[monkey][dayCount];
            }
        } // end inner for-loop     
        
        cout << endl;
    } // end outer for-loop
} // end module

/******************************************************************************
*   function: getAvgAmtEaten()
*
*   purpose:  this module calculates the average daily amount in lbs consumed by 
*             all monkeys during the week; this avg value is determined by 
*             totalling the pounds of food consumed and dividing that
*             total by seven; the resulting average is returned to main.
******************************************************************************/
float getAvgAmtEaten(float data[][7], int size){   
    float  total = 0, // accumulator: total amount of food eaten
        average = 0;  // avg amount of food eaten
        
    // iterate through the contents of data[][] 
    // in order to accumulate the total pounds of food eaten 
    for(int row = 0; row < 3; row++){ 
        for(int col = 0; col < 7; col++){   
            total = total + data[row][col];
        }   
    }       
    
    // compute and return average 
    average = total / 7;
    return average;     
} // end module

/******************************************************************************
*   function: getMinAmtEaten
*
*   purpose:  this module calculates the min amount in lbs eaten by any monkey
*             during the week; the result is determined by identifying the 
*             smallest value contained in monkeyData[][];
*             the min value is returned to main.
******************************************************************************/
float   getMinAmtEaten(float data[][7], int size)
{   float   min = 0;                    // min amount of food eaten
    float   compareMin = data[0][0];    // variable to hold comparison value as 
                                        // benchmarked to 1st value in the array
    
// iterate through contents of data[][], comparing each value against the 
// benchmarked comparison value; upon each comparison, reset the min variable 
// as needed to contain the smallest value
    for(int row = 0; row < 3; row++){   
        for(int col = 0; col < 7; col++){
        // if array val < benchmarked val, then reset min val
            if(data[row][col] < compareMin)
                min = data[row][col];
        }   
    }       
    return min;             
}

/******************************************************************************
*   function: getMaxAmtEaten
*
*   purpose:  this module calculates the max amount in lbs eaten by any monkey
*             during the week; the result is determined by identifying the 
*             greatest value contained in monkeyData[][];
*             the max value is returned to main.
******************************************************************************/
float   getMaxAmtEaten(float data[][7], int size){
    float   max;                        // max amount of food eaten
    float   compareMax = data[0][0];    // variable to hold comparison value as 
                                        // benchmarked to 1st value in the array
    
// iterate through contents of data[][], comparing each value against the 
// benchmarked comparison value; upon each comparison, reset the max variable 
// as needed to contain the smallest value
    for(int row = 0; row < 3; row++){   
        for(int col = 0; col < 7; col++){
        // if array val > benchmarked val, then reset max val
            if(data[row][col] > compareMax)
                max = data[row][col];
        }   
    }     
    return max;
}

/******************************************************************************
*   function: printFoodReport()
*
*   purpose:  this module prints a weekly food report based on the data 
*             contained in monkeyFood[][] and stats, including:
*               - the amount in lbs consumed by each monkey daily
*               - the avg amount consumed by all monkeys during the week
*               - the min amount consumed by any monkey during the week
*               - the max amount consumed by any monkey during the week
******************************************************************************/
void    printFoodReport(float data[][7], int size, FoodStats stats)
{
// print report title and column headers
    cout << "----------------------------------------------------------------" << endl;
    cout << "                   Weekly Food Report                           " << endl;
    cout << "           Pounds of food eaten per monkey per day:             " << endl;
    cout << "----------------------------------------------------------------" << endl;
    cout << right                    
         << setw(8) << "Monkey"
         << setw(8) << "Mon"
         << setw(8) << "Tue"
         << setw(8) << "Wed"
         << setw(8) << "Thu"
         << setw(8) << "Fri"
         << setw(8) << "Sat"
         << setw(8) << "Sun"
         << endl;

// always show decimal with precision of two points  
    cout    << showpoint << fixed << setprecision(2);

// print monkeyFood[][] data;
// the outer for-loop controls which monkey's data is being printed
    for(int monkey = 0; monkey < size; monkey++){
        cout << setw(8) << monkey + 1;              

    // the inner loop controls which day's consumption is being printed
        for(int day = 0; day < 7; day ++){
            cout << setw(8) << data[monkey][day];   
        }     
        cout << endl;
    }      
    cout << endl;
    
// print the average, max, and min values from stats
    cout    << left << setw(50)
            << "The average food eaten per day by all monkeys: "
            << right << setw(8) << stats.avgAmtEaten << " pounds" << endl;
    cout    << left << setw(50)
            << "The least amount of food eaten by any monkey:"
            << right << setw(8) << stats.minAmtEaten << " pounds" << endl;
    cout    << left << setw(50)
            << "The most amount of food eaten by any monkey:"
            << right << setw(8) << stats.maxAmtEaten << " pounds" << endl;     
} // end module
