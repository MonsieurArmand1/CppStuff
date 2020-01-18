void buscar_usuarios() {
fflush(stdin);
int i = 0; string usr_t;
cout << "===================================================================" << endl;
cout << "                    Consulta de Usuarios" << endl;
cout << "===================================================================" << endl;
cout << endl << endl;
    do {
        cout << "Usuario a buscar:  ";
        cin >> usr_t;
        cout << endl;
        if (usr_t == "*")
            return;
        Status_usuario found_usuario_local = buscar_usuario(usr_t);
        i = found_usuario_local.pos;
        if (i == -1) {
            cout << "***El usuario que esta buscando, no existe***\n" << endl;
        }
        if(admin_usuario[i].nombre == usr_t) {
            cout << setw(10) << "Nombre:" << setw(17) << "Contrasena:" << setw(13)<< "Ventas:" << setw(10) << "Tipo:" << endl << endl;
            if (admin_usuario[i].user_status == 1) {
                cout << setw(10) << admin_usuario[i].nombre << setw(15) << admin_usuario[i].contra << setw(12)
                << admin_usuario[i].total_venta << setw(11) << admin_usuario[i].tipo << endl << endl << endl;
            }
            else {
            cout << "***El usuario que está buscando está dado de baja***" << endl << endl;
            }

        }
    } while (usr_t != "*");
}
