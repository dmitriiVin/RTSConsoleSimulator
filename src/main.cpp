#include "Unit.h"

#include <iostream>
#include <ostream>
#include <vector>

int main() {
    std::vector<Unit> units;

    int choise;

    while (true) {
        std::cout << "\nВыберите действие (1 - создать юнита, 2 - показать всех юнитов, 0 - выход): \n";
        std::cin >> choise;
        if (choise == 1) {
            Unit unit = CreateUnit();
            units.push_back(unit);

        } else if (choise == 2) {
            for (const auto &element : units) {
                PrintUnit(element);
            }
        } else if (choise == 0) {
            return 0;
        } else {
            std::cout << "Неизвестная команда!\n";
        }
    }
}
