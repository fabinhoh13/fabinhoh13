package Classes;

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
import java.util.*;
import Telas.*;
import Classes.*;

/**
 *
 * @author fabio, igor and pedro
 */
public class Main {
    
    public static void main (String[] args){
        // Uso a minha função leArquivo, que lê o meu arquivo database e me retorna um ArrayList
        // Com todas os objetos criados a partir do arquivo
        ArrayList <Imovel> imoveis = FuncoesUteis.leArquivo();
        // Faço a referência a TelaInicial e a torno visível
        TelaInicial telaInicial = new TelaInicial(imoveis);
        telaInicial.setVisible(true);  
    }
}
