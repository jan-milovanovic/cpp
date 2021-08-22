#include "methods1.h"

#include <algorithm>
#include <iostream>
#include <sstream>
#include <ctime>	// for constant randomizing


void print_duplicated(std::vector<int> list)
{
	if (list.empty())
	{
		std::cout << "";
		return;
	}

	std::cout << "[";
	for (int i = 0; i < list.size()-1; ++i)
	{
		std::cout << list.at(i) << ", ";
	}
	std::cout << list.at(list.size() - 1) << "]";
}

// write a function "duplicated", that retains only unique numbers (delete all reoccurring elements) in the list xs
std::vector<int> duplicated(std::vector<int> xs)
{
	// i could create a set, or 2 for-loops iterating through to make each character get deleted
	// however, I could try a different approach using "std::unique"
	//auto test = std::unique(xs.begin(), xs.end());
	// unique only deletes characters that are next to each other, therefore we have to sort first?
	// 1. sort, 2.unique, 3.return.

	// here is an approach where we want to keep the same order
	// 1. make a new list
	// 2. add a new element if it's not already in the list
	// 3. return a list with only unique values :)
	std::vector<int> list{ xs.at(0) };
	
	for (int i = 1; i < xs.size(); ++i)
	{
		// if iterator result equals to end of list, then it didn't find a repeated number
		if (std::find(list.begin(), list.end(), xs.at(i)) == list.end())
			list.push_back(xs.at(i));

	}
	return list;
}


// write a function "eboran" which accepts a string sentence (with spaces included), and returns a new sentence with all the words flipped
// ex. "this is a flipped sentence" -> "siht si a deppilf ecnetnes"
std::string eboran(std::string string)
{
	std::string buffer;
	std::stringstream ss(string);

	std::string finalstring;
	while (ss >> buffer)
	{
		std::reverse(buffer.begin(), buffer.end());
		finalstring += buffer + " ";
	}
	return finalstring;
}

// some people use different kinds of dice, we describe those with a standard notation as following:
// 3d8 -> throw a dice with 8 sides 3 times. return the expected result (random)
// as a bonus: write a function "expected_result(dice, n) which simulates throwing a dice n-times and returns an average result
int throw_dice(std::string dice)
{
	int pos = dice.find("d");
	std::string rolled = dice.substr(0, pos);
	std::string size = dice.substr(pos + 1, dice.length()-1);

	srand(time(0));


	int result = 0;
	for (int i = 0; i < stoi(rolled); ++i)
	{
		result += rand() % stoi(size) + 1;	// random from 0 to n
	}
	return result;
}

double expected_result(std::string dice, int n)
{
	int result = 0;
	for (int i = 0; i < n; ++i)
	{
		result += throw_dice(dice);
	}
	return result / n;
}

// write a function "day" that returns the name of the day in the week for a given date
std::string date(int day, int month, int year)
{
	return "";
}

// an ban pet podgan (11 clenov) -> return a winner in the given list of players
std::string an_ban_pet_podgan(int* players)
{
	return "";
}

// main function
void main_methods1()
{
	std::vector<int> dup1{ 0, 1, 1, 4, 1, 5, 3, 9, 5, 4, 2, 1, 0, 9, 8, 7, 6, 5, 4, 3, 2, 1, 2, 2, 1, 0, 9, 0, 3, 2, 1, 5, 4, 3 };

	std::cout << "1. duplicate remove\n";
	print_duplicated(duplicated(dup1));

	std::cout << "\n\n2. string reversal\n";
	std::string str = "this is a string of a magical racecar driving across the    country";
	std::cout << eboran(str);

	std::string dice1 = "3d8";
	std::string dice2 = "1d1";
	std::string dice3 = "5d1";
	std::string dice4 = "3d10";
	std::cout << "\n\n3. dice throwing:\n1. ->  " << throw_dice(dice1)
			  << "\n2. ->  " << throw_dice(dice2)
			  << "\n3. ->  " << throw_dice(dice3)
			  << "\n4. ->  " << throw_dice(dice4);

	std::cout << "\n\n4. throwing dice n times:\n1. ->  " << expected_result("3d10", 1000);
}