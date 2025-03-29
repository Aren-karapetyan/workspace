#ifndef MONSTER
#define MONSTER
#include"Character.h"
#include"Combatable.h"
enum class Monstertype{
    Goblin,
    Troll,
    Dragon

};
void print_monstertype(Monstertype monstertype);

class Monster:public Character,public Combatable{
    public:
        Monster(string name,Monstertype type);
        void  displayStats()const override;
        void  takeDamage(int damage)override;
        void attack(Character* target)override;
        void useAbility(Character*target)override;

    private:
        Monstertype m_type;



};
#endif