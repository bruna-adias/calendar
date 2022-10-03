#include "conhecido.hpp"

void conhecido::setAdditionalInformation(string _additionalInformation)
{
    this->email = _additionalInformation;
}

string conhecido::getAdditionalInformation()
{
    return this->email;
}
