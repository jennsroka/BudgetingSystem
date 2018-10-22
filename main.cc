#include <iostream>
#include <iomanip>
#include "Budget.h"
using namespace std;
int main(){
    double car,cloth,rent,food,utility;
    budget set(car,cloth,rent,food,utility);
    budget spent;
    budget a;

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

    a.get_spent(spent);
    a.display(set,spent);
    return 0;
}

