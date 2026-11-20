/*Simule uma partida de um jogo de tabuleiro com 3 jogadores. Cada nó da lista circular representa um jogador e sua posição na vez.  
Percorra a lista 7 turnos, exibindo a ordem dos jogadores que jogam, repetindo ciclicamente.*/
#include <iostream>
#include <string>
using namespace std;

struct Node{
    string nome;
    Node* next;
};

int main()
{
    Node* J1 = new Node{"jogadore1",nullptr};
    Node* J2 = new Node{"jogadore2",nullptr};
    Node* J3 = new Node{"jogadore3",nullptr};
    
    J1->next = J2;
    J2->next = J3;
    J3->next = J1;
    
    Node* atual = J1;
    int contador=0;
    cout<<"lista da ordem de jogadas: \n";
    if(atual != nullptr){
        for (int i = 0; i < 7; i++) {
            cout<<atual->nome<<" , ";
            atual = atual->next;
        }
    }
    
    J3->next = nullptr;
    
    atual = J1;
    while(atual != nullptr){
        Node* temp = atual->next;
        delete atual;
        atual = temp;
    }

    return 0;
}