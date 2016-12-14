#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

typedef struct element {
	struct element *next;
	int nr;
	string nazwa;
	int unikalny_nr;
	string kategoria;
	string status;
	int cena;
	string wlasciciel;
	string kupujacy;
	string opis;
} el_listy;

el_listy *first;

void dodaj_do_listy_z_pliku(el_listy *lista)
{
	string line;
	//int linenr;
	el_listy *wsk, *nowy;
	wsk = lista;
	fstream plik;
	//getline(plik, linenr);
	getline(plik, line);
	plik.open("plik.txt", ios::out);
	while (wsk->next != NULL)
	{
		wsk = wsk->next; /*znajaduje ostatni el listy*/
	}
	nowy = new el_listy;
	//nowy->nr = linenr;
	nowy->nazwa = line;
	//nowy->unikalny_nr = unikalny_nr;
	nowy->kategoria = line;
	/*nowy->status = status;
	nowy->cena = cena;
	nowy->wlasciciel = wlasciciel;
	nowy->kupujacy = kupujacy;
	nowy->opis = opis;*/
	nowy->next = NULL;
	wsk->next = nowy; /*podczepiam wsk po ten element*/
	plik.close();
}

void dodaj_do_listy(el_listy *lista, int nr, string nazwa, int unikalny_nr, string kategoria, string status, int cena, string wlasciciel, string kupujacy, string opis)
{
	el_listy *wsk, *nowy;
	wsk = lista;
	while (wsk->next != NULL)
	{
		wsk = wsk->next; /*znajaduje ostatni el listy*/
	}
	nowy = new el_listy;
	nowy->nr=nr;
	nowy->nazwa=nazwa;
	nowy->unikalny_nr = unikalny_nr;
	nowy->kategoria = kategoria;
	nowy->status = status;
	nowy->cena = cena;
	nowy->wlasciciel = wlasciciel;
	nowy->kupujacy = kupujacy;
	nowy->opis = opis;
	nowy->next = NULL;
	wsk->next = nowy; /*podczepiam wsk po ten element*/
}

/*void usun_z_listy(el_listy *lista, string element)
{
	el_listy *wsk = lista;
	while (wsk->next != NULL)
	{
		if (wsk->next->aukcja == element)
		{
			el_listy *usuwany = wsk->next;
			wsk->next = usuwany->next;   /* przesuwam wsk aby omijal usuwany el *//*
			delete(usuwany);
		}
		else
		{
			wsk = wsk->next;
		}
	}
}*/

	void wypisz_liste(el_listy *lista)
	{
		el_listy *wsk = lista;
		while (wsk != NULL)
		{
			cout.width(1);
			cout << wsk->nr;
			cout.width(10);
			cout << wsk->nazwa;
			cout.width(10);
			cout << wsk->unikalny_nr;
			cout.width(15);
			cout << wsk->kategoria;
			cout.width(13);
			cout << wsk->status;
			cout.width(10);
			cout << wsk->cena;
			cout.width(23);
			cout << wsk->wlasciciel;
			cout.width(23);
			cout << wsk->kupujacy;
			cout.width(60);
			cout << wsk->opis << endl;
			wsk = wsk->next;
		}
	}


	int main()
	{
		int nr;
		string nazwa;
		int unikalny_nr;
		string kategoria;
		string status;
		int cena;
		string wlasciciel;
		string kupujacy;
		string opis;
	
		first = new el_listy;
		first->nazwa = "abc";
		first->nr = 5;
		first->unikalny_nr = 13513;
		first->kategoria = "smieci";
		first->status = "sprzedane";
		first->cena = 153;
		first->wlasciciel = "Patrys";
		first->kupujacy = "Zuczek";
		first->opis = "asdasdasdasdasdasdasdasdasdasd";
		first->next = NULL;

		dodaj_do_listy_z_pliku(first);

		/*while (true)
		{
			cout << "podaj nr";
			cin >> nr;
			cout << "podaj nazwe";
			cin >> nazwa;
			cout << "podaj unikalny nr";
			cin >> unikalny_nr;
			cout << "podaj kateorie";
			cin >> kategoria;
			cout << "podaj status";
			cin >> status;
			cout << "podaj cene";
			cin >> cena;
			cout << "podaj wlasciciela";
			cin >> wlasciciel;
			cout << "podaj kupujacego";
			cin >> kupujacy;
			cout << "podaj opis";
			cin >> opis;
			dodaj_do_listy(first, nr, nazwa, unikalny_nr, kategoria, status, cena, wlasciciel, kupujacy, opis);

			

			wypisz_liste(first);
		}*/
		wypisz_liste(first);
		system("pause");
		return 0;
	}