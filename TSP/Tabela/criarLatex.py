import pandas as pd

resultados = open("./resultados.txt", "r")

linhas: list = []

tabelaOriginal: list = [
                        2579,
                        202384,
                        10628,
                        27731,
                        1610,
                        2020,
                        7542,
                        118282,
                        25395,
                        1950,
                        3323,
                        6110,
                        6528,
                        15780,
                        35042,
                        699,
                        629,
                        429,
                        538,
                        11861,
                        937,
                        2378.7,
                        6942,
                        69853,
                        2085,
                        40160.1,
                        2707,
                        134613,
                        1272,
                        171530,
                        5046,
                        55209,
                        11461,
                        21282,                        
                        26524,
                        29368,
                        22141,
                        26130,
                        29437.2,
                        20749,
                        21294,
                        22068,
                        14379,
                        42045.7,
                        42053.1,
                        50876,
                        44303,
                        59030,
                        96772,
                        58537,
                        73682,
                        80369,
                        49135,
                        48194.8,
                        108159,
                        2326.1,
                        1211,
                        7910,
                        15296.1,
                        21407,
                        48466.8,
                        675,
                        1273,
                        126643,
                        3916,
                        42080,
                        6859,
                        7013
                       ]

for linha in resultados:
    divisao: list = list(linha[:-2].split(" "))
    linhas.append(divisao.copy())

nomesInstancias: list = []
for linha in linhas:
    nome: str = linha[0]
    nome = nome.replace(".tsp", "")
    nomesInstancias.append(nome)
    
valores: list = []
tempos: list = []
gap: list = []
for posicao, linha in enumerate(linhas):
    menorValor: float = float(linha[1])
    menorTempo: float = float(linha[2]) / 1000000
    for i in range(3, len(linha), 2):
        if (float(linha[i]) < menorValor):
            menorValor: float = float(linha[i])
            menorTempo: float = float(linha[i + 1]) / 1000000
    contaGAP = ((menorValor - tabelaOriginal[posicao]) / tabelaOriginal[posicao]) * 100
    gap.append(f'{contaGAP :.3f}')
    valores.append(f'{menorValor :.0f}')
    tempos.append(f'{menorTempo :.3f}')

primeiraMetadeNomes: list = []
primeiraMetadeTempos: list = []
primeiraMetadeCustos: list = []
primeiraMetadeGAP: list = []
for i in range(0, int((len(nomesInstancias) / 2))):
    primeiraMetadeNomes.append(nomesInstancias[i])
    primeiraMetadeTempos.append(tempos[i])
    primeiraMetadeCustos.append(valores[i])
    primeiraMetadeGAP.append(gap[i])

segundaMetadeNomes: list = []
segundaMetadeTempos: list = []
segundaMetadeCustos: list = []
segundaMetadeGAP: list = []
for i in range(int((len(nomesInstancias) / 2)), len(nomesInstancias)):
    segundaMetadeNomes.append(nomesInstancias[i])
    segundaMetadeTempos.append(tempos[i])
    segundaMetadeCustos.append(valores[i])
    segundaMetadeGAP.append(gap[i])

tabela: dict = {
               "Instância": primeiraMetadeNomes,
               "Tempo": primeiraMetadeTempos,
               "Custo": primeiraMetadeCustos,
               "GAP": primeiraMetadeGAP,
               "Instância_": segundaMetadeNomes,
               "Tempo_": segundaMetadeTempos,
               "Custo_": segundaMetadeCustos,
               "GAP_": segundaMetadeGAP
               }

df = pd.DataFrame(tabela)
latex = df.to_latex(index=False)
print(latex)