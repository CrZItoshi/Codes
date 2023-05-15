#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char nameAnimals[25], medic[25];
    int data, medicQuant[50];
} animals;

typedef struct
{
    char name[25];
} Pessoa;

void leituraArquivo(int *argc, FILE **file, char const **argv, int *totalAnimal);
void slotAnimals(animals **animais, int *totalAnimal, int *i, FILE **file, Pessoa **User);
void slotRelatorio(FILE **relatorio ,animals **animais, int *i, Pessoa **User , int *j);

int main(int argc, char const *argv[])
{
    
    FILE *file;
    animals *animais;
    FILE *relatorio;
    Pessoa *User;
    int totalAnimal;
    int i = 0;
    int j = 0;

    
    leituraArquivo(&argc, &file, &argv[1], &totalAnimal);
    slotAnimals(&animais, &totalAnimal, &i , &file , &User);
    slotRelatorio(&relatorio ,&animais,&i,&User,&j);

    
    fclose(file);
    fclose(relatorio);
    free(animais);
    free(User);
    return 0;
}

void leituraArquivo(int *argc, FILE **file, char const **argv, int *totalAnimal)
{
    
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

    

    fscanf(*file, "%d", &*totalAnimal);
    printf("%d\n", *totalAnimal);
}

void slotAnimals(animals **animais, int *totalAnimal, int *i, FILE **file, Pessoa **User)
{
    *animais = malloc(sizeof(animals) * (*totalAnimal));
    printf("apos malloc\n");

    if (*animais == NULL)
    {
        printf("Erro de memoria\n");
        exit(0);
    }

    *User = malloc(sizeof(Pessoa) * (*totalAnimal));
    
    if (*User == NULL)
    {
        printf("Erro de memoria na pessoa\n");
        exit(0);
    }

    while (!feof(*file))
    {
        fscanf(*file, " %s", &(*animais)[*i].nameAnimals);

        fscanf(*file, " %s", &(*animais)[*i].medic);

        if (feof(*file))
        {
            break;
        }
        fscanf(*file, " %i", &(*animais)[*i].data);
        fscanf(*file, " %s", (*User)[*i].name);


        printf("Nome Animal: %s\t", (*animais)[*i].nameAnimals);
        printf("Nome Medicamento: %s \t", (*animais)[*i].medic);
        printf("Data Medicamento: %d \t", (*animais)[*i].data);
        printf("Nome da Pessoa: %s\n", (*User)[*i].name);
        printf("qnt dados na func: %d\n", *i);
        (*i)++;
    }

    printf("qnt dados: %d\n", *i);

    printf("apos funcoes \n");
}

void slotRelatorio(FILE **relatorio ,animals **animais, int *i, Pessoa **User , int *j){

    *relatorio = fopen("tabela.txt", "w");
    printf("%i\n" , *i);

    for (*j = 0; *j < *i; (*j)++)
    {
        fprintf(*relatorio, "Animal: %s\t", (*animais)[*j].nameAnimals);
        fprintf(*relatorio, "Medicamento: %s\t", (*animais)[*j].medic);
        fprintf(*relatorio, "Data: %d\t", (*animais)[*j].data);
        fprintf(*relatorio, "Pessoa: %s\n", (*User)[*j].name);
        printf("gerando relatorio..\n");
    }
}
