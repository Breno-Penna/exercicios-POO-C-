/*(Museu) Crie Exposicao com nome; escreva uma função visitar que recebe shared_ptr<Exposicao> por valor e chama um  método. 
No main, crie um shared_ptr, chame visitar e mostre que use_count aumenta dentro da chamada e volta depois.*/
#include <iostream>
#include <memory>
#include <vector>
#include <string>
using namespace std;

class Exposicao{
public:
    string nome;
    
    Exposicao(string nome){
        this->nome =nome;
    }
    
    void mostrar(){
        cout<<"nome da Exposicao: "<<nome<<endl;
    }
    
};

void visitar(shared_ptr<Exposicao> x){//contagem aumenta +1 pela passagem por valor x 
    x->mostrar();
    cout<<"contagem dentro da chamada: "<<x.use_count()<<endl;
}

int main()
{
   string nome;
   
   cout<<"insira o nome da Exposicao: ";
   getline(cin,nome);
   shared_ptr<Exposicao> Nome = make_shared<Exposicao>(nome);
   
   visitar(Nome);
   
   cout<<"contagem fora da chamada: "<<Nome.use_count();

    return 0;
}