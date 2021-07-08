# YandexInternship2021

## Content
* [Back](#back)
	- [Андрей и кислота](#андрей-и-кислота)
	- [Посадка в самолет](#посадка-в-самолет)
	- [Расстояние](#расстояние)
* [Front](#front)
	- [Найти ошибки в коде](#найти-ошибки-в-коде)
	- [Поврежденные файлы Бальтазара](#поврежденные-файлы-бальтазара)
	- [Подземелье](#подземелье)
 
# Back
## Андрей и кислота
Андрей работает в секретной химической лаборатории, в которой производят опасную кислоту с удивительными свойствами. У Андрея есть n бесконечно больших резервуаров, расположенных в один ряд. Изначально в каждом резервуаре находится некоторое количество кислоты. Начальство Андрея требует, чтобы во всех резервуарах содержался одинаковый объем кислоты. К сожалению, разливающий аппарат несовершенен. За одну операцию он способен разлить по одному литру кислоты в каждый из первых k  (1 ≤ k ≤ n) резервуаров. Обратите внимание, что для разных операций k могут быть разными. Поскольку кислота очень дорогая, Андрею не разрешается выливать кислоту из резервуаров. Андрей просит вас узнать, можно ли уравнять объемы кислоты в резервуарах, и, если это возможно, то посчитать минимальное количество операций, которое потребуется, чтобы этого достичь.

### Формат ввода
Первая строка содержит число n  ( 1 ≤ n ≤ 100000 ) — количество резервуаров. Во второй строке содержатся n целых чисел a i  ( 1 ≤ ai ≤ 10^9 ), где  ai  означает исходный объём кислоты в  i -м резервуаре в литрах.

### Формат вывода
Если объемы кислоты в резервуарах можно уравнять, выведите минимальное количество операций, необходимых для этого.
Если это невозможно, выведите «-1».

### Пример 1
| **Ввод** | **Вывод**  |
| :------- | :--------- |
| 2 | 1 |
| 1 2 |

### Пример 2
| **Ввод** | **Вывод**  |
| :------- | :--------- |
| 5 | 4 |
| 1 1 5 5 5 |

### Пример 3
| **Ввод** | **Вывод**  |
| :------- | :--------- |
| 3 | -1 |
| 3 2 1 |

### Примечания
В первом примере достаточно одной операции с k, равным 1. Тогда в обоих резервуарах окажется по 2 литра.
Во втором примере достаточно четырех операций с k, равным 2. Тогда во всех резервуарах окажется по 5 литров.
В третьем примере объемы уравнять невозможно.


## Посадка в самолет
В самолете n рядов и по три кресла слева и справа в каждом ряду. Крайние кресла (A и F) находятся у окна, центральные (C и D) – у прохода. На регистрацию приходят группы из одного, двух или трех пассажиров. Они желают сидеть рядом, то есть на одном ряду и на одной стороне: левой или правой. Например, группа из двух пассажиров может сесть на кресла B и C, но не может сесть на кресла C и D, потому что они разделены проходом, а также не может сесть на кресла A и C, потому что тогда они окажутся не рядом. Кроме того, один из пассажиров каждой группы очень требовательный – он хочет сесть либо у окна, либо у прохода. Конечно же, каждая группа из пассажиров хочет занять места в ряду с как можно меньшим номером, ведь тогда они скорее выйдут из самолета после посадки. Для каждой группы пассажиров определите, есть ли места в самолете, подходящие для них.

### Формат ввода
Первая строка содержит число n ( 1 ≤ n ≤ 100 ) – количество рядов в самолете. Далее в n строках вводится изначальная рассадка в самолете по рядам (от первого до n-го), где символами . (точка) обозначены свободные места, символами # (решетка) обозначены занятые места, а символами _ (нижнее подчеркивание) обозначен проход между креслами C и D каждого ряда.
 
Следующая строка содержит число  m  ( 1 ≤ m ≤ 100 ) – количество групп пассажиров. Далее в m строках содержатся описания групп пассажиров. Формат описания такой:  num side position , где  num – количество пассажиров (число 1, 2 или 3), side – желаемая сторона самолета (строка left или right), position  – желаемое место требовательного пассажира (строка aisle или window).

### Формат вывода 
Если группа может сесть на места, удовлетворяющие ее требованиям, то выведите строку Passengers can take seats: и список их мест в формате row letter, упорядоченный по возрастанию буквы места. Затем выведите в n строках получившуюся рассадку в самолете, в формате, описанном выше, причем места, занятые текущей группой пассажиров, должны быть обозначены символом X.
Если группа не может найти места, удовлетворяющие ее требованиям, то выведите строку Cannot fulfill passengers requirements.
**Ответ сравнивается с правильным посимвольно, поэтому ваше решение не должно выводить никаких лишних символов, в том числе лишних переводов строк или пробельных символов в концах строк. В конце каждой строки (включая последнюю) должен быть выведен символ перевода строки.**

### Пример
| **Ввод** | **Вывод**  |
| :------- | :--------- |
| 4 | Passengers can take seats: 1B 1C |
| ..._.#. | .XX_.#. |
| .##_... | .##_... |
| .#._.## | .#._.## |
| ..._... | ..._... |
| 7 | Passengers can take seats: 2D 2E 2F |
| 2 left aisle | .##_.#. |
| 3 right window | .##_XXX |
| 2 left window | .#._.## |
| 3 left aisle | ..._... |
| 1 right window | Passengers can take seats: 4A 4B |
| 2 right window | .##_.#. |
| 1 right window | .##_### |
| | .#._.## |
| | XX._... |
| | Cannot fulfill passengers requirements |
| | Passengers can take seats: 1F |
| | .##_.#X |
| | .##_### |
| | .#._.## |
| | ##._... |
| | Passengers can take seats: 4E 4F |
| | .##_.## |
| | .##_### |
| | .#._.## |
| | ##._.XX |
| | Cannot fulfill passengers requirements |


## Расстояние
# Front
## Найти ошибки в коде
## Поврежденные файлы Бальтазара
## Подземелье
