#ifndef PROBLEMA_HPP
#define PROBLEMA_HPP

#include <iostream>
#include <vector>
#include "../data/Data.h"

using namespace std;

class Problema
{
private:
    int quantidadeDePontos;
    vector<vector<int>> matrizValores;

public:
    Problema(Data *data);
    ~Problema();

    // Getters
    int getQuantidadePontos();
    vector<vector<int>> &getMatrizValores();

    // Setters
    void setMatrizValores(vector<vector<int>> &matriz);
    void setQuantidadePontos(int valor);

    // Métodos
    void mostrarMatriz();
    void limparProblema();
};

#endif