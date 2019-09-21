#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdint.h>

int menu();
int arquivo();
int sair();

int testaARQUIVO(char *pnome, char *pnome_normal);
int infoARQUIVO(char *pnome, char *pnome_normal, FILE *ronaldo);

char *pnome, *pnome_normal;


int main()
{
    setlocale(LC_ALL, "");

    menu();
}

int menu(FILE *meuovo)
{
    int opcaoMENU;

    system("cls");

    printf("------MENU------");
    printf("\n\n1. Abrir o arquivo");
    printf("\n\n2. Exibir informações do arquivo");
    printf("\n\n3. Filtrar audio");
    printf("\n\n4. Recortar o arquivo");
    printf("\n\n0. Fechar programa");

    printf("\n\nSelecione uma opção: ");
    scanf("%d", &opcaoMENU);


    switch(opcaoMENU)
    {
        case 0: sair();
        break;
        case 1: arquivo();
        break;
        case 2: infoARQUIVO(pnome, pnome_normal, meuovo);
        break;
    }
}

int arquivo()
{
    char nome[100];
    char nome_normal[100];

    //char *pnome;
    //char *pnome_normal;

    printf("\nNome do arquivo no formato WAV: ");
    scanf("%s", nome);

    strcpy(nome_normal, nome); //COPIA O NOME NORMAL DO ARQUIVO, SEM O .WAV
	strcat(nome, ".wav");    //CONCATENA O NOME DO ARQUIVO COM O .WAV

	pnome = nome; //PONTEIRO PARA NOME COM .WAV
	pnome_normal = nome_normal; //PONTEIRO PARA NOME SEM .WAV

    testaARQUIVO(pnome, pnome_normal);
}

int testaARQUIVO(char *pnome, char *pnome_normal)
{

    FILE *fp;

    fp = fopen(pnome, "rb");

    if(fp == NULL)
    {
        printf("\n\nO arquivo %s não existe ou não possui formato .WAV\n\n", pnome);
        fclose(fp);
        system("pause");

        menu(fp);
    }
    else
    {
        printf("\n\nArquivo aberto com sucesso!\n\n");

        system("pause");
        menu(fp);
    }

}

 infoARQUIVO(char *pnome, char *pnome_normal, FILE *ronaldo)
{
     struct info
    {
        char ChunkID[5];// = {' ',' ', ' ', ' ', '\0'};
        uint32_t ChunkSize;
        char  Format[5];// = { ' ',' ', ' ', ' ', '\0' };
        char  Subchunk1ID[5];// = { ' ',' ', ' ', ' ', '\0' };
        uint32_t Subchunk1Size;
        uint16_t AudioFormat;
        uint16_t NumChannels;
        uint32_t SampleRate;
        uint32_t ByteRate;
        uint16_t BlockAlign;
        uint16_t BitsPerSample;
        char  Subchunk2ID[5];// = { ' ',' ', ' ', ' ', '\0' };
        char  ChunkListID[14];// = { ' ',' ', ' ', ' ', ' ', ' ', ' ', ' ',' ',' ', ' ',' ',' ', '\0' };
        float a;
    };

    struct info cabecalho;

    fread((void *) &cabecalho, sizeof(cabecalho), 1, ronaldo);

    puts("\n\nInformações do arquivo lidas!\n\n");

    printf("ChunkID: ");
    showID(cabecalho.ChunkID);

    printf("ChunkSize: %d bytes\n", cabecalho.ChunkSize);

    printf("Format: ");
    showID(cabecalho.Format);

    printf("Subchunk1ID: ");
    showID(cabecalho.Subchunk1ID);

    printf("Subchunk1Size: %d", cabecalho.Subchunk1Size);

    printf("\nAudioFormat: %d", cabecalho.AudioFormat);

    printf("\nNumChannels: %d", cabecalho.NumChannels);

    printf("\nSampleRate: %d", cabecalho.SampleRate);

    printf("\nByteRate: %d", cabecalho.ByteRate);

    printf("\nBlockAlign: %d", cabecalho.BlockAlign);

    printf("\nBitsPerSample: %d bits", cabecalho.BitsPerSample);

    printf("\nSubchunk2ID: ");
    showID(cabecalho.Subchunk2ID);

    printf("ChunkListID: ");
    showID(cabecalho.ChunkListID);

    //printf("Data: %f", cabecalho.a);

    puts("\n\n");


}


int sair()
{
    int opcaoSAIR;

    system("cls");

    printf("DESEJA SAIR DO PROGRAMA?");
    printf("\n\n1. Não");
    printf("\n\n2. Sim");

    printf("\n\nSelecione uma opção: ");
    scanf("%d", &opcaoSAIR);

    switch(opcaoSAIR)
    {
        case 1: menu(pnome);
        break;

        case 2: system("exit");
        break;
    }
}

void showID(char *id)
{
    int i;
    for (i=0;i<4;i++)
    {
        printf("%c",*id);
        id++;
    }
    puts(" ");
}
kayser
