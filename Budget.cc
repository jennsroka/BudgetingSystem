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
    cout << "Choice: ";
    int num;
    cin>>num;
    switch(num){
	case 1:
    	    cout << "Spent on car (input number only) \n";
	    double new_car;
            cin >> new_car;
	    s.car += new_car;
	    break;
	case 2:
    	    cout << "Spent on clothes (input number only) \n";
	    double new_cloth;
    	    cin >> new_cloth;
	    s.cloth += new_cloth;
	    break;
	case 3:
    	    cout << "Spent for rent (input number only) \n";
	    double new_rent;
    	    cin >> new_rent;
	    s.rent += new_rent;
	    break;
	case 4:
    	    cout << "Spent on food (input number only) \n";
	    double new_food;
    	    cin >> new_food;
	    s.food += new_food;
	    break;
	case 5:
    	    cout << "Spend on utilities (input number only) \n";
	    double new_utility;
    	    cin >> new_utility;
	    s.utility += new_utility;
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
		    double car2;
            	    cin >> car2;
            	    s.car += car2;
		    break;
		case 2:
    		    cout << "Spent on clothes (input number only) \n";
		    double cloth2;
    	    	    cin >> cloth2;
	   	    s.cloth += cloth2;
		    break;
		case 3:
    		    cout << "Spent for rent (input number only) \n";
    		    double rent2;
    	    	    cin >> rent2;
	    	    s.rent += rent2;
		    break;
		case 4:
    		    cout << "Spent on food (input number only) \n";
    		    double food2;
    	   	    cin >> food2;
	    	    s.food += food2;
		    break;
		case 5:
    		    cout << "Spend on utilities (input number only) \n";
    		    double utility2;
    	    	    cin >> utility2;
	    	    s.utility += utility2;
		    break;
    	}
	cout<<"Do you want to adding another? (y/n)"<<endl;
    	cin>>opt;}
}

void budget::display(budget &x, budget &y){
    double total, spent;
    cout<<endl<<"Monthly budget report"<<endl;
    cout<<"Car spent: $" << y.car << endl;
    calculate(x.car,y.car);
    cout<<"Cloth spent: $" << y.cloth << endl;
    calculate(x.cloth,y.cloth);
    cout<<"Rent spent: $" << y.rent << endl;
    calculate(x.rent,y.rent);
    cout<<"Food spent: $" << y.food << endl;
    calculate(x.food,y.food);
    cout<<"Utility spent: $" << y.utility << endl;
    calculate(x.utility,y.utility);

    total = x.car+x.cloth+x.rent+x.food+x.utility;
    spent = y.car+y.cloth+y.rent+y.food+y.utility;
    cout<<"Total Monthly budget constraints: $"<<total<<endl;
    cout<<"Total spent: $"<<spent<<endl;
    cout<<"Total: $";
    calculate(total,spent);
}

void budget::calculate(double &a, double &b){
    cout<<fixed<<showpoint<<setprecision(2);
    if(a>b){
        cout<<setw(7)<<a-b;
        cout<<" under budget. \n";
    }
    else if(b>a){
        cout<<setw(7)<<b-a;
        cout<<" over budget. \n";
    }
    else{
	cout << " At budget limit!" << endl;
    }
}
void budget::input(std::ifstream &ins, budget &x, budget &y){
	while(true){
	ins >> x.car;
	ins >> x.cloth;
	ins >> x.rent;
	ins >> x.food;
	ins >> x.utility;
	ins >> y.car;
	ins >> y.cloth;
	ins >> y.rent;
	ins >> y.food;
	ins >> y.utility;
	if(ins.eof()) break;
	cout << "Your current amount spent for each category is: " << endl;
	cout << "Car: $" << x.car << endl;
	cout << "Clothes: $" << x.cloth << endl;
	cout << "Rent: $" << x.rent << endl;
	cout << "Food: $" << x.food << endl;
	cout << "Utilities: $" << x.utility << endl;
	cout << "Your current monthly constraints are: " << endl;
	cout << "Car: $" << y.car << endl;
	cout << "Clothes: $" << y.cloth << endl;
	cout << "Rent: $" << y.rent << endl;
	cout << "Food: $" << y.food << endl;
	cout << "Utilities: $" << y.utility << endl;
	}
}
void budget::output(std::ofstream &outs, budget &x, budget &y){
	outs << x.car << endl;
        outs << x.cloth << endl;
        outs << x.rent << endl;
        outs << x.food << endl;
        outs << x.utility << endl;
	outs << y.car << endl;
        outs << y.cloth << endl;
        outs << y.rent << endl;
        outs << y.food << endl;
        outs << y.utility << endl;
}