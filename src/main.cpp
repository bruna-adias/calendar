#include <iostream>
#include "agenda.hpp"

int main()
{
    try
    {
        int tamAgenda;
        std::cout << "Insira o tamanho da sua agenda: ";
        std::cin >> tamAgenda;

        agenda minhaAgenda(tamAgenda);

        std::cout << "Quantidade de amigos em sua lista: " << minhaAgenda.getAmigos() << std::endl;
        std::cout << "Quantidade de conhecidos em sua lista: " << minhaAgenda.getConhecidos() << std::endl
                  << std::endl;

        minhaAgenda.addInformacoes();
        minhaAgenda.imprimeAniversarios();
        minhaAgenda.imprimeEmail();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}