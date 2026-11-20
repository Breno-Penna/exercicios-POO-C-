/*Crie uma caixa de entrada de mensagens urgentes, onde a última mensagem recebida deve ser lida primeiro. 
Cada nó da pilha representa uma mensagem identificada por um número. 
Insira 3 mensagens,  leia a última mensagem, insira mais 2 mensagens e exiba a pilha a cada operação.*/
#include <iostream>
#include <string>
using namespace std;

struct Node {
    string nome;
    Node* next;
};

struct Stack {
    Node* top = nullptr;

    void push(string v) {
        Node* n = new Node{v, top};
        top = n;
    }

    string pop() {
        if (top == nullptr) {
            cout << "Pilha vazia!\n";
            return "";
        }
        Node* temp = top;
        string val = temp->nome;
        top = top->next;
        delete temp;
        return val;
    }

    void print() {
        Node* atual = top;
        cout << "Pilha: ";
        while (atual != nullptr) {
            cout << atual->nome << " ";
            atual = atual->next;
        }
        cout << endl;
    }

    ~Stack() {
        while (top != nullptr) {
            pop();
        }
    }
};

int main() {
    Stack s;
    
    string name;
    cout<<"insira as 3 mensagens: "<<endl;
    for (int i = 0; i < 3; i++) {
        getline(cin,name);
        s.push(name);
        s.print();
    }
    
    
    cout<<"mensagem lida: "<<s.pop()<<endl;

    cout<<"insira as 2 mensagens: "<<endl;
    for (int i = 0; i < 2; i++) {
        getline(cin,name);
        s.push(name);
        s.print();
    }
    

    return 0;
}