#include <iostream>
#include <iomanip>
using namespace std;

struct budget{
    double car, cloth, rent, food, utility;
};

void get_spent(budget &s);
void display(budget x, budget y);
void calculate(double a, double b);

int main(){
    double car,cloth,rent,food,utility;
    cout<<"please typing your monthly budget"<<endl;
    cout<<"budget constraints of car:";
    cin>>car;
    cout<<"budget constraints of cloth:";
    cin>>cloth;
    cout<<"budget constraints of rent:";
    cin>>rent;
    cout<<"budget constraints of food:";
    cin>>food;
    cout<<"budget constraints of utility:";
    cin>>utility;
    budget set = {car,cloth,rent,food,utility};
    budget spent;
    get_spent(spent);
    display(set,spent);
    cin>>car;
    return 0;
}

void get_spent(budget &s){
    cout << "let's start type in how much you spend so far! \n";
    cout << "__________________________________________________ \n"; 
    cout << "-------------------------------------------------- \n";
    cout <<"What is you income or balance? \n";
    cout << "start with the rent (input number only) \n";
    cin >> s.rent;
    cout << "spend for food (input number only) \n";
    cin >> s.food;
    cout << "spend for car (input number only) \n";
    cin >> s.car;
    cout << "spend for clothing (input number only) \n";
    cin >> s.cloth;
    cout << "spend for utility (input number only) \n";
    cin >> s.utility;
}

void display(budget x, budget y){
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
    cout<<"Total: $";
    calculate(total,spent);
}

void calculate(double a, double b){
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