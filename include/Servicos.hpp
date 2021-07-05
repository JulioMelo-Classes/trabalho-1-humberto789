#ifndef Servicos_hpp
#define Servicos_hpp

#include <vector>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Servicos{
    public:
        vector<unsigned short int> transformarLinhaArquivoEmInteiros(string r);
        vector<float> gerarTabela( int tamanho );
        vector<unsigned short int> gerarNumerosAleatorios( void );
        bool stringIsInteger(const string& str);
        bool stringIsFloat(const string& str);
        bool verificaArquivo(vector<unsigned short int> dados_arquivo, float saldo, int num_apostas);
};

#endif