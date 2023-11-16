#include "../solucao/solucao.hpp"

// Duas arestas não adjacentes da solução são removidas e o segmento entre elas é reinserido de maneira 
// invertida, adicionando-se duas novas arestas para reconstruir a solução
bool Solucao::bestImprovement2Opt(Problema *p)
{

    // Variáveis utilizadas ao longo do akgoritmo
    int bestDelta = 0;
    int bestI = 0;
    int bestJ = 0;

    int primeiro = 0;
    int depoisPrimeiro = 0;

    int segundo = 0;
    int antesSegundo = 0;

    // * Informaces sobre a solucao
    vector<int> &sequencia = this->getSequencia();
    int tamanho = sequencia.size();

    // * Informacoes sobre o problema
    vector<vector<int>> &v = p->getMatrizValores();

    // | Para i
    for (int i = 0; i < tamanho - 3; i++)
    {

        // Pegando o vértice i e o próximo dele
        primeiro = sequencia[i];
        depoisPrimeiro = sequencia[i + 1];

        // | Para j
        for (int j = i + 3; j < tamanho; j++)
        {

            // Pegando o vértice j e o anterior dele
            segundo = sequencia[j];
            antesSegundo = sequencia[j - 1];

            int delta = 0;

            // Removendo as arestas
            delta -= v[primeiro][depoisPrimeiro];
            delta -= v[antesSegundo][segundo];

            // Realizando alguns cálculos para evitar retrabalho dentro do for
            int quantidadeTrocas = j - i - 2;

            int preCalculo1 = i + 1;
            int preCalculo2 = i + 2;
            int preCalculo3 = j - 1;
            int preCalculo4 = j - 2;

            // Refazendo as conexões do segmento invertido
            for (int k = 0; k < quantidadeTrocas; k++)
            {
                delta -= v[sequencia[preCalculo1 + k]][sequencia[preCalculo2 + k]];
                delta += v[sequencia[preCalculo3 - k]][sequencia[preCalculo4 - k]];
            }

            // Adicionando as arestas
            delta += v[primeiro][antesSegundo];
            delta += v[depoisPrimeiro][segundo];

            // Verificando se encontrou uma situação en que vai reduzir o valor da solução
            if (delta < bestDelta)
            {
                bestDelta = delta;
                bestI = i;
                bestJ = j;
            }
        }

    }

    // Se encontrou a tal situação
    if (bestDelta < 0)
    {
        // Atualizando o valor da solução
        this->setValor(this->getValor() + bestDelta);

        // Invertendo a ordem dos vértices do segmento entre bestI e bestJ
        inverterSegmento(sequencia, bestI, bestJ);

        return true;
    }

    return false;
}

void inverterSegmento(vector<int> &sequencia, int i, int j)
{

    int quantidadeTrocas = ((j - i) / 2);

    // Realizando alguns cálculos para evitar retrabalho dentro do for
    int preCalculo1 = i + 1;
    int preCalculo2 = j - 1;

    // Algoritmo semelhante ao swap
    for (int k = 0; k < quantidadeTrocas; k++)
    {
        int aux = sequencia[preCalculo1 + k];
        sequencia[preCalculo1 + k] = sequencia[preCalculo2 - k];
        sequencia[preCalculo2 - k] = aux;
    }

}