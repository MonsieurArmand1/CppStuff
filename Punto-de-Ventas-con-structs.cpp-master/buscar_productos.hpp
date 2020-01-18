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
