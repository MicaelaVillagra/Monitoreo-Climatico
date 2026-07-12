#include <iostream>
#include <cstdlib>
using namespace std;
#include "Funciones.h"
#include <string>

void Pausar()
{
    cout<<"Presione enter para continuar..."<<endl;
    cin.ignore();
    cin.get();
}
void LimpiarPantalla()
{
    system("clear");
}
void MostrarMenu()
{
    cout<<"==================================================================================================================="<<endl;
    cout<<"                                                 MENU                                                              "<<endl;
    cout<<"==================================================================================================================="<<endl;
    cout<<" A — Cargar datos de las ciudades.  "<<endl;
    cout<<" B — Mostrar el reporte completo de todas las ciudades. " <<endl;
    cout<<" C — Determinar qué ciudad tuvo la temperatura más alta e informar su nombre. " <<endl;
    cout<<" D — Calcular la temperatura promedio entre todas las ciudades. " <<endl;
    cout<<" E — Informar qué porcentaje de ciudades tuvieron más de 15 días con lluvia " <<endl;
    cout<<" F — Contar cuántas ciudades tuvieron temperatura mayor a 30°C Y menos de 10 días de lluvia (clima caluroso y seco). " <<endl;
    cout<<" G — Salir del sistema. " << endl;
    cout<<" H - Mostrar el nombre de la ciudad con MENOS días de lluvia"<<endl;
    cout<<"==================================================================================================================="<<endl;

    cout<<"Ingrese la opcion elegida : "<<endl;
}

void CargarCiudades(int vec1[], string vec2[], float vec3[], int vec4[], int tamanio)
{
    cout<<"========================================================"<<endl;
    cout<<"                     CARGAR CIUDADES                    "<<endl;
    cout<<"========================================================"<<endl;

    for(int i  = 0 ; i < tamanio; i++)
    {
        cout<<"Ingrese el codigo de la ciudad : "<<endl;
        cin>> vec1[i];

        cout<<"Ingrese el nombre de la ciudad : "<<endl;
        cin.ignore();
        getline(cin,vec2[i]);

        cout<<"Ingrese la temperatura : "<< endl;
        cin>>vec3[i];

        cout<<"Ingrese la cantidad de dias que llovio en el mes :" <<endl;
        cin>>vec4[i];
    }
}

void MostrarCiudades(int vec1[], string vec2[], float vec3[], int vec4[], int tamanio)
{
    cout<<"========================================================"<<endl;
    cout<<"                    MOSTRAR CIUDADES                    "<<endl;
    cout<<"========================================================"<<endl;
    for (int i= 0; i< tamanio ;i++ )
    {
        cout<<"Codigo de la ciudad : " << vec1[i] <<endl;
        cout<<"Nombre de la ciudad : "<< vec2[i] << endl;
        cout<<"Temperatura de la ciudad : " << vec3[i] <<endl;
        cout<<"Cantidad de dias que llovio en el mes : "<< vec4[i] <<endl;
    }

}

int BuscarTemperaturaMasAlta(string vec2[], float vec3[], int tamanio)
{
    cout<<"========================================================"<<endl;
    cout<<"                TEMPERATURA MAS ALTA                    "<<endl;
    cout<<"========================================================"<<endl;
    float TemperaturaMasAlta = vec3[0];
    int posicion = 0;

    for (int i = 1; i < tamanio ; i ++ )
        {
            if(vec3[i] > TemperaturaMasAlta)
            {
                TemperaturaMasAlta= vec3[i];
                posicion = i;
            }
        }
        return posicion;
}

float CalcularTemperaturaPromedio (float vec3[], int tamanio)
{
    cout<<"========================================================"<<endl;
    cout<<"                 PROMEDIO TEMPERATURA                   "<<endl;
    cout<<"========================================================"<<endl;
    float suma = 0;

    for (int i = 0; i <tamanio ; i ++ )
    {
        suma += vec3[i];
    }

    float promedio = (float)suma/ tamanio;
    return promedio;

}

float Porcentaje (int vec4[], int tamanio)
{
    cout<<"========================================================"<<endl;
    cout<<"                 PROMEDIO TEMPERATURA                   "<<endl;
    cout<<"========================================================"<<endl;
    int contador = 0;

    for (int i = 0; i < tamanio ; i++ )
        {
            if(vec4[i] > 15){
                contador++;
            }
        }

        float porcentajeLluvia = ((float) contador / tamanio )* 100;

        return porcentajeLluvia;
}

int TemperaturaMayor30YmenosDiezDiasLLuvia(float vec3[], int vec4[], int tamanio)
{
    cout<<"========================================================"<<endl;
    cout<<"  TEMPERATURA MAYOR A 30 Y MENOS DE 10 DIAS DE LLUVIA   "<<endl;
    cout<<"========================================================"<<endl;
    int contador = 0;
    for(int i = 0; i < tamanio; i++)
    {
        if(vec3[i] > 30 && vec4[i] < 10){
            contador++;
        }
    }
    return contador;
}

int MostrarCiudadMenosLluvia(string vec2[], int vec4[], int tamanio)
{

    cout<<"========================================================"<<endl;
    cout<<"          CIUDAD CON MENOS DIAS DE LLUVIA               "<<endl;
    cout<<"========================================================"<<endl;
    int MenosLLuvia = vec4[0];
    int posicion = 0;

    for (int i = 1; i < tamanio ; i ++ )
        {
            if(vec4[i] < MenosLLuvia){
                MenosLLuvia = vec4[i];
                posicion = i;
            }
        }
        return posicion;
}

