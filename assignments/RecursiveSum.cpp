/*
    Lab Assignment - Recursive Sum

    This basic C++ program uses recursion to calculate the sum
    of all positive integers from 1 to a user-provided number.

    Key features:
    - User input
    - Recursive function
    - Base and recursive cases

    Created by:
    - Adam Huynh
    - CS 236 Fall Semester LAVC
    - 10/09/2026
*/

#include <iostream>

using namespace std;

int sumToN(int n) {
	//base case
	if (n == 1)
		return 1;

	// recussive call
	return n + sumToN(n - 1);
}

int main() {

	int userInput;

	cout << "Enter a positive integer: ";
	cin >> userInput;

	cout << "The sum from 1 to " << userInput << " is " << sumToN(userInput);

	return 0;
}
