#include <iostream>
using namespace std;

struct Node{
    int valor;
    Node* next;
};

struct stack{
    Node* top = nullptr;
    
    void push(int v){
        Node* n = new Node{v,top};
        top = n;
    }
    
    int pop(){
        if(top == nullptr){
            cout<<"pilha vazia\n";
            return -1;
        }
        Node* temp = top;
        int val = temp->valor;
        top = top->next;
        delete temp;
        return val;
    }
    void print(){
        Node* atual=top;
        cout<<"pilha";
        while(atual != nullptr){
            cout<<atual->valor<<" ";
            atual = atual->next;
        }
        cout<<endl;
    }
    
};

int main()
{
    stack a;
    a.push(10);
    a.push(20);
    a.push(30);
    
    a.print();
    
    cout<<"pop: "<<a.pop()<<endl;
    a.print();

    return 0;
}