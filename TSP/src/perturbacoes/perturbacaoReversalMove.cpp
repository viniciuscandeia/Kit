#include "../solucao/solucao.hpp"

void Solucao::perturbacaoReversalMove(Problema *p, int bloco)
{
    // * Informaces sobre a solucao
    vector<int> &sequencia = this->getSequencia();
    int tamanho = sequencia.size();

    // * Informacoes sobre o problema
    vector<vector<int>> &v = p->getMatrizValores();

    srand(time(NULL));

    // Sorteando as posições do bloco e onde ele entrará
    int posicaoBloco = rand() % (tamanho - bloco - 1) + 1;
    int posicaoEntrada = rand() % (tamanho - 1) + 1;

    // Garantindo que a posição de entrada do bloco não seja entre as posições dos elementos do bloco
    while (posicaoEntrada >= posicaoBloco && posicaoEntrada <= posicaoBloco + bloco)
    {
        posicaoEntrada = rand() % (tamanho - 1) + 1;
    }

    int inicioBloco = sequencia[posicaoBloco];
    int antesBloco = sequencia[posicaoBloco - 1];
    int fimBloco = sequencia[posicaoBloco + bloco - 1];
    int depoisBloco = sequencia[posicaoBloco + bloco];

    int entrada = sequencia[posicaoEntrada];
    int antesEntrada = sequencia[posicaoEntrada - 1];

    int delta = 0;

    // Refazendo as conexões do segmento invertido
    for (int k = 0; k < bloco - 1; k++)
    {
        delta -= v[sequencia[posicaoBloco + k]][sequencia[posicaoBloco + 1 + k]];
        delta += v[sequencia[posicaoBloco + bloco - 1 - k]][sequencia[posicaoBloco + bloco - 2 - k]];
    }

    delta -= v[antesBloco][inicioBloco];
    delta -= v[fimBloco][depoisBloco];

    delta += v[antesBloco][depoisBloco];

    delta -= v[antesEntrada][entrada];
    delta += v[antesEntrada][fimBloco];

    delta += v[inicioBloco][entrada];

    // Atualizando o valor da solução
    this->setValor(this->getValor() + delta);

    // Reinserindo o bloco na posicao correta
    reinserirBlocoInvetido(sequencia, posicaoBloco, posicaoEntrada, bloco);
}