/*
Este programa es la implementacion del ADT de un Torneo (estructura linealde datos) que representar la información relacionada con un torneo de algún deporte.
*/

// Creado el 1 de noviembre del 2023
// Editado el 6 de noviembre del 2023
// Daniel Artega Mercado | A01369706

#include "Torneo.h"  

/**
 * Constructor de la clase Torneo
 * 
 * @param N Número máximo de equipos en el torneo
 * @param M Número máximo de jugadores por equipo
 */
Torneo::Torneo(int N, int M) {
    this->N = N;
    this->M = M;

    indexLibreEquipos = 0;

    // Asignación de memoria para el array de equipos y jugadores
    arrayEquipos = new Equipo[N];

    // Inicialización de los equipos y jugadores con valores predeterminados
    for (int i = 0; i < N; i++) {
        arrayEquipos[i].arrayJugadores = new Jugador[M];
        arrayEquipos[i].indexLibreJugadores = 0;
        arrayEquipos[i].nombreEquipo = "";
        arrayEquipos[i].juegosGanados = 0;
        arrayEquipos[i].juegosEmpatados = 0;
        arrayEquipos[i].juegosPerdidos = 0;
        arrayEquipos[i].puntosAcc = 0;
        for (int j = 0; j < M; j++) {
            arrayEquipos[i].arrayJugadores[j].nombreJugador = "";
            arrayEquipos[i].arrayJugadores[j].numeroId = 0;
            arrayEquipos[i].arrayJugadores[j].posicion = "";
            arrayEquipos[i].arrayJugadores[j].averageAcc = 0;
        }
    }
}

/**
 * Destructor de la clase Torneo
 */
Torneo::~Torneo() {
    // Liberación de memoria de los jugadores y equipos
    for (int i = 0; i < N; i++) {
        delete[] arrayEquipos[i].arrayJugadores;
    }
    delete[] arrayEquipos;
}

/**
 * Método para insertar un equipo en el torneo
 * 
 * @param equipoInsertado Objeto de tipo Equipo que se desea insertar en el torneo
 */
void Torneo::insertEquipo(Equipo equipoInsertado) {
    if (indexLibreEquipos >= N) {
        cout << "No hay espacio para insertar más equipos" << endl;
        return;
    } else {
        arrayEquipos[indexLibreEquipos] = equipoInsertado;
        indexLibreEquipos++;
    }
}

/**
 * Método para insertar un jugador en un equipo específico del torneo
 * 
 * @param equipoDelJugador Nombre del equipo donde se desea insertar al jugador
 * @param jugadorInsertado Objeto de tipo Jugador que se desea insertar en el equipo
 */
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

/**
 * Método para obtener información de un equipo específico del torneo
 * 
 * @param nombreEquipoConsultado Nombre del equipo del cual se desea obtener información
 * @return Objeto de tipo Equipo con la información del equipo consultado
 */
Torneo::Equipo Torneo::getInfoEquipo(string nombreEquipoConsultado) {
    for (int i = 0; i < indexLibreEquipos; i++) {
        if (nombreEquipoConsultado == arrayEquipos[i].nombreEquipo) {
            return arrayEquipos[i];
        }
    }
    cout << "No se encontró el equipo especificado" << endl;
    return Equipo{};
}

/**
 * Método para obtener información de un jugador específico del torneo
 * 
 * @param nombreJugadorConsultado Nombre del jugador del cual se desea obtener información
 * @return Objeto de tipo Jugador con la información del jugador consultado
 */
Torneo::Jugador Torneo::getInfoJugador(string nombreJugadorConsultado) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (nombreJugadorConsultado == arrayEquipos[i].arrayJugadores[j].nombreJugador) {
                return arrayEquipos[i].arrayJugadores[j];
            }
        }
    }
    cout << "No se encontró el jugador especificado" << endl;
    return Jugador{};
}

/**
 * Método para cambiar información de un equipo específico del torneo
 * 
 * @param nombreEquipoCambiado Nombre del equipo al cual se desea cambiar información
 * @param elementoCambiado Elemento del equipo que se desea modificar (nombre, juegosGanados, juegosPerdidos, juegosEmpatados, puntosAcc)
 * @param nuevoValor Nuevo valor que se asignará al elemento del equipo
 */
