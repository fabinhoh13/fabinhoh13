// Created by Igor Santiago - 19.1.4033 and Fábio Fernandes - 19.1.4128  on 11/2021.

#include "Apartamento.h"

//Construtor e destrutor
Apartamento :: Apartamento (int id, float valor, string proprietario,  string rua,  string bairro,  
                            string cidade, int numero, int quartos, int banheiros, int andar, 
                            float taxa_condominio, bool elevador, bool sacada):
    Imovel(id, valor, proprietario, rua, bairro, cidade, numero, quartos, banheiros), 
           andar(andar), taxa_condominio(taxa_condominio), elevador(elevador), sacada(sacada){}

Apartamento :: ~Apartamento(){}

//Getters
int Apartamento :: getAndar() const{
    return andar;
}
float Apartamento :: getTaxaCondominio() const{
    return taxa_condominio;
}
bool Apartamento :: getElevador() const{
    return elevador;
}
bool Apartamento :: getSacada() const{
    return sacada;
}

//Setters
void Apartamento :: setAndar(int andar){
    this->andar = andar;
}
void Apartamento :: setTaxaCondominio(float taxa_condominio){
    this->taxa_condominio = taxa_condominio;
}
void Apartamento :: setElevador(bool elevador){
    this->elevador = elevador;
}
void Apartamento :: setSacada(bool sacada){
    this->sacada = sacada;
}

void Apartamento :: saida (ostream & out) const{
    Imovel :: saida(out);
    if (elevador){
        out << "Tem elevador\n-----\n";
    }
    else{
        out << "Não tem elevador\n-----\n";
    }
}

ostream& operator << (ostream &out, const Apartamento &obj){
    obj.saida(out);
    return out;
}