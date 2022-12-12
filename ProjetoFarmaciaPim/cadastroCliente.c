#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include "comum.h"
#include "users.h"
#include "string.h"
#include "cadastroCliente.h"

bool cadastroCliente(){
    char digResposta;
    struct stUsuCliente cadastroCliente;
    chamaTelaCadastroCliente();
    cadastroCliente = trataInputCliente();
    consoleTela();
    desenhaTelaPadrao();

    digResposta = '\0';
    bool ok = false;
    while(ok == false){
        if ( digResposta == 'S' || digResposta == 'N' || digResposta == 's' || digResposta == 'n' )
         {
             ok = true;
         }
         else
         {
            setCursorXY(10,10);
            printf("Deseja cadastrar um novo cliente?(S/N)");
            scanf("%s", &digResposta);
         }
    }
     if (digResposta == 'S' ||digResposta == 's' )
      return true;
     else
        return false;
}

void chamaTelaCadastroCliente()
{
  consoleTela();
  desenhaTelaPadrao();
  desenhaTelaCadastroCliente();
}
void desenhaTelaCadastroCliente()
{

 //stUsuCliente usuCliente;
 //memset(&usuCliente, '\0', sizeof(usuCliente));

 // Entrada de dados cadastro
 int linha, coluna;

 linha  = 5;
 coluna = 10;

 setCursorXY(coluna,linha);
 printf("Codigo Cliente      :");
 linha++;

 setCursorXY(coluna,linha);
 printf("Nome                :");
 linha++;

 setCursorXY(coluna,linha);
 printf("Data Nascimento     :");

};

struct stUsuCliente trataInputCliente(){
 struct stUsuCliente retornoCadastroCliente = {0};

 char cInput;
 int i = 0;

 int linha, coluna;
 linha  = 5;
 coluna = 32;

 // Posiciona o curso para a entrada do código do cliente
 memset(&retornoCadastroCliente.codigoCliente, '\0' , sizeof(retornoCadastroCliente.codigoCliente ));
 setCursorXY(coluna,linha);
 do{
      cInput = getch();
      if (cInput == BACKSPACE && i > 0){
        retornoCadastroCliente.codigoCliente[i] = '\0';
        printf("\b \b");
        i--;
      }
      else if(cInput != BACKSPACE &&
              cInput != ENTER &&
              cInput != SPACE &&
              i != S_CODCLI) {
        putch(cInput);
        retornoCadastroCliente.codigoCliente[i] = cInput;
        i++;
      };
 }while (cInput != ENTER);

// Posiciona a entrada Nome
 i = 0;
 linha++;
 setCursorXY(coluna,linha);
 memset(&retornoCadastroCliente.nomeCliente, '\0' , sizeof(retornoCadastroCliente.nomeCliente));
 do{
      cInput = getch();
      if (cInput == BACKSPACE && i > 0){
        retornoCadastroCliente.nomeCliente[i] = '\0';
        printf("\b \b");
        i--;
      }
      else if(cInput != BACKSPACE &&
              cInput != ENTER &&
              //cInput != SPACE &&
              i != S_NOMECLI) {
        putch(cInput);
        retornoCadastroCliente.nomeCliente[i] = cInput;
        i++;
      };
 }while (cInput != ENTER);

 // Posiciona a entrada Data Nascimento
 i = 0;
 linha++;
 setCursorXY(coluna,linha);
 memset(&retornoCadastroCliente.dataNascCliente, '\0' , sizeof(retornoCadastroCliente.dataNascCliente));
 do{
      cInput = getch();
      if (cInput == BACKSPACE && i > 0){
        retornoCadastroCliente.dataNascCliente[i] = '\0';
        printf("\b \b");
        i--;
      }
      else if(cInput != BACKSPACE &&
              cInput != ENTER &&
              cInput != SPACE &&
              i != S_DTNASCCLI) {
        putch(cInput);
        retornoCadastroCliente.dataNascCliente[i] = cInput;
        i++;
        if( i == 2 || i == 5){
         putch('/');
         retornoCadastroCliente.dataNascCliente[i] = '/';
         i++;
        }
      };
 }while (cInput != ENTER);

 FILE *arq;
 int vok;
 fflush(stdin);
 arq = fopen("./BancoDados/T_CLIENTE.dat", "ab");
    if (arq == NULL)
    {
        exibeMensagemSistema("Erro ao abrir arquivo T_CLIENTE.dat");
        memset(&retornoCadastroCliente, '\0' , sizeof(retornoCadastroCliente));
        return retornoCadastroCliente;
    }

    vok = fwrite (&retornoCadastroCliente, sizeof(retornoCadastroCliente), 1, arq);
    if (vok == 1)
    {
        fclose(arq);
        exibeMensagemSistema("Cliente cadastrado com sucesso!.");
        return retornoCadastroCliente;
    }
    else
    {
        fclose (arq);
        exibeMensagemSistema("Erro ao gravar Cliente!.");
        memset(&retornoCadastroCliente, '\0' , sizeof(retornoCadastroCliente));
        return retornoCadastroCliente;
    }
 return retornoCadastroCliente;
};

void chamaSubMenuCadastroCliente(){
    int digSubMenu;
    bool resposta;
    memset(&resposta, '\0' , sizeof(resposta));
    resposta = 83;
    chamaTelaSubMenuCadastroCliente();
    digSubMenu = 1;
    setCursorXY(10,20);
    printf("Digitar opcao do sub-menu: ");
    scanf("%d", &digSubMenu);
     switch(digSubMenu)
      {
       case 1:
        while ( resposta == true ){
                resposta = cadastroCliente( );
        }
        menuSistema();
        break;
       case 2:
       // while ( resposta == true ){
       //         resposta = alteraCliente( );
       // }
        menuSistema();
        break;
       case 3:
       // while ( resposta == true ){
       //         resposta = deletaCliente( );
       // }
        menuSistema();
        break;
       case 4:
        menuSistema();
        break;
       default:
        exibeMensagemSistema("Erro - Opcao invalida!");
        chamaSubMenuCadastroCliente();
        break;
      } //switch
    return digSubMenu;
};

void chamaTelaSubMenuCadastroCliente(){
  consoleTela();
  desenhaTelaPadrao();
  desenhaTelaSubMenuCadastroCliente();
}

void desenhaTelaSubMenuCadastroCliente(){
 setCursorXY(30,4);
 printf("1 - Cadastrar Cliente");
 setCursorXY(30,5);
 printf("2 - Alterar Cliente");
 setCursorXY(30,6);
 printf("3 - Excluir Cliente");
 setCursorXY(30,7);
 printf("4 - Voltar");
};

















