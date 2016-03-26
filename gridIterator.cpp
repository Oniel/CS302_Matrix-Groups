/*
	oniel toledo
	cs 302 section 1001
	project 06: gridIterator header file
	File Description:
	 Implementation file for gridIterator object
*/
#include "gridIterator.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

//Class implementation functions
gridIterator::gridIterator(){
	rows =0;
	columns =0;
	listCount=0;
	top = NULL;
}

//Prompt user for file name and load matrix to class vector 'matrix'
void gridIterator::loadGrid(){
	//input file variables
	string fileName;
	string stringRows;
	string stringColumns;
	char charMatrixNum;
	ifstream inFile;
	//prompt the user for input file
	cout << "Please enter the input file name: ";
	cin >> fileName;
	//open file, error check
	inFile.open(fileName.c_str());
	if(!inFile){ cout << "File name invalid, file could not be found." << endl; goto badFile;}
	//read rows and cols from file, convert strings to integers and save
	getline(inFile, stringRows);
	rows = atoi(stringRows.c_str());
	getline(inFile, stringColumns);
	columns = atoi(stringColumns.c_str());
	//resize vector
	matrix.resize(rows);
	for(int i=0; i<rows;i++)
			matrix[i].resize(columns);
	//fill vector with data
	for(int i=0; i<rows; i++){
		for(int j=0; j<columns;j++){
			inFile >> charMatrixNum;
			(charMatrixNum=='0') ? matrix[i][j]=0 : matrix[i][j]=1;
		}
	}
	int sizeOfSet;
	//loop to find contiguous groups of 1s in the 2D matrix,
	//(diagnal continuity not taken into consideration)
	for(int r=0;r<rows;r++){
		for(int c=0;c<columns;c++){
			sizeOfSet = gridIterator::recurse(r, c);
			if(sizeOfSet!=0)
				if(findSize(sizeOfSet)==0)
					push(sizeOfSet);
				else if(findSize(sizeOfSet)==1)
					incSize(sizeOfSet);
		}	
	}
	//printGroupOccurances();
	badFile:;
}

//find the location of item and increment it's numbOfOccurances by 1
void gridIterator::incSize(int item){
	linkedList *current = top;
	while(current!=NULL){
		if(current->element==item){
			current->numbOfOccurances += 1;
			break;
			}
		else
			current = current->next;
	}

}

//determines if the passed item is already on the linked list, if it is
//returns 1 else if not found returns 0
int gridIterator::findSize(int item){
	linkedList *current = top;
	while(current!=NULL){
		if(current->element==item)
			return 1;
		else
			current = current->next;
	}
	return 0;
}

//recurse over group of 1s
int gridIterator::recurse(int x, int y){
	//inductive step->for all v==1 recurse for non-diagnal neighbors of v
	if(matrix[x][y]==1){
		matrix[x][y]=0;
		return (recurse(x+1, y) + recurse(x-1, y) +
			recurse(x, y+1) + recurse(x, y-1) + 1);
	}
	//base case->for all v==0 stop recursion and return 0
	if(matrix[x][y]==0)
		return 0;
}
void gridIterator::push(const int newItem){
	linkedList *newNode = new linkedList;
	newNode->element = newItem;
	newNode->numbOfOccurances = 1;
	newNode->next = top;
	top = newNode;
	listCount++;
}

//prints out the data from the linkedList which holds the size of groups
//and the number of occurances for each
void gridIterator::printGroupOccurances(){
	//selelection sort is used to sort the stack
	linkedList *current = top;
	linkedList *i = new linkedList;
	linkedList *j = new linkedList;
	linkedList *index = new linkedList;
	linkedList *small = new linkedList;
	for(i=top; i!=NULL;i=i->next){

		small->element = i->element;
		small->numbOfOccurances = i->numbOfOccurances;
		index=i;
		for(j=i; j!=NULL; j=j->next){
			if(j->element > small->element){
				small->element = j->element;
				small->numbOfOccurances = j->numbOfOccurances;
				index=j;
			}
		}
		index->element = i->element;
		index->numbOfOccurances = i->numbOfOccurances;
		i->element = small->element;
		i->numbOfOccurances = small->numbOfOccurances;
	}
	//print out the grid
	cout << setfill(' ') << setw(12) << left << "Group Size" << setw(16) << "Number of Groups" << endl;
	while(current!=NULL){
		cout << " " <<setw(12) << current->element << setw(16) << current->numbOfOccurances << endl;
		current = current->next;
	}
	//to print list in appropriate order will use selection sort


}