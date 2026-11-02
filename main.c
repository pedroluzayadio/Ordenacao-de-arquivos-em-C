#include <stdio.h>

#define MAX 100

void bubbleSort(int v[], int n) {
    int i, j, temp;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (v[j] > v[j + 1]) {
                temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }
}

void insertionSort(int v[], int n) {
    int i, j, chave;

    for (i = 1; i < n; i++) {
        chave = v[i];
        j = i - 1;

        while (j >= 0 && v[j] > chave) {
            v[j + 1] = v[j];
            j--;
        }

        v[j + 1] = chave;
    }
}

void selectionSort(int v[], int n) {
    int i, j, menor, temp;

    for (i = 0; i < n - 1; i++) {
        menor = i;

        for (j = i + 1; j < n; j++) {
            if (v[j] < v[menor]) {
                menor = j;
            }
        }

        temp = v[i];
        v[i] = v[menor];
        v[menor] = temp;
    }
}

void merge(int v[], int inicio, int meio, int fim) {
    int i = inicio;
    int j = meio + 1;
    int k = 0;
    int temp[MAX];

    while (i <= meio && j <= fim) {
        if (v[i] <= v[j]) {
            temp[k] = v[i];
            i++;
        } else {
            temp[k] = v[j];
            j++;
        }
        k++;
    }

    while (i <= meio) {
        temp[k] = v[i];
        i++;
        k++;
    }

    while (j <= fim) {
        temp[k] = v[j];
        j++;
        k++;
    }

    for (i = inicio, k = 0; i <= fim; i++, k++) {
        v[i] = temp[k];
    }
}

void mergeSort(int v[], int inicio, int fim) {
    int meio;

    if (inicio < fim) {
        meio = (inicio + fim) / 2;

        mergeSort(v, inicio, meio);
        mergeSort(v, meio + 1, fim);
        merge(v, inicio, meio, fim);
    }
}

int particionar(int v[], int inicio, int fim) {
    int pivo = v[fim];
    int i = inicio - 1;
    int j;
    int temp;

    for (j = inicio; j < fim; j++) {
        if (v[j] <= pivo) {
            i++;

            temp = v[i];
            v[i] = v[j];
            v[j] = temp;
        }
    }

    temp = v[i + 1];
    v[i + 1] = v[fim];
    v[fim] = temp;

    return i + 1;
}

void quickSort(int v[], int inicio, int fim) {
    int posicaoPivo;

    if (inicio < fim) {
        posicaoPivo = particionar(v, inicio, fim);

        quickSort(v, inicio, posicaoPivo - 1);
        quickSort(v, posicaoPivo + 1, fim);
    }
}

/* 1 - Criar e salvar arquivo com dados numericos desordenados */
void criarArquivoDados() {
    FILE *arquivo;
    int numeros[] = {45, 12, 78, 3, 56, 21, 90, 7, 34, 18};
    int quantidade = sizeof(numeros) / sizeof(numeros[0]);
    int i;

    arquivo = fopen("dados.txt", "w");

    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo dados.txt!\n");
        return;
    }

    for (i = 0; i < quantidade; i++) {
        fprintf(arquivo, "%d ", numeros[i]);
    }

    fclose(arquivo);

    printf("Arquivo dados.txt criado com sucesso!\n");
}

/* 2 - Ler os dados do arquivo */
int lerArquivo(int numeros[]) {
    FILE *arquivo;
    int quantidade = 0;

    arquivo = fopen("dados.txt", "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo dados.txt!\n");
        return 0;
    }

    while (quantidade < MAX &&
           fscanf(arquivo, "%d", &numeros[quantidade]) == 1) {
        quantidade++;
    }

    fclose(arquivo);

    return quantidade;
}

/* Salvar dados no arquivo */
void salvarArquivo(char nomeArquivo[], int numeros[], int quantidade) {
    FILE *arquivo;
    int i;

    arquivo = fopen(nomeArquivo, "w");

    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo %s!\n", nomeArquivo);
        return;
    }

    for (i = 0; i < quantidade; i++) {
        fprintf(arquivo, "%d ", numeros[i]);
    }

    fclose(arquivo);
}

/* 3 - Escolher e executar um algoritmo de ordenacao */
int escolherOrdenacao(int numeros[], int quantidade) {
    int opcao;

    printf("\n===== ESCOLHA O ALGORITMO =====\n");
    printf("1 - Bubble Sort\n");
    printf("2 - Insertion Sort\n");
    printf("3 - Selection Sort\n");
    printf("4 - Merge Sort\n");
    printf("5 - Quick Sort\n");
    printf("Escolha: ");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            bubbleSort(numeros, quantidade);
            printf("Bubble Sort executado!\n");
            break;

        case 2:
            insertionSort(numeros, quantidade);
            printf("Insertion Sort executado!\n");
            break;

        case 3:
            selectionSort(numeros, quantidade);
            printf("Selection Sort executado!\n");
            break;

        case 4:
            mergeSort(numeros, 0, quantidade - 1);
            printf("Merge Sort executado!\n");
            break;

        case 5:
            quickSort(numeros, 0, quantidade - 1);
            printf("Quick Sort executado!\n");
            break;

        default:
            printf("Opcao invalida!\n");
            return 0;
    }

    return 1;
}

