#ifndef GAMEWORLD
#define GAMEWORLD
#include"Hero.h"
#include"Monster.h"
#include"NPC.h"
#include<memory>
#include<vector>
#include"Location.h"


using namespace std;
class GameWorld{
    public:
        GameWorld();
        void addlocation(Location*location);
        void setCurrentLocation(Location* location);
        void moveToLocation();
        void meetcharacter(Hero* hero,Location* location );
        void battle(Hero* hero,Monster* monster);
        ~GameWorld();
    private:
        Location* currentLocation;
        vector<Location*>locations;
    };
#endif