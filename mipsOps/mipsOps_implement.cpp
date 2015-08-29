// THE MIPSOPS PROGRAM
// mipsOps_implement.cpp

#include "mipsOps_head.h"
#include<iostream>
#include<sstream>
#include<string>
using namespace std;

/********************************************************************
 void multiply(int a, int b)

 description: 
 perform simulated MIPS multiplication with the user-entered operands
 s.t. (a * b) and display the contents of the registers at each step

*********************************************************************/
void multiply(int a, int b){
    int multiplicandReg[32],  // simulate 32-bit register
        productReg[64];       // simulate 64-bit register

    // populate the multiplicand register   ------------------------
    int operand = a,          // operand a is the multiplicand
        remainder = 0;
 
    for( int count = 31; count >= 0; count --){
        remainder = operand % 2;
        operand = operand / 2;
        multiplicandReg[count] = remainder;
    }

    // populate the product/multiplier register   ------------------	
    operand   = b;             //  operand b is the multiplier
    remainder = 0;
 
    for( int count = 63; count >= 0; count -- ){
        remainder = operand % 2;
	operand = operand / 2;
	productReg[count] = remainder;
    }
    
    // display initial register contents
    cout    << endl
            << "step\t"   << "   "
            << "multiplicand"   << "                      "
            << "product     "   << "                      "
            << "multiplier  "   << "                      "
            <<  endl
            << "--------   "   
            << "--------------------------------  "
            << "--------------------------------  "
            << "--------------------------------  "
            << endl;

    printRegs("start", productReg, multiplicandReg);
            
    // perform multiplication operation	---------------------------
    for( int count = 0; count < 32; count ++){
    // STEP ONE:---------------------------------------------------
	// add multiplicand to product if multiplier lsb == 1
        if( productReg[63] == 1 ){
            int carryBit = 0;
            for( int i = 31; i >= 0; i-- ){
                if( multiplicandReg[i] + productReg[i] + carryBit == 0 ){   
		    productReg[i] = 0;
                    carryBit = 0;
                }
                else if( multiplicandReg[i] + productReg[i] + carryBit == 1 ){   
		    productReg[i] = 1;
                    carryBit = 0;
                }                
                else if( multiplicandReg[i] + productReg[i] + carryBit == 2 ){   
		    productReg[i] = 0;
                    carryBit = 1;
                }                
                else if( multiplicandReg[i] + productReg[i] + carryBit == 3 ){   
		    productReg[i] = 1;
                    carryBit = 1;
                }                
            }// end for
    
	    // print register contents to console
            printRegs("add", productReg, multiplicandReg);        
        }// end if
    // end step one
           
    // STEP TWO:--------------------------------------------------
	// don't add if multiplier lsb == 0  
        if( productReg[63] == 0 ){
            // print register contents to console
            printRegs("no add", productReg, multiplicandReg);     
        }// end if
    // end step two
    
    // STEP THREE:-------------------------------------------------
	// shift product/multiplier registers to the right
        for( int i = 63; i >=0 ; i -- ){
            if( i == 0 ) 
                productReg[i] = 0;  
            else  
                productReg[i] = productReg[i - 1];
        }// end for
        // print register contents to console        
        printRegs("shift", productReg, multiplicandReg);      
    // end step three        
    }// end for
}// end multiply()

