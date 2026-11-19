/*(Playlist de músicas) Crie uma classe Musica com título e artista. No main, crie um vector<shared_ptr<Musica>>  
representando uma playlist, adicione 3 músicas usando make_shared. 
Depois, crie um shared_ptr que aponte para a segunda  música e mostre a contagem de referências dessa música.*/
#include <iostream>
#include <memory>
#include <vector>
#include <string>
using namespace std;

class Musica{
public:
    string titulo;
    string artista;
    
    Musica(string titulo, string artista){
        this->titulo = titulo;
        this->artista = artista;
    }
    
};

int main()
{
    string titulo;
    string artista;
    
    vector<shared_ptr<Musica>> playlist;
    
    cout<<"insira 3 musicas(titulo e artista)"<<endl;
    for (int i = 0; i < 3; i++) {
        getline(cin,titulo);
        getline(cin,artista);
        playlist.push_back(make_shared<Musica>(titulo,artista));
    }
    
    shared_ptr<Musica> reserva = playlist[1];
    
    cout<<"contagem: "<<reserva.use_count()<<endl;

    return 0;
}