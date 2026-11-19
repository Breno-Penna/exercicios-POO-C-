
#include <iostream>
#include <array> //inclui a biblioteca que contem std:array
using namespace std;

int main()
{
    array<int,5> numeros = {10,20,30,40,50}; //array de inteiroscom tamanho fixo 5
    
    for (size_t i = 0; i<numeros.size();i++) { //size() retorna o tamanho do array
        cout<<"elementos "<<i<<": "<<numeros[i] <<endl; //acessa cada elemento
        
    }
    
    cout<<endl; //linha em branco
    
    //percorre array usando o loop "range based for" do C++ moderno
    cout<<"valores do array usando for-each: "<<endl;
    for(int n : numeros){
        cout<<n<<endl;
    }
    return 0;
}