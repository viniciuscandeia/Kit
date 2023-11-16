#include "../solucao/solucao.hpp"

void Solucao::perturbacaoSwap(Problema *p, int blocoUm, int blocoDois)
{

    // * Informaces sobre a solucao
    int tamanho = this->getSequencia().size();
    vector<int> &sequencia = this->getSequencia();

    // * Informacoes sobre o problema
    vector<vector<int>> &v = p->getMatrizValores();

    int limiteJ = tamanho + 1 - blocoDois;
    int limiteI = limiteJ - blocoUm;

    // Sorteando quais as posições dos blocos que serão trocados
    int posicaoBlocoUm = rand() % (limiteI);
    int posicaoBlocoDois = (rand() % (limiteJ - posicaoBlocoUm - blocoUm)) + posicaoBlocoUm + blocoUm;

    int inicioBlocoUm = sequencia[posicaoBlocoUm];
    int fimBlocoUm = sequencia[posicaoBlocoUm + blocoUm - 1];
    int depoisBlocoUm = sequencia[posicaoBlocoUm + blocoUm];

    int inicioBlocoDois = sequencia[posicaoBlocoDois];
    int fimBlocoDois = sequencia[posicaoBlocoDois + blocoDois - 1];
    int antesBlocoDois = sequencia[posicaoBlocoDois - 1];

    int delta = 0;

    delta -= v[fimBlocoUm][depoisBlocoUm];

    if (posicaoBlocoUm != 0)
    {
        int antesBlocoUm = sequencia[posicaoBlocoUm - 1];
        delta -= v[antesBlocoUm][inicioBlocoUm];
        delta += v[antesBlocoUm][inicioBlocoDois];
    }

    if (posicaoBlocoUm + blocoUm != posicaoBlocoDois)
    {
        delta += v[fimBlocoDois][depoisBlocoUm];

        delta -= v[antesBlocoDois][inicioBlocoDois];
        delta += v[antesBlocoDois][inicioBlocoUm];
    }
    else
    {
        delta += v[fimBlocoDois][inicioBlocoUm];
    }

    if (posicaoBlocoDois + blocoDois != tamanho)
    {
        int depoisBlocoDois = sequencia[posicaoBlocoDois + blocoDois];

        delta -= v[fimBlocoDois][depoisBlocoDois];
        delta += v[fimBlocoUm][depoisBlocoDois];
    }

    // Trocando de posições i e j
    swap(sequencia, posicaoBlocoUm, posicaoBlocoDois, blocoUm, blocoDois);

    // Atualizando o valor da solução
    this->setValor(this->getValor() + delta);

}