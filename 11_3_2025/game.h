#ifndef GAME_H
#define GAME_H
#include "Monster.h"
#include <iostream>
#include <string>
#include "Hero.h"
#include "Monster.h"
#include "GameWorld.h"

using namespace std;
class Game{
    public:
        Game(){
        }
        void run(){
            cout<<"1. Game"<<endl;
            cout<<"2. Exit"<<endl;
            int choice;
            cin>>choice;
            switch(choice){
                case 1:
                    manu();
                    break;
                case 2:
                    cout << "Goodbye" << endl;
                    break;
                default:
                    cout<<"Invalid choice"<<endl;
            }
        }
        
    private:
        Hero* hero;
        void manu(){
            cout << "1. Start Game" << endl;
            cout << "2. Creat hero" << endl;
            cout << "3. <-" << endl;
            cout << "4. Exit" << endl;
            int choice;
            cin>>choice;
            switch(choice){
                case 1:
                    startGame();
                    break;
                case 2:
                    qreathero();
                    break;
                case 3:
                    run();
                    break;
                case 4:
                    cout << "Goodbye" << endl;
                    break;

                default:
                    cout<<"Invalid choice"<<endl;
            }
        }

        void startGame(){
            cout << "=========\n";
            cout << "= Start =" << endl;
            cout << "=========\n" << endl;
            GameWorld gameworld;
            
            cout << endl;
            Monster* Griphook = new Monster("goblin", Monstertype::Goblin);
            Monster* Bogrod = new Monster("goblin", Monstertype::Goblin);            cout << "you are fighting with Goblin" << endl;
            int ready = 0;
            
            QuestManager* questManager = new QuestManager();
            NPC* villager = new NPC("Villager", questManager);
        
            Location* village = new Location("Village");
            village->addentity(villager);
            gameworld.addlocation(village);
            
            gameworld.setCurrentLocation(village);
            gameworld.meetcharacter(hero, village);
        
            cout << "A wild goblin appears!" << endl;
            gameworld.battle(hero, Griphook);
            cout << "You defeated the goblin!" << endl;
            cout << "A wild goblin appears!" << endl;
            gameworld.battle(hero, Bogrod);
            cout << "You defeated the goblin!" << endl;
            cout << "            ===========\n";
            cout << "            = YOU WIN =" << endl;
            cout << "            ===========\n" << endl;


        }
        void qreathero(){
            cout<<"Enter name: ";
            string heroName;
            cin>>heroName;
            cout<<"Enter hero type\n1 - Warrior\n2 - Mage\n3 - Rogue\n";
            int typeInput;
            cin>>typeInput;
            Herotype heroType = static_cast<Herotype>(typeInput);
            Sword* sword = new Sword("Excalibur", 15);
            HealthPotion* potion = new HealthPotion("Healing Potion", 20);
            Magic_Amulet* amulet = new Magic_Amulet("Mystic Amulet", 5);
            hero = new Hero(heroName, heroType);

            switch (heroType)
            {
            case Herotype::Warrior:
                hero->addItem(sword);
                break;
            case Herotype::Mage:
                hero->addItem(amulet);
                break;
            case Herotype::Rogue:
                hero->addItem(potion);
                break;
            default:
                break;
            }
            cout << "Hero created" << endl;
            hero->displayStats();
            manu();
        }

};
#endif