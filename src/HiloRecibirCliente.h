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

class HiloRecibirCliente {
public:
	HiloRecibirCliente();
	virtual ~HiloRecibirCliente();

	void IniciarHilo(/*struct Serparametros *parametros*/);
	static void * clienteRecibir(void *args);
	struct Serparametros{
		ConexCliente *cliente;
		//list<ProcesadorCliente>pcliente;
		int skt;
		queue<char*> colaPaquete;
	 };
	Serparametros parametros;
};

#endif /* HILORECIBIRCLIENTE_H_ */
