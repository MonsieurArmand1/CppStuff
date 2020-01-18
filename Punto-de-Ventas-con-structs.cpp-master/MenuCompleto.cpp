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
Version 42:
*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <cstring>

using namespace std;

struct Elemento {
    int id;
    string producto;
    float pc;
    float pv;
    int existencias;
    int nr;
    int sts;
    string resurtir;
};
struct Usuarios {
  string nombre;
  string contra;
  float total_compra;
  float total_venta;
  int tipo;
  int user_status;
};

struct Ventas{
  string nombre_de_producto;
  int cantidad_de_productos;
  float subtotal_de_compra;
  float precio_de_venta;
  float subtotal_de_venta;
  float total_de_venta;
  float total_de_compra;
  int no_de_ventas;
};

Elemento inventario[100] {
    {1, "agua", 10, 11, 12, 8, 1, ""},
    {5, "leche", 10, 11, 23, 5, 1, ""},
    {4, "huevos", 10, 15, 20, 5, 1, ""},
    {3, "pan", 10, 20, 20, 2, 1, ""},
    {2, "refresco", 10, 11, 10, 3, 1, ""}
};

Usuarios admin_usuario[100] {
    {"armando", "admin1", 0, 0, 1, 1},
    {"juan", "v1", 0, 0, 0, 1},
    {"maria", "v2", 0, 0, 0, 1}
};

int total = 5;
int total_usuarios = 3;

struct Status {
    int pos;
    bool st;
};

struct Status_usuario {
    int pos;
    bool st;
};

Status buscar(string prod_t) {
    Status found;
    int i = 0;
    for (i = 0; i < total; i++) {
        if (inventario[i].producto == prod_t) {
            found.pos = i;
            found.st = inventario[i].sts;
            return found;
        }
    }
    found.pos = -1;
    found.st = 0;
    return found;
}

Status_usuario buscar_usuario(string usr_t) {
    Status_usuario found_usuario;
    int i = 0;
    for (i = 0; i < total_usuarios; i++) {
        if (admin_usuario[i].nombre == usr_t) {
            found_usuario.pos = i;
            found_usuario.st = admin_usuario[i].user_status;
            return found_usuario;
        }
    }

    found_usuario.pos = -1;
    found_usuario.st = 0;
    return found_usuario;
}

