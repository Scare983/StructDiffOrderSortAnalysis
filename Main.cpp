#include <iostream>
#include "Sorting.h"
#include <fstream>
#include <string>
#include <ctime>
using namespace std;

void commandList() {  //basically the menu
	cout << "Commands - " ;
	cout << "insertion-sort (i),       " ;
	cout << "merge-sort (m),       ";
	cout << "quick-sort (q) " << endl;
}

int main(int argc, char *argv[]) {
	if(argc > 2 ) { //case for too many files ,exits
		cout << "Sorry! Too many files inputted, quitting..." << endl;
		return EXIT_SUCCESS;
	}
	if(argc == 1) { //checks if no files inputted, exit
		cout << "Sorry! No file inputted, quitting..." << endl;
		return EXIT_SUCCESS;
	}
	ifstream workingFile; 
	workingFile.open(argv[1], ios::in); //opens file to read from
	commandList();
	int singleNumber;  //placeholder for getting each int in list
		//intilizes list
	
	int arraySize;
	while(workingFile >> singleNumber) {//iterates to null
		arraySize++;
	}
	int myData [arraySize];
	workingFile.clear();
	workingFile.seekg(0, ios::beg);
	int iterate = 0;
		while(workingFile >> singleNumber) {//iterates to null
		myData[iterate] = singleNumber;
		iterate++;
	}
	Sorting currentList = Sorting(myData, arraySize);
	bool keepLooping = true;  //inifinite menu screen until q
	
	while (keepLooping) {//only leave when q is inputted
		
		string command; //tried char, but couldn't figure out how to look at too long of input
		cout << "Enter the algorithm: ";
		cin >> command;
		while(!cin.good()) {
					
					cin.ignore(2147483647, '\n');			//command = input
					cin.clear();
		}
		if(command.length() > 1) {
			cout << "Extracting first character in given string one moment..." << endl;
			int temp = time(NULL) + 1; //pause for 1 second, adds glitter to code.
			while(temp > time(NULL));  
		}
		switch(command.at(0)) { //takes the first character of the string, fixes the infinite loop when char more than 2 was inputted
			
			case 'i' : {
				currentList.insertAlgorithm();
				cout << "Insertion sort: " ; 
				currentList.printList();	
				
				cin.clear();
			keepLooping = false;
			
				cout << endl;
				cout << "		Total # comparisons :  " << currentList.getNumberComparisons() << endl;
			}
					break;
			case 'm' : {
				currentList.mergeAlgorithm();
				cout << "Merge sort:  " << endl;
				keepLooping = false;
				currentList.printList();
				cout << "		Total # comparisons :  " << currentList.getNumberComparisons() << endl;
			}
			break;
			case 'q' : {
				currentList.quickSortAlgorithm();
				cout << "Quick sort:  "  << endl;
				currentList.printList();
								cout << "		Total # comparisons :  " << currentList.getNumberComparisons() << endl;
				keepLooping = false;
			}
				break;
				default: {
					
					cout << "Command not recognized.  Try again." <<  endl;
					
					
				}
				break;
		}
}
	return EXIT_SUCCESS;
}

