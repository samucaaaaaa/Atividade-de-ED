# Atividade-de-ED
Nesta atividade, foram implementados e comparados os tempos de execução de diferentes algoritmos de ordenação em uma lista encadeada. O objetivo principal foi avaliar o desempenho relativo de cada algoritmo ao ordenar uma lista de 30.000 elementos aleatórios.

Os algoritmos de ordenação testados foram os seguintes:

* Bubble Sort: Um algoritmo de ordenação simples que percorre repetidamente a lista, comparando elementos adjacentes e os trocando se estiverem na ordem errada.
* Bubble Sort Otimizado: Uma versão otimizada do Bubble Sort que verifica se ocorreu alguma troca durante uma passagem completa pela lista. Se nenhuma troca ocorrer, o algoritmo interrompe a execução, pois a lista já está ordenada.
* Selection Sort: Um algoritmo que divide a lista em duas partes: uma parte ordenada e outra não ordenada. Ele encontra repetidamente o menor elemento da parte não ordenada e o coloca no final da parte ordenada.
* Selection Sort Otimizado: Uma versão otimizada do Selection Sort que encontra tanto o menor quanto o maior elemento da parte não ordenada durante cada iteração, reduzindo o número de iterações necessárias pela metade.
