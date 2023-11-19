#include "solucao.hpp"

// * Construtor

Solucao::Solucao()
{
    valorDaSolucao = 0;
    sequenciaDaSolucao = {};
}

Solucao::~Solucao()
{
}

// * Getters

int Solucao::getValor()
{
    return valorDaSolucao;
}

vector<int> &Solucao::getSequencia()
{
    return sequenciaDaSolucao;
}

// * Setters

void Solucao::setValor(int novoValor)
{
    valorDaSolucao = novoValor;
}

void Solucao::setSequencia(vector<int> &novaSequencia)
{
    sequenciaDaSolucao = novaSequencia;
}

// * Métodos

// Para mostrar a rota
void Solucao::mostrarSequencia()
{
    for (unsigned i = 0; i < sequenciaDaSolucao.size(); i++)
    {
        cout << sequenciaDaSolucao[i] << " ";
    }
    cout << endl;
}

// Calcular o valor da rota
void Solucao::calcularValor(Problema *p)
{
    int valor = 0;

    int tamanho = sequenciaDaSolucao.size();
    vector<int> &rota = this->getSequencia();

    for (int i = 0; i < tamanho - 1; i++)
    {
        valor += p->getMatrizValores()[rota[i]][rota[i + 1]];
    }

    valorDaSolucao = valor;
}

// Resetando as informações do objeto
void Solucao::limparSolucao()
{
    valorDaSolucao = 0;
    sequenciaDaSolucao = {};
}

// Verificando se cada estrutura de vizinhança desenvolvida está correta
void testesIndividuais(Problema *p)
{
    Solucao *t = new Solucao();

    int valorEncontrado = 0;
    int valorCorreto = 0;

    cout << " ----------- ESTRUTURAS DE VIZINHANÇA ----------- " << endl;

    t->algoritmoGuloso(p);
    cout << "ORIGINAL         : " << t->getValor() << endl;

    t->bestImprovementSwap(p, 1, 1);
    cout << "1 1 SWAP         : " << t->getValor();
    valorEncontrado = t->getValor();
    t->calcularValor(p);
    cout << " (" << t->getValor() << ") ";
    valorCorreto = t->getValor();
    validarValores(valorEncontrado, valorCorreto);

    t->mostrarSequencia();

    t->limparSolucao();
    t->algoritmoGuloso(p);

    t->bestImprovementSwap(p, 2, 1);
    cout << "2 1 SWAP         : " << t->getValor();
    valorEncontrado = t->getValor();
    t->calcularValor(p);
    cout << " (" << t->getValor() << ") ";
    valorCorreto = t->getValor();
    validarValores(valorEncontrado, valorCorreto);

    t->limparSolucao();
    t->algoritmoGuloso(p);

    t->bestImprovementSwap(p, 1, 2);
    cout << "1 2 SWAP         : " << t->getValor();
    valorEncontrado = t->getValor();
    t->calcularValor(p);
    cout << " (" << t->getValor() << ") ";
    valorCorreto = t->getValor();
    validarValores(valorEncontrado, valorCorreto);

    t->limparSolucao();
    t->algoritmoGuloso(p);

    t->bestImprovementSwap(p, 2, 2);
    cout << "2 2 SWAP         : " << t->getValor();
    valorEncontrado = t->getValor();
    t->calcularValor(p);
    cout << " (" << t->getValor() << ") ";
    valorCorreto = t->getValor();
    validarValores(valorEncontrado, valorCorreto);

    t->limparSolucao();
    t->algoritmoGuloso(p);

    t->bestImprovement2Opt(p);
    cout << "2-OPT            : " << t->getValor();
    valorEncontrado = t->getValor();
    t->calcularValor(p);
    cout << " (" << t->getValor() << ") ";
    valorCorreto = t->getValor();
    validarValores(valorEncontrado, valorCorreto);

    t->limparSolucao();
    t->algoritmoGuloso(p);

    t->bestImprovementReinsertion(p, 1);
    cout << "1 REINSERTION    : " << t->getValor();
    valorEncontrado = t->getValor();
    t->calcularValor(p);
    cout << " (" << t->getValor() << ") ";
    valorCorreto = t->getValor();
    validarValores(valorEncontrado, valorCorreto);

    t->limparSolucao();
    t->algoritmoGuloso(p);

    t->bestImprovementReinsertion(p, 2);
    cout << "2 REINSERTION    : " << t->getValor();
    valorEncontrado = t->getValor();
    t->calcularValor(p);
    cout << " (" << t->getValor() << ") ";
    valorCorreto = t->getValor();
    validarValores(valorEncontrado, valorCorreto);

    t->limparSolucao();
    t->algoritmoGuloso(p);

    t->bestImprovementReinsertion(p, 3);
    cout << "3 REINSERTION    : " << t->getValor();
    valorEncontrado = t->getValor();
    t->calcularValor(p);
    cout << " (" << t->getValor() << ") ";
    valorCorreto = t->getValor();
    validarValores(valorEncontrado, valorCorreto);

    t->limparSolucao();
    t->algoritmoGuloso(p);

    t->bestImprovementReversalMove(p, 2);
    cout << "2 REVERSAL MOVE  : " << t->getValor();
    valorEncontrado = t->getValor();
    t->calcularValor(p);
    cout << " (" << t->getValor() << ") ";
    valorCorreto = t->getValor();
    validarValores(valorEncontrado, valorCorreto);

    t->limparSolucao();
    t->algoritmoGuloso(p);

    t->bestImprovementReversalMove(p, 3);
    cout << "3 REVERSAL MOVE  : " << t->getValor();
    valorEncontrado = t->getValor();
    t->calcularValor(p);
    cout << " (" << t->getValor() << ") ";
    valorCorreto = t->getValor();
    validarValores(valorEncontrado, valorCorreto);

    t->limparSolucao();
    t->algoritmoGuloso(p);

    cout << endl;
}

