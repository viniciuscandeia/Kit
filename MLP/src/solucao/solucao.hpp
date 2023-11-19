#ifndef SOLUCAO_HPP
#define SOLUCAO_HPP

#include <iostream>
#include <vector>
#include "../problema/problema.hpp"
#include <filesystem>
#include <chrono>
#include <thread>
#include <mutex>
#include <queue>

#define QUANT_PERTURBACOES 9
#define QUANT_ESTRUTURAS 10
#define INFINITE 9999999

using namespace std;
using namespace chrono;
namespace fs = filesystem;

void swap(vector<int> &sequencia, int i, int j, int blocoUm, int blocoDois);
void inverterSegmento(vector<int> &sequencia, int i, int j);
void reinserirBloco(vector<int> &sequencia, int i, int j, int bloco);
void reinserirBlocoInvetido(vector<int> &sequencia, int i, int j, int bloco);

void testesIndividuais(Problema *p);
void testesBuscasLocais(Problema *p);
void testesPerturbacoes(Problema *p);
void testesMetaheuristicas(Problema *p);

void validarValores(int encontrado, int certo);

void criarArquivo(string nomeArquivo);
void gerenciarProducaoArquivos();
void criarResultados();

class Solucao
{
private:
    int valorDaSolucao;
    vector<int> sequenciaDaSolucao;

public:
    Solucao();
    ~Solucao();

    // Getters
    int getValor();
    vector<int> &getSequencia();

    // Setters
    void setValor(int novoValor);
    void setSequencia(vector<int> &novaSequencia);

    // Metodos
    void mostrarSequencia();
    void calcularValor(Problema *p);
    void calcularCusto(Problema *p);
    void limparSolucao();

    // Algoritmo Guloso
    void algoritmoGuloso(Problema *p);

    // Estruturas de vizinhancas
    bool bestImprovementSwap(Problema *p, int blocoUm, int blocoDois);
    bool bestImprovement2Opt(Problema *p);
    bool bestImprovementReinsertion(Problema *p, int bloco);
    bool bestImprovementReversalMove(Problema *p, int bloco);

    // Buscas locais
    bool vnd(Problema *p);
    bool rvnd(Problema *p);

    // Perturbações
    void perturbacaoSwap(Problema *p, int blocoUm, int blocoDois);
    void perturbacaoReinsertion(Problema *p, int bloco);
    void perturbacaoReversalMove(Problema *p, int bloco);
    // perturbacao2Opt

    // Metaheurísticas
    void ilsVND(Problema *p, int maxIter, int maxIterILS);
    void ilsRVND(Problema *p, int maxIter, int maxIterILS);
};

#endif