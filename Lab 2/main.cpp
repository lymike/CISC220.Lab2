/*
 * main.cpp
 *
 *  Created on: Sep 12, 2017
 *      Author: Michael Ly
 */

/* Michael Ly
 * TA: Eeshita Biswas
 * 9/12/17
 * Lab 2
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

bool elfish2(string str, int pos);

bool isPerfect(int num, int factor, int sum);
/* Returns a boolean determining whether the input integer is a perfect number.
 * Arguments: num: integer as an input.
 * 			  factor: an input integer used to determine the factors of the input integer
 * 			  		  except for the integer itself, 1 by default.
 * 			  sum: the sum of the factors, 0 by default.
 */

void printX(int count, int row);
/* Prints out an X shape corresponding to the input integer.
 * Arguments: count: integer as an input.
 * 			  row: number of rows being print out, value of 1 by default.
 */
void printLine(int count, int row);
//Helper function to be called within the function above.

bool order1(int* x, int* y);
/* Returns a boolean determining whether the first integer passed in is greater or less than
 * the second integer. If it is greater, return false and swap the two integers. If it is false,
 * return true and the integers remain the same.
 * Arguments: *x: a pointer that stores the address of the first integer.
 *            *y: a pointer that stores the address of the second integer.
 */

bool order2(int& x, int& y);
/* Returns a boolean determining whether the first integer passed in is greater or less than
 * the second integer. If it is greater, return false and swap the two integers. If it is false,
 * return true and the integers remain the same.
 * Arguments: &x: reference of the first integer passed in.
 *            &y: reference of the second integer passed in.
 */

void printAddressX(int* p);
/* Prints out the value at the address of the input, the address in the input parameter, and the
 * address of the input parameter.
 * Argument: *p: a pointer that stores the address of the input.
 *
 */

void printAddressY(int& r);
/* Prints out the address and the value of the input parameter.
 * Argument: &r: reference of the input.
 */

void createArr(int arr[20], int len);
/* Creates an array with the size of 20 and fill in each slot of the array with a random integer
 * between 0 and 100, not including 100.
 * Arguments: arr[20]: input array with a size of 20.
 *            len: the size of the array passed in.
 */

void printArr(int arr[], int len);
/* Prints out all the values within the input array.
 * Arguments: arr[]: input array.
 *            len: the size of the array passed in.
 */

void printMin(int arr[], int len, int& val, int& pos);
/* Prints out the minimum value of the array and the location of the value within the input array.
 * Arguments: arr[]: input array.
 * 			  len: the size of the array passed in.
 * 			  &val: value of the array passed by reference, -1 by default.
 * 			  &pos: position of the array within the array, -1 by default.
 */

void printAddresses(int arr[], int len);
/* Returns the addresses of every member(integers) within the array.
 * Arguments: arr[]: input array of integers.
 *  		  len: the size of the array passed in.
 */

void printDoubleAddresses(double arr[], int len);
/* Returns the addresses of every member(doubles) within the array.
 * Arguments: arr[]: input array of doubles.
 *  		  len: the size of the array passed in.
 */

// Testing Arrays
int arr1[] = {1, 2, 3, 4, 5};
int arr2[] = {9, 14, 88, 4, 10, 12};
int arr3[] = {25, 6, 6, 7, 22, -1};
int arr4[] = {4};
int arr5[] = {14, 10, 7, 8, 5};


