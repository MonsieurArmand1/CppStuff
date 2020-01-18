# Punto-de-Ventas-con-structs.cpp
Punto de Ventas en C++ 11. Utilizando Structs, archivos binarios y de texto
Adicionales a los requerimientos del proyecto:

Genera un folio aleatorio al momento de expedir un ticket.
Muestra las utilidades ganadas en el ejercicio (hasta el loggout).
Muestra el número de venta en el ticket (hasta el loggout).
Muestra subtotal, IVA y total.
Mostrar Usuarios guardará la cantidad vendida de cada usuario en archivo.
Genera archivo binario y de texto para inventario.
Genera archivo binario y de texto para cuentas.

MENÚ ADMINISTRADOR:
Se ingresa con: armando, contraseña: admin1
Se guardan los archivos una vez saliendo del Menú Administrador, al igual que los usuarios.

Importante:
Para salir de la función se debe ingresar “*” cuando solicita el primer input.

Para utilizar archivos de texto se debe activar desde código la función

MENÚ VENDEDOR:
Se puede ingresar con “juan” o “maria”, contraseñas “v1” y “v2”.
Para terminar una venta se debe ingresar “*”, una vez terminada, si desea salir de ventas, debe pulsar “**” y regresa al menú principal.

Nota: Los productos y cuentas se actualizarán una vez efectuado el ticket.
Estando en administrador, es necesario salir para que se actualicen los usuarios y cuentas.

*Importante*
Existe un error de memoria al dar de alta o baja un producto con una longitud de 7 caracteres, debido a la variable global "prod_t"... estaré trabajando en ello...
