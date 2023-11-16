#include "../solucao/solucao.hpp"

// Trocar a posição de dois vértices na sequência
// Melhoria: possibilidade de trocar dois blocos
bool Solucao::bestImprovementSwap(Problema *p, int blocoUm, int blocoDois)
{
    int bestdDelta = 0;
    int bestI = 0;
    int bestJ = 0;

    int inicioBlocoUm = 0;
    int fimBlocoUm = 0;
    int depoisBlocoUm = 0;

    int inicioBlocoDois = 0;
    int fimBlocoDois = 0;
    int antesBlocoDois = 0;

    // * Informaces sobre a solucao
    vector<int> &sequencia = this->getSequencia();
    int tamanho = sequencia.size();

    // * Informacoes sobre o problema
    vector<vector<int>> &v = p->getMatrizValores();

    // Limite dos fors

    // Se bloco 1 -> limiteJ = tamanho
    // Se bloco 2 -> limiteJ = tamanho - 1
    // Se bloco 3 -> limiteJ = tamanho - 2

    int limiteJ = tamanho + 1 - blocoDois;

    // Se bloco 1 -> limiteI = tamanho - 1
    // Se bloco 2 -> limiteI = tamanho - 3
    // Se bloco 3 -> limiteI = tamanho - 5

    int limiteI = limiteJ - blocoUm;

    // | Para i
    for (int i = 0; i < limiteI; i++)
    {

        inicioBlocoUm = sequencia[i];

        // Se bloco = 1 -> fimBloco = inicioBloco
        // Se bloco = 2 -> fimBloco = inicioBloco + 1
        // Se bloco = 3 -> fimBloco = inicioBloco + 2

        fimBlocoUm = sequencia[i + blocoUm - 1];

        // Se bloco = 1 -> depoisBloco = inicioBloco + 1
        // Se bloco = 2 -> depoisBloco = inicioBloco + 2
        // Se bloco = 3 -> depoisBloco = inicioBloco + 3

        depoisBlocoUm = sequencia[i + blocoUm];

        // | Para j
        for (int j = i + blocoUm; j < limiteJ; j++)
        {

            int delta = 0;

            // Independente da situação, sempre ocorrerá isso 
            delta -= v[fimBlocoUm][depoisBlocoUm];

            antesBlocoDois = sequencia[j - 1];
            inicioBlocoDois = sequencia[j];
            fimBlocoDois = sequencia[j + blocoDois - 1];

            // Se i não estiver no coneço, ele terá um vértice antes dele
            if (i != 0)
            {
                int antesBlocoUm = sequencia[i - 1];
                delta -= v[antesBlocoUm][inicioBlocoUm];
                delta += v[antesBlocoUm][inicioBlocoDois];
            }

            // Se blocoUm e blocoDois não são adjacentes
            if (i + blocoUm != j)
            {
                delta += v[fimBlocoDois][depoisBlocoUm];

                delta -= v[antesBlocoDois][inicioBlocoDois];
                delta += v[antesBlocoDois][inicioBlocoUm];
            }

            // Se blocoUm e blocoDois são adjacentes
            else
            {
                delta += v[fimBlocoDois][inicioBlocoUm];
            }

            // Se j não for o ultimo, ele terá um vértice depois dele
            if (j + blocoDois != tamanho)
            {
                int depoisBlocoDois = sequencia[j + blocoDois];

                delta -= v[fimBlocoDois][depoisBlocoDois];
                delta += v[fimBlocoUm][depoisBlocoDois];
            }

            // Verificando se encontrou uma situação en que vai reduzir o valor da solução
            if (delta < bestdDelta)
            {
                bestdDelta = delta;
                bestI = i;
                bestJ = j;
            }
        }
    }

    // | Se encontrou a tal situação
    if (bestdDelta < 0)
    {

        // Trocando de posições i e j
        swap(sequencia, bestI, bestJ, blocoUm, blocoDois);

        // Atualizando o valor da solução
        this->setValor(this->getValor() + bestdDelta);

        return true;
    }

    return false;
}

void swap(vector<int> &sequencia, int i, int j, int blocoUm, int blocoDois)
{

    // Movendo os elementos do blocoDois
    for (int k = 0; k < blocoDois; k++)
    {
        int elementoAtual = sequencia[j + k];
        sequencia.erase(sequencia.begin() + j + k);
        sequencia.insert(sequencia.begin() + i + k, elementoAtual);
    }

    // Movendo os elementos do blocoUm
    for (int k = 0; k < blocoUm; k++)
    {
        int elementoAtual = sequencia[i + blocoDois];
        sequencia.erase(sequencia.begin() + i + blocoDois);
        sequencia.insert(sequencia.begin() + j + blocoDois - 1, elementoAtual);
    }
}