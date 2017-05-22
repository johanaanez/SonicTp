/*
 * HiloMenuSer.cpp
 *
 *  Created on: 22 may. 2017
 *      Author: joha
 */

#include "HiloMenuSer.h"

HiloMenuSer::HiloMenuSer(Logger *log) : log(log), hilo(){
	// TODO Auto-generated constructor stub

}

HiloMenuSer::~HiloMenuSer() {
	// TODO Auto-generated destructor stub
}

void HiloMenuSer::IniciarHilo(bool *juegoTerminado)
{
	hilo = new Hilo();
	log->addLogMessage("[HILO MENU SERVIDOR] Iniciado.", 2);
	hilo->Create((void*)HiloMenuSer::menuSalir, (void*)&juegoTerminado);
	log->addLogMessage("[HILO MENU SERVIDOR] Terminado.", 2);
}

void* HiloMenuSer::menuSalir(void *args)
{
	bool *juegoTerminado = (bool*)args;

	int opcion = 1;
	while(opcion != 2)
	{
		cout<<"\t 2: Salir. \n"<<endl;
		cin >> opcion;
		if (opcion != 2)
		{
			cout<<"Opcion incorrecta, presione una de las opciones posibles.\n"<<endl;
		}
	}
	juegoTerminado = true;

}
