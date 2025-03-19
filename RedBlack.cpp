#include<iostream>
#include<cstdlib>
#include"ArvoreRB.cpp"
using namespace std;

int main(){
    ArvoreRB arvore;
    int operacao = 1, x;
    do{
        system("cls"); //Windows
        //system("clear"); //Linux

        cout << "[1 - Inserir um valor na arvore]" << endl;
		cout << "[2 - Deletar um valor da arvore]" << endl;
		cout << "[3 - Buscar um valor na arvore]" << endl;
        cout << "[4 - Obter o menor e o maior valor da arvore]" << endl;
        cout << "[0 - Sair]" << endl;
        cout << endl;
        arvore.imprimir();
        cout << endl;
        cout << "Digite o numero da operacao que deseja fazer: "; cin >> operacao;
        
        switch(operacao){
            case 0:
                cout << "Programa finalizado." << endl;
                cout << endl;
                break;
            case 1:
                cout << "Qual o valor que deseja inserir na arvore?: "; cin >> x;
                arvore.inserir(x);
                break;
            case 2:
                cout << "Qual o valor que deseja deletar da arvore?: "; cin >> x;
                arvore.remover(x);
                break;
            case 3:
                cout << "Qual o valor que deseja buscar na arvore?: "; cin >> x;
                cout << "Buscar " << x << ": " << (arvore.buscar(x) ? "Encontrado" : "Nao encontrado") << endl;
                cout << endl;
                //cout << "Pressione Enter para continuar..." << endl; //Linux
                //char pausa = cin.get()
                system("pause"); //Windows
                break;
            case 4:
                cout << "Minimo: " << arvore.obterMinimo() << endl;
                cout << "Maximo: " << arvore.obterMaximo() << endl;
                cout << endl;
                //cout << "Pressione Enter para continuar..." << endl; //Linux
                //char pausa = cin.get()
                system("pause"); //Windows
                break;
            default:
                cout << "O numero fornecido nao corresponde a uma operacao valida." << endl;
                cout << endl;
                //cout << "Pressione Enter para continuar..." << endl; //Linux
                //char pausa = cin.get()
                system("pause"); //Windows
                break;
        }
    }while(operacao!=0);

    //cout << "Pressione Enter para continuar..." << endl; //Linux
    //char pausa = cin.get();
    system("pause");
    return 0;
}