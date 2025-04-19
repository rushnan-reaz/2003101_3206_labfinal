#include <gtest/gtest.h>
#include <sstream>
#include "../src/factory.hpp"
using namespace std;

class VehicleFactoryTest : public ::testing::Test {
protected:
    
    stringstream buffer;
    streambuf* oldCout;

    void SetUp() override {
        
        oldCout = cout.rdbuf(buffer.rdbuf());
    }

    void TearDown() override {
        
        cout.rdbuf(oldCout);
    }
    
    
    void checkDriveOutput(vehicle* v, const string& expected) {
        buffer.str(""); 
        v->drive();
        EXPECT_EQ(buffer.str(), expected + "\n");
    }
};


TEST_F(VehicleFactoryTest, CreateCar) {
    vehicle* v = VehicleFactory::create_vehicle("car");
    ASSERT_NE(v, nullptr);
    checkDriveOutput(v, "car");
    delete v;
}


TEST_F(VehicleFactoryTest, CreateBike) {
    vehicle* v = VehicleFactory::create_vehicle("bike");
    ASSERT_NE(v, nullptr);
    checkDriveOutput(v, "bike");
    delete v;
}


TEST_F(VehicleFactoryTest, CreateTruck) {
    vehicle* v = VehicleFactory::create_vehicle("truck");
    ASSERT_NE(v, nullptr);
    checkDriveOutput(v, "truck");
    delete v;
}


TEST_F(VehicleFactoryTest, CreateInvalid) {
    vehicle* v = VehicleFactory::create_vehicle("invalid");
    EXPECT_EQ(v, nullptr);
}


TEST_F(VehicleFactoryTest, TestVehicleTypes) {
    car c;
    bike b;
    truck t;
    
    buffer.str("");
    c.drive();
    EXPECT_EQ(buffer.str(), "car\n");
    
    buffer.str("");
    b.drive();
    EXPECT_EQ(buffer.str(), "bike\n");
    
    buffer.str("");
    t.drive();
    EXPECT_EQ(buffer.str(), "truck\n");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}