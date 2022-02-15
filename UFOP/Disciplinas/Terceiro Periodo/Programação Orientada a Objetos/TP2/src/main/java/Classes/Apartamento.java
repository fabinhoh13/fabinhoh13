package Classes;
/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
/**
 *
 * @author fabio, igor and pedro
 */

// Sub Classe Apartamento
// Classe que vem a partir da classe Imóvel
public class Apartamento extends Imovel{
    //Além de ter os atributos de Imóvel, tem também os atributos que dizem respeito ao
    private int andar; // Andar em que está o apartamento
    private double taxa_condominio; // Taxa do condomínio a ser paga mensalmente
    private boolean elevador; // A presença ou não de elevador no prédio
    private boolean sacada; // A presença ou não de sacada no apartamento

    // Método que formata todos os dados da classe em String, para que possam ser impressos posteriormente
    @Override
    public String toString() {
        String separador = "-----\n";
        // Característica especial do apartamento: presença ou não de elevador no prédio
        // Por ser um boolean, verifico se é true ou false, e crio a String a partir disso
        if (elevador) {
            // Se tiver elevador, a minha String terá os dados do Imóvel + a confirmação do elevador
            return super.toString() + "Tem Elevador\n" + separador;
        }
        // Se não tiver elevador, a minha String terá os dados do Imóvel + a confirmação de não ter elevador
        return super.toString() + "Não tem Elevador\n" + separador;     
    }
    
    // Construtor Vazio para a subclasse Apartamento
    public Apartamento() {
    }

    // Construtor Completo para a subclasse Apartamento
    public Apartamento(double valor, String proprietario, String rua, String bairro, String cidade, int numero, int quartos, int banheiros, int andar, double taxa_condominio, boolean elevador, boolean sacada) {
        // Primeiro ele pega todos os dados para criar a superclasse Imóvel e chamo o construtor completo dele
        super(valor, proprietario, rua, bairro, cidade, numero, quartos, banheiros);
        // Agora eu faço as atribuições dessa subclasse de acordo com seus atributos e os atributos passados
        this.andar = andar;
        this.taxa_condominio = taxa_condominio;
        this.elevador = elevador;
        this.sacada = sacada;
    }
    
    // Setters
    
    public void setAndar(int andar) {
        this.andar = andar;
    }

    public void setTaxa_condominio(double taxa_condominio) {
        this.taxa_condominio = taxa_condominio;
    }

    public void setElevador(boolean elevador) {
        this.elevador = elevador;
    }

    public void setSacada(boolean sacada) {
        this.sacada = sacada;
    }
    
    // Getters
    
    public int getAndar() {
        return andar;
    }

    public double getTaxa_condominio() {
        return taxa_condominio;
    }

    public boolean isElevador() {
        return elevador;
    }

    public boolean isSacada() {
        return sacada;
    }
    
}
