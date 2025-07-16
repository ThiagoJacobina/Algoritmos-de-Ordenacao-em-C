#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define N 5 // Número de execuções para média

typedef struct {
    char nome[100];
    int idade;
} Pessoa;

typedef struct {
    long comparacoes;
    long trocas;
} Estatisticas;

void imprimirPessoas(Pessoa pessoas[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%s - %d\n", pessoas[i].nome, pessoas[i].idade);
    }
}

// ------------------------- Bubble Sort -------------------------
void bubbleSort(Pessoa arr[], int n, Estatisticas *est) {
    est->comparacoes = 0;
    est->trocas = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            est->comparacoes++;
            if (strcmp(arr[j].nome, arr[j + 1].nome) > 0) {
                Pessoa temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                est->trocas++;
            }
        }
    }
}

// ------------------------- Insertion Sort -------------------------
void insertionSort(Pessoa arr[], int n, Estatisticas *est) {
    est->comparacoes = 0;
    est->trocas = 0;
    for (int i = 1; i < n; i++) {
        Pessoa chave = arr[i];
        int j = i - 1;
        while (j >= 0 && (est->comparacoes++, strcmp(arr[j].nome, chave.nome) > 0)) {
            arr[j + 1] = arr[j];
            est->trocas++;
            j--;
        }
        arr[j + 1] = chave;
    }
}

// ------------------------- Quick Sort -------------------------
int partition(Pessoa arr[], int low, int high, Estatisticas *est);

void quickSort(Pessoa arr[], int low, int high, Estatisticas *est) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high, est);
        quickSort(arr, low, pivotIndex - 1, est);
        quickSort(arr, pivotIndex + 1, high, est);
    }
}

int partition(Pessoa arr[], int low, int high, Estatisticas *est) {
    Pessoa pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        est->comparacoes++;
        if (strcmp(arr[j].nome, pivot.nome) < 0) {
            i++;
            Pessoa temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            est->trocas++;
        }
    }
    Pessoa temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    est->trocas++;
    return i + 1;
}

// ------------------------- Funções Auxiliares -------------------------
void copiarArray(Pessoa origem[], Pessoa destino[], int n) {
    for (int i = 0; i < n; i++) {
        destino[i] = origem[i];
    }
}

void executarOrdenacao(void (*sortFunc)(Pessoa *, int, Estatisticas *), Pessoa pessoas[], int tamanho, const char *nomeAlgoritmo) {
    Pessoa copia[100];
    Estatisticas est;
    clock_t inicio, fim;
    double totalTempo = 0;

    for (int i = 0; i < N; i++) {
        copiarArray(pessoas, copia, tamanho);
        inicio = clock();
        sortFunc(copia, tamanho, &est);
        fim = clock();
        totalTempo += ((double)(fim - inicio)) / CLOCKS_PER_SEC * 1000;
    }

    printf("\n--- %s ---\n", nomeAlgoritmo);
    sortFunc(pessoas, tamanho, &est); // ordenar e imprimir resultado final
    imprimirPessoas(pessoas, tamanho);
    printf("Comparações: %ld\n", est.comparacoes);
    printf("Trocas: %ld\n", est.trocas);
    printf("Tempo médio: %.3f ms\n", totalTempo / N);
}

void executarQuickSort(Pessoa pessoas[], int tamanho) {
    Pessoa copia[100];
    Estatisticas est;
    clock_t inicio, fim;
    double totalTempo = 0;

    for (int i = 0; i < N; i++) {
        copiarArray(pessoas, copia, tamanho);
        inicio = clock();
        est.comparacoes = est.trocas = 0;
        quickSort(copia, 0, tamanho - 1, &est);
        fim = clock();
        totalTempo += ((double)(fim - inicio)) / CLOCKS_PER_SEC * 1000;
    }

    printf("\n--- Quick Sort ---\n");
    quickSort(pessoas, 0, tamanho - 1, &est);
    imprimirPessoas(pessoas, tamanho);
    printf("Comparações: %ld\n", est.comparacoes);
    printf("Trocas: %ld\n", est.trocas);
    printf("Tempo médio: %.3f ms\n", totalTempo / N);
}

// ------------------------- Main -------------------------
int main() {
    Pessoa pessoas[] = {
        {"Carlos", 30}, {"Ana", 25}, {"João", 40}, {"Bruna", 28}, {"Eduardo", 22},
        {"Gabriela", 35}, {"Fernando", 33}, {"Daniela", 29}, {"Helena", 31}, {"Marcos", 26},
        {"Patrícia", 38}, {"Ricardo", 41}, {"Larissa", 27}, {"Vinícius", 23}, {"Beatriz", 24},
        {"Otávio", 36}, {"Juliana", 34}, {"Felipe", 39}, {"Camila", 32}, {"Leandro", 37},
        {"Tatiane", 21}, {"Bruno", 45}, {"Natália", 20}, {"André", 42}, {"Isabela", 44},
        {"Rafael", 43}, {"Luciana", 26}, {"Thiago", 28}, {"Melissa", 30}, {"Caio", 31},
        {"Paula", 33}, {"Rodrigo", 27}, {"Simone", 34}, {"Alex", 29}, {"Verônica", 36},
        {"Gustavo", 38}, {"Luana", 40}, {"Henrique", 35}, {"Alice", 25}, {"Samuel", 32},
        {"Roberta", 31}, {"Murilo", 28}, {"Letícia", 29}, {"Márcio", 34}, {"Tatiana", 22},
        {"César", 30}, {"Elen", 33}, {"Jonas", 37}, {"Cristina", 36}, {"Douglas", 39},
        {"Vera", 21}, {"Brenda", 23}, {"Wagner", 41}, {"Sandra", 24}, {"Igor", 27},
        {"Mirela", 26}, {"Nathan", 42}, {"Tânia", 43}, {"Breno", 20}, {"Alessandra", 38},
        {"Renato", 44}, {"Celina", 45}, {"Danilo", 35}, {"Eliane", 34}, {"Sérgio", 36},
        {"Fátima", 33}, {"Júlio", 29}, {"Rebeca", 25}, {"Hugo", 31}, {"Elaine", 32},
        {"Davi", 30}, {"Raquel", 28}, {"Otávia", 22}, {"Vicente", 27}, {"Aline", 26},
        {"Pablo", 39}, {"Clarice", 24}, {"Mateus", 23}, {"Nicole", 21}, {"Alan", 40},
        {"Yasmin", 34}, {"Hélio", 32}, {"Monique", 33}, {"Irene", 36}, {"Cael", 37},
        {"Silvia", 35}, {"Pedro", 41}, {"Rita", 44}, {"Diego", 43}, {"Kelly", 20},
        {"Luan", 42}, {"Noemi", 45}, {"Enzo", 26}, {"Amanda", 25}, {"Érica", 22},
        {"Nicolas", 24}, {"Lorena", 23}, {"Heloísa", 30}, {"Otto", 29}, {"Mário", 38}
    };

    int tamanho = sizeof(pessoas) / sizeof(pessoas[0]);

    Pessoa backup[100];
    copiarArray(pessoas, backup, tamanho);

    executarOrdenacao(bubbleSort, pessoas, tamanho, "Bubble Sort");
    copiarArray(backup, pessoas, tamanho);

    executarOrdenacao(insertionSort, pessoas, tamanho, "Insertion Sort");
    copiarArray(backup, pessoas, tamanho);

    executarQuickSort(pessoas, tamanho);

    return 0;
}
