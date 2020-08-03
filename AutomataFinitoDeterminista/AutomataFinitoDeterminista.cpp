#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

#include "informacion.hpp"
#include "limpiar.hpp"
#include "structs.hpp"

int main() {
	cout << "*********************AUTOMATA FINITO DETERMINISTA*************************\n";
	cout << "******Por: Armando Del Rio Ramirez\n";
	cout << "******Materia: Metodos Formales\n";
	cout << "**************************************************************************\n\n";
	short opcionMenu = 0;
    do {
        cout << "Registre el numero de la opcion deseada" << endl;
		cout << "1. Informacion\n" << "2. Traduccion\n" << "3. Validacion\n";
		cout << "4. Estadisticas\n" << "5. Salir\n" << "\tOpcion: ";
		cin >> opcionMenu; cout << endl << endl;
        if (cin.fail()) {
            cout << "Opcion invalida, por favor intente de nuevo\n";
            cin.clear();
            cin.ignore(80, '\n');
        } else {
            switch (opcionMenu) {
				case 1:
					informacion();
					break;
                case 2:///TRADUCCION
                    ingresaAlfabetoEntrada();
                    estadosPosibles();
                    capturaEstadoInicial();
                    estadoAceptacion();
                    matrizTransicion();
                    palabraValidada();
                    totalAFDs++;
                    afdValidacion++;
                    borrarPunteros();
                    break;
                case 3:    ///VALIDAR PALABRA
                    ingresaAlfabetoEntrada();
                    ingresaAlfabetoSalida();
                    estadosPosibles();
                    capturaEstadoInicial();
                    estadoAceptacion();
                    matrizTransicion();
                    matrizTraduccion();
                    palabraTraducida();
                    totalAFDs++;
                    afdTraduccion++;
                    borrarPunteros();
                    break;
                case 4: ///ESTADISTICAS
                    estadisticas();
                    break;
				case 5: ///SALIR
                    system("cls");
					return 0;
					break;
                default:
					cout << "Opcion invalida, por favor intente de nuevo\n";
            }
        }
    } while (opcionMenu != 5);

    return 0;
}

void validarAlfabeto() {
    ptrAE = InicioAE;
    cout << "E: ";
    while (ptrAE != NULL) {
        cout << ptrAE->simbolo << " " << endl;
        ptrAE = ptrAE->siguiente;
    }

    if (inicioAS != NULL) {
        ptrAS = inicioAS;
        cout << "S: ";
        while (ptrAS != NULL) {
            cout << ptrAS->simbolo << "  " << endl;
            ptrAS = ptrAS->siguiente;
        }
    }

    if (inicio != NULL) {
        ptr = inicio;
        cout << "Q: ";
        while (ptr != NULL) {
            cout << ptr->dato << " " << endl;
            ptr = ptr->siguiente;
        }
    }

    if (q0 != NULL) {
        cout << "q0: " << q0->dato << endl;
    }

    cout << endl;
}

