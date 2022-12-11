#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include "comum.h"
#include "users.h"
#include "string.h"
#include "cadastroUsuario.h"

bool cadastroUsuario(){
    char digResposta;
    struct stUsuCadastro cadastroUsuario;
    chamaTelaCadastroUsuario();
    cadastroUsuario = trataInputCadastro();
    consoleTela();
    desenhaTelaPadrao();
    setCursorXY(5,20);
    printf("Deseja cadastrar um novo usuario?(S/N)");

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
            printf("Deseja cadastrar um novo usuario?(S/N)");
            scanf("%s", &digResposta);
         }
    }
     if (digResposta == 'S')
      return true;
     else
        return false;
}

void chamaTelaCadastroUsuario()
{
  consoleTela();
  desenhaTelaPadrao();
  desenhaTelaCadastroUsuario();
}

void desenhaTelaCadastroUsuario()
{

 //stUsuCadastro usuCadastro;
 //memset(&usuCadastro, '\0', sizeof(usuCadastro));
 //   arq = fopen("./BancoDados/T_usuario.dat","ab");
 //   if (arq == NULL)
 //   {
 //       printf("Erro ao abrir arquivo");
 //       return;
 //   }

 // Entrada de dados cadastro
 int linha, coluna;

 linha  = 5;
 coluna = 10;

 setCursorXY(coluna,linha);
 printf("Codigo Usuario      :");
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

struct stUsuCadastro trataInputCadastro(){
 struct stUsuCadastro retornoCadastro = {0};

 char cInput;
 int i = 0;

 int linha, coluna;
 linha  = 5;
 coluna = 32;

 // Posiciona o curso para a entrada do código do usuario
 memset(&retornoCadastro.codigoUsuario, '\0' , sizeof(retornoCadastro.codigoUsuario));

 setCursorXY(coluna,linha);
 do{
      cInput = getch();
      if (cInput == BACKSPACE && i > 0){
        retornoCadastro.codigoUsuario[i] = '\0';
        printf("\b \b");
        i--;
      }
      else if(cInput != BACKSPACE &&
              cInput != ENTER &&
              cInput != SPACE &&
              i != S_CODUSU) {
        putch(cInput);
        retornoCadastro.codigoUsuario[i] = cInput;
        i++;
      };
 }while (cInput != ENTER);

 // Posiciona a entrada da Senha
 i = 0;
 linha++;
 setCursorXY(coluna,linha);
 memset(&retornoCadastro.senhaUsuario, '\0' , sizeof(retornoCadastro.senhaUsuario));
 do{
      cInput = getch();
      if (cInput == BACKSPACE && i > 0){
        retornoCadastro.senhaUsuario[i] = '\0';
        printf("\b \b");
        i--;
      }
      else if(cInput != BACKSPACE &&
              cInput != ENTER &&
              cInput != SPACE &&
              i != S_SENHAUSU) {
        putch('*');
        retornoCadastro.senhaUsuario[i] = cInput;
        i++;
      };
 }while (cInput != ENTER); // Verificar se o usuario apertar enter primeiro

 // Posiciona a entrada Nome
 i = 0;
 linha++;
 setCursorXY(coluna,linha);
 memset(&retornoCadastro.nomeUsuario, '\0' , sizeof(retornoCadastro.nomeUsuario));
 do{
      cInput = getch();
      if (cInput == BACKSPACE && i > 0){
        retornoCadastro.nomeUsuario[i] = '\0';
        printf("\b \b");
        i--;
      }
      else if(cInput != BACKSPACE &&
              cInput != ENTER &&
              cInput != SPACE &&
              i != S_NOMEUSU) {
        putch(cInput);
        retornoCadastro.nomeUsuario[i] = cInput;
        i++;
      };
 }while (cInput != ENTER);

 // Posiciona a entrada Data Nascimento
 i = 0;
 linha++;
 setCursorXY(coluna,linha);
 memset(&retornoCadastro.dataNascUsuario, '\0' , sizeof(retornoCadastro.dataNascUsuario));
 do{
      cInput = getch();
      if (cInput == BACKSPACE && i > 0){
        retornoCadastro.dataNascUsuario[i] = '\0';
        printf("\b \b");
        i--;
      }
      else if(cInput != BACKSPACE &&
              cInput != ENTER &&
              cInput != SPACE &&
              i != S_DATANASCIMENTO) {
        putch(cInput);
        retornoCadastro.dataNascUsuario[i] = cInput;
        i++;
        if( i == 2 || i == 5){
         putch('/');
         retornoCadastro.dataNascUsuario[i] = '/';
         i++;
        }
      };
 }while (cInput != ENTER);

 FILE *arq;
 int vok;
 fflush(stdin);
 arq = fopen("./BancoDados/T_usuario.dat", "ab");
    if (arq == NULL)
    {
        exibeMensagemSistema("Erro ao abrir arquivo T_usuario.dat");
        memset(&retornoCadastro, '\0' , sizeof(retornoCadastro));
        return retornoCadastro;
    }

    vok = fwrite (&retornoCadastro, sizeof(retornoCadastro), 1, arq);
    if (vok == 1)
    {
        fclose(arq);
        exibeMensagemSistema("Usuario cadastrado com sucesso!.");
        return retornoCadastro;
    }
    else
    {
        fclose (arq);
        exibeMensagemSistema("Erro ao gravar usuario!.");
        memset(&retornoCadastro, '\0' , sizeof(retornoCadastro));
        return retornoCadastro;
    }

};

void chamaSubMenuCadastroUsuario(){
    int digSubMenu;
    bool resposta;
    memset(&resposta, '\0' , sizeof(resposta));
    resposta = 83;
    chamaTelaSubMenuCadastroUsuario();
    digSubMenu = 1;
    setCursorXY(10,20);
    printf("Digitar opcao do sub-menu: ");
    scanf("%d", &digSubMenu);
     switch(digSubMenu)
      {
       case 1:
        while ( resposta == true ){
                resposta = cadastroUsuario( );
        }
        menuSistema();
        break;
       case 2:
       // while ( resposta == true ){
       //         resposta = alteraUsuario( );
       // }
        menuSistema();
        break;
       case 3:
       // while ( resposta == true ){
       //         resposta = deletaUsuario( );
       // }
        menuSistema();
        break;
       case 4:
        menuSistema();
        break;
       default:
        exibeMensagemSistema("Erro - Opcao invalida!");
        chamaSubMenuCadastroUsuario();
        break;
      } //switch
    return digSubMenu;
};

void chamaTelaSubMenuCadastroUsuario(){
  consoleTela();
  desenhaTelaPadrao();
  desenhaTelaSubMenuCadastroUsuario();
}

void desenhaTelaSubMenuCadastroUsuario(){
 setCursorXY(30,4);
 printf("1 - Cadastrar usuario");
 setCursorXY(30,5);
 printf("2 - Alterar Usuario");
 setCursorXY(30,6);
 printf("3 - Excluir Usuario");
 setCursorXY(30,7);
 printf("4 - Voltar");
};
