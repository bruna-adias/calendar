#ifndef AMIGO_H
#define AMIGO_H

#include "pessoa.hpp"

class amigo : public pessoa
{
private:
    string birthday;

public:
    amigo() : pessoa(), birthday("indefinido"){};
    ~amigo(){};

    string getBirthday() const { return this->birthday; }
    void setBirthday(const string _birthday) { this->birthday = _birthday; }
    void setAdditionalInformation(string _additionalInformation);
    string getAdditionalInformation();
};

#endif