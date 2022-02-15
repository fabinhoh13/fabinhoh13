package Classes;
/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author fabio, igor and pedro
 */
// Sub Classe Casa
// Classe que vem a partir da classe Imóvel
public class Chacara extends Imovel{
    //Além de ter os atributos de Imóvel, tem também os atributos que dizem respeito a
    private boolean salao_festa; // Presença ou não de salão de Festa
    private boolean salao_jogos; // Presença ou não de Salão de Jogos
    private boolean campo_futebol; // Presença ou não de Campo de Futebol
    private boolean churrasqueira; // Presença ou não de Churrasqueira
    private boolean piscina;  // Presença ou não de Piscina
    
    // Método que formata todos os dados da classe em String, para que possam ser impressos posteriormente
    @Override
    public String toString() {
        String separador = "-----\n";
        // Característica especial do apartamento: Presença ou não de Piscina
        if (piscina) {
            // Se tiver piscina, a minha String terá os dados do Imóvel + a confirmação da piscina
            return super.toString() + "Tem Piscina\n" + separador;
        }
        // Se não tiver piscina, a minha String terá os dados do Imóvel + a confirmação de não ter piscina
        return super.toString() + "Não tem Piscina\n" + separador;     
    }

    // Construtor Completo para a subclasse Chácara
    public Chacara(double valor, String proprietario, String rua, String bairro, String cidade, int numero, int quartos, int banheiros, boolean salao_festa, boolean salao_jogos, boolean campo_futebol, boolean churrasqueira, boolean piscina) {
        // Primeiro ele pega todos os dados para criar a superclasse Imóvel e chamo o construtor completo dele
        super(valor, proprietario, rua, bairro, cidade, numero, quartos, banheiros);
        // Agora eu faço as atribuições dessa subclasse de acordo com seus atributos e os atributos passados
        this.salao_festa = salao_festa;
        this.salao_jogos = salao_jogos;
        this.campo_futebol = campo_futebol;
        this.churrasqueira = churrasqueira;
        this.piscina = piscina;
    }
    
    // Construtor Vazio
    public Chacara() {
    }
    
    // Setters
    
    public void setSalao_festa(boolean salao_festa) {
        this.salao_festa = salao_festa;
    }

    public void setSalao_jogos(boolean salao_jogos) {
        this.salao_jogos = salao_jogos;
    }

    public void setCampo_futebol(boolean campo_futebol) {
        this.campo_futebol = campo_futebol;
    }

    public void setChurrasqueira(boolean churrasqueira) {
        this.churrasqueira = churrasqueira;
    }

    public void setPiscina(boolean piscina) {
        this.piscina = piscina;
    }
    
    // Getters

    public boolean isSalao_festa() {
        return salao_festa;
    }

    public boolean isSalao_jogos() {
        return salao_jogos;
    }

    public boolean isCampo_futebol() {
        return campo_futebol;
    }

    public boolean isChurrasqueira() {
        return churrasqueira;
    }

    public boolean isPiscina() {
        return piscina;
    }
    
}
