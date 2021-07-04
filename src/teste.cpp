#include "KenoBet.hpp"
#include "Arquivo.hpp"

#include <iostream>   // cout, endl
#include <cassert>    // assert()
#include <random>     // random_device, mt19937
#include <iterator>   // std::begin(), std::end()

using namespace std;

//Verifica se uma string é um float
bool stringIsFloat(const string& str){
  int contadorNumero = 0;
  int contadorPonto = 0;
  for (char const &c : str) {
      if (isdigit(c) == 0 ){
        if(c=='.'){
          contadorPonto++;
          continue;
        }
        return false;
      }
      else{
        contadorNumero++;
      }
  }
  if(contadorNumero>=1 && contadorPonto<=1){
    return true;
  }
  return false;
}

//Verifica se uma string é um numero
bool stringIsInteger(const string& str){
  for (char const &c : str) {
      if (isdigit(c) == 0 ){
        return false;
      }
  }
  return true;
}

//Transforma uma Linha de um arquivo em um vetor de int
vector<unsigned short int> transformarLinhaArquivoEmInteiros(string r){

  string auxiliar = "";
  vector<unsigned short int> resultado;

  int contador = 0;
  for(char const &c : r){
    contador++;

    if(isdigit(c)){

      auxiliar=auxiliar+c;
    }

    if( c == ' ' || contador == r.size()){
      
      if(stringIsFloat(auxiliar)){

        int num = stoi(auxiliar);
        resultado.push_back(num);
      }
      auxiliar="";
    }
  }

  return resultado;
}

int main( int argc, char *argv[] ){

  if(argv[1].empty()){
    cout << ">>> Por favor informe o arquivo de apostas na inicialização do jogo" << endl
  }else{
    cout << ">>> Lendo arquivo de apostas [data/"<< argv[1] << "], por favor aguarde.." << endl;

    Arquivo arq(argv[1]);

  }



  //Testes KanoBet

  KenoBet keno;

  keno.adiciona_aposta(50.50);

  cout << "Valor saldo: " << keno.get_saldo() <<endl;

  keno.adicionar_numero(10);
  keno.adicionar_numero(12);
  keno.adicionar_numero(12);

  vector <unsigned short int> apostas = keno.get_apostas();

  cout<<"Apostas: "<< endl;
  for(int i = 0; i < apostas.size(); i++){
    cout << apostas[i] << endl;
  }

  cout<<"Quantidade de apostas: " << keno.qtd_apostas() << endl;


  const vector <unsigned short int> acertos = {10, 10, 12};

  vector <unsigned short int> numeros_acertados = keno.get_acertos(acertos);

  cout<<"Apostas acertadas: "<< numeros_acertados.size() << endl;
  
  for(int i = 0; i < numeros_acertados.size(); i++){
    cout << numeros_acertados[i] << endl;
  }

  for(int i=0; i<argc; i++){
    cout<<"Argumento["<<i<<"]: "<<argv[i]<<endl;
  }

  //Testes leitura de  Arquivos

  Arquivo a2(argv[1]);

  vector<string> r = a2.read_lines(3);

  for(int i = 0; i < r.size(); i++){
      cout<<"Linha: "<< r[i] <<endl;
  }

  float saldo_arquivo;
  int qtd_apostas_arquivo;
  
  cout <<"LEITURA ARQUIVO"<<endl;
  //Pegando o Saldo
  if( stringIsFloat(r[0]) ){

    saldo_arquivo = stof(r[0]);
    cout <<"Saldo:"<<saldo_arquivo<<endl;

  }
  //Pegando Quantidade Apostas
  if(stringIsInteger(r[1])){
    qtd_apostas_arquivo = stoi(r[1]);
    cout <<"Quantidade Apostas: "<<qtd_apostas_arquivo<<endl;
  }

  //Pegando Apostas
  
  vector<unsigned short int> apostas_arquivo = transformarLinhaStringsEmInteiros(r[2]);

  cout << "Apostas " << apostas_arquivo.size() << ":" <<endl;
  for(int i = 0; i < apostas_arquivo.size(); i++){
    cout << apostas_arquivo[i] << endl;
  }

}


