#pragma once
#include "pole.h"
#include <iostream>

using namespace std;

class Plansza  // klasa plansza 
{
	pole** _plansza;
	int w; // wiersze
	int k; // kolumny 
public:  // publiczna 
	pole get_pole(int i, int j) { return _plansza[i][j]; } // zajmowanie pola
	void set_pole(int i, int j, char znak) { _plansza[i][j].set_znak(znak);  // ustawianie znaku w polu
	}
	Plansza(int _w=3,int _k=3); // konstruktor planszy domyslnie 3x3
	~Plansza(); //  destruktor niszczy plansze
	void rysuj(); //funkcja rysuj


};

void Plansza::rysuj() // funkcja rysuj
{
	for (int i = 0; i < w; i++) // na ilosc wierszy 
	{
		for (int j = 0; j < k; j++) // na ilosc kolumn
		{
			cout << " " << _plansza[i][j].get_znak(); // wyswietla plansze
			if(j<k-1) // jezzeli mniejsze od kolumny o 1
				cout<< " |"; //stawia pionowa kreske
		}
		cout << endl; // koniec lini
		if(i<w-1) // jezeli mniejsze od wiersza o 1
			for (int j = 0; j < k; j++) // dla ilosci kolumn
			{
				cout << "---"; // stawia linie pozioma
				if (j < k - 1) // jezeli mniejsze o 1 od ilosci kolumn
					cout << "+"; // stawia +
			}
		cout << endl; // koniec lini
	}

}

Plansza::Plansza(int _w, int _k) // funkcja plansza
{
	k = _k; // podane kolumny przypisuje do zmiennej w programie
	w = _w; // podane wiersze przypisuje do zmiennej w programie
	_plansza = new pole * [w]; 
for(int i=0; i<w; i++) 
	_plansza[i] = new pole [k];
}

Plansza::~Plansza() // destruktor
{
	for (int i = 0; i < w; i++) 
		delete[] _plansza[i];
	delete _plansza;
}