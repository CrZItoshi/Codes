#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char nome[50];
} Pessoa;

void calcularDespesasTotal(Pessoa pessoas[], int quantidade)
{
    double totalCarne = 0.0;
    double totalBebida = 0.0;
    double totalAluguel = 0.0;
    double totalBanda = 0.0;

    for (int i = 0; i < quantidade; i++)
    {
        totalCarne += 1.5;
        totalBebida += 2.0;
        totalAluguel += 50.0;
        totalBanda += 70.0;
    }

    printf("Despesas Totais:\n");
    printf("Carne: R$ %.2f\n", totalCarne);
    printf("Bebida: R$ %.2f\n", totalBebida);
    printf("Aluguel: R$ %.2f\n", totalAluguel);
    printf("Banda: R$ %.2f\n", totalBanda);
}

int main()
{
    FILE *arquivo;
    char nomeArquivo[100];
    
    printf("Digite o nome do arquivo: ");
    scanf("%s", nomeArquivo);

    arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    int totalPessoas;
    fscanf(arquivo, "%d", &totalPessoas);

    Pessoa *pessoas = (Pessoa *)malloc(totalPessoas * sizeof(Pessoa));

    for (int i = 0; i < totalPessoas; i++)
    {
        fscanf(arquivo, "%s", pessoas[i].nome);
    }

    fclose(arquivo);

    calcularDespesasTotal(pessoas, totalPessoas);

    free(pessoas);

  return 0;
}