#ifndef USERS_H_INCLUDED
#define USERS_H_INCLUDED

#define S_CODUSU 15
#define S_SENHAUSU 15
#define S_NOMEUSU 60


#endif // USERS_H_INCLUDED

typedef struct {
    char codusu[S_CODUSU];
    char senhausu[S_SENHAUSU];
    char nome[S_NOMEUSU]
}stUsuario;
