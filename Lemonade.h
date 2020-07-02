#pragma once
#ifndef LEMONADE_H
#define LEMONADE_H
#include "Defines.h"


class Lemonade {
	public:
		void backRoom();	
	private:
		void checkstock();
		float checkfinances();
		int cups_sold();
		float profit();
		void checkRecipe();
		void makeLemonade();
		void open_shop();
};





#endif