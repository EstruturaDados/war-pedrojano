#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Global variables
#define MAX_TERRITORIES 5
#define MAX_STRING_NAMES 30
#define MAX_STRING_COLORS 10

// Structure to represent a territory
struct Territory
{
    char name[MAX_STRING_NAMES];
    char color[MAX_STRING_COLORS];
    int troops;
};

// Function to clean buffer input
void cleanBuf()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
};

// Main Function
int main()
{
    struct Territory territories[MAX_TERRITORIES];
    int totalTerritories = 0;

    // Registration loop
    printf("\n\n==================================\n\n");
    printf("Vamos cadastrar os 5 territorios iniciais do nosso mundo\n");
    do
    {
        //Registering the Territory
        printf("\n\n--- Cadastrando Territorio %d ---", totalTerritories + 1);
        printf("\nNome do Territorio: ");
        fgets(territories[totalTerritories].name, MAX_STRING_NAMES, stdin);
        territories[totalTerritories].name[strcspn(territories[totalTerritories].name, "\n")] = 0;

        // Army color
        printf("Cor do Exercito (ex: Azul, Verde): ");
        fgets(territories[totalTerritories].color, MAX_STRING_COLORS, stdin);
        territories[totalTerritories].color[strcspn(territories[totalTerritories].color, "\n")] = 0;

        // Number of troops
        printf("Numeros de Tropas: ");
        scanf("%d", &territories[totalTerritories].troops);
        cleanBuf();

        totalTerritories++;

        switch (totalTerritories)
        {
        case MAX_TERRITORIES:
            printf("\n==================================");
            printf("\n    MAPA DO MUNDO - ESTADO ATUAL\n");
            printf("==================================\n\n");

            // Returns list of territories, color of armies and number of troops
            for (int i = 0; i < totalTerritories; i++)
            {
                printf("Territorio %d:\n", i + 1);
                printf("Nome: %s\n", territories[i].name);
                printf("Dominado por: Exercito %s\n", territories[i].color);
                printf("Tropas: %d\n", territories[i].troops);
                printf("-------------------------\n");
            }
            break;
        }

    } while (totalTerritories < MAX_TERRITORIES);

    printf("\nTerritorios cadastrados com sucesso!\n");
    return 0;
};
