void admin_de_usuarios() {
fflush(stdin);
int opcion = 0;
cout << "===================================================================" << endl;
cout << "                   ADMINISTRACION DE CUENTAS" << endl;
cout << "===================================================================" << endl;
cout << endl << endl;
    do {
        cout <<  "1. Altas." << endl;
        cout <<  "2. Bajas." << endl;
        cout <<  "3. Mostrar Usuarios." << endl;
        cout <<  "4. Consultas." << endl;
        cout <<  "5. Modificaciones." << endl;
        cout <<  "6. Regresar al Menu Administrador.\n" << endl;
        cout << setw(15) << "Opcion:  ";
        cin >> opcion;
        cout << endl << endl;
        switch (opcion) {
        case 1:
            altas_de_usuarios();
            cout << endl;
            break;
        case 2:
            bajas_de_usuarios();
            cout << endl;
            break;
        case 3:
            mostrar_usuarios();
            cout << endl;
            break;
        case 4:
            buscar_usuarios();
            cout << endl;
            break;
        case 5:
            modificar_usuarios();
            cout << endl;
            break;
        case 6:
            cout << "Regresando al Menu Administrador..." << endl;
            break;
        default:
            cout <<" -Opcion invalida, intente de nuevo-" << endl << endl;
        }
    } while (opcion != 6);
}
