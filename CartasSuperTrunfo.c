#include <stdio.h>
#include <math.h>
#include <string.h>
#define EPSILON 0.0001 // Definição da margem de erro para comparação de Floats

// Nivel Mestre

/*O codigo vai comparar as duas cartas cadastradas pelo usuario e decidir um vencedor baseado em quem tiver a menor densidade populacional,
 caso haja empate, o vencedor vai ser a carta com maior atributo geral, que é a soma de todos os atributos.S*/

//Estrutura para armazenar os dados da carta
struct CartasSuperTrunfo
{
    char Estado[3];
    char CodigoDaCarta[5];
    char NomeDaCidade[60];
    long long int PIB, Populacao, area, atributosGerais;
    float DensidadePopulacional, PIBperCapita;
    int PontosTuristicos;
};

    //Criando função para evitar repitação de codigo
    void CadastrarCarta(struct CartasSuperTrunfo*Carta, int NumeroDaCarta){

    printf("Insira os dados da carta %d \n", NumeroDaCarta);

    printf("Estado (ex: SP): ");
    scanf("%s", Carta->Estado);

    printf("Codigo da carta (ex: A01): ");
    scanf("%3s", Carta->CodigoDaCarta);

    while (getchar() != '\n'); // limpa o buffer antes do nome da cidade

    printf("Nome da cidade (Exemplo: Sao Paulo): ");
    fgets(Carta->NomeDaCidade, sizeof(Carta->NomeDaCidade), stdin);
    Carta->NomeDaCidade[strcspn(Carta->NomeDaCidade, "\n")] = '\0'; // Remove '\n'
    
    printf("População (em milhões, exemplo: 11451999): ");
    scanf(" %lld", &Carta->Populacao);
   
    while (getchar() != '\n');

    printf("Área (em km², exemplo: 1521202): ");
    scanf(" %lld", &Carta->area);

     while (getchar() != '\n');

    printf("PIB (em bilhões, exemplo: 828980607731): ");
    scanf("%lld", &Carta->PIB);

    while (getchar() != '\n'); 

    printf("Número de pontos turisticos: ");
    scanf("%d", &Carta->PontosTuristicos);

    // Calculos 
    Carta->DensidadePopulacional = (float) Carta->Populacao / Carta->area;
    Carta->PIBperCapita = (float) Carta->PIB / Carta->Populacao;
    // Normalizando os valores para evitar que um atributo domine os outros
    Carta->atributosGerais = Carta->area + (Carta->PIB / 1000000) + (Carta->Populacao / 1000) + Carta->PontosTuristicos;

    }


int main(){

    struct CartasSuperTrunfo carta1, carta2; // Cria duas variaveis do tipo struct Carta


    //Chamando a função para cadastrar as duas cartas
    CadastrarCarta(&carta1, 1);
    printf("\n");
    CadastrarCarta(&carta2, 2);
    
    //Saida de dados
    printf(" \nPrimeiro, vence a cidade menos densamente povoada. Se houver empate, ganha a cidade com maior soma de atributos gerais. \n");

    printf("\nCarta 1: \n| Estado: %s \n| Cidade: %s \n| PIB: %lld \n| População: %lld \n| Área: %lld \n| Densidade: %.2f \n| PIB per Capita: %.2f \n| Pontos Turisticos: %d \n",
           carta1.Estado, carta1.NomeDaCidade, carta1.PIB, carta1.Populacao, carta1.area, carta1.DensidadePopulacional, carta1.PIBperCapita, carta1.PontosTuristicos);

    printf("\nCarta 2: \n| Estado: %s \n| Cidade: %s \n| PIB: %lld \n| População: %lld \n| Área: %lld \n| Densidade: %.2f \n| PIB per Capita: %.2f \n| Pontos Turisticos: %d \n",
           carta2.Estado, carta2.NomeDaCidade, carta2.PIB, carta2.Populacao, carta2.area, carta2.DensidadePopulacional, carta2.PIBperCapita, carta2.PontosTuristicos);

           // Comparação das cartas
           if (carta1.DensidadePopulacional < carta2.DensidadePopulacional) {
            printf("Vencedor: %s | Menor Densidade Populacional: %.2f \n", carta1.NomeDaCidade, carta1.DensidadePopulacional);
        } else if (carta2.DensidadePopulacional < carta1.DensidadePopulacional) {
            printf("Vencedor: %s | Menor Densidade Populacional: %.2f \n", carta2.NomeDaCidade, carta2.DensidadePopulacional);
        } else if (fabs(carta1.DensidadePopulacional - carta2.DensidadePopulacional) < EPSILON) {
            // Se for empate na densidade, usa atributos gerais como critério de desempate
            if (carta1.atributosGerais > carta2.atributosGerais) {
                printf("Vencedor: %s | Maior Atributos Gerais: %lld \n", carta1.NomeDaCidade, carta1.atributosGerais);
            } else {
                printf("Vencedor: %s | Maior Atributos Gerais: %lld \n", carta2.NomeDaCidade, carta2.atributosGerais);
            }
        }
    
        return 0;
    
}