#pragma once

#include <string>
#include <vector>

struct Unit
{
    std::string name;
    int hp;
    int damage;
};

Unit CreateUnit();
void PrintUnit(const Unit &unit);
void PrintUnitsList(std::vector<Unit> &units);
void AttackUnit(std::vector<Unit> &units, int attackerIndex, int targetIndex);
