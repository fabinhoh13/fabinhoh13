// Created by Igor Santiago - 19.1.4033 and Fábio Fernandes - 19.1.4128  on 11/2021.

#include "Chacara.h"

//Construtor e destrutor
Chacara :: Chacara (int id, float valor, string proprietario, string rua, string bairro,  
                    string cidade, int numero, int quartos, int banheiros, bool salao_festa, 
                    bool salao_jogos, bool campo_futebol, bool churrasqueira, bool piscina):
    Imovel(id, valor, proprietario, rua, bairro, cidade, numero, quartos, banheiros), 
           salao_festa(salao_festa), salao_jogos(salao_jogos), campo_futebol(campo_futebol), 
           churrasqueira(churrasqueira), piscina(piscina){}

Chacara :: ~Chacara(){}

//Getters
bool Chacara :: getSalaoFesta() const{
    return salao_festa;
}
bool Chacara :: getSalaoJogos() const{
    return salao_jogos;
}
bool Chacara :: getCampoFutebol() const{
    return campo_futebol;
}
bool Chacara :: getChurrasqueira() const{
    return churrasqueira;
}
bool Chacara :: getPiscina() const{
    return piscina;
}

//Setters
void Chacara :: setSalaoFesta(bool salao_festa){
    this->salao_festa = salao_festa;
}
void Chacara :: setSalaoJogos(bool salao_jogos){
    this->salao_jogos = salao_jogos;
}
void Chacara :: setCampoFutebol(bool campo_futebol){
    this->campo_futebol = campo_futebol;
}
void Chacara :: setChurrasqueira(bool churrasqueira){
    this->churrasqueira = churrasqueira;
}
void Chacara :: setPiscina(bool piscina){
    this->piscina = piscina;
}

void Chacara :: saida (ostream &out) const{
    Imovel :: saida(out);
    if (piscina){
        out << "Tem piscina\n-----\n";
    }
    else{
        out << "Não tem piscina\n-----\n";
    }
}

ostream& operator<<(ostream &out, const Chacara &obj){
    obj.saida(out);
    return out;
}