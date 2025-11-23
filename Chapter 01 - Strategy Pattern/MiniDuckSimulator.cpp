#include <memory>

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

    return 0;
}