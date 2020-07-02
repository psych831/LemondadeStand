#include "Defines.h"
#include "Lemonade.h"
#include <iostream>
void Lemonade::checkstock() {
	float stock[3];
	stock[0] = number_lemons;
	stock[1] = number_sugar;
	stock[2] = number_ice;
	std::cout << "Current Stock: " << std::endl;
	std::cout << "Lemons :" << stock[0] << std::endl;
	std::cout << "Sugar :" << stock[1] << std::endl;
	std::cout << "Ice :" << stock[2] << std::endl;
	
}

float Lemonade::checkfinances() {
	return current_money;
}

int Lemonade::cups_sold() {
	return cup_sold;
}

float Lemonade::profit() {
	Defines obj;
	return current_money - obj.starting_money;
}

void Lemonade::open_shop() {
	Defines obj;

	int choice, quantity;
	int a = 1;
	
	while (a == 1) {
		std::cout << "Welcome to the Shop" << std::endl;
		std::cout << "What would you like to buy today?" << std::endl;
		std::cout << "1. Lemons: Price- "<< obj.LEMON_COST << std::endl;
		std::cout << "2. Sugar Bag (50 helpings): Price- "<< obj.SUGAR_COST << std::endl;
		std::cout << "3. Ice Bag (20 helpings): Price- "<< obj.ICE_COST << std::endl;
		std::cout << "4. Check Wallet" << std::endl;
		std::cout << "5. Leave the shop" << std::endl;
		std::cout << "Please enter your choice" << std::endl;
		std::cin >> choice;
	
		switch (choice) {
		case 1:
			std::cout << "How many would you like to purchase?" << std::endl;
			std::cin >> quantity;
			if (current_money > quantity* obj.LEMON_COST) {
				number_lemons = number_lemons + quantity;
				total_spent = total_spent + quantity* obj.LEMON_COST;
				current_money = current_money - quantity * obj.LEMON_COST;
				std::cout << "Purchase successful" << std::endl;
				break;
			}
			else {
				std::cout << "Transaction declined due to insufficient funds" << std::endl;
				break;
			}
		case 2:
			std::cout << "How many would you like to purchase?" << std::endl;
			std::cin >> quantity;
			if (current_money > quantity* obj.SUGAR_COST) {
				number_sugar = number_sugar + quantity*50;
				total_spent = total_spent + quantity * obj.SUGAR_COST;
				current_money = current_money - quantity * obj.SUGAR_COST;
				std::cout << "Purchase successful" << std::endl;
				break;
			}
			else {
				std::cout << "Transaction declined due to insufficient funds" << std::endl;
				break;
			}
		case 3:
			std::cout << "How many would you like to purchase?" << std::endl;
			std::cin >> quantity;
			if (current_money >= quantity* obj.ICE_COST) {
				number_ice = number_ice + quantity*20;
				total_spent = total_spent + quantity * obj.ICE_COST;
				std::cout << "Purchase successful" << std::endl;
				break;
			}
			else {
				std::cout << "Transaction declined due to insufficient funds" << std::endl;
				break;
			}
		case 4:
			std::cout << "Wallet Balance: " << current_money << std::endl;
			std::cout << "Total Spent: " << total_spent << std::endl;
			break;
		case 5:
			std::cout << "Thank you for visiting. Come again" << std::endl;
			a = 2;
		default:
			std::cout << "Invalid input. Please select a valid input and try again." << std::endl;
			break;
		}
	}
}

void Lemonade::checkRecipe() {
	Defines obj;
	std::cout << "Current Recipe Requires: " << std::endl;
	std::cout << "Lemons: " << obj.RECIPE_LEMON << std::endl;
	std::cout << "Sugar: " << obj.RECIPE_SUGAR << std::endl;
	std::cout << "ICE: " << obj.RECIPE_ICE << std::endl;
}

void Lemonade::makeLemonade() {
	float stock[3];
	Defines obj;
	stock[0] = number_lemons;
	stock[1] = number_sugar;
	stock[2] = number_ice;
	int jar;
	std::cout << "How many jars would you like to make? (1 jar = 6 cups)" << std::endl;
	std::cin >> jar;
	float required_lemons=0.0, required_sugar=0.0, required_ice=0.0;
	required_lemons = obj.RECIPE_LEMON * jar;
	required_sugar = obj.RECIPE_SUGAR * jar;
	required_ice = obj.RECIPE_ICE * jar;
	if (stock[0] >= required_lemons && stock[1] >= required_sugar && stock[2] >= required_ice) {
		cups_available = cups_available + 6 * jar;
		number_lemons = number_lemons - required_lemons;
		number_sugar = number_sugar - required_sugar;
		number_ice = number_ice - required_ice;
		std::cout << "Lemonade jars made successfully" << std::endl;
	}
	else if (stock[0] < required_lemons) {
		std::cout << " You are low on lemons. Deficit: " << stock[0] - required_lemons << std::endl;
	}
	else if (stock[1] < required_sugar) {
		std::cout << " You are low on sugar. Deficit: " << stock[1] - required_sugar << std::endl;
	}
	else {
		std::cout << " You are low on ice. Deficit: " << stock[2] - required_ice << std::endl;
	}
}

void checklemonade() {
	std::cout << "Number of cups available: " << cups_available << std::endl;
}


void Lemonade::backRoom() {
	int choice, a = 1;
	float stock[3];
	float wallet = 0.0, profit_made = 0.0;
	while (a == 1) {
		std::cout << "Welcome to the Back Room" << std::endl;
		std::cout << "What would you like to do" << std::endl;
		std::cout << "1. Check inventory" << std::endl;
		std::cout << "2. Check Recipe" << std::endl;
		std::cout << "3. Visit Shop" << std::endl;
		std::cout << "4. Check Wallet" << std::endl;
		std::cout << "5. Profit Made" << std::endl;
		std::cout << "6. Check Lemonade Available" << std::endl;
		std::cout << "7. Make Lemonade" << std::endl;
		std::cout << "8. Return to Front Desk" << std::endl;
		
		std::cin >> choice;
	
		switch (choice)
		{
			case 1:
				checkstock();
				break;
			case 2:
				checkRecipe();
				break;
			case 3:
				open_shop();
				break;
			case 4:
				wallet = checkfinances();
				std::cout << "Current Wallet Balance: " << wallet << std::endl;
				break;
			case 5:
				profit_made = profit();
				std::cout << "Profit Made: " << wallet << std::endl;
				break;
			case 6:
				checklemonade();
				break;
			case 7:
				makeLemonade();
				break;
			case 8:
				std::cout << "Going Back to Front Desk" << std::endl;
				a = 2;
				break;
			default:
				std::cout<<"Please Enter a Valid Input." << std::endl;
				break;
		}
	}
}