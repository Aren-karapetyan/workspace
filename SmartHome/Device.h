#pragma once
#include <string>
#include <memory>

using namespace std;

class Device {
    public:
        virtual ~Device() = default;
        virtual void performAction() = 0;
        virtual void notifyEvent(const string& event) = 0;
        virtual string getName() const = 0;
};

