#ifndef COMBATABLE_H
#define COMBATABLE_H
#include <string>
#include <iostream>
using namespace std;
class Character;

class Combatable{
 virtual void attack(Character* target)=0;
 virtual void useAbility(Character*target)=0;
};
#endif
