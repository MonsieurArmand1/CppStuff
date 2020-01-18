void altas_de_usuarios() {
fflush(stdin);
Usuarios usuarios_temporal;
char resp; int i = 0;
string nom_temp; string contra_temp; string usr_t;
bool tipo_usuario;

cout << "===================================================================" << endl;
cout << "                       Altas de Usuarios" << endl;
cout << "===================================================================" << endl;
cout << endl << endl;
    do {
        cout << "Agregar Usuario:  ";
        cin >> usr_t;
        cout << endl;
        if (usr_t == "*") {
            return;
        }
        Status_usuario found_usuario_local = buscar_usuario(usr_t);
        i = found_usuario_local.pos;
        if (admin_usuario[i].nombre == usr_t) {
            cout << "***upss... El usuario ya existe***" << endl;
            if (admin_usuario[i].user_status == 0) {
                cout << "¿Desea Darlo de alta? (s/n): ";
                cin >> resp;
                cout << endl;
                if (resp == 's')
                    admin_usuario[i].user_status = 1;
                return;
            }
        } else {
            i = total_usuarios++;
            cout << "Agregar Contrasena:  ";
            cin >> contra_temp;
            cout << endl;
            cout << "Agregar Tipo (1 = Administrador, 0 = Vendedor):  ";
            cin >> tipo_usuario;
            cout << endl;

            admin_usuario[i].nombre = usr_t;
            admin_usuario[i].contra = contra_temp;
            admin_usuario[i].total_compra = 0;
            admin_usuario[i].total_venta = 0;
            admin_usuario[i].tipo = tipo_usuario;
            admin_usuario[i].user_status = 1;
            total_usuarios = total_usuarios++;
        }
        usr_t.clear();
    } while (usr_t != "*");
}
