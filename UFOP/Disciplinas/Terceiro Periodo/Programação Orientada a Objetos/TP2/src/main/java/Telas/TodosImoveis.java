/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/GUIForms/JFrame.java to edit this template
 */
package Telas;
import Classes.*;
/**
 *
 * @author fabio, igor and pedro
 */

// Essa tela é onde temos a opção de mostrar na tela todos os Imóveis ou salvá-los em um arquivo texto
// Como atributo, ela tem uma referência à TelaInicial, para que possamos deixá-la inativa 
public class TodosImoveis extends javax.swing.JFrame {

    /**
     * Creates new form TodosImoveis
     */
    
    TelaInicial tela;
    
    // Construtor para TodosImoveis
    public TodosImoveis() {
        initComponents();
    }
    
    // Construtor onde passamos a referência a TelaInicial
    public TodosImoveis(TelaInicial tela){
        this();
        this.tela = tela;
    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jButton1 = new javax.swing.JButton();
        jButton2 = new javax.swing.JButton();
        jScrollPane1 = new javax.swing.JScrollPane();
        jTextArea1 = new javax.swing.JTextArea();

        setDefaultCloseOperation(javax.swing.WindowConstants.DISPOSE_ON_CLOSE);
        setTitle("Mostrar os Imóveis");
        addWindowListener(new java.awt.event.WindowAdapter() {
            public void windowClosed(java.awt.event.WindowEvent evt) {
                formWindowClosed(evt);
            }
        });

        jButton1.setText("Salvar em Arquivo");
        jButton1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton1ActionPerformed(evt);
            }
        });

        jButton2.setText("Mostrar na Tela");
        jButton2.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton2ActionPerformed(evt);
            }
        });

        jTextArea1.setColumns(20);
        jTextArea1.setRows(5);
        jScrollPane1.setViewportView(jTextArea1);

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGap(51, 51, 51)
                .addComponent(jButton1)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 60, Short.MAX_VALUE)
                .addComponent(jButton2)
                .addGap(57, 57, 57))
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(jScrollPane1)
                .addContainerGap())
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(jScrollPane1, javax.swing.GroupLayout.DEFAULT_SIZE, 220, Short.MAX_VALUE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jButton1)
                    .addComponent(jButton2))
                .addGap(31, 31, 31))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void jButton1ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton1ActionPerformed
        // Esse botão chama a função que temos em FuncoesUteis, para salvar todos os Imóveis em um arquivo
        // Texto formatado
        
        // Para isso, usamos o getImoveis presente em TelaInicial
        FuncoesUteis.salva_aquivo_texto(tela.getImoveis());
    }//GEN-LAST:event_jButton1ActionPerformed

    private void jButton2ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton2ActionPerformed
        // Assim como na função salvar_arquivo_texto presente em FuncoesUteis, aqui fazemos todo o downcast
        // Para que possamos fazer a impressão na tela assim que o botão for acionado
        
        // Primeiro limpo o meu JTextArea
        jTextArea1.setText("");
        
        // percorro o meu ArrayList de Imóveis
        for (Imovel i : tela.getImoveis()) {
                // E vou escrevendo no JTextArea item por item, usando seus determinados getters
                jTextArea1.append("-----\n");
                jTextArea1.append(i.getProprietario());
                jTextArea1.append("\n\t" + i.getValor());
                jTextArea1.append("\n\t" + i.getRua());
                jTextArea1.append("\n\t" + i.getBairro());
                jTextArea1.append("\n\t" + i.getCidade());
                
                // Os próximos ifs são responsáveis por fazer o Downcast
                if (i instanceof Apartamento) {
                    // Caso for um Apartamento, escrevo o seu elemento especial
                    if (((Apartamento) i).isElevador()){
                        jTextArea1.append("\n\tTem Elevador");
                        jTextArea1.append("\n-----\n");
                    }
                    else {
                        jTextArea1.append("\n\tNão Tem Elevador");
                        jTextArea1.append("\n-----\n");
                    }
                }
                else if (i instanceof Casa) {
                    // Caso for uma Casa, escrevo o seu elemento especial
                        jTextArea1.append("\n\t" + ((Casa) i).getAndares() + " Andar(es)");
                        jTextArea1.append("\n-----\n"); 
                }
                else if (i instanceof Chacara) {
                    // Caso for uma Chacara, escrevo o seu elemento especial
                    if (((Chacara) i).isCampo_futebol()){
                        jTextArea1.append("\n\tTem Campo de Futebol");
                        jTextArea1.append("\n-----\n");
                    }
                    else {
                        jTextArea1.append("\n\tNão Tem Campo de Futebol");
                        jTextArea1.append("\n-----\n");
                    }
                } 
            }
    }//GEN-LAST:event_jButton2ActionPerformed

    private void formWindowClosed(java.awt.event.WindowEvent evt) {//GEN-FIRST:event_formWindowClosed
        // Quando a tela for fechada, a TelaPrincipal passa a estar ativa
        tela.setEnabled(true);
    }//GEN-LAST:event_formWindowClosed

    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        /* Set the Nimbus look and feel */
        //<editor-fold defaultstate="collapsed" desc=" Look and feel setting code (optional) ">
        /* If Nimbus (introduced in Java SE 6) is not available, stay with the default look and feel.
         * For details see http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html 
         */
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(TodosImoveis.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(TodosImoveis.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(TodosImoveis.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(TodosImoveis.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new TodosImoveis().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton jButton1;
    private javax.swing.JButton jButton2;
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JTextArea jTextArea1;
    // End of variables declaration//GEN-END:variables
}
