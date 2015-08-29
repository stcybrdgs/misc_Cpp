// THE MIPSOPS PROGRAM
// mipsOps_head.h

#ifndef MIPSOPS_HEAD_H
#define MIPSOPS_HEAD_H

#include<iostream>
#include<sstream>
#include<string>
using namespace std;

// non-member function prototypes
void printMenu();
void multiply(int, int);
void divide(int, int);
void printRegs(string, int [], int []);
string getBinVal(int []);
string getBinValUpper(int []);
string getBinValLower(int []);

#endif
