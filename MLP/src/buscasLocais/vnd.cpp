#include "../solucao/solucao.hpp"

bool Solucao::vnd(Problema *p)
{
    int estrutura = 0;
    bool melhoria = false;
    bool melhorou = false;

    // Até passar por todas as estruturas sem melhorar
    while (estrutura < 10)
    {

        switch (estrutura)
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

        // Se melhorou
        if (melhoria)
        {
            estrutura = 0;
            melhorou = true;
        }

        // Se não melhorou
        else
        {
            estrutura += 1;
        }
    }

    return melhorou;
}