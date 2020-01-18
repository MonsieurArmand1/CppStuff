void utilidades() {
float ingreso = 0, egreso = 0, utilidad = 0;
cout << "===================================================================" << endl;
cout << "                              UTILIDADES" << endl;
cout << "===================================================================" << endl;
    cout << endl;
    cout << endl;
                for (int posu = 0; posu < total_usuarios; posu++) {
                    ingreso = ingreso + admin_usuario[posu].total_compra;
                    egreso = egreso + admin_usuario[posu].total_venta;
                }
                cout << "Ingresos:  $ " << ingreso << endl;
                cout << "Egresos:  $ " << egreso << endl;
                utilidad = egreso - ingreso;
                cout << "Utilidad de la venta:  $ " << utilidad << endl;
}
