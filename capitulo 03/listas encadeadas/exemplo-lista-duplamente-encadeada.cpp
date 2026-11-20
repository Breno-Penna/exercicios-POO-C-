
#include <iostream>
using namespace std;

struct Node{
    int valor;
    Node* next;
    Node* prev;
};

int main()
{
    Node* n1 = new Node{10,nullptr,nullptr};
    Node* n2 = new Node{20,nullptr};
    Node* n3 = new Node{30,nullptr};
    
    n1->next = n2;
    n2->next = n3;
    
    //percorrrendo a lista para frente
    Node* atual = n1;
    cout<<"lista duplamente encadeada(frente): ";
    while(atual != nullptr){
        cout<<atual->valor<<" ";
        atual = atual->next;
    }
    cout<<endl;
    
    //percorrendo a lista para trás
    atual = n3;
    cout<<"lista duplamente encadeada(atrás): ";
    while(atual != nullptr){
        cout<<atual->valor<<" ";
        atual = atual->prev;
    }
    cout<<endl;
    
    //liberando memoria
    atual = n1;
    while(atual != nullptr){
        Node* temp = atual->next;
        delete atual;
        atual = temp;
    }
    return 0;
}