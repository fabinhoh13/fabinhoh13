// Created by Igor Santiago - 19.1.4033 and Fábio Fernandes - 19.1.4128  on 11/2021.

#include "funcoes.h"

vector<Imovel*> lerArquivo() {
    
    vector<Imovel*> imoveis;
    
    ifstream saida;
    saida.open("../database_imoveis.txt");

    string linha; char delimitador = ';';
    
    vector<string> words{};
    
    while (getline (saida, linha, '\n')){
        
        istringstream sstream(linha);
        string word;
        
        while (getline(sstream, word, delimitador)) {
           words.push_back(word);
        }

        string tipoImovel = words.at(0);
        
        //atributos de imovel
        
        int id = -1;
        float valor = stol(words.at(1)); 
        string proprietario = words.at(2);
        string rua = words.at(3);
        string bairro = words.at(4);
        string cidade = words.at(5); 
        int numero = stoi(words.at(6));
        int quartos = stoi(words.at(7)); 
        int banheiros = stoi(words.at(8));

        if (tipoImovel == "apartamento") {
            int andar = stoi(words.at(9));
            float taxa_condominio = stof(words.at(10));
            int elevador = stoi(words.at(11));
            int sacada = stoi(words.at(12)); 
            Apartamento *novoApartamento = new Apartamento (id, valor, proprietario, rua, bairro, 
                                                            cidade, numero, quartos, banheiros, 
                                                            andar, taxa_condominio, elevador, sacada);
            imoveis.push_back (novoApartamento);
        }
        
        else if (tipoImovel == "casa"){
            int andares = stoi(words.at(9));
            int sala_jantar = stoi(words.at(10));
            Casa *novaCasa = new Casa (id, valor, proprietario, rua, bairro, cidade, numero, 
                                       quartos, banheiros, andares, sala_jantar);
            imoveis.push_back (novaCasa);
        }

        else if (tipoImovel == "chacara"){
            int salao_festa= stoi(words.at(9));
            int salao_jogos = stoi(words.at(10));
            int campo_futebol = stoi(words.at(11));
            int churrasqueira = stoi(words.at(12));
            Chacara *novaChacara = new Chacara (id, valor, proprietario, rua, bairro, cidade, 
                                                numero, quartos, banheiros, salao_festa, 
                                                salao_jogos, campo_futebol, churrasqueira);
            imoveis.push_back (novaChacara);
        }

        words.clear();
    }

    //criação do vector contendo os dados do arquivo
    saida.close();
    return imoveis;
}

bool propTemImovel(vector<Imovel*> imoveis, string proprietario){
    vector <Imovel*> retorno;
    for (auto i : imoveis){
        if (i->getProprietario() == proprietario){
            return true;
        }
    }
    return false;
}

vector<Imovel*> conjuntoValor (vector<Imovel*> imoveis, float numMaxValor){
    vector <Imovel*> retorno;
    for (auto i : imoveis){
        if (i->getValor() <= numMaxValor){
            retorno.push_back(i);
        }
    }
    return retorno;
}

vector<Imovel*> conjuntoQuartos (vector<Imovel*> imoveis, int numMaxQuartos){
    vector <Imovel*> retorno;
    for (auto i : imoveis){
        if (i->getQuartos() <= numMaxQuartos){
            retorno.push_back(i);
        }
    }
    return retorno;
}

vector<Imovel*> conjuntoTipoImovel (vector<Imovel*> imoveis, string tipoImovel){
    vector <Imovel*> retorno;

    for (auto i : imoveis){
        if (tipoImovel == "apartamento"){
            if (typeid(*i).name() == typeid(class Apartamento).name()){
                retorno.push_back(i);
            }   
        }

        else if (tipoImovel == "casa"){
            if (typeid(*i).name() == typeid(class Casa).name()){
                retorno.push_back(i);
            }   
        }

        else if (tipoImovel == "chacara"){
            if (typeid(*i).name() == typeid(class Chacara).name()){
                retorno.push_back(i);
            }   
        }
    }
    return retorno;
}

