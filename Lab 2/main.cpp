/*
 * main.cpp
 *
 *  Created on: Sep 12, 2017
 *      Author: Michael Ly
 */

/* Michael Ly
 * TA: Eeshita Biswas
 * 9/12/17
 * This file contains functions for Lab 2.
 */

#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <array>
using namespace std;

// Function Declarations
string reverseStr(string x, int len, string y);
/* Returns a reversed string of the input string.
 * Arguments: x: string as an input.
 * 			  len: the length of the input string in terms of the number of characters within the string.
 * 			  y: the final output of the reversed string, empty by default.
 */

int sumdigs(int x, int sum);
/* Returns the sum of the digits within the input integer.
 * Arguments: x: integer as an input.
 * 			  sum: the final output of the sum of the digits, 0 by default.
 */

int min(int arr[], int final);
/* Returns the minimum value within the input array.
 * Arguments: arr[]: array as an input.
 * 			  final: the final index of the input array. e.g. In an array with 5 elements,
 * 			  		 the final index would be 4. In an array with 6 elements, the final
 * 			  		 index would be 5.
 */

bool elfish(string str, int pos, bool ctnsE, bool ctnsL, bool ctnsF);
bool elfish2(string str, int pos, bool ctnsE, bool ctnsL, bool ctnsF);
bool Einstr(string str, int pos, bool ctnsE);

bool isPerfect(int num, int factor, int sum);
/* Returns a boolean determining whether the input integer is a perfect number.
 * Arguments: num: integer as an input.
 * 			  factor: an input integer used to determine the factors of the input integer
 * 			  		  except for the integer itself, 1 by default.
 * 			  sum: the sum of the factors, 0 by default.
 */

// Testing Arrays
int arr1[] = {1, 2, 3, 4, 5};
int arr2[] = {9, 14, 88, 4, 10, 12};
int arr3[] = {25, 6, 6, 7, 22, -1};
int arr4[] = {4};


// Test Cases
int main() {

	cout << "PART I" << endl;
	cout << "Problem 1" << endl;
 	cout << "Test 1: " << reverseStr("map", 3, "") << endl; // Expected output is pam.
	cout << "Test 2: " << reverseStr("apple", 5, "") << endl; // Expected output is elppa.
	cout << "Test 3: " << reverseStr("plane", 5, "") << endl; // Expected output is enalp.
	cout << "****************************************" << endl;

	cout << "Problem 2" << endl;
	cout << "Test 1: " << sumdigs(1234, 0) << endl; // Expected output is 10.
	cout << "Test 2: " << sumdigs(123456, 0) << endl; // Expected output is 21.
	cout << "Test 3: " << sumdigs(5432, 0) << endl; // Expected output is 14.
	cout << "****************************************" << endl;

	cout << "Problem 3" << endl;
	cout << "Test 1: " << min(arr1, 4) << endl; // Expected output is 1.
	cout << "Test 2: " << min(arr2, 5) << endl; // Expected output is 4.
	cout << "Test 3: " << min(arr3, 5) << endl; // Expected output is -1.
	cout << "****************************************" << endl;

	cout << "Problem 4" << endl; // Not working
	cout << elfish("selfish", 6, false, false, false) << endl;
	cout << elfish("nick", 3, false, false, false) << endl;
	cout << elfish2("selfish", 6, false, false, false) << endl;
	cout << elfish2("nick", 3, false, false, false) << endl;
	cout << "****************************************" << endl;

	cout << "Problem 5" << endl;
	cout << "Test 1: " << isPerfect(28, 1, 0) << endl; // Expected output is 1, meaning true.
	cout << "Test 2: " << isPerfect(4, 1, 0) << endl; // Expected output is 0, meaning false.
	cout << "Test 3: " << isPerfect(496, 1, 0) << endl; // Expected output is 1, meaning true.
	cout << "****************************************" << endl;

	cout << "This is just for testing:" << endl;
	cout << Einstr("see", 2, false) << endl;
	cout << Einstr("eagle", 4, false) << endl;
	cout << Einstr("constant", 7, false) << endl;

	cout << "Problem 6" << endl;

	return 0;
}


// Part 1:
// Problem 1
string reverseStr(string x, int len, string y) {
	if (len < 0) {
		return y;
	}
	else {
		return reverseStr(x, len-1, y+string(1, x[len-1]));
	}
}

// Problem 2
int sumdigs(int x, int sum) {
	if (x < 1) {
		return sum;
	}
	else {
		return sumdigs(x/10, sum+x%10);
	}
}

// Problem 3
int min(int arr[], int final) {
	if (final == 0) {
		return arr[0];
	}
	else {
		if (arr[final] <= min(arr, final-1)) {
			return arr[final];
		}
		else {
			return min(arr, final-1);
		}
	}
}

// Problem 4
bool elfish(string str, int pos, bool ctnsE, bool ctnsL, bool ctnsF) {
	if (ctnsE == false) {
		if (pos < 0) {
			return ctnsE;
		}
		else if (str[pos] == 'e') {
			return elfish(str, pos-1, true, ctnsL, ctnsF);
		}
		else {
			return elfish(str, pos-1, ctnsE, ctnsL, ctnsF);
		}
	}
	else if (ctnsL == false) {
		if (pos < 0) {
			return ctnsL;
		}
		else if (str[pos] == 'l') {
			return elfish(str, pos-1, ctnsE, true, ctnsF);
		}
		else {
			return elfish(str, pos-1, ctnsE, ctnsL, ctnsF);
		}
	}
	else if (ctnsF == false) {
		if (pos < 0) {
			return ctnsF;
		}
		else if (str[pos] == 'f') {
			return elfish(str, pos-1, ctnsE, ctnsL, true);
		}
		else {
			return elfish(str, pos-1, ctnsE, ctnsL, ctnsF);
		}
	}
	else if (ctnsE==true && ctnsL==true && ctnsF==true) {
		return true;
	}
	else {
		return false;
	}

}
bool elfish2(string str, int pos, bool ctnsE, bool ctnsL, bool ctnsF) {
	if (ctnsE==false || ctnsL==false || ctnsF==false) {
		if (pos < 0) {
			return ctnsE;
			return ctnsL;
			return ctnsF;
		}
		else if (str[pos] == 'e') {
			return elfish(str, pos-1, true, ctnsL, ctnsF);
		}
		else if (str[pos] == 'l') {
			return elfish(str, pos-1, ctnsE, true, ctnsF);
		}
		else if (str[pos] == 'f') {
			return elfish(str, pos-1, ctnsE, ctnsL, true);
		}
		else {
			return elfish(str, pos-1, ctnsE, ctnsL, ctnsF);
		}
	}
	if (ctnsE==true && ctnsL==true && ctnsF==true) {
		return true;
	}
	else {
		return false;
	}
}

bool Einstr(string str, int pos, bool ctnsE) {
	if (pos < 0) {
		return ctnsE;
	}
	else if (str[pos] == 'e') {
		return Einstr(str, pos-1, true);
	}
	else {
		return Einstr(str, pos-1, ctnsE);
	}
}


// Problem 5
bool isPerfect(int num, int factor, int sum) {
	if (factor < num) {
		if (factor == num) {
			return sum;
		}
		else if (num%factor == 0) {
			return isPerfect(num, factor+1, sum+factor);
		}
		else {
			return isPerfect(num, factor+1, sum);
		}
	}
	else if (sum == num) {
		return true;
	}
	else {
		return false;
	}
}

// Problem 6



// Part 2:
// Problem 1
bool order1(int* x, int* y) {
	if (*x < *y) {
		return false;
	}
	else {
		return true;
	}
}

