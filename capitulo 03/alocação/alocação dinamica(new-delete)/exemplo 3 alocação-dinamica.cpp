
#include <iostream>
using namespace std;
int main()
{
    //alocação dinamica de um unico inteiro
    int* ptr = new int; //new int cria um espaço na heap para um inteiro
    *ptr = 42; //atribuimos o valor 42 ao espaço alocado
    cout<<"valor de ptr: "<<*ptr<<endl;
    
    delete ptr; //delete libera o espaço na heap
    ptr = nullptr; //evita ponteiro pendente(dangling pointer)
    
    cout<<"memoria liberada"<<endl;
    
    //alocação dinamica de um array
    int n;
    cout<<"digite o tamanho do array: ";
    cin>>n;
    
    int* vetor = new int[n]; //aloca dinamicamente um array de cinco interos
    
    for(int i=0;i<n;i++){
        vetor[i] = i * 10; //inicializa cada elemento
    }
    
    cout<<"valores do vetor: "<<endl;
    for(int i=0;i<n;i++){
        cout<<vetor[i]<<" ";
    }
    cout<<endl;
    
    //liverando memoria do array
    delete[] vetor; //usa delete[] para arrays alocados dinamicamente
    vetor = nullptr; //evita ponteiro pendente
    
    cout<<"array liberado"<<endl;
    
    return 0;
}