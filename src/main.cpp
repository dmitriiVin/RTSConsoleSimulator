#include "Unit.h"

#include <iostream>
#include <ostream>
#include <vector>

int main() {
    std::vector<Unit> units;

    int choise;

    while (true) {
        std::cout << "\nВыберите действие (1 - создать юнита, 2 - показать всех юнитов, 3 - удалить юнита по индексу, 0 - выход): \n";
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
            for (int i = 0; i < units.size(); i++) {
                std::cout << i << " - " << units[i].name << "\n";
            }
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
        else if (choise == 0) {
            return 0;
        }
        else {
            std::cout << "Неизвестная команда!\n";
        }
    }
}
