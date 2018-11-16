/**
    @file bank.cc
    @brief This file defines all of the functions and variables of the bank class.
 **/

#ifndef BANK_CC
#define BANK_CC
#include <iostream>
#include <cstdlib>

using namespace std; 

class bank
{
	public:
        /**
         @brief The constructor for the bank class. Sets the original balance variable to 0.
        **/
		bank()
		{
			balance = 0; 
		}
    
        /**
            @brief This function allows the user to add to how much money is in their account.
            @param money - a double that holds the value of how much they are adding to their account.
         **/
		void deposit(double money)
		{
			balance += money; 
		}
    
        /**
            @brief This function allows the user to subtract from the amount of money they have in their account.
            @param money - a double that holds the value of how much they are taking out of their account.
         **/
		void withdraw(double money)
		{
			if(isFunds(money))
			{
				balance = balance - money; 
			}
			else
				cout << "Insufficient Funds." << endl; 
		}
    
        /**
            @brief This function tests to see if the user has the proper amount of money in their account to see if there are sufficient funds for this withdrawal.
            @param money - a double that holds the value of the amount that the function is testing to see if the balance is larger or smaller than.
         **/
		bool isFunds(double money)
		{
			if(balance >= money)
				return true; 
			else 
				return false; 
		}
    
        /**
            @brief This function returns the current value of the balance variable.
         **/
		double getBalance()
		{
			return balance;
		}

	private:
		double balance; 
};

#endif
