package Classes;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Iterator;
import javax.swing.JOptionPane;

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author fabio, igor and pedro
 */

// Classe que tem todas as funções necessárias para o funcionamento do programa
public class FuncoesUteis {
    
    // Função que pega um inteiro 1 ou 0 e transforma em boolean
    public static boolean conversor (int a) {
        return a == 1;
    }
    
    // Função que lê o arquivo com todas as informações e o transforma em um ArrayList de Imoveis
    public static ArrayList <Imovel> leArquivo (){
        Apartamento novoAp;
        Casa novaCasa;
        Chacara novaChacara;
        
        // Todos os objetos criados dentro dessa função serão armazenados dentro de um ArrayList
        ArrayList <Imovel> imoveis = new ArrayList<> ();
        
        // Faço a leitura dentro de um try para obter qualquer excessão lançada durante a leitura
        try {
            //Indicamos o arquivo a partir de seu caminho relativo
            File caminhoDoTexto = new File("src/main/java/database_imoveis.txt");

            // Fazemos a abertura do arquivo usando o método de leitura FileReader
            FileReader lerCaminhoDoTexto = new FileReader(caminhoDoTexto);

            // Criamos o objeto BufferedReader que nos oferece o método de leitura readLine()
            BufferedReader lerArquivo = new BufferedReader(lerCaminhoDoTexto);


            // Esse while lê o arquivo linha por linha, até a sua última linha
            while (lerArquivo.ready()) {
                // Leio as linhas com o método readLine
                String texto = lerArquivo.readLine();
                // Jogamos dentro do vetor de strings textoSplit todas as strings formadas
                // A partir da separação de cada linha lida do arquivo usando o separador ';'
                // Para isso usamos o método split, que, a partir de um separador, cria um vetor de strings e o retorna
                String textoSplit [] = texto.split(";");
                
                // Com isso, vou em cada posição do meu vetor e retiro os dados necessários para a criação dos objetos
                double valor = Double.parseDouble(textoSplit[1]); 
                String proprietario = textoSplit[2];
                String rua = textoSplit[3];
                String bairro = textoSplit[4];
                String cidade = textoSplit[5]; 
                int numero = Integer.parseInt(textoSplit[6]);
                int quartos = Integer.parseInt(textoSplit[7]); 
                int banheiros = Integer.parseInt(textoSplit[8]);
                
                // Agora, de acordo com a primeira informação de cada linha, eu vejo qual linha é um apartamento, ou casa,
                // Ou chacara, e crio meus objetos
                if (textoSplit[0].equals("apartamento")){
                    int andar = Integer.parseInt(textoSplit[9]);
                    double taxa_condominio = Double.parseDouble(textoSplit[10]);
                    boolean elevador = conversor(Integer.parseInt(textoSplit[11]));
                    boolean sacada = conversor(Integer.parseInt(textoSplit[12]));
                    
                    novoAp = new Apartamento (valor, proprietario, rua, bairro, cidade, numero, quartos, banheiros, andar, taxa_condominio, elevador, sacada);
                    // Adiciono o novo objeto dentro do meu ArrayList
                    imoveis.add(novoAp);
                } 
                else if(textoSplit[0].equals("casa")){
                    int andares = Integer.parseInt(textoSplit[9]);
                    boolean sala_jantar = conversor(Integer.parseInt(textoSplit[10]));
                    
                    novaCasa = new Casa (valor, proprietario, rua, bairro, cidade, numero, quartos, banheiros, andares, sala_jantar);
                    // Adiciono o novo objeto dentro do meu ArrayList
                    imoveis.add(novaCasa);
                } 
                else if (textoSplit[0].equals("chacara")){
                    boolean salao_festa = conversor(Integer.parseInt(textoSplit[9]));
                    boolean salao_jogos = conversor(Integer.parseInt(textoSplit[10]));
                    boolean campo_futebol = conversor(Integer.parseInt(textoSplit[11]));
                    boolean churrasqueira = conversor(Integer.parseInt(textoSplit[12]));
                    boolean piscina = conversor(Integer.parseInt(textoSplit[13]));
                    
                    novaChacara = new Chacara (valor, proprietario, rua, bairro, cidade, numero, quartos, banheiros, salao_festa, salao_jogos, campo_futebol, churrasqueira, piscina);
                    // Adiciono o novo objeto dentro do meu ArrayList
                    imoveis.add(novaChacara);
                }


            }
            // Fecho o arquivo de leitura
            lerArquivo.close();

        } catch (IOException e) {
            // Caso seja lançada alguma excessão, aqui ela será tratada
            System.out.println("Arquivo não encontrado");

        }
        // Ao final, independente se tiver ou não alguma excessão, retornamos o ArrayList
        // Seja ele vazio, ou com objetos criados a partir do arquivo
        return imoveis;
    }
    
