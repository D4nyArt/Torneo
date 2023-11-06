#include "Torneo.h"


Torneo::Torneo(const int N, const int M) {
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

void Torneo::insertJugador(string nombreEquipo, Jugador jugadorInsertado) {
    cout << arrayEquipos[0].arrayJugadores[0].averageAcc << endl;
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
        } else{
            cout << "No se encontro el equipo especificado" << endl;
            return;
        }
    }
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
                    arrayEquipos[i].arrayJugadores[j].averageAcc = stoi(nuevoValor);
                    return;
                } else{
                    cout << "No se encontro el elemento especificado" << endl;
                    return;
                }
            } else{
                cout << "No se encontro el jugador especificado" << endl;
                return;
            }
        }    
    }
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

