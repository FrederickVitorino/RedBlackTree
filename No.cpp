#include<iostream>
#include "No.h"
    //Metodo Construtor
    No::No(int valor) : valor(valor), cor(VERMELHO), pai(nullptr), esquerda(nullptr), direita(nullptr) {}

    //Metodo destrutor
    No::~No(){
        delete esquerda;
        delete direita;
    }

    //Metodos getters
    int No::getValor(){
        return valor;
    }

    Cor No::getCor(){
        return cor;
    }

    No* No::getPai(){
        return pai;
    }

    No* No::getEsquerda(){
        return esquerda;
    }

    No* No::getDireita(){
        return direita;
    }

    //Metodos setters
    void No::setValor(int novoValor){
        valor = novoValor;
    }

    void No::setCor(Cor novaCor){
        cor = novaCor;
    }

    void No::setPai(No* novoPai){
        pai = novoPai;
    }

    void No::setEsquerda(No* novaEsquerda){
        esquerda = novaEsquerda;
    }

    void No::setDireita(No* novaDireita){
        direita = novaDireita;
    }