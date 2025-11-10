#pragma once

#include <iostream>
using namespace std;

//---------------------------------------------------
// 인터페이스 클래스: 날기 행동
class FlyBehavior {
public:
    virtual void fly() = 0;
    virtual ~FlyBehavior() {}
};

// 전략 구현 클래스들
class FlyWithWings : public FlyBehavior {
public:
    void fly() override;
    virtual ~FlyWithWings() {}
};

class FlyNoWay : public FlyBehavior {
public:
    void fly() override;
    virtual ~FlyNoWay(){}
};

//---------------------------------------------------
// 인터페이스 클래스: 꽥꽥 행동
class QuackBehavior {
public:
    virtual void quack() = 0;
    virtual ~QuackBehavior() {}
};

// 전략 구현 클래스들
class Quack : public QuackBehavior {
public:
    void quack() override;
    virtual ~Quack(){}
};

class Squeak : public QuackBehavior {
public:
    void quack() override;
    virtual ~Squeak() {}
};

class MuteQuack : public QuackBehavior {
public:
    void quack() override;
    virtual ~MuteQuack(){}
};

// 오리 클래스
class Duck {
protected:
    FlyBehavior* flyBehavior;
    QuackBehavior* quackBehavior;

public:
    Duck(): flyBehavior(nullptr), quackBehavior(nullptr) {}
    Duck(FlyBehavior* fb, QuackBehavior* qb)
        : flyBehavior(fb), quackBehavior(qb) {}

    virtual void display() = 0;
    
    void performFly();
    void performQuack();
    void setFlyBehavior(FlyBehavior* fb);
    void setQuackBehavior(QuackBehavior* qb);

    virtual ~Duck() {
        delete flyBehavior;
        delete quackBehavior;
    }
};

// 구체적인 오리 클래스
class MallardDuck : public Duck {
public:
    MallardDuck(); 
    void display() override {
        cout << "I'm a Mallar Duck." << endl;
    }
};

class RedheadDuck: public Duck{
public:
    RedheadDuck();
    void display() override {
        cout << "I'm a Redhead Duck." << endl;
    }
};

class RubberDuck: public Duck{
public:
    RubberDuck(); 
    void display() override {
        cout << "I'm a Rubber Duck." << endl;
    }
};

class DecoyDuck: public Duck{
public:
    DecoyDuck();
    void display() override {
        cout << "I'm a Decoy Duck." << endl;
    }
};

class ModelDuck: public Duck{
public:
    ModelDuck(); 
    void display() override {
        cout << "I'm a Decoy Duck." << endl;
    }
};

