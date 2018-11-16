/**
    @file account.cc
    @brief This file contains the basic account information for the main.
 **/

#ifndef ACCOUNT_CC
#define ACCOUNT_CC

#include <iostream>
#include <cstdlib>

using namespace std; 

class account
{
	public:
        /** @brief This function is the constructor that sets all of the variables to
            empty strings.
         **/
		account()
		{
			first = "";
			last = "";
			pin = "";
		}
    
    /**
        @brief This function allows the user to set the name on their account.
        @param f - string that represents the first name
        @param l - string that represents the last name
     **/
		void set_name(string f, string l)
		{
			first = f;
			last = l; 
		}
    
    /**
        @brief This function returns the user's full name based on the values assigned to the strings.
     **/
		string get_name()
		{
			return first + " " + last;
		}
    
    /**
        @brief This function allows the user to set the pin that gives them access to their accounts
        @param p - a string that is being used to set the value of the pin variable.
     **/
		void set_pin(string p)
		{
			pin = p; 
		}
    
    /**
        @brief This function returns the user's pin based on the values assigned to teh strings
     **/
		string get_pin()
		{
			return pin; 
		}

	private:
		string first, last;  
		string pin; 

};
#endif
