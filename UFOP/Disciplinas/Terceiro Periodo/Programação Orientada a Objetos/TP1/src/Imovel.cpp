// Created by Igor Santiago - 19.1.4033 and Fábio Fernandes - 19.1.4128  on 11/2021.

#include "Imovel.h"

//Construtor e destrutor
Imovel :: Imovel (int id, float valor, string proprietario, string rua, string bairro, 
                  string cidade, int numero, int quartos, int banheiros):
    id(id), valor(valor), proprietario(proprietario), rua(rua), bairro(bairro), cidade(cidade), 
    numero(numero), quartos (quartos), banheiros(banheiros) {}

Imovel :: ~Imovel() {}

//Getters
int Imovel :: getId () const {
    return id;
}
float Imovel :: getValor() const {
    return valor;
}
string Imovel :: getProprietario() const {
    return proprietario;
}
string Imovel :: getRua() const {
    return rua;
}
string Imovel :: getBairro() const {
    return bairro;
}
string Imovel :: getCidade() const {
    return cidade;
}
int Imovel :: getNumero () const {
    return numero;
}
int Imovel :: getQuartos () const {
    return quartos;
}
int Imovel :: getBanheiros () const {
    return banheiros;
}

//Setters
void Imovel :: setId (int id) {
    this->id = id;
}
void Imovel :: setValor(float valor) {
    this->valor = valor;
}
void Imovel :: setProprietario(string proprietario) {
    this->proprietario = proprietario;
}
void Imovel :: setRua(string rua) {
    this->rua = rua;
}
void Imovel :: setBairro(string bairro) {
    this->bairro = bairro;
}
void Imovel :: setCidade(string cidade) {
    this->cidade = cidade;
}
void Imovel :: setNumero (int numero) {
    this->numero = numero;
}
void Imovel :: setQuartos (int quartos) {
    this->quartos = quartos;
}
void Imovel :: setBanheiros (int banheiros) {
    this->banheiros = banheiros;
}


bool Imovel :: operator<(const Imovel& other) {
    return valor < other.valor;
}

bool Imovel :: operator>(const Imovel& other) {
    return valor > other.valor;
}


bool Imovel :: ordenaCrescente (Imovel a, Imovel b){
    if (a.valor > b.valor)
        return true;
    return false;
}

bool Imovel :: ordenaDecrescente (Imovel a, Imovel b){
    if (a.valor < b.valor)
        return true;
    return false;
}

void Imovel :: saida (ostream & out) const {
    out << "-----\n" 
        << proprietario << "\n\t" 
        << valor << "\n\t" 
        << quartos << "\n\t" 
        << rua << "\n\t" 
        << bairro << "\n\t" 
        << cidade << "\n\t";
}

ostream& operator<<(ostream &out, const Imovel &obj) {
    obj.saida(out);
    return out;
}