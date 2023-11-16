#include "../solucao/solucao.hpp"

void Solucao::perturbacaoReversalMove(Problema *p, int bloco)
{
    // * Informaces sobre a solucao
    int tamanho = this->getSequencia().size();
    vector<int> &sequencia = this->getSequencia();

    // * Informacoes sobre o problema
    vector<vector<int>> &v = p->getMatrizValores();

    // Sorteando as posições do bloco e onde ele entrará
    int posicaoBloco = rand() % (tamanho - bloco);
    int posicaoEntrada = rand() % (tamanho + 1);

    // Garantindo que a posição de entrada do bloco não seja entre as posições dos elementos do bloco
    while (posicaoEntrada >= posicaoBloco && posicaoEntrada <= posicaoBloco + bloco)
    {
        posicaoEntrada = rand() % (tamanho + 1);
    }

    int inicioBloco = sequencia[posicaoBloco];
    int fimBloco = sequencia[posicaoBloco + bloco - 1];
    int depoisBloco = sequencia[posicaoBloco + bloco];

    int entrada = sequencia[posicaoEntrada];

    int delta = 0;

    // Refazendo as conexões do segmento invertido
    for (int k = 0; k < bloco - 1; k++)
    {
        delta -= v[sequencia[posicaoBloco + k]][sequencia[posicaoBloco + 1 + k]];
        delta += v[sequencia[posicaoBloco + bloco - 1 - k]][sequencia[posicaoBloco + bloco - 2 - k]];
    }

    // # Se posicaoBloco estiver no coneço,
    // # Então, ele SÓ terá um vértice depois dele
    if (posicaoBloco == 0)
    {
        delta -= v[fimBloco][depoisBloco];
    }

    // # Se posicaoBloco estiver no fim,
    // # Então, ele SÓ terá um vértice antes dele
    if (posicaoBloco == tamanho - bloco)
    {
        int antesBloco = sequencia[posicaoBloco - 1];
        delta -= v[antesBloco][inicioBloco];
    }

    // # Se posicaoBloco não estiver no começo,
    // # Se posicaoBloco não estiver no fim,
    // # Então, ele terá um vértice antes e depois dele
    if (posicaoBloco != 0 && posicaoBloco != tamanho - bloco)
    {
        int antesBloco = sequencia[posicaoBloco - 1];
        delta -= v[antesBloco][inicioBloco];
        delta -= v[fimBloco][depoisBloco];
        delta += v[antesBloco][depoisBloco];
    }

    // & Se posicaoEntrada não estiver no começo,
    // & Então, a inserção será antes dele
    if (posicaoEntrada == 0)
    {
        delta += v[inicioBloco][entrada];
    }

    // & Se posicaoEntrada não estiver no começo,
    // & Se posicaoEntrada não estiver no fim,
    // & Então, a inserção será antes dele
    // & E posicaoEntrada terá um vértice antes dele
    if (posicaoEntrada != 0 && posicaoEntrada != tamanho)
    {
        int antesEntrada = sequencia[posicaoEntrada - 1];
        delta -= v[antesEntrada][entrada];
        delta += v[antesEntrada][fimBloco];

        delta += v[inicioBloco][entrada];
    }

    // & Se posicaoEntrada for o último,
    // & Então, a inserção será depois dele
    if (posicaoEntrada == tamanho)
    {
        int ultimaPosicao = sequencia[posicaoEntrada - 1];
        delta += v[ultimaPosicao][fimBloco];
    }

    // Atualizando o valor da solução
    this->setValor(this->getValor() + delta);

    // Reinserindo o bloco na posicao correta
    reinserirBlocoInvetido(sequencia, posicaoBloco, posicaoEntrada, bloco);
}