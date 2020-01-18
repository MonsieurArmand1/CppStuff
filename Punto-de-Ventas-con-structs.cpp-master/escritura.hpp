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
