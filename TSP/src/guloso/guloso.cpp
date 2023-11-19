#include "../solucao/solucao.hpp"

void Solucao::algoritmoGuloso(Problema *p)
{
    // Pegando as informações da instância
    int quantidadePontos = p->getQuantidadePontos();
    vector<vector<int>> &m = p->getMatrizValores();

    // Criando um vetor com a quantidade de linhas dita pela instância
    vector<int> rota = {};
    int tamanhoRota = 0;
    int ultimoRota = 0;

    // Criando um vetor de frequência dos pontos
    vector<int> frequencia(quantidadePontos, 0);

    // Adiciona na rota o ponto 0
    rota.push_back(0);
    frequencia[0] = 1;

    int custoRota = 0;

    // Loop com a quantidade de pontos
    for (int i = 1; i < quantidadePontos; i++)
    {

        // Pegando o último ponto que foi inserido na rota
        tamanhoRota = rota.size();
        ultimoRota = rota[tamanhoRota - 1];

        int adicionarNaRota = 0;
        int bestDelta = INFINITE;

        // Procurando qual ponto, que ainda não está na rota, tem a menor aresta para
        // o último ponto da rota
        for (int j = 1; j < quantidadePontos; j++)
        {
            // O ponto da posição j não pode ter sido utilizado
            if (frequencia[j] == 1)
            {
                continue;
            }

            int delta = 0;

            delta += m[ultimoRota][j];

            // Verificando se o ponto é melhor ou não
            if (delta < bestDelta)
            {
                bestDelta = delta;
                adicionarNaRota = j;
            }
        }

        // Adicionando o ponto na rota
        rota.push_back(adicionarNaRota);

        // Considerando aquele ponto já utilizado
        frequencia[adicionarNaRota] = 1;

        // Somando o valor daquele ponto na rota
        custoRota += bestDelta;
    }

    // Atualizando a rota e o valor da solução
    this->setSequencia(rota);
    this->setValor(custoRota);
}