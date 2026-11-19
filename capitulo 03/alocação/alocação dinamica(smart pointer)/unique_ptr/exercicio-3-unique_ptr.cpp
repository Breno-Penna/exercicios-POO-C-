/* Faça um programa que: 
1. Peça ao usuário 5 números inteiros. 
2. Armazene cada número em um unique_ptr<int> dentro de um vetor. 
3. Percorra o vetor e mostre os valores na tela. 
4. Os objetos devem ser destruídos automaticamente ao final do programa. 
*/
#include <iostream>
#include <memory>
#include <vector>
using namespace std;

int main()
{
    int n;
    
    vector<unique_ptr<int>> numeros;

    cout << "Digite 5 numeros inteiros:" << endl;
    for (int i = 0; i < 5; i++) {
        cin >> n;
        numeros.push_back(make_unique<int>(n));   
    }

    cout << "Valores armazenados:" << endl;
    for ( unique_ptr<int>& p : numeros) {               
        cout << *p << endl;
    }

    return 0;
}