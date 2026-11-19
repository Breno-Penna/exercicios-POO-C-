
#include <iostream>
#include <memory>
#include <vector>
#include <string>
using namespace std;

class Animal{
public:
    string nome;
    string especie;
    
    Animal(string n , string e){
        nome=n;
        especie = e;
        cout<<"animal criado: "<<nome<<" | especie: "<<especie<<endl;
    }
    
    ~Animal(){
        cout<<"animal destruido: "<<nome<<endl;
    }
    
    void mostrar(){
        cout<<"nome: "<<nome<<", especie: "<<especie<<endl;
    }
};

int main()
{
    vector<shared_ptr<animal>> zoologico;
    
    //cria animais e adiciona no vector
    zoologico.push_back(make_shared<animal>("leao", "felidae"));
    zoologico.push_back(make_shared<animal>("elefante", "elephantedae"));
    zoologico.push_back(make_shared<animal>("girafa", "girafidae"));
    
    //mostre todos os animais
    cout<<"\nAnimais no zoologico: "<<endl;
    for(size_t i =0;i<zoologico.size();i++){
        zoologico[i]->mostrar();
    }
    
    //cria um shared_ptr que compartilha o leao
    shared_ptr<Animal> animalAtual = zoologico[0];
    cout<<"\n contagem de referencia do leao apos criar animalAtual: "<< zoologico[0].use_count()<<endl;
    
    //criando outro vetor que compartilha os mesmos animais
    vector<shared_ptr<Animal>>reserva = zoologico;
    
    cout<<"\nAnimais na reserva(segundo vetor): "<<endl;
    for(size_t i = 0; i<reserva.size(); i++){
        reserva[i]->mostrar();
    }
    
    //mostrando a contagem de referencia do leao
    cout<<"\ncontagem de referencia leao: "<<zoologico[0].use_count();
    
    //aqui usamos reset() em animalAtual que remove as posses
    //como ainda temos zoologico[0] = reserva[0], o leao não é destruido
    animalAtual.reset();
    cout<<"\napos reset() em animalAtual, contagem do leao: "<<zoologico[0].use_count()<<endl;
    
    //clear(), limpa o vetor reserva
    //redes referenciais, mas leao ainda existe poque zoologico[0] ainda 
    reserva.clear();
    cout<<"apos limpar reserva, contagem leao: "<<zoologico[0].use_count()<<endl

    return 0;
}