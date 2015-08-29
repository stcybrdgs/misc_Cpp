// testScores program driver
// scores_main.cpp

/*******************************************************************************
Programmer:  Stacy Bridges
Description: This program processes test scores for a class of students. It
             reads user-input student names and scores, and then it prints
             a report of the data, ordered from lowest score to highest, 
             along with an average score.
*******************************************************************************/
#include "scores_head.h"
#include<iostream>
#include<string>
#include<iomanip>
#include<cstdlib>
using namespace std;

int main(){   
    int numScores;     // var for array size 
    float scoresAvg;   // var average of all student scores
    
    // prompt user for number of scores to be processed
	cout << "How many student scores need to be processed? ";
	cin >> numScores;         
    cout << endl;
    
    // dynamically allocate an array of Scores
	Scores *studentScores;                          
    studentScores =           
    new Scores[numScores];  

    // call functions to read name-score pairs, sort, compute avg, and print data
	readScores(studentScores, numScores);           
    sortScores(studentScores, numScores);             
    scoresAvg = getScoresAvg(studentScores, numScores); 
    printScoreInfo( studentScores, numScores, scoresAvg);

    delete [] studentScores;   // free the dynamically allocated memory
	studentScores = 0;         // set studentScores address to 0
	
	cout << endl << endl;      
	return EXIT_SUCCESS;                
}
