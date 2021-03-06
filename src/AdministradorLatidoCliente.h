/*
 * AdministradorLatidoCliente.h
 *
 *  Created on: 4 may. 2017
 *      Author: pato
 */

#ifndef ADMINISTRADORLATIDOCLIENTE_H_
#define ADMINISTRADORLATIDOCLIENTE_H_

#include <time.h>
#include <stdio.h>
#include "Hilo.h"
#include "Paquete.h"
#include "Definiciones.h"
namespace std {

class AdministradorLatidoCliente {
private:
	time_t end_t;
	ConexCliente *cliente;
	ConexServidor *servidor;
	int skt;
	Paquete *colaPaquete;
	Hilo *h;
	bool iniciar;
	std::string idCliente;
	std::string cadena;
public:


	void actualizarTiempoLatido();
	//bool pasoDemasiadoTiempoDelUltimoLatido();

	AdministradorLatidoCliente(Paquete *colaPaquete);
	~AdministradorLatidoCliente();
	void IniciarHilo();
	void IniciarHiloServidorCliente();
	static void* iniciarContadorServidorCliente(void *ars);
	std::string getidCliente();

	void setidCliente(std::string id);
	static void* iniciarContador(void *ars);
	struct SerParametros{
		ConexCliente *cliente;
		ConexServidor *servidor;
	//	time_t *end_t;


	};
	SerParametros parametros;

	ConexCliente* getconexcliente();
	void setconexcliente(ConexCliente *c);
	void setconexServidor(ConexServidor *s);
	Hilo* gethilo();

	void setH(Hilo*);
	int getSkt();
	void setSkt(int s);
	bool isIniciar();

	void setIniciar(bool ini);

	std::string getCadena();

	void setCadena(std::string c);
	int Join();
};

} /* namespace std */

#endif /* ADMINISTRADORLATIDOCLIENTE_H_ */
