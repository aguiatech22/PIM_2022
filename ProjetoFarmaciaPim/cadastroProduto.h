#ifndef CADASTROPRODUTO_H_INCLUDED
#define CADASTROPRODUTO_H_INCLUDED
#define S_CODIGOLOTE 15
#define S_FABRICANTE 40
#define S_DATAVALIDADE 10
#endif // CADASTROPRODUTO_H_INCLUDED


typedef struct {
    char codigoLote[S_CODIGOLOTE];
    char validadeProduto[S_DATAVALIDADE];
    char fabriProduto [S_DATAVALIDADE];
    char nomeFabricante[S_FABRICANTE];

}stUsuCadastroProduto;

bool cadastroProduto();
void chamaTelaCadastroProduto();
void desenhaTelaCadastroProduto();
stUsuCadastroProduto trataInputCadasProduto();
