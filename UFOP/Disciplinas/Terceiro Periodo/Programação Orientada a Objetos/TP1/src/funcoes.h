// Created by Igor Santiago - 19.1.4033 and Fábio Fernandes - 19.1.4128  on 11/2021.

#ifndef FUNCOES_H
#define FUNCOES_H

    #include "Apartamento.h"
    #include "Casa.h"
    #include "Chacara.h"

    #include <vector>
    #include <algorithm>
    #include <fstream>
    #include <sstream>
    #include <iterator>
    #include <cstring>

    using namespace std;

    vector<Imovel*> lerArquivo();
    bool propTemImovel(vector<Imovel*> imoveis, string proprietario);
    vector<Imovel*> conjuntoValor (vector<Imovel*> imoveis, float numMaxValor);
    vector<Imovel*> conjuntoQuartos (vector<Imovel*> imoveis, int numMaxQuartos);
    vector<Imovel*> conjuntoTipoImovel (vector<Imovel*> imoveis, string tipoImovel);
    vector<Imovel*> conjuntoCidade (vector<Imovel*> imoveis, string cidade);
    vector<int> iteradoresProprietario (vector<Imovel*> imoveis, string proprietario);
    bool compararCrescente(const Imovel *l, const Imovel *r);
    bool compararDecrescente(const Imovel *l, const Imovel *r);

    void ImprTerminalOuArquivo(vector<Imovel*> imoveis, bool opcao);

#endif