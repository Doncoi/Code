#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

class Mammal 
{
private:
    int age;
    int weight;
public:
    Mammal(int ag, int wt) : age(ag), weight(wt)
    {
        cout << "Mammal constructor......" << endl;
    };

    ~Mammal()
    {
        cout << "Mammal destructor......" << endl;
    };

    int getAge()
    {
        return age;
    }
    
    int getWeight()
    {
        return weight;
    }
    
    void speak()
    {
        cout << "Mammal sound!" << endl;
    }    
};

class Dog : public Mammal
{
private:
    string color;
public:
    Dog(int ag, int wt, string cr) : Mammal::Mammal(ag, wt)
    {
        color = cr;
        cout << "Dog constructor......" << endl;
    };

    ~Dog()
    {
        cout << "Dog destructor......" << endl;
        //Mammal::~Mammal();
    }

    string getColor()
    {
        return color;
    }

    void speak()
    {
        Mammal::speak();
    }

    void wagtail()
    {
        cout << "Tail wagging......" << endl;
    }
};

int main()
{

      Dog jack(2,20,"grown");

      jack.speak();

      jack.wagtail();

      cout<<"jack is "<<jack.getAge()<<" years old,"<<jack.getWeight()<<" pounds,"<<jack.getColor()<<"."<<endl;

      return 0;

}