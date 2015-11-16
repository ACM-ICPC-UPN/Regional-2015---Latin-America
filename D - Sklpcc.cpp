//	Name: D.cpp
//	Copyright: Copyright (C) 2015 LizaPastoreameLento
//	Author: Sklpcc
//	Date: 16/11/15 15:14
//	Description: 2015 ACM ICPC South American Regional's D problem "D as in Daedalus".

/*
* Descripcion del problema:
	N jugadores (C: i[0 - n>) participan en M rondas,
	en cada ronda el banco saca un presupuesto B,
	los jugadores tienen disponibles 5 cartas (1, 10, 100, 1000, 10000),
	en cada turno eligen solo 1 de ellas (nadie sabe la eleccion del otro),
	si la suma de estas es menor o igual que B, cada jugador ganara la cantidad descrita en la carta.
	Las cartas retornan a cada jugador antes del siguiente turno.
* Objetivo:
	Dada la informacion del juego, maximizar la cantidad que pudo haber ganado Dedalo (el primer jugador),
	de haber elegido la mejor carta en cada turno.
* Enfoque:
	Greedy
*/

#include <iostream>
using namespace std;

int main()
{
	/*
		n		cantidad de participantes
		m		cantidad de rounds
		b		presupuesto anunciado por el banco
		c		carta que el participante (j [0 - n>) eligio
		d		carta elegida por dedalo (j == 0)
		pd		puntos ganados por dedalo
		npd		la nueva cantidad maxima que pudo haber ganado dedalo
		sum		suma de las cartas elegidas por los participantes
		cards	arreglo (5)[0 - 4] con las cartas que disponen todos los participantes
	*/
    int n, m, b, c, d, pd, npd, sum, cards[5] = {10000, 1000, 100, 10, 1};

    /*while(*/cin >> n >> m;/*)*/
    //{
    pd = npd = 0;
    for(int i = 0; i < m; i++) //rounds
	{
		sum = 0;
		cin >> b; //presupuesto
		for(int j = 0; j < n; j++)
		{
			cin >> c;
			if(!j) d = c; //primer turno, dedalo
			sum += c;
		}
		if(sum <= b) pd += d; //si la suma es menor o igual ganan
		sum = b - (sum - d); //la cantidad maxima que pudo elegir dedalo para ganar
		if(sum < 0) continue; //si la suma de los participantes (sin dedalo) es mayor, ninguna sera valida
		for(int j = 0; j < 5; j++)
		{
			if(sum - cards[j] >= 0)
			{
				npd += cards[j]; //se elije la mayor carta posible para un maximo beneficio
				break;
			}
		}
	}
	cout << npd - pd << endl;
	//}
    return 0;
}

/*
- Input:
5 3
300 10 100 10 1 10
1100 100 10 100 1 1000
1200 100 100 10 1 1000
- Output:
100

- Input:
3 2
2000 1000 1000 1000
21 1 1 10
- Output:
9
*/
