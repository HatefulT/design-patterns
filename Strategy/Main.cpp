#include <iostream>
using namespace std;

class QuackBehavior
{
public:
  QuackBehavior() {}
  virtual void quack() = 0;
};

class NoQuackBehavior : public QuackBehavior
{
public:
  NoQuackBehavior() {}
  void quack() override { cout << endl; }
};

class NormalQuackBehavior : public QuackBehavior
{
public:
  NormalQuackBehavior() {}
  void quack() override { cout << "QUACK!" << endl; }
};


class Duck
{
protected:
  QuackBehavior *quackBehavior;
  // FlyBehavior flyBehavior;
public:
  Duck() {}
  void performQuack() { quackBehavior->quack(); }
  // void performFly();
};

class SilentDuck : public Duck
{
public:
  SilentDuck() { quackBehavior = new NoQuackBehavior(); }
};

class ObviousDuck : public Duck
{
public:
  ObviousDuck() { quackBehavior = new NormalQuackBehavior(); }
};

int main()
{
  Duck *d1 = new SilentDuck();
  Duck *d2 = new ObviousDuck();
  cout << "SilentDuck: ";
  d1->performQuack();
  cout << "ObviousDuck: ";
  d2->performQuack();

  delete d1;
  delete d2;
}
