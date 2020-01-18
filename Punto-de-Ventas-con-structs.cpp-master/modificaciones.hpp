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
        if(i >= 0 && inventario[i].producto == prod_t) {

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
