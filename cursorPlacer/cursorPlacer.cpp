//  The Cursor Placer Program
//  cursorPlacer.cpp
/*******************************************************************************
Programmer:  Stacy Bridges
Description: This program demonstrates how to use window.h to create a console 
             form that automatically places the cursor at the next field in the 
             form after each user entry.
*******************************************************************************/
#include<iostream>
#include<windows.h>  // allows for setting cursor positions
#include<string>
#include<cstdlib>    // allows for EXIT_SUCCESS
using namespace std;

struct UserInfo{
    string name;
    int age;
    char gender;
};

//  function prototypes
void placeCursor(HANDLE, int, int); 
void displayPrompts(HANDLE);
void getUserInput(HANDLE, UserInfo&);
void displayData(HANDLE, UserInfo);

int main(){
    UserInfo input; 
    
    // Get the handle to standard output device (the console)
    HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
    
    displayPrompts(screen);
    getUserInput(screen, input);
    displayData(screen, input);
    
    system("pause");
    return EXIT_SUCCESS;
}

//  function definitions
void placeCursor(HANDLE screen, int row, int col){
    // COORD is a defined C++ structure that holds a pair of X/Y coordinates
    COORD position;
    position.Y = row;
    position.X = col;
    SetConsoleCursorPosition(screen, position);   
}

void displayPrompts(HANDLE screen){
    placeCursor(screen, 3, 25);
    cout << "******* Data Entry Form *******" << endl;
    placeCursor(screen, 5, 25);
    cout << "Name: " << endl;
    placeCursor(screen, 7, 25);
    cout << "Age:           Gender (M/F): " << endl;
}

void getUserInput(HANDLE screen, UserInfo &input){
    placeCursor(screen, 5, 31);
    getline(cin, input.name);
    placeCursor(screen, 7, 30);
    cin >> input.age;
    placeCursor(screen, 7, 55);
    cin >> input.gender;    
}

void displayData(HANDLE screen, UserInfo input){
    placeCursor(screen, 10, 0);
    cout << "Here is the data you entered.\n";
    cout << "Name      : " << input.name    << endl;
    cout << "Age       : " << input.age     << endl;
    cout << "Gender    : " << input.gender  << endl;
}
