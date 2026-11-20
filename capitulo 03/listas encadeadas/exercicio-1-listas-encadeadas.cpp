/*Implemente uma lista de tarefas usando uma lista simplesmente encadeada. 
Cada nó deve armazenar o nome da Tarefa. Insira três  Tarefas e exiba todas na ordem de inserção.*/
#include <iostream>
#include <string>
using namespace std;

struct Tarefa{
    string nome;
    Tarefa* next;
};

int main()
{
    Tarefa* t1 = new Tarefa{"limpar",nullptr};
    Tarefa* t2 = new Tarefa{"comprar",nullptr};
    Tarefa* t3 = new Tarefa{"estudar",nullptr};
    
    t1->next = t2;
    t2->next = t3;
    
    Tarefa* atual = t1;
    cout<<"lista de Tarefas: ";
    while(atual != nullptr){
        cout<<atual->nome<<" ";
        atual = atual->next;
    }
    cout<<endl;
    
    //liberando memoria
    atual = t1;
    while(atual != nullptr){
        Tarefa* temp = atual->next;
        delete atual;
        atual = temp;
    }
    

    return 0;
}