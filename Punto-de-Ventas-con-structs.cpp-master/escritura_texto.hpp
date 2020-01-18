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
