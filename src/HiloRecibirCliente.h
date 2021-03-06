/*
 * HiloRecibirCliente.h
 *
 *  Created on: 23/04/2017
 *      Author: joha
 */

#ifndef HILORECIBIRCLIENTE_H_
#define HILORECIBIRCLIENTE_H_

#include "Hilo.h"
#include "ConexCliente.h"
#include "Paquete.h"
#include "VariableCondicional.h"
#include "Definiciones.h"
#include "AdministradorLatidoCliente.h"
#include <pthread.h>

class HiloRecibirCliente {
private:
	Hilo *hilo;
	Logger *log;

public:
	HiloRecibirCliente(Logger *log);
	virtual ~HiloRecibirCliente();
	void setVariableCondicional(VariableCondicional *varCond);

	void IniciarHilo(/*struct Serparametros *parametros*/);
	static void * clienteRecibir(void *args);
	struct Serparametros{
		ConexCliente *cliente;
		//list<ProcesadorCliente>pcliente;
		int skt;
		//queue<char*> colaPaquete;
		Paquete colaPaquete;
		bool continuar;
		VariableCondicional *vcIniciarJuego;
		//AdministradorLatidoCliente *alc;
	 };
	Serparametros parametros;


	void Join();
	std::string obtenerElementoDeLaCola();
	std::string obtenerPosicionDeLaCola();
};

#endif /* HILORECIBIRCLIENTE_H_ */
