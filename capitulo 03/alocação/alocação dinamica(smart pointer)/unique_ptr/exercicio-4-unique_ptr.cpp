/*Crie uma função criarLivro(string titulo) que retorna um unique_ptr<Livro>. 
No main, crie uma lista de livros utilizando um vetor de  unique_ptr<Livro> e inicialize cada livro diretamente com make_unique, 
atribuindo títulos diferentes para cada um. Em seguida,  percorra o vetor e exiba os títulos de todos os livros criados. Depois, 
transfira a posse do primeiro livro para um ponteiro separado  usando move() e verifique que o ponteiro original ficou vazio (nullptr). 
Por fim, exiba o título do livro que foi transferido para o  ponteiro separado.*/
#include <iostream>
#include <memory>
#include <string>
#include <vector>
using namespace std;

class Livro{
public:
    string titulo;
    
    Livro(string titulo){
        this->titulo = titulo;//construtor
    }
    
};

unique_ptr<Livro> criarLivro(string titulo){//função para criar o livro unique_ptr
    return make_unique<Livro>(titulo);
}

int main()
{
    string titulo;
    
    vector<unique_ptr<Livro>> listaLivros;
    
    cout<<"insira os livros(sair para terminar)"<<endl;
    do{
        getline(cin,titulo);
        if(titulo=="sair"){
            break;
        }
        listaLivros.push_back(criarLivro(titulo));//preencher o vetor com o livro criado
    }while(true);
    
    
    if(!listaLivros.empty()){//caso "sair" seja digitado no inicio
        
        for (unique_ptr<Livro>& i : listaLivros) {//exibir os titulos
            cout<<i->titulo<<endl;
        }
    
        unique_ptr<Livro> separado = move(listaLivros[0]);//mover o valor do ponteiro
    
        if(listaLivros[0] == nullptr){//verificar se o primeiro titulo ficou vazio e imprimir
            cout<<"primeiro vetor vazio"<<endl;
            cout<<"vetor saparado: "<<separado->titulo;
        }
    }else{
        cout<<"nenhum livro inserido";
    }
 
    return 0;
}