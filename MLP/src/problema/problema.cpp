#include "problema.hpp"

// Construtor da classe
// Define a matriz que será utilizada
Problema::Problema(Data *data)
{
    quantidadeDePontos = data->getDimension();

    vector<vector<int>> matriz(quantidadeDePontos, vector<int>(quantidadeDePontos, 0));

    for (int i = 1; i <= quantidadeDePontos; i++)
    {
        for (int j = 1; j <= quantidadeDePontos; j++)
        {
            if (i != j)
            {
                matriz[i - 1][j - 1] = data->getDistance(i, j);
            }
        }
    }

    matrizValores = matriz;
}

Problema::~Problema()
{
}

// Getters
int Problema::getQuantidadePontos()
{
    return quantidadeDePontos;
}

vector<vector<int>> &Problema::getMatrizValores()
{
    return matrizValores;
}

// Setters
void Problema::setQuantidadePontos(int valor)
{
    quantidadeDePontos = valor;
}

void Problema::setMatrizValores(vector<vector<int>> &matriz)
{
    matrizValores = matriz;
}

// Para mostrar a matriz
void Problema::mostrarMatriz()
{

    for (int i = 0; i < quantidadeDePontos; i++)
    {
        for (int j = 0; j < quantidadeDePontos; j++)
        {
            cout << matrizValores[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void Problema::limparProblema()
{
    quantidadeDePontos = 0;
    matrizValores = {};
}