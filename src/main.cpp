#include "Unit.h"

#include <iostream>
#include <ostream>
#include <vector>

int main() {
    std::vector<Unit> units;

    int choise;

    while (true) {
        std::cout << "\nВыберите действие (1 - создать юнита, 2 - показать всех юнитов, 3 - удалить юнита по индексу, 4 - атаковать юнита, 0 - выход): \n";
        std::cin >> choise;
        if (choise == 1) {
            Unit unit = CreateUnit();
            units.push_back(unit);
        }
        else if (choise == 2) {
            for (const auto &element : units) {
                PrintUnit(element);
            }
        }
        else if (choise == 3) {
            PrintUnitsList(units);
            int index;
            std::cout << "\nВведите что хотите удалить по индексу: ";
            std::cin >> index;
            if (index < units.size()) {
                units.erase(units.begin() + index);
            }
            for (const auto &element : units) {
                PrintUnit(element);
            }
        }
        else if (choise == 4) {
            PrintUnitsList(units);

            int index1, index2;

            std::cout << "Введите кто атакует: ";

            std::cin >> index1;

            std::cout << "Введите кого атаковать: ";

            std::cin >> index2;

            AttackUnit(units, index1, index2);
        }
        else if (choise == 0) {
            return 0;
        }
        else {
            std::cout << "Неизвестная команда!\n";
        }
    }
}
