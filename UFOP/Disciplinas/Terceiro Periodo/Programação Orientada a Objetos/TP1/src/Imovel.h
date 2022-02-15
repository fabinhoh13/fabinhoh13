// Created by Igor Santiago - 19.1.4033 and Fábio Fernandes - 19.1.4128  on 11/2021.

#ifndef IMOVEL_H
#define IMOVEL_H

    #include <string>
    #include <iostream>

    using namespace std;

    class Imovel{
        int id;
        float valor;
        string proprietario;
        string rua;
        string bairro;
        string cidade;
        int numero;
        int quartos;
        int banheiros;

        public:
        Imovel (int = 0, float = 0, string = "",  string = "",  string = "",  string = "", 
                int = 0, int = 0, int = 0);
        virtual ~Imovel();


        int getId () const;
        float getValor() const;
        string getProprietario() const;
        string getRua() const;
        string getBairro() const;
        string getCidade() const;
        int getNumero () const;
        int getQuartos () const;
        int getBanheiros () const;

        void setId (int);
        void setValor(float);
        void setProprietario(string);
        void setRua(string);
        void setBairro(string);
        void setCidade(string);
        void setNumero (int);
        void setQuartos (int);
        void setBanheiros (int);

        bool operator<(const Imovel& other);
        bool operator>(const Imovel& other);

        bool ordenaCrescente (Imovel a, Imovel b);
        bool ordenaDecrescente (Imovel a, Imovel b);

        

        virtual void saida (ostream &) const;
        friend ostream& operator<<(ostream &, const Imovel &);

    };

#endif
