// Created by Igor Santiago - 19.1.4033 and Fábio Fernandes - 19.1.4128  on 11/2021.

#ifndef CASA_H
#define CASA_H

    #include "Imovel.h"

    using namespace std;

    class Casa : public Imovel{
        int andares;
        bool sala_jantar;

        public:

        Casa(int = 0, float = 0, string = "",  string = "",  string = "",  string = "", int = 0, int = 0, int = 0, int = 0, bool = false);
        virtual ~Casa();

        int getAndares() const;
        bool getSalaJantar() const;

        void setAndares(int);
        void setSalaJantar(bool);

        virtual void saida (ostream &) const;
        friend ostream& operator<<(ostream &, const Casa &);
    };

#endif