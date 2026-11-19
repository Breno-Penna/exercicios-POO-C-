/*(Estacionamento)Faça um programa que possua uma classe Carro com placa e modelo. 
Simule um estacionamento com  vector<shared_ptr<Carro>>. 
Procure (simule) um carro e guarde em shared_ptr local. 
Depois reset() nesse ponteiro local e  mostre que a contagem diminuiu.*/
#include <iostream>
#include <memory>
#include <vector>
#include <string>
using namespace std;
class Carro{
public:
    string placa;
    string modelo;
    
    Carro(string placa, string modelo){
        this->placa = placa;
        this->modelo = modelo;
    }
};

int main()
{
    string placa;
    string modelo;
    
    vector<shared_ptr<Carro>> estacionamento;
    
    cout<<"insira os carros no estacionamento('sair' para parar)"<<endl;
    do{
        getline(cin,placa);
        if(placa == "sair"){
            break;
        }
        getline(cin,modelo);
        estacionamento.push_back(make_shared<Carro>(placa, modelo));
    }while(true);
    
    int posição = -1;
    shared_ptr<Carro> local;
    
    cout<<"insira a placa para achar o carro"<<endl;
    getline(cin,placa);
    for (size_t i = 0; i < estacionamento.size(); i++) {
        if(placa == estacionamento[i]->placa){
            cout<<"carro encontrado"<<endl;
            local = estacionamento[i];
            posição = i;
        }
    }
    
    if(posição!=-1){
        cout<<"contagem antes: "<<local.use_count()<<endl;
        local.reset();
        cout<<"contagem depois: "<<local.use_count();
    }else{
        cout<<"carro não encontrado";
    }
    

    return 0;
}