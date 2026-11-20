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
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.print();

    cout << "Dequeue: " << q.dequeue() << endl;
    q.print();

    return 0;
}