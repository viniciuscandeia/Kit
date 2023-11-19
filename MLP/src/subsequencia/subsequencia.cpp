#include "subsequencia.hpp"

Subsequencia::Subsequencia(vector<int> &vetor)
{
    int tamanho = vetor.size();
    this->setPrimeiro(vetor[0]);
    this->setUltimo(vetor[tamanho - 1]);

    if (tamanho == 1)
    {
        this->setT(0);
        this->setC(0);
        this->setW(0);
    }
    else
    {
        this->setW(1);
    }
}

Subsequencia::~Subsequencia()
{
}

// Setters
void Subsequencia::setPrimeiro(int valor)
{
    primeiroDaSequencia = valor;
}

void Subsequencia::setUltimo(int valor)
{
    ultimoDaSequencia = valor;
}

void Subsequencia::setT(double valor)
{
    T = valor;
}

void Subsequencia::setC(double valor)
{
    C = valor;
}

void Subsequencia::setW(int valor)
{
    W = valor;
}

// Getters
int Subsequencia::getPrimeiro()
{
    return primeiroDaSequencia;
}

int Subsequencia::getUltimo()
{
    return ultimoDaSequencia;
}

double Subsequencia::getT()
{
    return T;
}

double Subsequencia::getC()
{
    return C;
}

int Subsequencia::getW()
{
    return W;
}

Subsequencia concatenar(Subsequencia *sub1, Subsequencia *sub2, Problema *p)
{
    vector<int> vetor = {0};
    Subsequencia *novaSequencia = new Subsequencia(vetor);

    vector<vector<int>> &m = p->getMatrizValores();

    // Aresta entre as subsequências
    double temp = m[sub1->getUltimo()][sub2->getPrimeiro()];

    // cout << "1" << endl;

    novaSequencia->setW(sub1->getW() + sub2->getW());

    // cout << "1.5" << endl;

    novaSequencia->setT(sub1->getT() + temp + sub2->getT());

    // cout << "2" << endl;

    novaSequencia->setC(sub1->getC() + sub2->getW() * (sub1->getT() + temp) + sub2->getC());
    novaSequencia->setPrimeiro(sub1->getPrimeiro());

    // cout << "3" << endl;

    novaSequencia->setUltimo(sub2->getUltimo());

    // cout << "4" << endl;

    return *novaSequencia;
}

// Método
void Subsequencia::mostrarSubSequencia(Solucao *s)
{
    vector<int> &sequencia = s->getSequencia();
    int tamanho = sequencia.size();

    int primeiro = this->getPrimeiro();
    int ultimo = this->getUltimo();

    int indicePrimeiro = -1;
    int indiceUltimo = -1;

    for (int i = 0; i < tamanho; i++)
    {
        // Encontrar índice para o primeiro
        if (sequencia[i] == primeiro && indicePrimeiro == -1)
        {
            indicePrimeiro = i;
        }

        // Encontrar índice para o último
        if (sequencia[i] == ultimo && indiceUltimo == -1)
        {
            indiceUltimo = i;
        }
    }

    for (int i = indicePrimeiro; i <= indiceUltimo; i++)
    {
        cout << sequencia[i] << " ";
    }
    cout << endl;
}