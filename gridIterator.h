/*
	oniel toledo
	cs 302 section 1001
	project 06: gridIterator header file
	File Description:
	 The following file contains the class declartions
	 for the gridIterator object
*/
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

struct linkedList{
	int element;
	int numbOfOccurances;
	linkedList *next;
};

class gridIterator{
 public:
 	//grid iterations
 	gridIterator(); //construtor
 	void loadGrid(); 	//load data to grid
 	int recurse(int, int);
 	void printGroupOccurances();
 	//linked list iterations
 	int findSize(int);
 	void incSize(int);
 	void push(const int);
 private:
 	int rows;
 	int columns;
 	vector<vector<int> > matrix;
 	linkedList* top;
 	int listCount;
};