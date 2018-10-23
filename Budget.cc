#include "Budget.h"
#include <iostream>
#include <string>
#include <iomanip>

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
    cout << "Spent on car (input number only) \n";
    cin >> s.car;
    cout << "Spent on clothes (input number only) \n";
    cin >> s.cloth;
    cout << "Spent for rent (input number only) \n";
    cin >> s.rent;
    cout << "Spent on food (input number only) \n";
    cin >> s.food;
    cout << "Spend on utilities (input number only) \n";
    cin >> s.utility;
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

