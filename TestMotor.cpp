#include "TestMotor.hpp"

int main() {
    IMotor* dji_motor = new DJIMotor();
    TestMotor(dji_motor);

    IMotor* sim_motor = new SimMotor();
    TestMotor(sim_motor);

    delete dji_motor;
    delete sim_motor;

    return 0;
}