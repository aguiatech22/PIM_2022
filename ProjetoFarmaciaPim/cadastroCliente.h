#ifndef CADASTROCLIENTE_H_INCLUDED
#define CADASTROCLIENTE_H_INCLUDED
#define S_CODCLI 15
#define S_NOMECLI 50
#define S_DTNASCCLI 10
#endif // CADASTROCLIENTE_H_INCLUDED

 struct stUsuCliente{
    char codigoCliente[S_CODCLI];
    char nomeCliente[S_NOMECLI];
    char dataNascCliente[S_DTNASCCLI];
};

bool cadastroCliente();
void chamaTelaCadastroCliente();
void desenhaTelaCadastroCliente();
struct stUsuCliente trataInputCliente();
struct stUsuCliente retornoCadastroCliente();
void chamaSubMenuCadastroCliente();
void desenhaTelaSubMenuCadastroCliente();

