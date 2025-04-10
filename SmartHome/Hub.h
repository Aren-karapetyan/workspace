#pragma once
#include "Device.h"
#include <vector>
#include <memory>
#include <string>

using namespace std;

class Hub {
    private:
        vector<shared_ptr<Device>> devices;
    public:
        void registerDevice(const shared_ptr<Device>& device) {
            devices.push_back(device);
        }

        void broadcastEvent(const string& event) {
            for (const auto& device : devices) {
                device->notifyEvent(event);
            }
        }

        void commandAll(const string& deviceType) {
            for (const auto& device : devices) {
                if (device->getName().find(deviceType) != string::npos) {
                    device->performAction();
                }
            }
        }
};