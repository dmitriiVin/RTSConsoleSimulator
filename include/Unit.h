#pragma once

#include <string>

struct Unit {
    std::string name;
    int hp;
    int damage;
};

Unit CreateUnit();
void PrintUnit(const Unit &unit);
