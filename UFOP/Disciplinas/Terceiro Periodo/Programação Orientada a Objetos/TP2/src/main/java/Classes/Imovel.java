package Classes;


/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author fabio, igor and pedro
 */

// Super Classe Imóvel, responsável por a principal classe dentre as subclasses descritas
// As subclasses são Apartamento, Casa e Chacara, cada uma tem os mesmos atributos de Imóvel
// Além de seus próprios atributos

// Os atributos de um Imóvel são o seu valor, o proprietário, o endereço (rua, bairro, cidade e número)
// Além do número de quartos e o número de banheiros 

public class Imovel implements Comparable<Imovel>{
    private double valor;
    private String proprietario;
    private String rua;
    private String bairro;
    private String cidade;
    private int numero;
    private int quartos;
    private int banheiros;

    //Construtor completo, onde eu passo todos os atributos presentes na classe e os atribuo à classe
    public Imovel(double valor, String proprietario, String rua, String bairro, String cidade, int numero, int quartos, int banheiros) {
        this.valor = valor;
        this.proprietario = proprietario;
        this.rua = rua;
        this.bairro = bairro;
        this.cidade = cidade;
        this.numero = numero;
        this.quartos = quartos;
        this.banheiros = banheiros;
    }
    // Construtor vazio
    public Imovel() {
    }

    // Método semelhante à sobrecarga do método cout em C++. Esse método é o responsável por transformar
    // Todos os atributos da classe em uma única String, formatado ao necessário
    @Override
    public String toString() {
        String separador = "-----\n";
        return separador + proprietario + "\n\t" + valor + "\n\t" + quartos + "\n\t" + rua + "\n\t" + bairro + "\n\t" + cidade + "\n\t";
    }

    // Setters

    public void setValor(double valor) {
        this.valor = valor;
    }

    public void setProprietario(String proprietario) {
        this.proprietario = proprietario;
    }

    public void setRua(String rua) {
        this.rua = rua;
    }

    public void setBairro(String bairro) {
        this.bairro = bairro;
    }

    public void setCidade(String cidade) {
        this.cidade = cidade;
    }

    public void setNumero(int numero) {
        this.numero = numero;
    }

    public void setQuartos(int quartos) {
        this.quartos = quartos;
    }

    public void setBanheiros(int banheiros) {
        this.banheiros = banheiros;
    }

    // Getters

    public double getValor() {
        return valor;
    }
    
    // Get específico para a ordenação
    public Double GetValor() {
        return valor;
    }

    public String getProprietario() {
        return this.proprietario;
    }

    public String getRua() {
        return rua;
    }

    public String getBairro() {
        return bairro;
    }

    public String getCidade() {
        return this.cidade;
    }

    public int getNumero() {
        return numero;
    }

    public int getQuartos() {
        return quartos;
    }

    public int getBanheiros() {
        return banheiros;
    }

    // Sobrecarga do CompareTo para Imóveis. Função usada para a ordenação
    @Override
    public int compareTo(Imovel o) {
        return this.GetValor().compareTo(o.GetValor());
    }
    
    
}
