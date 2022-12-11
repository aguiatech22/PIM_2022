#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include "comum.h"
#include "users.h"
#include "string.h"
#include "cadastroProduto.h"

bool cadastroProduto(){
    stUsuCadastroProduto cadastroProduto;
    chamaTelaCadastroProduto();
    stUsuCadastroProduto trataInputCadasProduto();

 //return memcmp(cadastroSistema.codusu, cadastroSistema_comp.codusu, sizeof(cadastroSistema.codusu)) == 0;
    return true;
}

void chamaTelaCadastroProduto()
{
  consoleTela();
  desenhaTelaPadrao();
  desenhaTelaCadastroProduto();
}

void desenhaTelaCadastroProduto()
{

 stUsuCadastroProduto usuCadastroProduto;
 memset(&usuCadastroProduto, '\0', sizeof(usuCadastroProduto));

 // Entrada de dados cadastro
 int linha, coluna;

 linha  = 5;
 coluna = 10;

 setCursorXY(coluna,linha);
 printf("Codigo Lote      :");
 linha++;

 setCursorXY(coluna,linha);
 printf("Validade Produto               :");
 linha++;

 setCursorXY(coluna,linha);
 printf("Data Fabricacao                :");
 linha++;

 setCursorXY(coluna,linha);
 printf("Nome Fabricante     :");

};
stUsuCadastroProduto trataInputCadasProduto(){
 stUsuCadastroProduto retornoCadastroProduto = {0};

 char cInput;
 int i = 0;

 int linha, coluna;
 linha  = 5;
 coluna = 32;

 // Posiciona o curso para a entrada do código do Lote
 memset(&retornoCadastroProduto.codigoLote, '\0' , sizeof(retornoCadastroProduto.codigoLote));
 setCursorXY(coluna,linha);
 do{
      cInput = getch();
      if (cInput == BACKSPACE && i > 0){
        retornoCadastroProduto.codigoLote[i] = '\0';
        printf("\b \b");
        i--;
      }
      else if(cInput != BACKSPACE &&
              cInput != ENTER &&
              cInput != SPACE &&
              i != S_CODIGOLOTE) {
        putch(cInput);
        retornoCadastroProduto.codigoLote[i] = cInput;
        i++;
      };
 }while (cInput != ENTER);

 // Posiciona a entrada da Data de Validade do Produto
i = 0;
 linha++;
 setCursorXY(coluna,linha);
 memset(&retornoCadastroProduto.validadeProduto, '\0' , sizeof(retornoCadastroProduto.validadeProduto));
 do{
      cInput = getch();
      if (cInput == BACKSPACE && i > 0){
        retornoCadastroProduto.validadeProduto[i] = '\0';
        printf("\b \b");
        i--;
      }
      else if(cInput != BACKSPACE &&
              cInput != ENTER &&
              cInput != SPACE &&
              i != S_DATAVALIDADE) {
        putch(cInput);
        retornoCadastroProduto.validadeProduto[i] = cInput;
        i++;
        if( i == 2 || i == 5){
         putch('/');
         retornoCadastroProduto.validadeProduto[i] = '/';
         i++;
        }
      };
 }while (cInput != ENTER); // Verificar se o usuario apertar enter primeiro

 // Posiciona a entrada Data de Fabricacao
 i = 0;
 linha++;
 setCursorXY(coluna,linha);
 memset(&retornoCadastroProduto.fabriProduto, '\0' , sizeof(retornoCadastroProduto.fabriProduto));
 do{
      cInput = getch();
      if (cInput == BACKSPACE && i > 0){
        retornoCadastroProduto.fabriProduto[i] = '\0';
        printf("\b \b");
        i--;
      }
      else if(cInput != BACKSPACE &&
              cInput != ENTER &&
              cInput != SPACE &&
              i != S_DATAVALIDADE) {
        putch(cInput);
        retornoCadastroProduto.fabriProduto[i] = cInput;
        i++;
        if( i == 2 || i == 5){
         putch('/');
         retornoCadastroProduto.fabriProduto[i] = '/';
         i++;
        }
      };
 }while (cInput != ENTER);

 // Posiciona a entrada Data Nascimento
i = 0;
 linha++;
 setCursorXY(coluna,linha);
 memset(&retornoCadastroProduto.nomeFabricante, '\0' , sizeof(retornoCadastroProduto.nomeFabricante));
 do{
      cInput = getch();
      if (cInput == BACKSPACE && i > 0){
        retornoCadastroProduto.nomeFabricante[i] = '\0';
        printf("\b \b");
        i--;
      }
      else if(cInput != BACKSPACE &&
              cInput != ENTER &&
              cInput != SPACE &&
              i != S_FABRICANTE) {
        putch(cInput);
        retornoCadastroProduto.nomeFabricante[i] = cInput;
        i++;
      };
 }while (cInput != ENTER);


// returnUsuario = validaUsuario(usuLogin);
 return retornoCadastroProduto;
};













