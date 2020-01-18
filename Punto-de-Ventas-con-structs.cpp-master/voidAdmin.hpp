void admin() {
fflush(stdin);
Usuarios usuarios_temporal;
int opcion = 0; int i = 0; string contra_temp, usr_t;
usr_t.clear(); contra_temp.clear();

      do {
        cout << setw(20) << "Por favor, ingrese su usuario:  ";
        cin >> usr_t;
        Status_usuario found_usuario_local = buscar_usuario(usr_t);
        i = found_usuario_local.pos;
        cout << setw(20) << "Ingrese su contrasena:  ";
        cin >> contra_temp;
        cout << endl;
        if (admin_usuario[i].tipo != 1 || admin_usuario[i].user_status != 1 || admin_usuario[i].contra != contra_temp || admin_usuario[i].nombre != usr_t){
          cout << "*Usuario y/o contrsena incorrecto, intentelo de nuevo*\n" << endl;
          return;
        } else {
          break;
        }
      } while (admin_usuario[i].nombre != usr_t && admin_usuario[i].user_status != 1 && admin_usuario[i].tipo != 1 && admin_usuario[i].contra != contra_temp);
do {

cout << "===================================================================" << endl;
cout << "           ¡Bienvenid@ al Menu Administrador!" << endl;
cout << "===================================================================" << endl;
cout << endl << endl;
cout << "1. Productos" << endl;
cout << "2. Cuentas de Usuarios" << endl;
cout << "3. Utilidades." << endl;
cout << "4. Regresar al Menu Principal.\n" << endl;
cout << setw(15) << "Opcion:  ";
cin >> opcion;
cout << endl;

        switch (opcion) {
        case 1:
            admin_de_productos();
            cout << endl;
            break;
        case 2:
            admin_de_usuarios();
            cout << endl;
            break;
        case 3:
            utilidades();
            cout << endl;
            break;
        case 4:
            cout << "Regresando al Menu principal..." << endl;
            break;
        default:
            cout <<" -Opcion invalida, intente de nuevo-\n" << endl;
        }
        escritura();
        escritura_texto();
        escritura_usuarios();
        escritura_usuarios_texto();
    } while (opcion != 4);
}
