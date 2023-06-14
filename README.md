# Voto_Popular
Aplicação C++ utilizada durante a feira de ciências "Ciência Jovem" no ano de 2020 para registrar os votos dos visitantes nos projetos para a categoria "Voto Popular".

--------

A aplicação recebe como parâmetros o CPF do visitante e o código do projeto no qual se deseja votar.
Todos os registros estão armazenados nos arquivos .txt, referentes aos CPFs já utilizados, a referência textual do código de todos os projetos para confirmação e aos votos computados até então.
Nesse exemplo o arquivo que armazena os votos possui uma coluna para os códigos de projetos registrados e outra coluna com valores "0" que serão incrementados a cada voto.
O arquivo que armazena os CPFs utilizados está vazio e conterá os CPFs utilizados ao passar do tempo.

--------

A aplicação não possui método de ordenação e no exemplo aqui demonstrado foi utilizado um software de planilhas para importar o arquivo .txt dos votos e ordenar os valores de forma decrescente. 
