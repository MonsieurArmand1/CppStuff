/* Copyright[2019] <Armando Del Rio>
[Permitase su distribucion y lectura con fines academicos y de mejora]
"Menu de Ventas con archivos binarios"

RECOMENDACIONES GENERALES:
// Limitar las variables globales lo menos posible; ya que, se quedan modificadas y hay que resetearlas.
// Nombrar las variables con nombre completo a lo que se refiere.
// Para invocar el buscador se recomiendo 'found_local.x'.
// Una instruccion por linea.
// Los objetos o structs van la primera con mayúscula para diferenciar objetos de variables.
//Convertir de string a char, hacer flush de la pantalla y corroborar que cierre.

CONFIGURACIONES:
Version 41:

*Errores en ordenación alfabética y de ID.
*Se comentan las lecturas de texto y se crean archivos de texto y archivos binarios

*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <cstring>

using namespace std;

#include "Structs&VarGlobales.hpp"
#include "Buscadores.hpp"
#include "Prototipos.hpp"
#include "voidAdmin.hpp"
#include "admin_de_productos.hpp"
#include "altas.hpp"
#include "bajas.hpp"
#include "mostrar.hpp"
#include "id.hpp"
#include "alfabeto.hpp"
#include "buscar_productos.hpp"
#include "modificaciones.hpp"
#include "lectura.hpp"
#include "escritura.hpp"
#include "escritura_texto.hpp"
#include "lectura_texto.hpp"
#include "utilidades.hpp"
#include "admin_de_usuarios.hpp"
#include "altas_de_usuarios.hpp"
#include "bajas_de_usuarios.hpp"
#include "mostrar_usuarios.hpp"
#include "buscar_usuarios.hpp"
#include "modificar_usuarios.hpp"
#include "lectura_usuarios_texto.hpp"
#include "escritura_usuarios_texto.hpp"
#include "escritura_usuarios.hpp"
#include "lectura_usuarios.hpp"
#include "venta.hpp"

int main() {
fflush(stdin);
int opcion = 0;
time_t tSac = time(NULL);
struct tm* tmP = localtime(&tSac);
cout << "Hora: " << tmP->tm_hour << ":" << tmP->tm_min << ":"<< tmP->tm_sec << endl;
cout << "Fecha: " << tmP->tm_mday << "/" << tmP->tm_mon+1 << "/"<< tmP->tm_year+1900 << endl << endl;
do {
  lectura();
  //  lectura_texto();
  lectura_usuarios();
  //  lectura_usuarios_texto();
cout << "===================================================================" << endl;
cout << "                          ¡ BIENVENID@ !" << endl;
cout << "===================================================================" << endl;
cout << endl << endl;
        cout << setw(5) << "1. Menu Administrador." << endl;
        cout << setw(5) << "2. Menu Vendedor." << endl;
        cout << setw(5) << "3. Salir." << endl;
        cout << setw(15) << "Opcion:  ";
        cin >> opcion;
        cout << endl;
        cout << endl;
        switch (opcion) {
        case 1:
            admin();
            cout << endl;
            break;
        case 2:
            venta();
            cout << endl;
            break;
        case 3:
            cout << "Saliendo" << endl;
            exit(0);
        default:
            cout <<" -Opcion invalida, intente de nuevo-\n" << endl;
        }
    } while (opcion != 3);
    return 0;
}
