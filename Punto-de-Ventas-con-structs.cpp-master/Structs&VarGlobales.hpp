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
