#ifndef MAYORPUNTUACION_H_INCLUDED
#define MAYORPUNTUACION_H_INCLUDED

void mayorPuntuacion(int L,char nombreMax[], int puntMax)
{

    titulo(9);
    cout<<"PUNTUACION MAS ALTA"<<endl;
    cout<<endl;
    cout<<"--------------------------------------------------------------------"<<endl;
    {
        if(L==0)
        {
            cout<<" TODAVIA NO HAY PUNTUACIONES"<<endl;

        }
        else
        {
            sonidoResultado();

            recuadro(10,6,13,2,15,CYAN);
            locate(12,7);
            cout<<"NOMBRE"<<endl;

            recuadro(10,8,13,2,15,LIGHTBLUE);
            locate(12,9);
            cout<<nombreMax<<endl;


            recuadro(23,6,13,2,15,CYAN);
            locate(25,7);
            cout<<"PUNTAJE"<<endl;

            recuadro(23,8,13,2,15,LIGHTBLUE);
            locate(25,9);
            cout<<puntMax<<endl;
        }

    }
}

#endif // MAYORPUNTUACION_H_INCLUDED
