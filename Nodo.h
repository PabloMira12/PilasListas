#pragma once
class Nodo
{
	//atributos
public:
	int Dato;
	Nodo* Liga;

	//metodos
public:
	Nodo();
	void SetD(int);
	int GetD();
	void SetL(Nodo*);
	Nodo* GetL();
};

