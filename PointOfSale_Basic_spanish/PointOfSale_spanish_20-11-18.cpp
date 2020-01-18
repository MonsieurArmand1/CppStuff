/*Punto de Venta de una tienda de autoservicio. Elaborado por Armando Del Rio Ramirez

Despliega dos Menus:

Administrador: Se pueden elaborar Altas, bajas , consultas, modificaciones, consulta de inventario y admin. de usuarios.
Ventas: Venta de productos y corte de caja con impresion de ticket.
*/
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <math.h>
#include <fstream>
#include <ctime>
using namespace std;

//Funciones Globales / Prototipos

// MENU ADMINISTRADOR
void Admin();
    void altas();
    void bajas();
    void consultas();
    void modificaciones();
    void inventario();
    void admin_de_usuarios(); // ALTAS, BAJAS, MODIFICACIONES, CONSULTAS E INVENTARIO DE PERSONAS DEL PUNTO DE VENTA
        void altas_user();
        void bajas_user();
        void consultas_user();
        void modificaciones_user();
        void inventario_user();
    void corte_de_caja();

void ventas();          // MENU VENTAS
    //VENDEDORES Y TIPOS DE CUENTAS
int idu[100] = {1, 2, 3};
string user[100] = {"armando", "juan", "marta"}; string user_t;
string contrauser[100] = {"admin1", "vend1", "vend2"}; string contrauser_t;
bool estatususer[100] = {1, 1, 1};                       bool estatususer_t;
bool usertype [100] = {1, 0, 0};                        bool usertype_t;     //1.- Administrador. 2.- Vendedor.
float totvend[100] =  {0, 0, 0}; float totalcomp[100];
int totalu = 3;

// INVENTARIO
int id [100] = {0, 1, 2, 3, 4, 5};
string producto [100] = {"agua", "leche", "huevo", "pan", "refresco"};
float pdc[100] = {10, 10, 10, 10, 10};
float pdv[100] = {10, 10, 15, 20, 11};
int existencias[100] = {12, 23, 20, 20, 10};
int nr [100] = {5, 5, 5, 5, 5};
int estatus [100] = {1, 1, 1, 1, 1};
char llamprov[100];
int total = 5;

//VENTAS
float subtotal_vendedor = 0; float subtotal_cliente = 0;
float pu[100]; float puc[100];

//MODIFICACION DE INVENTARIO
string prod_t;
float pdc_t;
float pdv_t;
int existencias_t;
int nr_t;
int estatus_t;

int i = 0;
char resp = toupper(resp);

int buscar(string prod_t) {       // BUSCAR PRODUCTOS
    int i = 0;
    while (i < total) {
        if (prod_t == producto[i]) {
            return i;
        }
        i++;
    }
    return -1;
}

int buscar_u(string user_t) {         // BUSCAR USUARIOS
    int i = 0;
    while (i < totalu) {
        if (user_t == user[i]) {
            return i;
        }
        i++;
    }
    return -1;
}

int main()
{
    time_t tSac = time(NULL);
    struct tm* tmP = localtime(&tSac);
    cout << "Hora: " << tmP->tm_hour << ":" << tmP->tm_min << ":"<< tmP->tm_sec << endl;
    cout << "Fecha: " << tmP->tm_mday << "/" << tmP->tm_mon+1 << "/"<< tmP->tm_year+1900 << endl;
    cout << endl;
    int opcion;
    do
    {
        cout << "==========================================\n";
        cout <<"                ¡Bienvenid@!\n";
        cout << "==========================================\n";
        cout << endl;
        cout << "1. Menu Administrador.\n";
        cout << "2. Menu Vendedor.\n";
        cout << "3. Salir.\n";
        cout << setw(20) << "Opcion:  ";
        cin >> opcion;
        cout << endl;
        cout << endl;

        switch(opcion)
        {
        case 1:
            Admin();
            cout << endl;
            break;
        case 2:
            ventas();
            cout << endl;
            break;
        case 3:
            cout << "Salir." << endl;
            break;
        default:
            cout <<" -Opcion invalida, intente de nuevo-\n";
            cout << endl;
        }
    }
    while(opcion != 3);

    return 0;
}

