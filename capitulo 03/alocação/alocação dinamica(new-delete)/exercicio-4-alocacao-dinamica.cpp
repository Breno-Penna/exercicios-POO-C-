/*Contagem de vogais em palavras - faça um programa que, usando new e delete, leia uma palavra, armazene  dinamicamente e conte quantas vogais ela contém.*/
#include <iostream>
#include <string>
#include <cctype> 
using namespace std;
int main()
{
    string palavra;
    
    cout<<"insira a palavra: ";
    cin>>palavra;
    
    char* vetor = new char[palavra.size()];
    
    int contador=0;
    for (int i = 0; i < palavra.size(); i++) {
        vetor[i]=palavra[i];
        if(tolower(vetor[i])=='a' || tolower(vetor[i])=='e' || tolower(vetor[i])=='i' || tolower(vetor[i])=='o' ||tolower(vetor[i])=='u'){
            contador++;
        }
    }
    
    
    
    cout<<"quantidade = "<<contador<<endl;
    
    delete[] vetor;
    vetor = nullptr;
    

    return 0;
}