vector<Imovel*> conjuntoCidade (vector<Imovel*> imoveis, string cidade){
    vector <Imovel*> retorno;
    for (auto i : imoveis){
        if (i->getCidade().compare(cidade)){
            retorno.push_back(i);
        }
    }
    return retorno;
}

vector<int> iteradoresProprietario (vector<Imovel*> imoveis, string proprietario){
    vector<int> retorno;
    char proprietario_char[proprietario.length()+1];
    
    strcpy(proprietario_char, proprietario.c_str());
    int i = 0;
    for (auto item : imoveis){
        char proprietario_classe[item->getProprietario().length()+1];
        strcpy(proprietario_classe, item->getProprietario().c_str());
        if (strcmp(proprietario_char, proprietario_classe) == 0){
            retorno.push_back(i);
        }
        i++;
    }
    return retorno;
}

bool compararCrescente(const Imovel *l, const Imovel *r){
    return l->getValor() < r->getValor();
}

bool compararDecrescente(const Imovel *l, const Imovel *r){
    return l->getValor() > r->getValor();
}

void ImprTerminalOuArquivo (vector<Imovel*> imoveis, bool opcao){
    if (opcao){
        //terminal
        for (auto i : imoveis){
            //cout << *i;
            cout << "-----" << endl;
            cout << i->getProprietario() << endl;
            cout << i->getValor() << endl;
            cout << i->getQuartos() << endl;
            cout << i->getRua() << endl;
            cout << i->getBairro() << endl;
            cout << i->getCidade() << endl;
        
            if (typeid(*i).name() == typeid(class Apartamento).name()){
                Apartamento *ptr = dynamic_cast <Apartamento*>(i) ;
                if (ptr != nullptr ){
                    if (ptr->getElevador()){
                        cout << "Tem elevador\n";
                    }
                    else{
                        cout << "Não tem elevador\n";
                    }
                }
            }  
            else if (typeid(*i).name() == typeid(class Casa).name()){
                Casa *ptr = dynamic_cast <Casa*>(i) ;
                if (ptr != nullptr )
                    cout << ptr->getAndares() << "Andar(es)\n";
            }  
            if (typeid(*i).name() == typeid(class Chacara).name()){
                Chacara *ptr = dynamic_cast <Chacara*>(i) ;
                if (ptr != nullptr ){
                    if (ptr->getPiscina()){
                        cout << "Tem piscina\n";
                    }
                    else{
                        cout << "Não tem piscina\n";
                    }
                }
            }
            cout << "-----" << endl; 
        }
        
    }
    else{
        //arquivo
        ofstream saida;
        saida.open("../saida.txt");

        for (auto i : imoveis){
            //saida << *i;
            saida << "-----" << endl;
            saida << i->getProprietario() << endl;
            saida << i->getValor() << endl;
            saida << i->getQuartos() << endl;
            saida << i->getRua() << endl;
            saida << i->getBairro() << endl;
            saida << i->getCidade() << endl;
        
            if (typeid(*i).name() == typeid(class Apartamento).name()){
                Apartamento *ptr = dynamic_cast <Apartamento*>(i) ;
                if (ptr != nullptr ){
                    if (ptr->getElevador()){
                        saida << "Tem elevador\n";
                    }
                    else{
                        saida << "Não tem elevador\n";
                    }
                }
            }  
            else if (typeid(*i).name() == typeid(class Casa).name()){
                Casa *ptr = dynamic_cast <Casa*>(i) ;
                if (ptr != nullptr )
                    saida << ptr->getAndares() << " Andar(es)\n";
            }  
            if (typeid(*i).name() == typeid(class Chacara).name()){
                Chacara *ptr = dynamic_cast <Chacara*>(i) ;
                if (ptr != nullptr ){
                    if (ptr->getPiscina()){
                        saida << "Tem piscina\n";
                    }
                    else{
                        saida << "Não tem piscina\n";
                    }
                }
            }   
        
        }
        saida << "-----" << endl;
        saida.close();
    }
}