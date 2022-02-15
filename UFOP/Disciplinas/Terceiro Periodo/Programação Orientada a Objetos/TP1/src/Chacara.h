// Created by Igor Santiago - 19.1.4033 and Fábio Fernandes - 19.1.4128  on 11/2021.

#ifndef CHACARA_H
#define CHACARA_H

    #include "Imovel.h"

    using namespace std;

    class Chacara : public Imovel{
        bool salao_festa;
        bool salao_jogos;
        bool campo_futebol;
        bool churrasqueira;
        bool piscina;

        public:

        Chacara (int = 0, float = 0, string = "",  string = "",  string = "",  string = "", int = 0, int = 0, int = 0, bool = false, bool = false, bool = false, bool = false, bool = false);
        virtual ~Chacara();

        bool getSalaoFesta() const;
        bool getSalaoJogos() const;
        bool getCampoFutebol() const;
        bool getChurrasqueira() const;
        bool getPiscina() const;

        void setSalaoFesta(bool);
        void setSalaoJogos(bool);
        void setCampoFutebol(bool);
        void setChurrasqueira(bool);
        void setPiscina(bool);
        

        virtual void saida (ostream &) const;
        friend ostream& operator<<(ostream &, const Chacara &);
    };

#endif