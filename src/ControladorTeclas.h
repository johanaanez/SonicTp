/*
 * ControladorTeclas.h
 *
 *  Created on: 15 abr. 2017
 *      Author: julieta
 */

#ifndef CONTROLADORTECLAS_H_
#define CONTROLADORTECLAS_H_

#include "Personaje.h"
#include "Definiciones.h"
#include "ConexCliente.h"
#include "ConexServidor.h"
#include "Posicion.h"
#include "HiloRecibirCliente.h"
#include "HilolatidoSer.h"
#include "VistaSDL.h"

class ControladorTeclas {

private:
	bool teclaArriba;
	bool teclaAbajo;
	bool teclaIzquierda;
	bool teclaDerecha;
	bool teclaCorrer; //A

public:
	ControladorTeclas();
	virtual ~ControladorTeclas();
	void procesarEvento(SDL_Event &e, Personaje *sonic, HiloEnviarCliente *hiloEnviar,
		HiloRecibirCliente *hiloRecibir, HilolatidoSer* hiloLatido,  VistaSDL *vista,int &opcionMenu);
	void administrarTeclas(Personaje *sonic);

private:
	std::string intToString(int number);
};

#endif
