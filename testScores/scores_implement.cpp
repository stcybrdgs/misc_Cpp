// testScores program implementation 
// scores_implement.cpp

#include "scores_head.h"
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

/*******************************************************************************
*   function: readScores()
*
*   purpose: This module reads student names/scores into an array. Validations 
*            limit the names to 30 characters and limit the scores to an 
*            inclusive range from 0 to 105. Pointer notation is used to 
*            access the elements in the array.
*******************************************************************************/
void readScores(Scores *array, int size){	
    bool validScore; // flag to indicate valid score
    
    // use for-loop to iterate through the array elements
    for(int count = 0; count < size; count++){   
        // the validScore flag is used to prime the while-loop validation below        
        validScore = false;                  
    
        // prompt user for student name and read it into the array
        cout << "Enter student name: ";      
        cin.ignore();
        getline(cin, (array + count)->name); 

        // if name > 30 chars, trunc to 30 chars and notify user 
        if((array + count)->name.length() > 30){   
            cout << "The name will be truncated to 30 characters." << endl;
            (array + count)->name.resize(31); // 30 chars + end marker
        }
    
        // prompt user to enter the student score and read it into the array  
        cout << "Enter student score: ";      
        cin >> (array + count)->score;        
    
        // validate student score and re-prompt until score is valid
        while(!validScore){
            // if score < 0 or score > 105, tell user it's invalid and re-prompt input
            if((array + count)->score < 0 || (array + count)->score > 105){   
                cout << "Error. The score must be " 
                     << "between 0 and 105, inclusive." << endl;
                cout << "Enter student score: ";
                cin >> (array + count)->score;
            }
            // else if score is valid, then set validScore flag to true
            else if((array + count)->score >= 0 && (array + count)->score <= 105)
                validScore = true;
        } 
    } 
}// end readScores()

/*******************************************************************************
*   function: sortScores()
*
*   purpose: This module uses a Selection Sort alogrithm to sort the test
*            scores in ascending order. Array notation is used to access the 
*            elements in the array.
*******************************************************************************/
void sortScores(Scores array[], int size){   
    int minValue;  // smallest compared value               
    int minIndex;  // subscript of the smallest compared value
    int temp;      // temp value to support swap
    
    for(int index = 0; index < size - 1; index ++){   
        minValue = array[index].score; // set current min value 
        minIndex = index;              // set location of current min value
        
        // compare the remaining array values to current minValue;
        // if a new min val is found, make it the new minValue
        for(int scan = index + 1; scan < size; scan ++){   
            if(array[scan].score < minValue){   
                minValue = array[scan].score;   
                minIndex = scan;               
            }  
            // swap old minValue with new minValue
            temp = array[index].score;                  
            array[index].score = array[minIndex].score; 
            array[minIndex].score = temp;           
        }
    }
} // end sortScores()

/*******************************************************************************
*   function: getScoresAvg()
*
*   purpose: This module computes the average test score 
*            (i.e., score sum / score count) and returns it to the main 
*            program. Array notation is used to access the elements in the array.
*******************************************************************************/
float getScoresAvg(Scores array[], int size){   
    int sum = 0; // var for sum of all scores
    float avg;   // var for avg of all scores
    
    for(int count = 0; count < size; count ++) 
        sum += array[count].score;  // sum the scores

    // calculate avg and convert int to float to preserve data precision 
    avg = static_cast<float>(sum) / static_cast<float>(size); 
    
    return avg;                     
} // end getScoresAvg()

/*******************************************************************************
*   function: printScoreInfo
*
*   purpose: This module displays a neat table of student name/score pairs
*            in sorted order, including the average score. Pointer notation 
*            is used to access the elements in the array.
*******************************************************************************/
void printScoreInfo(Scores *array, int size, float avg){   
    // print table headers
    cout    << endl;
    cout    << setw(34) << left  << "Name"
            << setw(7)  << right << "Score"
            << endl;
    cout    << "----------------------------------------" << endl;
    
    // display contents of name/score array
    for(int count = 0; count < size; count++){   
        cout    << setw(34) << left  << (array + count)->name   
                << setw(7)  << right << (array + count)->score
                << endl; 
    }

    // display the average score
    cout    << "----------------------------------------" << endl;
    cout    << setw(34) << left  << "Average: " 
            << setw(7)  << right << fixed  
            << setprecision(2)   << avg;                      

} // end printScoreInfo()
