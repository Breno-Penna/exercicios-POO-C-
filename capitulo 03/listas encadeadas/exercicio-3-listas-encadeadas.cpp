/*Elabore uma lista de livros usando lista duplamente encadeada. 
Cada nó armazena o título de um livro. Insira três livros e percorra a  lista do início ao fim e do fim ao início.*/
#include <iostream>
#include <string>
using namespace std;

struct Node{
    string titulo;
    Node* next;
    Node* prev;
};

int main()
{
    Node* l1 = new Node{"senhor dos aneis",nullptr};
    Node* l2 = new Node{"H.P",nullptr};
    Node* l3 = new Node{"duna",nullptr};
    
    l1->next = l2;
    l2->next = l3;
    
    Node* atual = l1;
    cout<<"lista de livro (inicio-fim): ";
    while(atual != nullptr){
        cout<<atual->titulo<<",";
        atual = atual->next;
    };
    cout<<endl;
    
    l3->prev = l2;
    l2->prev = l1;
    
    atual = l3;
    cout<<"lista de livro (fim-inicio): ";
    while(atual != nullptr){
        cout<<atual->titulo<<",";
        atual = atual->prev;
    };
    
    atual = l1;
    while(atual != nullptr){
        Node* temp = atual->next;
        delete atual;
        atual = temp;
    }
    
    return 0;
}