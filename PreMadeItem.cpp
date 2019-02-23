#include "PreMadeItem.h"
#include <string>
#include <cstring>
#include <sstream>
#include <iostream>
#include <iomanip>
using namespace std;

PreMadeItem::PreMadeItem(std::string name, std::string size) : IceCreamItem(size) {
	this->name = name;
	price++;
}

std::string PreMadeItem::composeItem() {
	std::ostringstream oss;
        oss.precision(2);
	oss << "Pre-made Size: " << size << endl;
	oss << "Pre-made Item: " << name << endl;
	oss << "Price: $" << fixed << price << endl;
	return oss.str();
}
