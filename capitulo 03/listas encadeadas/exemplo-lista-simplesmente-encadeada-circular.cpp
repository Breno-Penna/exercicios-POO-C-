
#include <iostream>
using namespace std;

struct Node{
    int valor; //dado armazenado
    Node* next; //ponteiro para o proximo nó
};

int main()
{
    Node* n1 = new Node{10,nullptr};
    Node* n2 = new Node{20,nullptr};
    Node* n3 = new Node{30,nullptr};
    
    //encadeamento circular
    n1->next = n2;
    n2->next = n3;
    n3->next = n1;
    
    //percorrendo a lista(uma volta completa)
    cout<<"lista simplesmente ancadeada circular: ";
    Node* atual = n1;
    if(atual != nullptr){
        do{
            cout<<atual->valor<<" ";
            atual = atual->next;
        }while(atual != n1); //volta ao inicio e encerra o loop
    }
    cout<<endl;
    
    n3->next = nullptr; //quebra o ciclo para evitar loop infinito
    atual = n1;
    while(atual != nullptr){
        Node* temp atual->next;
        delete atual;
        atual = temp;
    }
    
    cout<<"memoria liberada com sucesso!"<<endl;

    return 0;
}