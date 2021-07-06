# Implementação do Jogo Keno, com interface textual
 Repositório contendo as especificações do Trabalho 1 da disciplina de LP1

# Documentação
- Você pode olhar a documentação abrindo o arquivo "Index.html" localizado em > Documentacao/Formato HTML/index.html 
- Ou se preferir pode olhar diretamente nos arquivos .hpp que estão dentro na pasta "include"

## Requisitos necessários
- Cmake >= 3.5
- C++ >= 14

## Como usar?

No mesmo diretório do projeto, crie uma pasta de sua preferência, após isso, abra um terminal dentro dessa pasta e execute os seguintes comandos:

1. `cmake ..`
2. `cmake --build .`

Após isso seu programa estará compilado e pronto para uso, basta usar o seguinte comando com o terminal aberto na pasta que você criou anteriormente:

- `./Keno "nome do arquivo de apostas".dat`

## Testes pré-definidos
Para usar um dos testes abaixo, use o seguinde comando:
`./Keno "numero do teste".dat`

1. Teste com número 80 e número 1.
2. Ordem dos números desordenada.
3. Entrada com mais de 15 números para apostar.
4. Com número maior que 80.
5. Com número menor que 1.
6. Com números repetidos.
7. Sem rodadas.
8. Sem saldo.

## Limitações

- Caso o arquivo de entrada esteja em branco ou faltando linhas o programa quebra.
- Caso exista um espaço no final das duas primeiras linhas, o programa quebra.
