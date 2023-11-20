#include "../solucao/solucao.hpp"

// Um bloco de vértices é retirado de sua posição e inserido em outra, de maneira invertida
bool Solucao::bestImprovementReversalMove(Problema *p, int bloco)
{

    // Variáveis utilizdas ao longo do algoritmo
    int bestDelta = 0;
    int bestI = 0;
    int bestJ = 0;

    int inicioBloco = 0;
    int antesBloco = 0;
    int fimBloco = 0;
    int depoisBloco = 0;

    int entrada = 0;
    int antesEntrada = 0;

    int deltaBloco = 0;
    int delta = 0;

    int preCalculo1 = 0;
    int preCalculo2 = 0;
    int preCalculo3 = 0;

    // * Informaces sobre a solucao
    int tamanho = this->getSequencia().size();
    vector<int> &sequencia = this->getSequencia();

    // * Informacoes sobre o problema
    vector<vector<int>> &v = p->getMatrizValores();

    int limiteI = tamanho - bloco;

    // | Para i
    for (int i = 1; i < limiteI; i++)
    {

        deltaBloco = 0;

        // Realizando alguns cálculos para evitar retrabalho dentro do for
        preCalculo1 = i + 1;
        preCalculo2 = i + bloco - 1;
        preCalculo3 = i + bloco - 2;

        // Refazendo as conexões do segmento invertido
        for (int k = 0; k < bloco - 1; k++)
        {
            deltaBloco -= v[sequencia[i + k]][sequencia[preCalculo1 + k]];
            deltaBloco += v[sequencia[preCalculo2 - k]][sequencia[preCalculo3 - k]];
        }

        antesBloco = sequencia[i - 1];
        inicioBloco = sequencia[i];
        fimBloco = sequencia[i + bloco - 1];
        depoisBloco = sequencia[i + bloco];

        deltaBloco = -v[antesBloco][inicioBloco] - v[fimBloco][depoisBloco] + v[antesBloco][depoisBloco];

        // | Para j
        for (int j = 1; j < tamanho; j++)
        {

            // Padrão: inserir no lado esquerdo de j.
            // Com o padrão adotado, ficaria faltando um caso, que é inserir após o último elemento.
            // Para corrigir, o for vai até o tamanho (<=).
            // Caso j == tamanho, irá inserir no lado direito de j - 1

            // & j não pode tá dentro do bloco
            if (j >= i && j <= i + bloco)
            {
                continue;
            }

            entrada = sequencia[j];
            antesEntrada = sequencia[j - 1];

            delta = deltaBloco - v[antesEntrada][entrada] + v[antesEntrada][fimBloco] + v[inicioBloco][entrada];

            // Verificando se encontrou uma situação en que vai reduzir o valor da solução
            if (delta < bestDelta)
            {
                bestDelta = delta;
                bestI = i;
                bestJ = j;
            }
        }
    }

    // | Se encontrou a tal situação
    if (bestDelta < 0)
    {
        // Atualizando o valor da solução
        this->setValor(this->getValor() + bestDelta);

        // Reinserindo o bloco na posicao correta
        reinserirBlocoInvetido(sequencia, bestI, bestJ, bloco);

        return true;
    }

    return false;
}

void reinserirBlocoInvetido(vector<int> &sequencia, int i, int j, int bloco)
{

    int tamanho = sequencia.size();

    // Caso o bloco tenha que ser inserido depois da sua posição atual
    int puxarPosicao = 0;
    if (i < j)
    {
        puxarPosicao = -1;
    }

    int casoAntes = 0;

    int preCalculo1 = i + bloco - 1;

    for (int k = 0; k < bloco; k++)
    {

        // Caso o bloco tenha que ser inserido antes da sua posição atual
        if (i > j)
        {
            casoAntes = k;
        }

        int elementoAtual = sequencia[preCalculo1 - k + casoAntes];

        // Apagando os elementos do bloco
        sequencia.erase(sequencia.begin() + preCalculo1 - k + casoAntes);

        // Inserindo os elementos do bloco nas novas posicoes deles
        if (j != tamanho)
        {
            sequencia.insert(sequencia.begin() + j + casoAntes + puxarPosicao, elementoAtual);
        }
        else
        {
            sequencia.push_back(elementoAtual);
        }
    }
}
