#include "Torneo.h"


Torneo::Torneo(int N, int M) {
    this -> N = N;
    this -> M = M;

    indexLibreEquipos = 0;

    arrayEquipos = new Equipo[N];

    for (int i = 0; i < N; i++) {
        arrayEquipos[i].arrayJugadores = new Jugador[M];
        arrayEquipos[i].indexLibreJugadores = 0;
        arrayEquipos[i].nombreEquipo = "";
        arrayEquipos[i].juegosGanados = 0;
        arrayEquipos[i].juegosEmpatados=0;
        arrayEquipos[i].juegosPerdidos=0;
        arrayEquipos[i].puntosAcc= 0;
        for(int j=0; j<M; j++){
            arrayEquipos[i].arrayJugadores[j].nombreJugador = "";
            arrayEquipos[i].arrayJugadores[j].numeroId = 0;
            arrayEquipos[i].arrayJugadores[j].posicion = "";
            arrayEquipos[i].arrayJugadores[j].averageAcc = 0;
        }
    }
}

Torneo::~Torneo(){
    for(int i=0; i<N; i++){
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
                cout << "El equipo ya tiene el numero maximo de jugadores." << endl;
            }
            return;
        }
    }
    cout << "No se encontro el equipo: " << equipoDelJugador << endl;
}

Torneo::Equipo Torneo::getInfoEquipo(string nombreEquipoConsultado){
    for(int i=0; i < indexLibreEquipos; i++){
        if(nombreEquipoConsultado == arrayEquipos[i].nombreEquipo){
            return arrayEquipos[i];
        }
    }
    cout << "No se encontro el equipo especificado" << endl;
    return Equipo{};
}

Torneo::Jugador Torneo::getInfoJugador(string nombreJugadorConsultado){
    for(int i=0; i < N; i++){
        for(int j=0; j < M ; j++){
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
        }
    }
    cout << "No se encontro el equipo especificado" << endl;
}

void Torneo::changeInfoJugador(string nombreJugadorCambiado, string elementoCambiado, string nuevoValor){  
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(nombreJugadorCambiado==arrayEquipos[i].arrayJugadores[j].nombreJugador){
                if(elementoCambiado=="nombre"){
                    arrayEquipos[i].arrayJugadores[j].nombreJugador = nuevoValor;
                    return;
                } else if(elementoCambiado=="numeroId"){
                    arrayEquipos[i].arrayJugadores[j].numeroId = stoi(nuevoValor);
                    return;
                } else if(elementoCambiado=="posicion"){
                    arrayEquipos[i].arrayJugadores[j].posicion = nuevoValor;
                    return;
                } else if(elementoCambiado=="averageAcc"){
                    arrayEquipos[i].arrayJugadores[j].averageAcc = stod(nuevoValor);
                    return;
                } else{
                    cout << "No se encontro el elemento especificado" << endl;
                    return;
                }
            }
        }    
    }
    cout << "No se encontro el jugador especificado" << endl;
}

void Torneo::deleteEquipo(string nombreEquipoEliminado){
    for(int i=0; i<indexLibreEquipos; i++){
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
        bool jugadorEncontrado = false;
        for(int j=0; j<M; j++){
            if(jugadorEncontrado && j < M-1){
                arrayEquipos[i].arrayJugadores[j-1] = arrayEquipos[i].arrayJugadores[j];
            } else if(nombreJugadorEliminado == arrayEquipos[i].arrayJugadores[j].nombreJugador){
                jugadorEncontrado = true;
            }
        }
        if(jugadorEncontrado){
            arrayEquipos[i].indexLibreJugadores--;
        }
    }
}

bool Torneo::compareEquipos(Equipo a, Equipo b) {
    return a.puntosAcc > b.puntosAcc;
}

void Torneo::showInfoTorneo() {
    sort(arrayEquipos, arrayEquipos + indexLibreEquipos, Torneo::compareEquipos);

    const int colWidth = 15;

    cout << setw(colWidth) << left << "Nombre";
    cout << setw(colWidth) << left << "Ganados";
    cout << setw(colWidth) << left << "Perdidos";
    cout << setw(colWidth) << left << "Empatados";
    cout << setw(colWidth) << left << "Puntos" << endl;

    for (int i = 0; i < indexLibreEquipos; i++) {
        cout << setw(colWidth) << left << arrayEquipos[i].nombreEquipo;
        cout << setw(colWidth) << left << arrayEquipos[i].juegosGanados;
        cout << setw(colWidth) << left << arrayEquipos[i].juegosPerdidos;
        cout << setw(colWidth) << left << arrayEquipos[i].juegosEmpatados;
        cout << setw(colWidth) << left << arrayEquipos[i].puntosAcc << endl;
    }
}
