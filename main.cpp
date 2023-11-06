#include "Torneo.h"
#include "Torneo.cpp"


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
    t1.showInfoTorneo();
    t1.insertJugador("San Pancho", jugador1);
    t1.insertJugador("Toros Tec", jugador2);
    t1.insertJugador("Phoenix", jugador3);
    cout<<"ok";
    return 0;
}