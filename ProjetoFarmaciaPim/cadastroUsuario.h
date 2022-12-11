#ifndef CADASTROUSUARIO_H_INCLUDED
#define CADASTROUSUARIO_H_INCLUDED
#define S_CODUSU 15
#define S_SENHAUSU 15
#define S_NOMEUSU 60
#define S_DATANASCIMENTO 10
#endif // CADASTROUSUARIO_H_INCLUDED

 struct stUsuCadastro{
    char codigoUsuario[S_CODUSU];
    char senhaUsuario[S_SENHAUSU];
    char nomeUsuario[S_NOMEUSU];
    char dataNascUsuario[S_DATANASCIMENTO];
};

bool cadastroUsuario();
void chamaTelaCadastroUsuario();
void desenhaTelaCadastroUsuario();
void chamaSubMenuCadastroUsuario();
void chamaTelaSubMenuCadastroUsuario();
void desenhaTelaSubMenuCadastroUsuario();
struct stUsuCadastro trataInputCadastro();

//stCadastro validaCadastro(stCadasUsuario cadasInput);
//stCadasUsuario inputCadastro();


