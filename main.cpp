#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef struct {
    string nome;
    int orcamento;
    vector<int> caracteristicas;
} Filme;

int main () {
    vector<Filme> filmes;
    
    int orcamentoDisponivel, idFilme = 0;        
    cin >> orcamentoDisponivel;
    
    string nome = "";
    while (cin >> nome) {
        int orcamento = 0, quantCaracteristicas = 0;
        cin >> orcamento;
        cin >> quantCaracteristicas;
        
        filmes.push_back(*new Filme());
        filmes[idFilme].nome = nome;
        filmes[idFilme].orcamento = orcamento;
        
        for (int i = 0; i < quantCaracteristicas; i++) {
            int entrada = 0;
            cin >> entrada;
            filmes[idFilme].caracteristicas.push_back(entrada);
        }
        idFilme++;
    }
    
    return 0;
}#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef struct {
    string nome;
    int orcamento;
    vector<int> caracteristicas;
} Filme;

int main () {
    vector<Filme> filmes;
    
    int orcamentoDisponivel, idFilme = 0;        
    cin >> orcamentoDisponivel;
    
    string nome = "";
    while (cin >> nome) {
        int orcamento = 0, quantCaracteristicas = 0;
        cin >> orcamento;
        cin >> quantCaracteristicas;
        
        filmes.push_back(*new Filme());
        filmes[idFilme].nome = nome;
        filmes[idFilme].orcamento = orcamento;
        
        for (int i = 0; i < quantCaracteristicas; i++) {
            int entrada = 0;
            cin >> entrada;
            filmes[idFilme].caracteristicas.push_back(entrada);
        }
        idFilme++;
    }
    
    return 0;
}