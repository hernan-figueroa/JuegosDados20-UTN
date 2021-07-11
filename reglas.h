#ifndef REGLAS_H_INCLUDED
#define REGLAS_H_INCLUDED

#include "funcionesGraficas.h"


void reglas(void);


void reglas()
{
    colorFondo(0);

    titulo(0);
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

    pausa();

    titulo(0);
    cout<<"Reglamento";


    cout<<endl<<endl<<" - Luego de las 5 tiradas se suman los valores de los 5 dados con los puntajes maximos de cada tirada. ."<<endl;
    cout<<" - Si la suma es mayor o igual a 20 el jugador continua."<<endl;
    cout<<" - Si la suma es menor a 20 el jugador pierde los puntos apostados para esa ronda, que se restan al puntaje total que tenia hasta ese momento."<<endl;
    cout<<" - Si la suma es mayor o igual a 20, el jugador tiene derecho a un nuevo tiro de los 5 dados."<<endl;
    cout<<" - Este tiro se denomina Tiro de Puntaje, y puede permitirle sumar puntos."<<endl;
    cout<<" - La cantidad de puntos surge de multiplicar los puntos apostados al empezar la ronda por la cantidad de dados con un valor igual al numero generador de puntos."<<endl;
    cout<<" - Este numero se obtiene de la siguiente tabla:"<<endl;
    cout<<" - 20 -> 1"<<endl<<" - 21 -> 2"<<endl<<" - 22 -> 3"<<endl<<" - 23 -> 4"<<endl<<" - 24 -> 5"<<endl<<" - 25 o mayor -> 6"<<endl;


}

#endif // REGLAS_H_INCLUDED
