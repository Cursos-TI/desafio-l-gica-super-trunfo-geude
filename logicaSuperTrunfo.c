#include <stdio.h>

//Estrutura para armazenar dados das cartas
typedef struct {

    int codigo_cidade, pontos_turisticos;         //Código da cidade (A01, B02, etc...).
    char nome_cidade[50];
    float populacao, PIB, area, densidade_populacional, pib_per_capta, super_poder;    //Aréa territórial, produto interno bruto e população da cidade.

} carta;
   //Função para calcular densidade populacional "Super poder"

void calcular_super_poder(carta *carta) {
    carta->densidade_populacional = carta->populacao / carta->area;
    carta->super_poder = carta->populacao + carta->PIB + carta->area + carta->pontos_turisticos;
}

//Função para cadastrar os dados de uma carta
void cadastrar_carta(carta *carta) {
    printf("Digite o código da cidade: ");
    scanf("%d", &carta->codigo_cidade);

    printf("Digite o nome da cidade: ");
    scanf("%30s", &carta->nome_cidade);

    printf("Digite a população da cidade: ");
    scanf("%f", &carta->populacao);

    printf("Digite a quantidade de pontos turísticos: ");
    scanf("%d", &carta->pontos_turisticos);

    printf("Digite o PIB da cidade: ");
    scanf("%f", &carta->PIB);

    printf("Digite a área territórial da cidade: ");
    scanf("%f", &carta->area);

    calcular_super_poder(carta);
}
// Função para comparar duas cartas
void comparar_cartas(carta carta1, carta carta2) {
    printf("\nResultado da Comparação:\n");

    // Comparação de Densidade Populacional (menor valor vence)
    if (carta1.densidade_populacional < carta2.densidade_populacional) {
        printf("Densidade Populacional: %s vence!\n", carta1.nome_cidade);
    } else if (carta1.densidade_populacional > carta2.densidade_populacional) {
        printf("Densidade Populacional: %s vence!\n", carta2.nome_cidade);
    } else {
        printf("Densidade Populacional: Empate!\n");
    }

    // Comparação do Super Poder (maior valor vence)
    if (carta1.super_poder > carta2.super_poder) {
        printf("Super Poder: %s vence!\n", carta1.nome_cidade);
    } else if (carta1.super_poder < carta2.super_poder) {
        printf("Super Poder: %s vence!\n", carta2.nome_cidade);
    } else {
        printf("Super Poder: Empate!\n");
    }
}

// Função para exibir os dados de uma carta
void exibir_carta(carta carta) {
    printf("\nDados da carta:\n");
    printf("Código: %d\n", carta.codigo_cidade);
    printf("Nome: %s\n", carta.nome_cidade);
    printf("População: %.2f\n", carta.populacao);
    printf("Pontos turísticos: %d\n", carta.pontos_turisticos);
    printf("PIB: %.2f\n", carta.PIB);
    printf("Área: %.2f km²\n", carta.area);
    printf("Densidade Populacional: %.6f habitantes/km²\n", carta.densidade_populacional);
    printf("Super Poder: %.2f\n", carta.super_poder);
}

int main() {
    carta carta1, carta2;

    // Cadastra os dados das duas cartas
    printf("Cadastro da primeira carta:\n");
    cadastrar_carta(&carta1);

    printf("\nCadastro da segunda carta:\n");
    cadastrar_carta(&carta2);

    // Exibe os dados das cartas
    exibir_carta(carta1);
    exibir_carta(carta2);

    // Realiza a comparação entre as cartas
    comparar_cartas(carta1, carta2);

    return 0;
}