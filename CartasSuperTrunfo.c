#include <stdio.h>

// Nivel Iniciante

int main(){

    //Declaração das variaveis
    char Estado[3], CodigoDaCarta[4], NomeDaCidade[50];
    int PontosTuristicos, PIB, Populacao, area;

    //Entrada de dados
    printf("Insira os dados da carta\n");
    printf("Estado (ex: SP): ");
    scanf("%s", &Estado);

    printf("Codigo da carta (ex: A01): ");
    scanf("%3s", &CodigoDaCarta);

    while (getchar() != '\n'); // limpa o buffer antes do nome da cidade

    printf("Nome da cidade (Exemplo: Sao Paulo): ");
    scanf(" %[^\n]", &NomeDaCidade); //  '%[^\n]' lê espaços

    printf("População (em milhões, exemplo: 11451999 milhões): ");
    scanf(" %d", &Populacao);
   
    while (getchar() != '\n');

    printf("Área (em km², exemplo: 1521202 milhões): ");
    scanf(" %d", &area);

     while (getchar() != '\n');

    printf("PIB (em bilhões, exemplo: 828 bilhões): ");
    scanf("%d", &PIB);

    while (getchar() != '\n'); 

    printf("Número de pontos turisticos: ");
    scanf("%d", &PontosTuristicos);

    //Saida de dados
    printf("\n");
    printf("Resultados: \n");
    printf("Estado: %s \n", Estado);
    printf("Codigo da carta: %s \n", CodigoDaCarta);
    printf("Nome da Cidade: %s \n", NomeDaCidade);
    printf("População: %d milhões \n", Populacao);
    printf("Área: %d km² \n", area);
    printf("PIB: %d bilhões \n", PIB);
    printf("Numero de pontos turisticos: %d \n", PontosTuristicos);

    return 0;
}