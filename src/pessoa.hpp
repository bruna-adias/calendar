#ifndef PESSOA_H
#define PESSOA_H

#include <iostream>
using namespace std;

class pessoa
{
private:
    string name;
    int age;

public:
    pessoa() : name("indefinido"), age(0){};
    ~pessoa(){};

    string getName() const { return this->name; }
    int getAge() const { return this->age; }
    void setName(const string _name) { this->name = _name; }
    void setAge(const int _age) { this->age = _age; }
    virtual void setAdditionalInformation(string _additionalInformation) = 0;
    virtual string getAdditionalInformation() = 0;
};

#endif