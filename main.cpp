#include "Torneo.h"


void imprimirJugador(const Torneo::Jugador& jugador) {
    cout << "Nombre: " << jugador.nombreJugador << endl;
    cout << "Numero de ID: " << jugador.numeroId << endl;
    cout << "Posicion: " << jugador.posicion << endl;
    cout << "Average Acumulado: " << jugador.averageAcc << endl;
}

void imprimirEquipo(const Torneo::Equipo& equipo) {
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
    
    Torneo::Equipo equipo1 = {"San Pancho", 4, 2, 1, 17, nullptr, 0};
    Torneo::Equipo equipo2 = {"Toros Tec", 5, 1, 2, 21, nullptr, 0};
    Torneo::Equipo equipo3 = {"Phoenix", 7, 0, 3, 25, nullptr, 0};
    Torneo::Jugador jugador1 = {"Juan", 1, "Delantero", 100};
    //Torneo::Jugador jugador2 = {"Pedro", 2, "Defensa", 90};
    //Torneo::Jugador jugador3 ={"Luis", 3, "Portero", 80};
    Torneo t1(3,3);
    t1.insertEquipo(equipo1);
    t1.insertEquipo(equipo2);
    t1.insertEquipo(equipo3);
    imprimirEquipo(t1.getInfoEquipo("San Pancho"));
    //t1.insertJugador("San Pancho", jugador1);
    //imprimirEquipo(t1.getInfoEquipo("San Pancho"));
    t1.changeInfoEquipo("San Pancho", "juegosGanados", "8");
    t1.deleteEquipo("San Pancho");
    t1.showInfoTorneo();
    cout<<"ok"<< endl;
    return 0;
}
