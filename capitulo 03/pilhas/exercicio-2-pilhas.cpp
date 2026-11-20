/*Implemente uma pilha que represente o histórico de páginas visitadas em um navegador. 
Cada nó  guarda o nome da página visitada. Adicione 5 páginas, remova a última visitada, e exiba a pilha antes e  depois da remoção.*/
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
    cout<<"insira as 5 paginas visitadas: "<<endl;
    for (int i = 0; i < 5; i++) {
        getline(cin,name);
        s.push(name);
    }
    s.print();
    
    cout<<"pagina removida: "<<s.pop();

    s.print();

    return 0;
}