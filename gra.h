#pragma once
#include "Plansza.h"


class gra   // klasa gra 
{
	Plansza* nowa; // przehowuje wskaznik na nowa plansze  
	int w; // wiersze 
	int k; // kolumny 
	char znak[2];  // przechowuje znaki graczy
	int i; // zmienna sterujaca graczami 
	int wygr; 
public: // publiczna  
	gra(int _w = 3, int _k = 3,int  _wygr=3)  // konstruktor gra 
	{
		wygr = _wygr;
		w = _w; // wiersz= wartosc wiersza
		k = _k; // kolumna = wartosc kolumna 
		i = 0; // ustawienie 1 gracza 
		znak[0] = 'O'; // pierwszy o gracz
		znak[1] = 'X'; // drugi x komputer 

		nowa =new Plansza(w, k); // tworzenie planszy 
	}
	bool wygrana(char gracz) //funkcja sprawdzaj¹ca wygrana 
	{
		int licznik = 0; // licznik znaków
		for (int i = 0; i < w; i++) // petla i przechodz¹ca po liczbie wierszy
		{
			licznik = 0; 
			for (int j = 0; j < w; j++) // petla j przechodz¹ca po liczbie wierszy
			{
				if (nowa->get_pole(i, j).get_znak() == gracz) //sprawdza czy na polu jest znak gracza
				{
					licznik++; 
				}
				else  // w przeciwnym razie
					licznik = 0; // przyrównuje do 0

				if (licznik == wygr)  // sprawdza czy licznik jest równy ilosci znaków potrzebnych do wygranej
				{
					return true; 
				}

			}
		}

		for (int i = 0; i < w; i++) // petla i przechodz¹ca po liczbie wierszy
		{
			licznik = 0;
			for (int j = 0; j < w; j++) // petla j przechodz¹ca po liczbie wierszy
			{
				if (nowa->get_pole(j, i).get_znak() == gracz) //sprawdza czy na polu jest znak gracza
				{
					licznik++;  
				}
				else //w przeciwnym razie 
					licznik = 0; // przyrównuje do 0

				if (licznik == wygr) // sprawdza czy licznik jest równy ilosci znaków potrzebnych do wygranej
				{
					return true; 
				}

			}
		}
		 
		licznik = 0; // przyrównuje do 0
			for (int j = 0; j < w; j++)  // petla j przechodz¹ca po liczbie wierszy
			{
				if (nowa->get_pole(j, j).get_znak() == gracz) //sprawdza czy na polu jest znak gracza
				{
					licznik++; 
				}
				else  //w przeciwnym razie 
					licznik = 0; // przyrównuje do 0

				if (licznik == wygr) // sprawdza czy licznik jest równy ilosci znaków potrzebnych do wygranej
				{
					return true; 
				}

			}
			licznik = 0;  // przyrównuje do 0
			for (int j = 0; j < w; j++)   // petla j przechodz¹ca po liczbie wierszy
			{
				if (nowa->get_pole(j, w-1-j).get_znak() == gracz)  //sprawdza czy na polu jest znak gracza
				{
					licznik++; 
				}
				else //w przeciwnym razie
					licznik = 0; // przyrównuje do 0

				if (licznik == wygr)  // sprawdza czy licznik jest równy ilosci znaków potrzebnych do wygranej
				{
					return true;
				}

			}
			return false;
	}


	int minimax(char gracz, int poz)   //algorytm minimax
	{
		int licznik = 0;  //przyrównujemy do 0
		int _w, _k;

		
		 
		for (int i = 0; i < w; i++)  // petla i przechodz¹ca po liczbie wierszy      //sparwdzamy czy wygrana
			for (int j = 0; j < k; j++)  // petla j przechodz¹ca po liczbie kolumn
				if (nowa->get_pole(i, j).get_znak() == ' ')  //sprawdzamy czy pole jest puste
				{
					nowa->set_pole(i, j,gracz); //ustawia pole aktualnego gracza
					_w = i;  
					_k = j;  
					licznik++;     

					bool test = wygrana(gracz);  // sprawdzamy czy nastapila wygrana

					nowa->set_pole(i, j,' ')  ; // pole wracamy do poprzedniego stanu
					if (test) 
					{
						if (!poz) nowa->set_pole(i, j,gracz) ; //jezeli poziom 0 zmien pole na gracza 
						return gracz == 'X' ? -1 : 1; // zwraca 1 albo -1
					}
				}
		
		if (licznik == 1) //jezeli licznik = 1        //sprawdzamy czy nastapil remis
		{
			if (!poz) nowa->set_pole(_w,_k,gracz); 
			return 0;  //zwracamy 0
		}


        int vmax;
		int v;
		
		
		vmax = gracz == 'X' ? 2 : -2; //vmax ustawiamy na -2 lub 2        //szukamy najlepszego pola dla gracza

		for (int i = 0; i < w; i++)  // petla i przechodz¹ca po liczbie wierszy
			for (int j = 0; j < k; j++)  // petla j przechodz¹ca po liczbie kolumn
				if (nowa->get_pole(i, j).get_znak() == ' ')  //sprawdzamy czy pole jest puste
				{
					nowa->set_pole(i, j,gracz) ;  // ustawiamy gracza w polu
					v = minimax(gracz == 'X' ? 'O' : 'X', poz + 1);  // rekurencyjnie wywoluje minmax z poziomem, +1
					nowa->set_pole(i, j,' ')  ; //ustawia pole na poprzedni stan

					if (((gracz == 'X') && (v < vmax)) || ((gracz == 'O') && (v > vmax))) // sprawdzamy wrunek max
					{
						vmax = v; _w = i; _k = j;
					}
				}

		if (!poz) nowa->set_pole(_w, _k,gracz); 

		return vmax;
	}
	bool graj() // funkcja graj 
	{
		nowa->rysuj();
		int x, y; // kordynanty
		cout << " podaj pole";
		cin >> x >> y; // pobiera x i y
		if(i==0)
		if (x <= w && x > 0 && y <= k && y > 0) // jezeli mieszcza sie w zakresie
		{
			if (nowa->get_pole(x-1, y-1).get_znak() == ' ') // jezeli pole nie zjaete 
			{
				nowa->set_pole(x-1, y-1, znak[0]); // dodajemy znak x albo o 
				if (i == 0) // jezeli pierwszy gracz  
					i = 1; 
				else
					i = 0;
			}
		}
		if (wygrana(znak[0]))  //jezeli wygral gracz
		{
			nowa->rysuj();
			cout << "wygral gracz" << endl;  //wypisz wygral gracz
			return false;
		}
		if (i == 1)
			if (x <= w && x > 0 && y <= k && y > 0) // jezeli mieszcza sie w zakresie
			{
				minimax(znak[1], 0);
					if (i == 0)  
						i = 1;
					else
						i = 0;
				
			}
		if (wygrana(znak[1]))  //jezeli wygral komputer 
		{
			nowa->rysuj();
			cout << "wygral komputer" << endl;  // wypisz wygral komputer
			return false;
		}
		nowa->rysuj();
		return true;
	}

};