// Verificando se cada busca local desenvolvida está correta
void testesBuscasLocais(Problema *p)
{

    Solucao *t = new Solucao();

    int valorEncontrado = 0;
    int valorCorreto = 0;

    cout << " ---------------- BUSCAS LOCAIS ----------------- " << endl;

    t->algoritmoGuloso(p);
    cout << "ORIGINAL         : " << t->getValor() << endl;

    t->vnd(p);
    cout << "VND              : " << t->getValor();
    valorEncontrado = t->getValor();
    t->calcularValor(p);
    cout << " (" << t->getValor() << ") ";
    valorCorreto = t->getValor();
    validarValores(valorEncontrado, valorCorreto);

    t->limparSolucao();
    t->algoritmoGuloso(p);

    t->rvnd(p);
    cout << "RVND             : " << t->getValor();
    valorEncontrado = t->getValor();
    t->calcularValor(p);
    cout << " (" << t->getValor() << ") ";
    valorCorreto = t->getValor();
    validarValores(valorEncontrado, valorCorreto);

    cout << endl;
}

// Verificando se cada perturbação desenvolvida está correta
void testesPerturbacoes(Problema *p)
{

    Solucao *t = new Solucao();

    int valorEncontrado = 0;
    int valorCorreto = 0;

    cout << " ----------------- PERTURBAÇÕES ----------------- " << endl;

    t->algoritmoGuloso(p);
    cout << "ORIGINAL         : " << t->getValor() << endl;

    t->perturbacaoSwap(p, 1, 1);
    cout << "1 1 PERT SWAP    : " << t->getValor();
    valorEncontrado = t->getValor();
    t->calcularValor(p);
    cout << " (" << t->getValor() << ") ";
    valorCorreto = t->getValor();
    validarValores(valorEncontrado, valorCorreto);

    t->limparSolucao();
    t->algoritmoGuloso(p);

    t->perturbacaoSwap(p, 2, 1);
    cout << "2 1 PERT SWAP    : " << t->getValor();
    valorEncontrado = t->getValor();
    t->calcularValor(p);
    cout << " (" << t->getValor() << ") ";
    valorCorreto = t->getValor();
    validarValores(valorEncontrado, valorCorreto);

    t->limparSolucao();
    t->algoritmoGuloso(p);

    t->perturbacaoSwap(p, 1, 2);
    cout << "1 2 PERT SWAP    : " << t->getValor();
    valorEncontrado = t->getValor();
    t->calcularValor(p);
    cout << " (" << t->getValor() << ") ";
    valorCorreto = t->getValor();
    validarValores(valorEncontrado, valorCorreto);

    t->limparSolucao();
    t->algoritmoGuloso(p);

    t->perturbacaoSwap(p, 2, 2);
    cout << "2 2 PERT SWAP    : " << t->getValor();
    valorEncontrado = t->getValor();
    t->calcularValor(p);
    cout << " (" << t->getValor() << ") ";
    valorCorreto = t->getValor();
    validarValores(valorEncontrado, valorCorreto);

    t->limparSolucao();
    t->algoritmoGuloso(p);

    t->perturbacaoReversalMove(p, 2);
    cout << "2 PERT RM        : " << t->getValor();
    valorEncontrado = t->getValor();
    t->calcularValor(p);
    cout << " (" << t->getValor() << ") ";
    valorCorreto = t->getValor();
    validarValores(valorEncontrado, valorCorreto);

    t->limparSolucao();
    t->algoritmoGuloso(p);

    t->perturbacaoReversalMove(p, 3);
    cout << "3 PERT RM        : " << t->getValor();
    valorEncontrado = t->getValor();
    t->calcularValor(p);
    cout << " (" << t->getValor() << ") ";
    valorCorreto = t->getValor();
    validarValores(valorEncontrado, valorCorreto);

    t->limparSolucao();
    t->algoritmoGuloso(p);

    cout << endl;
}