// Test Cases and Variables
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
	cout << elfish2("selfish", 6) << endl;
	cout << elfish2("come", 3) << endl;
	cout << "****************************************" << endl;

	cout << "Problem 5" << endl;
	cout << "Test 1: " << isPerfect(28, 1, 0) << endl; // Expected output is 1, meaning true.
	cout << "Test 2: " << isPerfect(4, 1, 0) << endl; // Expected output is 0, meaning false.
	cout << "Test 3: " << isPerfect(496, 1, 0) << endl; // Expected output is 1, meaning true.
	cout << "****************************************" << endl;

	cout << "Problem 6" << endl;
	cout << "Test 1: " << endl;
	printX(5, 1); // Expected output is an X shape like the problem described in the lab.
	cout << "Test 2: " << endl;
	printX(6, 1); // Expected output is an X shape corresponding to the input integer.
	cout << "Test 3: " << endl;
	printX(3, 1); // Expected output is an X shape corresponding to the input integer.
	cout << "****************************************" << endl;

	cout << "Part II" << endl;
	cout << "Problem 1" << endl;
	int a1 = 35;
	int b1 = 20;
	int a2 = 12;
	int b2 = 24;
	int a3 = 11;
	int b3 = 11;
	cout << "Case 1: If the first integer passed in is greater than the second integer: " << endl;
	cout << "Before the function call, a1=" << a1 << ", b1=" << b1 << "." << endl;
	cout << order1(&a1, &b1) << endl; // Expected output is 0, meaning false. Two values swap.
	cout << "After the function call, a1=" << a1 << ", b1=" << b1 << "." << endl;
	cout << "Case 2: If the first integer passed in is less than the second integer: " << endl;
	cout << "Before the function call, a2=" << a2 << ", b2=" << b2 << "." << endl;
	cout << order1(&a2, &b2) << endl; // Expected output is 1, meaning true. Two values don't swap.
	cout << "After the function call, a2=" << a2 << ", b2=" << b2 << "." << endl;
	cout << "Case 3: If the first integer passed in is equal to the second integer: " << endl;
	cout << "Before the function call, a3=" << a3 << ", b3=" << b3 << "." << endl;
	cout << order1(&a3, &b3) << endl; // Expected output is 1, meaning true. Two values don't swap.
	cout << "After the function call, a3=" << a3 << ", b3=" << b3 << "." << endl;
	cout << "****************************************" << endl;

	cout << "Problem 2" << endl;
	int a4 = 40;
	int b4 = 15;
	int a5 = 22;
	int b5 = 47;
	int a6 = 27;
	int b6 = 27;
	cout << "Case 1: If the first integer passed in is greater than the second integer: " << endl;
	cout << "Before the function call, a4=" << a4 << ", b4=" << b4 << "." << endl;
	cout << order2(a4, b4) << endl; // Expected output is 0, meaning false. Two values swap.
	cout << "After the function call, a4=" << a4 << ", b4=" << b4 << "." << endl;
	cout << "Case 2: If the first integer passed in is less than the second integer: " << endl;
	cout << "Before the function call, a5=" << a5 << ", b5=" << b5 << "." << endl;
	cout << order2(a5, b5) << endl; // Expected output is 1, meaning true. Two values don't swap.
	cout << "After the function call, a5=" << a5 << ", b5=" << b5 << "." << endl;
	cout << "Case 3: If the first integer passed in is equal to the second integer: " << endl;
	cout << "Before the function call, a6=" << a6 << ", b6=" << b6 << "." << endl;
	cout << order2(a6, b6) << endl; // Expected output is 1, meaning true. Two values don't swap.
	cout << "After the function call, a6=" << a6 << ", b6=" << b6 << "." << endl;
	cout << "****************************************" << endl;

	cout << "Problem 3" << endl;
	int x = 7;
	cout << "Since x=7, the address of x=" << &x << endl;
	cout << "After passing in the address of x to the function..." << endl;
	printAddressX(&x);
	cout << "****************************************" << endl;

	cout << "Problem 4" << endl;
	int y = 14;
	cout << "Since y=14, the value in y is " << y << ", and the address of y is " << &y << endl;
	cout << "After passing in the address of y to the function..." << endl;
	printAddressY(y);
	cout << "****************************************" << endl;

	cout << "Problem 5" << endl;
	int fillarr[20];
	createArr(fillarr, 20);
	cout << "Test: the array printed out below:" << endl;
	for (int i=0; i<20; i++) {
		if (i == 0) {
			cout << "{" << fillarr[i] << ", ";
		}
		else if (i == 19) {
			cout << fillarr[i] << "}" << endl;
		}
		else {
			cout << fillarr[i] << ", ";
		}
	}
	cout << "****************************************" << endl;

	cout << "Problem 6" << endl;
	cout << "Test 1: ";
	printArr(arr1, 5); // Expected all integers from arr1 printed out.
	cout << "Test 2: ";
	printArr(arr2, 6); // Expected all integers from arr2 printed out.
	cout << "Test 3: ";
	printArr(arr3, 6); // Expected all integers from arr3 printed out.
	cout << "****************************************" << endl;

	cout << "Problem 7" << endl;
	int val1=-1, pos1=-1, val2=-1, pos2=-1, val3=-1, pos3=-1;
	cout << "Test 1: " << endl;
	cout << "Before the modification, the initial value of the minimum value is: " << val1 << ", " << endl;
	cout << "the initial position of the minimum value is: " << pos1 << endl;
	cout << "After the modification..." << endl;
	printMin(arr1, 5, val1, pos1); // Expected value output is 1, with a position of 0.
	cout << endl;
	cout << "Test 2: " << endl;
	cout << "Before the modification, the initial value of the minimum value is: " << val2 << ", " << endl;
	cout << "the initial position of the minimum value is: " << pos2 << endl;
	cout << "After the modification..." << endl;
	printMin(arr2, 6, val2, pos2); // Expected value output is 4, with a position of 3.
	cout << endl;
	cout << "Test 3: " << endl;
	cout << "Before the modification, the initial value of the minimum value is: " << val3 << ", " << endl;
	cout << "the initial position of the minimum value is: " << pos3 << endl;
	cout << "After the modification..." << endl;
	printMin(arr5, 5, val3, pos3); // Expected value output is 5, with a position of 4.
	cout << "****************************************" << endl;

	cout << "Problem 8" << endl;
	cout << "Test 1: " << endl;
	printAddresses(arr1, 5); // Expected output of an array of the addresses of values in arr1.
	cout << "Test 2: " << endl;
	printAddresses(arr2, 6); // Expected output of an array of the addresses of values in arr2.
	cout << "Test 3: " << endl;
	printAddresses(arr3, 6); // Expected output of an array of the addresses of values in arr3.
	cout << "****************************************" << endl;

	cout << "Problem 9" << endl;
	double Darr1[] = {1.2, 3.6, 7.4, 6.8, 11.2, 88.1};
	double Darr2[] = {3.7, 11.0, 2.4, 4.5, 9.9};
	double Darr3[] = {4.1, 3.8, 2.2, 8.3, 23.1};
	cout << "Test 1: " << endl;
	printDoubleAddresses(Darr1, 6); // Expected output of an array of the addresses of values in Darr1.
	cout << "Test 2: " << endl;
	printDoubleAddresses(Darr2, 5); // Expected output of an array of the addresses of values in Darr2.
	cout << "Test 3: " << endl;
	printDoubleAddresses(Darr3, 5); // Expected output of an array of the addresses of values in Darr3.
	cout << "****************************************" << endl;

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

