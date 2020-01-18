void escritura_usuarios() {
  ofstream archivo_usuarios;
  archivo_usuarios.open("cuentas.dat", ios::out | ios::binary); // ("cuentas.bin", ios::out | ios::binary);
  int i = 0, total_usuarios_temp = 0;
  char nombre_e[20];
  char contra_a[20];
  float total_compra_a = 0, total_venta_a = 0;
  int tipo_o = 0, user_estatus_s = 0;

      if (!archivo_usuarios) {
      cout <<  "Archivo escritura_usuarios inexistente\n";
      } else {
        for (i = 0; i < total_usuarios ; i++) {
          memset(nombre_e, 0, sizeof(nombre_e));
          memset(contra_a, 0, sizeof(contra_a));
          strcpy(nombre_e,admin_usuario[i].nombre.c_str());
          strcpy(contra_a, admin_usuario[i].contra.c_str());
          total_compra_a = admin_usuario[i].total_compra;
          total_venta_a = admin_usuario[i].total_venta;
          tipo_o = admin_usuario[i].tipo;
          user_estatus_s = admin_usuario[i].user_status;

          archivo_usuarios.write(nombre_e, 20);
          archivo_usuarios.write(contra_a, 20);
          archivo_usuarios.write(reinterpret_cast<char* >(&total_compra_a), sizeof (total_compra_a));
          archivo_usuarios.write(reinterpret_cast<char* >(&total_venta_a), sizeof (total_venta_a));
          archivo_usuarios.write(reinterpret_cast<char* >(&tipo_o), sizeof (tipo_o));
          archivo_usuarios.write(reinterpret_cast<char* >(&user_estatus_s), sizeof (user_estatus_s));
        }
     }
    archivo_usuarios.close();
  }
