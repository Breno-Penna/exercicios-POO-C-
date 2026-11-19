/*Pesquisa de Satisfação - você recebeu n avaliações (inteiros 0–100). 
Alocar dinamicamente um array (com  uso de new e delete) para armazenar as notas, calcular média, encontrar maior e menor nota e seus índices.*/
#include <iostream>
using namespace std;
int main()
{
    int n,nota,soma=0,media=0,maior,menor,indicesMAX=0,indicesMIN=0;
    
    cout<<"quantidade de avaliações: "<<endl;//quantidade
    cin>>n;
    if(n>100 || n<0){
        cout<<"quantidade invalida";
    }
    
    int* array = new int[n];//alocar dinamicamente
    cout<<"insira as avaliaçoes";//preencher e calculo media
    for(int i =0;i<n;i++){
        cout<<"-";
        cin>>nota;
        array[i]=nota;
        soma+=nota;
    }
    media=soma/n;
    
    maior = array[0];
    menor = array[0];
    for(int i =0;i<n;i++){//min e max
        if(array[i]>maior){
            maior=array[i];
            indicesMAX=i;
        }
        if(array[i]<menor){
            menor=array[i];
            indicesMIN=i;
        }
    }
    
    cout<<"media = "<<media<<endl;
    cout<<"maior = "<<maior<<"indice = "<<indicesMAX<<endl;
    cout<<"menor = "<<menor<<"indice = "<<indicesMIN<<endl;
    
    delete[] array;
    array = nullptr;

    return 0;
}