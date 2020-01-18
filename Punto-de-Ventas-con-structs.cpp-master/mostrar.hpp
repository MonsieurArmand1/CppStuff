void mostrar() {
fflush(stdin);
int opcion = 0;
cout << "===================================================================" << endl;
cout << "                       Mostrar Productos" << endl;
cout << "===================================================================" << endl;
cout << endl << endl;
    do {
        cout <<  "1. Por ID." << endl;
        cout <<  "2. Por Alfabeto." << endl;
        cout <<  "3. Regresar.\n" << endl;
        cout << setw(15) << "Opcion:  ";
        cin >> opcion;
        cout << endl << endl;
        switch (opcion) {
        case 1:
            id();
            cout << endl;
            break;
        case 2:
            alfabeto();
            cout << endl;
            break;
        case 3:
            cout << "Regresando a Menu Administrador...\n" << endl;
            return;
        default:
            cout << " -Opcion invalida, intente de nuevo-\n" << endl;
        }
    } while (opcion != 3);
}
