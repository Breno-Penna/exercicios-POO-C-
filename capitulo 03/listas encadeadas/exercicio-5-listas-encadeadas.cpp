/*Crie uma lista circular de jogadores (simplesmente encadeada). Percorra 10 turnos, exibindo os jogadores em ordem cíclica.*/
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
    cout<<"lista de jogadores: \n";
    if(atual != nullptr){
        do{
            cout<<atual->nome<<",";
            atual = atual->next;
            if(atual == J1){
                cout<<endl;
                contador++;
            }
        }while(contador<10);
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