void Admin()
{
    int cont = true;
    int posu;
     do{
        do{
            cout << setw(20) << "Por favor, ingrese su usuario:  ";
            cin >> user_t;
            posu = buscar_u (user_t);
            cout << setw(20) <<"Ingrese su contrasena:  ";
            cin >> contrauser_t;
            cout << endl;
                if(usertype[posu] == 0 || estatususer[posu] == 0 || contrauser[posu] != contrauser_t || user[posu] != user_t){
                    cout << "Usuario y/o contrsena incorrecto, intentelo de nuevo\n" << endl;

                        return;
                }
         }while(user[posu] != user_t && contrauser[posu] != contrauser_t);
      }while(usertype[posu] != 1 && estatususer[posu] != 1);

    int opcion;
    do
    {
        cout << "==========================================\n";
        cout << "       Menu Administrador de " << user[posu] << endl;
        cout << "==========================================\n";
        cout << endl;
        cout << "1. Altas de Productos.\n" << endl;
        cout << "2. Bajas de Productos.\n" << endl;
        cout << "3. Consultas de Productos.\n" << endl;
        cout << "4. Modificaciones de Productos.\n" << endl;
        cout << "5. Mostrar Inventario.\n" << endl;
        cout << "6. Administracion de Usuarios.\n" << endl;
        cout << "7. Corte de Caja General.\n" << endl;
        cout << "8. Salir.\n" << endl;
        cout << endl;
        cout << setw(20) << "Opcion:  ";
        cin >> opcion; cout << endl;

        switch (opcion)
        {

        case 1:
            altas();
            cout << endl;
            break;
        case 2:
            bajas();
            cout << endl;
            break;
        case 3:
            consultas();
            cout << endl;
            break;
        case 4:
            modificaciones();
            cout << endl;
            break;
        case 5:
            inventario();
            cout << endl;
            break;
        case 6:
            admin_de_usuarios();
            cout << endl;
            break;
        case 7:
            corte_de_caja();
            break;
        case 8:
            cout << "Salir\n";
            break;
        default:
            cout << "Opcion invalida\n";
            cout << endl;
        }
    }
    while(opcion != 8);
}
void altas()
{

        cout << "==========================================\n";
        cout <<"              Altas de Productos\n";
        cout << "==========================================\n";
        cout << endl; cout << endl;

    do{
            cout << "Agregar Producto:  ";
            cin >> prod_t; cout << endl;
            int pos = buscar(prod_t); //POSICION = POS

            if (prod_t == producto[pos]){
                cout << "El producto ya existe\n";
                if(estatus[pos] == 0){
                    cout << "El producto se encuentra dado de baja ¿Desea darlo de alta? (s/n):  ";
                    cin >> resp;
                    if (resp == 's')
                    estatus[pos] = 1;
                    return;
                }
            }
            else{

            pos = total;
            total++;

                do{
                    cout << "Agregar Precio de Compra:  ";
                    cin >> pdc_t; cout << endl;
                    cout << "Agregar Precio de Venta:  ";
                    cin >> pdv_t; cout << endl;
                    if(pdv_t <= pdc_t){
                        cout << "El precio de venta no puede ser menor o igual al precio de venta\n" << endl;
                    }
                }while(pdc_t >= pdv_t);

                id[pos] = pos + 1; producto[pos] = prod_t; pdc[pos] = pdc_t; pdv[pos] = pdv_t;

                do{
                    cout << "Agregar Existencias:  ";
                    cin >> existencias_t; cout << endl;
                    cout << "Agregar nivel de reorden:  ";
                    cin >> nr_t; cout << endl;
                    estatus[pos] = 1; cout << endl;
                    if(existencias_t <= nr_t){
                        cout << "Las existenacias no pueden ser menores o igual al nivel de reorden\n" << endl;
                    }
                }while(existencias_t <= nr_t);
                existencias[pos] = existencias_t; nr[pos] = nr_t;

                total++;

                cout << "Producto agregado con exito\n";
                cout << "¿Desea agregar otro producto? (s/n):  ";
                cin >> resp;

                }

   }while(resp == 's');
}