// Problem 4 (not working)
bool elfish2(string str, int pos) {
	bool ctnsE=false, ctnsL=false, ctnsF=false;
	if (pos < 0) {
		return ctnsE;
		return ctnsL;
		return ctnsF;
	}
	else if (str[pos] == 'e') {
		ctnsE = true;
	}
	else if (str[pos] == 'l') {
		ctnsL = true;
	}
	else if (str[pos] == 'f') {
		ctnsF = true;
	}
	else {
		return elfish2(str, pos-1);
	}
	if (ctnsE==true && ctnsL==true && ctnsF==true) {
		return true;
	}
	else {
		return false;
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
void printX(int count, int row) {
	if (row == count*2-1) {
		printLine(count, row);
	}
	else {
		printLine(count, row);
		printX(count, row+1);
	}
}
void printLine(int count, int row) {
	int space, spacebtw;
	if (row < count) {
		spacebtw = (2*count-1)-2*row;
		space = row-1;
	}
	else if (row > count) {
		spacebtw = 2*row-(2*count+1);
		space = (2*count-1)-row;
	}
	else {
		spacebtw = 0;
		space = row-1;
	}
	for (int i=0; i<=space; i++) {
		if (i == space) {
			if (space == count-1) {
				cout << "";
			}
			else {
				cout << "*";
			}
		}
		else {
			cout << " ";
		}
	}
	for (int i=0; i<=spacebtw; i++) {
		if (i == spacebtw) {
			cout << "*" << endl;
		}
		else {
			cout << " ";
		}
	}
}



// Part 2:
// Problem 1
bool order1(int* x, int* y) {
	if (*x <= *y) {
		return true;
	}
	else {
		int z = *x;
		*x = *y;
		*y = z;
		return false;
	}
}

// Problem 2
bool order2(int& x, int& y) {
	if (x <= y) {
		return true;
	}
	else {
		int z = x;
		x = y;
		y = z;
		return false;
	}
}

// Problem 3
void printAddressX(int* p) {
	cout << "The value of the address is: " << *p << "." << endl;
	cout << "The address in the parameter is: " << p << "." << endl;
	cout << "The address of the parameter is: " << &p << "." << endl;
}

// Problem 4
void printAddressY(int& r) {
	cout << "The address of the input parameter is: " << &r << "." << endl;
	cout << "The value of the input parameter is: " << r << "." << endl;
}

// Problem 5
void createArr(int arr[20], int len) {
	for (int i=0; i<len; i++) {
		arr[i] = rand() % 100;
	}
}

// Problem 6
void printArr(int arr[], int len) {
	for (int i=0; i<len; i++) {
		if (i == 0) {
			cout << "{" << arr[i] << ", ";
		}
		else if (i == len-1) {
			cout << arr[i] << "}" << endl;
		}
		else {
			cout << arr[i] << ", ";
		}
	}
}

// Problem 7
void printMin(int arr[], int len, int& val, int& pos) {
	int min = arr[0];
	for (int i=0; i<len; i++) {
		if (arr[i] < min) {
			min = arr[i];
		}
	}
	val = min;
	for (int i=0; i<len; i++) {
		if (arr[i] == min) {
			pos = i;
		}
	}
	cout << "The value of the minimum value in this array is: " << val << endl;
	cout << "The location of this value is: " << pos << endl;
}

// Problem 8
void printAddresses(int arr[], int len) {
	cout << "{";
	for (int i=0; i<len; i++) {
		if (i<len-1) {
			cout << &arr[i] << ", ";
		}
		else {
			cout << &arr[i];
		}
	}
	cout << "}" << endl;
}

// Problem 9
void printDoubleAddresses(double arr[], int len) {
	cout << "{";
	for (int i=0; i<len; i++) {
		if (i<len-1) {
			cout << &arr[i] << ", ";
		}
		else {
			cout << &arr[i];
		}
	}
	cout << "}" << endl;
}
