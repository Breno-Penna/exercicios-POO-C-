/*(Inventário de itens) Crie Item com nome. No main, crie alguns shared_ptr<Item> (itens no jogo) 
e crie dois vetores  representando inventários de dois jogadores; permita que ambos apontem para o mesmo item (compartilhamento). 
Remova um  item do primeiro inventário e mostre use_count antes e depois.*/
#include <iostream>
#include <memory>
#include <vector>
#include <string>
using namespace std;

class Item {
public:
    string nome;

    Item(string nome) {
        this->nome = nome;
    }
};

int main() {
    shared_ptr<Item> sword = make_shared<Item>("sword");
    shared_ptr<Item> shield = make_shared<Item>("shield");
    shared_ptr<Item> armour = make_shared<Item>("armour");

    vector<shared_ptr<Item>> inventario_J1;
    vector<shared_ptr<Item>> inventario_J2;

    int codigo;
    int contador = 0;

    while (contador <= 3) {
        // JOGADOR 1
        cout << "\nEscolha 1 item (J1)\n(1) sword\n(2) shield\n(3) armour\n(4) exit" << endl;
        cin >> codigo;
        cin.ignore();
        if (codigo == 4) {
            break;
        }

        switch (codigo) {
            case 1: {
                bool jaTem = false;
                for (size_t i = 0; i < inventario_J1.size(); i++) {
                    if (inventario_J1[i]->nome == "sword") {
                        jaTem = true;
                        break;
                    }
                }
                if (jaTem) {
                    cout << "item ja adquirido" << endl;
                } else {
                    inventario_J1.push_back(sword);
                    cout << "espada coletada" << endl;
                }
                break;
            }
            case 2: {
                bool jaTem = false;
                for (size_t i = 0; i < inventario_J1.size(); i++) {
                    if (inventario_J1[i]->nome == "shield") {
                        jaTem = true;
                        break;
                    }
                }
                if (jaTem) {
                    cout << "item ja adquirido" << endl;
                } else {
                    inventario_J1.push_back(shield);
                    cout << "escudo coletado" << endl;
                }
                break;
            }
            case 3: {
                bool jaTem = false;
                for (size_t i = 0; i < inventario_J1.size(); i++) {
                    if (inventario_J1[i]->nome == "armour") {
                        jaTem = true;
                        break;
                    }
                }
                if (jaTem) {
                    cout << "item ja adquirido" << endl;
                } else {
                    inventario_J1.push_back(armour);
                    cout << "armadura coletada" << endl;
                }
                break;
            }
            default:
                cout << "item invalido" << endl;
                break;
        }

        // JOGADOR 2
        cout << "\nEscolha 1 item (J2)\n(1) sword\n(2) shield\n(3) armour\n(4) exit" << endl;
        cin >> codigo;
        cin.ignore();
        if (codigo == 4) {
            break;
        }

        switch (codigo) {
            case 1: {
                bool jaTem = false;
                for (size_t i = 0; i < inventario_J2.size(); i++) {
                    if (inventario_J2[i]->nome == "sword") {
                        jaTem = true;
                        break;
                    }
                }
                if (jaTem) {
                    cout << "item ja adquirido" << endl;
                } else {
                    inventario_J2.push_back(sword);
                    cout << "espada coletada" << endl;
                }
                break;
            }
            case 2: {
                bool jaTem = false;
                for (size_t i = 0; i < inventario_J2.size(); i++) {
                    if (inventario_J2[i]->nome == "shield") {
                        jaTem = true;
                        break;
                    }
                }
                if (jaTem) {
                    cout << "item ja adquirido" << endl;
                } else {
                    inventario_J2.push_back(shield);
                    cout << "escudo coletado" << endl;
                }
                break;
            }
            case 3: {
                bool jaTem = false;
                for (size_t i = 0; i < inventario_J2.size(); i++) {
                    if (inventario_J2[i]->nome == "armour") {
                        jaTem = true;
                        break;
                    }
                }
                if (jaTem) {
                    cout << "item ja adquirido" << endl;
                } else {
                    inventario_J2.push_back(armour);
                    cout << "armadura coletada" << endl;
                }
                break;
            }
            default:
                cout << "item invalido" << endl;
                break;
        }

        contador++;
    }

    cout << "\nRemova um item do primeiro jogador:" << endl;
    cout << "(1) - sword" << endl;
    cout << "(2) - shield" << endl;
    cout << "(3) - armour" << endl;
    cin >> codigo;

    string alvo;
    shared_ptr<Item> ponteiroAlvo = nullptr;

    if (codigo == 1) {
        alvo = "sword";
        ponteiroAlvo = sword;
    } else if (codigo == 2) {
        alvo = "shield";
        ponteiroAlvo = shield;
    } else if (codigo == 3) {
        alvo = "armour";
        ponteiroAlvo = armour;
    } else {
        cout << "opcao invalida" << endl;
        return 0;
    }

    bool removido = false;
    for (size_t i = 0; i < inventario_J1.size(); i++) {
        if (inventario_J1[i]->nome == alvo) {
            cout << "contagem antes (" << alvo << "): " << ponteiroAlvo.use_count() << endl;
            inventario_J1.erase(inventario_J1.begin() + static_cast<long>(i));
            cout << "item deletado do inventario do J1" << endl;
            cout << "contagem depois (" << alvo << "): " << ponteiroAlvo.use_count() << endl;
            removido = true;
            break;
        }
    }

    if (!removido) {
        cout << "item nao possuido pelo J1" << endl;
    }

    return 0;
}