void bajas()
{

        cout << "==========================================\n";
        cout <<"              Bajas de Productos\n";
        cout << "==========================================\n";
        cout << endl;
    int i = 0;
    char resp = toupper(resp);
    do{
        cout << "¿Cual producto desea dar de baja?:  "; cout << endl;
        cin >> prod_t;

    int pos = buscar(prod_t); //POSICION = POS
    if (estatus[pos] > 0){
        cout << setw(5) << "ID" << " - " << " PRODUCTO" << "  - " << setw(8) << "PdC" << "  - " << setw(5) << "PdV" << " - " << setw(5) << " Existencias" << " - " << setw(5) << "N.R." << " - " << setw(5) << "Estatus" << endl;
        cout << endl;
        cout << id[pos] << " - " << producto[pos] << " - " << pdc[pos]<< " - " << pdv[pos] << " - " << existencias[pos]<< " - " << nr[pos] << " - " << estatus[pos] << endl;
        estatus[pos] = 0;
        cout << " Producto dado de baja con exito\n";
    }
        else{
        cout << "El producto ya esta dado de baja o no se encuentra activo en el sistema\n";
        }

        cout << "\n¿Desea dar de baja otro producto? (s/n):  ";
        cout << endl;
        cin >> resp;
    }while(resp == 's');

}
void consultas()
{

        cout << "==========================================\n";
        cout <<"            Consultas de Productos\n";
        cout << "==========================================\n";
        cout << endl;

    int i = 0;
    char resp = toupper(resp);
    do{
        cout << "¿Cual producto desea buscar?\n"; cout << endl;
        cin >> prod_t;

    int pos = buscar(prod_t); //POSICION = POS
     if(existencias[pos] > nr[pos] && estatus[pos] == 1){
    //if (estatus[pos] >= 0){
        cout << setw(5) << "ID" << " - " << " PRODUCTO" << "  - " << setw(8) << "PdC" << "  - " << setw(5) << "PdV" << " - " << setw(5) << " Existencias" << " - " << setw(5) << "N.R." << " - " << setw(5) << "Estatus" << endl;
        cout << endl;
        cout << id[pos] << " - " << producto[pos] << " - " << pdc[pos]<< " - " << pdv[pos] << " - " << existencias[pos]<< " - " << nr[pos] << " - " << estatus[pos] << endl;
        }

        if (estatus[pos] == 0){
        cout << "\nEl producto no existe o esta dado de baja\n";
        }

    cout << "\n¿Desea consultar otro producto? (s/n):  ";
    cout << endl;
    cin >> resp;
    }while(resp == 's');
}
void modificaciones()
{
        cout << "==========================================\n";
        cout <<"         Modificaciones de Productos\n";
        cout << "==========================================\n";
        cout << endl;

    int opcion;
    char resp = toupper(resp);

       cout << "¿Cual producto desea modificar?\n"; cout << endl;
       cin >> prod_t;

        int pos = buscar(prod_t); //POSICION = POS
        if (estatus[pos] > 0){
            cout << setw(5) << "ID" << " - " << " PRODUCTO" << "  - " << setw(8) << "PdC" << "  - " << setw(5) << "PdV" << " - " << setw(5) << " Existencias" << " - " << setw(5) << "N.R." << " - " << setw(5) << "Estatus" << endl;
            cout << endl;
            cout << id[pos] << " - " << producto[pos] << " - " << pdc[pos]<< " - " << pdv[pos] << " - " << existencias[pos]<< " - " << nr[pos] << " - " << estatus[pos] << endl;
        }
        else{
        cout << "\nEl producto no existe o esta dado de baja\n";
        return;
        }
            cout << endl;
            cout << "1. Nombre de Producto. \n";
            cout << "2. Precio de Compra.\n";
            cout << "3. Precio de Venta.\n";
            cout << "4. Existencias.\n";
            cout << "5. Nivel de reorden. \n";
            cout << "6. Cancelar.\n";
            cin >> opcion; cout << endl;

                switch (opcion){
                case 1:
                {
                    cout << "Nuevo Nombre:  ";
                    cin >> prod_t; cout << endl;
                    producto[pos] = prod_t;
                    cout << "Modificacion Exitosa \n";
                    cout << endl;
                    return;
                }
                case 2:
                {
                    cout << "Nuevo Precio de Compra:  ";
                    cin >> pdc_t; cout << endl;
                    pdc[pos] = pdc_t;
                    cout << "Modificacion Exitosa  ";
                    cout << endl;
                    return;
                }
                case 3:
                {
                    cout << "Nuevo Precio de Venta:  ";
                    cin >> pdv_t; cout << endl;
                    pdv[pos] = pdv_t;
                    cout << "Modificacion Exitosa  ";
                    cout << endl;
                    return;
                }
                case 4:
                {
                    cout << "Cambiar Existencias:  ";
                    cin >> existencias_t; cout << endl;
                    existencias[pos] = existencias_t;
                    cout << "Modificacion Exitosa \n";
                    cout << endl;
                    return;
                }
                case 5:
                {
                    cout << "Cambiar nivel de reorden:  ";
                    cin >> nr_t; cout << endl;
                    nr[pos] = nr_t;
                    cout << "Modificacion Exitosa \n";
                    cout << endl;
                    return;
                }
                case 6:
                {
                    cout << "Cancelando \n";
                    return;
                }
                default:
                    cout << "Opcion Invalida\n"; cout<<endl;
                    break;
                }(opcion != 6);

}
void inventario()
{
int opcion;
    do{
        cout << "==========================================\n";
        cout <<"       Inventario Total de Productos\n";
        cout << "==========================================\n";
        cout << endl;

        cout << "1. Ordenar por ID.\n";
        cout << "2. Ordenar por Producto.\n" << endl;
        cout << setw(20) << "Opcion:  ";
        cin >> opcion; cout << endl;


        switch(opcion){
        case 1:
        {
        char resp = toupper(resp);
        cout << setw(5) << "ID" << " - " << " PRODUCTO" << "  - " << setw(8) << "PdC" << "  - " << setw(5) << "PdV" << " - " << setw(5) << " Existencias" << " - " << setw(5) << "N.R." << " - " << setw(5) << "Estatus" << endl;
        cout << endl;
            for (int pos = 0; pos < total; pos++)
               if (estatus[pos] == 1){
                cout << setw(5) << id[pos] << " - " << " " << producto[pos] << " - " << setw(5) << pdc[pos]<< " - " << setw(5) << pdv[pos] << " - " << setw(5) << existencias[pos]<< " - " << setw(5) << nr[pos] << " - " << setw(5) << estatus[pos] << endl;
                if (existencias[i] <= nr[i]){
                    cout << "Llamar a proveedor\n";
                }
            cout << endl;
            cout << "Para regresar pulse '*'\n";
            cin >> resp;
            if (toupper(resp) == '*')
                return;
                }

                /*clrscr();
                int total, i, id[pos], j, temp;
                for(i=0; i<n; i++)
                {
                        cin>>arr[i];
                }
                cout<<"Sorting array using bubble sort technique...\n";
                for(i=0; i<(n-1); i++)
                {
                    for(j=0; j<(n-i-1); j++)
                    {
                        if(arr  [j]>arr[j+1])
                    {
                        temp=arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=temp;
                        }
                    }
                }
                    cout<<"Elements sorted successfully..!!\n";
                    cout<<"Sorted list in ascending order :\n";
                    for(i=0; i<n; i++)
                    {
                        cout<<arr[i]<<" ";
                    }
                getch();*/
            }
        case 2:
        {
        char resp = toupper(resp);
        cout << setw(5) << "ID" << " - " << " PRODUCTO" << "  - " << setw(8) << "PdC" << "  - " << setw(5) << "PdV" << " - " << setw(5) << " Existencias" << " - " << setw(5) << "N.R." << " - " << setw(5) << "Estatus"
        << " - " << setw(5) << "Llam. Prov" << endl;
        cout << endl;
           for (int pos = 0; pos < total; pos++)
           if(estatus[pos] == 1){
            if(existencias[pos] <= nr[pos])
                llamprov[pos] = '*';
                    cout << setw(5) << producto[pos] << " - " << " " << id[pos] << " - " << setw(5) << pdc[pos]<< " - " << setw(5) << pdv[pos] << " - "
                    << setw(5) << existencias[pos] << " - " << setw(5) << nr[pos] << " - " << setw(5) << estatus[pos] << " - " << setw(5) << llamprov[pos] << endl;
                    cout << endl;
                    }
                    cout << "Para regresar pulse '*'\n";
                    cin >> resp;
                if (toupper(resp) == '*')
                   return;

        }
        case 3:
        {
            cout << "3. Regresar.\n";
            return;
        }
        default:
            cout << "Opcion Invalida.\n"; cout<<endl;
                break;


        }
    }while(opcion != 3);
}

