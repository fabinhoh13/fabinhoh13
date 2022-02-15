/* 
    01 Trabalho Prático - BCC221 (Programação Orientada à Objeto)
    Alunos: 
        * Fábio Fernandes - 19.1.4128
        * Igor Santiago - 19.1.4033
    Professor:
        * Guilhermo Cámara Chávez
*/

#include "funcoes.h"

int main(){

    vector<Imovel*> imoveis = lerArquivo();
    
    int questao;
    
    cout << "Qual questão deseja executar: ";
    cin >> questao;
    
    switch (questao){
        case 1: {
            for (auto i : imoveis) {
                cout << *i;
            }
            break;
        }
        case 2: {
            string proprietario;
            cout << "Digite o nome do proprietário: ";
            cin >> proprietario;
            if (propTemImovel (imoveis, proprietario)) {
                cout << "O proprietário tem pelo menos um imóvel" << endl;
            }
            else {
                cout << "O proprietário não tem imóvel" << endl;
            }
            break;
        }
        case 3: {
            vector <Imovel*> conjuntoMaioresQueX;
            float x;
            cout << "Digite o valor máximo: ";
            cin >> x;
            conjuntoMaioresQueX = conjuntoValor (imoveis, x);
            for (auto i : conjuntoMaioresQueX) {
                cout << *i;
            }
            break;
        }
        case 4: {
            int nQuartos;
            cout << "Digite o número máximo de quartos: ";
            cin >>nQuartos;
            vector <Imovel*> conjunto_Quartos = conjuntoQuartos(imoveis, nQuartos);
            for(auto i : conjunto_Quartos){
                cout << *i;
            }
            break;
        }
        case 5: {
            vector <Imovel*> conjuntoDeUmTipo;
            string tipo_imovel;
            cout << "Digite o tipo de imóvel: ";
            cin >> tipo_imovel;
            conjuntoDeUmTipo = conjuntoTipoImovel (imoveis, tipo_imovel);
            sort(conjuntoDeUmTipo.begin(), conjuntoDeUmTipo.end(), compararCrescente);

            for (auto i : conjuntoDeUmTipo) {
                cout << *i;
            }
            break;

        }
        case 6: {
            vector <Imovel*> conjuntoDeUmaCidade;
            string cidade;
            cout << "Digite a cidade: ";
            cin >> cidade;
            conjuntoDeUmaCidade = conjuntoTipoImovel (imoveis, cidade);
            sort(conjuntoDeUmaCidade.begin(), conjuntoDeUmaCidade.end(), compararDecrescente);

            for (auto i : conjuntoDeUmaCidade) {
                cout << *i;
            }
            break;

        }
        case 7: {
            vector <int> iteradores;
            string proprietario;
            cout << "Digite o proprietário: ";
            cin >> proprietario;

            iteradores = iteradoresProprietario (imoveis, proprietario);
            for (auto i : iteradores) {
                cout << *(imoveis.at(i));
            }
            break;
        }
        case 8: {
            string opcao;
            cout << "terminal ou arquivo? ";
            cin >> opcao;
            if(opcao == "terminal") {
                ImprTerminalOuArquivo(imoveis, true);
            }
            else if (opcao == "arquivo") {
                ImprTerminalOuArquivo(imoveis, false);
            }else
                cout << "Opcao inválida" << endl;
        }
            
    }

    for (auto i : imoveis) {
        delete i;
    }

    return 0;
}

