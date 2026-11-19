
#include <iostream>
#include <memory>
#include <vector>
using namespace std;

class Livro{
public:
    string titulo;
    
    Livro(string l){
        titulo = l;
        cout<<"livro criado: "<<titulo<<endl;
    }
    
    void mostrar(){
        cout<<"titulo: "<<titulo<<endl;
    }
};

int main()
{
    //cria shared_ptr para gerenciar um livro
    shared_ptr<Livro> livro1 = make_shared<Livro>("O senhor dos aneis");
    
    //cria outro ponteiro que compartilha a propriedade do mesmo Livro
    shared_ptr<Livro> livro2 = livro1;
    
    cout<<"livro1: " ; livro1->mostrar();
    cout<<"livro2: " ; livro2->mostrar();
    
    //mostra a contagem da referencia
    cout<<"contagem de referencias: "<<livro1.use_cout()<<endl
    //quando livro1 e livro2 sairem do escopo o objeto é destruido automaticamente

    return 0;
}