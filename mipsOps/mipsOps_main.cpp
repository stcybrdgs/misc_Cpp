// THE MIPSOPS PROGRAM
// mipsOps_main.cpp
/*******************************************************************************
Programmer:  Stacy Bridges
Description: This program simulates how the MIPS computer architecture 
             performs integer multiplication and division. The console
             output is used to display how each word's worth of bits 
             in each of the MIPS target registers is affected at each 
             step of the multiplication or division algorithm.
*******************************************************************************/
#include "mipsOps_head.h"

int main(){
//  declare local variables to contain user input
    char choice = 'M';
    int  op_a    = 0,
         op_b    = 0;

//  get user input and invoke simulated MIPS multiplication or division
    do{
		printMenu( );
        cout << "Enter menu choice: ";
        cin >> choice;
        cout << endl; 
        choice = toupper(choice);
        
        switch (choice){
		//	invoke simulated multiplication 
			case 'M':
                cout << "Enter the multiplicand: ";
                cin >> op_a;                 
                cout << "Enter the multiplier: ";
                cin >> op_b;             
                multiply(op_a, op_b);  
                break;

 		//	invoke simulated division
			case 'D': 
                cout << "Enter the dividend: ";
                cin >> op_a;                 
                cout << "Enter the divisor: ";
                cin >> op_b;             
                divide(op_a, op_b);  
                break;

		//	exit the program
            case 'Q': 
                cout << "Goodbye." << endl;
                break;
            default:  cout << choice << " is invalid." << endl;
        }
    } while ((choice != 'Q'));

	return 0;
}//	end driver
