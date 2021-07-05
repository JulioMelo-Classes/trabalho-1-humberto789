#include "KenoBet.hpp"
#include "Arquivo.hpp"
#include "Servicos.hpp"

#include <iostream>   // cout, endl
#include <cassert>    // assert()
#include <random>     // random_device, mt19937
#include <iterator>   // std::begin(), std::end()
#include <fstream>

using namespace std;

int main( int argc, char *argv[] ){

  srand(time(NULL));
  Servicos servicos;


  if( argc == 1 ){
    cout << ">>> Por favor informe o arquivo de apostas na inicialização do jogo" << endl;

  }else{
    cout << ">>> Lendo arquivo de apostas [data/"<< argv[1] << "], por favor aguarde.." << endl;

      Arquivo arq(argv[1]);
      vector<string> linha;
      
      //Lê a linha e verifica se o arquivo existe
      if(!arq.read_lines(3, linha)){
        cout<<"ERRO! Arquivo não encontrado!"<<endl;
        cout<<"Verifique se o arquivo está na pasta data!"<<endl;
      }else{

        float saldo_arquivo;
        int qtd_apostas_arquivo;
        vector<unsigned short int> apostas_arquivo;

        //Pegando o Saldo do arquivo
        if( servicos.stringIsFloat(linha[0])){
          saldo_arquivo = stof(linha[0]);
        }

        //Pegando Quantidade Apostas
        if(servicos.stringIsInteger(linha[1])){
          qtd_apostas_arquivo = stoi(linha[1]);
        }

        //Pegando Apostas
        apostas_arquivo = servicos.transformarLinhaArquivoEmInteiros(linha[2]);

        if(servicos.verificaArquivo(apostas_arquivo, saldo_arquivo, qtd_apostas_arquivo) == false){
          cout << "Corriga o erro acima e tente novamente!" << endl;

        }else{
          cout << "......................................................" << endl;
          cout << ">>> Aposta lida com sucesso!" << endl;
          cout << "    Você apostará um total de $" << saldo_arquivo << " créditos." << endl;

          float valor_por_rodada = saldo_arquivo/qtd_apostas_arquivo;

          cout << "    Jogará um total de " << qtd_apostas_arquivo << " rodadas, apostando $" << valor_por_rodada << " créditos por rodada\n" << endl;
          cout << "    Sua aposta tem " << apostas_arquivo.size() << " números, eles são [ ";

          for(unsigned short int i = 0; i < apostas_arquivo.size(); i++){
            cout << apostas_arquivo[i] << " ";
          }

          cout << "]" << endl;

          KenoBet keno;
          keno.adiciona_aposta(saldo_arquivo);
          
          for(unsigned short int i = 0; i < apostas_arquivo.size(); i++){
            keno.adicionar_numero(apostas_arquivo[i]);
          }

          //Gerando a tabela de valores

          vector<float> tabela = servicos.gerarTabela(apostas_arquivo.size());

          cout << "    ----------+-----------" << endl;
          cout << "    Hits      | Retorno" << endl;
          for(unsigned short int i = 0; i < tabela.size(); i++){
            cout << "    " << i << "         | " << tabela[i] << endl;
          }
          cout << "    ------------------------------------------------------------" << endl;

          for(int rodada = 1; rodada <= qtd_apostas_arquivo; rodada++){
            
            cout << "    Esta é a rodada #"<< rodada << " de " << qtd_apostas_arquivo << ", sua aposta é $" << valor_por_rodada << ". Boa sorte!" << endl; 

            keno.adiciona_aposta( keno.get_saldo() - valor_por_rodada );

            vector <unsigned short int> numeros_aleatorios = servicos.gerarNumerosAleatorios();
            
            cout << "    Os números sorteados são: [ ";

            for(unsigned short int i = 0; i < numeros_aleatorios.size(); i++){
              cout << numeros_aleatorios[i] << " ";
            }

            cout << "]" << endl;

            cout << endl;

            vector <unsigned short int> numeros_acertados = keno.get_acertos(numeros_aleatorios);

            cout << "    Você acertou os números: [ ";

            for(unsigned short int i = 0; i < numeros_acertados.size(); i++){
              cout << numeros_acertados[i] << " ";
            }

            cout << "], um total de " << numeros_acertados.size() << " hits de " << keno.qtd_apostas() << endl;

            float retorno = tabela[numeros_acertados.size()] * valor_por_rodada;

            cout << "    Sua taxa de retorno é " << tabela[numeros_acertados.size()] << ", assim você sai com: $" << retorno << endl;

            keno.adiciona_aposta( keno.get_saldo() + retorno );

            cout << "    Você possui um total de: $" << keno.get_saldo() << " créditos." << endl;

            if(rodada == qtd_apostas_arquivo){
              cout << ">>> Fim das rodadas!" << endl;
            }

            cout << "    ------------------------------------------------------------" << endl;

          }

          cout << endl;
          cout << "======= Sumário =======" << endl;
          cout << ">>> Você gastou um total de $" << saldo_arquivo << " créditos " << endl;

          float lucro = keno.get_saldo() - saldo_arquivo;

          cout << ">>> Hooray! você ganhou $"<< lucro << " créditos!" << endl;
          cout << ">>> Você está saindo do jogo com um total de $" << keno.get_saldo() << " créditos." << endl;
      }
    }
  }
}