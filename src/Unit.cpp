#include "Unit.h"

#include <iostream>

Unit CreateUnit() {
    Unit unit;

    std::cout << "Введите имя юнита: ";
    std::cin >> unit.name;

    std::cout << "Введите здоровье юнита: ";
    std::cin >> unit.hp;

    std::cout << "Введите урон юнита: ";
    std::cin >> unit.damage;

    return unit;
}

void PrintUnit(const Unit &unit) {

    std::cout << "\nИмя: " << unit.name << "\n";
    std::cout << "Здоровье: " << unit.hp << "\n";
    std::cout << "Урон: " << unit.damage << "\n";
}
