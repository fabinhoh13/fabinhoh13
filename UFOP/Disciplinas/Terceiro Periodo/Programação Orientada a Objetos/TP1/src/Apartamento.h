// Created by Igor Santiago - 19.1.4033 and Fábio Fernandes - 19.1.4128  on 11/2021.

#ifndef APARTAMENTO_H
#define APARTAMENTO_H

    #include "Imovel.h"

    using namespace std;

    class Apartamento : public Imovel{
        int andar;
        float taxa_condominio;
        bool elevador;
        bool sacada;

        public: 

        Apartamento (int = 0, float = 0, string = "",  string = "",  string = "",  string = "", int = 0, int = 0, int = 0, int = 0, float = 0, bool = false, bool = false);
        virtual ~Apartamento();

        int getAndar() const;
        float getTaxaCondominio() const;
        bool getElevador() const;
        bool getSacada() const;

        void setAndar(int);
        void setTaxaCondominio(float);
        void setElevador(bool);
        void setSacada(bool);

        virtual void saida (ostream &) const;
        friend ostream& operator<<(ostream &, const Apartamento &);
    };

#endif