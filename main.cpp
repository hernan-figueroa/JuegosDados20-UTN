#include <iostream>
#include <cstdlib>
#include <cstring>
#include <windows.h>

using namespace std;

#include "rlutil.h"
#include "funciones.h"
#include "funciones2.h"
#include "reglas.h"
#include "finDelPrograma.h"
#include "menuPrincipal.h"
#include "UnJugador.h"
#include "DosJugadores.h"
#include "mayorPuntuacion.h"
#include "modoSimulado.h"


using namespace rlutil;



int main()
{

    int L=0;

    while(true)
    {
        int puntMax;
        int opciones;
        char nombreMax[30];

        menuPrincipal(opciones);

        switch(opciones)
        {
        case 1:
        {
            unJugador(nombreMax,puntMax,L);
        }

        break;

        case 2:
        {
            dosJugadores(nombreMax,puntMax,L);
        }
        break;

        case 3:
        {
            mayorPuntuacion(L,nombreMax,puntMax);
        }
        break;

        case 4:
        {
            modoSimulado(nombreMax,puntMax,L);
        }

        break;

        case 5:
        {
            reglas();

        }

        break;

        case 0:
        {
            finDelPrograma();
            locate(15,25);
            return 0;
        }
        break;


        }
        locate(15,25);
        system("pause");
    }
    return 0;
}
