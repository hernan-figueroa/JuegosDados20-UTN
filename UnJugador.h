#ifndef UNJUGADOR_H_INCLUDED
#define UNJUGADOR_H_INCLUDED

#include "funciones2.h"
#include "rlutil.h"
#include "funciones.h"

void unJugador(char nombreMax[],int &puntMax,int &L)
{
    char nombreA[30];
    int vecRandomA[5];
    int puntajeAcumuladoA =0;
    int rondas,puntosA,totalPuntosA,puntajeA;
    int ContCeroPuntosA=0,ContRestaPuntosA=0;
    titulo(9);
    cout<<"MODO DE JUEGO PARA 1 JUGADOR"<<endl;
    cout<<endl;
    cout<<"**********************************************************************************"<<endl<<endl;
    cout << " INGRESE SU NOMBRE: " << endl;
    ponerPalabra(nombreA);
    cout<<endl;
    cout << " INGRESE LA CANTIDAD DE RONDAS QUE DESEA JUGAR: " << endl;
    cin >> rondas;
    while(rondas<1)
    {
        cout<<" INGRESE UN NUMERO DE RONDAS VALIDO (MAYOR QUE CERO)"<<endl;
        cin>>rondas;
    }

    for(int x=0; x<rondas; x++)
    {
        if(x>0)
        {
            titulo(9);
            cout<<"MODO DE JUEGO PARA 1 JUGADOR"<<endl;
            cout<<endl;
            cout<<" TURNO DE "<<nombreA<<"\t"<<"|"<<"RONDA NUMERO: "<<x+1<<"\t"<<"|"<<"PUNTAJE ACUMULADO: "<<puntajeAcumuladoA<<endl;
            cout<<"--------------------------------------------------------------------"<<endl;
        }
        int MaxA, MaxA2, MaxA3, MaxA4, MaxA5;
        cout <<endl<< " INDIQUE CUANTOS PUNTOS QUIERE APOSTAR:" << endl;
        cin >> puntosA;
        system("cls");
        for(int i=0; i<5; i++)
        {
            titulo(9);
            cout<<"MODO DE JUEGO PARA 1 JUGADOR"<<endl;
            cout<<endl;
            cout<<" TURNO DE "<<nombreA<<"\t"<<"|"<<"RONDA NUMERO: "<<x+1<<"\t"<<"|"<<"PUNTAJE ACUMULADO: "<<puntajeAcumuladoA<<endl;
            cout<<"--------------------------------------------------------------------"<<endl;
            cout<<endl<<endl;
            cout << " TIRADA NUMERO " << i+1 << endl;
            ponerCero(vecRandomA,5);
            locate(2,20);
            cout<<"MAXIMOS DE TIRADAS ANTERIORES: ";

            if(i==0)
            {
                sonidoDados();
                cargarAleatorio(vecRandomA,5,6);
                for(int b=0; b<5; b++)
                {
                    dados(b+1,vecRandomA[b],9);
                }
                MaxA=valorMaximoVector(vecRandomA, 5);

            }


            if(i==1)
            {
                sonidoDados();
                cargarAleatorio(vecRandomA,4,6);
                for(int b=0; b<4; b++)
                {
                    dados(b+1,vecRandomA[b],9);
                }
                MaxA2=valorMaximoVector(vecRandomA, 4);
                locate(2,20);
                dadosMax(1,MaxA,9);

            }

            if(i==2)
            {
                sonidoDados();
                cargarAleatorio(vecRandomA,3,6);
                for(int b=0; b<3; b++)
                {
                    dados(b+1,vecRandomA[b],9);
                }
                MaxA3=valorMaximoVector(vecRandomA, 3);
                dadosMax(1,MaxA,9);
                dadosMax(2,MaxA2,9);
            }
            if(i==3)
            {
                sonidoDados();
                cargarAleatorio(vecRandomA,2,6);
                for(int b=0; b<2; b++)
                {
                    dados(b+1,vecRandomA[b],9);
                }
                MaxA4=valorMaximoVector(vecRandomA, 2);
                dadosMax(1,MaxA,9);
                dadosMax(2,MaxA2,9);
                dadosMax(3,MaxA3,9);
            }
            if(i==4)
            {
                sonidoDados();
                cargarAleatorio(vecRandomA,1,6);
                dados(1,vecRandomA[0],9);
                MaxA5=vecRandomA[0];
                dadosMax(1,MaxA,9);
                dadosMax(2,MaxA2,9);
                dadosMax(3,MaxA3,9);
                dadosMax(4,MaxA4,9);

            }
            setBackgroundColor(LIGHTBLUE);
            pausa();
        }
        titulo(9);
        cout<<"MODO DE JUEGO PARA 1 JUGADOR"<<endl;
        cout<<endl;
        cout<<" TURNO DE "<<nombreA<<"\t"<<"|"<<"RONDA NUMERO: "<<x+1<<"\t"<<"|"<<"PUNTAJE ACUMULADO: "<<puntajeAcumuladoA<<endl;
        cout<<"--------------------------------------------------------------------"<<endl;
        totalPuntosA=MaxA+MaxA2+MaxA3+MaxA4+MaxA5;
        locate(2,6);
        cout << "LA SUMATORIA DE MAXIMOS ES DE: " << totalPuntosA << endl;

        if(totalPuntosA>=20)
        {
            int numGenA;
            if(totalPuntosA>=25)
            {
                numGenA=6;
            }
            else
            {
                numGenA=totalPuntosA-19;
            }
            locate(15,8);
            cout<< "*****  TIRO DE PUNTAJE  ******" << endl;
            locate(2,9);
            cout << "EL NUMERO GENERADOR DE PUNTOS ES "<<numGenA<< endl;
            cargarAleatorio(vecRandomA,5,6);
            sonidoSuspenso();
            for(int b=0; b<5; b++)
            {
                if(vecRandomA[b]==numGenA)
                {
                    dados(b+1,vecRandomA[b],10);
                }
                else
                {
                    dados(b+1,vecRandomA[b],9);
                }
            }
            puntajeA=puntosA*contarNumerosRepetidos(vecRandomA, numGenA, 5);
            if(puntajeA==0)
            {
                ContCeroPuntosA++;
            }
            setBackgroundColor(LIGHTBLUE);
            locate(2,10);
            cout << "SU PUNTAJE ES DE: " << puntajeA << " PUNTOS " << endl;
            puntajeAcumuladoA+=puntajeA;
            pausa();
        }
        else
        {
            ContRestaPuntosA++;
            cout << " SU PUNTAJE ES DE: -" << puntosA << " PUNTOS " << endl;
            puntajeAcumuladoA=puntajeAcumuladoA-puntosA;
            pausa();

        }
    }
    if(L==0)
    {
        strcpy(nombreMax,nombreA);
        puntMax=puntajeAcumuladoA;
        L=1;
    }
    else
    {
        if(puntajeAcumuladoA>puntMax)
        {
            puntMax=puntajeAcumuladoA;
            strcpy(nombreMax,nombreA);
        }
    }
    titulo(9);
    cout<<"MODO DE JUEGO PARA 1 JUGADOR"<<endl;
    cout<<endl;
    sonidoResultado();
    cout<<" NOMBRE DEL JUGADOR: "<<nombreA<<endl;
    cout<<" RONDAS SIN PUNTOS: "<<ContCeroPuntosA<<endl;
    cout<<" RONDAS RESTANDO PUNTOS: "<<ContRestaPuntosA<<endl;
    cout<<" PUNTAJE TOTAL ACUMULADO: "<<puntajeAcumuladoA<<endl;
}


#endif // UNJUGADOR_H_INCLUDED
