/*Simule uma rede social onde cada usuário pode seguir outro usuário, e também pode ser seguido de volta. Para
evitar ciclos de referência que causem vazamentos de memória, utilize shared_ptr para seguir e weak_ptr para ser
seguido. Crie dois usuários que seguem um ao outro. Ao final, verifique que a memória é liberada automaticamente sem
vazamento.*/
#include <iostream>
#include <memory>
#include <vector>
#include <string>
using namespace std;

class User{
public:
    string nome;
    vector<weak_ptr<User>> seguidores;
    vector<shared_ptr<User>> seguindo;
    
    User(string nome){
        this->nome = nome;
    }

    ~User(){
        cout << "User destruido: " << nome << endl;
    }
    
    void seguir(shared_ptr<User>& eu, shared_ptr<User>& pessoa){
        seguindo.push_back(pessoa);
        pessoa->seguidores.push_back(eu);
    }
};

int main()
{
    string n1, n2;
    cout<<"insira seu nome e quem quer seguir e ser seguido: "<<endl;
    getline(cin,n1);
    getline(cin,n2);

    auto nome1 = make_shared<User>(n1);
    auto nome2 = make_shared<User>(n2);
    
    nome1->seguir(nome1, nome2);
    nome2->seguir(nome2, nome1);

    cout << "use_count nome1: " << nome1.use_count() << endl;
    cout << "use_count nome2: " << nome2.use_count() << endl;

    return 0;
}