void admin();
  void admin_de_productos();
  void altas();
  void bajas();
  void mostrar();
  void id();
  void alfabeto();
  void buscar_productos();
  void modificaciones();
  void utilidades();
    void lectura();
    void escritura();
    void escritura_texto();
    void lectura_usuarios_texto();
  void admin_de_usuarios();
  void altas_de_usuarios();
  void bajas_de_usuarios();
  void mostrar_usuarios();
  void buscar_usuarios();
  void modificar_usuarios();
    void escritura_usuarios();
    void lectura_usuarios();
    void escritura_usuarios_texto();
    void lectura_usuarios_texto();
  void venta();

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
void admin() {
fflush(stdin);
Usuarios usuarios_temporal;
int opcion = 0; int i = 0; string contra_temp, usr_t;
usr_t.clear(); contra_temp.clear();

      do {
        cout << setw(20) << "Por favor, ingrese su usuario:  ";
        cin >> usr_t;
        Status_usuario found_usuario_local = buscar_usuario(usr_t);
        i = found_usuario_local.pos;
        cout << setw(20) << "Ingrese su contrasena:  ";
        cin >> contra_temp;
        cout << endl;
        if (admin_usuario[i].tipo != 1 || admin_usuario[i].user_status != 1 || admin_usuario[i].contra != contra_temp || admin_usuario[i].nombre != usr_t){
          cout << "*Usuario y/o contrsena incorrecto, intentelo de nuevo*\n" << endl;
          return;
        } else {
          break;
        }
      } while (admin_usuario[i].nombre != usr_t && admin_usuario[i].user_status != 1 && admin_usuario[i].tipo != 1 && admin_usuario[i].contra != contra_temp);
do {

cout << "===================================================================" << endl;
cout << "           ¡Bienvenid@ al Menu Administrador!" << endl;
cout << "===================================================================" << endl;
cout << endl << endl;
cout << "1. Productos" << endl;
cout << "2. Cuentas de Usuarios" << endl;
cout << "3. Utilidades." << endl;
cout << "4. Regresar al Menu Principal.\n" << endl;
cout << setw(15) << "Opcion:  ";
cin >> opcion;
cout << endl;

        switch (opcion) {
        case 1:
            admin_de_productos();
            cout << endl;
            break;
        case 2:
            admin_de_usuarios();
            cout << endl;
            break;
        case 3:
            utilidades();
            cout << endl;
            break;
        case 4:
            cout << "Regresando al Menu principal..." << endl;
            break;
        default:
            cout <<" -Opcion invalida, intente de nuevo-\n" << endl;
        }
        escritura();
        escritura_texto();
        escritura_usuarios();
        escritura_usuarios_texto();
    } while (opcion != 4);
}
void admin_de_productos() {
fflush(stdin);
int opcion = 0;
do {
cout << "===================================================================" << endl;
cout << "                  ADMINISTRACION DE PRODUCTOS   " << endl;
cout << "===================================================================" << endl;
cout << endl << endl;
cout <<  "1. Altas." << endl;
cout <<  "2. Bajas." << endl;
cout <<  "3. Mostrar." << endl;
cout <<  "4. Consultar Producto." << endl;
cout <<  "5. Modificaciones." << endl;
cout <<  "6. Regresar al Menu Administrador.\n" << endl;
cout << setw(15) << "Opcion:  ";
cin >> opcion;
cout << endl << endl;
        switch (opcion) {
        case 1:
            altas();
            cout << endl;
            break;
        case 2:
            bajas();
            cout << endl;
            break;
        case 3:
            mostrar();
            cout << endl;
            break;
        case 4:
            buscar_productos();
            cout << endl;
            break;
        case 5:
            modificaciones();
            cout << endl;
            break;
        case 6:
            cout << "Regresando al Menu Administrador..." << endl;
            cout << endl;
            break;
        default:
            cout << "-Opcion invalida, intente de nuevo-\n" << endl;
        }
    } while (opcion != 6);
}
void altas() {
fflush(stdin);
int id_t, nr_t, existencias_t;
float pc_t, pv_t;
int i  = 0;
string prod_t;
char pro[20];
char resp;
cout << "===================================================================" << endl;
cout << "                    Altas de Productos" << endl;
cout << "===================================================================" << endl;
cout << endl << endl;
    do {
        fflush(stdin);
        cout << "Agregar Producto:  ";
        prod_t.clear();
        cin >> prod_t;
        cout << endl;
        if (prod_t == "*") {
            return;
        }
        Status found_local = buscar(prod_t);
        i = found_local.pos;
        if (i >= 0 && inventario[i].producto == prod_t) {
            cout << "***upss... El producto ya existe***" << endl;
            if (inventario[i].sts == 0) {
                cout << "¿Desea Darlo de alta? (s/n): ";
                cin >> resp;
                cout << endl;
                if (resp == 's')
                    inventario[i].sts = 1;
                return;
            }
        } else {
            i = total++;
            do {
                cout << "Agregar Precio de Compra:  ";
                cin >> pc_t;
                cout << endl;
                cout << "Agregar Precio de Venta:  ";
                cin >> pv_t;
                cout << endl;
                if (pv_t <= pc_t)
                  cout << "El precio de venta no puede ser menor o igual al precio de venta\n" << endl;
            } while (pc_t > pv_t);

            inventario[i].id = i + 1;
            inventario[i].producto = prod_t;
            inventario[i].pc = pc_t;
            inventario[i].pv = pv_t;

            do {
                cout << "Agregar Existencias:  ";
                cin >> existencias_t;
                cout << endl;
                cout << "Agregar nivel de reorden:  ";
                cin >> nr_t;
                cout << endl;
                inventario[i].sts = 1;
                cout << endl;
                if (existencias_t <= nr_t) {
                  cout << "Las existenacias no pueden ser menores o igual al nivel de reorden\n" << endl;
                }
            } while (existencias_t <= nr_t);
            inventario[i].existencias = existencias_t;
            inventario[i].nr = nr_t;
            total = total++;
        }
        prod_t.clear();
    } while (prod_t != "*");
}
void bajas() {
fflush(stdin);
string prod_t;
int i = 0;
cout << "===================================================================" << endl;
cout << "                        Bajas de Productos" << endl;
cout << "===================================================================" << endl;
    cout << endl << endl;
    do {
        cout << "Producto que desea dar de baja:  ";
        cin >> prod_t;
        cout << endl;
        if (prod_t == "*") {
            return;
        }
        Status found_local = buscar(prod_t);
        i = found_local.pos;
        if (i < 0  || inventario[i].sts == 0) {
            cout << "***El producto, ya ha sido dado de baja o no existe***"
            << endl;
        }
        else{
            inventario[i].sts = 0;
        }
        prod_t.clear();
    } while (prod_t != "*");
}
void mostrar() {
fflush(stdin);
int opcion = 0;
cout << "===================================================================" << endl;
cout << "                       Mostrar Productos" << endl;
cout << "===================================================================" << endl;
cout << endl << endl;
    do {
        cout <<  "1. Por ID." << endl;
        cout <<  "2. Por Alfabeto." << endl;
        cout <<  "3. Regresar.\n" << endl;
        cout << setw(15) << "Opcion:  ";
        cin >> opcion;
        cout << endl << endl;
        switch (opcion) {
        case 1:
            id();
            cout << endl;
            break;
        case 2:
            alfabeto();
            cout << endl;
            break;
        case 3:
            cout << "Regresando a Menu Administrador...\n" << endl;
            return;
        default:
            cout << " -Opcion invalida, intente de nuevo-\n" << endl;
        }
    } while (opcion != 3);
}
void id() {
fflush(stdin);
Elemento datos;
int i = 0, j = 0;
cout << "===================================================================" << endl;
cout << "                        Mostrando por ID" << endl;
cout << "===================================================================\n" << endl;
cout << setw(6) << "ID" << setw(11)<< "Producto" << setw(9) << "PdC" << setw(5)
<< "PdV" << setw(15) << "Existencias" << setw(6) << "NdR" << setw(15) << "Resurtir" << endl << endl << endl;
    for (i = 0; i < total; i++) {
        for (j = 0; j < (total-1); j++) {
          if (inventario[j].id > inventario[j+1].id) {
                datos = inventario[j];
                inventario[j] = inventario[j+1];
                inventario[j+1] = datos;
            }
        }
      }
for (i = 0; i < total; i++) {
  if (inventario[i].sts == 1) {
      if (inventario[i].existencias < inventario[i].nr) {
          inventario[i].resurtir = "*";
      }
  cout << setw(5) << inventario[i].id << setw(10) << inventario[i].producto << setw(10) << inventario[i].pc << setw(5)
  << inventario[i].pv << setw(10) << inventario[i].existencias << setw(10) << inventario[i].nr
  << setw(13) << inventario[i].resurtir << endl;
  }
}
}
void alfabeto() {
fflush(stdin);
int j = 0, i = 0;
Elemento datos;
cout << "===================================================================" << endl;
cout << "                Mostrando por orden Alfabetico" << endl;
cout << "===================================================================" << endl;
cout << endl << endl << setw(11) << "Producto" << setw(6) << "ID" << setw(9) << "PdC" << setw(5)
<< "PdV" << setw(15) << "Existencias" << setw(6) << "NdR" << setw(15) << "Resurtir" << endl << endl << endl;

    for (i = 0; i < total; i++) {
        for (j = 1; j < (total-1); j++) {
            if (inventario[j].producto.compare(inventario[j+1].producto) > 0) {
                datos = inventario[j];
                inventario[j] = inventario[j+1];
                inventario[j+1] = datos;

             }
          }
        }
        for (i = 0; i < total; i++) {
          if (inventario[i].sts == 1) {
              if (inventario[i].existencias < inventario[i].nr) {
                  inventario[i].resurtir = "*";
              }
          cout << setw(5) << inventario[i].id << setw(10) << inventario[i].producto << setw(10) << inventario[i].pc << setw(5)
          << inventario[i].pv << setw(10) << inventario[i].existencias << setw(10) << inventario[i].nr
          << setw(13) << inventario[i].resurtir << endl;
          }
        }
}
void buscar_productos() {
fflush(stdin);
string prod_t = "";
int i = 0;
cout << "===================================================================" << endl;
cout << "                     Consulta de Productos" << endl;
cout << "===================================================================" << endl;
cout << endl << endl;
    do
    {
        cout << "Producto a buscar:  ";
        cin >> prod_t;
        cout << endl;
        if (prod_t == "*")
            return;
        Status found_local = buscar(prod_t);
        i = found_local.pos;
        if (inventario[i].producto == prod_t && inventario[i].sts == 1) {
            cout << setw(6) << "ID" << setw(11)<< "Producto" << setw(9) << "PdC" << setw(5)
            << "PdV" << setw(15) << "Existencias" << setw(6) << "NdR" << setw(15) << "Resurtir" << endl << endl;
                if (inventario[i].existencias < inventario[i].nr) {
                    inventario[i].resurtir = "*";
                }
                cout << setw(5) << inventario[i].id << setw(10) << inventario[i].producto << setw(10) << inventario[i].pc << setw(5)
                     << inventario[i].pv << setw(10) << inventario[i].existencias << setw(10) << inventario[i].nr << setw(13) << inventario[i].resurtir
                     << endl << endl;
        }
        else
            cout << "***El producto que está buscando está dado de baja o no existe***\n" << endl;
    } while (prod_t != "*");
    //prod_t.clear();
}
void modificaciones() {
fflush(stdin);
string prod_t;
float pv_t, pc_t;
int id_t, nr_t, existencias_t;
int opcion = 0, i = 0;
cout << "===================================================================" << endl;
cout << "                 Modificaciones de Productos" << endl;
cout << "===================================================================" << endl;
    cout << endl;
    cout << endl;
    do {
        cout << "¿Que producto desea modificar?: ";
        cin >> prod_t;
        cout << endl;
        if (prod_t == "*") {
            return;
        }
        Status found_local = buscar(prod_t);
        i = found_local.pos;
        if(found_local.st == 0) {
            cout << "El producto se encuentra dado de baja, debe darlo de alta para modificarlo\n" << endl;
        }
        if (i >= 0 && inventario[i].producto == prod_t) {

            cout << setw(6) << "ID" << setw(11)<< "Producto" << setw(9) << "PdC" << setw(5)
            << "PdV" << setw(15) << "Existencias" << setw(6) << "NdR" << setw(15) << "Resurtir" << endl << endl;

        if(inventario[i].sts == 1) {
          if (inventario[i].existencias < inventario[i].nr) {
            inventario[i].resurtir = "*";
          }
        cout << setw(5) << inventario[i].id << setw(10) << inventario[i].producto << setw(10) << inventario[i].pc << setw(5)
        << inventario[i].pv << setw(10) << inventario[i].existencias << setw(10) << inventario[i].nr << setw(13) << inventario[i].resurtir
        << endl << endl;
        cout << "1. Precio de Compra" << endl;
        cout << "2. Precio de Venta" << endl;
        cout << "3. Existencias" << endl;
        cout << "4. Nivel de Reorden" << endl;
        cout << "5. Regresar" << endl;
        cout << setw(15) << "Opcion:  ";
        cin >> opcion;
        cout << endl << endl;
        switch (opcion) {
        case 1:
          do {
                cout << "Nuevo Precio de Compra:  ";
                cin >> pc_t;
                cout << endl;
                if(pc_t > inventario[i].pv)
                    cout << "El precio de compra no puede ser mayor o igual al precio de venta\n" << endl;
            } while (inventario[i].pv <= pc_t);
          inventario[i].pc = pc_t;
          return;
        case 2:
            do {
              cout << "Nuevo Precio de Venta:  ";
              cin >> pv_t;
              cout << endl;
              if (pv_t <= inventario[i].pc) {
                cout << "El precio de venta no puede ser menor o igual al precio de compra\n" << endl;
              }
            } while (pv_t <= inventario[i].pc);
            inventario[i].pv = pv_t;
            return;
        case 3:
            do {
              cout << "Agregar Existencias:  ";
              cin >> existencias_t;
              cout << endl;
              if (existencias_t <= inventario[i].nr)
                cout << "Las existenacias no pueden ser menores o iguales al nivel de reorden\n" << endl;
            } while (existencias_t <= inventario[i].nr);
              inventario[i].existencias = existencias_t;
        case 4:
             do {
              cout << "Nuevo Nivel de Reorden:  ";
              cin >> nr_t;
              cout << endl;
                if (inventario[i].existencias < nr_t)
                      cout << "El nivel de reorden no puede ser mayor a las existencias\n" << endl;
            } while (inventario[i].existencias <= nr_t);
                inventario[i].nr = nr_t;
                return;
            case 5:
              cout << "... Regresando a Administracion de Productos\n" << endl;
                return;
            default:
              cout << "Opcion invalida, intente de nuevo\n" << endl;
            }
          }
        }
        else {
            cout << "***El producto a modificar no existe***\n" << endl;
        }
    } while (prod_t != "*");
}
void lectura() {
      ifstream archivo("inventario.bin", ios::in | ios::binary);
      fflush(stdin);
      int i = 0;
      int id_d;
      char producto_o[20];
      //  char cstr;
      float pc_c, pv_v;
      int existencias_s, n_r, st_t;
    if (!archivo) {
        cout << "Error en la apertura del archivo de lectura\n";
    } else {
      while (!archivo.eof()) {
        archivo.read(reinterpret_cast<char *> (&id_d), sizeof (id_d));
        archivo.read(producto_o, 20);
        archivo.read(reinterpret_cast<char *> (&pc_c), sizeof (pc_c));
        archivo.read(reinterpret_cast<char *> (&pv_v), sizeof (pv_v));
        archivo.read(reinterpret_cast<char *> (&existencias_s), sizeof (existencias_s));
        archivo.read(reinterpret_cast<char *> (&n_r), sizeof (n_r));
        archivo.read(reinterpret_cast<char *> (&st_t), sizeof (st_t));

        inventario[i].id = id_d;
        inventario[i].producto = producto_o;
        inventario[i].pc = pc_c;
        inventario[i].pv = pv_v;
        inventario[i].existencias = existencias_s;
        inventario[i].nr = n_r;
        inventario[i].sts = st_t;
        total = i;
        i++;
      }
    }
       archivo.close();
}
void escritura() {
      ofstream archivo("inventario.bin", ios::out | ios::binary);
      fflush(stdin);
      int i = 0;
      int id_d;
      char producto_o[20];
      float pc_c, pv_v;
      int existencias_s, n_r, st_t;

    if (!archivo) {
        cout << "Error en la apertura del archivo de escritura\n";
    } else {
      for (i = 0; i < total; i++) {
        id_d = inventario[i].id;
        strcpy(producto_o,inventario[i].producto.c_str());
        /*char cstr[producto_o.size() + 1];
        producto_o.copy(cstr, producto_o.size() + 1);
        cstr[producto_o.size()] = '\0';*/
        pc_c = inventario[i].pc;
        pv_v = inventario[i].pv;
        existencias_s = inventario[i].existencias;
        n_r = inventario[i].nr;
        st_t = inventario[i].sts;

        archivo.write(reinterpret_cast<char* >(&id_d), sizeof (id_d));
        archivo.write(producto_o, 20);
        archivo.write(reinterpret_cast<char* >(&pc_c), sizeof (pc_c));
        archivo.write(reinterpret_cast<char* >(&pv_v), sizeof (pv_v));
        archivo.write(reinterpret_cast<char* >(&existencias_s), sizeof (existencias_s));
        archivo.write(reinterpret_cast<char* >(&n_r), sizeof (n_r));
        archivo.write(reinterpret_cast<char* >(&st_t), sizeof (st_t));
      }
    }
       archivo.close();
}
void escritura_texto() {
      ofstream archivo_texto("inventario_texto.txt", ios::out | ios::binary);
      fflush(stdin);
      int i = 0;
      int id_d, total_temp;
      string producto_o;
      float pc_c, pv_v;
      int existencias_s, n_r, st_t;

    if (!archivo_texto)
        cout << "Error en la apertura del archivo de escritura de texto\n";
    else {
      total_temp = total;
      for (i = 0; i < total; i++) {
            id_d = inventario[i].id;
            producto_o = inventario[i].producto;
            pc_c = inventario[i].pc;
            pv_v = inventario[i].pv;
            existencias_s = inventario[i].existencias;
            n_r = inventario[i].nr;
            st_t = inventario[i].sts;

archivo_texto << total_temp << " " << id_d << " " << producto_o << " " << pc_c
<< " " << pv_v << " " << existencias_s << " " << n_r << " " << st_t << " ";
        }
    }
       archivo_texto.close();
}
void lectura_texto() { //  ARCHIVOS DE TEXTO
      ifstream archivo_texto("inventario_texto.txt", ios::in | ios::binary);
      fflush(stdin);
      int i = 0;
      int id_d, total_temp;
      string producto_o, nombre_e, contra_a;
      float pc_c, pv_v, total_compra_a, total_venta_a;
      int existencias_s, n_r, st_t, tipo_o, user_estatus_s;

    if (!archivo_texto)
        cout << "Error en la apertura del archivo de lectura_texo\n";
    else {
archivo_texto >> total_temp >> id_d >> producto_o >> pc_c >> pv_v >> existencias_s
>> n_r >> st_t;

    total = total_temp;
      for (i = 0; i < total ; i++) {
            inventario[i].id = id_d;
            inventario[i].producto = producto_o;
            inventario[i].pc = pc_c;
            inventario[i].pv = pv_v;
            inventario[i].existencias = existencias_s;
            inventario[i].nr = n_r;
            inventario[i].sts = st_t;

archivo_texto >> total_temp >> id_d >> producto_o >> pc_c
>> pv_v >> existencias_s >> n_r >> st_t;
      }
    }
       archivo_texto.close();
}
void utilidades() {
float ingreso = 0, egreso = 0, utilidad = 0;
cout << "===================================================================" << endl;
cout << "                              UTILIDADES" << endl;
cout << "===================================================================" << endl;
    cout << endl;
    cout << endl;
                for (int posu = 0; posu < total_usuarios; posu++) {
                    ingreso = ingreso + admin_usuario[posu].total_compra;
                    egreso = egreso + admin_usuario[posu].total_venta;
                }
                cout << "Ingresos:  $ " << ingreso << endl;
                cout << "Egresos:  $ " << egreso << endl;
                utilidad = egreso - ingreso;
                cout << "Utilidad de la venta:  $ " << utilidad << endl;
}
void admin_de_usuarios() {
fflush(stdin);
int opcion = 0;
cout << "===================================================================" << endl;
cout << "                   ADMINISTRACION DE CUENTAS" << endl;
cout << "===================================================================" << endl;
cout << endl << endl;
    do {
        cout <<  "1. Altas." << endl;
        cout <<  "2. Bajas." << endl;
        cout <<  "3. Mostrar Usuarios." << endl;
        cout <<  "4. Consultas." << endl;
        cout <<  "5. Modificaciones." << endl;
        cout <<  "6. Regresar al Menu Administrador.\n" << endl;
        cout << setw(15) << "Opcion:  ";
        cin >> opcion;
        cout << endl << endl;
        switch (opcion) {
        case 1:
            altas_de_usuarios();
            cout << endl;
            break;
        case 2:
            bajas_de_usuarios();
            cout << endl;
            break;
        case 3:
            mostrar_usuarios();
            cout << endl;
            break;
        case 4:
            buscar_usuarios();
            cout << endl;
            break;
        case 5:
            modificar_usuarios();
            cout << endl;
            break;
        case 6:
            cout << "Regresando al Menu Administrador..." << endl;
            break;
        default:
            cout <<" -Opcion invalida, intente de nuevo-" << endl << endl;
        }
    } while (opcion != 6);
}
void altas_de_usuarios() {
fflush(stdin);
Usuarios usuarios_temporal;
char resp; int i = 0;
string nom_temp; string contra_temp; string usr_t;
bool tipo_usuario;

cout << "===================================================================" << endl;
cout << "                       Altas de Usuarios" << endl;
cout << "===================================================================" << endl;
cout << endl << endl;
    do {
        cout << "Agregar Usuario:  ";
        cin >> usr_t;
        cout << endl;
        if (usr_t == "*") {
            return;
        }
        Status_usuario found_usuario_local = buscar_usuario(usr_t);
        i = found_usuario_local.pos;
        if (admin_usuario[i].nombre == usr_t) {
            cout << "***upss... El usuario ya existe***" << endl;
            if (admin_usuario[i].user_status == 0) {
                cout << "¿Desea Darlo de alta? (s/n): ";
                cin >> resp;
                cout << endl;
                if (resp == 's')
                    admin_usuario[i].user_status = 1;
                return;
            }
        } else {
            i = total_usuarios++;
            cout << "Agregar Contrasena:  ";
            cin >> contra_temp;
            cout << endl;
            cout << "Agregar Tipo (1 = Administrador, 0 = Vendedor):  ";
            cin >> tipo_usuario;
            cout << endl;

            admin_usuario[i].nombre = usr_t;
            admin_usuario[i].contra = contra_temp;
            admin_usuario[i].total_compra = 0;
            admin_usuario[i].total_venta = 0;
            admin_usuario[i].tipo = tipo_usuario;
            admin_usuario[i].user_status = 1;
            total_usuarios = total_usuarios++;
        }
        usr_t.clear();
    } while (usr_t != "*");
}
void bajas_de_usuarios() {
fflush(stdin);
int i = 0; string usr_t;
cout << "===================================================================" << endl;
cout << "                      Bajas de Usuarios" << endl;
cout << "===================================================================" << endl;
    cout << endl << endl;
    do {
        cout << "Usuario que desea dar de baja:  ";
        cin >> usr_t;
        cout << endl;
        if (usr_t == "*") {
          return;
        }
        Status_usuario found_usuario = buscar_usuario(usr_t);
        i = found_usuario.pos;
        if (admin_usuario[i].user_status == 0) {
            cout << "El usuario, ya ha sido dado de baja o no existe" << endl;
        }
        else {
            admin_usuario[i].user_status = 0;
        }
        usr_t.clear();
    } while (usr_t != "*");
}
void mostrar_usuarios() {
fflush(stdin);
int i = 0;
cout << "===================================================================" << endl;
cout << "            		    Mostrar Usuarios" << endl;
cout << "===================================================================\n" << endl << endl;
cout << setw(10) << "Nombre:" << setw(17) << "Contrasena:" << setw(13)<< "Ventas:" << setw(10) << "Tipo:" << endl << endl;

  for (i = 0; i < total_usuarios; i++) {
    if (admin_usuario[i].user_status == 1) {
      cout << setw(10) << admin_usuario[i].nombre << setw(15) << admin_usuario[i].contra << setw(12)
      << admin_usuario[i].total_venta << setw(11) << admin_usuario[i].tipo << endl;
    }
  }
    cout << endl;
}
void buscar_usuarios() {
fflush(stdin);
int i = 0; string usr_t;
cout << "===================================================================" << endl;
cout << "                    Consulta de Usuarios" << endl;
cout << "===================================================================" << endl;
cout << endl << endl;
    do {
        cout << "Usuario a buscar:  ";
        cin >> usr_t;
        cout << endl;
        if (usr_t == "*")
            return;
        Status_usuario found_usuario_local = buscar_usuario(usr_t);
        i = found_usuario_local.pos;
        if (i == -1) {
            cout << "***El usuario que esta buscando, no existe***\n" << endl;
        }
        if(admin_usuario[i].nombre == usr_t) {
            cout << setw(10) << "Nombre:" << setw(17) << "Contrasena:" << setw(13)<< "Ventas:" << setw(10) << "Tipo:" << endl << endl;
            if (admin_usuario[i].user_status == 1) {
                cout << setw(10) << admin_usuario[i].nombre << setw(15) << admin_usuario[i].contra << setw(12)
                << admin_usuario[i].total_venta << setw(11) << admin_usuario[i].tipo << endl << endl << endl;
            }
            else {
            cout << "***El usuario que está buscando está dado de baja***" << endl << endl;
            }

        }
    } while (usr_t != "*");
}
void modificar_usuarios() {
fflush(stdin);
int opcion = 0, i = 0;
string usr_t = "";
Usuarios usuario_temporal;
cout << "===================================================================" << endl;
cout << "                 Modificaciones de Usuarios" << endl;
cout << "===================================================================" << endl;
cout << endl << endl;
do {
        cout << "¿Que usuario desea modificar?: ";
        cin >> usr_t;
        cout << endl;
        if (usr_t == "*")
            return;
        Status_usuario found_usuario_local = buscar_usuario(usr_t);
        i = found_usuario_local.pos;
        if (found_usuario_local.st == 0) {
            cout << "El usuario se encuentra dado de baja, debe darlo de alta para modificarlo\n" << endl;
        }
        if (admin_usuario[i].nombre == usr_t) {

        cout << setw(10) << "Nombre:" << setw(17) << "Contrasena:" << setw(13)<< "Ventas:" << setw(10) << "Tipo:" << endl << endl;
        cout << setw(10) << admin_usuario[i].nombre << setw(15) << admin_usuario[i].contra << setw(12)
        << admin_usuario[i].total_venta << setw(11) << admin_usuario[i].tipo << endl << endl;

            cout << "1. Nombre" << endl;
            cout << "2. Contrasena" << endl;
            cout << "3. Tipo" << endl;
            cout << "4. Regresar\n" << endl;
            cout << setw(15) << "Opcion:  ";
            cin >> opcion;
            cout << endl << endl;
            switch (opcion) {
            case 1:
                do {
                    cout << "Nuevo Nombre:  ";
                    cin >> usr_t;
                    cout << endl;
                    if(usr_t == admin_usuario[i].nombre)
                        cout << "El nombre no puede ser igual al anterior\n" << endl;
                }
                while(admin_usuario[i].nombre == usr_t);
                admin_usuario[i].nombre = usr_t;
                break;
            case 2:
                do {
                    cout << "Nueva Contrasena:  ";
                    cin >> usuario_temporal.contra;
                    cout << endl;
                    if (usuario_temporal.contra == admin_usuario[i].contra)
                        cout << "La contrasena no puede ser igual al anterior\n" << endl;
                } while (admin_usuario[i].contra == usuario_temporal.contra);
                admin_usuario[i].contra = usuario_temporal.contra;
                break;
            case 3:

                if (admin_usuario[i].tipo == 1) {
                    cout << "El tipo ha sido cambiado a Vendedor" << endl;
                    admin_usuario[i].tipo = 0;
                } else {
                    cout << "El tipo ha sido cambiado a Administrador" << endl;
                    admin_usuario[i].tipo = 1;
                }
                break;

            case 4:
                return;

            default:
                cout << "***Opcion invalida, intente de nuevo***" << endl;
            }
        } else {
            cout << "***El usuario a modificar no existe***\n" << endl;
            usr_t == "*";
        }
  } while (usr_t != "*");
}
void lectura_usuarios_texto() {
  ifstream archivo_usuarios_texto("cuentas_texto.txt", ios::in);
  fflush(stdin);
  int i;
  int total_usuarios_temp;
  string  nombre_e, contra_a;
  float total_compra_a, total_venta_a;
  int tipo_o, user_estatus_s;
  if (!archivo_usuarios_texto) {
      cout << "Error en la apertura del archivo de lectura_usuarios" << endl;
  } else {
        while (!archivo_usuarios_texto) {
              total_usuarios = total_usuarios_temp;
              admin_usuario[i].nombre = nombre_e;
              admin_usuario[i].contra = contra_a;
              admin_usuario[i].total_compra = total_compra_a;
              admin_usuario[i].total_venta; total_venta_a;
              admin_usuario[i].tipo = tipo_o;
              admin_usuario[i].user_status =  user_estatus_s;

        archivo_usuarios_texto >> total_usuarios >> nombre_e >> contra_a >>
        total_compra_a >> total_venta_a >> tipo_o >> user_estatus_s;
        }
    }
       archivo_usuarios_texto.close();
}
void escritura_usuarios_texto() {
  ofstream archivo_usuarios_texto("cuentas_texto.txt", ios::out);
  fflush(stdin);
  int i;
  int total_usuarios_temp;
  string nombre_e, contra_a;
  float total_compra_a, total_venta_a;
  int tipo_o, user_estatus_s;

  if (!archivo_usuarios_texto) {
      cout << "Error en la apertura del archivo de escritura_usuarios_texo\n";
  } else {
        for (i = 0; i < total_usuarios; i++) {
              total_usuarios_temp = total_usuarios;
              nombre_e = admin_usuario[i].nombre;
              contra_a = admin_usuario[i].contra;
              total_compra_a = admin_usuario[i].total_compra;
              total_venta_a = admin_usuario[i].total_venta;
              tipo_o = admin_usuario[i].tipo;
              user_estatus_s = admin_usuario[i].user_status;

              archivo_usuarios_texto << total_usuarios_temp << nombre_e << " "
              << contra_a << " " << total_compra_a << " " << total_venta_a <<
              " " << tipo_o << " " << user_estatus_s << " ";
          }
      }
  archivo_usuarios_texto.close();
}
void lectura_usuarios() {
  // ifstream archivo_usuarios("cuentas.bin", ios::in | ios::binary);
  ifstream archivo_usuarios;
  archivo_usuarios.open("cuentas.dat", ios::in | ios::binary);
  char nombre_e[20];
  char contra_a[20];
  float total_compra_a, total_venta_a;
  int tipo_o, user_estatus_s;
    if (!archivo_usuarios) {
      cout << "Archivo lectura_usuarios inexistente\n";
  } else {
    int i = 0;
      while (!archivo_usuarios.eof()) {

        archivo_usuarios.read(nombre_e, 20);
        archivo_usuarios.read(contra_a, 20);
        archivo_usuarios.read(reinterpret_cast<char *> (&total_compra_a), sizeof (total_compra_a));
        archivo_usuarios.read(reinterpret_cast<char *> (&total_venta_a), sizeof (total_venta_a));
        archivo_usuarios.read(reinterpret_cast<char *> (&tipo_o), sizeof (tipo_o));
        archivo_usuarios.read(reinterpret_cast<char *> (&user_estatus_s), sizeof (user_estatus_s));

        admin_usuario[i].nombre = nombre_e;
        admin_usuario[i].contra = contra_a;
        admin_usuario[i].total_compra = total_compra_a;
        admin_usuario[i].total_venta; total_venta_a;
        admin_usuario[i].tipo = tipo_o;
        admin_usuario[i].user_status =  user_estatus_s;
        total_usuarios = i;
        i++;
      }
    }
  archivo_usuarios.close();
}
void escritura_usuarios() {
  ofstream archivo_usuarios;
  archivo_usuarios.open("cuentas.dat", ios::out | ios::binary); // ("cuentas.bin", ios::out | ios::binary);
  int i = 0, total_usuarios_temp = 0;
  char nombre_e[20];
  char contra_a[20];
  float total_compra_a = 0, total_venta_a = 0;
  int tipo_o = 0, user_estatus_s = 0;

      if (!archivo_usuarios) {
      cout <<  "Archivo escritura_usuarios inexistente\n";
      } else {
        for (i = 0; i < total_usuarios ; i++) {
          memset(nombre_e, 0, sizeof(nombre_e));
          memset(contra_a, 0, sizeof(contra_a));
          strcpy(nombre_e,admin_usuario[i].nombre.c_str());
          strcpy(contra_a, admin_usuario[i].contra.c_str());
          total_compra_a = admin_usuario[i].total_compra;
          total_venta_a = admin_usuario[i].total_venta;
          tipo_o = admin_usuario[i].tipo;
          user_estatus_s = admin_usuario[i].user_status;

          archivo_usuarios.write(nombre_e, 20);
          archivo_usuarios.write(contra_a, 20);
          archivo_usuarios.write(reinterpret_cast<char* >(&total_compra_a), sizeof (total_compra_a));
          archivo_usuarios.write(reinterpret_cast<char* >(&total_venta_a), sizeof (total_venta_a));
          archivo_usuarios.write(reinterpret_cast<char* >(&tipo_o), sizeof (tipo_o));
          archivo_usuarios.write(reinterpret_cast<char* >(&user_estatus_s), sizeof (user_estatus_s));
        }
     }
    archivo_usuarios.close();
  }
  void venta() {
  Ventas recibo[100];
  string usr_t, contra_temp;
  int posu, no_de_venta = 1, i = 0;
  float iva = 0, corte_de_caja = 0, sub = 0;
  char resp;
  string prod_t;
  time_t tSac = time(NULL);
  struct tm* tmP = localtime(&tSac);
  cout << "===================================================================" << endl;
  cout << setw(40) << "¡ BIENVENID@ !" << endl;
  cout << "===================================================================" << endl;
  cout << endl << endl;
  usr_t.clear(); contra_temp.clear();
        do {
          cout << setw(20) << "Por favor, ingrese su usuario:  ";
          cin >> usr_t;
          Status_usuario found_usuario_local = buscar_usuario(usr_t);
          posu = found_usuario_local.pos;
          cout << setw(20) << "Ingrese su contrasena:  ";
          cin >> contra_temp;
          cout << endl;
          if (admin_usuario[posu].tipo != 0 || admin_usuario[posu].user_status != 1 || admin_usuario[posu].contra != contra_temp || admin_usuario[posu].nombre != usr_t){
            cout << "*Usuario y/o contrsena incorrecto, intentelo de nuevo*\n" << endl;
            return;
          } else {
            break;
          }
        } while (admin_usuario[posu].nombre != usr_t && admin_usuario[posu].user_status != 1 && admin_usuario[posu].tipo != 0 && admin_usuario[posu].contra != contra_temp);
  int j = 0;
    do {
      do {
          cout << "Producto: ";
          cin >> prod_t;
          if (prod_t == "**") {
              cout << endl << endl;
              cout << "Corte de Caja: $ ";
              cout << corte_de_caja << endl << endl;
              corte_de_caja = 0;
              return;
          }
          Status found_local = buscar(prod_t);
          j = found_local.pos;
          if (found_local.st == 1 && inventario[j].existencias > 0) {
            cout << "Cantidad: ";
            cin >> recibo[i].cantidad_de_productos;
            cout << endl;

            if (recibo[i].cantidad_de_productos > inventario[j].existencias) {
              cout << "Solo se tienen: " << inventario[j].existencias  <<
              "  ¿Efectuar venta? (s/n):  ";
              cin >> resp;
              cout << endl;
              if (resp == 's') {
                recibo[i].cantidad_de_productos = 0;
                recibo[i].cantidad_de_productos = inventario[j].existencias;
                inventario[j].existencias = 0;
                recibo[i].nombre_de_producto = prod_t;
                recibo[i].precio_de_venta = inventario[j].pv;

                recibo[i].subtotal_de_compra = inventario[j].pc * recibo[i].cantidad_de_productos;
                recibo[0].total_de_compra = recibo[0].total_de_compra + recibo[i].subtotal_de_compra;

                recibo[i].subtotal_de_venta = inventario[j].pv * recibo[i].cantidad_de_productos;
                recibo[0].total_de_venta = recibo[0].total_de_venta + recibo[i].subtotal_de_venta;

                i++;
                recibo[0].no_de_ventas = recibo[0].no_de_ventas + 1;
              }
            } else if  (recibo[i].cantidad_de_productos <= inventario[j].existencias) {
              inventario[j].existencias = inventario[j].existencias - recibo[i].cantidad_de_productos;
              recibo[i].nombre_de_producto = prod_t;
              recibo[i].precio_de_venta = inventario[i].pv;

              recibo[i].subtotal_de_compra = inventario[j].pc * recibo[i].cantidad_de_productos;
              recibo[0].total_de_compra = recibo[0].total_de_compra + recibo[i].subtotal_de_compra;

              recibo[i].subtotal_de_venta = inventario[j].pv * recibo[i].cantidad_de_productos;
              recibo[0].total_de_venta = recibo[0].total_de_venta + recibo[i].subtotal_de_venta;

              i++;
              recibo[0].no_de_ventas = recibo[0].no_de_ventas + 1;
            }
          } else {
            cout << "***No tenemos existencias de " << prod_t << " ***\n" << endl;
          }
      } while (prod_t != "*");
  cout << endl << endl;
  cout << "===================================================================\n" << endl;
  cout << "                       Abarrotes 'La Estrella'                     \n" << endl;
  cout << "                        R.F.C. ALE 730903 BB9                      \n" << endl;
  cout << "                           Ticket de Venta                         \n" << endl;
  cout << "                    Hora: " << tmP->tm_hour << ":" << tmP->tm_min << ":"<< tmP->tm_sec << setw(10) << "Fecha: " << tmP->tm_mday << "/" << tmP->tm_mon+1 << "/"<< tmP->tm_year+1900 << endl << endl;
  cout << "  No. de Venta: " << no_de_venta << endl;
  cout << "===================================================================\n" << endl << endl;
  cout << "Vendedor/a: ";
  cout <<  admin_usuario[posu].nombre << setw(43) << "Folio: " << rand() << endl << endl;
  cout << "Producto" << "  " << "Precio unitario  " << "Cantidad" << "" << "  " << setw(4) << "Subtotal" << endl << endl;
  int k = 0;
      for (k = 0; k < recibo[0].no_de_ventas; k++) {
            cout << setw(8) << recibo[k].nombre_de_producto << setw(4) << " - " <<
            setw(6) << recibo[k].precio_de_venta << setw(6) <<  " - "
            << setw(8) << recibo[k].cantidad_de_productos << setw(8) << " - " <<
            setw(8) << recibo[k].subtotal_de_venta << endl << endl;
      }
  iva = recibo[0].total_de_venta * 0.16;
  sub = recibo[0].total_de_venta - iva;
  cout << setw(61) << "Subtotal: $ " << sub << endl;
  cout << setw(61) << "IVA: $ " << iva << endl;
  cout << setw(61) << "Total: $ " << recibo[0].total_de_venta << endl;
  cout << endl << setw(40) << "¡ Gracias por su compra !\n" << endl;

  corte_de_caja = corte_de_caja + recibo[0].total_de_venta;
  admin_usuario[posu].total_venta = admin_usuario[posu].total_venta + corte_de_caja;
  admin_usuario[posu].total_compra = admin_usuario[posu].total_compra + recibo[0].total_de_compra;
  no_de_venta++;

  recibo[0].no_de_ventas = 0; recibo[0].total_de_venta = 0;
  recibo[0].total_de_compra = 0;
  escritura();
  escritura_texto();
  escritura_usuarios();
  escritura_usuarios_texto();
  } while (prod_t != "**");
}
