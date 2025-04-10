#include "Light.h"
#include "Hub.h"
#include <memory>

using namespace std;

int main() {
    Hub hub;
    std::shared_ptr<Light> light1(new Light("Light1"));
    std::shared_ptr<Light> light2(new Light("Light2"));

    hub.registerDevice(light1);
    hub.registerDevice(light2);

    hub.broadcastEvent("Motion Detected");
    hub.commandAll("Light");
    hub.commandAll("Light");
    return 0;
}