#include "solucao/solucao.hpp"

// int main(int argc, char **argv)
int main()
{
	system("clear");

	// | Etapa 1

	// Criando o objeto da instância
	// Data data = Data(argc, argv[1]);
	// Data *data = new Data(2, "instances/berlin52.tsp");
	// data->read();

	// Criando o objeto do Problema
	// Problema *p = new Problema(data);
	// p->mostrarMatriz();

	// Criando o objeto da Solucao
	// Solucao *s = new Solucao();
	// s->algoritmoGuloso(p);

	// | Etapa 2

	// testesIndividuais(p);
	// testesBuscasLocais(p);
	// testesPerturbacoes(p);
	// testesMetaheuristicas(p);

	// | Etapa 3

	// !
	auto inicio = steady_clock::now();

	gerenciarProducaoArquivos();
	criarResultados();

	// !
	auto fim = steady_clock::now();
	auto duracao = duration_cast<seconds>(fim - inicio);
	cout << "Tempo executado: " << duracao.count() << endl;

	return 0;
}