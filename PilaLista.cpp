#include "PilaLista.h"
#include<iostream>
using namespace std;

PilaLista::PilaLista(int T)
{
	Punta = nullptr;
	Tope = 0;
	Limite = T;
}

void PilaLista::Apilar(int n)
{
	Tope++;
	InsertarInicio(n);
}

int PilaLista::Desapilar()
{
	Nodo* p = Punta;
	int r = p->GetD();
	Punta = Punta->GetL();
	Tope--;
	delete (p);					//profe aqui a veces me sale error en el delete pero luego cierro el visual y lo vuelvo a abrir y ya me funcion normal , creo que era por el visual

	return r;
}

bool PilaLista::PilaLlena()
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

bool PilaLista::PilaVacia()
{
	if (Tope == 0)
	{
		return true;
	}
	else
	{
		return false;
	}	
}

void PilaLista::LlenarPila(PilaLista* a)
{
	while (a->PilaVacia() == false)
	{
		Apilar(a->Desapilar());
	}
}

void PilaLista::InsertarInicio(int d)
{
	Nodo* x = new Nodo();
	x->SetD(d);
	if (Punta == nullptr)
	{
		Punta = x;
	}
	else
	{
		x->SetL(Punta);
		Punta = x;
	}
}

void PilaLista::MostrarPila()
{
	int P = 0;
	PilaLista* aux = new PilaLista(Limite);

	while (PilaVacia() == false)
	{
		P = Desapilar();			//vacio la p1 para que salga cada dato a mostrar
		cout << "|" << P << "|";
		aux->Apilar(P);				//apilo en p2 para que no se peirdan los datod
	}
	LlenarPila(aux);					//lleno a p1 otra vez con los datos
	system("pause");
}

void PilaLista::OrdenarPila()
{
	int P = 0;
	PilaLista* aux = new PilaLista(Limite);
	PilaLista* resp = new PilaLista(Limite);

	while (PilaVacia() == false)
	{
		if (resp->PilaVacia() == true)
		{
			resp->Apilar(Desapilar());
		}
		else
		{
			P = Desapilar();
			if (P > resp->Punta->GetD())
			{
				resp->Apilar(P);
			}
			else
			{
				do
				{
					aux->Apilar(resp->Desapilar());					
				} while (resp->PilaVacia() == false && P < resp->Punta->GetD());

				resp->Apilar(P);
				resp->LlenarPila(aux);				
			}
		}
	}
	aux->LlenarPila(resp);
	LlenarPila(aux);
	MostrarPila();
	system("pause");
}


void PilaLista::ApilarOrdenado(int d )
{
	PilaLista* aux = new PilaLista(Limite);

	if (Punta == nullptr)
	{
		Apilar(d);
	}
	else
	{
		if (d > Punta->GetD())
		{
			Apilar(d);
		}
		else
		{
			do
			{				
				aux->Apilar(Desapilar());				

			} while (PilaVacia() != true && d < Punta->GetD());
			Apilar(d);
			LlenarPila(aux);			
		}
	}
}

void PilaLista::InvertirPila()
{
	PilaLista* P2 = new PilaLista(Limite);
	PilaLista* P3 = new PilaLista(Limite);

	while (PilaVacia() == false)
	{
		P2->Apilar(Desapilar());
	}
	while (P2->PilaVacia() == false)
	{
		P3->Apilar(P2->Desapilar());
	}
	while (P3->PilaVacia() == false)
	{
		Apilar(P3->Desapilar());
	}
}

void PilaLista::Suma_PilaCola(Cola* C1)
{
	Cola* Res, * aux1 = new Cola(C1->GetLimite() + 1);
	PilaLista* aux = new PilaLista(Limite);
	int r = 0, x = 0;

	if (GetLimite() < C1->GetLimite())
	{
		Res = new Cola(C1->GetLimite() + 1);
		while (Tope != C1->GetTope())
		{
			r = C1->Desencolar();
			Res->Encolar(r);
			aux1->Encolar(r);
		}
		while (Res->ColaLlena() == false)
		{
			r = C1->Desencolar();
			x = Desapilar();
			Res->Encolar(r + x);
			aux1->Encolar(r);
			aux->Apilar(x);
		}
		LlenarPila(aux);
		C1->LlenarCola(aux1);
	}
	else
	{
		Res = new Cola(GetLimite() + 1);
		while (Tope != C1->GetTope())
		{
			x = Desapilar();
			Res->Encolar(x);
			aux->Apilar(x);
		}
		while (Res->ColaLlena() == false)
		{
			r = C1->Desencolar();
			x = Desapilar();
			Res->Encolar(r + x);
			aux1->Encolar(r);
			aux->Apilar(x);
		}
		LlenarPila(aux);
		C1->LlenarCola(aux1);
	}
	Res->MostrarCola();

}

int PilaLista::GetLimite()
{
	return Limite;
}
