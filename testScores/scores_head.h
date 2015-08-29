// testScores program head
// scores_head.h

#ifndef SCORES_HEAD_H
#define SCORES_HEAD_H

#include<string>
using namespace std;

//  define struct to hold student name-score pair
struct Scores{	
    string name;              
	int score;                 
};

//	function prototypes 
void readScores(Scores *, int);             // pointer notation
void sortScores(Scores [], int);            // array notation            
float getScoresAvg(Scores [], int);         // array notation
void printScoreInfo(Scores *, int, float);  // pointer notation

#endif
