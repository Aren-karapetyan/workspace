#pragma once
#include "Device.h"
#include <iostream>

using namespace std;

class Light : public Device {
    private:
        string name;
        bool isOn = false;
    public:
        Light(const string& n) : name(n) {}
        void performAction() override {
            if (isOn)
                cout << name << ": OFF" << endl;
            else
                cout << name << ": ON" << endl;
            isOn = !isOn;
        }
        void notifyEvent(const string& event) override {
            cout << name << ": Event received - " << event << endl;
        }
        string getName() const override { 
            return name; 
        }
};