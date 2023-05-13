#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char nameAnimals[25], medic[25];
    int data , medicQuant[50];
    
} animals;

typedef struct
{
    char name[25];
} Pessoa;

int main(int argc, char const *argv[])
{
    // localizando e recebendo o arquivo por parâmetros do terminal
    if (argc < 2)
    {

        printf("Erro ao encontrar o arquivo\n");
    }
    printf("Sucesso ao encontrar o arquivo\n");
    printf("Sucesso ao abrir o arquivo\n");

    // Guardando todo o arquivo em file
    FILE *file;
    file = fopen(argv[1], "r");
    if (file == NULL)
    {

        printf("Erro ao encontrar ao abrir arquivo\n");
        return -1;
    }

    // lendo a primeira linha.
    int totalAnimal;
    fscanf(file, "%d", &totalAnimal);
    printf("%d\n", totalAnimal);

    animals *animais;

    animais = malloc(sizeof(animals) * totalAnimal);
    printf("apos malloc\n");

    if (animais == NULL)
    {
        printf("Erro de memoria\n");
        return -1;
    }

    Pessoa *User;
    User = malloc(sizeof(Pessoa) * totalAnimal);
    if (User == NULL)
    {
        printf("Erro de memoria na pessoa\n");
        return -1;
    }

    int i = 0;
    
    while (!feof(file))
    {
        fscanf(file, " %s", &animais[i].nameAnimals);

        fscanf(file, " %s", &animais[i].medic);

        if (feof(file))
        {
            break;
        }
        fscanf(file, " %d", &animais[i].data);
        fscanf(file, "%s", User[i].name);

        printf("Nome Animal: %s\t", animais[i].nameAnimals);
        printf("Nome Medicamento: %s \t", animais[i].medic);
        printf("Data Medicamento: %d \t", animais[i].data);
        printf("Nome da Pessoa: %s\n", User[i].name);

        i++;
    }
    printf("qnt daddos: %d\n", i);

    printf("apos funcoes \n");

    FILE *relatorio;
    relatorio = fopen("tabela.txt" , "w");

    int j = 0;
    
    for ( j = 0; j < i; j++)
    {
        printf("gerando relatorio..");
        fprintf(relatorio, "Animal: %s\t", &animais[j].nameAnimals);
        fprintf(relatorio, "Medicamento: %s\t", &animais[j].medic);
        fprintf(relatorio, "Data: %d\t", &animais[j].data);
        fprintf(relatorio, "Pessoa: %s\n", &User[j].name);
    }
    
    fclose(file);
    fclose(relatorio);
    free(animais);
    free(User);
    return 0;
}
