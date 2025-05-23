#include<iostream>
#include "factory.hpp"

using namespace std;


int main() {
    vehicle* myCar = VehicleFactory::create_vehicle("car");
    if (myCar) {
        myCar->drive();
        delete myCar;
    } else {
        cout << "Unknown vehicle type" << endl;
    }

    vehicle* mybike = VehicleFactory::create_vehicle("bike");
    if (mybike) {
        mybike->drive();
        delete mybike;
    } else {
        cout << "Unknown vehicle type" << endl;
    }

    vehicle* myTruck = VehicleFactory::create_vehicle("truck");
    if (myTruck) {
        myTruck->drive();
        delete myTruck;
    } else {
        cout << "Unknown vehicle type" << endl;
    }

    return 0;
}