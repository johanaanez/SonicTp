/*
 * Juego.h
 *
 *  Created on: 22 abr. 2017
 *      Author: julieta
 */

#ifndef JUEGOCLIENTE_H_
#define JUEGOCLIENTE_H_

#include "jescenarioJuego.h"
#include "VistaSDL.h"
#include "Personaje.h"
#include "Control.h"
#include "ConexCliente.h"
#include "Logger.h"
#include "parseadorJson.h"
#include "Hilo.h"
#include "HiloEnviarCliente.h"
#include "HiloRecibirCliente.h"

using namespace std;
class JuegoCliente {

private:
	VistaSDL *vista;
	Personaje* sonic;
	Control *control;
	ConexCliente *cliente;
	Logger *log;

	HiloRecibirCliente *hiloRecibir;
	HiloEnviarCliente *hiloEnviar;
	Hilo *hiloJuego;

	int maxJugadores;
	std::vector<Personaje*> sonics;

public:
	JuegoCliente();
	virtual ~JuegoCliente();

	JuegoCliente(ConexCliente *cliente, Logger *log);
	void iniciarHilos();
	void terminarHilos();
	void iniciarJuego(); //Crea el parseador e inicia el juego
	void CargarVistaParaElMenu();
	int elegirOpcionDeMenu(Logger *log);
	struct Datos{
		ConexCliente *cliente;
		Logger *log;
	};

private:
	void inicializarOtrosSonics(int id);
	static void* iniciarJuegoCliente(void *datos);
	void inicializarJuegoCliente(/*std::jescenarioJuego *jparseador*/); //Inicializa control, vista y sonic
	void iniciarJuegoControlCliente(); //Llama al juego propiamente dicho (Control::ControlarJuego)
};

#endif