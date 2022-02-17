# Descriere
Tema se bazeaza pe o forma a jocului de Scrabble in care am folosit matrici si functii pentru prelucrarea sirurilor de caractere. Scopul final este implementarea completa a jocului astfel incat doi participanti (programul implementat impotriva checker-ului) sa poata sa joace alternativ si sa se determine un castigator.

In fisierul scrabble.h se afla vectorul de cuvinte folosit de program

# Rulare program

```
1
N
Y1 X1 D1 WORD1
Y2 X2 D2 WORD2
…
Yn Xn Dn WORDn
```
unde
```
N -> numar de cuvinte primite
Yi -> coloana unde va fi plasat cuvantul(aici va fi plasata prima litera din WORDi)
Xi -> linia unde va fi plasat cuvantul WORDi(aici va fi plasata prima litera din WORDi)
Di -> directia in care este scris cuvantul WORDi
* Daca D == 0: cuvantul e scris pe orizontala, de la (Yi, Xi) spre dreapta
* Daca D == 1: cuvantul e scris pe verticala, de la (Yi, Xi) in jos
```
Scorurile literelor sunt urmatoarele:
```
A, E, I, L, N, O, R, S, T, U - 1 Punct
D, G - 2 Puncte
B, C, M, P - 3 Puncte
F, H, V, W, Y - 4 Puncte
K - 5 Puncte
J, X - 8 Puncte
Q, Z - 10 Puncte
```
# Functionalul task-urilor
## Task 1
Pentru acest task se citeste numarul intreg N urmat de N linii continand coordonatele unui cuvant si cuvantul respectiv. Dupa ce sa facut citirea unei linii, aceasta se adauga la coordonatele corespunzatoare in matricea de joc. Cuvantul va fi pastrat caracter cu caracter in matrice incepand cu coordonatele date.

Dupa ce se salveaza toate cele N cuvinte se afiseaza matricea apeland functia de afisare:
```
print_board(game_board)
```
## Task 2
Pentru aceasta task se calculeaza punctajul obtinut de doi jucatori fara a tine cont de punctele bonus. Input-ul este exact ca la task-ul precedent, dar output-ul va fi punctajul total al celor doi jucatori.

Primul jucator va lua cuvintele cu indicele impar
Al doilea jucator va lua cuvintele cu indicele par

Calcularea scorului unui cuvant se face prin insumarea scorului fiecarei litere din cuvant

## Task 3
### Tabla de punctaj bonusuri
Aceasta tabla (bonus_board) este data in fisierul header (scrabble.h)

Aceasta tabla va avea aceeasi dimensiune ca si tabla de joc, de 15 X 15. Tabla este populata cu valori de 0, 1 si 2 cu urmatoarea semnificatie:
```
0 - niciun bonus
1 - punctajul se dubleaza daca pe patratica respectiva se afla o litera apartinand unui cuvant care are substringul “XX” in compozitie, se da substringul la fiecare joc
2 - punctajul se tripleaza daca pe patratica respectiva se afla o litera apartinand unui cuvant care se termina cu substringul “YY”, se da substringul la fiecare joc
```
Pentru aceasta cerinta se calculeaza punctajul celor doi jucatori, ca la task-ul precedent, dar de aceasta data se verifica daca sunt indeplinite conditiile de bonus.
Se da un input de forma:
```
3
XX
YY
N
Y1 X1 D1 WORD1
Y2 X2 D2 WORD2
```
Unde:
```
XX este substringul pentru bonusul primit pentru casutele marcate cu 1. 
YY este substringul pentru bonusurile primite pentru casutele marcate cu 2.
N este numarul de cunvinte
Xi, Yi, WORDi sunt coordonatele pentru cuvantul WORDi
Di este directia in care este scris cuvantul
```
## Task 4
Se cere gasirea primul cuvant din vectorul de cuvinte (vectorul words din fisierul scrabble.h) pe care il poate juca jucatorul 2 si care indeplineste conditiile:

- Face parte din lista de cuvinte (vectorul words din fisierul scrabble.h)
- Cuvantul nu e deja pus pe tabla de niciunul dintre jucatori
- Prima litera din cuvant se afla deja pe tabla si cuvantul poate fi pus in continuarea literei respective, fie pe orizontala, fie pe verticala. (Pentru a verifica acest lucru, se cauta pe tabla prima litera din cuvant de la coltul stanga sus, linie cu linie, pana la coltul dreapta jos al tablei de joc.).
- Cuvantul nu iese din marginile tablei de joc si nu se suprapune cu alte cuvinte (inafara de prima litera)

## Task 5
Pentru acest task se va face acelasi lucru ca si la task-ul precedent, dar de aceasta data se va alege cuvantul din lista de cuvinte care va aduce castigul (sau remiza) pentru Player 2

## Task 6
Pentru acest task se va simula jocul intre cei doi jucatori. Mai exact, daca inainte la input se primea alternativ cuvintele pentru Player 1 si Player 2, de aceasta se va primi numai cuvintele pentru Player 1, iar cele pentru Player 2 vor fi alese din lista de cuvinte cu conditiile de la task-ul anterior. Dupa fiecare cuvant pus de player 1 se va alege ce cuvant va fi jucat de player 2.

Drepturile de autor fata de crearea checkerului si conditiei apartin echipei de Programare a Calculatoarelor 2020

Implementarea codului: Calmis Liviu