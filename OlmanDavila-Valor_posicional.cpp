#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <string.h>
#include <iomanip>

using namespace std;

void aleatorio(int&, int&, int&);

void preguntas(int&, int&, int&);

void limpiar();

void titulo();

int main()
{
   int numero, centenas, decenas, unidades,c,d,u;
   int jugador;
   int puntosj1 = 0, puntosj2 = 0;
   int ronda = 0;
   char respuesta = 'N';
   char j1[15], j2[15];

   //Funcion para que el aleatorio cambie sacada de cplusplus.com
   srand(time(0));

   //Funcion para cambiar el titulo y el color a la consola sacada de cplusplus.com
   system("title JUEGO DE VALOR POSICIONAL by Olman Davila Solano");
   system("color 7d");

   do{

    // Se empieza guardando los nombres de los jugadores

    //Nombres de los jugadores
    //Se hace una función para imprimir el titulo y ahorrar codigo
    titulo();

    //Se tabulo con setw para mejorar la vista en consola
    cout << right << setw(55) << "Digite el nombre del jugador 1: " ;
    cin >> j1;

    cout << right << setw(55) << "Digite el nombre del jugador 2: " ;
    cin >> j2;

    //Para decoración se decide pasar a mayusculas los nombres
    //Pasar a mayusculas los nombres
    strupr(j1);
    strupr(j2);

    /*Se hace una funcion con system("pause) y system("cls") para pausar y limpiar pantalla
    sacada de cplusplus.com*/
    limpiar();

    titulo();
    //Titulo de bienvenida
    cout << right << setw(37) << "¡BIENVENIDOS " << j1 <<  " Y " << j2 << "!" << endl;
    cout << right << setw(87) << "Se seleccionara de manera aleatoria el primer jugador, ¡suerte!" << endl;
    limpiar();

    //Se reinician los puntajes para evitar acumulaciones cada que el juego empiece
    //Reiniciar puntos
    ronda = 0;
    puntosj1 = 0;
    puntosj2 = 0;

    //Procesp para sacar el primer jugador de manera aleatoria con rand()
    jugador = 1 + rand()%2;
    if(jugador == 1){

    titulo();
    cout << right << setw(46) << "¡¡Jugaras de primero " << j1 <<"!!" <<endl;
    }else{

        titulo();
        cout << right << setw(46) << "¡¡Jugaras de primero " << j2 << "!!"<<endl;
    }
    limpiar();

    //Se empieza el juego con un do while y condicionales para intercambiar turnos o continuar el mismo jugador
   do{

    //Jugador 1/////////////////////////////////////////////////////////
    if(jugador == 1){

    titulo();
    //Imprimir ronda, puntaje y turno
    cout << right << setw(30) << "Ronda #" << ronda << endl;
    cout << right << setw(34) << "Puntaje de " << j1 << " : " <<puntosj1 << endl;
    cout << right << setw(73) << "Turno de " << j1 << endl;

        //Sacar el numero aleatorio, descomponerlo y imprimirlo
        aleatorio(c,d,u);

        //Pedir las d,c,u al usuario
        preguntas(centenas,decenas,unidades);

        //Condicional de ganar o perder
       if(centenas == c && decenas == d && unidades == u){
            //Si se acierta se sumara puntos a un jugador y la ronda siempre sumara
            puntosj1++;
            ronda++;
            cout << right << setw(25) << ":D" << endl;
            cout << right << setw(40) << "!!Ganas un punto " <<j1 << ", continua jugando!!" << endl;
            limpiar();

             }else{
                cout << right << setw(25) << ":(" << endl;
                cout << right << setw(37) << "!!Has fallado " <<j1 << ", perdiste el turno!!" << endl;
                ronda++;
                limpiar();

                //Con este proceso se cambiara la condicional, para cambiar de jugador
                jugador = 2;
            }
        }

        //Jugador 2//////////////////////////////////////////////////////////////////////////////////////
        if(jugador == 2){

        titulo();
        cout << right << setw(30) << "Ronda #" << ronda << endl;
        cout << right << setw(34) << "Puntaje de " << j2 << ": " <<puntosj2 << endl;
        cout << right << setw(73) << "Turno de " << j2 << endl;

        //Juego;
        //Sacar el numero aleatorio, descomponerlo y imprimirlo
        aleatorio(c,d,u);

        //Pedir las d,c,u al usuario
        preguntas(centenas,decenas,unidades);

        //Condicional de ganar o perder
        if(centenas == c && decenas == d && unidades == u){

            puntosj2++;
            ronda++;
            cout << right << setw(25) << ":D" << endl;
            cout << right << setw(40) << "!!Ganas un punto " <<j2 << ", continua jugando!!" << endl;
            limpiar();

            }else{

                cout << right << setw(25) << ":(" << endl;
                cout << right << setw(37) << "!!Has fallado " <<j2 << ",perdiste el turno!!" << endl;
                ronda++;
                limpiar();
                jugador = 1;
                }
    }

    //El juego solo tendra 20 rondas
   }while(ronda <= 20);

   //Condicional de ganador o empate y imprimirlo
   titulo();

   if(puntosj1 > puntosj2){
    cout << right << setw(69) << "El ganador es " << j1 << " con " << puntosj1 <<" puntos!!" << endl;

   }
   if(puntosj1 < puntosj2){
   cout << right << setw(69) << "El ganador es " << j2 << " con " << puntosj2 <<" puntos!!" << endl;

   }
   if(puntosj1 == puntosj2){
    cout << right << setw(55) << j1 << " y " << j2 <<" han empatado con " << puntosj1 << " puntos cada uno!!" << endl;

    }

    //Mensaje de salida
     cout << right << setw(44) << "Desea volver a jugar?" << endl;
     cout << right << setw(70) << "Digite S para iniciar de nuevo o N para salir: ";
     cin >> respuesta;
     respuesta = toupper(respuesta);

     limpiar();

   }while(respuesta=='S');

    return 0;
}

void aleatorio(int& c, int& d, int& u){

int numero,aux;

    numero = 1 + rand()%999;

    //Se saca el modular para ir descomponiendo el numero, y asi sacar las CDU
   //Unidades
    u = numero % 10;

    //Decenas
    aux = numero - u;
    aux = aux % 100;
    d = aux/10;

    //Centenas
    aux = numero - d*10 - u;
    c = aux/100;

    cout << right << setw(32) << "NUMERO: [" << c << d <<u << "]";


}

void preguntas(int& centenas, int& decenas,int& unidades){

cout << "\n";
cout << right << setw(64) << "Digite cuantas centenas tiene el numero: " ;
cin >> centenas;

cout << "\n";
cout << right << setw(63) << "Digite cuantas decenas tiene el numero: " ;
cin >> decenas;

cout << "\n";
cout << right << setw(64) << "Digite cuantas unidades tiene el numero: " ;
cin >> unidades;
cout << "\n";

}

void limpiar(){
system("PAUSE");
system("CLS");
}

void titulo(){
cout << right << setw(110) << "---------------------------------------------------------------------------------------" << endl;
cout << right << setw(110) << "---------------------------------------------------------------------------------------" << endl;
cout << right << setw(90) << "<<<<<<JUEGO DE VALOR POSICIONAL>>>>>>" << endl;
cout << right << setw(110) << "---------------------------------------------------------------------------------------" << endl;
cout << right << setw(110) << "---------------------------------------------------------------------------------------" << endl;

}
