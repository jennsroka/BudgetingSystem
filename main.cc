#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include "Budget.h"
using namespace std;
int readInt(string prompt){
	string inputstring;
	int inputInt;
	cout<<prompt;
	getline(cin,inputstring);
	stringstream(inputstring) >> inputInt;
	return inputInt;}

int main(){
    ifstream inFile;
    ofstream outFile;
    double car;
    double clothes;
    double food;
    double utilities;
    double rent;
    inFile.open("budgeting.csv");
    if(inFile.is_open()){
	cout << "File has been opened" << endl;
    }
    else{
	cout << "NO FILE HAS BEEN OPENED" << endl;
    }

    while(!inFile.eof()){
	inFile >> car;
	inFile >> clothes;
	inFile >> food;
	inFile >> utilities;
	inFile >> rent;
	cout << "Car: " << car << endl;
	cout << "Clothes: " << clothes << endl;
	cout << "Food: " << food << endl;
	cout << "Utilities: " << utilities << endl;
	cout << "Rent: " << rent << endl;
    }
    inFile.close();

    budget spent,set;
    budget a;
    while (true){
	cout<<"MENU:"<<endl;
	cout<<"1- add your spent for today" <<endl;
	cout<<"2- " <<endl;
	cout<<"3- " <<endl;
	cout<<"4- " <<endl;	cout<<"5- " <<endl;
	cout<<"6- List all spent " <<endl;
	cout<<"7- " <<endl;
	cout<<"8- " <<endl;
	cout<<"9- reset the monthly budget" <<endl;
	cout<<"0- Exit and save" <<endl;

	int option = readInt("option: ");
	if (option ==0){
		break;}
	switch (option){
		case 1:
			a.get_spent(spent);
			break;	
		case 2:
			break;
		case 3:
			break;	
		case 4:
			break;
		case 5:
			break;	
		case 6:
			a.display(set,spent);
			break;
		case 7:
			break;	
		case 8:
			break;
		case 9:
			a.reset(set);
			break;
		case 0:
			 outFile.open("budgeting.csv");
        		outFile << car << endl;
        		outFile << clothes << endl;
        		outFile << food << endl;
        		outFile << utilities << endl;
        		outFile << rent << endl;
        		outFile.close();
			break;
		}
		}	
   
    return 0;
}
