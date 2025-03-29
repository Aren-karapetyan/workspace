
#ifndef INTERACTABLE_H
#define INTERACTABLE_H
#include <string>

class Character;
using namespace std;
class Interactable{
    virtual void interact(Character*target)=0;
    virtual  string getDialogue()const=0;
};
#endif