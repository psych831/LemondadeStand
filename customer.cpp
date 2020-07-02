#include "Defines.h"
#include "Lemonade.h"
#include "Customer.h"
#include <iostream>
#include <windows.h> 
#include <stdio.h> 


void Customer::events() {
    int timer = rand() % 1115 + 1985;
    Sleep(timer);
    int chance = rand() % 100 + 1;
    if (chance <= 20) {
        rodentattack();
    }
    else
    {
        purchases();
    }
    
 }

void Customer::purchases() {
    Defines obj;
    int deficit;
    int chance = rand() % 100 + 1;
    int request = rand() % 11 + 1;
    std::cout << "A customer wants " << request << " cups of lemonade." << std::endl;
    if (request <= cups_available) {
        cups_available = cups_available - request;
        cup_sold = cup_sold + request;
        total_sale = obj.CUP_PRICE * request;
        current_money = current_money + total_sale;
        std::cout << "Profit of " << total_sale << "was made." << std::endl;
        if (chance <= 10) {
            std::cout << "Customer loved the Lemonade. Paid Extra. " << std::endl;
            current_money = current_money + 10;
        }
    }
    else if (request >=cups_available && cups_available>=1) {
        deficit = request - cups_available;
        total_sale = obj.CUP_PRICE * cups_available;
        cup_sold = cup_sold + cups_available;
        cups_available = 0;
        current_money = current_money + total_sale;
        std::cout << "Profit of " << total_sale << "was made." << std::endl;
        std::cout << "Loss of " << obj.CUP_PRICE * request- total_sale << " was made." << std::endl;
    }
    else {
        std::cout << "No lemonades. Customer left" << std::endl;
    }
    
}

void Customer::rodentattack() {
    if (number_lemons > 40 && number_sugar > 60) {
        std::cout << "You just had a rodent attack on your stock. You lost inventory." << std::endl;
        int v1, v2;
        v1 = rand() % 19 + 1;
        v2 = rand() % 29 + 1;
        number_lemons = number_lemons - v1;
        number_sugar = number_sugar - v2;
    }
    else
    {
        std::cout << "Sorry no customers came." << std::endl;
    }
}