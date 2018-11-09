#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include "Budget.h"

using namespace std;
int menu();

int main(){
    int choice;
    ofstream outs;
    ifstream ins;
    double car, cloth, rent, food, utility;
    budget a;

    ins.open("budgeting.csv");
    if(ins.is_open()){
	cout << "File has been opened" << endl;
    }
    else{
	cout << "NO FILE HAS BEEN OPENED" << endl;
    }

    while(!ins.eof()){
	ins >> car;
	ins >> cloth;
	ins >> rent;
	ins >> food;
	ins >> utility;
	if(ins.eof()) break;
	cout << "Your current amount spent for each category is: " << endl;
	cout << "Car: $" << car << endl;
	cout << "Clothes: $" << cloth << endl;
	cout << "Rent: $" << rent << endl;
	cout << "Food: $" << food << endl;
	cout << "Utilities: $" << utility << endl;
    }
    ins.close();
    budget set;
    budget spent(car, cloth, rent, food, utility);
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
	outs << car << endl;
        outs << cloth << endl;
        outs << rent << endl;
        outs << food << endl;
        outs << utility << endl;
    }
    else
        cout<<"Problem with saving data!\n";
    outs.close();
    return 0;
}

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
