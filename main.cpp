/*
	oniel toledo
	cs 302 section 1001
	project 06
	Program Description:
	 the following program prompt the user for an input file containing a matrix
	 of 0's and 1's, groups of 1's represent characters. The program will identify
	 these groups of 1's from the matrix and determine the size of the group, making
	 an output list of the number of groups of size n; this is done for all groups
	 of 1 within the matrix
	 for further information, refer to the comments below
	To compile: $: g++ main.cpp gridIterator.cpp -o main
	 or use compile file: $: chmod +x compile    ./compile (results in executable named main)
*/
#include "gridIterator.h"
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

int main(){
	//all functionality is handled by the gridIterator class
	//loadGrid will prompt for text file, create grid, and find groups via recursion
	gridIterator grid;
	grid.loadGrid();
	//print out the results
	grid.printGroupOccurances();
	return 0;
}