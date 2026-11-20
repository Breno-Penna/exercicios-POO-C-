/*Crie uma lista de pontuações de jogadores usando lista simplesmente encadeada. Insira três pontuações e exiba da primeira à  última.*/
#include <iostream>
using namespace std;

//estrutura de nó
struct Node{
    int pontuações;
    Node* next;
};

int main()
{
    //criando nós manualmente
    
    
    
    Node* n1 = new Node{10,nullptr};
    Node* n2 = new Node{20,nullptr};
    Node* n3 = new Node{30,nullptr};
    
    //encadeando os mós
    n1->next = n2;
    n2->next = n3;
    
    //Percorrendo a lista
    Node* atual = n1;
    cout<<"lista de pontuações: ";
    while(atual != nullptr){
        cout<<atual->pontuações<<" ";
        atual = atual->next;
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