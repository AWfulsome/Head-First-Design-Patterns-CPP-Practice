#include <memory>

#include "DuckCall.hpp"
#include "FlyRocketPowered.hpp"
#include "MallardDuck.hpp"
#include "ModelDuck.hpp"

using DuckPtr = std::unique_ptr<Duck>;

int main()
{

    DuckPtr mallard = std::make_unique<MallardDuck>();

    mallard->perform_quack();
    mallard->perform_fly();

    DuckPtr model = std::make_unique<ModelDuck>();

    model->perform_fly();
    model->set_fly_behavior(std::make_unique<FlyRocketPowered>());
    model->perform_fly();

    std::unique_ptr<DuckCall> duckCall = std::make_unique<DuckCall>();

    duckCall->display();
    duckCall->performQuack();

    return 0;
}