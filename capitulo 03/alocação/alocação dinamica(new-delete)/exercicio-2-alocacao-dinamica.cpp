/*Vetor de temperaturas diárias - Crie um programa que leia a quantidade de dias e, 
usando alocação dinâmica  (new e delete), armazene as temperaturas registradas. 
Em seguida, calcule e exiba a temperatura média.*/
#include <iostream>
using namespace std;
int main()
{
    int n;
    float temp;
    cout<<"digite a quantidade de dias: ";
    cin>>n;
    
    float* Vtemp = new int[n]; //aloca dinamicamente um array 
    
    float soma = 0;
    float media = 0;
    cout<<"insira as temperaturas: "<<endl;
    for(int i=0;i<n;i++){
        cout<<"dia "<<i<<"= ";
        cin>>temp;
        Vtemp[i] = temp; //inicializa cada elemento
        soma += temp;
    }
    media = soma/n;
    
    cout<<"temperatura media = "<<media<<endl;
    
    //liberando memoria do array
    delete[] Vtemp; //usa delete[] para arrays alocados dinamicamente
    Vtemp = nullptr; //evita ponteiro pendente
    
    cout<<"array liberado"<<endl;

    return 0;
}