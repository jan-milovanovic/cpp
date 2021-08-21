#include "functions1.h"

#include <iostream>

using namespace std;

// function returns the biggest number in list "xs".
int max(int* array, int size)
{
	int max = array[0];
	for (int i = 1; i < size; ++i)
	{
		if (array[i] > max)
			max = array[i];
	}
	return max;
}

// function returns number with the highest absolute value in the list
int max_abs(int* array, int size)
{
	int max = abs(array[0]);
	for (int i = 1; i < size; ++i)
	{
		if (abs(array[i]) > max)
			max = abs(array[i]);
	}
	return max;
}

// help function for label (prints out the result)
void print_label(std::vector<std::tuple<int, int>> label)
{
	for (int i = 0; i < label.size(); ++i)
	{
		cout << "(" << std::get<0>(label.at(i)) << ", " << std::get<1>(label.at(i)) << ") ";
	}
}

// function returns a list of tuples
std::vector<std::tuple<int, int>> label(int* array, int size)
{
	std::vector<std::tuple<int, int>> labeled;
	for (int i = 0; i < size; ++i)
	{
		labeled.push_back(std::make_tuple(i, array[i]));
	}
	return labeled;
}

void print_bmi(std::vector<std::tuple<std::string, double>> bmis)
{
	cout << "[";
	for (int i = 0; i < bmis.size(); ++i)
	{
		cout << "(" << std::get<0>(bmis.at(i)) << ", " << (double)((int)(std::get<1>(bmis.at(i)) * 100)) / 100 << "), ";
	}
	cout << "]\n";
}

// function returns a bmi of the people inside tuples that contain
// ('name', weight, height) ex. bmi(['Ana', 55, 165]) returns [('Ana'), 20.20)]
// set decimal precision to 2 decimals
std::vector<std::tuple<std::string, double>> bmi(std::vector<std::tuple<std::string, double, double>> people)
{
	std::vector<std::tuple<std::string, double>> bmis;
	for (int i = 0; i < people.size(); ++i)
	{
		bmis.push_back(std::make_tuple(std::get<0>(people.at(i)),
					   std::get<1>(people.at(i)) / pow(std::get<2>(people.at(i)) / 100, 2)));
	}
	return bmis;
}

// function is same as before, with a different approach:
// all variables are stored inside a list and passed to the function
// names = ['Ana', 'Berta'], weights = [55, 60], heights = [165, 153] ... bmi2(names, weights, heights)
std::vector<std::tuple<std::string, double>> bmi2(std::vector<std::string> people, double* weights, double* heights)
{
	std::vector<std::tuple<std::string, double>> bmis;
	for (int i = 0; i < people.size(); ++i)	// I assume all arrays are the same length, otherwise this would never work
	{
		bmis.push_back(make_tuple(people.at(i), weights[i] / pow(heights[i] / 100, 2)));
	}
	return bmis;
}

// function returns the amount of prime numbers that are lower than the given number n
int prime(int n)
{
	int counter = 0;
	for (int i = n-1; i > 1; --i)
	{
		bool prime = true;
		for (int j = i-1; j > 1; --j)
		{
			if (i % j == 0)
				prime = false;
		}
		if (prime)
			counter++;
	}
	return counter;
}

// function checks if the given string is a palindrome (when reversed, string stays the same)
bool palindrome(std::string s)
{
	for (int i = s.length()-1; i > s.length()/2-1; --i)
	{
		cout << i << ": " << s.at(i) << "    " << s.at(s.length()-1 - i);
		if (s.at(i) != s.at(s.length()-1 - i))
			return false;
	}
	return true;
}


