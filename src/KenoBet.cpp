#include "KenoBet.hpp"

bool KenoBet::adiciona_aposta( tipo_dinheiro saldo_ ){

  if(saldo_ >= 0){
    saldo_jogador = saldo_;

    return true;
  }
  
  return false;
}

tipo_dinheiro KenoBet::get_saldo( void ) const{

  return saldo_jogador;
}

lista_tipo_numero KenoBet::get_apostas( void ) const{
  
  return apostas_jogador;
}

bool KenoBet::adicionar_numero( tipo_numero aposta_ ){
  
  //Verificar se o numero já existe
  for(int i = 0; i < apostas_jogador.size(); i++){
    if(aposta_ == apostas_jogador[i]){
      return false;
    }
  }

  //Adicionando a nova aposta
  apostas_jogador.push_back(aposta_);

  return true;
}

size_t KenoBet::qtd_apostas( void ) const{

  return apostas_jogador.size();
}

void KenoBet::resetar( void ){

  apostas_jogador.clear();
  saldo_jogador = 0;

}


lista_tipo_numero KenoBet::get_acertos( const lista_tipo_numero acertos_ ) const{

  lista_tipo_numero numeros_acertados;

  for(int i = 0; i < apostas_jogador.size(); i++){
    
    for(int j = 0; j < acertos_.size(); j++){

      //Verificando se o numero do jogador na posição i está na lista dos acertos 
      if(apostas_jogador[i] == acertos_[j]){

        bool resultado = true;

        //Verificando se o numero já foi adicionado a lista de numeros acertados
        for(int k = 0; k < numeros_acertados.size(); k++){
          if(numeros_acertados[k] == apostas_jogador[i]){
            resultado = false;
          }
        }

        if(resultado){
          numeros_acertados.push_back(apostas_jogador[i]);
        }
      }
    }
  }

  return numeros_acertados;

}