#include "stdafx.h"
#include "AgentieImobiliara.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;


Locuinta::Locuinta()
{
	nume_client = "";
	suprafata_utila = 0;
	discount = 0;
	pret_pe_metru_patrat = 0;
}

Locuinta::Locuinta(const Locuinta& loc1)
{
	nume_client = loc1.nume_client;
	suprafata_utila = loc1.suprafata_utila;
	discount = loc1.discount;
	pret_pe_metru_patrat = loc1.pret_pe_metru_patrat;
}

Locuinta::~Locuinta()
{
	nume_client = "";
	suprafata_utila = 0;
	discount = 0;
	pret_pe_metru_patrat = 0;
}

istream& operator>>(istream& a, Locuinta& loc1)
{
	getline(a, loc1.nume_client);
	getline(a, loc1.nume_client);
	a >> loc1.suprafata_utila >> loc1.pret_pe_metru_patrat >> loc1.discount;
	if (loc1.discount < 0 || loc1.discount > 10)
		throw "Discount gresit!";

	return a;
}

ostream& operator<<(ostream& a, Locuinta& loc1)
{
	a << loc1.nume_client << " " << loc1.suprafata_utila << " " << loc1.pret_pe_metru_patrat << " " << loc1.discount << endl;

	return a;
}

void Locuinta::operator=(Locuinta loc1)
{
	nume_client = loc1.nume_client;
	suprafata_utila = loc1.suprafata_utila;
	discount = loc1.discount;
	pret_pe_metru_patrat = loc1.pret_pe_metru_patrat;
}

void Locuinta::afisare()
{
	cout << "Locuinta lui " << nume_client << endl;
}




Apartament::Apartament()
{
	nume_client = "";
	suprafata_utila = 0;
	discount = 0;
	etaj = 0;
	pret_pe_metru_patrat = 0;
}

Apartament::Apartament(const Apartament& ap1)
{
	nume_client = ap1.nume_client;
	suprafata_utila = ap1.suprafata_utila;
	discount = ap1.discount;
	etaj = ap1.etaj;
	pret_pe_metru_patrat = ap1.pret_pe_metru_patrat;
}

Apartament::~Apartament()
{
	nume_client = "";
	suprafata_utila = 0;
	discount = 0;
	etaj = 0;
	pret_pe_metru_patrat = 0;
}

void Apartament::operator=(Apartament ap1)
{
	nume_client = ap1.nume_client;
	suprafata_utila = ap1.suprafata_utila;
	discount = ap1.discount;
	etaj = ap1.etaj;
	pret_pe_metru_patrat = ap1.pret_pe_metru_patrat;
}

istream& operator>>(istream& a, Apartament& ap1)
{
	getline(a, ap1.nume_client);
	getline(a, ap1.nume_client);
	a >> ap1.suprafata_utila >> ap1.pret_pe_metru_patrat >> ap1.discount >> ap1.etaj;
	if (ap1.discount < 0 || ap1.discount > 10)
		throw "Discount gresit!";

	return a;
}

ostream& operator<<(ostream& a, Apartament& ap1)
{
	a << ap1.nume_client << " " << ap1.suprafata_utila << " " << ap1.pret_pe_metru_patrat << " " << ap1.discount << " " << ap1.etaj << endl;

	return a;
}

void Apartament::afisare()
{
	cout << "Apartamentul lui " << nume_client << endl;
}

double Apartament::chirie()
{
	return suprafata_utila * pret_pe_metru_patrat * (1 - discount / 100);
}




Casa::Casa()
{
	nume_client = "";
	suprafata_utila = 0;
	discount = 0;
	pret_pe_metru_patrat = 0;
	etaje = 0;
	suprafata_curte = 0;
	pret_pe_metru_patrat_curte = 0;
}

Casa::Casa(const Casa& c1)
{
	nume_client = c1.nume_client;
	suprafata_utila = c1.suprafata_utila;
	discount = c1.discount;
	etaje = c1.etaje;
	pret_pe_metru_patrat = c1.pret_pe_metru_patrat;
	suprafata_curte = c1.suprafata_curte;
	suprafata_etaj = c1.suprafata_etaj;
	pret_pe_metru_patrat_curte = c1.pret_pe_metru_patrat_curte;
}

Casa::~Casa()
{
	nume_client = "";
	suprafata_utila = 0;
	discount = 0;
	pret_pe_metru_patrat = 0;
	etaje = 0;
	suprafata_curte = 0;
	pret_pe_metru_patrat_curte = 0;
	suprafata_etaj.clear();
}

void Casa::operator=(Casa c1)
{
	nume_client = c1.nume_client;
	suprafata_utila = c1.suprafata_utila;
	discount = c1.discount;
	etaje = c1.etaje;
	pret_pe_metru_patrat = c1.pret_pe_metru_patrat;
	suprafata_curte = c1.suprafata_curte;
	suprafata_etaj = c1.suprafata_etaj;
	pret_pe_metru_patrat_curte = c1.pret_pe_metru_patrat_curte;
}

istream& operator>>(istream& a, Casa& c1)
{
	getline(a, c1.nume_client);
	getline(a, c1.nume_client);
	a >> c1.pret_pe_metru_patrat >> c1.discount >> c1.etaje >> c1.suprafata_curte >> c1.pret_pe_metru_patrat_curte;
	
	if (c1.discount < 0 || c1.discount > 10)
		throw "Discount gresit!";

	for (int i = 0; i <= c1.etaje; i++)
	{
		int aux;
		a >> aux;
		c1.suprafata_utila += aux;
		c1.suprafata_etaj.push_back(aux);
	}

	return a;
}

ostream& operator<<(ostream& a, Casa& c1)
{
	a << c1.nume_client << " " << c1.suprafata_utila << " " << c1.pret_pe_metru_patrat << " " << c1.discount << " " << c1.etaje << " " << c1.suprafata_curte << " " << c1.pret_pe_metru_patrat_curte << endl;

	for (vector<double>::iterator it = c1.suprafata_etaj.begin(); it != c1.suprafata_etaj.end(); it++)
		a << *it << " ";
	cout << endl;

	return a;
}

double Casa::chirie()
{
	return suprafata_utila * pret_pe_metru_patrat * (1 - discount / 100) + pret_pe_metru_patrat_curte * suprafata_curte;
}

void Casa::afisare()
{
	cout << "Casa lui " << nume_client << endl;
}
