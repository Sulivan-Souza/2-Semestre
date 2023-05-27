#include "stdio.h"

char matriz[3][3];

void init_matriz();
void show_matriz();
void play_request(char simbolo);
int isFull();
int isSequence();


int main()
{
	system(" Jogo da Velha");

	char sim[2];
	int vez = 1;
	
	do
	{
	
		//int vez = 1;
		char simbolo;
		char nome1[21], nome2[21];
		char *c;
		int jogada = 0;
		
		printf("   =====================\n");
		printf("   ==| JOGO DA VELHA |==\n");
		printf("   =====================\n");

		printf("\n");

		printf("NOME DO JOGADOR 1: ");
		scanf("%s", nome1);

		printf("NOME DO JOGADOR 2: ");
		scanf("%s", nome2);

		system("cls"); // limpar a tela

		init_matriz();

		do
		{
			printf("\n");

			if (jogada <= 10)
			{
				system("cls");
			}
			
			show_matriz();

			printf("\n");

			if (vez)
			{
				printf("E a vez do jogador %s\n", nome1);
				simbolo = 'X';
				play_request(simbolo);
				vez = 0;
			}
			else
			{
				printf("E a vez do jogador %s\n", nome2);
				simbolo = 'O';
				play_request(simbolo);
				vez = 1;
			}


			if (isSequence())
			{
				if (vez)
				{

					system("cls");
					show_matriz();
					printf("\n");
					printf("O jogador \'%s\' ganhou!\n", nome2);
					vez = 0;
					break;
				}
				else
				{
					system("cls");
					show_matriz();
					printf("\n");
					printf("O jogador \'%s\' ganhou!\n", nome1);
					vez = 1;
					break;
				}
			}
			else if (isFull())
			{
				system("cls");
				show_matriz();
				printf("\n");
				printf("O jogo terminou empatado!\n\n");
				break;
			}

			jogada++;

		} while (1);

		printf("\nDeseja jogar novamente? s/n: ");
		scanf("%s", sim);

		printf("\n");

		system("cls");

	} while (!strcmp(sim, "s"));

	printf("voce saiu do Jogo!\n\n");

	//scanf("%d", &c);
	system("pause");

    return 0;
}



void init_matriz()
{
	int i;
	int j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			matriz[i][j] = ' ';
		}
	}
}



void show_matriz()
{
	int i;

	printf("\n");

	for (i = 0; i < 3; i++)
	{
		printf("        %c | %c | %c", matriz[i][0], matriz[i][1], matriz[i][2]);

		if (i < 2)
		{
			printf("\n       ---|---|---\n");
		}
	}

	printf("\n\n");

}



void play_request(char simbolo)
{
	int i;
	int j;
	int jogada = 0;

	printf("\n");

	
	do {
		do
		{
			printf("LINHA: ");
			scanf("%d", &i);

			if (i > 3 || i < 1)
			{
				printf("\n");
				printf("ERRO: JOGADA INVALIDA!\n");
				printf("\n");
				jogada = 0;
			}
			else
			{
				jogada = 1;
			}
		} while (jogada == 0);

		do
		{
			printf("COLUNA: ");
			scanf("%d", &j);

			if (j > 3 || j < 1)
			{
				printf("\n");
				printf("ERRO: JOGADA INVALIDA!\n");
				printf("\n");
				jogada = 0;
			}
			else
			{
				jogada = 1;
			}
		
		} while (jogada == 0);

		if (matriz[i - 1][j - 1] != ' ')
		{
			printf("\n");
			printf("ERRO: ESSA JOGADA JA FOI EFETUADA!\n");
			printf("\n");
			continue;
		}

	} while (matriz[i - 1][j - 1] != ' ');
	
	matriz[i - 1][j - 1] = simbolo;

}

int isFull()
{
	int i;
	int j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (matriz[i][j] == ' ')
			{
				return 0;
			}

		}
	}
	return 1;
}


int isSequence()
{
	// Linhas
	if (matriz[0][0] == matriz[0][1] && matriz[0][1] == matriz[0][2] && matriz[0][0] != ' ')
	{
		return 1;
	}
	if (matriz[1][0] == matriz[1][1] && matriz[1][1] == matriz[1][2] && matriz[1][0] != ' ')
	{
		return 1;
	}
	if (matriz[2][0] == matriz[2][1] && matriz[2][1] == matriz[2][2] && matriz[2][0] != ' ')
	{
		return 1;
	}
	// Colunas
	if (matriz[0][0] == matriz[1][0] && matriz[1][0] == matriz[2][0] && matriz[0][0] != ' ')
	{
		return 1;
	}
	if (matriz[0][1] == matriz[1][1] && matriz[1][1] == matriz[2][1] && matriz[0][1] != ' ')
	{
		return 1;
	}
	if (matriz[0][2] == matriz[1][2] && matriz[1][2] == matriz[2][2] && matriz[0][2] != ' ')
	{
		return 1;
	}
	// Diagonais
	if (matriz[0][0] == matriz[1][1] && matriz[1][1] == matriz[2][2] && matriz[0][0] != ' ')
	{
		return 1;
	}
	if (matriz[2][0] == matriz[1][1] && matriz[1][1] == matriz[0][2] && matriz[2][0] != ' ')
	{
		return 1;
	}
	
	return 0;

}