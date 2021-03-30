Avaliação 2 de Programação Funcional
========================

ATENÇÃO
-------

* A interpretação dos enunciados faz parte
da avaliação.

* A avaliação deve ser resolvida INDIVIDUALMENTE.
Se você discutir soluções com outros alunos da
disciplina, deverá mencionar esse fato como
parte dos comentários de sua solução.

* Se você utilizar recursos disponíveis na internet
e que não fazem parte da bibliografia, você deverá
explicitamente citar a fonte apresentando o link
pertinente como um comentário em seu código.

* Todo código produzido por você deve ser acompanhado
por um texto explicando a estratégia usada para a
solução. Lembre-se: meramente parafrasear o código
não é considerado uma explicação!

* Não é permitido modificar a seção Setup inicial
do código, seja por incluir bibliotecas ou por
eliminar a diretiva de compilação -Wall.

* Seu código deve ser compilado sem erros e warnings
de compilação. A presença de erros acarretará em
uma penalidade de 20% para cada erro de compilação e
de 10% para cada warning. Esses valores serão descontados
sobre a nota final obtida pelo aluno.

* Todo o código a ser produzido por você está marcado
usando a função "undefined". Sua solução deverá
substituir a chamada a undefined por uma implementação
apropriada.

* Cada questão desta avaliação possui o valor de 1,0 ponto.

* Sobre a entrega da solução:

1. A entrega da solução da avaliação deve ser feita
como um único arquivo .zip contendo todo o projeto
stack usado.

2. O arquivo .zip a ser entregue deve usar a seguinte
convenção de nome: MATRÍCULA.zip, em que matrícula é
a sua matrícula. Exemplo: Se sua matrícula for
20.1.2020 então o arquivo entregue deve ser
2012020.zip. A não observância ao critério de nome e
formato da solução receberá uma penalidade de 20%
sobre a nota obtida na avaliação.

3. O arquivo de solução deverá ser entregue usando a
atividade "Entrega da Avaliação 2" no Moodle dentro do
prazo estabelecido.

4. É de responsabilidade do aluno a entrega da solução
dentro deste prazo.

5. Sob NENHUMA hipótese serão aceitas soluções fora do
prazo ou entregues usando outra ferramenta que
não a plataforma Moodle.


Setup inicial
-------------

