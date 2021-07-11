#ifndef MENUPRINCIPAL_H_INCLUDED
#define MENUPRINCIPAL_H_INCLUDED

void menuPrincipal(int &opciones)
{
    colorFondo(9);
    titulo(9);
    cout<<"JUEGO DE DADOS 20"<<endl;
    cout<<endl;
    sonidoMenu();
    Sleep(60);
    cout <<endl<<endl<< " 1) Juego nuevo para un jugador" << endl;
    Sleep(60);
    cout << " 2) Juego nuevo para dos jugadores" << endl;
    Sleep(60);
    cout << " 3) Mostrar puntuacion mas alta"<< endl;
    Sleep(60);
    cout << " 4) Modo simulado (carga de dados manual)" << endl;
    Sleep(60);
    cout << " 5) Reglamendo del juego" << endl;
    Sleep(60);
    cout << " 0) Fin del programa" << endl<<"\t" << endl<<"\t" << endl<<"\t" << endl;
    Sleep(120);

    cout << " INGRESE LA OPCION QUE DESEA ELEGIR: " << endl<< "\t" << endl;
    cin >> opciones;


    system("cls");
}
#endif // MENUPRINCIPAL_H_INCLUDED
