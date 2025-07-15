# Ordenação de Pessoas por Nome

Este projeto implementa três algoritmos de ordenação clássicos em linguagem C para organizar uma lista de 100 pessoas por nome. Além disso, ele coleta estatísticas como o número de comparações, trocas e o tempo médio de execução de cada algoritmo.

---

## 📌 Algoritmos Utilizados

### 1. Bubble Sort

Bubble Sort compara elementos adjacentes e os troca de posição se estiverem fora de ordem. Esse processo é repetido até que todo o vetor esteja ordenado.

- **Vantagens**: Simples de entender e implementar.
- **Desvantagens**: Muito ineficiente para listas grandes.

### 2. Insertion Sort

O Insertion Sort constrói a lista ordenada uma posição por vez, inserindo cada novo elemento na posição correta em relação aos já ordenados.

- **Vantagens**: Muito eficiente para listas pequenas ou quase ordenadas.
- **Desvantagens**: Desempenho ruim com listas grandes desordenadas.

### 3. Quick Sort

Quick Sort é um algoritmo eficiente de divisão e conquista. Ele seleciona um pivô e particiona os elementos em torno dele, aplicando o processo recursivamente.

- **Vantagens**: Muito rápido na prática com grandes volumes de dados.
- **Desvantagens**: Pode ter desempenho ruim em casos degenerados (quando o pivô é mal escolhido).

---

## ⏱️ Complexidade dos Algoritmos

| Algoritmo      | Melhor Caso | Médio Caso  | Pior Caso   | Espaço Auxiliar |
|----------------|-------------|-------------|-------------|------------------|
| Bubble Sort    | O(n)        | O(n²)       | O(n²)       | O(1)             |
| Insertion Sort | O(n)        | O(n²)       | O(n²)       | O(1)             |
| Quick Sort     | O(n log n)  | O(n log n)  | O(n²)       | O(log n)         |

---

## 📊 Resultados Obtidos

Os testes foram realizados com uma lista de 100 pessoas, repetidos 5 vezes para calcular o tempo médio de execução.

| Algoritmo      | Comparações | Trocas | Tempo Médio (ms) |
|----------------|-------------|--------|------------------|
| Bubble Sort    | 4950        | 2274   | 0.065            |
| Insertion Sort | 2369        | 2274   | 0.025            |
| Quick Sort     | 1204        | 866    | 0.011            |

