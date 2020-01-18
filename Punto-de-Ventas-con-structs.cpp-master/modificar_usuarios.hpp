void modificar_usuarios() {
fflush(stdin);
int opcion = 0, i = 0;
string usr_t = "";
Usuarios usuario_temporal;
cout << "===================================================================" << endl;
cout << "                 Modificaciones de Usuarios" << endl;
cout << "===================================================================" << endl;
cout << endl << endl;
do {
        cout << "¿Que usuario desea modificar?: ";
        cin >> usr_t;
        cout << endl;
        if (usr_t == "*")
            return;
        Status_usuario found_usuario_local = buscar_usuario(usr_t);
        i = found_usuario_local.pos;
        if (found_usuario_local.st == 0) {
            cout << "El usuario se encuentra dado de baja, debe darlo de alta para modificarlo\n" << endl;
        }
        if (admin_usuario[i].nombre == usr_t) {

        cout << setw(10) << "Nombre:" << setw(17) << "Contrasena:" << setw(13)<< "Ventas:" << setw(10) << "Tipo:" << endl << endl;
        cout << setw(10) << admin_usuario[i].nombre << setw(15) << admin_usuario[i].contra << setw(12)
        << admin_usuario[i].total_venta << setw(11) << admin_usuario[i].tipo << endl << endl;

            cout << "1. Nombre" << endl;
            cout << "2. Contrasena" << endl;
            cout << "3. Tipo" << endl;
            cout << "4. Regresar\n" << endl;
            cout << setw(15) << "Opcion:  ";
            cin >> opcion;
            cout << endl << endl;
            switch (opcion) {
            case 1:
                do {
                    cout << "Nuevo Nombre:  ";
                    cin >> usr_t;
                    cout << endl;
                    if(usr_t == admin_usuario[i].nombre)
                        cout << "El nombre no puede ser igual al anterior\n" << endl;
                }
                while(admin_usuario[i].nombre == usr_t);
                admin_usuario[i].nombre = usr_t;
                break;
            case 2:
                do {
                    cout << "Nueva Contrasena:  ";
                    cin >> usuario_temporal.contra;
                    cout << endl;
                    if (usuario_temporal.contra == admin_usuario[i].contra)
                        cout << "La contrasena no puede ser igual al anterior\n" << endl;
                } while (admin_usuario[i].contra == usuario_temporal.contra);
                admin_usuario[i].contra = usuario_temporal.contra;
                break;
            case 3:

                if (admin_usuario[i].tipo == 1) {
                    cout << "El tipo ha sido cambiado a Vendedor" << endl;
                    admin_usuario[i].tipo = 0;
                } else {
                    cout << "El tipo ha sido cambiado a Administrador" << endl;
                    admin_usuario[i].tipo = 1;
                }
                break;

            case 4:
                return;

            default:
                cout << "***Opcion invalida, intente de nuevo***" << endl;
            }
        } else {
            cout << "***El usuario a modificar no existe***\n" << endl;
            usr_t == "*";
        }
  } while (usr_t != "*");
}
