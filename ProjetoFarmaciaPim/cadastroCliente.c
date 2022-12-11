#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include "comum.h"
#include "users.h"
#include "string.h"
#include "cadastroCliente.h"

bool cadastroCliente(){
    stUsuCliente cadastroCliente;
    chamaTelaCadastroCliente();
    cadastroCliente = trataInputCliente();

    //return memcmp(cadastroSistema.codusu, cadastroSistema_comp.codusu, sizeof(cadastroSistema.codusu)) == 0;
    return true;
}

void chamaTelaCadastroCliente()
{
  consoleTela();
  desenhaTelaPadrao();
  desenhaTelaCadastroCliente();
}
void desenhaTelaCadastroCliente()
{

 stUsuCliente usuCliente;
 memset(&usuCliente, '\0', sizeof(usuCliente));

 // Entrada de dados cadastro
 int linha, coluna;

 linha  = 5;
 coluna = 10;

 setCursorXY(coluna,linha);
 printf("Codigo Cliente      :");
 linha++;

 setCursorXY(coluna,linha);
 printf("Senha               :");
 linha++;

 setCursorXY(coluna,linha);
 printf("Nome                :");
 linha++;

 setCursorXY(coluna,linha);
 printf("Data Nascimento     :");

};

stUsuCliente trataInputCliente(){
 stUsuCliente retornoCadastroCliente = {0};

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
              i != S_CODUSU) {
        putch(cInput);
        retornoCadastroCliente.codigoCliente[i] = cInput;
        i++;
      };
 }while (cInput != ENTER);

 // Posiciona a entrada da Senha
 i = 0;
 linha++;
 setCursorXY(coluna,linha);
 memset(&retornoCadastroCliente.senhaCliente, '\0' , sizeof(retornoCadastroCliente.senhaCliente));
 do{
      cInput = getch();
      if (cInput == BACKSPACE && i > 0){
        retornoCadastroCliente.senhaCliente[i] = '\0';
        printf("\b \b");
        i--;
      }
      else if(cInput != BACKSPACE &&
              cInput != ENTER &&
              cInput != SPACE &&
              i != S_SENHAUSU) {
        putch('*');
        retornoCadastroCliente.senhaCliente[i] = cInput;
        i++;
      };
 }while (cInput != ENTER); // Verificar se o usuario apertar enter primeiro

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
              cInput != SPACE &&
              i != S_NOMEUSU) {
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
              i != S_DATANASCIMENTO) {
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


// returnUsuario = validaUsuario(usuLogin);
 return retornoCadastroCliente;
};


















