#include <stdio.h>
#include <string.h>

typedef struct
{
    char nume[20], prenume[20], oras[20], liceu[50], hobbyuri[20][20];

} STUDENT;

void afisare(char s[], char indicator[])
{
    printf("%s: %s\n", indicator, s);
}

void afisare_vectori(char a[20][20], int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("Hobby %d: %s\n", i+1, a[i]);
    }
}

void ordonare(char a[20][20], int n)
{
    int i, j;
    char aux[20];

    for(i = 0; i < n; i++)
        for(j = i+1; j < n; j++)
        {
            if(strcmp(a[i], a[j]) > 0)
            {
                strcpy(aux, a[i]);
                strcpy(a[i], a[j]);
                strcpy(a[j], aux);
            }
        }
}

int main()
{

    STUDENT student;
    int nr_hobby, i;

    printf("Introduceti datele studentului:\n");
    printf("Nume: ");
    gets(student.nume);
    printf("Prenume: ");
    gets(student.prenume);
    printf("Oras: ");
    gets(student.oras);
    printf("Liceu: ");
    gets(student.liceu);

    printf("Introduceti numarul de hobbyuri: ");
    scanf("%d", &nr_hobby);
    printf("Introduceti hobbyurile unul cate unul:\n");
    fflush(stdin);

    for(i = 0; i < nr_hobby; i++)
    {
        gets(student.hobbyuri[i]);
    }
    printf("\n");

    ordonare(student.hobbyuri, nr_hobby);

    afisare(student.nume, "Nume");
    afisare(student.prenume, "Prenume");
    afisare(student.oras, "Oras");
    afisare(student.liceu, "Liceu");
    afisare_vectori(student.hobbyuri, nr_hobby);

}
