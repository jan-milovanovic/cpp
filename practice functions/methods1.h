#pragma once

#include <vector>
#include <string>

// write a function "duplicated", that retains only unique numbers (delete all reoccurring elements) in the list xs
std::vector<int> duplicated(std::vector<int> xs);


// write a function "eboran" which accepts a string sentence (with spaces included), and returns a new sentence with all the words flipped
// ex. "this is a flipped sentence" -> "siht si a deppilf ecnetnes"
std::string eboran(std::string string);

// some people use different kinds of dice, we describe those with a standard notation as following:
// 3d8 -> throw a dice with 8 sides 3 times. return the expected result (random)
// as a bonus: write a function "expected_result(dice, n) which simulates throwing a dice n-times and returns an average result
int throw_dice(std::string dice);

double expected_result(std::string dice, int n);

// write a function "day" that returns the name of the day in the week for a given date
std::string date(int day, int month, int year);

// an ban pet podgan (11 clenov) -> return a winner in the given list of players
std::string an_ban_pet_podgan(int* players);

// main function
void main_methods1();