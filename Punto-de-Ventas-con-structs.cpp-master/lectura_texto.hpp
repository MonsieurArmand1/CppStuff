void lectura_texto() { //  ARCHIVOS DE TEXTO
      ifstream archivo_texto("inventario_texto.txt", ios::in | ios::binary);
      fflush(stdin);
      int i = 0;
      int id_d, total_temp;
      string producto_o, nombre_e, contra_a;
      float pc_c, pv_v, total_compra_a, total_venta_a;
      int existencias_s, n_r, st_t, tipo_o, user_estatus_s;

    if (!archivo_texto)
        cout << "Error en la apertura del archivo de lectura_texo\n";
    else {
archivo_texto >> total_temp >> id_d >> producto_o >> pc_c >> pv_v >> existencias_s
>> n_r >> st_t;

    total = total_temp;
      for (i = 0; i < total ; i++) {
            inventario[i].id = id_d;
            inventario[i].producto = producto_o;
            inventario[i].pc = pc_c;
            inventario[i].pv = pv_v;
            inventario[i].existencias = existencias_s;
            inventario[i].nr = n_r;
            inventario[i].sts = st_t;

archivo_texto >> total_temp >> id_d >> producto_o >> pc_c
>> pv_v >> existencias_s >> n_r >> st_t;
      }
    }
       archivo_texto.close();
}
