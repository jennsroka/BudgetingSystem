#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include "Budget.h"
using namespace std;

int main(){
    budget a;
    ofstream outs;
    ifstream ins;
    double car, cloth, rent, food, utility;
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
    while (true){
	cout<<"MENU:"<<endl;
	cout<<"1- add your spent for today" <<endl;
	cout<<"2- List all spent" <<endl;
	cout<<"3- reset the monthly budget" <<endl;
	cout<<"0- Exit and save" <<endl;
	cout << "Choice: ";
	int option;
	cin>>option;
	if (option==0){
		break;
	}
	switch (option){
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
			outs.open("budgeting.csv");
			outs << car << endl;
        		outs << cloth << endl;
        		outs << rent << endl;
        		outs << food << endl;
        		outs << utility << endl;
			outs.close();
			break;
		}
		}	
   
    return 0;
}
