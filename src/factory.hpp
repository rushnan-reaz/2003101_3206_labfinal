#pragma once

#include <string>
#include <iostream>


using namespace std;

class vehicle {
public:
    virtual ~vehicle() = default;
    virtual void drive() = 0;
};

class car : public vehicle {
public:
    void drive() override {
        cout << "car" << endl;
    }
};

class bike : public vehicle {
public:
    void drive() override {
        cout << "bike" << endl;
    }
};

class truck : public vehicle {
public:
    void drive() override {
        cout << "truck" << endl;
    }
};


class VehicleFactory {
public:
    
    static vehicle* create_vehicle(const string& type) {
        if (type == "car") {
            return new car();
        } else if (type == "bike") {
            return new bike();
        } else if (type == "truck") {
            return new truck();
        }
        return nullptr;
    }
};


