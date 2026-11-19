/*Crie um unique_ptr para um inteiro, transfira a posse para outro unique_ptr usando std::move, e verifique qual ponteiro está vazio.*/
#include <iostream>
#include <memory>
using namespace std;

int main()
{
    
    unique_ptr<int> n = make_unique<int>(10);
    
    unique_ptr<int> n2 = move(n);
    
    if(!n){
        cout<<"ponteiro inicial vazio"<<endl;
    }
    
    cout<<"ponteiro secundario: "<<*n2;


    return 0;
}