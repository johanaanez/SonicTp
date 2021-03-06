/*
 * HiloEnviarCliente.h
 *
 *  Created on: 23/04/2017
 *      Author: joha
 */

#ifndef HILOENVIARCLIENTE_H_
#define HILOENVIARCLIENTE_H_

#include "ConexCliente.h"
#include "Hilo.h"
#include "Paquete.h"
#include  "AdministradorLatidoCliente.h"
#include "HilolatidoSer.h"

class HiloEnviarCliente {
private:
	Hilo* hilo;
	Logger *log;

public:
	HiloEnviarCliente(Logger *log);
	virtual ~HiloEnviarCliente();
	void IniciarHilo(/*struct parametrosEnviar *parametros*/);
		static void * clienteEnviar(void *args);
		struct SerParametros{
			ConexCliente *cliente;
			char *buffer;
			int skt;
			Paquete pack;
			char *bufferQ;
			AdministradorLatidoCliente *alc;
			bool continuar;
		};
	SerParametros parametros;
	void iniciarHiloQueue();
	static void* clienteEnviarQueue(void* args);
	void enviarDato(char* dato);
	void Join();
};

#endif /* HILOENVIARCLIENTE_H_ */
