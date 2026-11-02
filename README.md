# Atividade Avaliativa 03 — Ordenação e Arquivos em C

## Atendimento aos 5 requisitos da Atividade

### 1. Criar e salvar um arquivo com dados numéricos desordenados
O programa cria o arquivo `dados.txt` e grava valores numéricos inicialmente desordenados.

### 2. Ler os dados do arquivo
O programa utiliza `fopen` no modo leitura (`"r"`) e `fscanf` para ler os valores de `dados.txt`.

### 3. Permitir escolher o tipo de ordenação
O programa permite escolher entre:
- Bubble Sort
- Insertion Sort
- Selection Sort
- Merge Sort
- Quick Sort

### 4. Ordenar os dados e salvar o resultado em um novo arquivo
Depois da ordenação, o resultado é salvo no arquivo `ordenado.txt`.

### 5. Permitir alterar um valor dentro do arquivo e ordenar novamente
O programa permite escolher uma posição, informar um novo valor e atualizar o próprio `dados.txt`. Depois, os dados são lidos novamente, um algoritmo de ordenação é escolhido e o novo resultado é salvo em `ordenado.txt`.

## Arquivos da entrega

- `main.c` — código-fonte completo.
- `dados.txt` — arquivo com os dados originais/desordenados.
- `ordenado.txt` — exemplo do arquivo com os dados ordenados.
- `README.md` — documentação e relação dos requisitos.
- `log_execucao.txt` — exemplo de execução.

## Compilação

### GCC
```bash
gcc main.c -o ordenacao
```

### Windows
```bash
gcc main.c -o ordenacao.exe
```

### Execução
```bash
./ordenacao
```

No Windows:
```bash
ordenacao.exe
```