void Torneo::changeInfoEquipo(string nombreEquipoCambiado, string elementoCambiado, string nuevoValor) {
    for (int i = 0; i < indexLibreEquipos; i++) {
        if (nombreEquipoCambiado == arrayEquipos[i].nombreEquipo) {
            if (elementoCambiado == "nombre") {
                arrayEquipos[i].nombreEquipo = nuevoValor;
                return;
            } else if (elementoCambiado == "juegosGanados") {
                arrayEquipos[i].juegosGanados = stoi(nuevoValor);
                return;
            } else if (elementoCambiado == "juegosPerdidos") {
                arrayEquipos[i].juegosPerdidos = stoi(nuevoValor);
                return;
            } else if (elementoCambiado == "juegosEmpatados") {
                arrayEquipos[i].juegosEmpatados = stoi(nuevoValor);
                return;
            } else if (elementoCambiado == "puntosAcc") {
                arrayEquipos[i].puntosAcc = stoi(nuevoValor);
                return;
            } else {
                cout << "No se encontró el elemento especificado" << endl;
                return;
            }
        }
    }
    cout << "No se encontró el equipo especificado" << endl;
}

/**
 * Método para cambiar información de un jugador específico del torneo
 * 
 * @param nombreJugadorCambiado Nombre del jugador al cual se desea cambiar información
 * @param elementoCambiado Elemento del jugador que se desea modificar (nombre, numeroId, posicion, averageAcc)
 * @param nuevoValor Nuevo valor que se asignará al elemento del jugador
 */
void Torneo::changeInfoJugador(string nombreJugadorCambiado, string elementoCambiado, string nuevoValor) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (nombreJugadorCambiado == arrayEquipos[i].arrayJugadores[j].nombreJugador) {
                if (elementoCambiado == "nombre") {
                    arrayEquipos[i].arrayJugadores[j].nombreJugador = nuevoValor;
                    return;
                } else if (elementoCambiado == "numeroId") {
                    arrayEquipos[i].arrayJugadores[j].numeroId = stoi(nuevoValor);
                    return;
                } else if (elementoCambiado == "posicion") {
                    arrayEquipos[i].arrayJugadores[j].posicion = nuevoValor;
                    return;
                } else if (elementoCambiado == "averageAcc") {
                    arrayEquipos[i].arrayJugadores[j].averageAcc = stod(nuevoValor);
                    return;
                } else {
                    cout << "No se encontró el elemento especificado" << endl;
                    return;
                }
            }
        }
    }
    cout << "No se encontró el jugador especificado" << endl;
}

/**
 * Método para eliminar un equipo del torneo
 * 
 * @param nombreEquipoEliminado Nombre del equipo que se desea eliminar del torneo
 */
void Torneo::deleteEquipo(string nombreEquipoEliminado) {
    for (int i = 0; i < indexLibreEquipos; i++) {
        if (nombreEquipoEliminado == arrayEquipos[i].nombreEquipo) {
            for (int j = i; j < N - 1; j++) {
                arrayEquipos[j] = arrayEquipos[j + 1];
            }
            indexLibreEquipos--;
            return;
        }
    }
    cout << "No se encontró el equipo especificado" << endl;
}

/**
 * Método para eliminar un jugador del torneo
 * 
 * @param nombreJugadorEliminado Nombre del jugador que se desea eliminar del torneo
 */
void Torneo::deleteJugador(string nombreJugadorEliminado) {
    for (int i = 0; i < N; i++) {
        bool jugadorEncontrado = false;
        for (int j = 0; j < M; j++) {
            if (jugadorEncontrado && j < M - 1) {
                arrayEquipos[i].arrayJugadores[j - 1] = arrayEquipos[i].arrayJugadores[j];
            } else if (nombreJugadorEliminado == arrayEquipos[i].arrayJugadores[j].nombreJugador) {
                jugadorEncontrado = true;
            }
        }
        if (jugadorEncontrado) {
            arrayEquipos[i].indexLibreJugadores--;
            return;
        }
    }
    cout << "No se encontró el jugador especificado" << endl;
}

/**
 * Método de comparación para ordenar los equipos por puntos en orden descendente
 * 
 * @param a Objeto de tipo Equipo a comparar
 * @param b Objeto de tipo Equipo a comparar
 * @return true si a tiene más puntos que b, false en caso contrario
 */
bool Torneo::compareEquipos(Equipo a, Equipo b) {
    return a.puntosAcc > b.puntosAcc;
}

/**
 * Método para mostrar la información de los equipos del torneo ordenados por puntos de forma descendente
 */
void Torneo::showInfoTorneo() {
    // Ordena los equipos utilizando el método de comparación compareEquipos
    sort(arrayEquipos, arrayEquipos + indexLibreEquipos, Torneo::compareEquipos);

    const int colWidth = 15;

    // Imprime la información de los equipos en formato tabular
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
