#include "duck.h"
#include <iostream>

void FlyWithWings::fly(){
    std::cout<<"I can Fly!"<<std::endl;
}

void FlyNoWay::fly(){
    std::cout<<"I can't fly..."<<std::endl;
}

void Quack::quack(){
    std::cout<<"Quack!"<<std::endl;
}

void Squeak::quack(){
    std::cout<<"Squeak!"<<std::endl;
}

void MuteQuack::quack(){
    std::cout<<"<<Silent>>"<<std::endl;
}

void Duck::performFly(){
    if(flyBehavior) flyBehavior->fly();
    else std::cout<<"(no fly behavior)"<<std::endl;
}

void Duck::performQuack(){
    if(quackBehavior) quackBehavior->quack();
    else std::cout<<"(no quack behavior)"<<std::endl;
}

void Duck::setFlyBehavior(FlyBehavior* fb){
    if(flyBehavior) delete flyBehavior;
    flyBehavior = fb;
}

void Duck::setQuackBehavior(QuackBehavior* qb){
    if(quackBehavior) delete quackBehavior;
    quackBehavior = qb;
}

MallardDuck::MallarDuck(){
    flyBehavior = new FlyWithWings();
    quackBehavior = new Quack();
}

RedheaddDuck::RedheadDuck(){
    flyBehavior = new FlyWithWings();
    quackBehavior = new Quack();
}
RubberdDuck::RubberDuck(){
    flyBehavior = new FlyNoWay();
    quackBehavior = new Squeak();
}

DecoyDuck::DecoyDuck() {
    flyBehavior = new FlyNoWay();
    quackBehavior = new MuteQuack();
}

ModelDuck::ModelDuck() {
    flyBehavior = new FlyNoWay();
    quackBehavior = new MuteQuack();
}

