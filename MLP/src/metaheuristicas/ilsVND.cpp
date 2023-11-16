#include "../solucao/solucao.hpp"

void Solucao::ilsVND(Problema *p, int maxIter, int maxIterILS)
{

    int perturbacao = 0;

    this->setValor(INFINITE);

    // Criando dois objetos
    Solucao solucaoTemp;
    Solucao solucaoAtual;

    // Gerando a solução inicial
    solucaoAtual.algoritmoGuloso(p);

    // Limitando para não ficar demorando demais
    if (maxIterILS >= 150)
    {
        maxIterILS /= 2;
    }

    for (int i = 0; i < maxIter; i++)
    {

        int quantidadeIteracoes = 0;
        while (quantidadeIteracoes < maxIterILS)
        {

            // Trabalhando em cima de uma cópia
            solucaoTemp = solucaoAtual;

            // Fazendo sorteio para decidir qual a perturbação que será usada
            perturbacao = rand() % (QUANT_PERTURBACOES);

            // Aplicando a perturbação sorteada
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

            // Aplicando o VND
            solucaoTemp.vnd(p);

            // Se o valor da solução melhorou
            if (solucaoTemp.getValor() < solucaoAtual.getValor())
            {
                // Resetando a quantidade de iterações necessárias para encerrar o loop
                quantidadeIteracoes = 0;

                // Atualizando a melhor solução encontrada
                solucaoAtual = solucaoTemp;
            }

            // Independente se melhorou ou não
            quantidadeIteracoes += 1;
        }

        // Se a solução encontrada é melhor que a do objeto
        if (solucaoAtual.getValor() < this->getValor())
        {
            *this = solucaoAtual;
        }
    }
}