void ingresaAlfabetoEntrada() {
    string simb_t = "";
    int i = 1;
    bool check = false;
    cout << "Ingrese el alfabeto de entrada, un simbolo a la vez. '*' para terminar: " << endl;
    while (true) {
        cout << i << ": ";
        cin>>simb_t;
        if (simb_t.length() != 1)
            cout << "¡Tranquilo! Solamente puede ingresar un símbolo a la vez :)\n" << endl;
        else {
            if (simb_t == "*") {
                if (InicioAE == NULL)
                    cout << "No es posible tener un alfabeto de entrada vacio" << endl;
                else
                    break;
            }
            char simb = simb_t[0];
            int ascii_simb = (int) simb;//Parseo a ASCII
            if (ascii_simb >= 48 && ascii_simb <= 57 || ascii_simb >= 65 && ascii_simb <= 90 
                || ascii_simb >= 97 && ascii_simb <= 122 || ascii_simb == -15 
                || ascii_simb == -47) {
                if (InicioAE == NULL) {
                    nuevoAE = new(AlfabetoEntrada);
                    nuevoAE->simbolo = simb;
                    InicioAE = nuevoAE;
                    finAE = nuevoAE;
                    finAE->siguiente = NULL;
                    i++;
                } else {
                    check = true;
                    ptrAE = InicioAE;
                    while (ptrAE != NULL) {
                        if (ptrAE->simbolo == simb) {
                            check = false;
                            break;
                        }
                        ptrAE = ptrAE->siguiente;
                    }
                    if (check == false)
                        cout << "No se pueden ingresar simbolos repetidos\n" << endl;
                    else {
                        nuevoAE = new(AlfabetoEntrada);
                        nuevoAE->simbolo = simb;
                        finAE->siguiente = nuevoAE;
                        finAE = nuevoAE;
                        finAE->siguiente = NULL;
                        i++;
                    }
                }
            } else {
                if (simb_t != "*")
                    cout << "Este simbolo no es válido--\n" << endl;
            }
        }
    }
    ptrAE = InicioAE;
    cout << "El Alfabeto de entrada es: ";
    while (ptrAE != NULL) {
        cout << ptrAE->simbolo << " ";
        ptrAE = ptrAE->siguiente;
    }
    cout << endl << endl;
    
    validarAlfabeto();
}

void ingresaAlfabetoSalida() {
    string simb_t = "";
    int i = 1;
    bool check = false;
    cout << "Ingrese el alfabeto de salida (seleccione '*' para terminar): " << endl;
    while (true) {
        cout << i << ": ";
        cin>>simb_t;
        if (simb_t.length() != 1)
            cout << "¡Tranquilo! Solamente puede ingresar un símbolo a la vez :)\n" << endl;
        else {
            if (simb_t == "*") {
                if (inicioAS == NULL)
                    cout << "No es posible tener un alfabeto de entrada vacio" << endl;
                else
                    break;
            }
            char simb = simb_t[0];
            int ascii_simb = (int) simb;
            if (ascii_simb >= 48 && ascii_simb <= 57 || ascii_simb >= 65 && ascii_simb <= 90 
                || ascii_simb >= 97 && ascii_simb <= 122 || ascii_simb == -15 
                || ascii_simb == -47) {
                if (inicioAS == NULL) {
                    nuevoAS = new(AlfabetoSalida);
                    nuevoAS->simbolo = simb;
                    inicioAS = nuevoAS;
                    finAS = nuevoAS;
                    finAS->siguiente = NULL;
                    i++;
                } else {
                    check = true;
                    ptrAS = inicioAS;
                    while (ptrAS != NULL) {
                        if (ptrAS->simbolo == simb) {
                            check = false;
                            break;
                        }
                        ptrAS = ptrAS->siguiente;
                    }
                    if (check == false)
                        cout << "No es posible ingresar simbolos repetidos\n" << endl;
                    else {
                        nuevoAS = new(AlfabetoSalida);
                        nuevoAS->simbolo = simb;
                        finAS->siguiente = nuevoAS;
                        finAS = nuevoAS;
                        finAS->siguiente = NULL;
                        i++;
                    }
                }
            } else {
                if (simb_t != "*")
                    cout << "El simbolo ingresado no es válido\n" << endl;
            }
        }
    }
    ptrAS = inicioAS;
    cout << "El alfabeto de salida es: ";
    while (ptrAS != NULL) {
        cout << ptrAS->simbolo << " ";
        ptrAS = ptrAS->siguiente;
    }
    cout << endl;
    
    validarAlfabeto();
}

