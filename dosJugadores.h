#ifndef DOSJUGADORES_H_INCLUDED
#define DOSJUGADORES_H_INCLUDED

#include "funciones2.h"
#include "rlutil.h"
#include "funciones.h"



void dosJugadores(char nombreMax[],int &puntMax,int &L)
{
    int vecRandomA[5];
    int vecRandomB[5];
    char nombreB[30];
    char nombreA[30];
    int puntajeAcumuladoA =0;
    int puntajeAcumuladoB =0;
    int rondas,puntosA,totalPuntosA,puntajeA;
    int puntosB,totalPuntosB,puntajeB;

    titulo(9);
    cout<<"MODO DE JUEGO PARA 2 JUGADORES"<<endl;
    cout<<endl;
    cout<<"**********************************************************************************"<<endl<<endl;
    cout << " INGRESE NOMBRE DEL JUGADOR 1:"<<endl;
    ponerPalabra(nombreA);
    cout<<endl;
    cout<<" INGRESE NOMBRE DEL JUGADOR 2:"<<endl;
    ponerPalabra(nombreB);
    cout<<endl;
    cout << " INGRESEN LA CANTIDAD DE RONDAS QUE DESEAN JUGAR: " << endl;
    cin >> rondas;
    while(rondas<1)
    {
        cout<<" INGRESE UN NUMERO DE RONDAS VALIDO (MAYOR QUE CERO)";
        cin>>rondas;
    }

    for(int x=0; x<rondas; x++)
    {
        system("cls");
        titulo(9);
        cout<<"MODO DE JUEGO PARA 2 JUGADORES"<<endl;
        cout<<endl;
        cout<<" TURNO DE "<<nombreA<<"\t"<<"|"<<"RONDA NUMERO: "<<x+1<<"\t"<<"|"<<"PUNTAJE ACUMULADO: "<<puntajeAcumuladoA<<endl;
        cout<<"--------------------------------------------------------------------"<<endl;

        int MaxA=0, MaxA2=0, MaxA3=0, MaxA4=0, MaxA5=0, MaxB=0, MaxB2=0, MaxB3=0, MaxB4=0, MaxB5=0;
        cout <<endl<< " INDIQUE CUANTOS PUNTOS QUIERE APOSTAR:" << endl;
        cin >> puntosA;

        system("cls");
        for(int i=0; i<5; i++)
        {
            system("cls");
            titulo(9);
            cout<<"MODO DE JUEGO PARA 2 JUGADORES"<<endl;
            cout<<endl;
            cout<<" TURNO DE "<<nombreA<<"\t"<<"|"<<"RONDA NUMERO: "<<x+1<<"\t"<<"|"<<"PUNTAJE ACUMULADO: "<<puntajeAcumuladoA<<endl;
            cout<<"--------------------------------------------------------------------"<<endl;

            cout << "TIRADA NUMERO " << i+1 << endl;
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
            pausa();
        }
        titulo(9);
        cout<<"MODO DE JUEGO PARA 2 JUGADORES"<<endl;
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
            setBackgroundColor(LIGHTBLUE);
            locate(2,10);
            cout << "SU PUNTAJE ES DE: " << puntajeA << " PUNTOS " << endl;
            puntajeAcumuladoA+=puntajeA;
            pausa();
        }
        else
        {
            cout << " SU PUNTAJE ES DE: -" << puntosA << " PUNTOS " << endl;
            puntajeAcumuladoA=puntajeAcumuladoA-puntosA;
            pausa();

        }
        system("cls");
        titulo(9);
        cout<<"MODO DE JUEGO PARA 2 JUGADORES"<<endl;
        cout<<endl;
        cout<<" TURNO DE "<<nombreB<<"\t"<<"|"<<"RONDA NUMERO: "<<x+1<<"\t"<<"|"<<"PUNTAJE ACUMULADO: "<<puntajeAcumuladoB<<endl;
        cout<<"--------------------------------------------------------------------"<<endl;
        cout <<endl<< "INDIQUE CUANTOS PUNTOS QUIERE APOSTAR:" << endl;
        cin >> puntosB;
        system("cls");
        for(int i=0; i<5; i++)
        {
            titulo(9);
            cout<<"MODO DE JUEGO PARA 2 JUGADORES"<<endl;
            cout<<endl;
            cout<<" TURNO DE "<<nombreB<<"\t"<<"|"<<"RONDA NUMERO: "<<x+1<<"\t"<<"|"<<"PUNTAJE ACUMULADO: "<<puntajeAcumuladoB<<endl;
            cout<<"--------------------------------------------------------------------"<<endl;
            cout << " TIRADA NUMERO " << i+1 << endl;
            ponerCero(vecRandomB,5);
            locate(2,20);
            cout<<"MAXIMOS DE TIRADAS ANTERIORES: ";

            if(i==0)
            {
                sonidoDados();
                cargarAleatorio(vecRandomB,5,6);
                for(int b=0; b<5; b++)
                {
                    dados(b+1,vecRandomB[b],9);
                }
                MaxB=valorMaximoVector(vecRandomB, 5);

            }

            if(i==1)
            {
                sonidoDados();
                cargarAleatorio(vecRandomB,4,6);
                for(int b=0; b<4; b++)
                {
                    dados(b+1,vecRandomB[b],9);
                }
                MaxB2=valorMaximoVector(vecRandomB, 4);
                locate(2,20);
                dadosMax(1,MaxB,9);

            }

            if(i==2)
            {
                sonidoDados();
                cargarAleatorio(vecRandomB,3,6);
                for(int b=0; b<3; b++)
                {
                    dados(b+1,vecRandomB[b],9);
                }
                MaxB3=valorMaximoVector(vecRandomB, 3);
                dadosMax(1,MaxB,9);
                dadosMax(2,MaxB2,9);
            }

            if(i==3)
            {
                sonidoDados();
                cargarAleatorio(vecRandomB,2,6);
                for(int b=0; b<2; b++)
                {
                    dados(b+1,vecRandomB[b],9);
                }
                MaxB4=valorMaximoVector(vecRandomB, 2);
                dadosMax(1,MaxB,9);
                dadosMax(2,MaxB2,9);
                dadosMax(3,MaxB3,9);
            }

            if(i==4)
            {
                sonidoDados();
                cargarAleatorio(vecRandomB,1,6);
                dados(1,vecRandomB[0],9);
                MaxB5=vecRandomB[0];
                dadosMax(1,MaxB,9);
                dadosMax(2,MaxB2,9);
                dadosMax(3,MaxB3,9);
                dadosMax(4,MaxB4,9);

            }

            setBackgroundColor(LIGHTBLUE);
            pausa();
        }
        titulo(9);
        cout<<"MODO DE JUEGO PARA 2 JUGADORES"<<endl;
        cout<<endl;
        cout<<" TURNO DE "<<nombreB<<"\t"<<"|"<<"RONDA NUMERO: "<<x+1<<"\t"<<"|"<<"PUNTAJE ACUMULADO: "<<puntajeAcumuladoB<<endl;
        cout<<"--------------------------------------------------------------------"<<endl;
        totalPuntosB=MaxB+MaxB2+MaxB3+MaxB4+MaxB5;
        locate(2,6);
        cout << "LA SUMATORIA DE MAXIMOS ES DE: " << totalPuntosB << endl;

        if(totalPuntosB>=20)
        {
            int numGenB;
            if(totalPuntosB>=25)
            {
                numGenB=6;
            }
            else
            {
                numGenB=totalPuntosB-19;
            }
            locate(15,8);
            cout<< "*****  TIRO DE PUNTAJE  ******" << endl;
            locate(2,9);
            cout << "EL NUMERO GENERADOR DE PUNTOS ES "<<numGenB<< endl;
            cargarAleatorio(vecRandomB,5,6);
            sonidoSuspenso();
            for(int b=0; b<5; b++)
            {
                if(vecRandomB[b]==numGenB)
                {
                    dados(b+1,vecRandomB[b],10);
                }
                else///
                {
                    dados(b+1,vecRandomB[b],9);
                }
            }
            puntajeB=puntosB*contarNumerosRepetidos(vecRandomB, numGenB, 5);///
            setBackgroundColor(LIGHTBLUE);
            locate(2,10);
            cout << "SU PUNTAJE ES DE: " << puntajeB << " PUNTOS " << endl;
            puntajeAcumuladoB+=puntajeB;
            pausa();
        }
        else
        {
            cout << " SU PUNTAJE ES DE: -" << puntosB << " PUNTOS " << endl;
            puntajeAcumuladoB=puntajeAcumuladoB-puntosB;
            pausa();
        }
    }
    if(L==0)
    {
        if(puntajeAcumuladoA>puntajeAcumuladoB)
        {
            strcpy(nombreMax,nombreA);
            puntMax=puntajeAcumuladoA;
            L=1;
        }
        else
        {
            strcpy(nombreMax,nombreB);
            puntMax=puntajeAcumuladoB;
            L=1;
        }
    }
    else
    {
        if(puntajeAcumuladoA>puntajeAcumuladoB)
        {
            if(puntajeAcumuladoA>puntMax)
            {
                puntMax=puntajeAcumuladoA;
                strcpy(nombreMax,nombreA);
            }
        }
        else
        {
            if(puntajeAcumuladoB>puntMax)
            {
                puntMax=puntajeAcumuladoB;
                strcpy(nombreMax,nombreB);
            }
        }
    }
    titulo(9);
    cout<<"MODO DE JUEGO PARA 2 JUGADORES"<<endl;
    cout<<endl;
    cout<<"--------------------------------------------------------------------"<<endl;
    if(puntajeAcumuladoA>puntajeAcumuladoB)
    {
        sonidoResultado();
        cout<<" EL GANADOR ES EL JUGADOR: "<<nombreA<<endl;
        cout<<" PUNTAJE TOTAL ACUMULADO: "<<puntajeAcumuladoA<<endl;
    }
    if(puntajeAcumuladoB>puntajeAcumuladoA)
    {
        sonidoResultado();
        cout<<" EL GANADOR ES EL JUGADOR: "<<nombreB<<endl;
        cout<<" PUNTAJE TOTAL ACUMULADO: "<<puntajeAcumuladoB<<endl;
    }
    if(puntajeAcumuladoA==puntajeAcumuladoB)
    {
        sonidoResultado();
        cout<<" HUBO UN EMPATE CON "<<puntajeAcumuladoA<<" PUNTOS"<<endl;
    }

}


#endif // DOSJUGADORES_H_INCLUDED
