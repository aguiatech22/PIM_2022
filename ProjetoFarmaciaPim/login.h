#ifndef LOGIN_H_INCLUDED
#define LOGIN_H_INCLUDED
    #define S_CODUSU 15
    #define S_SENHAUSU 15
    #define S_NOMEUSU 60
#endif // LOGIN_H_INCLUDED

struct stUsuLogin{
    char codusu[S_CODUSU];
    char senhausu[S_SENHAUSU];
};

bool loginSistema();
void chamaTelaLogin();
struct stUsuCadastro trataInputLogin();
struct stUsuCadastro validaUsuario(struct stUsuLogin stUsuLogin);
struct stUsuCadastro inputUsuario();
