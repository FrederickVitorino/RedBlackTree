#include<iostream>
#include "ArvoreRB.h"
using namespace std;

    //Função auxiliar para trocar as cores de dois nós
    void ArvoreRB::swapCores(No* no1, No* no2){
        //Faz a troca das cores de dois nos fornecidos utilizando uma variável temporaria
        Cor temp;
        temp = no1->getCor();
        no1->setCor(no2->getCor());
        no2->setCor(temp);
    }

    //Realiza uma rotação para a esquerda em torno de um nó
    void ArvoreRB::rotacaoEsquerda(No* no){
        No* direita = no->getDireita();
        no->setDireita(direita->getEsquerda());

        //Atualiza o pai do filho à esquerda, caso exista
        if(direita->getEsquerda() != nullptr)
            direita->getEsquerda()->setPai(no);

        //Atualiza o pai do nó à direita como o pai do nó atual
        direita->setPai(no->getPai());

        if(no->getPai() == nullptr) //Verifica se o nó atual é a raiz da árvore, se for então atualiza raiz
            raiz = direita;
        else if(no == no->getPai()->getEsquerda()) //Verifica se o nó atual é filho esquerdo do seu pai
            no->getPai()->setEsquerda(direita);
        else//Se entra aqui, o nó atual é filho direito do seu pai
            no->getPai()->setDireita(direita);

        //Faz a rotação à esquerda
        direita->setEsquerda(no);
        no->setPai(direita);
    }

    //Realiza uma rotação para a direita em torno de um nó
    void ArvoreRB::rotacaoDireita(No* no){
        No* esquerda = no->getEsquerda();
        no->setEsquerda(esquerda->getDireita());

        //Atualiza o pai do filho à direita, caso exista
        if(esquerda->getDireita() != nullptr)
            esquerda->getDireita()->setPai(no);

        //Atualiza o pai do nó à esquerda como o pai do nó atual
        esquerda->setPai(no->getPai());

        if(no->getPai() == nullptr) //Verifica se o nó atual é a raiz da árvore, se for então atualiza raiz
            raiz = esquerda;
        else if(no == no->getPai()->getEsquerda()) //Verifica se o nó atual é filho esquerdo do seu pai
            no->getPai()->setEsquerda(esquerda);
        else //Se entra aqui, o nó atual é filho direito do seu pai
            no->getPai()->setDireita(esquerda);

        //Faz a rotação à direita
        esquerda->setDireita(no);
        no->setPai(esquerda);
    }

    //Balanceia a árvore apos uma inserção
    void ArvoreRB::balancearInsercao(No* no){
        No* pai = nullptr;
        No* avo = nullptr;

        while(no != raiz && no->getCor() == VERMELHO && no->getPai()-> getCor() == VERMELHO){
            pai = no-> getPai();
            avo = no-> getPai()-> getPai();

            //Verifica se o pai do nó é filho esquerdo do avô
            if(pai == avo -> getEsquerda()){
                No* tio = avo->getDireita();
                
                //Se o tio é vermelho
                if(tio != nullptr && tio->getCor() == VERMELHO){
                    avo->setCor(VERMELHO);
                    pai->setCor(PRETO);
                    tio->setCor(PRETO);
                    no = avo;
                } 
                else{  
                    //Se o tio é preto
                    if(no == pai->getDireita()){
                        rotacaoEsquerda(pai);
                        no = pai;
                        pai = no->getPai();
                    }
                    rotacaoDireita(avo);
                    swapCores(pai, avo);
                    no = pai;
                }
            } 
            else{
                No* tio = avo-> getEsquerda();

                //Se o tio é vermelho
                if(tio != nullptr && tio->getCor() == VERMELHO){
                    avo->setCor(VERMELHO);
                    pai->setCor(PRETO);
                    tio->setCor(PRETO);
                    no = avo;
                }
                else{
                    //Se o tio é preto
                    if(no == pai->getEsquerda()){
                        rotacaoDireita(pai);
                        no = pai;
                        pai = no->getPai();
                    }
                    rotacaoEsquerda(avo);
                    swapCores(pai, avo);
                    no = pai;
                }
            }
        }

        raiz->setCor(PRETO);
    }

    //Balanceia a árvore apos uma remoção
    void ArvoreRB::balancearRemocao(No* no){
        while(no != raiz && no->getCor() == PRETO){
            cout << "Esta no no: " << no->getValor() << endl;
            if(no == no-> getPai()->getEsquerda()){
                No* irmao = no->getPai()->getDireita();
                cout << "Entrou na verificacao da direita" << endl;
                //Se o irmão é vermelho
                if(irmao->getCor() == VERMELHO){
                    irmao->setCor(PRETO);
                    no->getPai()->setCor(VERMELHO);
                    rotacaoEsquerda(no->getPai());
                    irmao = no->getPai()->getDireita();
                }
                
                //Se o irmão e os filhos do irmão são pretos
                if(irmao->getEsquerda()->getCor() == PRETO && irmao->getDireita()->getCor() == PRETO){
                    irmao->setCor(VERMELHO);
                    no = no->getPai();
                } 
                else{
                    //Se o irmão é preto, o filho esquerdo do irmão é preto e o filho direito do irmão é vermelho
                    if(irmao->getDireita()->getCor() == PRETO){
                        irmao->getEsquerda()->setCor(PRETO);
                        irmao->setCor(VERMELHO);
                        rotacaoDireita(irmao);
                        irmao = no->getPai()->getDireita();
                    }
                    
                    //Se o irmão é preto e o filho direito do irmão é vermelho
                    irmao->setCor(no->getPai()->getCor());
                    no->getPai()->setCor(PRETO);
                    irmao->getDireita()->setCor(PRETO);
                    rotacaoEsquerda(no->getPai());
                    no = raiz;
                }
            } 
            else{
                No* irmao = no->getPai()->getEsquerda();
                cout << "Entrou na verificacao da esquerda" << endl;
                //Se o irmão é vermelho
                if(irmao->getCor() == VERMELHO){
                    irmao->setCor(PRETO);
                    no->getPai()->setCor(VERMELHO);
                    rotacaoDireita(no->getPai());
                    irmao = no->getPai()->getEsquerda();
                }

                 //Se o irmão e os filhos do irmão são pretos
                if(irmao->getDireita()->getCor() == PRETO && irmao->getEsquerda()->getCor() == PRETO){
                    irmao->setCor(VERMELHO);
                    no = no->getPai();
                } 
                else{
                    //Se o irmão é preto, o filho direito do irmão é preto e o filho esquerdo do irmão é vermelho
                    if(irmao->getEsquerda()->getCor() == PRETO){
                        irmao->getDireita()->setCor(PRETO);
                        irmao-> setCor(VERMELHO);
                        rotacaoEsquerda(irmao);
                        irmao = no->getPai()->getEsquerda();
                    }
                    
                    //Se o irmão é preto e o filho esquerdo do irmão é vermelho
                    irmao->setCor(no->getPai()->getCor());
                    no->getPai()->setCor(PRETO);
                    irmao->getEsquerda()->setCor(PRETO);
                    rotacaoDireita(no->getPai());
                    no = raiz;
                }
            }
            cout << "Vai repetir" << endl;
        }
        no->setCor(PRETO);
    }

    //Busca um nó com o valor fornecido nas subárvores com raiz no nó especificado
    No* ArvoreRB::buscarNo(No* no, int valor){
        if(no == nullptr || no->getValor() == valor)
            return no;

        if(valor < no->getValor())
            return buscarNo(no->getEsquerda(), valor);

        return buscarNo(no->getDireita(), valor);
    }

    //Imprime a árvore de forma recursiva (função auxiliar da função imprimir())
    void ArvoreRB::imprimirAuxiliar(No* no, string espacamento, string direcao){
        if(no != nullptr){
            //Imprime o espaçamento, a direção e o valor do nó, juntamente com sua cor
            cout << espacamento; //Espaçamento representaria o nível/profundidade do nó
            cout << direcao; //Direcao = Esquerda ou Direita
            cout << no->getValor() << "(" << (no->getCor() == PRETO ? "P" : "V") << ")" << endl;

            //Chama a função recursivamente para imprimir os filhos à esquerda e à direita
            imprimirAuxiliar(no->getEsquerda(), espacamento + "  ", "Esq: ");
            imprimirAuxiliar(no->getDireita(), espacamento + "  ", "Dir: ");
        }
    }

    //Retorna o nó com o menor valor na subárvore com raiz no nó especificado (função auxiliar de obtemMinimo())
    No* ArvoreRB::obterMinimoAuxiliar(No* no){
        while(no->getEsquerda() != nullptr)
            no = no->getEsquerda();

        return no;
    }

    //Retorna o nó com o maior valor na subárvore com raiz no nó especificado (função auxiliar de obtemMaximo())
    No* ArvoreRB::obterMaximoAuxiliar(No* no){
        while(no->getDireita() != nullptr)
            no = no->getDireita();

        return no;
    }

    //Metodo construtor
    ArvoreRB::ArvoreRB() : raiz(nullptr) {}

    //Metodo destrutor
    ArvoreRB::~ArvoreRB(){
        delete raiz;
    }

    //Insere um valor na árvore
    void ArvoreRB::inserir(int valor){
        No* no = new No(valor);

        No* atual = raiz;
        No* pai = nullptr;
        
        //Percorre a árvore para inserir o nó em uma posição inadequada
        while(atual != nullptr){
            pai = atual;

            if(valor < atual->getValor())
                atual = atual->getEsquerda();
            else
                atual = atual->getDireita();
        }

        no->setPai(pai);

        //Verifica se o pai é nulo, o que indica que a árvore estava vazia
        if(pai == nullptr)
            raiz = no;
        else if(valor < pai->getValor())
            pai->setEsquerda(no);
        else
            pai->setDireita(no);

        //Realiza o balanceamento após a inserção do novo nó
        balancearInsercao(no);
    }

    //Exclui um valor da árvore
    void ArvoreRB::remover(int valor){
        
        //Busca o nó a ser removido na árvore, se o nó não foi encontrado, retorna
        No* no = buscarNo(raiz, valor);
        if(no == nullptr)
            return;

        No* substituto = nullptr;
        No* filho = nullptr;

        //Verifica se o nó tem no máximo um filho, se sim, o substituto é o próprio nó, senão o substituto 
        //é o sucessor do nó
        if(no->getEsquerda() == nullptr || no->getDireita() == nullptr)
            substituto = no;
        else
            substituto = obterMinimoAuxiliar(no->getDireita());

        if(substituto->getEsquerda() != nullptr)
            filho = substituto->getEsquerda();
        else
            filho = substituto->getDireita();

        if(filho != nullptr)
            filho->setPai(substituto -> getPai());


        //Atualiza as conexões do pai do substituto
        //Se o substituto for a raiz, o filho se torna a nova raiz, senão o substituto é removido da árvore,
        //e o filho toma seu lugar como filho do pai do substituto
        if(substituto->getPai() == nullptr)
            raiz = filho;
        else if(substituto == substituto->getPai()->getEsquerda())
            substituto->getPai()->setEsquerda(filho);
        else
            substituto->getPai()->setDireita(filho);

        //Se o substituto não for o nó original, copia o valor do substituto para o nó original
        if(substituto != no)
            no->setValor(substituto->getValor());

        //Balanceia a árvore após a remoção, considerando a cor do substituto
        if(substituto->getCor() == PRETO)
            balancearRemocao(filho);

        delete substituto;
    }

    //Busca um valor na árvore
    bool ArvoreRB::buscar(int valor){
        return buscarNo(raiz, valor) != nullptr;
    }

    //Imprime a árvore
    void ArvoreRB::imprimir(){
        imprimirAuxiliar(raiz, "", "");
    }

    //Retorna o valor do nó com o menor valor na árvore
    int ArvoreRB::obterMinimo(){
        No* minimo = obterMinimoAuxiliar(raiz);
        return minimo != nullptr ? minimo->getValor() : -1;
    }

    //Retorna o valor do nó com o maior valor na árvore
    int ArvoreRB::obterMaximo(){
        No* maximo = obterMaximoAuxiliar(raiz);
        return maximo != nullptr ? maximo->getValor() : -1;
    }