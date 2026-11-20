
#include <iostream>
using namespace std;

//estrutura do nó da lista
struct Node{
    int valor;
    Node* next;
    Node* prev;
};

int main()
{
    Node* n1 = new Node(10,nullptr);
    Node* n2 = new Node(20,nullptr);
    Node* n3 = new Node(30,nullptr);
    
    //encadenando de forma circular
    n1->next = n2;
    n2->next = n3;
    n3->next = n1;
    
    n1->prev = n2;
    n2->prev = n3;
    n3->prev = n1;
    
    cout<<"lista circular(frente): ";
    Node* atual = n1;
    if(atual != nullptr){
        do{
            cout<<atual->valor<<" ";
            atual = atual->next;
        }while(atual != n1);//volta ao inicio = encerra o loop
    }
    cout<<endl;
    
    cout<<"lista circular (atras): ";
    atual = n3;
    if(atual != nullptr){
        do{
            cout<<atual->valor<<" ";
            atual = atual->prev;
        }while(atual != n3);
    }
    cout<<endl;
    
    n3->next = nullptr // quebra o ciclo para evitar o loop infinito
    atual = n1;
    while(atual != nullptr){
        Node* temp =atual->next;
        delete atual;
        atual=temp;
    }
    
    

    return 0;
}