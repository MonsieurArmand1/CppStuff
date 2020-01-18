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