void estadosPosibles() {
    totalEstados = 0;
    string estado = "";
    int i = 1;
    bool s = false, check = false;
    cout << "Ingrese el conjunto de estados posibles 'Q'. '*' para terminar: \n";
    while (true) {
        cout << i << ": ";
        cin>>estado;
        if (estado.length() > 15) //Verificar la longitud de caracteres ingresados, máximo 15
            cout << "La cardinalidad maxima de la palabra es de 15 caracteres\n" << endl;
        else {
            if (estado == "*") {
                if (inicio == NULL)
                    cout << "No es posible tener estados vacios\n";
                else
                    break;
            }
            int longitud = estado.length();
            int j;
            for (j = 0; j < longitud; j++) {
                char simb = estado[j]; //Pasar el string a un char
                int ascii_simb = (int) simb; //regresa el valor ingresado en codigo ASCII
                if (ascii_simb >= 48 && ascii_simb <= 57 || ascii_simb >= 65 && ascii_simb <= 90 || ascii_simb >= 97 && ascii_simb <= 122 || ascii_simb == -15 || ascii_simb == -47)
                    //Para que solo admita letras en español mayúsculas, minúsculas y números del 0 al 9
                    s = true;
                else {
                    if (estado != "*")
                        cout << "El input contiene simbolos invalidos\n" << endl;
                    break;
                }
            }
            if (j == longitud) {
                if (inicio == NULL) {
                    nuevo = new(Estado);
                    nuevo->dato = estado;
                    inicio = nuevo;
                    fin = nuevo;
                    fin->siguiente = NULL;
                    i++;
                } else {
                    check = true;
                    ptr = inicio;
                    while (ptr != NULL) {
                        if (ptr->dato == estado) {
                            check = false;
                            break;
                        }
                        ptr = ptr->siguiente;
                    }
                    if (check == false)
                        cout << "No es posible ingresar simbolos repetidos\n" << endl;
                    else {
                        nuevo = new(Estado);
                        nuevo->dato = estado;
                        fin->siguiente = nuevo;
                        fin = nuevo;
                        fin->siguiente = NULL;
                        i++;
                    }
                }
            }
        }
    }
    totalEstados = i - 1;
    cout << "El total de estados es: " << totalEstados << endl;
    ptr = inicio;
    cout << "El Conjunto de estados de Posibles es: ";
    while (ptr != NULL) {
        cout << ptr->dato << " ";
        ptr = ptr->siguiente;
    }
    cout << endl << endl;

    validarAlfabeto();
}

void capturaEstadoInicial() {
    string q = "";
    bool check; //check true = no existe el dato; check = false ya existe
    while (true) {
        cout << "Ingrese el estado inicial de Operación 'q0', debiendo pertenecer a Q: ";
        cin >> q;
        check = true;
        ptr = inicio;
        while (ptr != NULL) {
            if (ptr->dato == q) {
                check = false;
                break;
            }
            ptr = ptr->siguiente;
        }
        if (check == false) {
            q0 = ptr;
            cout << "El estado inicial es: " << q0->dato << endl;
            break;
        } else
            cout << "El estado ingresado no pertenece a Q, intente de nuevo\n"
             << endl << endl;
    }

    validarAlfabeto();
}

void estadoAceptacion() {
    char estado = 't';
    bool validarOpcion = false;
    cout << "Determine el conjunto de Estados de aceptacion: \n";
    cout << "'T' = True (Estado aceptado). 'F' = False (Estado NO aceptado)" << endl << endl;
    ptr = inicio;
    while (ptr != NULL) {
        do {
            validarOpcion = true;
            cout << ptr->dato << "---------------->";
            cin>>estado; toupper(estado);
            switch (estado) {
                case 'T': ptr->validacion = true;
                    break;
                case 'F': ptr->validacion = false;
                    break;
                default: cout << "\nLa opcion no es valida, vuelva a intentar" << endl << endl;
                    validarOpcion = false;
            }
        } while (validarOpcion != true);
        ptr = ptr->siguiente;
    }
    cout << "Los estados de aceptacion del conjunto son: ";
    ptr = inicio;
    while (ptr != NULL) {
        if (ptr->validacion == true)
            cout << ptr->dato << " ";
        ptr = ptr->siguiente;
    }
    cout << endl;
    
    validarAlfabeto();
}

