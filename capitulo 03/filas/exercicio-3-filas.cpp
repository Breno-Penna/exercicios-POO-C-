/*Crie uma fila de atendimento em um banco com senhas numeradas. 
Adicione 6 clientes à fila e  atenda todos, mas antes de atender o último cliente, adicione mais 2 clientes à fila. 
Mostre a fila  antes e depois de cada atendimento.*/
#include <iostream>
using namespace std;

struct Node {
    int valor;
    Node* next;
};

struct Queue {
    Node* front = nullptr;
    Node* rear = nullptr;

    void enqueue(int v) {
        Node* n = new Node{v, nullptr};
        if (rear == nullptr) {
            front = rear = n;
        } else {
            rear->next = n;
            rear = n;
        }
    }

    int dequeue() {
        if (front == nullptr) {
            cout << "Fila vazia!\n";
            return -1;
        }
        Node* temp = front;
        int val = temp->valor;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
        return val;
    }

    void print() {
        Node* atual = front;
        cout << "Fila: ";
        while (atual != nullptr) {
            cout << atual->valor << " ";
            atual = atual->next;
        }
        cout << endl;
    }
};

int main() {
    Queue cliente;
    cliente.enqueue(1);
    cliente.enqueue(2);
    cliente.enqueue(3);
    cliente.enqueue(4);
    cliente.enqueue(5);
    cliente.enqueue(6);

    cliente.print();

    for (int i = 0; i < 5; i++) {
        cout << "cliente atendido: " << cliente.dequeue() << endl;
        cliente.print();
    }
    
    cliente.enqueue(7);
    cliente.enqueue(8);
    
    for (int i = 0; i < 3; i++) {
        cout << "cliente atendido: " << cliente.dequeue() << endl;
        cliente.print();
    }
    

    return 0;
}