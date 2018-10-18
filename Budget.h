#ifndef Budget_H
#define BUdget_H

using namespace std;

class budget{
    public:
	void get_spent(budget &s);
	void display(budget x, budget y);
	void calculate(double a, double b);
    private:
        double car, cloth, rent, food, utility;
};

#endif