// Verificando se cada metaheurística desenvolvida está correta
void testesMetaheuristicas(Problema *p)
{

    Solucao *t = new Solucao();

    int valorEncontrado = 0;
    int valorCorreto = 0;

    cout << " ---------------- METAHEURÍSTICAS --------------- " << endl;

    t->algoritmoGuloso(p);
    cout << "ORIGINAL         : " << t->getValor() << endl;

    t->ilsVND(p, 50, 100);
    cout << "ILS VND          : " << t->getValor();
    valorEncontrado = t->getValor();
    t->calcularValor(p);
    cout << " (" << t->getValor() << ") ";
    valorCorreto = t->getValor();
    validarValores(valorEncontrado, valorCorreto);

    t->limparSolucao();
    t->algoritmoGuloso(p);

    t->ilsRVND(p, 50, 100);
    cout << "ILS RVND         : " << t->getValor();
    valorEncontrado = t->getValor();
    t->calcularValor(p);
    cout << " (" << t->getValor() << ") ";
    valorCorreto = t->getValor();
    validarValores(valorEncontrado, valorCorreto);

    cout << endl;
}

// Indicação visual para o resultado dos testes
void validarValores(int encontrado, int certo)
{
    if (encontrado == certo)
    {
        // Código ANSI para fundo verde
        cout << "\x1b[48;5;2m \x1b[0m" << endl;
    }
    else
    {
        // Código ANSI para fundo vermelho
        cout << "\x1b[48;5;1m \x1b[0m" << endl;
    }
}

// Aplicando VND, RNVD, ILS VND e ILS RVND para a instância passada
// Gerando um arquivo com o nome da instância com os resultados
void criarArquivo(string nomeArquivo)
{

    // | Criando o objeto da Solucao
    Solucao *s = new Solucao();

    // | Para o arquivo de saída
    string arquivoSaida = nomeArquivo;

    // Encontrar a posição da substring ".tsp"
    size_t pos = arquivoSaida.find(".tsp");
    while (pos != string::npos)
    {
        // Substituir ".tsp" por ".txt"
        arquivoSaida.replace(pos, 4, ".txt");
        // Encontrar a próxima posição da substring ".tsp"
        pos = arquivoSaida.find(".tsp", pos + 1);
    }
    arquivoSaida = "././saida/" + arquivoSaida;

    ofstream arquivo(arquivoSaida);

    int repeticoes = 1;

    // Escrevendo o nome da instância no arquivo de saída
    arquivo << nomeArquivo << " ";

    string pastaInstancias = "././instances";
    string caminhoArquivo = pastaInstancias + "/" + nomeArquivo;

    // Criando o objeto da instância
    Data *data = new Data(2, caminhoArquivo);
    data->read();

    // Criando o objeto do Problema
    Problema *p = new Problema(data);

    // | Para o algoritmo guloso
    // !
    auto inicio = steady_clock::now();

    s->algoritmoGuloso(p);

    // !
    auto fim = steady_clock::now();
    auto duracao = duration_cast<microseconds>(fim - inicio);
    arquivo << s->getValor() << " " << duracao.count() << " ";

    // | Para o VND
    // !
    inicio = steady_clock::now();

    s->vnd(p);

    // !
    fim = steady_clock::now();
    duracao = duration_cast<microseconds>(fim - inicio);
    arquivo << s->getValor() << " " << duracao.count() << " ";

    // | Para o RVND
    double somaValores = 0;
    double somaTempos = 0;

    // Valor médio de 10 execuções
    for (int j = 0; j < repeticoes; j++)
    {
        s->limparSolucao();
        s->algoritmoGuloso(p);

        // !
        inicio = steady_clock::now();
        s->rvnd(p);

        // !
        fim = steady_clock::now();
        duracao = duration_cast<microseconds>(fim - inicio);

        somaValores += s->getValor();
        somaTempos += duracao.count();
    }
    arquivo << (somaValores / repeticoes) << " " << (somaTempos / repeticoes) << " ";

    // | Para o ILS VND
    somaValores = 0;
    somaTempos = 0;

    // Valor médio de 10 execuções
    for (int j = 0; j < repeticoes; j++)
    {
        s->limparSolucao();
        s->algoritmoGuloso(p);

        // !
        inicio = steady_clock::now();
        s->ilsVND(p, 100, 50);

        // !
        fim = steady_clock::now();
        duracao = duration_cast<microseconds>(fim - inicio);

        somaValores += s->getValor();
        somaTempos += duracao.count();
    }
    arquivo << (somaValores / repeticoes) << " " << (somaTempos / repeticoes) << " ";

    // | Para o ILS RVND
    somaValores = 0;
    somaTempos = 0;

    // Valor médio de 10 execuções
    for (int j = 0; j < repeticoes; j++)
    {
        s->limparSolucao();
        s->algoritmoGuloso(p);

        // !
        inicio = steady_clock::now();
        s->ilsRVND(p, 100, 50);

        // !
        fim = steady_clock::now();
        duracao = duration_cast<microseconds>(fim - inicio);

        somaValores += s->getValor();
        somaTempos += duracao.count();
    }
    arquivo << (somaValores / repeticoes) << " " << (somaTempos / repeticoes) << " ";

    delete data;
    delete p;
    delete s;

    arquivo.close();
}

