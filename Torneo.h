#ifndef TORNEO_H
#define TORNEO_H

#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

struct Jugador{
	string nombreJugador;
	int numeroId;
	string posicion;
	int averageAcc;
};

struct Equipo{
	string nombreEquipo;
	int juegosGanados;
	int juegosPerdidos;
	int juegosEmpatados;
	int puntosAcc;
	Jugador* arrayJugadores;
	int indexLibreJugadores;
};

class Torneo{

	private:

	int indexLibreEquipos;

	int N,M;

	Equipo* arrayEquipos;

	static bool compareEquipos(Equipo a, Equipo b);

	public:
	
	//CREATE
	Torneo(int num_equipos, int num_jugadores);
	~Torneo();

	void insertEquipo(Equipo equipoInsertado);
	void insertJugador(string equipoDelJugador, Jugador jugadorInsertado);

	//READ
	Equipo getInfoEquipo(string nombreEquipoConsultado);
	Jugador getInfoJugador(string nombreJugadorConsultado);
	
	//UPDATE
	void changeInfoEquipo(string nombreEquipoCambiado, string elementoCambiado, string nuevoValor);
	void changeInfoJugador();

	//DELETE
	void deleteEquipo(string nombreEquipoEliminado);
	void deleteJugador(string nombreJugadorEliminado);

	//TABLE
	void showInfoTorneo();

};

#endif// !Torneo.09:29:29
