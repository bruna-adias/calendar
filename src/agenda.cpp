#include "agenda.hpp"

agenda::agenda(int qtdPessoas)
{
    this->qtdAmigos = 0;
    this->qtdConhecidos = 0;

    srand(time(NULL));

    int i = 0;
    while (i < qtdPessoas)
    {
        int random = rand() % 2 + 1;
        random == 1 ? this->addInVector(new amigo()) : this->addInVector(new conhecido());
        i++;
    }
}

void agenda::addInVector(amigo *_amigo)
{
    this->v.push_back(_amigo);
    this->qtdAmigos++;
}

void agenda::addInVector(conhecido *_conhecido)
{
    this->v.push_back(_conhecido);
    this->qtdConhecidos++;
}

pessoa *agenda::getPessoa(int _position) const
{
    return this->v.at(_position);
}

void agenda::updateDataPessoa(int _position, string _name, int _age, string _additionalInformation)
{
    this->getPessoa(_position)->setAge(_age);
    this->getPessoa(_position)->setName(_name);
    this->getPessoa(_position)->setAdditionalInformation(_additionalInformation);
}

void agenda::insertInformation(const int _position)
{
    int switchVar;
    string name;
    string additionalInformation;
    int age;

    typeid(*this->getPessoa(_position)).hash_code() == typeid(amigo).hash_code() ? switchVar = 0 : switchVar = 1;

    std::cout << "******** CADASTRANDO PESSOA NÚMERO " << _position + 1 << " ********" << std::endl;

    std::cout << "Insira o nome do seu ";
    switchVar == 0 ? std::cout << "amigo" : std::cout << "conhecido";
    std::cout << ": ";

    std::cin >> name;
    name[0] = toupper(name[0]);

    std::cout << "Insira a idade de " << name << ": ";

    if (!(std::cin >> age))
        throw std::runtime_error("Invalid age input");

    switch (switchVar)
    {
    case 0:
        std::cout << "Insira o aniversário de " << name << ": ";
        break;

    case 1:
        std::cout << "Insira o email de " << name << ": ";
        break;
    }

    std::cin >> additionalInformation;
    std::cout << std::endl;

    this->updateDataPessoa(_position, name, age, additionalInformation);
}

void agenda::addInformacoes()
{
    int i = 0;
    while (i < this->v.size())
    {
        this->insertInformation(i);
        i++;
    }
}

void agenda::imprimeAniversarios() const
{
    std::cout << "******** ANIVERSÁRIOS NA SUA LISTA ********" << std::endl;

    int i = 0;
    while (i < this->v.size())
    {
        typeid(*this->getPessoa(i)).hash_code() == typeid(amigo).hash_code() ? std::cout << this->v.at(i)->getName() << ": " << this->v.at(i)->getAdditionalInformation() << std::endl : std::cout;
        i++;
    }

    std::cout << std::endl;
}

void agenda::imprimeEmail() const
{
    std::cout << "******** EMAILS NA SUA LISTA ********" << std::endl;

    int i = 0;
    while (i < this->v.size())
    {
        (typeid(*this->getPessoa(i)).hash_code() == typeid(conhecido).hash_code()) ? std::cout << this->v.at(i)->getName() << ": " << this->v.at(i)->getAdditionalInformation() << std::endl : std::cout;
        i++;
    }

    std::cout << std::endl;
}