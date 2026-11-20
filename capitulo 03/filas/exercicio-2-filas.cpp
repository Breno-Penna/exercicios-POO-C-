/*Simule uma impressora compartilhada. Cada nó representa um documento identificado por um  número. 
Adicione 4 documentos à fila e processe-os um a um, exibindo o estado da fila a cada  impressão.*/
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
    Queue documentos;
    documentos.enqueue(1);
    documentos.enqueue(2);
    documentos.enqueue(3);
    documentos.enqueue(4);
    
    documentos.print();
    
    for (int i = 0; i < 4; i++) {
        cout << "documento processado: " << documentos.dequeue() << endl;
    }

    documentos.print();

    return 0;
}