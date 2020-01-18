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
