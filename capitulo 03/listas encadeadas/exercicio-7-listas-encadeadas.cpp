/* Crie uma lista circular duplamente encadeada com os meses do ano. Percorra a lista do início ao fim e depois de trás para frente em  2 ciclos.*/
#include <iostream>
#include <string>
using namespace std;

struct Node{
    string meses;
    Node* next;
    Node* prev;
};

int main()
{
    Node* E1 = new Node{"janeiro",nullptr};
    Node* E2 = new Node{"fevereiro",nullptr};
    Node* E3 = new Node{"março",nullptr};
    Node* E4 = new Node{"abril",nullptr};
    Node* E5 = new Node{"maio",nullptr};
    Node* E6 = new Node{"junho",nullptr};
    Node* E7 = new Node{"julho",nullptr};
    Node* E8 = new Node{"agosto",nullptr};
    Node* E9 = new Node{"setembro",nullptr};
    Node* E10 = new Node{"outubro",nullptr};
    Node* E11 = new Node{"novembro",nullptr};
    Node* E12 = new Node{"dezembro",nullptr};
    
    E1->next = E2;
    E2->next = E3;
    E3->next = E4;
    E4->next = E5;
    E5->next = E6;
    E6->next = E7;
    E7->next = E8;
    E8->next = E9;
    E9->next = E10;
    E10->next = E11;
    E11->next = E12;
    E12->next = E1;
    
    int contador=0;
    Node* atual = E1;
    cout<<"lista de meses 2C(inicio-fim): ";
    if(atual != nullptr){
        do{
        cout<<atual->meses<<",";
        atual = atual->next;
        if(atual == E1){
            cout<<"\n";
            contador++;
        }
        }while(contador<2);
    }
    
    cout<<endl;
    
    E1->prev = E12;
    E2->prev = E1;
    E3->prev = E2;
    E4->prev = E3;
    E5->prev = E4;
    E6->prev = E5;
    E7->prev = E6;
    E8->prev = E7;
    E9->prev = E8;
    E10->prev = E9;
    E11->prev = E10;
    E12->prev = E11;
    
    atual = E12;
    contador = 0;
    cout<<"lista de meses 2C(fim-inicio): ";
    if(atual != nullptr){
        do{
        cout<<atual->meses<<",";
        atual = atual->prev;
        if(atual == E1){
            cout<<"\n";
            contador++;
        }
        }while(contador<2);
    }
    
    E12->next = nullptr;
    atual = E1;
    while(atual != nullptr){
        Node* temp = atual->next;
        delete atual;
        atual = temp;
    }
    
    return 0;
}