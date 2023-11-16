#include "../solucao/solucao.hpp"

void Solucao::ilsVND(Problema *p, int maxIter, int maxIterILS)
{

    int perturbacao = 0;

    this->setValor(INFINITE);

    Solucao solucaoTemp;
    Solucao solucaoAtual;

    solucaoAtual.algoritmoGuloso(p);

    for (int i = 0; i < maxIter; i++)
    {

        int quantidadeIteracoes = 0;
        while (quantidadeIteracoes < maxIterILS)
        {

            // Trabalhando em cima de uma cópia
            solucaoTemp = solucaoAtual;

            perturbacao = rand() % (QUANT_PERTURBACOES + 1);
            switch (perturbacao)
            {
            case 0:
                solucaoTemp.perturbacaoSwap(p, 1, 1);
                break;
            case 1:
                solucaoTemp.perturbacaoSwap(p, 2, 1);
                break;
            case 2:
                solucaoTemp.perturbacaoSwap(p, 1, 2);
                break;
            case 3:
                solucaoTemp.perturbacaoSwap(p, 2, 2);
                break;
            case 4:
                solucaoTemp.perturbacaoReinsertion(p, 1);
                break;
            case 5:
                solucaoTemp.perturbacaoReinsertion(p, 2);
                break;
            case 6:
                solucaoTemp.perturbacaoReinsertion(p, 3);
                break;
            case 7:
                solucaoTemp.perturbacaoReversalMove(p, 2);
                break;
            case 8:
                solucaoTemp.perturbacaoReversalMove(p, 3);
                break;
            }

            solucaoTemp.vnd(p);

            if (solucaoTemp.getValor() < solucaoAtual.getValor())
            {
                // Resetando a quantidade de iterações necessárias para encerrar o loop
                quantidadeIteracoes = 0;

                // Atualizando a melhor solução encontrada
                solucaoAtual = solucaoTemp;
            }

            quantidadeIteracoes += 1;
        }

        if (solucaoAtual.getValor() < this->getValor())
        {
            *this = solucaoAtual;
        }

    }
}