// Pegando os nomes das instâncias e aplicando nelas as heurísticas
// Uso de threads para acelerar
void gerenciarProducaoArquivos()
{

    // | Para as instâncias
    string pastaInstancias = "././instances";
    vector<string> nomesArquivos = {};

    // Pegando o nome dos arquivos das instâncias
    for (const auto &entry : fs::directory_iterator(pastaInstancias))
    {
        if (fs::is_regular_file(entry))
        {
            nomesArquivos.push_back(entry.path().filename().string());
        }
    }

    // Ordenando de forma alfabética
    sort(nomesArquivos.begin(), nomesArquivos.end());
    int quantidadeArquivos = nomesArquivos.size();

    int quantidadeThreads = 4;

    vector<thread> threads = {};
    queue<string> arquivoQueue;
    mutex mtx;

    // Inicializar fila de arquivos
    for (int i = 0; i < quantidadeArquivos; ++i)
    {
        arquivoQueue.push(nomesArquivos[i]);
    }

    // Função para processar a fila de arquivos
    auto processarFila = [&]()
    {
        while (true)
        {
            string nomeArquivo;
            {
                unique_lock<mutex> lock(mtx);
                if (arquivoQueue.empty())
                {
                    // Fila vazia, sair do loop
                    break; 
                }

                // Pega o arquivo que está na frente da fila
                nomeArquivo = arquivoQueue.front();
                arquivoQueue.pop();
            }

            cout << "Processando: " << nomeArquivo << endl;
            criarArquivo(nomeArquivo);
        }
    };

    // Inicializar e executar threads
    for (int i = 0; i < quantidadeThreads; ++i)
    {
        threads.emplace_back(processarFila);
    }

    // Aguardar a conclusão de todas as threads
    for (thread &t : threads)
    {
        t.join();
    }
}

// Compilando os resultados obtidos em um único arquivo
void criarResultados()
{
    // | Para os resultados
    string pastaSaida = "././saida";
    vector<string> nomesArquivos = {};

    // Pegando o nome dos arquivos das instâncias
    for (const auto &entry : fs::directory_iterator(pastaSaida))
    {
        if (fs::is_regular_file(entry))
        {
            nomesArquivos.push_back(entry.path().filename().string());
        }
    }

    // Ordenando de forma alfabética
    sort(nomesArquivos.begin(), nomesArquivos.end());
    int quantidadeArquivos = nomesArquivos.size();

    // Criando o arquivo de resultados
    ofstream arquivo("resultados.txt");

    for (int i = 0; i < quantidadeArquivos; i++)
    {
        string caminhoArquivo = pastaSaida + "/" + nomesArquivos[i];
        ifstream arquivoEntrada(caminhoArquivo);

        cout << caminhoArquivo << endl;

        // Verificar se o arquivo foi aberto com sucesso
        if (arquivoEntrada.is_open())
        {
            // Variável para armazenar cada linha do arquivo
            string linha;

            // Loop para ler cada linha do arquivo
            while (getline(arquivoEntrada, linha))
            {
                // Processar a linha conforme necessário
                arquivo << linha << endl;
            }

            // Fechar o arquivo após a leitura
            arquivoEntrada.close();
        }
        else
        {
            // Exibir uma mensagem se o arquivo não puder ser aberto
            cerr << "Erro ao abrir o arquivo: " << nomesArquivos[i] << endl;
        }
    }

    arquivo.close();
}