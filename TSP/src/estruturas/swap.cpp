#include "../solucao/solucao.hpp"

// Trocar a posição de dois vértices na sequência
// Melhoria: possibilidade de trocar dois blocos
bool Solucao::bestImprovementSwap(Problema *p, int blocoUm, int blocoDois)
{
    int bestdDelta = 0;
    int bestI = 0;
    int bestJ = 0;

    int inicioBlocoUm = 0;
    int antesBlocoUm = 0;
    int fimBlocoUm = 0;
    int depoisBlocoUm = 0;

    int inicioBlocoDois = 0;
    int antesBlocoDois = 0;
    int fimBlocoDois = 0;
    int depoisBlocoDois = 0;

    // * Informaces sobre a solucao
    vector<int> &sequencia = this->getSequencia();
    int tamanho = sequencia.size();

    // * Informacoes sobre o problema
    vector<vector<int>> &v = p->getMatrizValores();

    // Limite dos fors
    int limiteJ = tamanho - blocoDois;
    int limiteI = limiteJ - blocoUm;

    // | Para i
    for (int i = 1; i < limiteI; i++)
    {

        antesBlocoUm = sequencia[i - 1];
        inicioBlocoUm = sequencia[i];
        fimBlocoUm = sequencia[i + blocoUm - 1];
        depoisBlocoUm = sequencia[i + blocoUm];

        int deltaBloco = 0;

        // Independente da situação, sempre ocorrerá isso
        deltaBloco -= v[fimBlocoUm][depoisBlocoUm];

        // i terá um vértice antes dele
        deltaBloco -= v[antesBlocoUm][inicioBlocoUm];

        // | Para j
        for (int j = i + blocoUm; j < limiteJ; j++)
        {

            int delta = deltaBloco;

            antesBlocoDois = sequencia[j - 1];
            inicioBlocoDois = sequencia[j];
            fimBlocoDois = sequencia[j + blocoDois - 1];
            depoisBlocoDois = sequencia[j + blocoDois];

            // i terá um vértice antes dele
            delta += v[antesBlocoUm][inicioBlocoDois];

            // j terá um vértice depois dele
            delta -= v[fimBlocoDois][depoisBlocoDois];
            delta += v[fimBlocoUm][depoisBlocoDois];

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

    int elementoAtual = 0;

    // Caso o blocoUm e o blocoDois sejam iguais
    if (blocoUm == blocoDois)
    {
        for (int k = 0; k < blocoUm; k++)
        {
            elementoAtual = sequencia[i + k];
            sequencia[i + k] = sequencia[j + k];
            sequencia[j + k] = elementoAtual;
        }
    }

    else
    {
        // Movendo os elementos do blocoDois
        for (int k = 0; k < blocoDois; k++)
        {
            elementoAtual = sequencia[j + k];
            sequencia.erase(sequencia.begin() + j + k);
            sequencia.insert(sequencia.begin() + i + k, elementoAtual);
        }

        // Movendo os elementos do blocoUm
        for (int k = 0; k < blocoUm; k++)
        {
            elementoAtual = sequencia[i + blocoDois];
            sequencia.erase(sequencia.begin() + i + blocoDois);
            sequencia.insert(sequencia.begin() + j + blocoDois - 1, elementoAtual);
        }
    }
}