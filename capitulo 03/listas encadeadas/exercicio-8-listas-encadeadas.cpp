/*Crie uma playlist de músicas em C++. Cada música é representada por um nó da lista duplamente encadeada circular. 
A playlist  deve permitir percorrer as músicas para frente e para trás de forma infinita. 
Crie 3 músicas na lista e percorra 5 músicas à frente e 5  músicas para trás, exibindo os nomes no console.*/
#include <iostream>
#include <string>
using namespace std;

struct Node{
    string musicas;
    Node* next;
    Node* prev;
};

int main()
{
    Node* M1 = new Node{"On&On",nullptr};
    Node* M2 = new Node{"Chicago",nullptr};
    Node* M3 = new Node{"resistence",nullptr};
    
    M1->next = M2;
    M2->next = M3;
    M3->next = M1;
    
    M1->prev = M3;
    M2->prev = M1;
    M3->prev = M2;
   
   Node* atual = M3;
    cout<<"playlist: ";
    if(atual != nullptr){
        for (int i = 0; i < 5; i++) {
            cout<<atual->musicas<<"\n";
            atual = atual->prev;
        }
    }
   
    atual = M1;
    if(atual != nullptr){
        for (int i = 0; i < 8; i++) {
            cout<<atual->musicas<<"\n";
            atual = atual->next;
        }
    }
    
    M3->next = nullptr;
    atual = M1;
    while(atual!=nullptr){
        Node* temp = atual->next;
        delete atual;
        atual=temp;
    }
    

    return 0;
}