void informacion(){
    cout << "Un automata finito determinista (abreviado AFD) es un automata finito que ademas es un sistema ";
    cout << "\ndeterminista; es decir, para cada estado en que se encuentre el automata, y con cualquier simbolo del alfabeto leido,\n";
    cout << "existe siempre no mas de una transicion posible desde ese estado y con ese simbolo.\n";
    cout << "Q: es un conjunto de estados;\n";
    cout << "Sigma: es un alfabeto\n";
    cout << "q0 perteneciente a Q:es el estado inicial\n";
    cout << "delta: Q multiplicado por Sigma a Q es una funcion de transicion\n;";
    cout << "F perteneciente a Q es un conjunto de estados finales o de aceptacion\n";
    cout << "En un AFD no pueden darse ninguno de estos dos casos:\n\n";
    cout << "Que existan dos transiciones del tipo sigma(q,a)=q1 y sigma(q,a)=q2, siendo q1 no es igual a q2;";
    cout << "\nQue existan transiciones del tipo sigma(q, epsilon), donde epsilon es la cadena vacia, salvo que q\n sea un estado final";
    cout << ", sin transiciones hacia otros estados.\n\n";

    cout <<"\t\tMas informacion en: https://www.institucional.frc.utn.edu.ar/sistemas/ghd/T-M-AFD.htm\n\n";
}