void mostrarNumeros(int numeros[], int quantidade) {
    int i;

    for (i = 0; i < quantidade; i++) {
        printf("%d ", numeros[i]);
    }

    printf("\n");
}

/* 5 - Alterar um valor DENTRO do arquivo e depois reordenar */
int alterarValorNoArquivo(int numeros[], int quantidade) {
    FILE *arquivo;
    int posicao;
    int novoValor;
    int i;

    printf("\n===== ALTERAR VALOR NO ARQUIVO =====\n");
    printf("Dados atuais do arquivo dados.txt:\n");
    mostrarNumeros(numeros, quantidade);

    printf("Informe a posicao que deseja alterar (1 a %d): ", quantidade);
    scanf("%d", &posicao);

    if (posicao < 1 || posicao > quantidade) {
        printf("Posicao invalida!\n");
        return 0;
    }

    printf("Valor atual: %d\n", numeros[posicao - 1]);
    printf("Informe o novo valor: ");
    scanf("%d", &novoValor);

    numeros[posicao - 1] = novoValor;

    arquivo = fopen("dados.txt", "w");

    if (arquivo == NULL) {
        printf("Erro ao atualizar dados.txt!\n");
        return 0;
    }

    for (i = 0; i < quantidade; i++) {
        fprintf(arquivo, "%d ", numeros[i]);
    }

    fclose(arquivo);

    printf("Valor alterado e salvo novamente em dados.txt!\n");

    return 1;
}

int main() {
    FILE *arquivo;
    int numeros[MAX];
    int quantidade;
    int opcao;
    int i;

    /* 1 - Criacao do arquivo */
    criarArquivoDados();

    /* 2 - Leitura do arquivo */
    quantidade = lerArquivo(numeros);

    if (quantidade == 0) {
        printf("Nenhum dado encontrado no arquivo.\n");
        return 1;
    }

    printf("\n===== DADOS ORIGINAIS =====\n");
    mostrarNumeros(numeros, quantidade);

    do {
        printf("\n===== MENU PRINCIPAL =====\n");
        printf("1 - Ler e mostrar dados do arquivo\n");
        printf("2 - Ordenar dados e salvar em ordenado.txt\n");
        printf("3 - Alterar valor no arquivo e reordenar\n");
        printf("4 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                quantidade = lerArquivo(numeros);

                if (quantidade > 0) {
                    printf("\nDados lidos de dados.txt:\n");
                    mostrarNumeros(numeros, quantidade);
                }
                break;

            case 2:
                quantidade = lerArquivo(numeros);

                if (quantidade == 0) {
                    printf("Nao foi possivel ler os dados.\n");
                    break;
                }

                if (escolherOrdenacao(numeros, quantidade)) {
                    /* 4 - Salvar resultado em novo arquivo */
                    salvarArquivo("ordenado.txt", numeros, quantidade);

                    printf("\nDados ordenados:\n");
                    mostrarNumeros(numeros, quantidade);
                    printf("Resultado salvo em ordenado.txt!\n");
                }
                break;

            case 3:
                quantidade = lerArquivo(numeros);

                if (quantidade == 0) {
                    printf("Nao foi possivel ler os dados.\n");
                    break;
                }

                /* 5 - Alterar valor dentro do arquivo */
                if (alterarValorNoArquivo(numeros, quantidade)) {
                    /* Ler novamente para garantir que o programa usa
                       exatamente os dados atualizados do arquivo. */
                    quantidade = lerArquivo(numeros);

                    printf("\nDados atualizados em dados.txt:\n");
                    mostrarNumeros(numeros, quantidade);

                    printf("\nAgora escolha o algoritmo para reordenar:\n");

                    if (escolherOrdenacao(numeros, quantidade)) {
                        salvarArquivo("ordenado.txt", numeros, quantidade);

                        printf("\nDados depois da alteracao e nova ordenacao:\n");
                        mostrarNumeros(numeros, quantidade);
                        printf("Novo resultado salvo em ordenado.txt!\n");
                    }
                }
                break;

            case 4:
                printf("\nPrograma encerrado.\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }

    } while (opcao != 4);

    /* Apenas para evitar aviso de compiladores sobre variavel nao usada. */
    arquivo = NULL;
    (void)arquivo;
    (void)i;

    return 0;
}
