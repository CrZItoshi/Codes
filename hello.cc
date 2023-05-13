#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    char nameAnimals[25],medic[25];
    int data , medicQuant;
} animals;

typedef struct 
{
    char nameAnimals[25],medic[25];
    int data , medicQuant;
} animals;


int main(){

    int i;
    int u;
    animals animais[u];
    for(i = 0; i < u ; ++i){
    printf("Digite o nome dos animais ;");
    scanf(" %[^\n]" , &animais[i].nameAnimals);
    printf("%s\n",animais[i].nameAnimals);
    }


}

// int main(int argc, char const *argv[])
// {
// 	turma *t;
// 	int numeroDeTurmas,r;
// 	int quantidadeTurma=0,op,numeroTurma,indice;
	
// 	printf("Entre com o numero de turmas: ");
// 	scanf("%d",&numeroDeTurmas);
// 	t=(turma *)malloc(sizeof(turma)* numeroDeTurmas);
// 	if(t==NULL){
// 		printf("Erro ao alocar\n");
// 		return -1;
// 	}




