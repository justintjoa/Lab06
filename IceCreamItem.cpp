#include "IceCreamItem.h"
#include <cstring>
#include <string>

using namespace std;

IceCreamItem::IceCreamItem(std::string size) {
	this->size = size;
	string a = "small";
	string b = "medium";
	string c = "large";
	if (size.compare(a) == 0) {
		price = 3;
	}
	if (size.compare(b) == 0) {
		price = 5;
	}
	if (size.compare(c) == 0) {
		price = 6.5;
	}
}

double IceCreamItem::getPrice() {
	return price;
}