    // Função que retorna se determinado priprietário tem ou não imóvel cadastrado
    public static boolean proprietario_tem_imovel(ArrayList <Imovel> imoveis, String proprietario){
        for (Imovel i : imoveis){
            // Procuro dentro do meu ArrayList de imoveis, qual tem o mesmo nome que foi passado por
            // Valor
            if (i.getProprietario().equals(proprietario)){
                // Se eu encontro pelo menos um imóvel que seja desse proprietário, retorno true
                return true;
            }
        }
        // Se não for encontrado em nenhum imóvel, retorno false
        return false;
    }
    
    // Função que retorna um conjunto com Imóveis que tem valor menor ou igual a determinado valor
    public static ArrayList <Imovel> conjunto_valor(ArrayList <Imovel> imoveis, double valor_max){
        // ArrayList que vai receber todos os imóveis que tem valor menor ou igual a "valor_max"
        ArrayList <Imovel> retorno = new ArrayList<> ();
        for (Imovel i : imoveis){
            // Procuro dentro do ArrayList que contém todos os imóveis
            if (i.getValor() <= valor_max){
                // Os que tiverem o valor menor ou igual ao estabelecido em "valor_max" são
                // Inseridos no meu ArrayList de retorno
                retorno.add(i);
            }
        }
        // Logo após, eu retorno esse ArrayList, seja ele vazio ou com os imóveis selecionados
        return retorno;
    }

    // Funçõ que retorna um conjunto de Imóveis com um número de quarto menor ou igual ao determinado
    public static ArrayList <Imovel> conjunto_quartos (ArrayList <Imovel> imoveis, int numMaxQuartos){
        // ArrayList que vai receber todos os imóveis que tem um numero de quartos menor ou igual 
        // a "numMaxQuartos"
        ArrayList <Imovel> retorno = new ArrayList<> ();
        for (Imovel i : imoveis){
            // Procuro dentro do ArrayList que contém todos os imóveis
            if (i.getQuartos() <= numMaxQuartos){
                // Os que tiverem o numero de quartos menor ou igual ao estabelecido em "numMaxQuartos" são
                // Inseridos no meu ArrayList de retorno
                retorno.add(i);
            }
        }
        // Logo após, eu retorno esse ArrayList, seja ele vazio ou com os imóveis selecionados
        return retorno;
    }

    // Função que retorna um conjunto de Imóveis que são de determinada cidade
    public static ArrayList <Imovel> conjunto_cidade (ArrayList <Imovel> imoveis, String cidade){
        // ArrayList que recebe todos os imóveis que são da mesma cidade especificada em "cidade"
        ArrayList <Imovel> retorno = new ArrayList<> ();
        for (Imovel i : imoveis){
            // Procuro dentro do meu ArrayList de imoveis, qual tem o mesmo nome que foi passado por
            // Valor
            if (i.getCidade().equals(cidade)){
                retorno.add(i);
            }
        }
        return retorno;
    }
    
    // Função que retorna um conjunto com todos os Aparamentos
    public static ArrayList <Imovel> conjunto_apartamento (ArrayList <Imovel> imoveis) {
        // ArrayList que guarda todos os Apartamentos
        ArrayList <Imovel> retorno = new ArrayList<> ();
        // Usarei o método instanceof que retorna se determinado objeto pertence a determinada classe
        for (Imovel i : imoveis) {
            // Se for um Apartamento, ela será adicionada ao ArrayList
            if (i instanceof Apartamento) {
                retorno.add (i);
            }
        }
        // Ao final, retorno o ArrayList
        return retorno;
    }
    
    // Função que retorna um conjunto com todos as Casas
    public static ArrayList <Imovel> conjunto_casa (ArrayList <Imovel> imoveis) {
        // ArrayList que guarda todos as Casas
        ArrayList <Imovel> retorno = new ArrayList<> ();
        // Usarei o método instanceof que retorna se determinado objeto pertence a determinada classe
        for (Imovel i : imoveis) {
            // Se for uma Casa, ela será adicionada ao ArrayList
            if (i instanceof Casa) {
                retorno.add (i);
            }
        }
        // Ao final, retorno o ArrayList
        return retorno;
    }
    
