#include<iostream>
#include "No.cpp"
class ArvoreRB{
private:
    //Definicao dos atributos e metodos privados da classe
    No* raiz;
    void swapCores(No* no1, No* no2);
    void rotacaoEsquerda(No* no);
    void rotacaoDireita(No* no);
    void balancearInsercao(No* no);
    void balancearRemocao(No* no);
    No* buscarNo(No* no, int valor);
    void imprimirAuxiliar(No* no, std::string espacamento, std::string direcao);
    No* obterMinimoAuxiliar(No* no);
    No* obterMaximoAuxiliar(No* no);

public:
    //Construtor
    ArvoreRB();
    //Destrutor
    ~ArvoreRB();
    //Definicao dos metodos da classe
    void inserir(int valor);
    void remover(int valor);
    bool buscar(int valor);
    void imprimir();
    int obterMinimo();
    int obterMaximo();
};