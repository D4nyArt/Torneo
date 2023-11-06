#include "Torneo.h"


Torneo::Torneo(int num_equipos, int num_jugadores) {
    N = num_equipos;
    M = num_jugadores;
    indexLibreEquipos = 0;

    arrayEquipos = new Equipo[num_equipos];

    for (int i = 0; i < num_equipos; i++) {
        arrayEquipos[i].arrayJugadores = new Jugador[num_jugadores];
        arrayEquipos[i].indexLibreJugadores = 0;
    }
}

Torneo::~Torneo(){
    for (int i = 0; i < N; i++) {
        delete[] arrayEquipos[i].arrayJugadores;
    }

    delete[] arrayEquipos;
}

void Torneo::insertEquipo(Equipo equipoinsertado){
    if(indexLibreEquipos >= N){
        cout << "No hay espacio para insertar mas equipos" << endl;
        return;
    } else{
        arrayEquipos[indexLibreEquipos] = equipoinsertado;
        indexLibreEquipos++;
    }
}

void Torneo::insertJugador(string equipoDelJugador, Jugador jugadorInsertado){
    if(indexLibreEquipos==0){
        cout << "No hay equipos registrados" << endl;
        return;
    }else {
        for(int i=0; i<indexLibreEquipos; i++){
            if(equipoDelJugador == arrayEquipos[i].nombreEquipo){
                if(arrayEquipos[i].indexLibreJugadores >= M){
                    cout << "No hay espacio para insertar mas jugadores" << endl;
                    return;
                }else{
                    cout << arrayEquipos[i].indexLibreJugadores;
                    arrayEquipos[i].indexLibreJugadores++;
                    return;
                }
            }
        }
    }
}

Equipo Torneo::getInfoEquipo(string nombreEquipoConsultado){
    for(int i=0; i < N; i++){
        if(nombreEquipoConsultado == arrayEquipos[i].nombreEquipo){
            return arrayEquipos[i];
        }
    }
    cout << "No se encontro el equipo especificado" << endl;
    return Equipo{};
}

Jugador Torneo::getInfoJugador(string nombreJugadorConsultado){
    for(int i=0; i < N; i++){
        for(int j=0; j < M; j++){
            if(nombreJugadorConsultado == arrayEquipos[i].arrayJugadores[j].nombreJugador){
                return arrayEquipos[i].arrayJugadores[j];
            }
        }
    }
    cout << "No se encontro el jugador especificado" << endl;
    return Jugador{};
}

void Torneo::changeInfoEquipo(){  
    cout << "hello";
}

void Torneo::changeInfoJugador(){  
    cout << "world";
}

void Torneo::deleteEquipo(string nombreEquipoEliminado){
    for(int i=0; i<N; i++){
        if(nombreEquipoEliminado == arrayEquipos[i].nombreEquipo){
            for(int j=i; j<N-1; j++){
                arrayEquipos[j] = arrayEquipos[j+1];
            }
            indexLibreEquipos--;
            return;
        }
    }
}

void Torneo::deleteJugador(string nombreJugadorEliminado){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(nombreJugadorEliminado == arrayEquipos[i].arrayJugadores[j].nombreJugador){
                for(int k=j; k<M; k++){
                    arrayEquipos[i].arrayJugadores[k] = arrayEquipos[i].arrayJugadores[k+1];
                }
                arrayEquipos[i].indexLibreJugadores--;
            }
        }
    }
}

void Torneo::showInfoTorneo(){
    for(int i=0; i<indexLibreEquipos; i++){
        cout << arrayEquipos[i].nombreEquipo << " " << arrayEquipos[i].juegosGanados << " " << arrayEquipos[i].juegosEmpatados << " " << arrayEquipos[i].juegosPerdidos << " " << arrayEquipos[i].puntosAcc << endl;
    }

}

