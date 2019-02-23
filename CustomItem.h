#ifndef CUSTOMITEM_H
#define CUSTOMITEM_H
#include <string>
#include <cstring>
#include "IceCreamItem.h"

using namespace std;

struct Topping {
	std::string topping;
	double weight = 0;
	Topping* next;
	Topping* prev;
};



class CustomItem : public IceCreamItem {
	public:
		CustomItem(std::string size);
		virtual std::string composeItem(); 
		void addTopping(std::string topping);
		bool toppingexists(std::string topping);
		int toppingcount();	
		~CustomItem();

	private:
		int numberoftoppings;
		Topping* head;
		Topping* tail;
};


#endif
