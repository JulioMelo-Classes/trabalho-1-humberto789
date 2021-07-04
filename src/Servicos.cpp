#include "Servicos.hpp"

//Verifica se uma string é um float
bool Servicos::stringIsFloat(const string& str){
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
bool Servicos::stringIsInteger(const string& str){
  for (char const &c : str) {
      if (isdigit(c) == 0 ){
        return false;
      }
  }
  return true;
}

//Transforma uma Linha de um arquivo em um vetor de int
vector<unsigned short int> Servicos::transformarLinhaArquivoEmInteiros(string r){

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

//Gerar Tabela de apostas
vector<float> Servicos::gerarTabela( int tamanho ){

  vector<float> resultado;

  switch(tamanho) {
    case 0:
      resultado.push_back(0);
      break;
    case 1:
      resultado.push_back(0); resultado.push_back(3);
      break;
    case 2:
      resultado.push_back(0); resultado.push_back(1);resultado.push_back(9);
      break;
    case 3:
      resultado.push_back(0); resultado.push_back(1);resultado.push_back(2);resultado.push_back(16);
      break;
    case 4:
      resultado.push_back(0); resultado.push_back(0.5);resultado.push_back(2);resultado.push_back(6);resultado.push_back(12);
      break;
    case 5:
      resultado.push_back(0); resultado.push_back(0.5);resultado.push_back(1);resultado.push_back(3);resultado.push_back(15);resultado.push_back(50);
      break;
    case 6:
      resultado.push_back(0); resultado.push_back(0.5);resultado.push_back(1);resultado.push_back(2);resultado.push_back(3);resultado.push_back(30);resultado.push_back(75);
      break;
    case 7:
      resultado.push_back(0); resultado.push_back(0.5);resultado.push_back(0.5);resultado.push_back(1);resultado.push_back(6);resultado.push_back(12);resultado.push_back(36);resultado.push_back(100);
      break;
    case 8:
      resultado.push_back(0); resultado.push_back(0.5);resultado.push_back(0.5);resultado.push_back(1);resultado.push_back(3);resultado.push_back(6);resultado.push_back(19);resultado.push_back(90);resultado.push_back(720);
      break;
    case 9:
      resultado.push_back(0); resultado.push_back(0.5);resultado.push_back(0.5);resultado.push_back(1);resultado.push_back(2);resultado.push_back(4);resultado.push_back(8);resultado.push_back(20);resultado.push_back(80);resultado.push_back(1200);
      break;
    case 10:
      resultado.push_back(0); resultado.push_back(0);resultado.push_back(0.5);resultado.push_back(1);resultado.push_back(2);resultado.push_back(3);resultado.push_back(5);resultado.push_back(10);resultado.push_back(30);resultado.push_back(600);resultado.push_back(1800);
      break;
    case 11:
      resultado.push_back(0); resultado.push_back(0);resultado.push_back(0.5);resultado.push_back(1);resultado.push_back(1);resultado.push_back(2);resultado.push_back(6);resultado.push_back(15);resultado.push_back(25);resultado.push_back(180);resultado.push_back(1000);resultado.push_back(3000);
      break;
    case 12:
      resultado.push_back(0); resultado.push_back(0);resultado.push_back(0);resultado.push_back(0.5);resultado.push_back(1);resultado.push_back(2);resultado.push_back(4);resultado.push_back(24);resultado.push_back(72);resultado.push_back(250);resultado.push_back(500);resultado.push_back(2000);resultado.push_back(4000);
      break;
    case 13:
      resultado.push_back(0); resultado.push_back(0);resultado.push_back(0);resultado.push_back(0.5);resultado.push_back(0.5);resultado.push_back(3);resultado.push_back(4);resultado.push_back(5);resultado.push_back(20);resultado.push_back(80);resultado.push_back(240);resultado.push_back(500);resultado.push_back(3000);resultado.push_back(6000);resultado.push_back(7500);
      break;
    case 14:
      resultado.push_back(0); resultado.push_back(0);resultado.push_back(0);resultado.push_back(0.5);resultado.push_back(0.5);resultado.push_back(2);resultado.push_back(3);resultado.push_back(5);resultado.push_back(12);resultado.push_back(50);resultado.push_back(150);resultado.push_back(500);resultado.push_back(1000);resultado.push_back(2000);resultado.push_back(7500);
      break;
    case 15:
      resultado.push_back(0); resultado.push_back(0);resultado.push_back(0);resultado.push_back(0.5);resultado.push_back(0.5);resultado.push_back(1);resultado.push_back(2);resultado.push_back(5);resultado.push_back(15);resultado.push_back(50);resultado.push_back(150);resultado.push_back(300);resultado.push_back(600);resultado.push_back(1200);resultado.push_back(2500);resultado.push_back(10000);
      break;
    default:
      break;
  }

  return resultado;
}

//Gera 20 numeros aleatorios de 0 a 100
vector<unsigned short int> Servicos::gerarNumerosAleatorios( void ){
  vector<unsigned short int> resultado;
  for(int i = 0; i < 20; i++){
    resultado.push_back(rand()% 80 + 1);
  }
  return resultado;
}

//Valida os dados do arquivo de apostas
bool Servicos::verificaArquivo(vector<unsigned short int> dados_arquivo, float saldo, int num_apostas){

  //Verifica se algúm número ultrapassa o range
  for(int i = 0; i < dados_arquivo.size(); i++){
      if(dados_arquivo[i] < 1 || dados_arquivo[i] > 80){
        cout << "ERRO! Os números devem estar entre 1 e 80!" << endl;
        return false;
      }
  }

  if(saldo <= 0){
    cout << "ERRO! Por favor, informe na linha 1 do arquivo um saldo valido!" << endl;
    return false;

  }else if(num_apostas <= 0){
    cout << "ERRO! Por favor, informe na linha 2 do arquivo uma quantidade de apostas validas!" << endl;
    return false;

  }else if(dados_arquivo.size() == 0){
    cout << "ERRO! Por favor, informe na linha 3 os numeros que você quer apostar!" << endl;
    return false;

  }else if(dados_arquivo.size() > 15){
    cout << "ERRO! Você só pode escolher no máximo 15 números para apostar" << endl;
    return false;  

  }else{
    return true;

  }
}