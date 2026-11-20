/*Simule uma pilha de pratos em um restaurante. Cada prato é representado por um número de identificação. 
O último prato empilhado deve ser o primeiro a ser retirado. 
Crie uma pilha com 4 pratos, remova 2 pratos e exiba o estado da pilha antes e depois das remoções.*/
#include <iostream>
using namespace std;

struct Node {
    int valor;
    Node* next;
};

struct Stack {
    Node* top = nullptr;

    void push(int v) {
        Node* n = new Node{v, top};
        top = n;
    }

    int pop() {
        if (top == nullptr) {
            cout << "Pilha vazia!\n";
            return -1;
        }
        Node* temp = top;
        int val = temp->valor;
        top = top->next;
        delete temp;
        return val;
    }

    void print() {
        Node* atual = top;
        cout << "Pilha: ";
        while (atual != nullptr) {
            cout << atual->valor << " ";
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
    
    for (int i = 0; i < 4; i++) {
        s.push(i+1);
    }
    s.print();
    
    //remover 2
    s.pop();
    s.pop();

    s.print();

    return 0;
}