void corte_de_caja()
{
int posu;

double ingresos; double egresos; double utilidad;

                    cout << endl << endl;
                    cout << "==========================================" << endl;
                    cout << "          Abarrotes 'La Estrella'       \n" << endl;
                    cout << "           R.F.C. ALE 730903 BB9        \n" << endl;
                    cout << "              Corte de Caja            \n" << endl;
                    cout << "                                        \n" << endl;
                    cout << "==========================================" << endl << endl;
time_t tSac = time(NULL); struct tm* tmP = localtime(&tSac); cout << "Hora: " << tmP->tm_hour << ":" << tmP->tm_min << ":"<< tmP->tm_sec << endl; cout << "Fecha: " << tmP->tm_mday << "/" << tmP->tm_mon+1 << "/"<< tmP->tm_year+1900 << endl;

        cout << " VENDEDOR " << " - " << " TOTAL X VENTAS " << endl << endl;
            for (int posu = 0; posu < totalu; posu++){
                if (estatususer[posu] == 1){
                    cout << user[posu] << " vendio:  " << totvend[posu] << endl;
                    ingresos = ingresos + totvend[posu]; egresos = egresos + totalcomp[posu];
                }
            }
            cout << "Ingresos:  $ " << ingresos << endl;
            cout << "Egresos:  $ " << egresos << endl;
                utilidad = ingresos - egresos;
            cout << "Utilidad:  $ " << utilidad << endl;

    cout << "Para salir, presione '*'\n";
    cin >> resp;
   if (resp == '*'){
    return;
    }
}

