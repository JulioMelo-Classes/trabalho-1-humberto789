#include "Arquivo.hpp"
#include <fstream>

using namespace std;

Arquivo::Arquivo(std::string local_){
    local = local_;
}

void Arquivo::write_ln(std::string texto){
    ofstream file1;
    file1.open(local, ios::app);
    //cout << "texto"<<endl;
    file1<<texto<<endl;
    file1.close();
}

std::vector<std::string> Arquivo::read_lines(int n){
    ifstream file1;
    file1.open("../data/" + local);
    //cin >> var;
    std::vector<string> v;
    for(int i=0; i<n; i++){
        string texto;
        getline(file1, texto);
        v.push_back(texto);
    }
    file1.close();

    return v;
}