#ifndef CADASTROCLIENTE_H_INCLUDED
#define CADASTROCLIENTE_H_INCLUDED
#define S_CODUSU 15
#define S_SENHAUSU 15
#define S_NOMEUSU 60
#define S_DATANASCIMENTO 10
#endif // CADASTROCLIENTE_H_INCLUDED

typedef struct {
    char codigoCliente[S_CODUSU];
    char senhaCliente[S_SENHAUSU];
    char nomeCliente[S_NOMEUSU];
    char dataNascCliente[S_DATANASCIMENTO];
}stUsuCliente;

bool cadastroCliente();
void chamaTelaCadastroCliente();
void desenhaTelaCadastroCliente();
stUsuCliente trataInputCliente();

