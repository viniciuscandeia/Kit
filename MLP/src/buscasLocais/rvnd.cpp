#include "../solucao/solucao.hpp"

bool Solucao::rvnd(Problema *p)
{

    // Criando um vetor com todas as estruturas de vizinhança
    vector<int> estruturas = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    // Variáveis utilizadas para controlar o fluxo do código
    bool melhoria = false;
    bool melhorou = false;

    // Vetor não vazio
    while (!estruturas.empty())
    {

        // Sorteio de uma das estruturas
        int estruturaSorteada = rand() % estruturas.size();

        // Aplicando a estrutura sorteada
        switch (estruturaSorteada)
        {
        case 0:
            melhoria = this->bestImprovementSwap(p, 1, 1);
            break;
        case 1:
            melhoria = this->bestImprovementSwap(p, 2, 1);
            break;
        case 2:
            melhoria = this->bestImprovementSwap(p, 1, 2);
            break;
        case 3:
            melhoria = this->bestImprovementSwap(p, 2, 2);
            break;
        case 4:
            melhoria = this->bestImprovement2Opt(p);
            break;
        case 5:
            melhoria = this->bestImprovementReinsertion(p, 1);
            break;
        case 6:
            melhoria = this->bestImprovementReinsertion(p, 2);
            break;
        case 7:
            melhoria = this->bestImprovementReinsertion(p, 3);
            break;
        case 8:
            melhoria = this->bestImprovementReversalMove(p, 2);
            break;
        case 9:
            melhoria = this->bestImprovementReversalMove(p, 3);
            break;
        }

        // Se melhorou ...
        if (melhoria)
        {
            // ... pode utilizar todas as estruturas
            estruturas = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
            melhorou = true;
        }

        // Se não melhorou ...
        else
        {
            // ... remove do vetor estruturas a estrutura que não conseguiu melhorar a solução
            estruturas.erase(estruturas.begin() + estruturaSorteada);
        }
    }

    // Retorno booleano para identificar se o valor da solução reduziu ou não
    return melhorou;
}