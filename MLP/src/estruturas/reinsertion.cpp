#include "../solucao/solucao.hpp"

// Um único vértice é retirado de sua posição e inserido em outra
// Código adaptado para realizar o OR-OPT-2 e o OR-OPT-3
bool Solucao::bestImprovementReinsertion(Problema *p, int bloco)
{
    int bestDelta = 0;
    int bestI = 0;
    int bestJ = 0;

    int inicioBloco = 0;
    int fimBloco = 0;
    int depoisBloco = 0;

    int entrada = 0;

    // * Informaces sobre a solucao
    int tamanho = this->getSequencia().size();
    vector<int> &sequencia = this->getSequencia();

    // * Informacoes sobre o problema
    vector<vector<int>> &v = p->getMatrizValores();

    int limiteI = tamanho - bloco + 1;

    // | Para i
    for (int i = 0; i < limiteI; i++)
    {

        inicioBloco = sequencia[i];

        // Se bloco = 1 -> fimBloco = inicioBloco
        // Se bloco = 2 -> fimBloco = inicioBloco + 1
        // Se bloco = 3 -> fimBloco = inicioBloco + 2

        fimBloco = sequencia[i + bloco - 1];

        // Se bloco = 1 -> depoisBloco = inicioBloco + 1
        // Se bloco = 2 -> depoisBloco = inicioBloco + 2
        // Se bloco = 3 -> depoisBloco = inicioBloco + 3

        depoisBloco = sequencia[i + bloco];

        // | Para j
        for (int j = 0; j <= tamanho; j++)
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

            // & Se j for tamanho, o bloco será inserido após o último elemento
            if (j == tamanho)
            {
                entrada = sequencia[j - 1];
            }
            else
            {
                entrada = sequencia[j];
            }

            int delta = 0;

            // # Se i estiver no coneço,
            // # Então, ele SÓ terá um vértice depois dele
            if (i == 0)
            {
                delta -= v[fimBloco][depoisBloco];
            }

            // # Se i estiver no fim,
            // # Então, ele SÓ terá um vértice antes dele
            if (i == tamanho - bloco)
            {
                int antesBloco = sequencia[i - 1];
                delta -= v[antesBloco][inicioBloco];
            }

            // # Se i não estiver no começo,
            // # Se i não estiver no fim,
            // # Então, ele terá um vértice antes e depois dele
            if (i != 0 && i != tamanho - bloco)
            {
                int antesBloco = sequencia[i - 1];
                delta -= v[antesBloco][inicioBloco];
                delta -= v[fimBloco][depoisBloco];
                delta += v[antesBloco][depoisBloco];
            }

            // & Se j não estiver no começo,
            // & Então, a inserção será antes dele
            if (j == 0)
            {
                delta += v[fimBloco][entrada];
            }

            // & Se j não estiver no começo,
            // & Se j não estiver no fim,
            // & Então, a inserção será antes dele
            // & E j terá um vértice antes dele
            if (j != 0 && j != tamanho)
            {
                int antesEntrada = sequencia[j - 1];
                delta -= v[antesEntrada][entrada];
                delta += v[antesEntrada][inicioBloco];

                delta += v[fimBloco][entrada];
            }

            // & Se j for o último,
            // & Então, a inserção será depois dele
            if (j == tamanho)
            {
                int ultimaPosicao = sequencia[j - 1];
                delta += v[ultimaPosicao][inicioBloco];
            }

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
        reinserirBloco(sequencia, bestI, bestJ, bloco);

        return true;
    }

    return false;
}

void reinserirBloco(vector<int> &sequencia, int i, int j, int bloco)
{

    int tamanho = sequencia.size();

    // Caso o bloco tenha que ser inserido depois da sua posição atual
    int puxarPosicao = 0;
    if (i < j)
    {
        puxarPosicao = -1;
    }

    int casoAntes = 0;

    for (int k = 0; k < bloco; k++)
    {

        // Caso o bloco tenha que ser inserido antes da sua posição atual
        if (i > j)
        {
            casoAntes = k;
        }

        int elementoAtual = sequencia[i + casoAntes];

        // Apagando os elementos do bloco
        sequencia.erase(sequencia.begin() + i + casoAntes);

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
