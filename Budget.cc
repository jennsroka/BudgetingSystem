#include "Budget.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
void budget::get_spent(budget &s){
    cout << "let's start type in how much you spent so far! \n";
    cout << "__________________________________________________ \n"; 
    cout << "-------------------------------------------------- \n";
    cout << "spent for car (input number only) \n";
    cin >> s.car;
    cout << "spent for clothes (input number only) \n";
    cin >> s.cloth;
    cout << "spent with the rent (input number only) \n";
    cin >> s.rent;
    cout << "spent for food (input number only) \n";
    cin >> s.food;
    cout << "spend for utility (input number only) \n";
    cin >> s.utility;
}

void budget::display(budget x, budget y){
    double total, spent;
    cout<<endl<<"Monthly budget report"<<endl;
    cout<<"car: $";
    calculate(x.car,y.car);
    cout<<"cloth: $";
    calculate(x.cloth,y.cloth);
    cout<<"rent: $";
    calculate(x.rent,y.rent);
    cout<<"food: $";
    calculate(x.food,y.food);
    cout<<"utility: $";
    calculate(x.utility,y.utility);

    total = x.car+x.cloth+x.rent+x.food+x.utility;
    spent = y.car+y.cloth+y.rent+y.food+y.utility;
    cout<<"Total Monthly budget constraints: $"<<total<<endl;
    cout<<"Total of Spent: $"<<spent<<endl;
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

