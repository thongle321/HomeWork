#include <iostream>
using namespace std;

class Animal
{
public:
    virtual void Move(){};
};

class Dog : public Animal
{
public:
    void Move()
    {
        cout << "Walk" << endl;
    }
};

class Fish : public Animal
{
public:
    void Move()
    {
        cout << "Swim" << endl;
    }
};

class Bird : public Animal
{
public:
    void Move()
    {
        cout << "Fly" << endl;
    }
};

int main()
{
    Animal *animal1 = new Dog();
    Animal *animal2 = new Fish();
    Animal *animal3 = new Bird();

    animal1->Move();
    animal2->Move();
    animal3->Move();

    delete animal1;
    delete animal2;
    delete animal3;
    return 0;
}
