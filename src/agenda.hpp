#ifndef AGENDA_H
#define AGENDA_H

#include <vector>
#include <string>
#include <typeinfo>
#include <time.h>
#include <cctype>
#include "pessoa.hpp"
#include "amigo.hpp"
#include "conhecido.hpp"

using namespace std;

class agenda
{
private:
    vector<pessoa *> v;
    int qtdAmigos;
    int qtdConhecidos;

public:
    agenda(int qtdPessoas);
    ~agenda(){};

    void addInVector(amigo *_amigo);
    void addInVector(conhecido *_conhecido);

    pessoa *getPessoa(int _position) const;
    void updateDataPessoa(int _position, string _name = "indefinido", int _age = 0, string _additionalInformation = "indefinido");
    void insertInformation(const int _position);
    void addInformacoes();
    void imprimeAniversarios() const;
    void imprimeEmail() const;

    int getAmigos() const { return this->qtdAmigos; }
    int getConhecidos() const { return this->qtdConhecidos; }
};

#endif