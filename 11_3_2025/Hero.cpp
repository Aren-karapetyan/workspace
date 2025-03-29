
#ifndef HERO_H
#define HERO_H
#include"Hero.h"
#include "Monster.h"
using namespace std;

void print_herotype(Herotype herotype) {
    switch (herotype) {
        case Herotype::Warrior:
            cout << "Warrior" << endl;
            break;
        case Herotype::Mage:
            cout << "Mage" << endl;
            break;
        case Herotype::Rogue:
            cout << "Rogue" << endl;
            break;
    }
}
Hero::Hero(string name,Herotype herotype):Character(name,100,25,30){
    m_herotype=herotype;
    m_level=1;
    m_XP=0;  
}
void Hero::addItem(Item*inventory){
    m_inventory.push_back(inventory);
}
void Hero::useItem(int index) {
    if (index >= 0 && index < m_inventory.size()) {
        m_inventory[index]->use_Item(this);  
    }
    std::cout << "Invalid item index.\n";
}
void Hero::printItem() {
    for (int i = 0; i < m_inventory.size(); i++) {
        std::cout << i << ". " << m_inventory[i]->getName() << '\n';
    }
}
void Hero::gainXP(int xp){
    m_XP+=xp;
    std::cout << m_name <<" XP:"<< xp << '/' << m_level * 100 << '\n' << std::endl;
    if (m_XP >= m_level * 100) {
        levelup();
    }
}
int Hero::getlevel(){
    return m_level;
}
void Hero::levelup(){
    while(m_XP >= m_level*100){
        m_XP -= m_level*100;
        m_health+=25;
        m_defense+=15;
        m_attackPower+=25;
        cout << "************\n";
        cout << "* level up *  "<< m_level++ << " -> " << m_level <<endl;
        cout << "************\n" << endl;
        cout << m_name <<" XP: "<< m_XP << '/' << m_level * 100 << '\n' << std::endl;
    }
}

void Hero::displayStats()const{
    cout << "Hero:" << m_name << endl;
    cout << "your hero is:";
    print_herotype(m_herotype);
    cout << "health:" << m_health << endl;
    cout << "attackPower:" << m_attackPower << endl;
    cout << "defense:" << m_defense << endl;
    cout << "level:" << m_level << endl;
    cout << "XP:" << m_XP << endl;
}

void Hero::takeDamage(int damage){
    damage-=m_defense;
    if(damage>0){
        m_health-=damage;
        if (m_health > 0)
        {
            cout << "\nHP:" << m_health << endl;
        }
        if(m_health<0){
            cout << "          =============\n";
            cout << "          = GAME OVER =\n";
            cout << "          =============\n" << endl; 
        }
    }   
}
void Hero::attack(Character* target){
    if(target==nullptr){
        return;
    }
    target->takeDamage(m_attackPower);
    cout<<"Your hero attack on" << target->get_name()<<"in attackpower:"<<m_attackPower<<endl;     
}
void Hero::useAbility(Character*target){
    if(target==nullptr){
        cout<<"there is no such target"<<endl;
        return;
    }
    if(m_herotype==Herotype::Warrior){
        cout<<"you use Power Strike on:"<< target->get_name()<<endl;
        target->takeDamage(20);
    }
    if(m_herotype==Herotype::Mage){
        cout<<"you use Fireball on:"<<target->get_name()<<endl;
        target->takeDamage(20); 
    }
    if(m_herotype==Herotype::Rogue){
        cout<<"you use Stealth Attack on:"<<target->get_name()<<endl;
        target->takeDamage(20);
    }
}
void Hero::interact(Character*target){
    cout<<"your hero interact with:"<<target->get_name()<<endl;
}
string Hero::getDialogue()const {
    return "Hello i am hero";
}
Hero::~Hero(){
    for(int i=0;i<m_inventory.size();i++){
        delete m_inventory[i];
    }
    m_inventory.clear();
}
#endif

