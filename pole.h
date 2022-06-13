#pragma once

class pole   // klasa pole
{
	bool czy_zajete;  // posiada informacje o tym czy pole zajete
	char znak;  // znak 
public:  // pubiczna 
	pole()  // konstruktor pole
	{
		czy_zajete = false;  // czy pole zajete ustawiamy na false 
		znak = ' '; // ustawiamy na puste pola 
	}
	bool get_czy_zajete()const { return czy_zajete; }  // zwracamy status pola
	char  get_znak()const { return znak; } // zwracamy znak 
	void zajmij() {  czy_zajete=true; } // zajmowanie pola 
	void  set_znak(char _znak) {  znak= _znak; }  // ustawiamy znak 

};