#include<fstream>
#ifndef Budget_H
#define Budget_H

class budget{	
    public:
	~budget(){};
        budget(double a = 0, double b = 0, double c = 0, double d = 0, double e = 0)
        {
	 car = a; cloth = b; rent = c; food = d; utility = e; 
        };
	void reset(budget &q);
        void get_spent(budget &s);
        void display(budget &x, budget &y);
        void calculate(double &a, double &b);   
     private:
        double car, cloth, rent, food, utility;
};

#endif
