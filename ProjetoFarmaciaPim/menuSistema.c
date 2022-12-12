#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include "comum.h"
#include "menuSistema.h"

int menuSistema(){
    int digMenu;
    bool resposta;
    memset(&resposta, '\0' , sizeof(resposta));
    resposta = 83;
    chamaTelaMenu();
    digMenu = 1;
    setCursorXY(10,20);
    printf("Digitar opcao do menu: ");
    scanf("%d", &digMenu);
     switch(digMenu)
      {
       case 1:
        chamaSubMenuCadastroUsuario( );
        break;
       case 2:
        chamaSubMenuCadastroCliente( );
        //while ( resposta == true ){
        //resposta = cadastroCliente( );
        //}
         break;
       case 3:
        chamaSubMenuCadastroProduto( );
        //while ( resposta == true ){
        //    resposta = cadastroProduto( );
        //}
           break;
       case 4:
           break;
       case 5:
           break;
       case 6:
           break;
       case 7:
           break;
       case 0:
           break;
       default:
        exibeMensagemSistema("Erro - Opcao invalida!");
        break;
      } //switch
    return digMenu;
};

void desenhaTelaMenu(){
 // Tela de Menu
 setCursorXY(30,4);
 printf("1 - Cadastro de usuario");
 setCursorXY(30,5);
 printf("2 - Cadastro do Cliente");
 setCursorXY(30,6);
 printf("3 - Cadastro de Produtos");
 setCursorXY(30,7);
 printf("4 - Relatorios");
 setCursorXY(30,8);
 printf("5 - Cliente fielidade");
 setCursorXY(30,9);
 printf("0 - Finalizar");
};

void chamaTelaMenu(){
  consoleTela();
  desenhaTelaPadrao();
  desenhaTelaMenu();
}
