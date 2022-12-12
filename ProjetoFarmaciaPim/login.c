#include <stdbool.h>
#include <conio.h>
#include <stdlib.h>
#include "comum.h"
#include "login.h"
#include "cadastroUsuario.h"

bool loginSistema(){
    struct stUsuCadastro usuarioSistema ={0};
    struct stUsuCadastro usuarioSistema_comp = {0};

    chamaTelaLogin();
    usuarioSistema = trataInputLogin();

    return memcmp(usuarioSistema.codigoUsuario, usuarioSistema_comp.codigoUsuario, sizeof(usuarioSistema.codigoUsuario)) == 0;

}

void chamaTelaLogin(){
    consoleTela();
    desenhaTelaPadrao();
    desenhaTelaLogin();
}

struct stUsuCadastro validaUsuario ( struct stUsuLogin usuInput){
   // Valida se os usuario e senha estão preenchidos
   FILE *tabelaUsuario;
   struct stUsuCadastro usuarioArquivo;
   struct stUsuLogin usuInputaux;
   int c;

   usuInputaux = usuInput;
   // Validar se o usuario e senha estão preenchidos
  memset(&usuarioArquivo, '\0' , sizeof(usuarioArquivo));
  tabelaUsuario = fopen("./BancoDados/T_USUARIO.dat","rb");
  if( tabelaUsuario == NULL )
  {
    exibeMensagemSistema("Arquivo nao pode ser aberto.\n");
  }

   while( fread (&usuarioArquivo, sizeof(usuarioArquivo), 1, tabelaUsuario) )
   {
     if ( strcmp(usuarioArquivo.codigoUsuario,usuInput.codusu) == 0 &&
          strcmp(usuarioArquivo.senhaUsuario,usuInput.senhausu) != 0 ){
        exibeMensagemSistema("Senha incorreta!");
        memset(&usuarioArquivo, '\0' , sizeof(usuarioArquivo));
        fclose(tabelaUsuario);
        return usuarioArquivo;
     }
     else if ( strcmp(usuarioArquivo.codigoUsuario,usuInput.codusu) == 0 &&
               strcmp(usuarioArquivo.senhaUsuario,usuInput.senhausu) == 0 ){
        fclose(tabelaUsuario);
        return usuarioArquivo;
     }
     /*if ( usuarioArquivo.codigoUsuario == usuInput.codusu &&
          usuarioArquivo.senhaUsuario  != usuInput.senhausu )
        {
        exibeMensagemSistema("Senha incorreta!");
        memset(&usuarioArquivo, '\0' , sizeof(usuarioArquivo));
        fclose(tabelaUsuario);
        return usuarioArquivo;
     }
     else if ( usuarioArquivo.codigoUsuario == usuInput.codusu  &&
               usuarioArquivo.senhaUsuario == usuInput.senhausu ){
        fclose(tabelaUsuario);
        return usuarioArquivo;
        break;
     }*/

   }

   memset(&usuarioArquivo, '\0' , sizeof(usuarioArquivo));
   exibeMensagemSistema("Usuario nao encontrado!");
   fclose(tabelaUsuario);
   return usuarioArquivo;
};

struct stUsuLogin inputUsuarioLogin(){
 char cInput;
 int i = 0;
 struct stUsuLogin retunrUsuLogin;

 // Posiciona a entrada do usuário
 memset(retunrUsuLogin.codusu, '\0' , sizeof(retunrUsuLogin.codusu));
 memset(retunrUsuLogin.senhausu, '\0' , sizeof(retunrUsuLogin.senhausu));
 setCursorXY(40,11);
 do{
      cInput = getch();
      if (cInput == BACKSPACE && i > 0){
        retunrUsuLogin.codusu[i] = '\0';
        printf("\b \b");
        i--;
      }
      else if(cInput != BACKSPACE &&
              cInput != ENTER &&
              cInput != SPACE &&
              i != S_CODUSU) {
        putch(cInput);
        retunrUsuLogin.codusu[i] = cInput;
        i++;
      };
 }while (cInput != ENTER); // Verificar se o usuario apertar enter primeiro

 // Posiciona a entrada da Senha
  i = 0;
  setCursorXY(40,12);
 do{
      cInput = getch();

      if (cInput == BACKSPACE && i > 0){
        retunrUsuLogin.senhausu[i] = '\0';
        printf("\b \b");
        i--;
      }
      else if(cInput != BACKSPACE &&
              cInput != ENTER &&
              cInput != SPACE &&
              i != S_SENHAUSU) {
        putch('*');
        retunrUsuLogin.senhausu[i] = cInput;
        i++;
      };
 }while (cInput != ENTER); // Verificar se o usuario apertar enter primeiro

 return retunrUsuLogin;
};

struct stUsuCadastro trataInputLogin(){
struct stUsuLogin usuLogin;
struct stUsuCadastro returnUsuario = {0};
 memset(&returnUsuario,'\0',sizeof(returnUsuario));
 usuLogin = inputUsuarioLogin();
 returnUsuario = validaUsuario(usuLogin);
 return returnUsuario;
};

void desenhaTelaLogin(){
struct stUsuLogin usuLogin;
//struct stUsuLogin usuarioSistema;
 memset(&usuLogin, '\0', sizeof(usuLogin));

 // Entrada de textos do login
 setCursorXY(30,11);
 printf("Usuario :");
 setCursorXY(30,12);
 printf("Senha   :");

  // Apaga dados de entrada Usuario e Senha
 setCursorXY(40,11);
 char clearUsuario[S_CODUSU + 1];
 memset( clearUsuario, ' ', sizeof clearUsuario - 1 );
 clearUsuario[sizeof clearUsuario] = '\0';
 printf(clearUsuario);

  setCursorXY(40,12);
 char clearSenha[S_SENHAUSU + 1];
 memset( clearSenha, ' ', sizeof clearSenha - 1 );
 clearSenha[sizeof clearSenha] = '\0';
 printf(clearSenha);

}
