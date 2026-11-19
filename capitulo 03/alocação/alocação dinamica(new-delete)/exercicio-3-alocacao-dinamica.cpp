/*Filtro de IDs duplicados - foram recebidos n IDs de produtos (inteiros), com possíveis repetições. 
Crie um novo  array contendo apenas os IDs únicos (preservando a ordem da primeira ocorrência). 
Alocar dinamicamente os  arrays necessários e liberar o original, com o uso de new e delete. */
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n,ID;
    cout<<"insira a quantidade de IDs"<<endl;
    cin>>n;
    
    int* vetor = new int[n];
    
    cout<<"insira os IDs"<<endl;
    for(int i =0;i<n;i++){
        cin>>ID;
        vetor[i]=ID;
    }
    
    
    int* IDsUnicos = new int[n];
    
    int contador = 0;
    for (int i = 0; i < n; i++) {
        bool repetido = false;
        for (int j = 0; j < contador; j++) {
            if (IDsUnicos[j] == vetor[i]) {
                repetido = true;         // achou: ja existe
                break;
            }
        }
        if (!repetido) {                 // so guarda se NAO achou
            IDsUnicos[contador] = vetor[i];
            contador++;
        }
    }
    
    cout << "ids unicos: ";
    for (int i = 0; i < contador; i++) {
        cout << IDsUnicos[i] << " ";
    }
    cout << endl;
    
    
    
    delete[] vetor;
    vetor = nullptr;
    delete[] IDsUnicos;
    IDsUnicos = nullptr;
    
    

    return 0;
}