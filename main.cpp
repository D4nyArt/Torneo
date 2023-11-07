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
}


int main(){
    Torneo::Equipo equipo1;
    equipo1.nombreEquipo = "San Pancho";
    equipo1.juegosGanados = 4;
    equipo1.juegosPerdidos = 2;
    equipo1.juegosEmpatados = 1;
    equipo1.puntosAcc = 17;
    equipo1.arrayJugadores = new Torneo::Jugador[3];
    equipo1.indexLibreJugadores = 0;
    Torneo::Equipo equipo2;
    equipo2.nombreEquipo = "Toros Tec";
    equipo2.juegosGanados = 5;
    equipo2.juegosPerdidos = 1;
    equipo2.juegosEmpatados = 2;
    equipo2.puntosAcc = 21;
    equipo2.arrayJugadores = new Torneo::Jugador[3];
    equipo2.indexLibreJugadores = 0;
    Torneo::Equipo equipo3;
    equipo3.nombreEquipo = "Phoenix";
    equipo3.juegosGanados = 7;
    equipo3.juegosPerdidos = 0;
    equipo3.juegosEmpatados = 3;
    equipo3.puntosAcc = 25;
    equipo3.arrayJugadores = new Torneo::Jugador[3];
    equipo3.indexLibreJugadores = 0;
    Torneo::Equipo equipo4;
    equipo3.nombreEquipo = "Atlantec";
    equipo3.juegosGanados = 9;
    equipo3.juegosPerdidos = 1;
    equipo3.juegosEmpatados = 1;
    equipo3.puntosAcc = 28;
    equipo3.arrayJugadores = new Torneo::Jugador[3];
    equipo3.indexLibreJugadores = 0;
    Torneo::Jugador jugador1 = {"Juan", 1, "Delantero", 10};
    Torneo::Jugador jugador2 = {"Pedro", 2, "Defensa", 15};
    Torneo::Jugador jugador3 ={"Luis", 3, "Portero", 11};
    Torneo::Jugador jugador4 ={"Mario", 4, "Lateral", 12};
    Torneo t1(3,3);
    cout << "Insercion Equipos" << endl;
    t1.insertEquipo(equipo1);
    t1.insertEquipo(equipo2);
    t1.insertEquipo(equipo3);
    t1.insertEquipo(equipo4);
    cout << "Insercion Jugadores" << endl;
    t1.insertJugador("San Pancho", jugador1);
    t1.insertJugador("San Pancho", jugador2);
    t1.insertJugador("San Pancho", jugador3);
    t1.insertJugador("San Pancho", jugador4);
    t1.showInfoTorneo();
    cout << "Impresion Jugador y Equipo" << endl;
    imprimirEquipo(t1.getInfoEquipo("San Pancho"));
    imprimirJugador(t1.getInfoJugador("Pedro"));
    cout << "Cambio Jugador y Equipo" << endl;
    t1.changeInfoEquipo("San Pancho", "juegosGanados", "8");
    imprimirEquipo(t1.getInfoEquipo("San Pancho"));
    t1.changeInfoJugador("Pedro", "averageAcc", "80");
    imprimirJugador(t1.getInfoJugador("Pedro"));
    cout << "Delete Jugador y Equipo" << endl;
    t1.deleteJugador("Pedro");
    t1.deleteEquipo("San Pancho");
    t1.showInfoTorneo();
    return 0;
}
