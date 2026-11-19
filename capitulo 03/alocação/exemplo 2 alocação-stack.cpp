
#include <iostream>
#include <vector>
using namespace std;

class Caixa{
private:
    int valor;
public:
    //contrutor:chamado quando o objeto é criado
    Caixa(int v){
        valor=v;//atribuição dentro do corpo do contrutor
        cout<<"contrutor: caixa criada com valor "<<valor<<endl;
    }
    ~Caixa(){
        cout<<"destrutor: caixa destruida com valor "<<valor<<endl;
    }
    int getValor() const{return valor;}
    
};

int main()
{
    //1.alocação automatica do objeto
    Caixa el(100);//objeto criado no stack
    cout<<"valor de el: "<<el.getValor()<<endl;
    
    //2.referencia a objeto existente
    Caixa& refCI =el;//cria a referencia e el não ocupa nova memoria
    cout<<"valor via referencia: "<<refCI.getValor()<<endl;
    
    //3.container SVL (vector)da stack
    vector<Caixa> caixas;
    caixas.push_back(Caixa(200));
    caixas.push_back(Caixa(300));
    
    cout<<"pesquisando vector da caixas:"<<endl;
    for(const Caixa& i : caixas){
        cout<<"valor: "<<i.getValor()<<endl;
    }
    return 0;
}