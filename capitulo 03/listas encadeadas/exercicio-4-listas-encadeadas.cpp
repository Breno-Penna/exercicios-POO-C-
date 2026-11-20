/*Crie uma lista duplamente encadeada de estações de trem. Cada nó armazena o nome da estação. 
Insira três estações e percorra a  lista do início ao fim exibindo os nomes, depois percorra do fim ao início para mostrar o percurso inverso.*/
#include <iostream>
#include <string>
using namespace std;

struct Node{
    string nome;
    Node* next;
    Node* prev;
};

int main()
{
    Node* E1 = new Node{"norte",nullptr};
    Node* E2 = new Node{"sul",nullptr};
    Node* E3 = new Node{"leste",nullptr};
    
    E1->next = E2;
    E2->next = E3;
    
    Node* atual = E1;
    cout<<"lista de estações(inicio-fim): ";
    while(atual != nullptr){
        cout<<atual->nome<<",";
        atual = atual->next;
    };
    cout<<endl;
    
    E3->prev = E2;
    E2->prev = E1;
    
    atual = E3;
    cout<<"lista de estações(fim-inicio): ";
    while(atual != nullptr){
        cout<<atual->nome<<",";
        atual = atual->prev;
    };
    
    atual = E1;
    while(atual != nullptr){
        Node* temp = atual->next;
        delete atual;
        atual = temp;
    }
    
    return 0;
}