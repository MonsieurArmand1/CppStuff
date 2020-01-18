void venta() {
Ventas recibo[100];
string usr_t, contra_temp;
int posu, no_de_venta = 1, i = 0;
float iva = 0, corte_de_caja = 0, sub = 0;
char resp;
string prod_t;
time_t tSac = time(NULL);
struct tm* tmP = localtime(&tSac);

cout << "===================================================================" << endl;
cout << setw(40) << "¡ BIENVENID@ !" << endl;
cout << "===================================================================" << endl;
cout << endl << endl;
usr_t.clear(); contra_temp.clear();
      do {
        cout << setw(20) << "Por favor, ingrese su usuario:  ";
        cin >> usr_t;
        Status_usuario found_usuario_local = buscar_usuario(usr_t);
        posu = found_usuario_local.pos;
        cout << setw(20) << "Ingrese su contrasena:  ";
        cin >> contra_temp;
        cout << endl;
        if (admin_usuario[posu].tipo != 0 || admin_usuario[posu].user_status != 1 || admin_usuario[posu].contra != contra_temp || admin_usuario[posu].nombre != usr_t){
          cout << "*Usuario y/o contrsena incorrecto, intentelo de nuevo*\n" << endl;
          return;
        } else {
          break;
        }
      } while (admin_usuario[posu].nombre != usr_t && admin_usuario[posu].user_status != 1 && admin_usuario[posu].tipo != 0 && admin_usuario[posu].contra != contra_temp);
int j = 0;
  do {
    do {
        cout << "Producto: ";
        cin >> prod_t;
        if (prod_t == "**") {
            cout << endl << endl;
            cout << "Corte de Caja: $ ";
            cout << corte_de_caja << endl << endl;
            corte_de_caja = 0;
            return;
        }
        Status found_local = buscar(prod_t);
        j = found_local.pos;
        if (found_local.st == 1 && inventario[j].existencias > 0) {
          cout << "Cantidad: ";
          cin >> recibo[i].cantidad_de_productos;
          cout << endl;

          if (recibo[i].cantidad_de_productos > inventario[j].existencias) {
            cout << "Solo se tienen: " << inventario[j].existencias  <<
            "  ¿Efectuar venta? (s/n):  ";
            cin >> resp;
            cout << endl;
            if (resp == 's') {
              recibo[i].cantidad_de_productos = 0;
              recibo[i].cantidad_de_productos = inventario[j].existencias;
              inventario[j].existencias = 0;
              recibo[i].nombre_de_producto = prod_t;
              recibo[i].precio_de_venta = inventario[j].pv;

              recibo[i].subtotal_de_compra = inventario[j].pc * recibo[i].cantidad_de_productos;
              recibo[0].total_de_compra = recibo[0].total_de_compra + recibo[i].subtotal_de_compra;

              recibo[i].subtotal_de_venta = inventario[j].pv * recibo[i].cantidad_de_productos;
              recibo[0].total_de_venta = recibo[0].total_de_venta + recibo[i].subtotal_de_venta;

              i++;
              recibo[0].no_de_ventas = recibo[0].no_de_ventas + 1;
            }
          } else if  (recibo[i].cantidad_de_productos <= inventario[j].existencias) {
            inventario[j].existencias = inventario[j].existencias - recibo[i].cantidad_de_productos;
            recibo[i].nombre_de_producto = prod_t;
            recibo[i].precio_de_venta = inventario[i].pv;

            recibo[i].subtotal_de_compra = inventario[j].pc * recibo[i].cantidad_de_productos;
            recibo[0].total_de_compra = recibo[0].total_de_compra + recibo[i].subtotal_de_compra;

            recibo[i].subtotal_de_venta = inventario[j].pv * recibo[i].cantidad_de_productos;
            recibo[0].total_de_venta = recibo[0].total_de_venta + recibo[i].subtotal_de_venta;

            i++;
            recibo[0].no_de_ventas = recibo[0].no_de_ventas + 1;
          }
        } else {
          cout << "***No tenemos existencias de " << prod_t << " ***\n" << endl;
        }
    } while (prod_t != "*");
cout << endl << endl;
cout << "===================================================================\n" << endl;
cout << "                       Abarrotes 'La Estrella'                     \n" << endl;
cout << "                        R.F.C. ALE 730903 BB9                      \n" << endl;
cout << "                           Ticket de Venta                         \n" << endl;
cout << "                    Hora: " << tmP->tm_hour << ":" << tmP->tm_min << ":"<< tmP->tm_sec << setw(10) << "Fecha: " << tmP->tm_mday << "/" << tmP->tm_mon+1 << "/"<< tmP->tm_year+1900 << endl << endl;
cout << "  No. de Venta: " << no_de_venta << endl;
cout << "===================================================================\n" << endl << endl;
cout << "Vendedor/a: ";
cout <<  admin_usuario[posu].nombre << setw(43) << "Folio: " << rand() << endl << endl;
cout << "Producto" << "  " << "Precio unitario  " << "Cantidad" << "" << "  " << setw(4) << "Subtotal" << endl << endl;
int k = 0;
    for (k = 0; k < recibo[0].no_de_ventas; k++) {
          cout << setw(8) << recibo[k].nombre_de_producto << setw(4) << " - " <<
          setw(6) << recibo[k].precio_de_venta << setw(6) <<  " - "
          << setw(8) << recibo[k].cantidad_de_productos << setw(8) << " - " <<
          setw(8) << recibo[k].subtotal_de_venta << endl << endl;
    }
iva = recibo[0].total_de_venta * 0.16;
sub = recibo[0].total_de_venta - iva;
cout << setw(61) << "Subtotal: $ " << sub << endl;
cout << setw(61) << "IVA: $ " << iva << endl;
cout << setw(61) << "Total: $ " << recibo[0].total_de_venta << endl;
cout << endl << setw(40) << "¡ Gracias por su compra !\n" << endl;

corte_de_caja = corte_de_caja + recibo[0].total_de_venta;
admin_usuario[posu].total_venta = admin_usuario[posu].total_venta + corte_de_caja;
admin_usuario[posu].total_compra = admin_usuario[posu].total_compra + recibo[0].total_de_compra;
no_de_venta++;

recibo[0].no_de_ventas = 0; recibo[0].total_de_venta = 0;
recibo[0].total_de_compra = 0;
escritura();
escritura_texto();
escritura_usuarios();
escritura_usuarios_texto();
} while (prod_t != "**");
  // corte_de_caja = 0;  //  Revisar por que no guarda el acumulado, es saliendo de corte de caja
}
