#ifndef ACCOUNT_CC
#define ACCOUNT_CC

#include <iostream>
#include <cstdlib>

using namespace std; 

class account
{
	public:
		account()
		{
			first = "";
			last = "";
			pin = "";
		}
		void set_name(string f, string l)
		{
			first = f;
			last = l; 
		}
		string get_name()
		{
			return first + " " + last;
		}
		void set_pin(string p)
		{
			pin = p; 
		}
		string get_pin()
		{
			return pin; 
		}

	private:
		string first, last;  
		string pin; 

};
#endif