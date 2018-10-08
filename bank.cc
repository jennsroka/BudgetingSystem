#ifndef BANK_CC
#define BANK_CC
#include <iostream>
#include <cstdlib>

using namespace std; 

class bank
{
	public:
		bank()
		{
			balance = 0; 
		}
		void deposit(double money)
		{
			balance += money; 
		}
		void withdraw(double money)
		{
			if(isFunds(money))
			{
				balance = balance - money; 
			}
			else
				cout << "Insufficient Funds." << endl; 
		}
		bool isFunds(double money)
		{
			if(balance >= money)
				return true; 
			else 
				return false; 
		}
		double getBalance()
		{
			return balance;
		}

	private:
		double balance; 
};

#endif