    // Função que retorna um conjunto com todos as Chacaras
    public static ArrayList <Imovel> conjunto_chacara (ArrayList <Imovel> imoveis) {
        // ArrayList que guarda todos as Cahacara
        ArrayList <Imovel> retorno = new ArrayList<> ();
        // Usarei o método instanceof que retorna se determinado objeto pertence a determinada classe
        for (Imovel i : imoveis) {
            // Se for uma Chacara, ela será adicionada ao ArrayList
            if (i instanceof Chacara) {
                retorno.add (i);
            }
        }
        // Ao final, retorno o ArrayList
        return retorno;
    }
    
    // Função que retorna um ou mais imóveis que tem determinado número de endereço
    public static ArrayList <Imovel> conjunto_numero_imovel (ArrayList <Imovel> imoveis, int numero) {
        // ArrayList que irá conter os Imóveis que tem o determinado número de endereço
        ArrayList <Imovel> retorno = new ArrayList<> ();
        // Percorro dentro do ArrayList e procuro pelo número
        for (Imovel i : imoveis) {
            if (i.getNumero() == numero) {
                retorno.add (i);
            }
        }
        // Retorno todos os imóveis que foram encontrados
        return retorno;
    }
    
    // Função que retorna os iteradores onde, no meu ArrayList imoveis estão presentes os Imóveis de 
    // Determinado proprietário
    public static ArrayList <Integer> conjunto_iteradores(ArrayList <Imovel> imoveis, String proprietario){
        // ArrayList que ficarão os iteradores
        ArrayList <Integer> retorno = new ArrayList<> ();
        // Usaremos os iteradores como inteiros, por ser mais fácil trabalhar assim
        
        int contador = 0; // Contador responsável por determinar em qual iterador que está o Imóvel desejado
        for (Imovel i : imoveis) {
            // Procuro dentro do meu ArrayList de imoveis, qual tem o mesmo nome que foi passado por
            // Valor
            if (i.getProprietario().equals(proprietario)){
                // Se eu encontro um imóvel que seja desse proprietário, adiciono no ArrayList de retorno
                retorno.add(contador);
            }
            // Incremento em +1 o meu contador
            contador++;
        }
        // Retorno o meu ArrayList com os iteradores
        return retorno;
    }
    
    // Função que faz o Downcast e salva dentro do arquivo texto "saida.txt"
    public static void salva_aquivo_texto(ArrayList <Imovel> imoveis){
        // Determino onde está o meu arquivo de saída
        File caminhoDoTexto = new File("src/main/java/saida.txt");
        // Faço um try para que caso ocorra erros na escrita do arquivo, seja tratada como uma excessão
        try (FileWriter fw = new FileWriter (caminhoDoTexto)){
            
            // percorro o meu ArrayList de Imóveis
            for (Imovel i : imoveis) {
                // E vou escrevendo no arquivo item por item, usando seus determinados getters
                fw.write("-----\n");
                fw.write(i.getProprietario());
                fw.write("\n\t" + i.getValor());
                fw.write("\n\t" + i.getRua());
                fw.write("\n\t" + i.getBairro());
                fw.write("\n\t" + i.getCidade());
                
                // Os próximos ifs são responsáveis por fazer o Downcast
                if (i instanceof Apartamento) {
                    // Caso for um Apartamento, escrevo o seu elemento especial
                    if (((Apartamento) i).isElevador()){
                        fw.write("\n\tTem Elevador");
                        fw.write("\n-----\n");
                    }
                    else {
                        fw.write("\n\tNão Tem Elevador");
                        fw.write("\n-----\n");
                    }
                }
                else if (i instanceof Casa) {
                    // Caso for uma Casa, escrevo o seu elemento especial
                        fw.write("\n\t" + ((Casa) i).getAndares() + " Andar(es)");
                        fw.write("\n-----\n"); 
                }
                else if (i instanceof Chacara) {
                    // Caso for uma Casa, escrevo o seu elemento especial
                    if (((Chacara) i).isCampo_futebol()){
                        fw.write("\n\tTem Campo de Futebol");
                        fw.write("\n-----\n");
                    }
                    else {
                        fw.write("\n\tNão Tem Campo de Futebol");
                        fw.write("\n-----\n");
                    }
                } 
            }
            // Fecho o arquivo, independe ou não de sucesso
            fw.close();
        }catch (IOException ex){
            // Caso ocorra um erro, eu dou um catch nessa excessão e mostro na tela uma mensagem de erro
            // Usando um JOptionPane, que é uma janelinha de notificação
            JOptionPane.showMessageDialog(null, "Falha ao escrever no arquivo!");
        }
        // Caso ocorra tudo com sucesso, abro uma JOptionPane como mensagem de sucesso
        JOptionPane.showMessageDialog(null, "Arquivo escrito com sucesso!");
    }
    
}
