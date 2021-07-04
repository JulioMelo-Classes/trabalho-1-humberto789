#ifndef KenoBet_hpp
#define KenoBet_hpp

#include <iostream>
#include <vector>

using namespace std;

using tipo_numero = unsigned short int; //<! tipo das apostas no keno.
using tipo_dinheiro = float; //<! Define o tipo da moeda utilizada na aplicação.
using lista_tipo_numero = std::vector< tipo_numero >;

class KenoBet {
    public:
        //! Cria uma aposta Keno vazia.
        KenoBet( ) : saldo_jogador(0)
        { /* vazio */ };

        /*! Adiciona um número a aposta apenas se o número ainda não estiver lá.
            @param spot_ O numero da aposta.
            @return true se o numero foi adicionado. False caso o contrario. */
        bool adicionar_numero( tipo_numero aposta_ );

        /*! Define a quantidade de dinheiro que o jogador está apostando.
            @param saldo_ O saldo apostado.
            @return Verdadeiro se tivermos um salário acima de zero; caso contrário, falso. */
        bool adiciona_aposta( tipo_dinheiro saldo_ );

        //! Resets a bet to an empty state.
        void resetar( void );

        /*! Recupera o salário do jogador nesta aposta.
            @return The wage value. */
        tipo_dinheiro get_saldo( void ) const;

        /*! Retorna ao número atual de apostas do jogador.
            @return Número de pontos presentes na aposta. */
        size_t qtd_apostas( void ) const;

        /*! Determine quantos pontos correspondem aos acertos passados ​​como argumento.
            @param hits_ Lista de acertos gerados randomicamento pelo computador.
            @return Um vetor com a lista de acertos. */
        lista_tipo_numero get_acertos( const lista_tipo_numero acertos_ ) const;

        /*! Return a vector< spot_type > com os pontos que o jogador escolheu até agora.
            @return The vector< spot_type > com os pontos do jogador escolhidos até agora. */
        lista_tipo_numero get_apostas( void ) const;

    private:
        lista_tipo_numero apostas_jogador;  //<! Apostas do jogador.
        tipo_dinheiro saldo_jogador;             //<! O saldo do jogador
};

#endif