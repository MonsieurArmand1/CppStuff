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
