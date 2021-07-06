#ifndef Servicos_hpp
#define Servicos_hpp

#include <vector>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Servicos{
    public:

        /*
          @brief Transforma uma linha em um vetor de inteiros e o retorna.
          @param r Linhas a ser transformada.
          @return Retorna um vetor de inteiros.
        */
        vector<unsigned short int> transformarLinhaArquivoEmInteiros(string r);

        /*
          @brief Gera a tabela de retorno com os multipliers para cada acerto.
          @param tamanho Quantidade de números apostados.
          @return Retorna um vetor de números float contendo os multipliers.
        */
        vector<float> gerarTabela( int tamanho );

        /*
          @brief Gera os números do sorteio de cada rodada.
          @return Retorna um vetor de inteiros contendo os números sorteados da rodada.
        */
        vector<unsigned short int> gerarNumerosAleatorios( void );

        /*
          @brief Verifica se uma string é um número inteiro.
          @param str String qualquer.
          @return Retorna True se a string possuir algúm número e False caso não.
        */
        bool stringIsInteger(const string& str);

        /*
          @brief Verifica se uma string é um número decimal.
          @param str String qualquer.
          @return Retorna True se a string for um número decimal e False caso não.
        */
        bool stringIsFloat(const string& str);

        /*
          @brief Verifica os dados do arquivo para atender requisitos definidos.
          @param dados_arquivo Vetor de inteiros que contém os número apostados.
          @param saldo Saldo disponível do jogador.
          @param num_apostas Número total de apostas.
          @return Retorna True caso o arquivo atenda os requisitos e False caso não.
        */
        bool verificaArquivo(vector<unsigned short int> dados_arquivo, float saldo, int num_apostas);
};

#endif