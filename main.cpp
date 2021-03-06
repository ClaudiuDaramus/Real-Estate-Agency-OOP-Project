// Tema10_AgentieImob_Gr144v2_DaramusClaudiu.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "AgentieImobiliara.h"
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;


template <class T>
class Gestiune
{
private:
	vector <T> resedinte;
	int numar_resedinte, contor;
	double chirie;
public:
	Gestiune();
	Gestiune(const Gestiune& g1);
	~Gestiune();
	void operator=(Gestiune g1);
	void operator+=(const T& res);
	virtual void afis();

	friend istream& operator>>(istream& a, Gestiune& g1)
	{
		a >> g1.numar_resedinte;

		return a;
	}

	friend ostream& operator<<(ostream& a, Gestiune& g1)
	{
		a << typeid(g1).name() << endl;
		a << g1.numar_resedinte << " " << g1.contor << endl;
		//for (typename vector<Gestiune<T>*>::iterator it = g1.resedinte.begin(); it != g1.resedinte.end(); it++)
		//	cout << *it;
		for (int i = 0; i < g1.contor; i++)
		{
			if (i == g1.resedinte.size())
				throw "Out of range!";
			cout << g1.resedinte[i];
		}
		g1.afis();
		cout << endl;

		return a;
	}
};

template <class T>
Gestiune<T>::Gestiune()
{
	numar_resedinte = contor = chirie = 0;
}

template <class T>
Gestiune<T>::Gestiune(const Gestiune& g1)
{
	resedinte = g1.resedinte;
	numar_resedinte = g1.numar_resedinte;
	contor = g1.contor;
	chirie = g1.chririe;
}

template <class T>
Gestiune<T>::~Gestiune()
{
	resedinte.clear();
	numar_resedinte = contor = chirie = 0;
}

template <class T>
void Gestiune<T>::operator=(Gestiune g1)
{
	resedinte = g1.resedinte;
	numar_resedinte = g1.numar_resedinte;
	contor = g1.contor;
	chirie = g1.chririe;
}

template <class T>
void Gestiune<T>::operator+=(const T& res)
{
	resedinte.push_back(res);
	contor++;
}

template <class T>
void Gestiune<T>::afis()
{
	for (int i = 0; i < contor; i++)
	{
		resedinte[i].afisare();
		cout << resedinte[i].chirie() << endl;
	}
}

template <>
void Gestiune<Locuinta>::afis()
{
	for (int i = 0; i < contor; i++)
	{
		resedinte[i].afisare();
	}
}


template <>
class Gestiune <string>
{
private:
	vector <string> nume_client;
	int numar_clienti, contor;
public:

	Gestiune()
	{
		numar_clienti = contor = 0;
	}

	Gestiune(const Gestiune& g1)
	{
		nume_client = g1.nume_client;
		numar_clienti = g1.numar_clienti;
		contor = g1.contor;
	}

	~Gestiune()
	{
		nume_client.clear();
		numar_clienti = contor = 0;
	}

	void operator=(Gestiune g1)
	{
		nume_client = g1.nume_client;
		numar_clienti = g1.numar_clienti;
		contor = g1.contor;
	}

	void operator+=(string num)
	{
		nume_client.push_back(num);
		contor++;
	}

	friend istream& operator>>(istream& a, Gestiune& g1)
	{
		a >> g1.numar_clienti;

		return a;
	}

	friend ostream& operator<<(ostream& a, Gestiune& g1)
	{
		a << typeid(g1).name() << endl;
		a << g1.numar_clienti << " " << g1.contor << endl;
		//for (typename vector<Gestiune<string>*>::iterator it = g1.nume_client.begin(); it != g1.nume_client.end(); it++)
		//	cout << *it << " ";

		for (int i = 0; i < g1.contor; i++)
			cout << g1.nume_client[i] << endl;
		cout << endl;

		return a;
	}
};




int main()
{
	try
	{
		string temp;

		Gestiune <Casa> ges;
		int n;
		ifstream f("casa.in");
		f >> n >> ges;

		for (int i = 0; i < n; i++)
		{
			Casa aux;
			f >> aux;
			ges += aux;
		}


		Gestiune <Apartament> ges1;
		int n1;
		ifstream g("apartament.in");
		g >> n1 >> ges1;

		for (int i = 0; i < n1; i++)
		{
			Apartament aux;
			g >> aux;
			ges1 += aux;
		}


		Gestiune <Locuinta> ges2;
		int n2;
		ifstream h("locuinta.in");
		h >> n2 >> ges2;

		for (int i = 0; i < n2; i++)
		{
			Locuinta aux;
			h >> aux;
			ges2 += aux;
		}


		Gestiune <string> ges_num;
		int n3;
		ifstream q("string.in");
		q >> n3 >> ges_num;
		getline(q, temp);

		for (int i = 0; i < n3; i++)
		{
			string aux;
			getline(q, aux);
			ges_num += aux;
		}

		cout << ges2 << ges1 << ges << ges_num;

		Locuinta *lp1, *lp2;
		Casa c1;
		Apartament a1;
		ifstream f1("cast.in");
		f1 >> temp >> c1 >> temp >> a1;
		lp1 = dynamic_cast<Locuinta*>(&c1);
		lp2 = static_cast<Locuinta*>(&a1);

		cout << "dynamic_cast: " << *lp1 << "static_cast: " << *lp2 << endl;

		Apartament exceptie;
		ifstream ex("exception.in");
		ex >> temp >> exceptie;
	}
	catch (const char* msg)
	{
		cout << "EXCEPTIE GASITA: ";
		cout << msg << endl << endl;
	}

    return 0;
}

