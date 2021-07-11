#ifndef FUNCIONESGRAFICAS_H_INCLUDED
#define FUNCIONESGRAFICAS_H_INCLUDED

void titulo(int color);
void pausa(void);
void colorFondo(int color);

void colorFondo(int color)
{
    setBackgroundColor(color);
    system("cls");
}

void pausa()
{
    locate(15,25);
    system("pause");
    system ("cls");
}

void titulo(int color)
{

    recuadro(20,1,40,2,15,color);
    locate(26,2);
}

#endif // FUNCIONESGRAFICAS_H_INCLUDED
