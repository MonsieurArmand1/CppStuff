void lectura_usuarios_texto() {
  ifstream archivo_usuarios_texto("cuentas_texto.txt", ios::in);
  fflush(stdin);
  int i;
  int total_usuarios_temp;
  string  nombre_e, contra_a;
  float total_compra_a, total_venta_a;
  int tipo_o, user_estatus_s;
  if (!archivo_usuarios_texto) {
      cout << "Error en la apertura del archivo de lectura_usuarios" << endl;
  } else {
        while (!archivo_usuarios_texto) {
              total_usuarios = total_usuarios_temp;
              admin_usuario[i].nombre = nombre_e;
              admin_usuario[i].contra = contra_a;
              admin_usuario[i].total_compra = total_compra_a;
              admin_usuario[i].total_venta; total_venta_a;
              admin_usuario[i].tipo = tipo_o;
              admin_usuario[i].user_status =  user_estatus_s;

        archivo_usuarios_texto >> total_usuarios >> nombre_e >> contra_a >>
        total_compra_a >> total_venta_a >> tipo_o >> user_estatus_s;
        }
    }
       archivo_usuarios_texto.close();
}