void main_functions1()
{
	int max1[]{ 5, 1, -6, -7, 2 };
	int max2[]{ 5, 2, -3, 42, 12, -124, -14451, 36, 12, 1351, 41, 24, 59, 0, 10, -18 };
	int max3[]{ -562, -53, -13, -41, -72, -63, -39, -25, -265, -754, -625, -235, -235, -25, -235, -91, -213, -416 };
	int max4[]{ 0 };

	int label1[]{ 4, 4, 4 };
	int label2[]{ 5, 1, 4, 2, 3 };
	int label3[]{ 0, 1, -12, -124, 2234, -25, 14, 5499, 2495, 24, 324, 43, 2152, 5 };

	vector<tuple<string, double, double>> people = { make_tuple("Ana", 55, 165), make_tuple("Berta", 60, 153) };
	vector<tuple<string, double, double>> people2 = { make_tuple("Cilka", 73, 178), make_tuple("David", 82, 190),
												make_tuple("Erik", 67, 174), make_tuple("Friderik", 76, 184) };

	vector<string> people_names { "Ana", "Berta" };
	double people_weights[]{ 55, 60 };
	double people_heights[]{ 165, 153 };

	vector<string> people_names2 { "Cilka", "David", "Erik", "Friderik" };
	double people_weights2[]{ 73, 82, 67, 76 };
	double people_heights2[]{ 178, 190, 174, 184 };

	cout << "max values:\n1. [5, 1, -6, -7, 2]\n2.[5, 2, -3, 42, 12, -124, -14451, 36, 12, 1351, 41, 24, 59, 0, 10, -18]\n"
		"3. [-562, -53, -13, -41, -72, -63, -39, -25, -265, -754, -625, -235, -235, -25, -235, -91, -213, -416]\n4. [0]\n\n" << endl;

	cout << "Function max():\n1 ->  " << max(max1, (sizeof(max1) / sizeof(max1[0])))
		<< "\n2 ->  " << max(max2, (sizeof(max2) / sizeof(max2[0])))
		<< "\n3 ->  " << max(max3, (sizeof(max3) / sizeof(max3[0])))
		<< "\n4 ->  " << max(max4, (sizeof(max4) / sizeof(max4[0]))) << endl;

	cout << "\n\nFunction max_abs():\n1 ->  " << max_abs(max1, (sizeof(max1) / sizeof(max1[0])))
		<< "\n2 ->  " << max_abs(max2, (sizeof(max2) / sizeof(max2[0])))
		<< "\n3 ->  " << max_abs(max3, (sizeof(max3) / sizeof(max3[0])))
		<< "\n4 ->  " << max_abs(max4, (sizeof(max4) / sizeof(max4[0]))) << endl;

	cout << "\n\nFunction label():\n1. ->  ";
	print_label(label(label1, (sizeof(label1) / sizeof(label1[0]))));
	cout << "\n2. ->  ";
	print_label(label(label2, (sizeof(label2) / sizeof(label2[0]))));
	cout << "\n3. ->  ";
	print_label(label(label3, (sizeof(label3) / sizeof(label3[0]))));

	cout << "\n\nFunction bmi():\n1. ->  ";
	print_bmi(bmi(people));
	cout << "2. ->  ";
	print_bmi(bmi(people2));

	cout << "\n\nFunction bmi():\n1. ->  ";
	print_bmi(bmi2(people_names, people_weights, people_heights));
	cout << "2. ->  ";
	print_bmi(bmi2(people_names2, people_weights2, people_heights2));

	cout << "\n\nFunction prime():\n1. ->  " << prime(10)
		 << "\n2. ->  " << prime(48)
	     << "\n3. ->  " << prime(203) << endl;

	cout << "\n\nFunction palindrome(): \n1. racecar(true) ->  " << palindrome("racecar")
		<< "\n2. mleko(false) ->  " << palindrome("mleko")
		<< "\n3. pericarezeracirep(true) ->  " << palindrome("pericarezeracirep")
		<< "\n4. 0(true) ->  " << palindrome("0")
		<< "\n5. 02(false) ->  " << palindrome("02")
		<< "\n6. malacglam(false) ->  " << palindrome("malacglam") << endl;

}
