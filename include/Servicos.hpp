#ifndef Servicos_hpp
#define Servicos_hpp

#include <vector>
#include <iostream>

using namespace std;

class Servicos{
    public:
        vector<unsigned short int> transformarLinhaArquivoEmInteiros(string r);
        vector<float> gerarTabela( int tamanho );
        vector<unsigned short int> gerarNumerosAleatorios( void );
        bool stringIsInteger(const string& str);
        bool stringIsFloat(const string& str);
};

#endif