void matrizTransicion() {
    string temp = "";
    bool check = false;
    Estado *ptr_temp = NULL;
    for (ptr = inicio; ptr != NULL; ptr = ptr->siguiente) {
        for (ptrAE = InicioAE; ptrAE != NULL; ptrAE = ptrAE->siguiente) {
            if (inicioM == NULL) {
                nuevaM = new(Matriz);
                nuevaM->simbolo = ptrAE->simbolo;
                inicioM = nuevaM;
                finM = nuevaM;
                finM->siguiente = NULL;
            } else {
                nuevaM = new(Matriz);
                nuevaM->simbolo = ptrAE->simbolo;
                finM->siguiente = nuevaM;
                finM = nuevaM;
                finM->siguiente = NULL;
            }
        }
        ptr->aristas = inicioM;
        inicioM = NULL;
        finM = NULL;
        nuevaM = NULL;
    }
    cout << "Ingrese la matriz de transicion: " << endl;
    for (ptr = inicio; ptr != NULL; ptr = ptr->siguiente) {
        for (ptrM = ptr->aristas; ptrM != NULL; ptrM = ptrM->siguiente) {
            while (true) {
                cout << ptr->dato << " - " << ptrM->simbolo << "---------->";
                cin >> temp;
                check = true;
                ptr_temp = inicio;
                while (ptr_temp != NULL) {
                    if (ptr_temp->dato == temp) {
                        check = false;
                        break;
                    }
                    ptr_temp = ptr_temp->siguiente;
                }
                if (check == false) {
                    ptrM->transicion = ptr_temp;
                    break;
                } else
                    cout << "--El estado ingresado no pertenece a Q, vuelva a intentar--\n" << endl;
            }
        }
    }
    cout << endl << endl << endl;
    for (ptr = inicio; ptr != NULL; ptr = ptr->siguiente) {
        for (ptrM = ptr->aristas; ptrM != NULL; ptrM = ptrM->siguiente) {
            cout << ptr->dato << " - " << ptrM->simbolo << "---------->" << ptrM->transicion->dato << endl;
        }
    }

    validarAlfabeto();

}

void matrizTraduccion() {
    string temp = "";
    bool check = false;
    AlfabetoSalida *ptr_temp = NULL;
    cout << "Ingrese Matriz de Traducción: " << endl;
    for (ptr = inicio; ptr != NULL; ptr = ptr->siguiente) {
        for (ptrM = ptr->aristas; ptrM != NULL; ptrM = ptrM->siguiente) {
            while (true) {
                cout << ptr->dato << " - " << ptrM->simbolo << "---------->";
                cin >> temp;
                if (temp.length() != 1){
                    cout << "--Solamente puede ingresar un símbolo a la vez--\n" << endl;
                }else {
                    char simb = temp[0];
                    check = true;
                    ptr_temp = inicioAS;
                    while (ptr_temp != NULL) {
                        if (ptr_temp->simbolo == simb) {
                            check = false;
                            break;
                        }
                        ptr_temp = ptr_temp->siguiente;
                    }
                    if (check == false) {
                        ptrM->traduccion = ptr_temp->simbolo;
                        break;
                    } else
                        cout << "Este simbolo no pertenece al alfabeto de salida. Intentalo de nuevo\n\n";
                }
            }
        }
    }
    cout << endl << endl << endl;
    for (ptr = inicio; ptr != NULL; ptr = ptr->siguiente) {
        for (ptrM = ptr->aristas; ptrM != NULL; ptrM = ptrM->siguiente) {
            cout << ptr->dato << " - " << ptrM->simbolo << "---------->" << ptrM->traduccion << endl;
        }
    }

    validarAlfabeto();
}

