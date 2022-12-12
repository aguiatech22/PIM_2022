#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include "comum.h"
#include "users.h"
#include "string.h"
#include "cadastroProduto.h"

bool cadastroProduto(){
    char digResposta;
   struct stUsuCadastroProduto cadastroProduto;
    chamaTelaCadastroProduto();
struct    stUsuCadastroProduto trataInputCadasProduto();
    consoleTela();
    desenhaTelaPadrao();
     digResposta = '\0';
    bool ok = false;
    while(ok == false){
        if ( digResposta == 'S' || digResposta == 'N' )
         {
             ok = true;
         }
         else
         {
            setCursorXY(10,10);
            printf("Deseja cadastrar um novo produto?(S/N)");
            scanf("%s", &digResposta);
         }
    }
     if (digResposta == 'S')
      return true;
     else
        return false;
}

void chamaTelaCadastroProduto()
{
  consoleTela();
  desenhaTelaPadrao();
  desenhaTelaCadastroProduto();
}

void desenhaTelaCadastroProduto()
{

struct stUsuCadastroProduto usuCadastroProduto;
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
struct stUsuCadastroProduto trataInputCadasProduto(){
struct stUsuCadastroProduto retornoCadastroProduto = {0};

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

FILE *arq;
 int vok;
 fflush(stdin);
 arq = fopen("./BancoDados/T_usuario.dat", "ab");
    if (arq == NULL)
    {
        exibeMensagemSistema("Erro ao abrir arquivo T_usuario.dat");
        memset(&retornoCadastroProduto, '\0' , sizeof(retornoCadastroProduto));
        return retornoCadastroProduto;
    }

    vok = fwrite (&retornoCadastroProduto, sizeof(retornoCadastroProduto), 1, arq);
    if (vok == 1)
    {
        fclose(arq);
        exibeMensagemSistema("Produto cadastrado com sucesso!.");
        return retornoCadastroProduto;
    }
    else
    {
        fclose (arq);
        exibeMensagemSistema("Erro ao gravar usuario!.");
        memset(&retornoCadastroProduto, '\0' , sizeof(retornoCadastroProduto));
        return retornoCadastroProduto;
    }

 return retornoCadastroProduto;
};

void chamaSubMenuCadastroProduto(){
    int digSubMenu;
    bool resposta;
    memset(&resposta, '\0' , sizeof(resposta));
    resposta = 83;
    chamaTelaSubMenuCadastroProduto();
    digSubMenu = 1;
    setCursorXY(10,20);
    printf("Digitar opcao do sub-menu: ");
    scanf("%d", &digSubMenu);
     switch(digSubMenu)
      {
       case 1:
          while ( resposta == true ){
                resposta = cadastroProduto( );
        }
        menuSistema();
        break;
       case 2:
         // while ( resposta == true ){
       // resposta = alteraProduto( );
      // }
        menuSistema();
        break;
       case 3:
          //while ( resposta == true ){
        //resposta = deletaProduto( );
        //}
        menuSistema();
        break;
       case 4:
        menuSistema();
        break;
       default:
        exibeMensagemSistema("Erro - Opcao invalida!");
        void chamaSubMenuCadastroProduto();
        break;
      } //switch
    return digSubMenu;
};

void chamaTelaSubMenuCadastroProduto(){
  consoleTela();
  desenhaTelaPadrao();
  desenhaTelaSubMenuCadastroProduto();
}

void desenhaTelaSubMenuCadastroProduto(){
 setCursorXY(30,4);
 printf("1 - Cadastrar produto");
 setCursorXY(30,5);
 printf("2 - Alterar produto");
 setCursorXY(30,6);
 printf("3 - Excluir produto");
 setCursorXY(30,7);
 printf("4 - Voltar");
};











