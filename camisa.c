#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char name[30];
	int class;
} Allumn;

int main(int argc, const char *argv[])
{
	Allumn *student;
	int qnt;

	printf("quantidade de alunos: ");
	scanf(" %d", &qnt);
	
	student = malloc(sizeof(Allumn)* qnt);
	if(student == NULL)
		printf("error\n");

	for(int i = 0; i < qnt; i++)
	{
		printf("nome: ");
		scanf(" %[^\n]s", student[i].name);
		printf("classe: ");
		scanf(" %d", &student[i].class);
	}

	printf("Allumns created\n");

	for(int j = 0; j < qnt ; j++)
	{
		printf("Aluno: %s", student[j].name);
		printf("Turma: %d\n", student[j].class);
	}

}