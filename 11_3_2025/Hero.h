#ifndef Heros
#define Heros
#include"Character.h"
#include"Combatable.h"
#include"Interactable.h"
#include"Item.h"
#include<vector>
//#include"Magic_Amulet.h"
//#include"HealthPotion.h"
enum  Herotype{
Warrior = 1,
Mage,
Rogue
};
void print_herotype(Herotype herotype);

class Hero:public Character,public Combatable,public Interactable{
private:
    vector<Item*>m_inventory;
    int m_level;
    int m_XP;
    Herotype m_herotype;
public:
    Hero(string name,Herotype herotype);
    void addItem(Item* inventory);
    void displayStats()const override;
    void takeDamage(int damage)override;
    void attack(Character* target)override;
    void useAbility(Character*target)override;
    void interact(Character*target)override;
    string getDialogue()const override;
    void useItem(int index);
    void gainXP(int xp);
    void levelup();
    void printItem();
    int getlevel();
    ~Hero();
};
#endif
