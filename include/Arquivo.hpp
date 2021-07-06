#ifndef Arquivo_hpp
#define Arquivo_hpp

#include <vector>
#include <iostream>

using namespace std;

class Arquivo{
    private:
        string local;
    public:
        
        /*!
          @brief Seta a variavel 'local' do objeto que foi instanciado
          @param local_ Local onde está o arquivo.
        */
        Arquivo(string local_);

         /*!
          @brief Lê e separa as linhas do arquivo e verifica se houve algum erro de diretório.
          @param n Número de linhas a serem lidas.
          @param linha Vetor de string que armazena as linhas do arquivo.
          @return Retornar True caso não houver falhas e False caso haja.
        */
        bool read_lines(int n, vector<string> &linha);
};

#endif