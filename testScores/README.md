#THE TEST SCORES PROGRAM

OBJECTIVE:
This console program demonstrates the use of struct, array, pointer, and selection sort in C++.

DESCRIPTION: 
The program processes test scores for a class of students. It reads user-input student names and scores, and then it prints a report of the data, ordered from lowest score to highest, along with an average score.

REQUIREMENTS:
For each student, read the following input from the keyboard:
- student name (up to 30 chars)
- score (an integer value)

Store the name in a C++ string object. Use a struct to hold the name and score for one student. 
When the program starts, it asks the user for the number of students to be processed. Then it dynamically allocates an array of that size (an array of student-score structs). The program then:
- calls a function to read and store the name-score pairs 
- validates that the score is between 0 and 105, inclusive
- calls a function to sort the array on in ascending score order
- calls a value-returning function that calculates the average of the scores
- calls a function that displays a table of sorted student name-score pairs
- displays the average score with after the table
