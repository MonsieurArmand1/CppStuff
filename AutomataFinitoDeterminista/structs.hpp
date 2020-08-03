#include <string>
#include <cstddef>
#include <string.h>

using namespace std;

struct AlfabetoEntrada {
    char simbolo;
    AlfabetoEntrada *siguiente;
};

AlfabetoEntrada *InicioAE = NULL;
AlfabetoEntrada *finAE = NULL;
AlfabetoEntrada *nuevoAE = NULL;
AlfabetoEntrada *ptrAE = NULL;

struct AlfabetoSalida {
    char simbolo;
    AlfabetoSalida *siguiente;
};

AlfabetoSalida *inicioAS = NULL;
AlfabetoSalida *finAS = NULL;
AlfabetoSalida *nuevoAS = NULL;
AlfabetoSalida *ptrAS = NULL;

struct Matriz; //forward declaration

struct Estado { //estructura para nodos de estados posibles
    string dato;
    bool validacion;
    Estado *siguiente;
    Matriz *aristas; //apunta a los nodos (aristas) de la matriz
};

Estado *inicio = NULL;
Estado *fin = NULL;
Estado *nuevo = NULL;
Estado *ptr = NULL;
Estado *q0 = NULL;

struct Matriz { //estructura para nodos de la matriz
    char simbolo;
    char traduccion;
    Estado *transicion;
    Matriz *siguiente;
} override;

Matriz *inicioM = NULL;
Matriz *finM = NULL;
Matriz *nuevaM = NULL;
Matriz *ptrM = NULL;

void ingresaAlfabetoEntrada();
void ingresaAlfabetoSalida();
void estadosPosibles();
void capturaEstadoInicial();
void estadoAceptacion();
void matrizTransicion();
void matrizTraduccion();
void palabraTraducida();
void palabraValidada();
void borrarPunteros();
void validarAlfabeto();
void estadisticas();

int totalAFDs = 0, afdTraduccion = 0, afdValidacion = 0, totalEstados = 0,
totalPalabras = 0, palabrasTraducidas = 0, palabrasValidadas = 0;
