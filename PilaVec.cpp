#include "PilaVec.h"
#include<iostream>
using namespace std;


PilaVec::PilaVec(int T)
{
	Tope = -1;
	Limite = T - 1;
	Vec = new int[T];
}

void PilaVec::Apilar(int d1 )
{
	Tope++;
	Vec[Tope] = d1;
}

int PilaVec::Desapilar()
{
	int r1 = Vec[Tope];
	Tope--;
	return r1;
}

bool PilaVec::PilaLlena()
{
	if (Tope == Limite)
	{
		return true;
	}
	else
	{
		return false;
	}	
}

bool PilaVec::PilaVacia()
{
	if(Tope == -1)
	{
		return true;
	}
	else
	{
	return false;
	}
}

void PilaVec::LlenarPila(PilaVec* a)
{
	while (a->PilaVacia() == false)
	{
		Apilar(a->Desapilar());
	}
}

void PilaVec::MostrarPila()
{
	int P = 0;
	PilaVec* aux = new PilaVec(Limite);

	while (PilaVacia() == false)
	{
		P = Desapilar();			//vacio la p1 para que salga cada dato a mostrar
		cout << "|" << P << "|";
		aux->Apilar(P);				//apilo en p2 para que no se peirdan los datod
	}
	LlenarPila(aux);					//lleno a p1 otra vez con los datos
	system("pause");
}
