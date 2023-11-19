#include "solucao/solucao.hpp"
#include "subsequencia/subsequencia.hpp"

// int main(int argc, char **argv)
int main()
{
	system("clear");

	// | Etapa 1

	// Criando o objeto da instância
	// Data data = Data(argc, argv[1]);
	Data *data = new Data(2, "instances/gr17.tsp");
	data->read();

	// Criando o objeto do Problema
	Problema *p = new Problema(data);
	p->limparProblema();

	vector<vector<int>> matriz = {
		{0, 12, 0, 0, 9, 16},
		{12, 0, 19, 12, 0, 15},
		{0, 19, 0, 21, 0, 17},
		{0, 12, 21, 0, 10, 16},
		{9, 0, 0, 10, 0, 10},
		{16, 15, 17, 16, 10, 0}};

	p->setMatrizValores(matriz);
	p->setQuantidadePontos(6);

	p->mostrarMatriz();

	// Criando o objeto da Solucao
	Solucao *s = new Solucao();
	vector<int> sequencia = {0, 4, 3, 1, 2, 5, 0};

	s->setSequencia(sequencia);
	s->mostrarSequencia();
	s->calcularCusto(p);

	vector<int> subsequencia1 = {0};
	vector<int> subsequencia2 = {1};

	Subsequencia *sub1 = new Subsequencia(subsequencia1);
	sub1->mostrarSubSequencia(s);

	Subsequencia *sub2 = new Subsequencia(subsequencia2);
	sub2->mostrarSubSequencia(s);

	Subsequencia sub3 = concatenar(sub1, sub2, p);

	sub3.mostrarSubSequencia(s);

	// | Etapa 2

	// testesIndividuais(p);
	// testesBuscasLocais(p);
	// testesPerturbacoes(p);
	// testesMetaheuristicas(p);

	// | Etapa 3

	{
		// // !
		// auto inicio = steady_clock::now();

		// gerenciarProducaoArquivos();
		// criarResultados();

		// // !
		// auto fim = steady_clock::now();
		// auto duracao = duration_cast<microseconds>(fim - inicio);
		// cout << "Tempo executado: " << duracao.count() << endl;
	}

	return 0;
}