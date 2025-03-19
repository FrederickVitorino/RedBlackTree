#include<iostream>
enum Cor { VERMELHO, PRETO };

class No{
private:
    //Definicao dos atributos privados
    int valor;
    Cor cor;
    No* pai;
    No* esquerda;
    No* direita;

public:
    //Construtor
    No(int valor);
    //Destrutor
    ~No();
    //Definicao dos metodos da classe
    int getValor();
    Cor getCor();
    No* getPai();
    No* getEsquerda();
    No* getDireita();
    void setValor(int novoValor);
    void setCor(Cor novaCor);
    void setPai(No* novoPai);
    void setEsquerda(No* novaEsquerda);
    void setDireita(No* novaDireita);
};