void mostrar_usuarios() {
fflush(stdin);
int i = 0;
cout << "===================================================================" << endl;
cout << "            		    Mostrar Usuarios" << endl;
cout << "===================================================================\n" << endl << endl;
cout << setw(10) << "Nombre:" << setw(17) << "Contrasena:" << setw(13)<< "Ventas:" << setw(10) << "Tipo:" << endl << endl;

  for (i = 0; i < total_usuarios; i++) {
    if (admin_usuario[i].user_status == 1) {
      cout << setw(10) << admin_usuario[i].nombre << setw(15) << admin_usuario[i].contra << setw(12)
      << admin_usuario[i].total_venta << setw(11) << admin_usuario[i].tipo << endl;
    }
  }
    cout << endl;
}