void palabraTraducida() {
    char opcionPT = 'a';
    string palabra = "";
    bool check = false;
    do {
        ptrAE = InicioAE; //Muestra Alfabeto de Entrada
        cout << "E: ";
        while (ptrAE != NULL) {
            cout << ptrAE->simbolo << " ";
            ptrAE = ptrAE->siguiente;
        }
        cout << endl << endl;
        cout << "Ingrese palabra a Traducir: ";
        cin >> palabra;
        int longitud = palabra.length();
        int j;
        for (j = 0; j < longitud; j++) {
            char simb = palabra[j];
            int ascii_simb = (int) simb;
            if (ascii_simb >= 48 && ascii_simb <= 57 || ascii_simb >= 65 && ascii_simb <= 90 
                || ascii_simb >= 97 && ascii_simb <= 122 || ascii_simb == -15 
                || ascii_simb == -47) {
                check = true;
            } else {
                cout << "La palabra tiene simbolos invalidos\n" << endl;
                break;
            }
        }
        for (j = 0; j < longitud; j++) {
            char simb = palabra[j];
            check = true;
            ptrAE = InicioAE;
            while (ptrAE != NULL) {
                if (ptrAE->simbolo == simb) {
                    check = false;
                    break;
                }
                ptrAE = ptrAE->siguiente;
            }
            if (check == true) {
                cout << "Este simbolo no pertenece al alfabeto de entrada. Intentalo de nuevo\n\n";
                break;
            }
        }
        int k = j;

        if (j == longitud) {
            cout << "La palabra traducida es: ";
            ptrM = q0->aristas;
            j = 0;
            char simb = palabra [j];
            while (ptrM != NULL) {
                if (ptrM->simbolo == simb)
                    break;
                ptrM = ptrM->siguiente;
            }
            cout << ptrM->traduccion;
            if (k > 1) {
                for (j = 1; j < longitud; j++) {
                    ptr = ptrM->transicion;
                    ptrM = ptrM->transicion->aristas;
                    char simb = palabra [j];
                    while (ptrM != NULL) {
                        if (ptrM->simbolo == simb)
                            break;
                        ptrM = ptrM->siguiente;
                    }
                    cout << ptrM->traduccion;
                }
            }
            cout << endl;
        }

        if (k == longitud) {
            if (k <= 1) {
                if (q0->validacion == true) {
                    cout << "La palabra es valida\n" << endl;
                    palabrasValidadas++;
                } else
                    cout << "La palabra es invalida\n" << endl;
                palabrasTraducidas++;
                totalPalabras++;
            } else {
                if (ptr->validacion == true) {
                    cout << "La palabra es valida\n" << endl;
                    palabrasValidadas++;
                } else
                    cout << "La palabra es invalida\n" << endl;
                palabrasTraducidas++;
                totalPalabras++;
            }
        }
        do {
            cout << "¿Desea ingresar otra palabra? (Si = 'S' ; No = 'N'): ";
            cin>>opcionPT; toupper(opcionPT);
            cout << endl;
            switch (opcionPT) {
                case 'S':  
                    cout << endl;
                case 'N':
                    break;
                default:  
                    cout << "\nOpcion invalida" << endl;
            }
        } while (opcionPT != 'S' && opcionPT != 'N');
    } while (opcionPT != 'N');
}

