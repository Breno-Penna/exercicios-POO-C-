/*Soma de vetores dinâmicos - construa um programa que leia um tamanho n e crie dois vetores dinâmicos de  inteiros. 
Em seguida, preencha-os, calcule a soma elemento a elemento e exiba o vetor resultante. Faça uso de  new e delete.*/
#include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"insira o tamanho: ";
    cin>>n;
    
    int* vetor1 = new int[n];
    int* vetor2 = new int[n];
    int* vetorR = new int[n];
    
    
    int elementos;
    cout<<"insira os elementos do vetor 1"<<endl;
    for (int i = 0; i < n; i++) {
        cin>>elementos;
        vetor1[i] = elementos;
    }
    
    cout<<"insira os elementos do vetor 2"<<endl;
    for (int i = 0; i < n; i++) {
        cin>>elementos;
        vetor2[i] = elementos;
    }
    
    cout<<"vetor soma"<<endl;
    for (int i = 0; i < n; i++) {
        vetorR[i] = vetor1[i] + vetor2[i];
        cout<<vetorR[i]<<" ";
    }
    
    delete[] vetor1;
    vetor1 = nullptr;
    
    delete[] vetor2;
    vetor2 = nullptr;
    
    delete[] vetorR;
    vetorR = nullptr;

    return 0;
}