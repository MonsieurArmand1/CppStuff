void admin_de_productos() {
fflush(stdin);
int opcion = 0;
do {
cout << "===================================================================" << endl;
cout << "                  ADMINISTRACION DE PRODUCTOS   " << endl;
cout << "===================================================================" << endl;
cout << endl << endl;
cout <<  "1. Altas." << endl;
cout <<  "2. Bajas." << endl;
cout <<  "3. Mostrar." << endl;
cout <<  "4. Consultar Producto." << endl;
cout <<  "5. Modificaciones." << endl;
cout <<  "6. Regresar al Menu Administrador.\n" << endl;
cout << setw(15) << "Opcion:  ";
cin >> opcion;
cout << endl << endl;
        switch (opcion) {
        case 1:
            altas();
            cout << endl;
            break;
        case 2:
            bajas();
            cout << endl;
            break;
        case 3:
            mostrar();
            cout << endl;
            break;
        case 4:
            buscar_productos();
            cout << endl;
            break;
        case 5:
            modificaciones();
            cout << endl;
            break;
        case 6:
            cout << "Regresando al Menu Administrador..." << endl;
            cout << endl;
            break;
        default:
            cout << "-Opcion invalida, intente de nuevo-\n" << endl;
        }
    } while (opcion != 6);
}