void admin_de_usuarios()
{
int opcion;
 do
    {
        cout << "==========================================\n";
        cout <<"       Menu Administrador de Usuarios\n";
        cout << "==========================================\n";
        cout << endl;
        cout << "1. Altas.\n";
        cout << "2. Bajas.\n";
        cout << "3. Consultas.\n";
        cout << "4. Modificaciones.\n";
        cout << "5. Mostrar Cuentas de Usuarios.\n";
        cout << "6. Regresar al menu anterior.\n";
        cout << endl;
        cout << setw(20) << "Opcion:  ";
        cin >> opcion; cout << endl;

        switch (opcion){

        case 1:
            altas_user();
            cout << endl;
            break;
        case 2:
            bajas_user();
            cout << endl;
            break;
        case 3:
            consultas_user();
            cout << endl;
            break;
        case 4:
            modificaciones_user();
            cout << endl;
            break;
        case 5:
            inventario_user();
            cout << endl;
            break;
        case 6:
            cout << "Regreso al menu anterior.\n";
            break;
        default:
            cout << "Opcion invalida.\n";
            cout << endl;
        }
    }
    while(opcion != 6);
}
void altas_user()
{

        cout << "==========================================\n";
        cout <<"               Altas de Usuario\n";
        cout << "==========================================\n";
        cout << endl; cout << endl;

    do{
            cout << "Agregar Usuario: \n";
            cin >> user_t; cout << endl;
            int posu = buscar_u(user_t); //POSICION = POS EN USUARIOS

            if (user_t == user[posu]){
                cout << "El usuario ya existe\n";
                if(estatus[posu] == 0){
                    cout << "El usuario se encuentra dado de baja ¿Desea darlo de alta? (s/n):  ";
                    cin >> resp;
                    if (resp == 's')
                    estatususer[posu] = 1;
                    cout << "Modificacion exitosa\n";
                    return;
                }
            }

            else{

            posu = totalu;
            totalu++;

                cout << "Agregar contrasena:  ";
                cin >> contrauser_t; cout << endl;
                cout << "Agregar tipo:  ";
                cin >> usertype_t; cout << endl;
                idu[posu] = posu + 1;  user[posu] = user_t; contrauser[posu] = contrauser_t;  estatususer[posu] = 1; usertype[posu] = usertype_t;

                //totalu + 1;
                cout << "Usuario dado de alta con exito\n";
                cout << "¿Desea agregar otro usuario? (s/n):  ";
                cin >> resp;

                }

   }while(resp == 's');
}
void bajas_user()
{

            cout << "==========================================\n";
            cout <<"              Bajas de Usuarios \n";
            cout << "==========================================\n";
            cout << endl;
        int i = 0;
        char resp = toupper(resp);
        do{
            cout << "¿Cual usuario que desea dar de baja?\n "; cout << endl;
            cin >> user_t;

        int posu = buscar_u(user_t); //POSICION = POS EN USUARIOS
        if (estatususer[posu] > 0){
             cout << setw(5) << "ID" << " - " << " USUARIO" << "  - " << setw(8) << "CONTRSENA" << "  - " << setw(5) << "ESTATUS"
            << " - " << setw(5) << " TIPO" << endl;
            cout << endl;
            cout << idu[posu] << " - " << user[posu] << " - " << contrauser[posu] << " - " << estatususer[posu]<< " - " << usertype[posu] << endl;
            estatususer[posu] = 0;
            cout << " Usuario dado de baja con exito\n";
        }
            else{
            cout << "El usuario ya esta dado de baja, o no se encuentra en el sistema\n";
            }

            cout << "\n¿Desea dar de baja otro usuario? (s/n) \n";
            cout << endl;
            cin >> resp;
        }while(resp == 's');

}
void consultas_user()
{

        cout << "==========================================\n";
        cout <<"            Consultas de Cuentas\n";
        cout << "==========================================\n";
        cout << endl;

    int i = 0;
    char resp = toupper(resp);
    do{
        cout << "¿Cual usuario desea buscar?\n"; cout << endl;
        cin >> user_t;

    int posu = buscar_u(user_t); //POSICION = POS EN USUARIOS
    if (estatususer[posu] > 0){
         cout << setw(5) << "ID" << " - " << " USUARIO" << "  - " << setw(8) << "CONTRSENA" << "  - " << setw(5) << "ESTATUS"
         << " - " << setw(5) << " TIPO" << endl;
        cout << endl;
        cout << idu[posu] << " - " << user[posu] << " - " << contrauser[posu] << " - " << estatususer[posu]<< " - " << usertype[posu]
        << " - " << totvend[posu] << endl;
    }
        else{
        cout << endl << "El usuario no existe o esta dado de baja\n";
        }
    cout << endl << "¿Desea consultar otro usuario? (s/n) \n";
    cout << endl;
    cin >> resp;
    }while(resp == 's');
}
void modificaciones_user()
{
        cout << "==========================================\n";
        cout <<"         Modificaciones de Cuentas \n";
        cout << "==========================================\n";
        cout << endl;

    int opcion;

    char resp = toupper(resp);

       cout << "¿Cual usuario al que desea modificar?\n"; cout << endl;
       cin >> user_t;

        int posu = buscar_u(user_t); //POSICION = POS EN USUARIOS
        if (estatususer[posu] > 0){
             cout << setw(5) << "ID" << " - " << " USUARIO" << "  - " << setw(8) << "CONTRSENA" << "  - " << setw(5) << "ESTATUS"
            << " - " << setw(5) << " TIPO" << endl;
            cout << endl;
            cout << idu[posu] << " - " << user[posu] << " - " << contrauser[posu] << " - " << estatususer[posu]<< " - " << usertype[posu] << endl;
        }
        else{
        cout << endl << "El producto no existe o esta dado de baja\n";
        return;
        }

            cout << endl;
            cout << "1. Nombre de Usuario. \n";
            cout << "2. Contrasena.\n";
            cout << "3. Tipo.\n";
            cout << "4. Cancelar.\n";
            cin >> opcion; cout << endl;

                switch (opcion){
                case 1:
                {
                    cout << "Nuevo Nombre:  ";
                    cin >> user_t; cout << endl;
                    user[posu] = user_t;
                    cout << "Modificacion exitosa\n";
                    return;
                }
                case 2:
                {
                    cout << "Nueva contrasena:  ";
                    cin >> contrauser_t; cout << endl;
                    contrauser[posu] = contrauser_t;
                    cout << "Modificacion exitosa\n";
                    return;
                }
                case 3:
                {
                    cout << "Cambiar tipo (1 = admin, 0 = vendedor):  ";
                    cin >> usertype_t; cout << endl;
                    usertype[posu] = usertype_t;
                    cout << "Modificacion exitosa\n";
                    return;
                }
                case 4:
                {
                    return;
                }
                default:
                    cout << "Opcion Invalida.\n"; cout << endl;
                    break;

                }(opcion != 4);
}

