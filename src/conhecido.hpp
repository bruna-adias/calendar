#ifndef CONHECIDO_H
#define CONHECIDO_H

#include "pessoa.hpp"

class conhecido : public pessoa
{
private:
    string email;

public:
    conhecido() : pessoa(), email("indefinido"){};
    ~conhecido();

    string getEmail() const { return this->email; }
    void setEmail(const string _email) { this->email = _email; }
    void setAdditionalInformation(string _additionalInformation);
    string getAdditionalInformation();
};

#endif