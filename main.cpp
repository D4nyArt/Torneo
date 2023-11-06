#include "Torneo.h"
#include "Torneo.cpp"

void imprimirJugador(const Jugador& jugador) {
    cout << "Nombre: " << jugador.nombreJugador << endl;
    cout << "Número de ID: " << jugador.numeroId << endl;
    cout << "Posición: " << jugador.posicion << endl;
    cout << "Average Accuracy: " << jugador.averageAcc << endl;
}

void imprimirEquipo(const Equipo& equipo) {
    cout << "Nombre del Equipo: " << equipo.nombreEquipo << endl;
    cout << "Juegos Ganados: " << equipo.juegosGanados << endl;
    cout << "Juegos Perdidos: " << equipo.juegosPerdidos << endl;
    cout << "Juegos Empatados: " << equipo.juegosEmpatados << endl;
    cout << "Puntos Acumulados: " << equipo.puntosAcc << endl;
    
    cout << "Jugadores en el Equipo:" << endl;
    for (int i = 0; i < equipo.indexLibreJugadores; ++i) {
        cout << "Jugador #" << i + 1 << ":" << endl;
        imprimirJugador(equipo.arrayJugadores[i]);
        cout << "-----------------------" << endl;
    }
}

int main(){
    Equipo equipo1 = {"San Pancho", 4, 2, 1, 17};
    Equipo equipo2 = {"Toros Tec", 5, 1, 2, 21};
    Equipo equipo3 = {"Phoenix", 7, 0, 3, 25};
    Jugador jugador1 = {"Juan", 1, "Delantero", 100};
    Jugador jugador2 = {"Pedro", 2, "Defensa", 90};
    Jugador jugador3 = {"Luis", 3, "Portero", 80};
    Torneo t1(3,3);
    t1.insertEquipo(equipo1);
    t1.insertEquipo(equipo2);
    t1.insertEquipo(equipo3);
    imprimirEquipo(t1.getInfoEquipo("San Pancho"));
    //t1.insertJugador("San Pancho", jugador1);
    t1.showInfoTorneo();
    return 0;
}
