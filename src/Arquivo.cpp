#include "Arquivo.hpp"
#include <fstream>

using namespace std;

Arquivo::Arquivo(std::string local_){
    local = local_;
}

bool Arquivo::read_lines(int n, vector<string> &linha){
    ifstream file1;
    file1.open("../data/" + local);

    //Verifica se houve falhar após o .open()
    if(!file1.fail()){
      for(int i=0; i<n; i++){
          string texto;
          getline(file1, texto);
          linha.push_back(texto);
      }
      file1.close();

      return true;
    }else{

      return false;
    }
}