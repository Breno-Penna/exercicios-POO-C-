
#include <iostream>
#include <memory> // Inclui suporte aos smart pointers (shared_ptr, weak_ptr, unique_ptr)
using namespace std;
struct Node {
shared_ptr<Node> next; // Ponteiro inteligente compartilhado para o próximo nó
//shared_ptr<Node> prev;
weak_ptr<Node> prev; // Ponteiro fraco para o nó anterior (evita ciclo de referência)
// Destrutor: é chamado automaticamente quando o objeto é destruído
~Node() {
cout << "Node destruído\n"; // Mensagem para indicar quando o nó é desalocado
}
};
int main() {
auto n1 = make_shared<Node>();
cout << "Contagem de referências: " << n1.use_count() << endl;
auto n2 = make_shared<Node>();
cout << "Contagem de referências: " << n2.use_count() << endl;
// Faz n1 apontar para n2 através do ponteiro "next"
n1->next = n2;
cout << "Contagem de referências: " << n1.use_count() << endl;
cout << "Contagem de referências: " << n2.use_count() << endl;
// Faz n2 apontar de volta para n1, mas usando weak_ptr
// Isso evita um ciclo de referência (onde ambos teriam shared_ptr um do outro)
n2->prev = n1;
cout << "Contagem de referências: " << n1.use_count() << endl;
cout << "Contagem de referências: " << n2.use_count() << endl;
// Mensagem indicando o fim do programa
cout << "Fim do programa\n";
// Ao sair do escopo, n1 e n2 são destruídos automaticamente
// Uso de weak_ptr garante que o ciclo seja quebrado e a memória liberada corretamente
}
    return 0;
}