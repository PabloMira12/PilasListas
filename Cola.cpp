#include "Cola.h"
#include<iostream>
using namespace std;

Cola::Cola(int T)
{
	Limite = T - 1;
	Tope = -1;
	Vcola = new int[T];
}

void Cola::Encolar(int d)
{
	Tope++;
	Vcola[Tope] = d;
}

int Cola::Desencolar()
{
	int r = Vcola[0], I = 1;
	while (I <= Tope)
	{
		Vcola[I - 1] = Vcola[I];
		I++;
	}
	Tope--;
	return r;
}

bool Cola::ColaLlena()
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

bool Cola::ColaVacia()
{
	if (Tope == -1)
	{
		return true;
	}
	else
	{
		return false;
	}	
}

void Cola::LlenarCola(Cola* b)
{
	while (b->ColaVacia() == false && ColaLlena() == false)
	{
		Encolar(b->Desencolar());
	}
}

void Cola::MostrarCola()
{
	Cola* aux = new Cola(Limite + 1);
	int R = 0;
	while (ColaVacia() == false)
	{
		R = Desencolar();
		cout << " - " << R << " - ";
		aux->Encolar(R);
	}
	LlenarCola(aux);
	system("pause");

}

void Cola::OrdenarCola()
{
	Cola* aux1 = new Cola(Limite + 1);
	Cola* aux2 = new Cola(Limite + 1);
	int p = 0;
	do
	{
		if (aux2->ColaVacia() == true)
		{
			aux2->Encolar(Desencolar());
		}
		else
		{
			p = Desencolar();
			if (p < aux2->GetD())
			{
				aux2->Encolar(p);
			}
			else
			{
				do
				{
					aux1->Encolar(aux2->Desencolar());
				} while (aux2->ColaVacia() == false && p > aux2->GetD());
				aux2->Encolar(p);
				aux2->LlenarCola(aux1);				
			}
		}
	} while (ColaVacia() == false);

	LlenarCola(aux2);
	MostrarCola();
	system("pause");

}

void Cola::EncolarOrdenado(int d)
{
	Cola* aux = new Cola(Limite +1 );
	if (ColaVacia() == true)
	{
		Encolar(d);
	}
	else
	{
		if (d > GetD())
		{
			Encolar(d);
		}
		else
		{
			while ( ColaVacia() == false && d < GetD() )
			{
				aux->Encolar(Desencolar());
			}
			Encolar(d);
			while (aux->ColaVacia() == false)
			{
				Encolar(aux->Desencolar());
			}
		}
	}
}

void Cola::InvertirCola()
{
	Cola* C = new Cola(Limite + 1);
	Cola* C4 = new Cola(Limite + 1);

	while (ColaVacia() == false)
	{
		C->Encolar(Desencolar());
	}
	while (C->ColaVacia() == false)
	{
		C4->Encolar(C->Desencolar());
	}
	while (C4->ColaVacia() == false)
	{
		Encolar(C4->Desencolar());
	}
}

int Cola::GetLimite()
{
	return Limite;
}

int Cola::GetTope()
{
	return Tope;
}

int Cola::GetD()
{
	return Vcola[Tope];
}

void Cola::Entrelazado_Colas_Pilas(Cola*C2)
{
	PilaVec* Pv;
	Cola *aux = new Cola(Limite + 1) , * aux1 = new Cola(C2->GetLimite() + 1);
	int r = GetLimite(), z = C2->GetLimite() , y = 0 , x = 0;
	Pv = new PilaVec(r + z);

	if (GetLimite() < C2->GetLimite())
	{
		while (ColaVacia() == false)
		{
			y = Desencolar();
			x = C2->Desencolar();
			aux->Encolar(y);
			aux1->Encolar(x);
			Pv->Apilar(y);
			Pv->Apilar(x);
		}
		while (C2->ColaVacia() == false)
		{
			x = C2->Desencolar();
			Pv->Apilar(x);
			aux1->Encolar(x);
		}
	}
	else
	{
		while (C2->ColaVacia() == false)
		{
			y = Desencolar();
			x = C2->Desencolar();
			aux->Encolar(y);
			aux1->Encolar(x);
			Pv->Apilar(y);
			Pv->Apilar(x);
		}
		while (ColaVacia() == false)
		{
			y = Desencolar();
			Pv->Apilar(y);
			aux->Encolar(y);
		}
	}
	LlenarCola(aux);
	C2->LlenarCola(aux1);
	Pv->MostrarPila();
}
