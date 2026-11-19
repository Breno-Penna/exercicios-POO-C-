
#include <iostream>
#include <memory>
using namespace std;
int main()
{
    //criando unique uniqueptr
    unique_ptr<int> a = make_unique<int>(10);//a é dono do inteiro 10
    cout<<"valor de a: "<<*a<<endl;
    
    //tentando copiar (naão permitido)
    //unique_ptr<int> c=a; //erro: não pode copiar unique_ptr
    
    //movendo a posse para outro ponteiro
    unique_ptr<int> b = move(a); //b agora é o dono, a fica vazio
    if(!a){
        cout<<"a não possui mais o objeto, esta vazio"<<endl;
    }
    
    cout<<"valor de b: "<<*b<<endl;
    
    //objeto destruido automaticamente ao final do escopo

    return 0;
}