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

void PrintUnitsList(const std::vector<Unit> &units) {
    for (int i = 0; i < units.size(); i++) {
        std::cout << i << " - " << units[i].name << "\n";
    }
}

void AttackUnit(std::vector<Unit> &units, int attackerIndex, int targetIndex) {
    if (attackerIndex == targetIndex) {
        std::cout << "Юнит не может атаковать сам себя!\n";
    }
    else if (attackerIndex >= 0 && attackerIndex < units.size() && targetIndex >= 0 && targetIndex < units.size()) {

        units[targetIndex].hp -= units[attackerIndex].damage;

        std::cout << units[attackerIndex].name << " атаковал " << units[targetIndex].name << "\n";

        std::cout << "Нанесено " << units[attackerIndex].damage << " урона\n";

        std::cout << "У " << units[targetIndex].name << " осталось " << units[targetIndex].hp << " HP\n";

        if (units[targetIndex].hp <= 0) {
            std::cout << units[targetIndex].name << " погиб!\n";
            units.erase(units.begin() + targetIndex);
        }
    }
    else {
        std::cout << "Некорректный индекс!\n";
    }
}
