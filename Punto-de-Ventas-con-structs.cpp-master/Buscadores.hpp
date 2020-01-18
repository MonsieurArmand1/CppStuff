

Status buscar(string prod_t) {
    Status found;
    int i = 0;
    for (i = 0; i < total; i++) {
        if (inventario[i].producto == prod_t) {
            found.pos = i;
            found.st = inventario[i].sts;
            return found;
        }
    }
    found.pos = -1;
    found.st = 0;
    return found;
}

Status_usuario buscar_usuario(string usr_t) {
    Status_usuario found_usuario;
    int i = 0;
    for (i = 0; i < total_usuarios; i++) {
        if (admin_usuario[i].nombre == usr_t) {
            found_usuario.pos = i;
            found_usuario.st = admin_usuario[i].user_status;
            return found_usuario;
        }
    }

    found_usuario.pos = -1;
    found_usuario.st = 0;
    return found_usuario;
}
