#include <iostream>
#include <cstdlib>
#include <cstring>
#include <windows.h>

using namespace std;

#include "rlutil.h"
#include "funciones.h"
#include "funciones2.h"

using namespace rlutil;



int main()
{

    int L=0;

    while(true)
    {
        int puntMax;
        int opciones, rondas, puntosA, puntosB, tirada;
        int i, x;
        int totalPuntosA;
        int totalPuntosB;
        int puntajeAcumuladoA =0;
        int puntajeAcumuladoB =0;
        int puntajeA=0;
        int puntajeB=0;
        int vecRandomA[5];
        int vecRandomB[5];
        char nombrePrueba[30];
        char nombreA[30];
        char nombreB[30];
        char nombreMax[30];
        int ContCeroPuntosA=0,ContRestaPuntosA=0;


        setBackgroundColor(LIGHTBLUE);
        system("cls");
        recuadro(20,1,30,2,15,LIGHTBLUE);
        locate(27,2);
        cout<<"JUEGO DE DADOS 20"<<endl;
        cout<<endl;
                    Beep(1480,200);
                    Beep(1568,200);
                    Beep(1568,200);
                    Beep(1568,200);
                    Beep(739.99,200);
                    Beep(783.99,200);
                    Beep(783.99,200);
                    Beep(783.99,200);
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
        switch(opciones)
        {
        case 1:
        {

            recuadro(20,1,31,2,15,LIGHTBLUE);
            locate(22,2);
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

            for(x=0; x<rondas; x++)
            {
                if(x>0)
                {
                    recuadro(20,1,31,2,15,LIGHTBLUE);
                    locate(22,2);
                    cout<<"MODO DE JUEGO PARA 1 JUGADOR"<<endl;
                    cout<<endl;
                    cout<<" TURNO DE "<<nombreA<<"\t"<<"|"<<"RONDA NUMERO: "<<x+1<<"\t"<<"|"<<"PUNTAJE ACUMULADO: "<<puntajeAcumuladoA<<endl;
                    cout<<"--------------------------------------------------------------------"<<endl;
                }
                int MaxA, MaxA2, MaxA3, MaxA4, MaxA5;
                cout <<endl<< " INDIQUE CUANTOS PUNTOS QUIERE APOSTAR:" << endl;
                cin >> puntosA;
                system("cls");
                for(i=0; i<5; i++)
                {
                    recuadro(20,1,31,2,15,LIGHTBLUE);
                    locate(22,2);
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
                    Beep(300,200);
                    Beep(500,200);
                    Beep(700,200);
                        cargarAleatorio(vecRandomA,5,6);
                        for(int b=0; b<5; b++)
                        {
                            dados(b+1,vecRandomA[b],9);
                        }
                        MaxA=valorMaximoVector(vecRandomA, 5);

                    }


                    if(i==1)
                    {
                    Beep(300,200);
                    Beep(500,200);
                    Beep(700,200);
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
                    Beep(300,200);
                    Beep(500,200);
                    Beep(700,200);
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
                    Beep(300,200);
                    Beep(500,200);
                    Beep(700,200);
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
                    Beep(300,200);
                    Beep(500,200);
                    Beep(700,200);
                        cargarAleatorio(vecRandomA,1,6);
                        dados(1,vecRandomA[0],9);
                        MaxA5=vecRandomA[0];
                        dadosMax(1,MaxA,9);
                        dadosMax(2,MaxA2,9);
                        dadosMax(3,MaxA3,9);
                        dadosMax(4,MaxA4,9);

                    }
                    locate(15,25);
                    system("pause");
                    setBackgroundColor(LIGHTBLUE);
                    system("cls");
                }
                recuadro(20,1,31,2,15,LIGHTBLUE);
                locate(22,2);
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
                    Beep(300,200);
                    Beep(500,200);
                    Beep(700,200);
                    Beep(300,200);
                    Beep(500,200);
                    Beep(700,200);
                    Beep(300,200);
                    Beep(500,200);
                    Beep(700,200);
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
                    locate(15,25);
                    system("pause");
                    system("cls");
                }
                else
                {
                    ContRestaPuntosA++;
                    cout << " SU PUNTAJE ES DE: -" << puntosA << " PUNTOS " << endl;
                    puntajeAcumuladoA=puntajeAcumuladoA-puntosA;
                    locate(15,25);
                    system("pause");
                    system("cls");

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
            recuadro(20,1,31,2,15,LIGHTBLUE);
            locate(22,2);
            cout<<"MODO DE JUEGO PARA 1 JUGADOR"<<endl;
            cout<<endl;
                    Beep(300,100);
                    Beep(300,100);
                    Beep(300,100);
                    Beep(600,100);
                    Beep(700,100);
                    Beep(700,100);
                    Beep(800,100);
                    Beep(900,100);
                    Beep(1000,100);
                    Beep(1500,300);
            cout<<" NOMBRE DEL JUGADOR: "<<nombreA<<endl;
            cout<<" RONDAS SIN PUNTOS: "<<ContCeroPuntosA<<endl;
            cout<<" RONDAS RESTANDO PUNTOS: "<<ContRestaPuntosA<<endl;
            cout<<" PUNTAJE TOTAL ACUMULADO: "<<puntajeAcumuladoA<<endl;
            locate(15,25);
            system("pause");
            system("cls");
        }

        break;

        case 2:
        {
            recuadro(20,1,33,2,15,LIGHTBLUE);
            locate(22,2);
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

            for(x=0; x<rondas; x++)
            {
                system("cls");
                recuadro(20,1,33,2,15,LIGHTBLUE);
                locate(22,2);
                cout<<"MODO DE JUEGO PARA 2 JUGADORES"<<endl;
                cout<<endl;
                cout<<" TURNO DE "<<nombreA<<"\t"<<"|"<<"RONDA NUMERO: "<<x+1<<"\t"<<"|"<<"PUNTAJE ACUMULADO: "<<puntajeAcumuladoA<<endl;
                cout<<"--------------------------------------------------------------------"<<endl;

                int MaxA=0, MaxA2=0, MaxA3=0, MaxA4=0, MaxA5=0, MaxB=0, MaxB2=0, MaxB3=0, MaxB4=0, MaxB5=0;
                cout <<endl<< " INDIQUE CUANTOS PUNTOS QUIERE APOSTAR:" << endl;
                cin >> puntosA;

                system("cls");
                for(i=0; i<5; i++)
                {
                    system("cls");
                    recuadro(20,1,33,2,15,LIGHTBLUE);
                    locate(22,2);
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
                    Beep(300,200);
                    Beep(500,200);
                    Beep(700,200);
                        cargarAleatorio(vecRandomA,5,6);
                        for(int b=0; b<5; b++)
                        {
                            dados(b+1,vecRandomA[b],9);
                        }

                        MaxA=valorMaximoVector(vecRandomA, 5);

                    }

                    if(i==1)
                    {
                    Beep(300,200);
                    Beep(500,200);
                    Beep(700,200);
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
                    Beep(300,200);
                    Beep(500,200);
                    Beep(700,200);
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
                    Beep(300,200);
                    Beep(500,200);
                    Beep(700,200);
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
                    Beep(300,200);
                    Beep(500,200);
                    Beep(700,200);
                        cargarAleatorio(vecRandomA,1,6);
                        dados(1,vecRandomA[0],9);
                        MaxA5=vecRandomA[0];
                        dadosMax(1,MaxA,9);
                        dadosMax(2,MaxA2,9);
                        dadosMax(3,MaxA3,9);
                        dadosMax(4,MaxA4,9);

                    }
                    locate(15,25);
                    system("pause");
                    setBackgroundColor(LIGHTBLUE);
                    system("cls");
                }
                recuadro(20,1,33,2,15,LIGHTBLUE);
                locate(22,2);
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
                    Beep(300,200);
                    Beep(500,200);
                    Beep(700,200);
                    Beep(300,200);
                    Beep(500,200);
                    Beep(700,200);
                    Beep(300,200);
                    Beep(500,200);
                    Beep(700,200);
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
                    locate(15,25);
                    system("pause");
                    system("cls");
                }
                else
                {
                    cout << " SU PUNTAJE ES DE: -" << puntosA << " PUNTOS " << endl;
                    puntajeAcumuladoA=puntajeAcumuladoA-puntosA;
                    locate(15,25);
                    system("pause");
                    system("cls");

                }
                system("cls");
                recuadro(20,1,33,2,15,LIGHTBLUE);
                locate(22,2);
                cout<<"MODO DE JUEGO PARA 2 JUGADORES"<<endl;
                cout<<endl;
                cout<<" TURNO DE "<<nombreB<<"\t"<<"|"<<"RONDA NUMERO: "<<x+1<<"\t"<<"|"<<"PUNTAJE ACUMULADO: "<<puntajeAcumuladoB<<endl;
                cout<<"--------------------------------------------------------------------"<<endl;
                cout <<endl<< "INDIQUE CUANTOS PUNTOS QUIERE APOSTAR:" << endl;
                cin >> puntosB;
                system("cls");
                for(i=0; i<5; i++)
                {
                    recuadro(20,1,33,2,15,LIGHTBLUE);
                    locate(22,2);
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
                    Beep(300,200);
                    Beep(500,200);
                    Beep(700,200);
                        cargarAleatorio(vecRandomB,5,6);
                        for(int b=0; b<5; b++)
                        {
                            dados(b+1,vecRandomB[b],9);
                        }
                        MaxB=valorMaximoVector(vecRandomB, 5);

                    }

                    if(i==1)
                    {
                    Beep(300,200);
                    Beep(500,200);
                    Beep(700,200);
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
                    Beep(300,200);
                    Beep(500,200);
                    Beep(700,200);
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
                    Beep(300,200);
                    Beep(500,200);
                    Beep(700,200);
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
                    Beep(300,200);
                    Beep(500,200);
                    Beep(700,200);
                        cargarAleatorio(vecRandomB,1,6);
                        dados(1,vecRandomB[0],9);
                        MaxB5=vecRandomB[0];
                        dadosMax(1,MaxB,9);
                        dadosMax(2,MaxB2,9);
                        dadosMax(3,MaxB3,9);
                        dadosMax(4,MaxB4,9);

                    }
                    locate(15,25);
                    system("pause");
                    setBackgroundColor(LIGHTBLUE);
                    system("cls");
                }
                recuadro(20,1,33,2,15,LIGHTBLUE);
                locate(22,2);
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
                    Beep(300,200);
                    Beep(500,200);
                    Beep(700,200);
                    Beep(300,200);
                    Beep(500,200);
                    Beep(700,200);
                    Beep(300,200);
                    Beep(500,200);
                    Beep(700,200);
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
                    locate(15,25);
                    system("pause");
                    system("cls");
                }
                else
                {
                    cout << " SU PUNTAJE ES DE: -" << puntosB << " PUNTOS " << endl;
                    puntajeAcumuladoB=puntajeAcumuladoB-puntosB;
                    locate(15,25);
                    system("pause");
                    system("cls");
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
            recuadro(20,1,33,2,15,LIGHTBLUE);
            locate(22,2);
            cout<<"MODO DE JUEGO PARA 2 JUGADORES"<<endl;
            cout<<endl;
            cout<<"--------------------------------------------------------------------"<<endl;
            if(puntajeAcumuladoA>puntajeAcumuladoB)
            {
                    Beep(300,100);
                    Beep(300,100);
                    Beep(300,100);
                    Beep(600,100);
                    Beep(700,100);
                    Beep(700,100);
                    Beep(800,100);
                    Beep(900,100);
                    Beep(1000,100);
                    Beep(1500,300);
                cout<<" EL GANADOR ES EL JUGADOR: "<<nombreA<<endl;
                cout<<" PUNTAJE TOTAL ACUMULADO: "<<puntajeAcumuladoA<<endl;
            }
            if(puntajeAcumuladoB>puntajeAcumuladoA)
            {
                    Beep(300,100);
                    Beep(300,100);
                    Beep(300,100);
                    Beep(600,100);
                    Beep(700,100);
                    Beep(700,100);
                    Beep(800,100);
                    Beep(900,100);
                    Beep(1000,100);
                    Beep(1500,300);
                cout<<" EL GANADOR ES EL JUGADOR: "<<nombreB<<endl;
                cout<<" PUNTAJE TOTAL ACUMULADO: "<<puntajeAcumuladoB<<endl;
            }
            if(puntajeAcumuladoA==puntajeAcumuladoB)
            {
                    Beep(300,100);
                    Beep(500,100);
                    Beep(700,100);
                    Beep(300,100);
                    Beep(500,100);
                    Beep(700,100);
                    Beep(300,100);
                    Beep(500,100);
                    Beep(700,100);
                cout<<" HUBO UN EMPATE CON "<<puntajeAcumuladoA<<" PUNTOS"<<endl;
            }

            locate(15,25);
            system("pause");
            system("cls");
        }
        break;

        case 3:
            recuadro(20,1,23,2,15,LIGHTBLUE);
            locate(23,2);
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
                    Beep(300,100);
                    Beep(300,100);
                    Beep(300,100);
                    Beep(600,100);
                    Beep(700,100);
                    Beep(700,100);
                    Beep(800,100);
                    Beep(900,100);
                    Beep(1000,100);
                    Beep(1500,300);

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
            break;

        case 4:
        {
            int puntajeAcumuladoPrueba=0, puntosPrueba=0, puntajePrueba=0, Max, Max2, Max3, Max4, Max5, puntosPruebaTotal, ContCeroPuntosPrueba=0;
            int ContRestaPuntosPrueba=0;
            int vecPrueba[5];
            setBackgroundColor(BLACK);
            system("cls");
            recuadro(20,1,24,2,15,0);
            locate(26,2);
            cout<<"MODO SIMULADO"<<endl;
            cout<<endl;

            cout << " BIENVENIDO AL MODO SIMULADO, AQUI PODRA CARGAR LOS VALORES DE LOS DADOS DE MANERA MANUAL" << endl;
            cout << " COMENCEMOS" << endl;
            cout<<"*************************************************"<<endl<<endl;
            cout << " INGRESE SU NOMBRE: " << endl;
            ponerPalabra(nombrePrueba);
            cout << " INGRESEN LA CANTIDAD DE RONDAS QUE DESEAN JUGAR: " << endl;
            cin >> rondas;
            while(rondas<1)
            {
                cout<<" INGRESE UN NUMERO DE RONDAS VALIDO (MAYOR QUE CERO)";
                cin>>rondas;
            }
            for(x=0; x<rondas; x++)
            {
                int Max, Max2, Max3, Max4, Max5;
                if(x>0)
                {
                    recuadro(20,1,24,2,15,0);
                    locate(26,2);
                    cout<<"MODO SIMULADO"<<endl;
                    cout<<endl;
                    cout<<" TURNO DE "<<nombrePrueba<<"\t"<<"|"<<"RONDA NUMERO: "<<x+1<<"\t"<<"|"<<"PUNTAJE ACUMULADO: "<<puntajeAcumuladoPrueba<<endl;
                    cout<<"--------------------------------------------------------------------"<<endl;
                }
                cout<<" INDIQUE CUANTOS PUNTOS QUIERE APOSTAR:"<<endl;
                cin>>puntosPrueba;
                system("cls");
                for(i=0; i<5; i++)
                {
                    recuadro(20,1,24,2,15,0);
                    locate(26,2);
                    cout<<"MODO SIMULADO"<<endl;
                    cout<<endl;
                    cout<<" TURNO DE "<<nombrePrueba<<"\t"<<"|"<<"RONDA NUMERO: "<<x+1<<"\t"<<"|"<<"PUNTAJE ACUMULADO: "<<puntajeAcumuladoPrueba<<endl;
                    cout<<"--------------------------------------------------------------------"<<endl;
                    cout << " TIRADA NUMERO " << i+1 << endl;

                    ponerCero(vecPrueba,5);
                    locate(2,20);
                    cout<<"MAXIMOS DE TIRADAS ANTERIORES: "<<endl;
                    locate(1,5);
                    if(i==0)
                    {
                        cargarVector(vecPrueba,5);
                        for(int b=0; b<5; b++)
                        {
                            dados(b+1,vecPrueba[b],0);
                        }
                        Max=valorMaximoVector(vecPrueba, 5);

                    }


                    if(i==1)
                    {
                        cargarVector(vecPrueba,4);
                        for(int b=0; b<4; b++)
                        {
                            dados(b+1,vecPrueba[b],0);
                        }
                        Max2=valorMaximoVector(vecPrueba, 4);
                        locate(2,20);
                        dadosMax(1,Max,0);

                    }

                    if(i==2)
                    {
                        cargarVector(vecPrueba,3);
                        for(int b=0; b<3; b++)
                        {
                            dados(b+1,vecPrueba[b],0);
                        }
                        Max3=valorMaximoVector(vecPrueba, 3);
                        dadosMax(1,Max,0);
                        dadosMax(2,Max2,0);
                    }
                    if(i==3)
                    {
                        cargarVector(vecPrueba,2);
                        for(int b=0; b<2; b++)
                        {
                            dados(b+1,vecPrueba[b],0);
                        }
                        Max4=valorMaximoVector(vecPrueba, 2);
                        dadosMax(1,Max,0);
                        dadosMax(2,Max2,0);
                        dadosMax(3,Max3,0);
                    }
                    if(i==4)
                    {
                        cargarVector(vecPrueba,1);
                        dados(1,vecPrueba[0],0);
                        Max5=vecPrueba[0];
                        dadosMax(1,Max,0);
                        dadosMax(2,Max2,0);
                        dadosMax(3,Max3,0);
                        dadosMax(4,Max4,0);
                        locate(2,20);
                        cout<<"MAXIMOS DE TIRADAS ANTERIORES: "<<endl;
                    }
                    locate(15,25);
                    system("pause");
                    setBackgroundColor(BLACK);
                    system("cls");
                }
                recuadro(20,1,24,2,15,0);
                locate(26,2);
                cout<<"MODO SIMULADO"<<endl;
                cout<<endl;
                cout<<" TURNO DE "<<nombrePrueba<<"\t"<<"|"<<"RONDA NUMERO: "<<x+1<<"\t"<<"|"<<"PUNTAJE ACUMULADO: "<<puntajeAcumuladoPrueba<<endl;
                cout<<"--------------------------------------------------------------------"<<endl;
                puntosPruebaTotal=Max+Max2+Max3+Max4+Max5;
                locate(2,6);
                cout << "LA SUMATORIA DE MAXIMOS ES DE: " << puntosPruebaTotal << endl;

                if(puntosPruebaTotal>=20)
                {
                    int numGenPrueba;
                    if(puntosPruebaTotal>=25)
                    {
                        numGenPrueba=6;
                    }
                    else
                    {
                        numGenPrueba=puntosPruebaTotal-19;
                    }
                    locate(15,12);
                    cout<< "*****  TIRO DE PUNTAJE  ******" << endl;
                    locate(2,13);
                    cout << "EL NUMERO GENERADOR DE PUNTOS ES "<<numGenPrueba<< endl;
                    cargarVector(vecPrueba,5);
                    for(int b=0; b<5; b++)
                    {
                        if(vecPrueba[b]==numGenPrueba)
                        {
                            dadosSimulado(b+1,vecPrueba[b],10);
                        }
                        else
                        {
                            dadosSimulado(b+1,vecPrueba[b],0);
                        }
                    }

                    puntajePrueba=puntosPrueba*contarNumerosRepetidos(vecPrueba, numGenPrueba, 6);
                    if(puntajePrueba==0)
                    {
                        ContCeroPuntosPrueba++;
                    }
                    setBackgroundColor(BLACK);
                    locate(2,14);
                    cout << "SU PUNTAJE ES DE: " << puntajePrueba << " PUNTOS " << endl;
                    puntajeAcumuladoPrueba+=puntajePrueba;
                    locate(15,27);
                    system("pause");
                    system("cls");
                }
                else
                {
                    ContRestaPuntosPrueba++;
                    cout << " SU PUNTAJE ES DE: -" << puntosPrueba << " PUNTOS " << endl;
                    puntajeAcumuladoPrueba=puntajeAcumuladoPrueba-puntosPrueba;
                    locate(15,25);
                    system("pause");
                    system("cls");

                }
            }

            recuadro(20,1,24,2,15,0);
            locate(26,2);
            cout<<"MODO SIMULADO"<<endl;
            cout<<endl;
            cout<<" NOMBRE DEL JUGADOR: "<<nombrePrueba<<endl;
            cout<<" RONDAS SIN PUNTOS: "<<ContCeroPuntosPrueba<<endl;
            cout<<" RONDAS RESTANDO PUNTOS: "<<ContRestaPuntosPrueba<<endl;
            cout<<" PUNTAJE TOTAL ACUMULADO: "<<puntajeAcumuladoPrueba<<endl;
            locate(15,25);
            system("pause");
            system("cls");
        }

        break;

        case 5:{
            setBackgroundColor(BLACK);
            system("cls");
            recuadro(20,1,24,2,15,0);
            locate(26,2);
            cout<<"Reglamento";
            cout<<endl<<endl<<" - 20 es un juego que utiliza 5 dados, y que puede ser jugado por uno o varios jugadores."<<endl;
            cout<<" - Nuestra version sera para 1 o 2 jugadores."<<endl;
            cout<<" - El juego consiste en un conjunto de rondas en las que se analizan los valores obtenidos al tirar los dados."<<endl;
            cout<<" - En la version que se propone la cantidad de rondas se establece cuando el juego empieza(se ingresa por teclado)."<<endl;

            cout<<" - Al inicio de cada ronda, y cuando le toca el turno, cada jugador debe indicar cuantos puntos quiere apostar en esa ronda."<<endl;
            cout<<" - De acuerdo a los valores que obtenga en las tiradas de dados, esos puntos apostados podran sumarse o restarse a su puntaje total."<<endl;
            cout<<" - Cada ronda consiste en 5 tiradas de dados de la siguiente manera:"<<endl;
            cout<<"     ~ Tirada 1: se tiran los 5 dados. Se analiza el valor de cada dado y se retira el que tiene mayor puntaje."<<endl;
            cout<<"     ~ Tirada 2: se tiran 4 dados. Se analiza el valor de cada dado y se retira el que tiene mayor puntaje."<<endl;
            cout<<"     ~ Tirada 3: se tiran 3 dados. Se analiza el valor de cada dado y se retira el que tiene mayor puntaje."<<endl;
            cout<<"     ~ Tirada 4: se tiran 2 dados. Se analiza el valor de cada dado y se retira el que tiene mayor puntaje."<<endl;
            cout<<"     ~ Tirada 5: se tira el dado restante."<<endl;
            locate(15,25);
            system("pause");
            system ("cls");
            cout<<" - Luego de las 5 tiradas se suman los valores de los 5 dados con los puntajes maximos de cada tirada. ."<<endl;
            cout<<" - Si la suma es mayor o igual a 20 el jugador continua."<<endl;
            cout<<" - Si la suma es menor a 20 el jugador pierde los puntos apostados para esa ronda, que se restan al puntaje total que tenia hasta ese momento."<<endl;
            cout<<" - Si la suma es mayor o igual a 20, el jugador tiene derecho a un nuevo tiro de los 5 dados."<<endl;
            cout<<" - Este tiro se denomina Tiro de Puntaje, y puede permitirle sumar puntos."<<endl;
            cout<<" - La cantidad de puntos surge de multiplicar los puntos apostados al empezar la ronda por la cantidad de dados con un valor igual al numero generador de puntos."<<endl;
            cout<<" - Este numero se obtiene de la siguiente tabla:"<<endl;
            cout<<" - 20 -> 1"<<endl<<" - 21 -> 2"<<endl<<" - 22 -> 3"<<endl<<" - 23 -> 4"<<endl<<" - 24 -> 5"<<endl<<" - 25 o mayor -> 6"<<endl;

        }

        break;

        case 0:
        {
            cout << " FIN DEL PROGRAMA, GRACIAS POR JUGAR!" << endl;
            cout << "\t" << endl;
            cout <<"PRODUCIDO POR: " << endl;
            cout << "-HERNAN FIGUEROA" << endl;
            cout << "-JULIAN MIGUEL" << endl;
            cout << "-JOAQUIN MATEO BONET" << endl;
            cout << "\t" << endl;
            cout << (char) 169 << endl;
                    Beep(739.99,200);
                    Beep(783.99,200);
                    Beep(783.99,200);
                    Beep(783.99,200);
                    Beep(1568,200);
                    Beep(1568,200);
                    Beep(1568,200);
                    Beep(1480,200);
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
