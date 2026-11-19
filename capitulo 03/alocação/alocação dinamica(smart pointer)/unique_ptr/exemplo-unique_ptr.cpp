
#include <iostream>
#include <memory>//unique_ptr
#include <string>
using namespace std;

class Pedido{
public:
    string descrição;
    
    Pedido(string desc){
        descrição=desc;
        cout<<"Pedido criado: "<<descrição<<endl;
    }
    //destrutor
    ~Pedido(){
        cout<<"Pedido finalizado: "<<descrição<<endl;
    }
    //mostrar Pedido
    void mostrar(){
        cout<<"pedido: "<<descrição<<endl;
    }
};

int main()
{
    unique_ptr<Pedido> pedido1=make_unique<Pedido>("pizza de calabresa");
    
    pedido1->mostrar();
    
    //transferindo a posse do pedido para outro ponteriro
    unique_ptr<Pedido> pedidoAtual = move(pedido1); //pedido1 fica vazio
    
    //verificando se pedido1 esta vazio
    if(pedido1 == nullptr){
        cout<<"pedido1 não tem mais o pedido"<<endl;
    }
    
    //mostrando o pedido pelo novo ponteriro
    pedidoAtual->mostrar();
    
    //ao sair, pedidoAtual é destruido automaticamente
    
    return 0;
}