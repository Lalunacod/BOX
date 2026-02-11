#include <iostream>
#include <cstdio>


class IMotor {
public:
    virtual ~IMotor() {};
    virtual void SetOutput(int current) = 0;
    virtual int GetSpeed() = 0;
    virtual void Update() = 0;
};

class DJIMotor : public IMotor {
private:
    int current_;
public:
    void SetOutput(int current) override {
        current_ = current;
        printf("[CAN BUS] ID: 0x201, Send Current: %d\n", current);
    }

    int GetSpeed() override {
        return 1000;
    };

    void Update() override {
        
    }
};

class SimMotor : public IMotor {
private:
    int velocity_;
    int input_;
    const int resistance_ = 10;
public:
    SimMotor() : velocity_(0), input_(0) {}

    void SetOutput(int current) override {
        input_ = current;
    }

    int GetSpeed() override {
        return velocity_;
    }

    void Update() override {
        velocity_ += (input_ - resistance_);
        if (velocity_ < 0) velocity_ = 0;
    }
};

void TestMotor(IMotor* motor) {

    motor->SetOutput(500);
    motor->Update();
    int speed = motor->GetSpeed();
    std::cout << "Motor current speed: " << speed << std::endl;

}
