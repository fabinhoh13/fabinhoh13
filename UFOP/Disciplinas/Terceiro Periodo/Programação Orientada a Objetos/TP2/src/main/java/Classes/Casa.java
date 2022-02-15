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
public class Casa extends Imovel{
    //Além de ter os atributos de Imóvel, tem também os atributos que dizem respeito ao
    private int andares; // Número de andares que a casa tem
    private boolean sala_jantar; // A presença ou não de uma sala de jantar

    // Construtor Completo para a subclasse Casa
    public Casa(double valor, String proprietario, String rua, String bairro, String cidade, int numero, int quartos, int banheiros, int andares, boolean sala_jantar) {
        // Primeiro ele pega todos os dados para criar a superclasse Imóvel e chamo o construtor completo dele
        super(valor, proprietario, rua, bairro, cidade, numero, quartos, banheiros);
        // Agora eu faço as atribuições dessa subclasse de acordo com seus atributos e os atributos passados
        this.andares = andares;
        this.sala_jantar = sala_jantar;
    }
    
    // Construtor Vazio para a subclasse Casa
    public Casa() {
    }

    // Método que formata todos os dados da classe em String, para que possam ser impressos posteriormente
    @Override
    public String toString() {
        String separador = "-----\n";
        // Característica especial do apartamento: Quantos andares tem a casa
        return super.toString() + andares + " Andar(es)\n" + separador;
        // Passo junto a string quantos andares tem dentro da casa
    }
    
    // Setters
    
    public void setAndares(int andares) {
        this.andares = andares;
    }

    public void setSala_jantar(boolean sala_jantar) {
        this.sala_jantar = sala_jantar;
    }
    
    // Getters

    public int getAndares() {
        return andares;
    }

    public boolean isSala_jantar() {
        return sala_jantar;
    }
    
}
