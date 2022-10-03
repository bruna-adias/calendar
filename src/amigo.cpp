#include "amigo.hpp"

void amigo::setAdditionalInformation(string _additionalInformation)
{
    this->birthday = _additionalInformation;
}

string amigo::getAdditionalInformation()
{
    return this->birthday;
}
