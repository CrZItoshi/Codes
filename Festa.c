#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char name[25];
    float carne, bebida;
    float aluguel, banda;
} Pessoas;

void slotArquivo(int *argc, char const **argv , FILE **file , int *totalPessoas);
void slotUsuario(Pessoas **usuario , int *totalPessoas, FILE **file , int *i);
void slotCalc(int *j , int *i , Pessoas **usuario, float const *carne , float const *bebida , float const *banda , float const *aluguel ,float *totalCarne , float *totalBebida , float *totalBanda , float *totalAluguel);
void slotRelatorio(FILE **relatorio , int *j , int *i , Pessoas **usuario , float *totalCarne , float *totalBebida , float *totalBanda , float *totalAluguel);

int main(int argc, char const *argv[])
{
    
    FILE *file;
    FILE *relatorio;
    int totalPessoas;
    Pessoas *usuario;

    int i = 0;
    int j = 0;

    float const carne = 1.5, bebida = 2.0, banda = 50.00, aluguel = 70.00;
    float totalCarne = 0, totalBebida = 0, totalAluguel = 0, totalBanda = 0;

    slotArquivo(&argc , &argv[1] , &file , &totalPessoas);
    slotUsuario(&usuario , &totalPessoas, &file , &i);
    slotCalc(&j , &i , &usuario, &carne , &bebida , &banda , &aluguel , &totalCarne , &totalBebida , &totalBanda , &totalAluguel);
    slotRelatorio(&relatorio , &j , &i , &usuario , &totalCarne , &totalBebida , &totalBanda , &totalAluguel);
    
    free(usuario);
    fclose(file);
    return 0;
}

void slotArquivo(int *argc, char const **argv , FILE **file , int *totalPessoas ){
    if (*argc < 2)
    {
        printf("Erro ao encontrar o arquivo\n");
    }
        printf("Sucesso ao encontrar o arquivo\n");
        printf("Sucesso ao abrir o arquivo\n");

    *file = fopen(*argv, "r");
    if (*file == NULL)
    {
        printf("Erro ao encontrar ao abrir arquivo\n");
    }

    fscanf(*file, "%d", &(*totalPessoas));
    printf("%d\n", (*totalPessoas));
}


void slotUsuario(Pessoas **usuario , int *totalPessoas, FILE **file , int *i)
{
    
    *usuario = malloc(sizeof(Pessoas) * (*totalPessoas));
    if (*usuario == NULL)
    {
        printf("Erro ao alocar memoria ao usuario\n");
    }

     
    while (!feof(*file))
    {
        fscanf(*file, "%s", (*usuario)[*i].name);

        if (feof(*file))
        {
            break;
        }

        printf("--%s\n" , (*usuario)[*i].name );
        (*i)++;
    }
}

void slotCalc(int *j , int *i , Pessoas **usuario, float const *carne , float const *bebida , float const *banda , float const *aluguel ,float *totalCarne , float *totalBebida , float *totalBanda , float *totalAluguel)
{
    for (*j = 0; *j < *i; (*j)++)
    {
        (*usuario)[*j].carne = (*carne);
        (*usuario)[*j].bebida = (*bebida);
        (*usuario)[*j].banda = (*banda);
        (*usuario)[*j].aluguel = (*aluguel);

        (*totalCarne) += (*carne);
        (*totalBebida) += (*bebida);
        (*totalBanda) += (*banda);
        (*totalAluguel) += (*aluguel);

        printf("Nome: %s ", (*usuario)[*j].name);
        printf("Carne: %.2fkg ", (*usuario)[*j].carne);
        printf("Bebida: %.2fl ", (*usuario)[*j].bebida);
        printf("Banda: %.2f ", (*usuario)[*j].banda);
        printf("Aluguel: %.2f \n", (*usuario)[*j].aluguel);
    }
    
    printf("Total Carne: %.2fkg ", (*totalCarne));
    printf("Total Bebida: %.2fl ", (*totalBebida));
    printf("Total Banda: %.2f ", (*totalBanda));
    printf("Total Aluguel: %.2f \n", (*totalAluguel));
}
void slotRelatorio(FILE **relatorio , int *j , int *i , Pessoas **usuario , float *totalCarne , float *totalBebida , float *totalBanda , float *totalAluguel)
{
    *relatorio = fopen("relatorio.txt", "w");
    // printf("%i\n" , i);

    for (*j = 0; *j < *i; *j++)
    {
        fprintf(*relatorio, "Nome: %s ", (*usuario)[*j].name);
        fprintf(*relatorio, "Carne: %.2fkg ", (*usuario)[*j].carne);
        fprintf(*relatorio, "Bebida: %.2fl ", (*usuario)[*j].bebida);
        fprintf(*relatorio,"Banda: %.2f ", (*usuario)[*j].banda);
        fprintf(*relatorio, "Aluguel: %.2f \n", (*usuario)[*j].aluguel);
    }
        fprintf(*relatorio, "Total Carne: %.2fkg ", (*totalCarne));
        fprintf(*relatorio, "Total Bebida: %.2fl ",(*totalBebida));
        fprintf(*relatorio, "Total Banda: %.2f ",(*totalBanda));
        fprintf(*relatorio, "Total Aluguel: %.2f \n", (*totalAluguel));
}
