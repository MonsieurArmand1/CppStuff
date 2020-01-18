void bajas_de_usuarios() {
fflush(stdin);
int i = 0; string usr_t;
cout << "===================================================================" << endl;
cout << "                      Bajas de Usuarios" << endl;
cout << "===================================================================" << endl;
    cout << endl << endl;
    do {
        cout << "Usuario que desea dar de baja:  ";
        cin >> usr_t;
        cout << endl;
        if (usr_t == "*") {
          return;
        }
        Status_usuario found_usuario = buscar_usuario(usr_t);
        i = found_usuario.pos;
        if (admin_usuario[i].user_status == 0) {
            cout << "El usuario, ya ha sido dado de baja o no existe" << endl;
        }
        else {
            admin_usuario[i].user_status = 0;
        }
        usr_t.clear();
    } while (usr_t != "*");
}
