/*Construa sistema de chat simples em C++. Cada mensagem possui um destinatário e um remetente; 
para evitar ciclos de referência que impeçam a liberação de memória, o destinatário é mantido com 
shared_ptr e o remetente  apenas observado com weak_ptr. Crie dois usuários, crie uma mensagem de um
para outro usando shared_ptr para o  destinatário e weak_ptr para o remetente, exiba a mensagem junto com remetente e destinatário no console, 
e garanta  que ao final do programa a memória seja liberada corretamente, observando a destruição da mensagem. */
#include <iostream>
#include <memory>
#include <vector>
#include <string>
using namespace std;

class Chat{
public:
    string nome;
    string mensagem;
    shared_ptr<Chat> destinatario;
    weak_ptr<Chat> remetente;
    
    Chat(string nome, string mensagem = ""){
        this->nome = nome;
        this->mensagem = mensagem;
    }
    
    ~Chat(){
        cout<<"mensagem deletada"<<endl;
    }
    
};

int main()
{
    auto user1 = make_shared<Chat>("user1");
    auto user2 = make_shared<Chat>("user2");
    
    auto mensagem1 = make_shared<Chat>("msg1", "oi");
    mensagem1->destinatario = user2;
    mensagem1->remetente = user1;

    auto mensagem2 = make_shared<Chat>("msg2", "tudo bem?");
    mensagem2->destinatario = user1;
    mensagem2->remetente = user2;
    
    cout << "remetente: " << mensagem1->remetente.lock()->nome << " , " << mensagem1->mensagem << endl;
    cout << "destinatario: " << mensagem1->destinatario->nome << " , " << mensagem1->mensagem << endl;

    cout << "remetente: " << mensagem2->remetente.lock()->nome << " , " << mensagem2->mensagem << endl;
    cout << "destinatario: " << mensagem2->destinatario->nome << " , " << mensagem2->mensagem << endl;
    
    return 0;
}