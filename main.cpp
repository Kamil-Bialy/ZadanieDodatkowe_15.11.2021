#include <iostream>
#include <fstream>

using namespace std;

class Uczen
{
	public:
		string imie, nazwisko, klasa;
		float ocena_polski, ocena_matematyka, ocena_fizyka;
		
		void dodajUcznia()
		{
			cout << "Podaj imie ucznia: " << endl;
			cin >> imie;
			cout << "Podaj nazwisko ucznia: " << endl;
			cin >> nazwisko;
			cout << "Podaj klase ucznia: " << endl;
			cin >> klasa;
			cout << "Podaj ocene koncowa z polskiego ucznia: " << endl;
			cin >> ocena_polski;
			cout << "Podaj ocene koncowa z matematyki ucznia: " << endl;
			cin >> ocena_matematyka;
			cout << "Podaj ocene koncowa z fizyki ucznia: " << endl;
			cin >> ocena_fizyka;
			cout << endl;
		}
		
		void wyswietlDane()
		{
			cout << "Imie ucznia: " << imie << endl;
			cout << "Nazwisko ucznia: " << nazwisko << endl;
			cout << "Klasa ucznia: " << klasa << endl;
		}
		
		void wyswietlOceny()
		{
			cout << "Ocena koncowa z polskiego ucznia: " << ocena_polski << endl;
			cout << "Ocena koncowa z matematyki ucznia: " << ocena_matematyka << endl;
			cout << "Ocena koncowa z fizyki ucznia: " << ocena_fizyka << endl;
		}
		
		float sredniaOcen()
		{
			return (ocena_polski + ocena_matematyka + ocena_fizyka)/3;
		}
		
		void metryczka()
		{
			cout << "Autor: Kamil Bialy 3Cg" << endl;
		}
};

void porownajSrednie(Uczen &u1, Uczen &u2)
{
	float srednia1 = u1.sredniaOcen();
	float srednia2 = u2.sredniaOcen();
	
	if(srednia1 > srednia2)
	{
		cout << "Uczen1 ma wieksza srednia niz uczen2" << endl;
	}
	else if(srednia2 > srednia1)
	{
		cout << "Uczen2 ma wieksza srednia niz uczen1" << endl;
	}
	else
	{
		cout << "Uczniowie maja takie same srednie" << endl;
	}
}

int main() 
{
	fstream plik;
	Uczen uczen1, uczen2;
	uczen1.dodajUcznia();
	uczen2.dodajUcznia();
	porownajSrednie(uczen1, uczen2);
	
	plik.open("uczniowie.txt", ios::out);
	
	if(plik.good())
	{
		plik << "Imie: " << uczen1.imie << endl;
		plik << "Nazwisko: " << uczen1.nazwisko << endl;
		plik << "Klasa: " << uczen1.klasa << endl;
		plik << "Ocena z polskiego: " << uczen1.ocena_polski << endl;
		plik << "Ocena z matematyki: " << uczen1.ocena_matematyka << endl;
		plik << "Ocena z fizyki: " << uczen1.ocena_fizyka << endl;
		
		plik << "\nImie: " << uczen2.imie << endl;
		plik << "Nazwisko: " << uczen2.nazwisko << endl;
		plik << "Klasa: " << uczen2.klasa << endl;
		plik << "Ocena z polskiego: " << uczen2.ocena_polski << endl;
		plik << "Ocena z matematyki: " << uczen2.ocena_matematyka << endl;
		plik << "Ocena z fizyki: " << uczen2.ocena_fizyka << endl;
	}
	
	plik.close();
	
	return 0;
}
