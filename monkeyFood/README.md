Program Requirements

Background:
This program was written for COSC1337, Programming Fundamentals II, at Austin Community College.
Objective: ? Demonstrate how to use 2-D arrays to process multiple sets of identical data ? Demonstrate how to pass 2-D arrays to functions in C++

Premise:
The local zoo has three monkeys and wants to track how many pounds of food each of them eat every day of the week.

Requirements:
Write a program that stores the monkey data in a two-dimensional array (3 x 7). Each row represents a monkey, and each column represents a day of the week. The monkey data is captured from the keyboard, and each entry is stored a floating-point value. The only data validation required is the rejection of negative numbers. Don't use global variables or loops.

Once all the data is read from the keyboard, the program should print a formatted report to the screen. The report should include:
- amount of food eaten by each monkey per day
- the average amount of food eaten by all monkeys per day
- the least amount of food eaten on any day by any monkey
- the largest amount of food eaten on any day by any monkey

The program should call a separate function to compute the value for each of the bullets above, as well as a separate function to print the report (5 functions total).