void inventario_user()
{
        cout << "==========================================\n";
        cout <<"                Mostrar Usuarios\n";
        cout << "==========================================\n";
        cout << endl;

        char resp = toupper(resp);
        cout << setw(5) << "ID" << " - " << " USUARIO" << "  - " << setw(8) << "CONTRSENA" << "  - " << setw(5) << "ESTATUS"
         << " - " << setw(5) << " TIPO" << endl;
        cout << endl;
            for (int posu = 0; posu < totalu; posu++)
               if (estatususer[posu] == 1)
                cout << idu[posu] << " - " << user[posu] << " - " << contrauser[posu] << " - " << estatususer[posu]<< " - "
                << usertype[posu] << " - " << totvend[posu] << endl;

            cout << endl;
            cout << "Para regresar pulse '*'\n";
            cin >> resp;
            if (toupper(resp) == '*')
            return;
}

void ventas()
{
    time_t tSac = time(NULL);
    struct tm* tmP = localtime(&tSac);
    cout << "Hora: " << tmP->tm_hour << ":" << tmP->tm_min << ":"<< tmP->tm_sec << endl;
    cout << "Fecha: " << tmP->tm_mday << "/" << tmP->tm_mon+1 << "/"<< tmP->tm_year+1900 << endl << endl;

        cout << "==========================================\n";
        cout <<"            Bienvenid@ a Ventas\n";
        cout << "==========================================\n";
        cout << endl;

//VARIABLES PARA VENTA
int cant; string ticket, salir;
int totalvend = 0;
float subtot[100];
float subtotcomp[100];
//float subtot_cliente[100];
float subtot_cant[100];
string total_productos[100];

//int totalcomp = sizeof(subtotal[i]);
// AUTENTIFICACIÓN CON USUARIO
       int posu;
             do {
                cout << setw(20) << "Por favor, ingrese su usuario:  ";
                cin >> user_t;
                posu = buscar_u (user_t);
                cout << setw(20) << "Ingrese su contrasena:  ";
                cin >> contrauser_t;
                cout << endl;
                    if(usertype[posu] != 0 || estatususer[posu] == 0 || user[posu] != user_t || contrauser[posu] != contrauser_t){
                        cout << "Usuario y/o contrsena incorrecto, intentelo de nuevo\n";
                        cout << endl;
                            return;
                    }
            }while(user[posu] != user_t && contrauser[posu] != contrauser_t && estatususer[posu] != 1 && usertype[posu] != 0);

    int pos;
    do{
// SALIR Y TICKET
        do{
//VALIDACION DE PRODUCTO
            cout << "Ingrese nombre del producto: ";
            cin >> prod_t; cout << endl;
            pos = buscar(prod_t);

            if (estatus[pos] == 1 && existencias[pos] > 0) {
                cout << "¿Cuántos?: ";
                cin >> cant; cout << endl;

                i = totalvend;
                //totalvend ++;

                if (cant <= existencias[pos]) {
                    total_productos[i] = prod_t;
                    subtot_cant[i] = cant;
                    existencias[pos] = existencias[pos] - cant;
                    subtot[i] = pdv[pos] * cant;
                    //subtot[i] + i;
                    subtotcomp[i] = pdc[pos] * cant;
                    //subtotcomp[i] + i;/// compra
                    totalvend ++;
                }

                  else{
                    cout << "Solo se tiene: " << existencias[pos] << "  ¿Efectuar venta? (s/n):  ";
                    cin>>resp; cout << endl;
                        if (resp == 's'){
                        total_productos[i] = prod_t;
                        cant = existencias[pos];
                        existencias[pos] = existencias[pos] - existencias[pos];
                            subtot_cant[i] = cant;
                        subtot[i] = pdv[pos] * cant;  subtot[i] + i;
                        subtotcomp[i] = pdc[pos] * cant; subtotcomp[i] + i;/// compra
                        totalvend ++;
                        }
                  }
            }
            else{
               cout << "No tenemos existencias de ese producto  \n";
            }
                cout << "¿Quiere comprar algo mas? (s/n):  ";
                pu[i] = pdv[pos];
                cin >> resp; cout << endl;

            }while (resp != 'n');

                    cout << endl << endl;
                    cout << "==========================================" << endl;
                    cout << "          Abarrotes 'La Estrella'       \n" << endl;
                    cout << "           R.F.C. ALE 730903 BB9        \n" << endl;
                    cout << "             Ticket de Venta            \n" << endl;
                    cout << "                                          " << endl;
                    cout << "==========================================" << endl;
                    cout << endl;
            cout << setw(20) << "Hora: " << tmP->tm_hour << ":" << tmP->tm_min << ":"<< tmP->tm_sec << endl;
            cout << setw(20) << "Fecha: " << tmP->tm_mday << "/" << tmP->tm_mon+1 << "/"<< tmP->tm_year+1900 << endl << endl;

            cout << "Vendedor/a: " << user[posu] << endl << endl;
            cout << "Producto" << " - " << "Cantidad" << " - " << "Precio Unitario" << " - " << "Subtotal" << endl << endl;

                for (i = 0; i < totalvend; i++)
                if(subtot_cant[i] > 0){
                    cout << setw(8) << total_productos[i] << setw(4) << " - " << setw(4) << subtot_cant[i] << setw(6) <<  " - "
                    << setw(8) << pu[i] << setw(8) << " - " << setw(8) << subtot[i] << endl << endl;

                }
                for (i = 0; i < totalvend; i++){
                        subtotal_vendedor = subtotal_vendedor + subtot[i];
                        subtotal_cliente = subtotal_cliente + subtotcomp[i];
                }
            cout << setw(58) << "Total: " << subtotal_vendedor << endl; cout << setw(60) << "<<Excento de impuestos>>" << endl;

        totvend[posu] = totvend[posu] + subtotal_vendedor;
        cout << totvend[posu];
        totalcomp[posu] = totalcomp[posu] + subtotal_cliente;
        subtotal_vendedor = 0; i = 0; totalvend = 0; subtotal_cliente = 0;
        cout << endl << "Para salir, simplemente escriba 'salir'; otro cliente, escriba 'otro': ";
        cin >> salir; cout << endl;
        if (salir == "salir"){
        cout << "Corte de Caja: $ " << totvend[posu] << endl;
            return;
        }
    }while(salir == "otro");
}
