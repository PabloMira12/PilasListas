#pragma once
#include"Nodo.h"
#include"Cola.h"

class PilaLista
{
	//atributos
public:

	Nodo* Punta;
	int Limite, Tope;

	//metodos
public:
	PilaLista(int);

	void Apilar(int);
	int Desapilar();
	bool PilaLlena();
	bool PilaVacia();
	void LlenarPila(PilaLista*);
	void InsertarInicio(int);
	void MostrarPila();
	void OrdenarPila();
	void ApilarOrdenado(int);
	void InvertirPila();
	void Suma_PilaCola(Cola*);
	int GetLimite();
};

