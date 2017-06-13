#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

int main() {
    setlocale(LC_ALL, "Portuguese"); //PEGAR ACENTOS

    char base[3][3]; // MATRIZ BASE DO JOGO
    int inicio; // MENU E PARA INICIAR O JOGO
    int mostrar; // CASO DE ERRO ELE N�O MOSTRAR MATRIZ DUPLICADA
    int coluna; // PARA O CONTADOR DE COLUNA
    int linha; // PARA O CONTADOR DE LINHA
    int icoluna; // PARA O CONTADOR DE COLUNA QUE O JOGADOR COLOCOU
    int ilinha; // PARA O CONTADOR DE LINHA QUE O JOGADOR COLOCOU
    int jogador; // NENHUM JOGADOR = 0 | JOGADOR X(1) = 1 | JOGADOR O(2) = 2;
    int empate; // CONTADOR DE EMPATE
    int placarX;
    int placarO;
    char o = 'O';
    char x = 'X';

    inicio = mostrar = coluna = linha = icoluna = ilinha = jogador = empate = placarX = placarO = 0; // INICIAR VARI�VEIS

    for (linha=0;linha<3;linha++){
        for(coluna=0;coluna<3;coluna++){
            base[linha][coluna] = '?';     // INCIAR MATRIZ "BASE" COM CARACTERS '?'
        }
    }

    /*
    00 01 02      11 12 13    ? ? ?
    10 11 12  ==  21 22 23 == ? ? ?
    20 21 22      31 32 33    ? ? ?
    */

    printf("\n+----------------------------------------------------------+");
    printf("\n|  JOGO DA VELHA - MENU - ESCOLHA O MODO QUE DESEJA JOGAR  |");
    printf("\n+----------------------------------------------------------+");
    printf("\n| *PARA JOGAR 'JOGADOR x JOGADOR' digite o n�mero '1'.     |");
    printf("\n| *PARA JOGAR 'JOGADOR x COMPUTADOR' digite o n�mero '2'.  |");
    printf("\n+----------------------------------------------------------+");
    printf("\n|                       PLACAR                             |");
    printf("\n|                      X: %d | O: %d                       |", placarX, placarO);
    printf("\n+----------------------------------------------------------+");
    printf("\n\n>> Escolha sua op��o: ");
    scanf("%d", &inicio);

    if (inicio==1){

        inicio = 0;
        printf("\n+---------------------------------------------+");
        printf("\n|  VOC� ESCOLHEU O MODO 'JOGADOR x JOGADOR'.  |");
        printf("\n+---------------------------------------------+");
        printf("\n|  A BASE DO JOGO � COMPOSTA POR UMA MATRIZ   |");
        printf("\n|                  EXEMPLO:                   |");
        printf("\n|                                             |");
        printf("\n|               %d |",11); printf(" %d |",12); printf(" %d                  |",13);
        printf("\n|               %d |",21); printf(" %d |",22); printf(" %d                  |",23);    // MOSTRAR MATRIZ NUMERADA
        printf("\n|               %d |",31); printf(" %d |",32); printf(" %d                  |",33);
        printf("\n|                                             |");
        printf("\n|        '11' = LINHA '1' E COLUNA '1'        |");
        printf("\n|        '12' = LINHA '1' E COLUNA '2'        |");
        printf("\n|        '32' = LINHA '3' E COLUNA '2'        |");
        printf("\n|                                             |");
        printf("\n+---------------------------------------------+");

        printf("\n\n>> Para come�ar digite qualquer n�mero +0 e pressione enter: ");
        scanf("%d", &inicio);

        if (inicio>0){ // SE O N�MERO DIGITADO ACIMA FOR <1 INICIA
            printf("\n\nJogo iniciando...");

        printf("\n\nTabuleiro resetado.");
            printf("\n+-------------+");
            printf("\n|             |");
            printf("\n|  %c |",base[0][0]); printf(" %c |",base[0][1]); printf(" %c  |",base[0][2]);
            printf("\n|  %c |",base[1][0]); printf(" %c |",base[1][1]); printf(" %c  |",base[1][2]);  //  MOSTRAR MATRIZ ATUAL
            printf("\n|  %c |",base[2][0]); printf(" %c |",base[2][1]); printf(" %c  |",base[2][2]);
            printf("\n|             |");
            printf("\n+-------------+");

        printf("\n");
        } else { // SE O N�MERO DIGITADO ACIMA FOR >1 N�O INICIA
            printf("\n\n** Jogo n�o iniciado...");
        }

        inicio = 1;
        mostrar = 0;

        while(inicio==1){

                if (jogador==0){ // SE N�O TIVER NENHUM JOGADOR, TAL VALOR MUDA PARA O JOGADOR X(1)
                    jogador=1;
                }

                // ***************** JOGADOR 1 *****************
                if (jogador==1){
                    printf("\n>> � a vez do jogador X (1)");
                    printf("\n>> Digite linha e coluna que preferir");
                    printf("\n** Linha: ");
                    scanf("%d", &ilinha);
                    printf("** Coluna: ");
                    scanf("%d", &icoluna);

                    if (base[ilinha-1][icoluna-1] == '?'){ // CASO O LUGAR DA MATRIZ ESTEJA VAZIO, EXECUTAR COMANDO ABAIXO (CONSIDERE LUGAR VAZIO AQUELES QUE ESTIVEREM '?')
                        base[ilinha-1][icoluna-1] = x; // PREENCHE LUGAR VAZIO COM X
                        jogador=2; // MUDA PARA O JOGADOR O(2)
                        mostrar=1; // MOSTRA A MATRIZ
                        empate=empate+1;
                    } else {
                        printf("\n** ERRO: Lugar inv�lido, digite linha e coluna novamente! **\n"); // CASI EKE DIGITE UM LUGAR DA MATRIZ QUE J� ESTEJA OCUPADO, ELE CAI AQUI
                        jogador=1;  // RETORNA PARA O JOGADOR 1
                        mostrar=0; // N�O MOSTRA 1 MATRIZ (PARA N�O REPETIR)
                    }
                }
                // ***************** FIM JOGADOR 1 *****************

                if(mostrar==1){
                    printf("\n+-------------+");
                    printf("\n|             |");
                    printf("\n|  %c |",base[0][0]); printf(" %c |",base[0][1]); printf(" %c  |",base[0][2]);
                    printf("\n|  %c |",base[1][0]); printf(" %c |",base[1][1]); printf(" %c  |",base[1][2]);  //  MOSTRAR MATRIZ ATUAL
                    printf("\n|  %c |",base[2][0]); printf(" %c |",base[2][1]); printf(" %c  |",base[2][2]);
                    printf("\n|             |");
                    printf("\n+-------------+");

                    printf("\n");
                }

                // ***************** VERIFICA��O X *****************.

                if(
                   (base[0][0]==x)&&(base[1][1]==x)&&(base[2][2]==x)
                || (base[0][0]==x)&&(base[0][1]==x)&&(base[0][2]==x)
                || (base[0][0]==x)&&(base[1][0]==x)&&(base[2][0]==x)
                || (base[0][2]==x)&&(base[1][2]==x)&&(base[2][2]==x)
                || (base[2][0]==x)&&(base[2][1]==x)&&(base[2][2]==x)
                || (base[2][0]==x)&&(base[1][1]==x)&&(base[0][2]==x)
                || (base[1][0]==x)&&(base[1][1]==x)&&(base[1][2]==x)
                || (base[0][1]==x)&&(base[1][1]==x)&&(base[2][1]==x)
                ){
                    printf("\n+--------------------------------------------------------------+");
                    printf("\n|************** Ora ora, o jogador 'X' venceu!!! **************|");
                    printf("\n+--------------------------------------------------------------+\n");
                    placarX = placarX+1;
                    inicio=0;

                    printf("\n\n>> DESEJA CONTINUAR JOGANDO? DIGITE QUALQUER 'N�MERO>0' PARA CONTINUAR E '0' PARA SAIR!");
                    scanf("%d", &inicio);
                    if (inicio>0){
                        main();
                    }else{
                    printf("\n\n >> FIM DE JOGO SEU CAG�O!! <<");
                    }
                }

                if (empate==9){
                    printf("\n+------------------------------------------------------+");
                    printf("\n|************** Ora ora, o jogo empatou! **************|");
                    printf("\n+------------------------------------------------------+\n");
                    return (0);
                }
                // ***************** FIM VERIFICA��O *****************

                // ***************** JOGADOR 2 *****************
                if (jogador==2){
                    printf("\n>> � a vez do jogador O (2)");
                    printf("\n>> Digite linha e coluna que preferir");
                    printf("\n** Linha: ");
                    scanf("%d", &ilinha);
                    printf("** Coluna: ");
                    scanf("%d", &icoluna);

                    if (base[ilinha-1][icoluna-1] == '?'){
                        base[ilinha-1][icoluna-1] = o;
                        empate=empate+1;
                        jogador=1;
                        mostrar=1;
                    } else {
                        printf("\n** ERRO: Lugar inv�lido, digite linha e coluna novamente! **\n");
                        jogador=2;
                        mostrar=0;
                    }
                }
                // ***************** FIM JOGADOR 2 *****************


                printf("\n+-------------+");
                printf("\n|             |");
                printf("\n|  %c |",base[0][0]); printf(" %c |",base[0][1]); printf(" %c  |",base[0][2]);
                printf("\n|  %c |",base[1][0]); printf(" %c |",base[1][1]); printf(" %c  |",base[1][2]);  //  MOSTRAR MATRIZ ATUAL
                printf("\n|  %c |",base[2][0]); printf(" %c |",base[2][1]); printf(" %c  |",base[2][2]);
                printf("\n|             |");
                printf("\n+-------------+");

                printf("\n");

                // ***************** VERIFICA��O O *****************.

                if(
                   (base[0][0]==o)&&(base[1][1]==o)&&(base[2][2]==o)
                || (base[0][0]==o)&&(base[0][1]==o)&&(base[0][2]==o)
                || (base[0][0]==o)&&(base[1][0]==o)&&(base[2][0]==o)
                || (base[0][2]==o)&&(base[1][2]==o)&&(base[2][2]==o)
                || (base[2][0]==o)&&(base[2][1]==o)&&(base[2][2]==o)
                || (base[2][0]==o)&&(base[1][1]==o)&&(base[0][2]==o)
                || (base[1][0]==o)&&(base[1][1]==o)&&(base[1][2]==o)
                || (base[0][1]==o)&&(base[1][1]==o)&&(base[2][1]==o)
                ){
                    printf("\n+--------------------------------------------------------------+");
                    printf("\n|************** Ora ora, o jogador 'O' venceu!!! **************|");
                    printf("\n+--------------------------------------------------------------+\n");
                    placarO+1;

                    printf("\n\n>> DESEJA CONTINUAR JOGANDO? DIGITE QUALQUER 'N�MERO>0' PARA CONTINUAR E '0' PARA SAIR!");
                    scanf("%d", &inicio);
                    if (inicio>0){
                        main();
                    }else{
                    printf("\n\n >> FIM DE JOGO SEU CAG�O!! <<");
                    }
                }

                if (empate==9){
                    printf("\n+------------------------------------------------------+");
                    printf("\n|************** Ora ora, o jogo empatou! **************|");
                    printf("\n+------------------------------------------------------+\n");
                    return (0);
                }
                // ***************** FIM VERIFICA��O *****************

            }
        }






    if (inicio==2){

        inicio = 0;

        printf("\n\n VOC� ESCOLHEU O MODO 'JOGADOR x COMPUTADOR'.");
        printf("\n\nBase do jogo: ");
        printf("\nLinhaColuna");
        printf("\n\n  %d |",11); printf(" %d |",12); printf(" %d ",13);
        printf("\n  %d |",21); printf(" %d |",22); printf(" %d ",23);    // MOSTRAR MATRIZ NUMERADA
        printf("\n  %d |",31); printf(" %d |",32); printf(" %d ",33);

        printf("\n\n>> Para come�ar digite qualquer n�mero +0 e pressione enter: ");
        scanf("%d", &inicio);

        if (inicio>0){ // SE O N�MERO DIGITADO ACIMA FOR <1 INICIA
            printf("\n\nJogo iniciando...");

        printf("\nTabuleiro resetado.");
            printf("\n");
            printf("\n  %c |",base[0][0]); printf(" %c |",base[0][1]); printf(" %c ",base[0][2]);
            printf("\n  %c |",base[1][0]); printf(" %c |",base[1][1]); printf(" %c ",base[1][2]);  //  MOSTRAR MATRIZ ATUAL
            printf("\n  %c |",base[2][0]); printf(" %c |",base[2][1]); printf(" %c ",base[2][2]);
            printf("\n");
            printf("\n*AVISO* >> SUAS JOGADAS SER�O REPRESENTADAS PELA LETRA 'X'!!");
        printf("\n");
        } else { // SE O N�MERO DIGITADO ACIMA FOR >1 N�O INICIA
            printf("\n\n** Jogo n�o iniciado...");
        }

        inicio = 1;
        mostrar = 0;

        while(inicio==1){

                if (jogador==0){ // SE N�O TIVER NENHUM JOGADOR, TAL VALOR MUDA PARA O JOGADOR X(1)
                    jogador=1;
                }

                // ***************** JOGADOR 1 *****************
                if (jogador==1){
                    printf("\n>> � A SUA VEZ");
                    printf("\n>> Digite linha e coluna que preferir");
                    printf("\n** Linha: ");
                    scanf("%d", &ilinha);
                    printf("** Coluna: ");
                    scanf("%d", &icoluna);

                    if (base[ilinha-1][icoluna-1] == '?'){ // CASO O LUGAR DA MATRIZ ESTEJA VAZIO, EXECUTAR COMANDO ABAIXO (CONSIDERE LUGAR VAZIO AQUELES QUE ESTIVEREM '?')
                        base[ilinha-1][icoluna-1] = x; // PREENCHE LUGAR VAZIO COM X
                        jogador=2; // MUDA PARA O JOGADOR O(2)
                        mostrar=1; // MOSTRA A MATRIZ
                        empate=empate+1;
                    } else {
                        printf("\n** ERRO: Lugar inv�lido, digite linha e coluna novamente! **\n"); // CASI EKE DIGITE UM LUGAR DA MATRIZ QUE J� ESTEJA OCUPADO, ELE CAI AQUI
                        jogador=1;  // RETORNA PARA O JOGADOR 1
                        mostrar=0; // N�O MOSTRA 1 MATRIZ (PARA N�O REPETIR)
                    }
                }
                // ***************** FIM JOGADOR 1 *****************

                printf("\n");
                printf("\n  %c |",base[0][0]); printf(" %c |",base[0][1]); printf(" %c ",base[0][2]);
                printf("\n  %c |",base[1][0]); printf(" %c |",base[1][1]); printf(" %c ",base[1][2]);  // MOSTRA MATRIZ
                printf("\n  %c |",base[2][0]); printf(" %c |",base[2][1]); printf(" %c ",base[2][2]);
                printf("\n");


                // ***************** VERIFICA��O X *****************.

                if(
                   (base[0][0]==x)&&(base[1][1]==x)&&(base[2][2]==x)
                || (base[0][0]==x)&&(base[0][1]==x)&&(base[0][2]==x)
                || (base[0][0]==x)&&(base[1][0]==x)&&(base[2][0]==x)
                || (base[0][2]==x)&&(base[1][2]==x)&&(base[2][2]==x)
                || (base[2][0]==x)&&(base[2][1]==x)&&(base[2][2]==x)
                || (base[2][0]==x)&&(base[1][1]==x)&&(base[0][2]==x)
                || (base[1][0]==x)&&(base[1][1]==x)&&(base[1][2]==x)
                || (base[0][1]==x)&&(base[1][1]==x)&&(base[2][1]==x)
                ){
                    printf("\n*************** ORA ORA, O VOC� VENCEU! ***************\n");
                    return (0);
                }

                if (empate==9){
                    printf("\n*************** ORA ORA, PARECE QUE O JOGO EMPATOU, N�O � MESMO? ***************\n");
                    return (0);
                }
                // ***************** FIM VERIFICA��O *****************

                // ***************** JOGADOR 2 *****************
                if (jogador==2){
                    printf("\n� A VEZ DO COMPUTADOR!!");

                            srand(time(NULL));
                            ilinha = rand()%3;
                            icoluna = rand()%3;
                            printf("\nN�mero Sorteado L: %d", ilinha);
                            printf("\nN�mero Sorteado C: %d", icoluna);

                    if (base[ilinha][icoluna] == '?'){
                        base[ilinha][icoluna] = o;
                        empate=empate+1;
                        jogador=1;
                        mostrar=1;
                    } else {
                        jogador=2;
                    }
                }
                // ***************** FIM JOGADOR 2 *****************

                if (mostrar==1){
                    printf("\n");
                    printf("\n  %c |",base[0][0]); printf(" %c |",base[0][1]); printf(" %c ",base[0][2]);
                    printf("\n  %c |",base[1][0]); printf(" %c |",base[1][1]); printf(" %c ",base[1][2]);
                    printf("\n  %c |",base[2][0]); printf(" %c |",base[2][1]); printf(" %c ",base[2][2]);
                    printf("\n");
                }

                // ***************** VERIFICA��O O *****************.

                if(
                   (base[0][0]==o)&&(base[1][1]==o)&&(base[2][2]==o)
                || (base[0][0]==o)&&(base[0][1]==o)&&(base[0][2]==o)
                || (base[0][0]==o)&&(base[1][0]==o)&&(base[2][0]==o)
                || (base[0][2]==o)&&(base[1][2]==o)&&(base[2][2]==o)
                || (base[2][0]==o)&&(base[2][1]==o)&&(base[2][2]==o)
                || (base[2][0]==o)&&(base[1][1]==o)&&(base[0][2]==o)
                || (base[1][0]==o)&&(base[1][1]==o)&&(base[1][2]==o)
                || (base[0][1]==o)&&(base[1][1]==o)&&(base[2][1]==o)
                ){
                    printf("\n*************** ORA ORA, O COMPUTADOR VENCEU! ***************\n");
                    return (0);
                }

                if (empate==9){
                    printf("\n*************** ORA ORA, PARECE QUE O JOGO EMPATOU, N�O � MESMO? ***************\n");
                    return (0);
                }
                // ***************** FIM VERIFICA��O *****************

            }
    }





    printf("\n\n------------------- FIM DA EXECU��O ------------------\n\n");
    return 0;
}
