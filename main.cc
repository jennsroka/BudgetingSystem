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
    a.input(ins);
    budget set;
    double car, cloth, rent, food, utility;
    budget spent(car, cloth, rent, food, utility);
    while (true){
	cout<<"MENU:"<<endl;
	cout<<"1- add your spent for today" <<endl;
	cout<<"2- List all spent" <<endl;
	cout<<"3- reset the monthly budget" <<endl;
	cout<<"0- Exit and save" <<endl;
	int option;
	cin>>option;
	if (option ==0){
		break;}
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
			a.output(outs);
			outs.close();
			break;
		}
		}	
   
    return 0;
}
