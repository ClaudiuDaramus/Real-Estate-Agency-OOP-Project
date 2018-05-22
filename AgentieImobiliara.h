#pragma once
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Locuinta
{
protected:
	string nume_client;
	int suprafata_utila;
	double discount, pret_pe_metru_patrat;

public:
	Locuinta();
	Locuinta(const Locuinta& loc1);
	~Locuinta();
	friend istream& operator>>(istream& a, Locuinta& loc1);
	friend ostream& operator<<(ostream& a, Locuinta& loc1);
	void operator=(Locuinta loc1);
	virtual void afisare();
};


class Apartament : public Locuinta
{
private:
	int etaj;

public:
	Apartament();
	Apartament(const Apartament& ap1);
	~Apartament();
	friend istream& operator>>(istream& a, Apartament& ap1);
	friend ostream& operator<<(ostream& a, Apartament& ap1);
	void operator=(Apartament ap1);
	void afisare();
	double chirie();
};


class Casa : public Locuinta
{
private:
	int etaje;
	double suprafata_curte, pret_pe_metru_patrat_curte;
	vector <double> suprafata_etaj;

public:
	Casa();
	Casa(const Casa& c1);
	~Casa();
	friend istream& operator>>(istream& a, Casa& c1);
	friend ostream& operator<<(ostream& a, Casa& c1);
	void operator=(Casa c1);
	void afisare();
	double chirie();
};

