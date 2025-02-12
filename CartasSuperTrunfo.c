#include <stdio.h>

// Nivel Mestre

//Estrutura para armazenar os dados da carta
struct CartasSuperTrunfo
{
    char Estado[3];
    char CodigoDaCarta[5];
    char NomeDaCidade[60];
    long long int PIB, Populacao, area;
    float DensidadePopulacional, PIBperCapita;
    int PontosTuristicos;
};

    //Criando função para evitar repitação de codigo
    void CadastrarCarta(struct CartasSuperTrunfo*Carta, int NumeroDaCarta){

    printf("Insira os dados da carta %d \n", NumeroDaCarta);

    printf("Estado (ex: SP): ");
    scanf("%s", Carta->Estado);

    printf("Codigo da carta (ex: A01): ");
    scanf("%3s", &Carta->CodigoDaCarta);

    while (getchar() != '\n'); // limpa o buffer antes do nome da cidade

    printf("Nome da cidade (Exemplo: Sao Paulo): ");
    scanf(" %[^\n]", Carta->NomeDaCidade); //  '%[^\n]' lê espaços

    printf("População (em milhões, exemplo: 11451999): ");
    scanf(" %d", &Carta->Populacao);
   
    while (getchar() != '\n');

    printf("Área (em km², exemplo: 1521202): ");
    scanf(" %d", &Carta->area);

     while (getchar() != '\n');

    printf("PIB (em bilhões, exemplo: 828980607731): ");
    scanf("%lld", &Carta->PIB);

    while (getchar() != '\n'); 

    printf("Número de pontos turisticos: ");
    scanf("%d", &Carta->PontosTuristicos);

    // Calculos 
    Carta->DensidadePopulacional = (float) Carta->Populacao / Carta->area;
    Carta->PIBperCapita = (double) Carta->PIB / Carta->Populacao;

    }


int main(){

    struct CartasSuperTrunfo carta1, carta2; // Cria duas variaveis do tipo struct Carta

    //Chamando a função para cadastrar as duas cartas
    CadastrarCarta(&carta1, 1);
    CadastrarCarta(&carta2, 2);
    
    //Saida de dados
    printf("Carta 1 - Estado: %s | Cidade: %s | PIB: %lld | População: %lld | Área: %lld | Densidade: %.2f | PIB per Capita: %.2f\n",
           carta1.Estado, carta1.NomeDaCidade, carta1.PIB, carta1.Populacao, carta1.area, carta1.DensidadePopulacional, carta1.PIBperCapita);

    printf("Carta 2 - Estado: %s | Cidade: %s | PIB: %lld | População: %lld | Área: %lld | Densidade: %.2f | PIB per Capita: %.2f\n",
           carta2.Estado, carta2.NomeDaCidade, carta2.PIB, carta2.Populacao, carta2.area, carta2.DensidadePopulacional, carta2.PIBperCapita);

    return 0;
}