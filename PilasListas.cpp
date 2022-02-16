// PilasListas.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include<iostream>
#include<stdlib.h>
#include"PilaLista.h"
#include"Cola.h"

using namespace std;

void Menu();
void Menu2();

int main()
{
    int opc1 = 0, dato = 0, n = 0 , m = 0 , Men = 0 , resp = 0;
        
    cout << "\nIngrese el Limite de la Pila : ";
    cin >> n;
    cout << "\nIngrese el Limite de la Cola : ";
    cin >> m;
    //instanciar
    PilaLista* P1 = new PilaLista(n);
    PilaLista* P2 = new PilaLista(n);
    Cola* C1 = new Cola(m);
    Cola* C2 = new Cola(m);

    do
    {
        cout << "Quieres el menu de colas (1) o Pilas ( 2 ) o salir (3) ";
        cin >> Men;
        switch (Men)
        {
            case 1: 
                
                do
                {
                    Menu();
                    cout << "\nIngrese una opcion:" << endl;
                    cin >> opc1;
                        switch (opc1)
                        {
                            case 1: //Encolar
                                cout << "Ingrese el dato a Encolar : ";
                                cin >> dato;
                                if (C1->ColaLlena() == false) 
                                {
                                   C1->Encolar(dato);
                                }
                                else
                                {
                                    cout << "\nLa Cola ya esta llena por lo tanto no se pueden ingresar mas datos " << endl;
                                }
                                system("pause");
                                break;

                            case 2: //Desencolar
                                if (C1->ColaVacia() == false) 
                                {
                                    C1->Desencolar();
                                }
                                else
                                {
                                    cout << "\nLa Cola esta vacia " << endl;
                                }
                                system("pause");
                                break;

                            case 3: // Mostrar Cola
                                if (C1->ColaVacia() == false) {
                                    C1->MostrarCola();
                                }
                                else
                                {
                                    cout << "\nLa Cola esta vacia " << endl;
                                }
                                system("pause");
                                break;

                            case 4://Encolar ordenado
                                cout << "Ingrese el dato a Encolar : ";
                                cin >> dato;
                                if (C1->ColaLlena() == false)
                                {
                                    C1->EncolarOrdenado(dato);
                                }
                                else
                                {
                                    cout << "\nLa Cola ya esta llena por lo tanto no se pueden ingresar mas datos " << endl;
                                }
                                system("pause");
                                break;

                            case 5://ordenar cola
                                if (C1->ColaVacia() == false)
                                {
                                    C1->OrdenarCola();
                                }
                                else
                                {
                                    cout << "\nLa Cola esta vacia " << endl;
                                }
                                system("pause");
                                break;

                            case 6://entrelazar dos pilas y acomodarlas en una cola con vectores                            //falta este
                                cout << "\nPrimero llene la Cola 2 -> " << endl;
                                system("pause");
                                while (C2->ColaLlena() == false)
                                {
                                    cout << "\nIngrese el dato que la cola aun no esta llena : "; cin >> dato;
                                    C2->Encolar(dato);
                                }
                                cout << "\nLa cola 2 quedo : " << endl;
                                C2->MostrarCola();

                                if (C1->ColaVacia() == false)
                                {
                                    C1->Entrelazado_Colas_Pilas(C2);
                                }
                                else
                                {
                                    cout << "\nLa Cola 1 esta vacia del todo primero ingresele datos" << endl;
                                }                                
                                break;

                            case 7: //salir del menu y terminar el programa
                                break;
                            default:cout << "\nOpcion incorrecta" << endl;
                                system("pause");
                                break;
                        }
                        system("cls");
                } while (opc1 != 7);

                break;

            case 2: 
                do 
                {
                    Menu2();
                    cout << "\nIngrese una opcion:" << endl;
                    cin >> opc1;
                    switch (opc1)
                    {
                        case 1: //Apilar
                            cout << "Ingrese el dato a apilar : ";
                            cin >> dato;
                            if (P1->PilaLlena() == false) {
                                P1->Apilar(dato);
                            }
                            else
                            {
                                cout << "\nLa Pila ya esta llena por lo tanto no se pueden ingresar mas datos " << endl;
                            }
                            system("pause");
                            break;

                        case 2: //Desapilar
                            if (P1->PilaVacia() == false) {
                                P1->Desapilar();
                            }
                            else
                            {
                                cout << "\nLa pila esta vacia " << endl;
                            }
                            system("pause");
                            break;

                        case 3: // Mostrar Pila
                            if (P1->PilaVacia() == false) {
                                P1->MostrarPila();
                            }
                            else
                            {
                                cout << "\nLa pila esta vacia " << endl;
                            }
                            system("pause");
                            break;

                        case 4://apilar ordenado
                            cout << "Ingrese el dato a apilar : ";
                            cin >> dato;
                            if (P1->PilaLlena() == false) {
                                P1->ApilarOrdenado(dato);
                            }
                            else
                            {
                                cout << "\nLa Pila ya esta llena por lo tanto no se pueden ingresar mas datos " << endl;
                            }
                            system("pause");
                            break;

                        case 5:// ordenar pila
                            if (P1->PilaVacia() == false)
                            {
                                P1->OrdenarPila();
                            }
                            else
                            {
                                cout << "\nLa pila esta vacia " << endl;
                            }
                            system("pause");
                            break;

                        case 6://sumar p + c1 = c2
                            if (P1->PilaVacia() == false && C1->ColaVacia() == false)
                            {
                                P1->Suma_PilaCola(C1);                                
                            }
                            else
                            {
                                cout << "La cola o la pila estan vacias por favor llenalas " << endl;
                                cout << "Quieres llenar la cola ? SI = 1 o NO = 2" << endl;
                                cin >> resp;

                                while (resp != 1 && resp != 2)
                                {
                                    cout << "Opcion incorrecta ingrese 1 o 2 " << endl;
                                    cin >> resp;
                                }

                                if (resp == 1)
                                {
                                    while (C1->ColaLlena() == false)
                                    {
                                        cout << "Aun no esta llena entre un numero : " << endl; cin >> dato;
                                        C1->Encolar(dato);
                                    }
                                }
                            }
                                            
                            
                            system("pause");
                            break;

                        case 7: //salir
                            break;
                        default:cout << "\nOpcion incorrecta" << endl;
                            system("pause");
                            break;
                    }
                    system("cls");
                } while (opc1 != 7);                        
                   

            break;
            case 3:// salir
                break;
            default:cout << "\nOpcion incorrecta" << endl;
                    system("pause");
                break;
        }
        system("cls");
    } while (Men != 3);

    cout << "\tGracias por utilizar el programa" << endl << endl;
    system("pause");
    return EXIT_SUCCESS;
}



void Menu()
{
    cout << "\n\t (MENU)Colas " << endl;
    cout << "\n1. Encolar" << endl;
    cout << "\n2. Desencolar " << endl;
    cout << "\n3. Mostrar Cola " << endl;
    cout << "\n4. Encolar ordenado" << endl;
    cout << "\n5. ordenar cola" << endl;
    cout << "\n6. Entrelazados (intercalado ) , el resultado en cola con vectores  " << endl;
    cout << "\n7. Salir " << endl;    
 }
    

void Menu2()
{
    cout << "\n\t (MENU)Pilas " << endl;
    cout << "\n1. Apilar " << endl;
    cout << "\n2. Desapilar " << endl;
    cout << "\n3. Mostrar Pila " << endl;
    cout << "\n4. Apilar ordenado" << endl;
    cout << "\n5. Ordenar pila " << endl;
    cout << "\n6. Sumar p1 + c = c2" << endl;
    cout << "\n7. Salir " << endl;   
}