> {-# OPTIONS_GHC -Wall #-}

> module Main where

> import System.Environment
> import ParseLib

Processando arquivos DOT
------------------------


DOT é uma linguagem simples para descrição de grafos.
Um descrição de grafo é iniciada pelas palavras reservadas
`graph` ou `digraph` seguida de um nome para o grafo definido
e uma listagem de arestas.

Considere o seguinte grafo.

![Grafo não directionado](graph.png){ height=80px, width=60 }

O código dot correspondente é dado por

```
graph graphname {
    a--b;
    b--c;
    b--d;
}
```

Note que arestas entre dois nós são especificadas pelos caracteres `--`.
Para especificar um grafo direcionado, basta iniciar a definição usando
a palavra reservada `digraph` e especificar arestas usando `->`, como se
segue.

```
digraph graphname {
    a -> b;
    b -> c;
    b -> d;
}
```

A figura 2 ilustra o grafo direcionado descrito pelo trecho de
código anterior.

![Grafo não directionado](directed.png){ height=80px, width=60 }


O objetivo desta avaliação é o desenvolvimento de um parser para
arquivos dot. Para esse intuito, faça o que se pede a seguir.


Definindo arquivos DOT
----------------------

O primeiro passo é definir um tipo de dados para representar arquivos dot.
O tipo `Graph` a seguir representa grafos direcionados e não direcionados.

> data Graph = Undirected Id [Edge]
>            | Directed Id [Edge]
>            deriving Eq

O tipo `Id` é usado para representar identificadores e é simplesmente um sinônimo
para strings.

> type Id = String

O tipo `Edge` especifica arestas que são representadas por pares de identificadores.

> type Edge = (Id,Id)

Usando os tipos de dados acima, podemos descrever o grafo não direcionado apresentado
anteriormente pelo seguinte valor:

> undirected :: Graph
> undirected = Undirected "graphname"
>                         [ ("a", "b")
>                         , ("b", "c")
>                         , ("b", "d")]


Questão 1. Elabore uma instância de `Show` para o tipo Graph de forma que a string retornada
seja o código dot correspondente ao grafo fornecido como argumento de entrada. Como exemplo,
considere a seguinte string gerada ao executar a função `show` sobre o grafo `undirected`

```
$> show undirected
graph graphname {\na -- b ; b -- c ; b -- d ; \n}
```

comentário: Para essa questão, temos três casos: quando o Grafo for Undirected, Directed e quando ele não
existir. Diante disso, criamos instanciamos para os três casos. Também criei duas funções extras para
concatenação dos "Id's" recursivamente para casa construtor

> instance Show Graph where
>   show (Undirected _ list) = "graph " ++ " {\n " ++ (showUnEdge list) ++ " \n}"
>   show (Directed _ list) = "graph " ++ " {\n " ++ (showDeEdge list) ++ " \n}"

> showUnEdge :: [Edge] -> String
> showUnEdge ((a, b):xs) = a ++ " -- " ++ b ++ " ; " ++ (showUnEdge xs)
> showUnEdge [] = ""

> showDeEdge :: [Edge] -> String
> showDeEdge ((a, b):xs) = a ++ " -> " ++ b ++ " ; " ++ (showDeEdge xs)
> showDeEdge [] = ""

Questão 3. A biblioteca de parsing possui a função

```haskell
identifier :: Parser Char String
```

que realiza o parsing de um identificador. Porém, idealmente,
esse e outros parsers da biblioteca deveriam descartar espaços
em branco do texto fornecido na entrada.

Infelizmente, esse não é o caso. A biblioteca fornece a função

```haskell
whitespace :: Parser Char ()
```

que consome todos os caracteres em branco de um prefixo da entrada.

Combine essas funções para implementar o parser

comentário: a função ident usa o identifier que retorna o identificador. Depois uso o <*> para passar 
o parser para whitespace e retirar os espaços em brancos, criando uma função extra 'f' para lidar com
o resultado das duas funções utilizadas, utilizando da função fmap. 

> ident :: Parser Char String
> ident = f <$> whitespace <*> identifier
>    where
>         f _ x = x

que faz o parsing de um identificador descartando caracteres em branco
presentes no início da entrada.

Questão 4. A biblioteca de parsing possui a função

```haskell
token :: String -> Parser Char String
```

que realiza o parsing de uma string fornecida como entrada. Assim como a
função `identifier`, `token` não remove os caractees em branco presentes
no início da entrada. Implemente a função:

comentário: essa questão é quase identica a anterior, porém precisamos trabalhar com a string de 
entrada. 

> tok :: String -> Parser Char String
> tok s = f <$> whitespace <*> (token s)
>    where
>         f _ x = x

que processa a string s, fornecida como argumento, descartando
quaisquer caracteres em branco que possam estar presentes no início da
entrada.

Questão 5. Usando as funções anteriores construa o parser

comentário: para fazer o edgeParse, temos que pensar como separar edges e colocar em uma tupla.
Com isso, usamos as duas funções já feitas anteriormente: a ident para pegar os dois Id's e o tok
que ajuda com o separador.

> edgeParser :: String -> Parser Char Edge
> edgeParser s = f <$> ident <*> (tok s) <*> ident
>   where
>      f x _ y = (x, y)

que processa uma aresta no formato dot. A função `edgeParser`
recebe como parâmetro uma string que representa o separador
dos nós que formam uma aresta no grafo.


Questão 6. O objetivo desta questão é implementar um parser para
a lista de arestas presente entre chaves "{" e "}" em um arquivo dot.
A função `bodyParser` deve receber como argumento uma string que
denota o separador entre nós que compõe as arestas a serem processadas.

comentário: com a ajuda do Carlos Eduardo, fiz uma função para cada construtor, além de funções auxiliares
para concatenação dos edges na lista usando recursão

> bodyParser :: String -> Parser Char [Edge]
> bodyParser s = pack (tok "{") (undirRec s) (tok "}")


> bodyParser' :: String -> Parser Char [Edge]
> bodyParser' s = pack (tok "{") (dirRec s) (tok "}")



> undirRec :: String -> Parser Char [Edge]
> undirRec s = (f <$> (edgeParser "--") <*> (tok s) <*> (undirRec s)) <|> succeed []
>     where
>         f x _ y = (x:y)

> dirRec :: String -> Parser Char [Edge]
> dirRec s = (f <$> (edgeParser "->") <*> (tok s) <*> (dirRec s)) <|> succeed []
>     where
>         f x _ y = (x:y)



Para impelmentar essa função, utilize as funções anteriores e a função

```haskell
pack :: Parser s a -> Parser s b ->
        Parser s c -> Parser s b
```

da biblioteca de parsing.


Questão 7. De posse das funções anteriores, podemos criar a função

comentario: serve tanto para a questão 7 quanto para a 8. contando como está a minha string do parser 
("graph graphname {a--b; c--b;}") e uso os parsers ident e bodyParser para separar o nome e os edges, e 
depois usar o construtor para finalmente ter o meu tipo Graph pronto


> undirParser :: Parser Char Graph
> undirParser = f <$> ident <*> ident <*> (bodyParser ";")
>    where
>        f _ b c = (Undirected b c)

que realiza o parsing de uma string em formato dot que descreve um
grafo não direcionado.


Questão 8. Implemente a função

> dirParser :: Parser Char Graph
> dirParser = f <$> ident <*> ident <*> (bodyParser' ";")
>    where
>        f _ b c = (Directed b c)

que realiza o parsing de uma string em formato dot que descreve um grafo
direcionado.

Questão 9. Usando as duas funções anteriores, implemente o parser
para strings descrevendo grafos usando o formato dot.

comentário: agora eu só preciso saber qual construtor usar, seja ele o Undirected ou o Directed.
Para isso, usamos o functor <|>, que me permite usar um parser ou o outro

> dotParser :: Parser Char Graph
> dotParser = undirParser <|> dirParser


Questão 10. O último componente do seu parser é ser capaz de processar
arquivos texto contendo código dot usando o parser construído nas questões
anteriores e exibindo, na saída padrão, o nome do grafo processado e a
quantidade de arestas presente neste grafo.

Para isso, você deve ser capaz de receber um nome de arquivo ao
executar seu código em linha de comando usando a função `getArgs`, presente
na biblioteca  `System.Environment`. Para usar essa biblioteca, inclua
a seguinte definição de import no cabeçalho deste arquivo, como se segue:

```haskell
module Main where

import System.Environment
import ParseLib
```

A função `getArgs :: IO [String]`
retorna uma lista contendo os argumentos de linha de comando fornecidos quando
da execução de seu programa no terminal. Argumentos adicionais podem ser fornecidos
da seguinte maneira via stack:

```
$> stack build
$> stack exec prova2-exe -- teste.dv
```

Considerando o acima exposto, implemente a função `main :: IO ()` que, a partir de
um nome de arquivo fornecido como argumento, faz o parsing da descrição no formato dot
e imprime, na saída padrão, o nome do grafo e o seu número de arestas.

comentario: Discutindo com Carlos Eduardo, percebemos que a quando chamamos o parser dotParser,
o retorno dela saía como [(Graph, [Char])]. Para podermos contar o numero de arestas retiramos somente
a lista de Char da tupla e chamamos a função length, que retorna o tamanho de uma lista.
Fizemos o mesmo para retirar o nome do Grafo da tupla. Logo após, reutilizamos o código referente ´
a um código feito na aula ao vivo, referente a um exercício da aula 14, para leitura de arquivos. 

> contArestas :: [(Graph, [Char])] -> Int
> contArestas (((Undirected _ b), _): _) = length b
> contArestas (((Directed _ b), _): _) = length b
> contArestas [] = 0

> nameGraph :: [(Graph, [Char])] -> String
> nameGraph (((Undirected a _), _): _) = a
> nameGraph (((Directed a _), _): _) = a
> nameGraph [] = "Empty"

> main :: IO ()
> main = do
>       args <- getArgs
>       case args of
>         [] -> putStrLn "Erro!\nInforme um arquivo"
>         (f : _) -> do
>                      s <- readFile f
>                      let ls = runParser dotParser s
>                      putStrLn $ "Numero de Arestas: " ++ (show (contArestas ls))
>                      putStrLn $ "Nome do Grafo: " ++ (nameGraph ls)
