void escritura_usuarios_texto() {
  ofstream archivo_usuarios_texto("cuentas_texto.txt", ios::out);
  fflush(stdin);
  int i;
  int total_usuarios_temp;
  string nombre_e, contra_a;
  float total_compra_a, total_venta_a;
  int tipo_o, user_estatus_s;

  if (!archivo_usuarios_texto) {
      cout << "Error en la apertura del archivo de escritura_usuarios_texo\n";
  } else {
        for (i = 0; i < total_usuarios; i++) {
              total_usuarios_temp = total_usuarios;
              nombre_e = admin_usuario[i].nombre;
              contra_a = admin_usuario[i].contra;
              total_compra_a = admin_usuario[i].total_compra;
              total_venta_a = admin_usuario[i].total_venta;
              tipo_o = admin_usuario[i].tipo;
              user_estatus_s = admin_usuario[i].user_status;

              archivo_usuarios_texto << total_usuarios_temp << nombre_e << " "
              << contra_a << " " << total_compra_a << " " << total_venta_a <<
              " " << tipo_o << " " << user_estatus_s << " ";
          }
      }
  archivo_usuarios_texto.close();
}
