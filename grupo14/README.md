# Crappy Roulette
### Por:
>**Diogo Maia** - 21502575
>**José Lopes** - 21803474

## Introdução

Este projecto foi desenvolvido com o âmbito de implementar um jogo de roleta programado na **linguagem C**.
Apesar de este projecto ter sido bastante interessante, a resolução foi bastante atribulada. 

## Como foi feito...
Começou-se por tentar criar um menu exatamente igual ao que o foi exemplificado no enunciado no ***GitHub***, mas não conseguimos. Para dar a volta a este problema, usámos um menu composto pelo comando `switch` e respetivos `cases`, onde cada `case` corresponde a uma opção do menu. Depois disto, encontrámos mais alguns problemas ao tentar implementar a função `rand`, pois sempre que se rolava a roleta, saía o mesmo número. Tivemos que investir mais tempo em perceber como escrever a função corretamente e em como funciona a *seed* da função `rand`. Após alguma exprimentação, conseguimos obter números aleatórios consistentemente.

Consequentemente tivemos que voltar a ir estudar o comando `for` para perceber como fazer com que o programa verifique se o número que tinha saído na roleta pertencia a algum *array* (foram feitos *arrays* para os números pares e ímpares, pois não sabíamos como fazer de outra maneira). Este sim foi o grande desafio do desenvolvimento do programa, pelo menos para nós.  Foram percorridos todos os *slides* das aulas que o professor disponibilizou e assistimos a inúmeros tutoriais no *YouTube* e outros sites até conseguir escrever o código correto.

A implementação de *delay* foi baseado numa *thread* do site ***Stack Overflow***, pois não tivemos conhecimento suficiente para conseguir fazer por nós mesmos. Do resto do código, nada foi copiado. Alterámos e modificámos bastantes coisas que foram vistas em variados sites e nos *slides* para obter código que conseguissemos compreender e que compilasse sem problemas.

## Observações finais e matéria aprendida
A realização deste projecto permitiu-nos com que percebessemos melhor o uso de diferentes variáveis dadas em aula, como `int` e `char`, e a funcionalidades dos ciclos `for` e `while`, sendo este último mais indicado para um **jogo de chance** como a roleta, pois **nunca saberemos o número de ciclos** que irão ser executados. Os arrays são usados para armazenar uma colecção de dados, neste caso, dos números de **0 a 36** nos quais a bola poderia ter parado. 
Por fim, a declaração do `switch` acabou por dinamizar o controlo de fluxo de cada situação que acontece no jogo, o que levou à criação de vários `case`. Se nenhum destes casos são verdadeiros, então é corrido um caso extra, `default`,  que aparece sempre no fim do `switch`.  

Por fim,  a utilização da função `rand` ajudou-nos não só a conseguir obter números aleatórios de forma consistente como também perceber o seu potencial: retorna um *pseudo* número aleatório num intervalo de 0 a `RAND_MAX`. `RAND_MAX`é uma constante  cujo valor padrão pode variar entre implementações, mas é garantido ser, pelo menos, 32767.
 ### Referências bibliográficas
> - [https://www.youtube.com/watch?v=w3-0Ut0QQtU&fbclid=IwAR2VVoLpfpvCutbw_Xevm5Xf_gfN8pLXhqduVARtKjMyidgzjlsfPyQdtdI](https://www.youtube.com/watch?v=w3-0Ut0QQtU&fbclid=IwAR04TguY4ythQaBs-mUzgzUnCZXXn2Oy64x3GML76YYQNgVQlaDqAHs_PA8)
> - [https://www.youtube.com/watch?v=-CpG3oATGIs&t=6687s](https://www.youtube.com/watch?v=-CpG3oATGIs&t=6687s&fbclid=IwAR1jnXDtuT5TLFqJjS8dYBfeR7krgTBFMGagu3Sz28gJBmEj4pRw1bUufIc)
> - [https://stackoverflow.com/questions/46675878/random-number-from-array-c](https://stackoverflow.com/questions/46675878/random-number-from-array-c?fbclid=IwAR32hnyxxfKozDO76y-23GffA7x-8itsIFkqeFeYRX9Zd1-GVLnOHcFDrJU)
> - [https://stackoverflow.com/questions/27447195/how-to-use-delay-function-in-c-using-codeblocks-13-12mingw](https://stackoverflow.com/questions/27447195/how-to-use-delay-function-in-c-using-codeblocks-13-12mingw?fbclid=IwAR1TVfqE5v_M63oEGNniTSE_6JmXCtJxW94l-V8hMsM0-Cino92_3qo-XG4)
> - https://www.tutorialspoint.com/c_standard_library/c_function_rand.htm


