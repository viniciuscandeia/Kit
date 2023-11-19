#ifndef SUBSEQUENCIA_HPP
#define SUBSEQUENCIA_HPP

#include <vector>
#include "../problema/problema.hpp"
#include "../solucao/solucao.hpp"

using namespace std;

class Subsequencia
{
private:
    // | Sobre a sequência
    int primeiroDaSequencia;
    int ultimoDaSequencia;

    // | Para o cálculo

    // T -> duração
    // C -> custo acumulado
    // W -> custo de atraso
    double T;
    double C;
    int W;

public:
    Subsequencia(vector<int> &vetor);
    ~Subsequencia();

    // Setters
    void setPrimeiro(int valor);
    void setUltimo(int valor);
    void setT(double valor);
    void setC(double valor);
    void setW(int valor);

    // Getters
    int getPrimeiro();
    int getUltimo();
    double getT();
    double getC();
    int getW();

    // Métodos
    void mostrarSubSequencia(Solucao *s);
};

Subsequencia concatenar(Subsequencia *sub1, Subsequencia *sub2, Problema *p);

#endif