/********************************************************************
 void divide(int a, int b)

 description:	
 perform simulated MIPS division with the user-entered operands 
 s.t. (a / b) and display the contents of the registers at each step

********************************************************************/
void divide(int a, int b){
    int divisorReg[32],         //  simulate 32-bit register
        divisorRegTwos[32],     //  two's compliment of divisor
        dividendReg[64];        //  simulate 64-bit register

    // populate divisor register   ------------------------
    int operand = b,      
        remainder = 0;
 
    for( int count = 31; count >= 0; count --){
        remainder = operand % 2;
        operand = operand / 2;
        divisorReg[count] = remainder;
    }

    // get two's compliment of divisor register  ---------------
    // flip the bits
    for( int i = 0; i < 32; i ++ ){
        if( divisorReg[i] == 0 )
            divisorRegTwos[i] = 1;
        else if( divisorReg[i] == 1 )
            divisorRegTwos[i] = 0;            
    }// end for 

    // add one
    int carryBit = 1;      
    for( int i = 31; i >= 0; i-- ){
        if( divisorRegTwos[i] + carryBit == 1 ){   
	    divisorRegTwos[i] = 1;
            carryBit = 0;
        }
        else if( divisorRegTwos[i] + carryBit == 2 ){   
	    divisorRegTwos[i] = 0;
            carryBit = 1;
        }                
    }// end for

    // populate remainder/quotient register  --------------------	
    operand   = a;             
    remainder = 0;
 
    for( int count = 63; count >= 0; count -- ){
        remainder = operand % 2;
	operand = operand / 2;
	dividendReg[count] = remainder;
    }
    
    // display initial register contents
    cout    << endl
            << "step\t"   << "   "
            << "divisor     "   << "                      "
            << "remainder   "   << "                      "
            << "quotient    "   
            <<  endl
            << "--------   "   
            << "--------------------------------  "
            << "--------------------------------  "
            << "--------------------------------  "
            << endl;
    printRegs("start", dividendReg, divisorReg); 

    // perform division and displays register contents 
    for( int count = 0; count < 32; count ++){
        // STEP ONE:--------------------------------------------------
	// shift dividendlow left 
        for( int i = 0; i < 64 ; i ++ ){
            if( i == 63 ) 
                dividendReg[i] = 0;  
            else  
                dividendReg[i] = dividendReg[i + 1];
        }// end for
        // print register contents to console        
        printRegs("shift", dividendReg, divisorReg);         
        // end step one          
    
        // STEP TWO:--------------------------------------------------   
	// subtract dividendhigh - divisor 
	carryBit = 0;
        for( int i = 31; i >= 0; i-- ){
            if( dividendReg[i] + divisorRegTwos[i] + carryBit == 0 ){   
		dividendReg[i] = 0;
                carryBit = 0;
            }
            else if( dividendReg[i] + divisorRegTwos[i] + carryBit == 1 ){   
		dividendReg[i] = 1;
                carryBit = 0;
            }                
            else if( dividendReg[i] + divisorRegTwos[i] + carryBit == 2 ){   
		dividendReg[i] = 0;
                carryBit = 1;
            }                
            else if( dividendReg[i] + divisorRegTwos[i] + carryBit == 3 ){   
		dividendReg[i] = 1;
                carryBit = 1;
            }                
        }// end for
        // print register contents to console        
        printRegs("sub", dividendReg, divisorReg);           
        // end step two
    
	// STEP THREE:--------------------------------------------------   
	// dividendhigh >= 0 ? lsb = 1 : lsb = 0 && restore dividendhigh 
        if( dividendReg[0] == 0 ){   
	    dividendReg[63] = 1;
            printRegs("lsb++", dividendReg, divisorReg);        
        }
        else if ( dividendReg[0] == 1 ){
            dividendReg[63] = 0;
            carryBit = 0;
            for( int i = 31; i >= 0; i-- ){
                if( dividendReg[i] + divisorReg[i] + carryBit == 0 ){   
		    dividendReg[i] = 0;
                    carryBit = 0;
                }
                else if( dividendReg[i] + divisorReg[i] + carryBit == 1 ){   
		    dividendReg[i] = 1;
                    carryBit = 0;
                }                
                else if( dividendReg[i] + divisorReg[i] + carryBit == 2 ){   
		    dividendReg[i] = 0;
                    carryBit = 1;
                }                
                else if( dividendReg[i] + divisorReg[i] + carryBit == 3 ){   
		    dividendReg[i] = 1;
                    carryBit = 1;
                }    
            }// end for
            printRegs("restore", dividendReg, divisorReg);                       
        }// end if-else
        // end step three
    }// end for   
}// end divide()

/********************************************************************
 void printMenu()

 description:	
 print the driver menu to the console

*********************************************************************/
void printMenu(){
    cout << endl; 
    cout << "Menu: ----------------------------\n";
    cout << " M    Multiply algorithm ( a*b )  \n";
    cout << " D    Divide algorithm   ( a/b )  \n";
    cout << " Q    Quit                        \n";
    cout << "----------------------------------\n";    
    cout << "(You may need to widen your display to accomodate the output)\n\n";    
}

/********************************************************************
 string getBinVal(int array[])

 description:	
 convert the argument array[] into a char string simulating the 
 contents of a 32-bit register and return the char string to the 
 calling function

*********************************************************************/
string getBinVal(int array[]){
    char charArray[33];    // char array to hold register bits as text
    
    for( int i = 0; i < 33; i ++ ){
        // put a terminal space at the end of the character array        
        if( i == 32 )
            charArray[i] = 32;
        // copy register bits into charArray           
        else
            charArray[i] = ( array[i] + 48 );
    }

    // turn charArray into a string
    stringstream ss;
    string binVal;
    ss << charArray;
    ss >> binVal;
 
    // return string for display to console    
    return binVal;   
}

/********************************************************************
 string getBinValUpper(int array[])

 description:	
 convert the argument array[] into a char string simulating the 
 contents of the upper 32-bits of a 64-bit combined register 
 and return the char string to the calling function

*********************************************************************/
string getBinValUpper(int array[]){
    char charArray[33];    // char array to hold register bits as text
    
    for( int i = 0; i < 33; i ++ ){
        // put a terminal space at the end of the character array        
        if( i == 32 )
            charArray[i] = 32;
        // copy register bits into charArray           
        else
            charArray[i] = ( array[i] + 48 );
    }

    // turn charArray into a string
    stringstream ss;
    string binVal;
    ss << charArray;
    ss >> binVal;
 
    // return string for display to console    
    return binVal;     
}

/********************************************************************
 string getBinValLower(int array[])

 description:	
 convert the argument array[] into a char string simulating the 
 contents of the lower 32-bits of a 64-bit combined register 
 and return the char string to the calling function

*********************************************************************/
string getBinValLower(int array[]){
    char charArray[33];    // char array to hold register bits as text
    
    for( int i = 32; i <= 64; i ++ ){
        // put a terminal space at the end of the character array        
        if( i == 64 )
            charArray[i-32] = 32;
        // copy register bits into charArray           
        else
            charArray[i-32] = ( array[i] + 48 );
    }

    // turn charArray into a string
    stringstream ss;
    string binVal;
    ss << charArray;
    ss >> binVal;
 
    // return string for display to console    
    return binVal;      
}

/********************************************************************
 void printRegs(string mssg, int bigReg[], int littleReg[])

 description:	
 print the contents of the registers; this method is invoked at 
 the end of each step in the multiply() and divide() methods.

*********************************************************************/
void printRegs(string mssg, int bigReg[], int littleReg[]){
    cout    << mssg    << "\t"          << "   "        
            << getBinVal(littleReg)     << "  "
            << getBinValUpper(bigReg)   << "  "
            << getBinValLower(bigReg)   << "  "
            << endl;          
}
