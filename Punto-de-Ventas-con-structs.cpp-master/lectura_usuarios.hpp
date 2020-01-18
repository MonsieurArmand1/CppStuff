void lectura_usuarios() {
  // ifstream archivo_usuarios("cuentas.bin", ios::in | ios::binary);
  ifstream archivo_usuarios;
  archivo_usuarios.open("cuentas.dat", ios::in | ios::binary);
  char nombre_e[20];
  char contra_a[20];
  float total_compra_a, total_venta_a;
  int tipo_o, user_estatus_s;
    if (!archivo_usuarios) {
      cout << "Archivo lectura_usuarios inexistente\n";
  } else {
    int i = 0;
      while (!archivo_usuarios.eof()) {

        archivo_usuarios.read(nombre_e, 20);
        archivo_usuarios.read(contra_a, 20);
        archivo_usuarios.read(reinterpret_cast<char *> (&total_compra_a), sizeof (total_compra_a));
        archivo_usuarios.read(reinterpret_cast<char *> (&total_venta_a), sizeof (total_venta_a));
        archivo_usuarios.read(reinterpret_cast<char *> (&tipo_o), sizeof (tipo_o));
        archivo_usuarios.read(reinterpret_cast<char *> (&user_estatus_s), sizeof (user_estatus_s));

        admin_usuario[i].nombre = nombre_e;
        admin_usuario[i].contra = contra_a;
        admin_usuario[i].total_compra = total_compra_a;
        admin_usuario[i].total_venta; total_venta_a;
        admin_usuario[i].tipo = tipo_o;
        admin_usuario[i].user_status =  user_estatus_s;
        total_usuarios = i;
        i++;
      }
    }
  archivo_usuarios.close();
}
