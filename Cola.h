#pragma once
#include "PilaVec.h"

class Cola
{
	//atributos
private:
	int Limite, Tope, *Vcola;

	//metodos
public:
	Cola(int);

	void Encolar(int);
	int Desencolar();
	bool ColaLlena();
	bool ColaVacia();
	void LlenarCola(Cola*);
	void MostrarCola();
	void OrdenarCola();
	void EncolarOrdenado(int);
	void InvertirCola();
	int GetLimite();
	int GetTope();
	int GetD();
	void Entrelazado_Colas_Pilas(Cola*);
};

