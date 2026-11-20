/*Implemente uma fila de pedidos em uma cafeteria. Cada nó representa um pedido com o número  do cliente. 
Simule a chegada de 5 clientes, adicione-os à fila e depois atenda 2 clientes, exibindo a  fila antes e depois do atendimento.*/
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

    cliente.print();

    //atendendo 2 clientes
    cliente.dequeue();
    cliente.dequeue();
    
    cliente.print();

    return 0;
}