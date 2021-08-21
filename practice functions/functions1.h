#include <tuple>
#include <string>
#include <vector>

#pragma once

// function returns the biggest number in list "xs".
int max(int* array, int size);

// function returns number with the highest absolute value in the list
int max_abs(int* array, int size);

// function returns a list of tuples
std::vector<std::tuple<int, int>> label(int* array, int size);

// function returns a bmi of the people inside tuples that contain
// ('name', weight, height) ex. bmi(['Ana', 55, 165]) returns [('Ana'), 20.20)]
// set decimal precision to 2 decimals
std::vector<std::tuple<std::string, double>> bmi(std::vector<std::tuple<std::string, double, double>> people);

// function is same as before, with a different approach:
// all variables are stored inside a list and passed to the function
// names = ['Ana', 'Berta'], weights = [55, 60], heights = [165, 153] ... bmi2(names, weights, heights)
std::vector<std::tuple<std::string, double>> bmi(std::vector<std::string> people, double* weights, double* heights);

// function returns the amount of prime numbers that are lower than the given number n
int prime(int n);

// function checks if the given string is a palindrome (when reversed, string stays the same)
bool palindrome(std::string s);

// main function of the functions1 section
void main_functions1();

