

#include <iostream>
#include "gra.h"

int main()
{
    int w; // zmienna pol
    cout << "rozmiar pola ";
    cin >> w;
    int wy; // zmienna wygranej (ilosc)
    cout << "rozmiar wygranej ";
    cin >> wy;
    gra p(w,w,wy); // tworzenie gry
    while (  p.graj())  // do mometu wygranej
    {
      
   }
    
}

