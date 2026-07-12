#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
using namespace std;

void Pausar();
void LimpiarPantalla();
void MostrarMenu();

// codigo, nombre temperatura diaslluvia
//a
void CargarCiudades(int vec1[], string vec2[], float vec3[], int vec4[], int tamanio);

//b
void MostrarCiudades(int vec1[], string vec2[], float vec3[], int vec4[], int tamanio);

int BuscarTemperaturaMasAlta(string vec2[], float vec3[], int tamanio);

float CalcularTemperaturaPromedio (float vec3[], int tamanio);

float Porcentaje (int vec4[], int tamanio);

//Contar cuántas ciudades tuvieron temperatura mayor a 30°C Y menos de 10 días de lluvia (clima caluroso y seco).

int TemperaturaMayor30YmenosDiezDiasLLuvia(float vec3[], int vec4[], int tamanio);

int MostrarCiudadMenosLluvia(string vec2[], int vec4[], int tamanio);

#endif // FUNCIONES_H_INCLUDED
