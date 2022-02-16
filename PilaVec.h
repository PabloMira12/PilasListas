#pragma once
class PilaVec
{
	//atributos
public:
	int Tope, Limite, * Vec;

	//metodos
	PilaVec(int);

	void Apilar(int);
	int Desapilar();
	bool PilaLlena();
	bool PilaVacia();
	void LlenarPila(PilaVec*);
	void MostrarPila();



};

