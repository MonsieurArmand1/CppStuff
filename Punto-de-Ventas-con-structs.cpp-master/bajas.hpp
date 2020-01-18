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
        if (i < 0 || inventario[i].sts == 0) {
            cout << "***El producto, ya ha sido dado de baja o no existe***"
            << endl;
        }
        else{
            inventario[i].sts = 0;
        }
        prod_t.clear();
    } while (prod_t != "*");
}
