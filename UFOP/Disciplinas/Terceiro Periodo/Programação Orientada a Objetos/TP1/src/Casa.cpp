// Created by Igor Santiago - 19.1.4033 and Fábio Fernandes - 19.1.4128  on 11/2021.

#include "Casa.h"

//Construtor e destrutor
Casa :: Casa (int id, float valor, string proprietario, string rua, string bairro, string cidade, 
              int numero, int quartos, int banheiros, int andares, bool sala_jantar):
    Imovel(id, valor, proprietario, rua, bairro, cidade, numero, quartos, banheiros), 
           andares(andares), sala_jantar(sala_jantar){}

Casa :: ~Casa(){}

//Getters
int Casa :: getAndares() const{
    return andares;
}
bool Casa :: getSalaJantar() const{
    return sala_jantar;
}

//Setters
void Casa :: setAndares(int andares){
    this->andares = andares;
}
void Casa :: setSalaJantar(bool sala_jantar){
    this->sala_jantar = sala_jantar;
}

void Casa :: saida (ostream & out) const{
    Imovel :: saida(out);
    out << andares << " Andar(es)\n-----\n";
}

ostream& operator<<(ostream &out, const Casa &obj){
    obj.saida(out);
    return out;
}