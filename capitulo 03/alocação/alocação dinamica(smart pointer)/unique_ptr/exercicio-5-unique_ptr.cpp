/*Crie uma classe Caixa que armazena um número. No main, crie três caixas dinamicamente usando unique_ptr e armazene em um  vetor. 
Depois, transfira uma caixa específica para um ponteiro separado, mostre o valor e confirme que o vetor não possui mais a  caixa.*/
#include <iostream>
#include <memory>
#include <vector>
using namespace std;

class Caixa{
public:
    int número;
    
    Caixa(int número){
        this->número=número;
    }
};

int main()
{
    int número;
    vector<unique_ptr<Caixa>> caixas;
    
    cout<<"insira 3 valores para as caixas"<<endl;
    for (int i = 0; i < 3; i++) {
        cin>>número;
        caixas.push_back(make_unique<Caixa>(número));
    }
    
    
    
    int codigo;
    do{
        cout<<"escolha a caixa a ser transferida"<<"\n(1)"<<"\n(2)"<<"\n(3)"<<endl;
        cin>>codigo;
        
    }while(codigo<1 || codigo>3);
    
    unique_ptr<Caixa> separado = move(caixas[codigo-1]);
    
    if(caixas[codigo-1] == nullptr){
        cout<<"vetor da caixa primaria vazia"<<endl;
        cout<<"valor da caixa transferida: "<<separado->número;
    }

    return 0;
}