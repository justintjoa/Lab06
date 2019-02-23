#include "CustomItem.h"
#include <set>
#include <iomanip>
#include <string>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <cstring>
#include <sstream>
#include <array>

using namespace std;

CustomItem::CustomItem(std::string size) : IceCreamItem(size) {
	head = NULL;

	tail = NULL;
	numberoftoppings = 0;
}

bool CustomItem::toppingexists(std::string topping) {
	Topping* p1;
	p1 = head;
	while (p1 != NULL) {
		if ((p1->topping).compare(topping) == 0) {
			return true;
		}
		else {
			p1 = p1->next;
			continue;
		}
	}
	return false;
}

int CustomItem::toppingcount() {
	return numberoftoppings;
}

	

void CustomItem::addTopping(std::string topping) {
        //add topping here
	price = price + 0.4;
	if (toppingexists(topping) == 1) {
		Topping* p2;
		p2 = head;
		while (p2 != NULL) {
			if ((p2->topping).compare(topping) == 0) {
				(p2->weight)++;
				return;
			} 
			else {
				p2 = p2->next;
			}
		}
	}
	else {
		Topping* p2;
		p2 = new Topping;
		p2->topping = topping;
		if (numberoftoppings == 0) {
			head = p2;
			tail = p2;
			numberoftoppings = 1;
			p2->next = NULL;
			p2->prev = NULL;
			//cout << p2->identity() << endl;
			//cout << "First addition" << endl;
			(p2->weight)++;
			return;
		}
		else {
			//cout << "begin else" << endl;
			Topping* p3;
			p3 = head;
			while (p3 != NULL) {
				std::set<std::string> sortedItems;
				sortedItems.insert(topping);
				sortedItems.insert(p3->topping);
				auto first = sortedItems.begin(); 
				if (*first != topping) {
					p3 = p3->next;
					//cout << "Comparison successful" << endl;
					continue;
				}
				else {
					//cout << "tryme" << endl;
					Topping* p4;
					p4 = p3->prev;
					if (p4 != NULL) {
						p4->next = p2;
					}
					else {
						head = p2;
					}
					p3->prev = p2;
					p2->prev = p4;
					p2->next = p3;
					numberoftoppings++;
					//cout << "Another one" << endl;
					//cout << p2->identity() << endl;
					(p2->weight)++;
					return;
				}
			}	
		}
		tail->next = p2;
		p2->prev = tail;
		p2->next = NULL;
		numberoftoppings++;
		tail = p2; 
		//cout << "add to end" << endl;
		//cout << p2->identity() << endl;
		(p2->weight)++;
		return;	
   	}

}

std::string CustomItem::composeItem() {
	std::ostringstream oss;
	oss.precision(2);
	oss << "Custom Size: " << size << endl;
	Topping* p1;
	p1 = head;
	oss << "Toppings:" << endl;
	while (p1 != NULL) {
		oss << p1->topping << ": " << p1->weight << " oz" << endl;
		p1 = p1->next;
	}
	oss << "Price: $" << fixed << price << endl;
	return oss.str();
}


CustomItem::~CustomItem() {
	Topping* p1;
	p1 = head;
	while (p1 != NULL) {
		Topping* temp;
		temp = p1->next;
		delete p1;
		p1 = temp;
	}
	numberoftoppings = 0;
}
 


