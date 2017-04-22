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
	void procesarEvento(SDL_Event &e,Personaje *sonic, ConexCliente *cliente);
	void administrarTeclas(Personaje *sonic);

private:
};

#endif
