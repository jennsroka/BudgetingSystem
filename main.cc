/** 
	@file main.cc
	@brief this file runs the program and uses the Budget class to determine spent amounts and how those pertain to the monthly budget
**/

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include "Budget.h"

using namespace std;
int menu();

/**
	@brief this is the main function that runs the program
	@return is int
**/
int main(){
    int choice;
    ofstream outs;
    ifstream ins;
    double car, cloth, rent, food, utility;
    budget a;
    budget set;
    budget spent(car, cloth, rent, food, utility);

    ins.open("budgeting.csv");
    if(ins.is_open()){
	cout << "File has been opened" << endl;
    }
    else{
	cout << "NO FILE HAS BEEN OPENED" << endl;
    }

    a.input(ins, spent, set);
    ins.close();

    choice = menu();
    while (choice!=0){
	switch(choice){
		case 1:
			a.get_spent(spent);
			break;
		case 2:
			a.display(set,spent);
			break;
		case 3:
			a.reset(set);
			break;
		case 0:
			cout << "Thank you for using Budgeting!" << endl;
			break;
		default:
			cout << "Not an option." << endl;
			break;
		}
	choice = menu();
	}

    outs.open("budgeting.csv");
    if(!outs.fail()){
	a.output(outs, spent, set);
    }
    else
        cout<<"Problem with saving data!\n";
    outs.close();
    return 0;
}
/**
        @brief this function calls the menu where the user can then input their choice
        @return is int
**/
int menu(){
	int choice;
	cout<<"MENU:"<<endl;
        cout<<"1- add your spent for today" <<endl;
        cout<<"2- List all spent" <<endl;
        cout<<"3- reset the monthly budget" <<endl;
        cout<<"0- Exit and save" <<endl;
        cout << "Choice: ";
	cin >> choice;
	
	return choice;
}