void palabraValidada() {
    char opcionPV = 'a';
    string palabra = "";
    bool check = false;
    int j = 0;
    do {
        ptrAE = InicioAE;
        cout << "E: ";
        while (ptrAE != NULL) {
            cout << ptrAE->simbolo << " ";
            ptrAE = ptrAE->siguiente;
        }
        cout << endl << endl;
        cout << "Ingrese palabra a Validar: ";
        cin>> palabra;
        int longitud = palabra.length();
        for (j = 0; j < longitud; j++) {
            char simb = palabra[j];
            int ascii_simb = (int) simb;
            if (ascii_simb >= 48 && ascii_simb <= 57 || ascii_simb >= 65 && ascii_simb <= 90 
                || ascii_simb >= 97 && ascii_simb <= 122 || ascii_simb == -15 
                || ascii_simb == -47) {
                check = true;
            } else {
                cout << "La palabra tiene simbolos invalidos\n" << endl;
                break;
            }
        }
        for (j = 0; j < longitud; j++) {
            char simb = palabra[j];
            check = true;
            ptrAE = InicioAE;
            while (ptrAE != NULL) {
                if (ptrAE->simbolo == simb) {
                    check = false;
                    break;
                }
                ptrAE = ptrAE->siguiente;
            }
            if (check == true) {
                cout << "La palabra contiene simbolos ajenos al alfabeto de entrada\n" << endl;
                break;
            }
        }
        int k = j;
        cout << "k: " << k << endl;
        cout << "j: " << j << endl;
        cout << "longitud: " << longitud << endl;
        if (j == longitud) {
            cout << "La palabra ingresada es: ";
            ptrM = q0->aristas;
            j = 0;
            char simb = palabra [j];
            while (ptrM != NULL) {
                if (ptrM->simbolo == simb)
                    break;
                ptrM = ptrM->siguiente;
            }
            if (j > 1) {
                for (j = 1; j < longitud; j++) {
                    ptr = ptrM->transicion;
                    ptrM = ptrM->transicion->aristas;
                    char simb = palabra [j];
                    while (ptrM != NULL) {
                        if (ptrM->simbolo == simb)
                            break;
                        ptrM = ptrM->siguiente;
                    }
                }
            }
        }
        if (check = true) {
            if (k = 1) {
                if (q0->validacion == true) {
                    cout << "valida" << endl;
                    palabrasValidadas++;
                } else
                    cout << "invalida" << endl;
                palabrasTraducidas++;
                totalPalabras++;
            } else {
                if (ptr->validacion == true) {
                    cout << "valida" << endl;
                    palabrasValidadas++;
                } else
                    cout << "invalida" << endl;
                palabrasTraducidas++;
                totalPalabras++;
            }
        }
        do {
            cout << "\n¿Desea ingresar otra palabra? (Si = 'S' ; No = 'N'): ";
            cin>>opcionPV; toupper(opcionPV);
            cout << endl;
            switch (opcionPV) {
                case 'S':  
                    cout << endl;
                case 'N':
                    break;
                default:
                    cout << "Opcion invalida, intente de nuevo\n" << endl;
            }
        } while (opcionPV != 'S' && opcionPV != 'N');
    } while (opcionPV != 'N');
}

void borrarPunteros() {
    ptrAE = InicioAE;
    while (ptrAE->siguiente != NULL) {
        ptrAE = InicioAE;
        InicioAE = ptrAE->siguiente;
        delete(ptrAE);
    }
    delete(InicioAE);
    InicioAE = NULL;
    finAE = NULL;
    ptrAE = NULL;
    nuevoAE = NULL;

    if (inicioAS != NULL) {
        ptrAS = inicioAS;
        while (ptrAS->siguiente != NULL) {
            ptrAS = inicioAS;
            inicioAS = ptrAS->siguiente;
            delete(ptrAS);
        }
        delete(inicioAS);
        inicioAS = NULL;
        finAS = NULL;
        ptrAS = NULL;
        nuevoAS = NULL;
    }

    for (ptr = inicio; ptr->siguiente != NULL; ptr = ptr->siguiente) {
        inicioM = ptr->aristas;
        ptr->aristas = NULL;
        while (inicioM->siguiente != NULL) {
            ptrM = inicioM;
            inicioM = ptrM->siguiente;
            delete(ptrM);
        }
        delete(inicioM);
        inicioM = NULL;
        finM = NULL;
        ptrM = NULL;
        nuevaM = NULL;
    }

    ptr = inicio;
    while (ptr->siguiente != NULL) {
        ptr = inicio;
        inicio = ptr->siguiente;
        delete(ptr);
    }
    delete(inicio);
    inicio = NULL;
    fin = NULL;
    ptr = NULL;
    nuevo = NULL;
    q0 = NULL;
}

void estadisticas(){
    cout << "Total de AFDs: " << totalAFDs << endl;
    cout << "Total de AFDs de Traduccion: " << afdTraduccion << endl;
    cout << "Total de AFDs de Validacion: " << afdValidacion << endl;
    cout << "Palabras ingresadas: " << totalPalabras << endl;
    cout << "Palabras traducidas: " << palabrasTraducidas << endl;
    cout << "Palabras validas: " << palabrasValidadas << endl;
    cout << "Palabras invalidas: " << totalPalabras - palabrasValidadas << endl;
}