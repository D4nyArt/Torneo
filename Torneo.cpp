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

void Torneo::insertJugador(string equipoDelJugador, Jugador jugadorInsertado) {
    for (int i = 0; i < indexLibreEquipos; ++i) {
        if (arrayEquipos[i].nombreEquipo == equipoDelJugador) {
            if (arrayEquipos[i].indexLibreJugadores < M) {
                arrayEquipos[i].arrayJugadores[arrayEquipos[i].indexLibreJugadores] = jugadorInsertado;
                arrayEquipos[i].indexLibreJugadores++;
                cout << "Jugador insertado en el equipo: " << equipoDelJugador << endl;
            } else {
                cout << "El equipo ya tiene el número máximo de jugadores." << endl;
            }
            return;
        }
    }
    cout << "No se encontró el equipo: " << equipoDelJugador << endl;
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

void Torneo::changeInfoEquipo(string nombreEquipoCambiado, string elementoCambiado, string nuevoValor){  
    for(int i=0; i<indexLibreEquipos; i++){
        if(nombreEquipoCambiado==arrayEquipos[i].nombreEquipo){
            if(elementoCambiado=="nombre"){
                arrayEquipos[i].nombreEquipo = nuevoValor;
                return;
            } else if(elementoCambiado=="juegosGanados"){
                arrayEquipos[i].juegosGanados = stoi(nuevoValor);
                return;
            } else if(elementoCambiado=="juegosPerdidos"){
                arrayEquipos[i].juegosPerdidos = stoi(nuevoValor);
                return;
            } else if(elementoCambiado=="juegosEmpatados"){
                arrayEquipos[i].juegosEmpatados = stoi(nuevoValor);
                return;
            } else if(elementoCambiado=="puntosAcc"){
                arrayEquipos[i].puntosAcc = stoi(nuevoValor);
                return;
            } else{
                cout << "No se encontro el elemento especificado" << endl;
                return;
            }
        } else{
            cout << "No se encontro el equipo especificado" << endl;
            return;
        }
    }
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

bool Torneo::compareEquipos(Equipo a, Equipo b) {
    return a.puntosAcc > b.puntosAcc;
}

void Torneo::showInfoTorneo(){

    sort(arrayEquipos, arrayEquipos + indexLibreEquipos, Torneo::compareEquipos);
    
    for(int i=0; i<indexLibreEquipos; i++){
        cout << arrayEquipos[i].nombreEquipo << " " << arrayEquipos[i].juegosGanados << " " << arrayEquipos[i].juegosEmpatados << " " << arrayEquipos[i].juegosPerdidos << " " << arrayEquipos[i].puntosAcc << endl;
    }
}

