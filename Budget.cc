#include "Budget.h"
#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>
#include <fstream>

using namespace std;
void budget::reset(budget &q){
    cout<<"Please enter your monthly budget components"<<endl;
    cout<<"Budget constraints of car:";
    cin>>q.car;
    cout<<"Budget constraints of clothes:";
    cin>>q.cloth;
    cout<<"Budget constraints of rent:";
    cin>>q.rent;
    cout<<"Budget constraints of food:";
    cin>>q.food;
    cout<<"Budget constraints of utility:";
    cin>>q.utility;}

void budget::get_spent(budget &s){
    cout << "Let's start! Type in how much you spent so far! \n";
    cout << "__________________________________________________ \n"; 
    cout << "-------------------------------------------------- \n";
    cout << "1- add spent for car"<<endl;
    cout << "2- add spent for clothes"<<endl;
    cout << "3- add spent for rent"<<endl;
    cout << "4- add spent for food"<<endl;
    cout << "5- add spent for utilities"<<endl;
    int num;
    cin>>num;
    switch(num){
	case 1:
    	    cout << "Spent on car (input number only) \n";
            cin >> s.car;
	    break;
	case 2:
    	    cout << "Spent on clothes (input number only) \n";
    	    cin >> s.cloth;
	    break;
	case 3:
    	    cout << "Spent for rent (input number only) \n";
    	    cin >> s.rent;
	    break;
	case 4:
    	    cout << "Spent on food (input number only) \n";
    	    cin >> s.food;
	    break;
	case 5:
    	    cout << "Spend on utilities (input number only) \n";
    	    cin >> s.utility;
	    break;
    }
    cout<<"Do you want to add another? (y/n)"<<endl;
    char opt;
    cin>>opt;
    while(opt == 'y'){
    	cout << "1- add spent for car"<<endl;
    	cout << "2- add spent for clothes"<<endl;
    	cout << "3- add spent for rent"<<endl;
    	cout << "4- add spent for food"<<endl;
    	cout << "5- add spent for utilities"<<endl;
    	int num;
    	cin>>num;
    	switch(num){
		case 1:
    		    cout << "Spent on car (input number only) \n";
        	    cin >> s.car;
		    break;
		case 2:
    		    cout << "Spent on clothes (input number only) \n";
    		    cin >> s.cloth;
		    break;
		case 3:
    		    cout << "Spent for rent (input number only) \n";
    		    cin >> s.rent;
		    break;
		case 4:
    		    cout << "Spent on food (input number only) \n";
    		    cin >> s.food;
		    break;
		case 5:
    		    cout << "Spend on utilities (input number only) \n";
    		    cin >> s.utility;
		    break;
    	}
	cout<<"Do you want to adding another? (y/n)"<<endl;
    	cin>>opt;}
}

void budget::display(budget x, budget y){
    double total, spent;
    cout<<endl<<"Monthly budget report"<<endl;
    cout<<"Car: $";
    calculate(x.car,y.car);
    cout<<"Cloth: $";
    calculate(x.cloth,y.cloth);
    cout<<"Rent: $";
    calculate(x.rent,y.rent);
    cout<<"Food: $";
    calculate(x.food,y.food);
    cout<<"Utility: $";
    calculate(x.utility,y.utility);

    total = x.car+x.cloth+x.rent+x.food+x.utility;
    spent = y.car+y.cloth+y.rent+y.food+y.utility;
    cout<<"Total Monthly budget constraints: $"<<total<<endl;
    cout<<"Total spent: $"<<spent<<endl;
    cout<<"Total: $";
    calculate(total,spent);
}

void budget::calculate(double a, double b){
    cout<<fixed<<showpoint<<setprecision(2);
    if(a>b){
        cout<<setw(7)<<a-b;
        cout<<" under. \n";
    }
    else{
        cout<<setw(7)<<b-a;
        cout<<" over. \n";
    }
}

void budget::output(std::ofstream& outs){
        outs << car << endl;
        outs << cloth << endl;
        outs << rent << endl;
        outs << food << endl;
        outs << utility << endl;
}

void budget::input(std::ifstream& ins){
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
	cout << "Your current amount spent for each category is: " << endl;
	cout << "Car: $" << car << endl;
	cout << "Clothes: $" << cloth << endl;
	cout << "Rent: $" << rent << endl;
	cout << "Food: $" << food << endl;
	cout << "Utilities: $" << utility << endl;
    }
    ins.close();
}

std::ifstream& operator >>(std::ifstream& ins, budget& a){
	a.input(ins);
	return ins;
}

std::ofstream& operator <<(std::ofstream& outs, budget& a){
	a.output(outs);
	return outs;
}
