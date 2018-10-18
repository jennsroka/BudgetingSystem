#include <iostream>
#include <iomanip>
#include "Budget.h"
using namespace std;

int main(){
    double car,cloth,rent,food,utility;
    cout<<"please typing your monthly budget"<<endl;
    cout<<"budget constraints of car:";
    cin>>car;
    cout<<"budget constraints of clothes:";
    cin>>cloth;
    cout<<"budget constraints of rent:";
    cin>>rent;
    cout<<"budget constraints of food:";
    cin>>food;
    cout<<"budget constraints of utility:";
    cin>>utility;
    budget set = budget(car,cloth,rent,food,utility);
    budget spent = budget();
    get_spent(spent);
    display(set,spent);
    return 0;
}

