#pragma once
#ifndef DEFINES_H
#define DEFINES_H


extern float number_lemons;
extern float number_sugar;
extern float number_ice;
extern int made_lemonade;
extern int lemonade_sold;
extern float total_sale;
extern float total_spent;
extern float current_money;
extern int cup_sold;
extern float stock_costs;
extern int cups_available;
class Defines
{

public:
	enum state { initializing, running, finished };
	const float RECIPE_LEMON = 6.5f;
	const float RECIPE_SUGAR = 4.0f;
	const float RECIPE_ICE = 7.0f;
	const float LEMON_COST = 0.5f;
	const float SUGAR_COST = 2.20f;
	const float ICE_COST = 2.0f;
	const float CUP_PRICE = 1.20f;
	const int MAX_CUPS = 10;
	const int MIN_CUPS = 1;
	const float WIN_VALUE = 2000.0f;
	const float starting_money = 80.0f;
private:
	

};

#endif
