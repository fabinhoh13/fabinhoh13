#ifndef ENDERECO_H
#define ENDERECO_H

typedef struct endereco Endereco;

Endereco* criaEndereco();
Endereco* criaEndereco2( int, int );
void liberaEndereco( Endereco* );
int getEnderecoBloco( Endereco* );
void setEnderecoBloco( Endereco*, int );
int getEnderecoPalavra( Endereco* );
void setEnderecoPalavra( Endereco*, int );

#endif