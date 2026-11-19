/*(Sala de bate-papo )Crie User com nome. Crie uma lista de usuários ativos (vetor de shared_ptr<User>). 
Crie dois vetores  representando salas de chat e copie alguns shared_ptr para ambas as salas (compartilhamento).
Mostre o use_count de um  usuário específico.*/
#include <iostream>
#include <memory>
#include <vector>
#include <string>
using namespace std;

class User{
public:
    string nome;
    
    User(string nome){
        this->nome=nome;
    }
};

int main()
{
    string nome;
    
    vector<shared_ptr<User>> usuario;
    
    cout<<"insira o nome dos usuarios ativos(sair para parar)"<<endl;
    
    while(true){
        getline(cin,nome);
        if(nome == "sair"){
            break;
        }
        usuario.push_back(make_shared<User>(nome));
    }
    
    vector<shared_ptr<User>> sala1;
    vector<shared_ptr<User>> sala2;
    
    int codigo;
    bool encontrado;
    while(true){
        cout<<"escolha a sala de chat"<<"\n(1)"<<"\n(2)"<<"\n(3-sair)"<<endl;
        cin>>codigo;
        
        cin.ignore();//o \n não entar no proximo getline
        
        if(codigo == 3){
            break;
        }
        switch(codigo){
            case 1:
                cout<<"digite os nomes para entrar na sala de chat(sair para parar)"<<endl;
                
                while(true){
                    getline(cin,nome);
                    encontrado = false;
                    if(nome == "sair"){
                        break;
                    }
                    
                    for (size_t i = 0; i < usuario.size(); i++) {
                        if(nome == usuario[i]->nome){
                            sala1.push_back(usuario[i]);
                            encontrado = true;
                        }
                    }
                    if(encontrado == false){
                        cout<<"usuario inativo";
                    }
                }
                break;
                
            case 2:
             cout<<"digite os nomes para entrar na sala de chat(sair para parar)"<<endl;
                 while(true){
                    getline(cin,nome);
                    encontrado = false;
                    if(nome == "sair"){
                        break;
                    }
                    
                    for (size_t i = 0; i < usuario.size(); i++) {
                        if(nome == usuario[i]->nome){
                            sala2.push_back(usuario[i]);
                            encontrado = true;
                        }
                    }
                    if(encontrado == false){
                        cout<<"usuario inativo";
                    }
                }
                break;
                
            default: cout<<"sala inexistente";
                break;
        }
        
    }
    
    
    
    
    cout<<"escolha o usuario para verificar a contagem"<<endl;
    getline(cin,nome);
    for (size_t i = 0; i < usuario.size(); i++) {
        if(nome == usuario[i]->nome){
            cout<<usuario[i].use_count();
        }
    }
    return 0;
}