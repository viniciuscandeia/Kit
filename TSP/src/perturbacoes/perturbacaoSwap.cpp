#include "../solucao/solucao.hpp"

void Solucao::perturbacaoSwap(Problema *p, int blocoUm, int blocoDois)
{

    // * Informaces sobre a solucao
    int tamanho = this->getSequencia().size();
    vector<int> &sequencia = this->getSequencia();

    // * Informacoes sobre o problema
    vector<vector<int>> &v = p->getMatrizValores();

    int limiteJ = tamanho - blocoDois - 1;
    int limiteI = limiteJ - blocoUm;

    srand(time(NULL));

    // Sorteando quais as posições dos blocos que serão trocados
    int posicaoBlocoUm = rand() % (limiteI) + 1;

    int conta = limiteJ - posicaoBlocoUm - blocoUm;
    int posicaoBlocoDois = 0;
    if (conta == 0)
    {
        posicaoBlocoDois = posicaoBlocoUm + blocoUm;
    }
    else
    {
        posicaoBlocoDois = (rand() % (conta)) + posicaoBlocoUm + blocoUm;
    }

    int inicioBlocoUm = sequencia[posicaoBlocoUm];
    int antesBlocoUm = sequencia[posicaoBlocoUm - 1];
    int fimBlocoUm = sequencia[posicaoBlocoUm + blocoUm - 1];
    int depoisBlocoUm = sequencia[posicaoBlocoUm + blocoUm];

    int inicioBlocoDois = sequencia[posicaoBlocoDois];
    int antesBlocoDois = sequencia[posicaoBlocoDois - 1];
    int fimBlocoDois = sequencia[posicaoBlocoDois + blocoDois - 1];
    int depoisBlocoDois = sequencia[posicaoBlocoDois + blocoDois];

    int delta = 0;

    // Independente da situação, sempre ocorrerá isso
    delta -= v[fimBlocoUm][depoisBlocoUm];

    // i terá um vértice antes dele
    delta -= v[antesBlocoUm][inicioBlocoUm];

    // i terá um vértice antes dele
    delta += v[antesBlocoUm][inicioBlocoDois];

    // j terá um vértice depois dele
    delta -= v[fimBlocoDois][depoisBlocoDois];
    delta += v[fimBlocoUm][depoisBlocoDois];

    // Se blocoUm e blocoDois não são adjacentes
    if (posicaoBlocoUm + blocoUm != posicaoBlocoDois)
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

    // Trocando de posições i e j
    swap(sequencia, posicaoBlocoUm, posicaoBlocoDois, blocoUm, blocoDois);

    // Atualizando o valor da solução
    this->setValor(this->getValor() + delta);
}