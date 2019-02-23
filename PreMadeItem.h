#ifndef PREMADEITEM_H
#define PREMADEITEM_H
#include "IceCreamItem.h"
#include <string>
#include <cstring>
using namespace std;

class PreMadeItem : public IceCreamItem {
	public:
		PreMadeItem(std::string name, std::string size);
		virtual std::string composeItem();
		


	private:
		std::string name;
		

};

#endif
