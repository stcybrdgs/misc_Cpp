#ifndef MONKEY_HEAD_H
#define MONKEY_HEAD_H

// struct declaration
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

#endif
