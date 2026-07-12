#include <iostream>

using namespace std;
#include "Funciones.h"
/*
Sistema de Monitoreo Climático
Una empresa de meteorología necesita un sistema para registrar y analizar datos climáticos de distintas ciudades. El sistema debe manejar información de 4 ciudades.
Por cada ciudad se registra:

Código de ciudad (int)
Nombre de ciudad (string)
Temperatura máxima registrada en °C (float)
Cantidad de días con lluvia en el mes (int)


Requerimientos del sistema:
El sistema debe contar con un menú que permita:
Opción A — Cargar datos de las ciudades
Opción B — Mostrar el reporte completo de todas las ciudades
Opción C — Determinar qué ciudad tuvo la temperatura más alta e informar su nombre
Opción D — Calcular la temperatura promedio entre todas las ciudades
Opción E — Informar qué porcentaje de ciudades tuvieron más de 15 días con lluvia
Opción F — Contar cuántas ciudades tuvieron temperatura mayor a 30°C Y menos de 10 días de lluvia (clima caluroso y seco)
Opción G — Salir del sistema

Condiciones de entrega:

El menú debe mostrar letras, no números
Si el usuario intenta acceder a cualquier opción antes de cargar datos, el sistema debe avisarle
El sistema no debe cerrarse hasta que el usuario elija explícitamente la opción G
Estructura obligatoria: main.cpp, Funciones.h, Funciones.cpp


Nota: el cambio de números a letras en el menú implica que tengas que pensar qué tipo de variable usás para OpcionMenu y cómo cambia la condición del while y el switch. Eso es parte del ejercicio.


Modificación en vivo:
El profesor te dice:
"Quiero que agregues una opción H — Mostrar el nombre de la ciudad con MENOS días de lluvia. Tenés 5 minutos."
*/
int main()
{
    char caracter;

    const int TAM = 4;

    int Codigo[TAM]= {0,0,0,0};
    string Nombre[TAM]= {"","","",""};
    float Temperatura[TAM]= {0,0,0,0};
    int DiasDeLluvia[TAM]= {0,0,0,0};

    bool CiudadesCargadas = false;


    while(caracter != 'G' && caracter != 'g'&& caracter != 'H' && caracter != 'h')
    {
        system("clear");
        MostrarMenu();
        cin>>caracter;

        switch(caracter)
        {

        case 'a':
        case 'A':
        {
            system("clear");
            CargarCiudades(Codigo, Nombre, Temperatura, DiasDeLluvia, TAM);
            CiudadesCargadas = true;
            Pausar();
        }
        break;
        case 'b':
        case 'B':
        {
            if(CiudadesCargadas == false)
            {
                system("clear");
                cout<<"---------------------------"<<endl;
                cout<<"No se registraron ciudades."<<endl;
                cout<<"---------------------------"<<endl;
                Pausar();
            }
            else
            {
                MostrarCiudades(Codigo, Nombre, Temperatura, DiasDeLluvia, TAM);
                Pausar();
            }

        }
        break;
        case 'c':
        case 'C':
        {
            if(CiudadesCargadas == false)
            {
                system("clear");
                cout<<"---------------------------"<<endl;
                cout<<"No se registraron ciudades."<<endl;
                cout<<"---------------------------"<<endl;
                Pausar();
            }
            else
            {
                int resultado = BuscarTemperaturaMasAlta(Nombre, Temperatura, TAM);
                cout<<"La ciudad con mayor temperatura es : " << Nombre[resultado]<<endl;
                Pausar();
            }

        }
        break;
        case 'd':
        case 'D':
        {
            if(CiudadesCargadas == false)
            {
                system("clear");
                cout<<"---------------------------"<<endl;
                cout<<"No se registraron ciudades."<<endl;
                cout<<"---------------------------"<<endl;
                Pausar();
            }
            else
            {
                float resultado = CalcularTemperaturaPromedio (Temperatura, TAM);
                cout<<"La temperatura promedio entre todas las ciudades es de : " << resultado << endl;
                Pausar();
            }
        }
        break;
        case 'e':
        case 'E':
        {
            if(CiudadesCargadas == false)
            {
                system("clear");
                cout<<"---------------------------"<<endl;
                cout<<"No se registraron ciudades."<<endl;
                cout<<"---------------------------"<<endl;
                Pausar();
            }
            else
            {
                float resultado = Porcentaje (DiasDeLluvia, TAM);
                cout<<"El porcentaje de ciudades tuvieron más de 15 días con lluvia  es : " << resultado <<endl;
                Pausar();
            }
        }
        break;
        case 'f':
        case 'F':
        {
            if(CiudadesCargadas == false)
            {
                system("clear");
                cout<<"---------------------------"<<endl;
                cout<<"No se registraron ciudades."<<endl;
                cout<<"---------------------------"<<endl;
                Pausar();
            }
            else
            {
                int resultado = TemperaturaMayor30YmenosDiezDiasLLuvia(Temperatura, DiasDeLluvia, TAM);
                cout<<"La cantidad de cuidades que tienen una temperatura mayor a 30 y menos de 10 dias de lluvia son : " << resultado<<endl;
                Pausar();
            }
        }
        break;
        case 'g':
        case 'G':
        {
            system("clear");
            cout<<"-----------------------------"<<endl;
            cout<<"Esta saliendo del programa..."<<endl;
            cout<<"-----------------------------"<<endl;
            Pausar();
        }
        break;
        case 'h':
        case 'H':
        {
              if(CiudadesCargadas == false)
            {
                system("clear");
                cout<<"---------------------------"<<endl;
                cout<<"No se registraron ciudades."<<endl;
                cout<<"---------------------------"<<endl;
                Pausar();
            }else
            {
                int resultado = MostrarCiudadMenosLluvia(Nombre, DiasDeLluvia, TAM);
                cout<<"La cuidad con menos cantidad de dias de lluevia es : " << Nombre[resultado] <<endl;
                Pausar();
            }
        }
        break;

        }//fin switch
    }//fin while




    return 0;
}
