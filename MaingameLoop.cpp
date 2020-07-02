#include "Defines.h"
#include "Lemonade.h"
#include "Customer.h"
#include "MaingameLoop.h"
#include <iostream>
#include <conio.h>


void MaingameLoop::menu() {
	int a = 1;
	int choice;
	while (a == 1) {
		std::cout << "////////Welcome to the Lemonade Stand the Game////////" << std::endl;
		std::cout << "1. Play Game" << std::endl;
		std::cout << "2. Objectives" << std::endl;
		std::cout << "3. Exit" << std::endl;
		std::cin >> choice;
		switch (choice)
		{
		case 1:
			playermenu();
		case 2:
			std::cout << "The objective  is to setup your own lemonade stall. Buy stock, sell lemonade and plan accordingly \n to make the most profit. You win on making 2000$ worth of profit" << std::endl;
			break;
		case 3:
			std::cout << "Thank You for playing!" << std::endl;
			a = 2;
			break;
		default:
			std::cout << "Please enter a valid input" << std::endl;
			menu();
		}
	}
}

void MaingameLoop::playermenu() {
	int choice;
	Lemonade obj;
	Defines obj2;
	Customer obj3;
	int a = 1;
	while (a == 1){
		if (current_money <= obj2.WIN_VALUE) {
			 std::cout << "1. See Finances" << std::endl;
			 std::cout << "2. Enter Backroom" << std::endl;
			 std::cout << "3. Wait at Front Desk" << std::endl;
			 std::cout << "4. Exit" << std::endl;
			 std::cin >> choice;
			 switch (choice)
			 {
			 case 1:
				 std::cout << "Current Money: " << current_money << std::endl;
				 std::cout << "Cups of Lemonade Sold: " << cup_sold << std::endl;
				 std::cout << "Money spent on Stock: " << total_spent << std::endl;
				 std::cout << "Money gained on Sale: " << total_sale << std::endl;
				 std::cout << "Profit: " << current_money - obj2.starting_money << std::endl;
				 break;
			 case 2:
				 obj.backRoom();
				 break;
			 case 3:
				 while (1)
				 {
					 obj3.events();
					 if (_kbhit())
					 {
						 break;
					 }
				 }
				 break;
				 
			 case 4:
				 std::cout << "the player has neither won nor lost and is exiting" << std::endl;
				 a = 2;
				 break;
			 default:
				 break;
			 }
		 }
		
		if (current_money >= obj2.WIN_VALUE) {
			std::cout << "The player has WON" << std::endl;
			a = 2;
		}
		if (current_money <= 1) {
			std::cout << "The player has gpne broke  and lost" << std::endl;
			a = 2;
		}
	}
}