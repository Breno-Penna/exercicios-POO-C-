/* Crie uma classe Lampada com um atributo estado (bool) e um método ligar(). 
No main, crie um unique_ptr que gerencia uma  lâmpada, ligue a lâmpada e mostre seu estado.*/
#include <iostream>
#include <memory>
using namespace std;
class Lampada{
public:
    bool estado;
    
    Lampada(bool estado){
        this->estado = estado;
    }
    
    void ligar(){
        estado = true;
    }
    
    void mostrar(){
        if(estado){
            cout<<"lampada ligada";
        }else{
            cout<<"lampada desligada";
        }
    }
    
    
};

int main()
{
    unique_ptr<Lampada> ligarLampada = make_unique<Lampada>(false);
    
    ligarLampada->ligar();
    ligarLampada->mostrar();
    

    return 0;
}