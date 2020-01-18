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
