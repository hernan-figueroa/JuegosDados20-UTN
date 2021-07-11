#ifndef MODOSIMULADO_H_INCLUDED
#define MODOSIMULADO_H_INCLUDED

void modoSimulado(char nombreMax[],int &puntMax,int &L)
{
    char nombrePrueba[30];
    int rondas,puntajeAcumuladoPrueba=0, puntosPrueba=0, puntajePrueba=0, Max, Max2, Max3, Max4, Max5, puntosPruebaTotal, ContCeroPuntosPrueba=0;
    int ContRestaPuntosPrueba=0;
    int vecPrueba[5];

    colorFondo(0);
    titulo(0);
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
    for(int x=0; x<rondas; x++)
    {
        if(x>0)
        {
            titulo(0);;
            cout<<"MODO SIMULADO"<<endl;
            cout<<endl;
            cout<<" TURNO DE "<<nombrePrueba<<"\t"<<"|"<<"RONDA NUMERO: "<<x+1<<"\t"<<"|"<<"PUNTAJE ACUMULADO: "<<puntajeAcumuladoPrueba<<endl;
            cout<<"--------------------------------------------------------------------"<<endl;
        }
        cout<<" INDIQUE CUANTOS PUNTOS QUIERE APOSTAR:"<<endl;
        cin>>puntosPrueba;
        system("cls");
        for(int i=0; i<5; i++)
        {
            titulo(0);
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
            setBackgroundColor(0);
            pausa();
        }
        titulo(0);
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

            puntajePrueba=puntosPrueba*contarNumerosRepetidos(vecPrueba, numGenPrueba, 5);
            if(puntajePrueba==0)
            {
                ContCeroPuntosPrueba++;
            }
            setBackgroundColor(BLACK);
            locate(2,14);
            cout << "SU PUNTAJE ES DE: " << puntajePrueba << " PUNTOS " << endl;
            puntajeAcumuladoPrueba+=puntajePrueba;
            pausa();
        }
        else
        {
            ContRestaPuntosPrueba++;
            cout << " SU PUNTAJE ES DE: -" << puntosPrueba << " PUNTOS " << endl;
            puntajeAcumuladoPrueba=puntajeAcumuladoPrueba-puntosPrueba;
            pausa();

        }
    }
    if(L==0)
    {
        strcpy(nombreMax,nombrePrueba);
        puntMax=puntajeAcumuladoPrueba;
        L=1;
    }
    else
    {
        if(puntajeAcumuladoPrueba>puntMax)
        {
            puntMax=puntajeAcumuladoPrueba;
            strcpy(nombreMax,nombrePrueba);
        }
    }
    titulo(0);
    cout<<"MODO SIMULADO"<<endl;
    cout<<endl;
    cout<<" NOMBRE DEL JUGADOR: "<<nombrePrueba<<endl;
    cout<<" RONDAS SIN PUNTOS: "<<ContCeroPuntosPrueba<<endl;
    cout<<" RONDAS RESTANDO PUNTOS: "<<ContRestaPuntosPrueba<<endl;
    cout<<" PUNTAJE TOTAL ACUMULADO: "<<puntajeAcumuladoPrueba<<endl;

}

#endif // MODOSIMULADO_H_INCLUDED
