/*
 * AdministradorLatidoCliente.cpp
 *
 *  Created on: 4 may. 2017
 *      Author: pato
 */

#include "AdministradorLatidoCliente.h"
#include <stdio.h>
#include <iostream>
#include <math.h>

namespace std {
//clock_t tiempoUltimoLatido;

AdministradorLatidoCliente::AdministradorLatidoCliente(Paquete *colaPaquete) {
	// TODO Auto-generated constructor stub
  this->colaPaquete = colaPaquete;
  this->iniciar = false;
}
/*time_t AdministradorLatidoCliente::getEndT(){
		return end_t;
}

void AdministradorLatidoCliente::setEndT(time_t endT) {
		end_t = endT;
}
*/
AdministradorLatidoCliente::~AdministradorLatidoCliente() {
	// TODO Auto-generated destructor stub
	delete h;
}

void AdministradorLatidoCliente::actualizarTiempoLatido(){
	//printf("Se actualiza el tiempo \n");
	time(&end_t);
	//cout<<"+++++++++++++++++++++++++++ :  "<<end_t<<endl;
}
void AdministradorLatidoCliente::IniciarHilo(){

	//Hilo *hilo = new Hilo(/*log*/);

	//hilo->Create((void *)AdministradorLatidoCliente::iniciarContador ,  (void *)this);
	//Hilo hilo = Hilo(/*log*/);
	h = new Hilo();
	h->Create((void *)AdministradorLatidoCliente::iniciarContador ,  (void *)this);
	//this->setH(hilo);
}
void AdministradorLatidoCliente::IniciarHiloServidorCliente(){
	//Hilo *hilo = new Hilo(/*log*/);
	//hilo->Create((void *)AdministradorLatidoCliente::iniciarContadorServidorCliente ,  (void *)this);
	//Hilo hilo = Hilo(/*log*/);
	h = new Hilo();
	h->Create((void *)AdministradorLatidoCliente::iniciarContadorServidorCliente ,  (void *)this);

}
void* AdministradorLatidoCliente::iniciarContadorServidorCliente(void *ars){
	AdministradorLatidoCliente *alc = (AdministradorLatidoCliente*)ars;

	alc->actualizarTiempoLatido();
	alc->iniciar = true;

	double diff_t;
	time_t start_t;
	time(&start_t);

	diff_t = difftime(alc->end_t,start_t);
	diff_t = fabs(diff_t);
	//cout<<"CADENAAA"<<endl;
	//cout<<alc->cadena<<endl;
	//bool comenzo = true;
	//while(comenzo){
	while(diff_t < 6.0 && alc->iniciar){
			 time(&start_t);

			 diff_t = difftime(alc->end_t,start_t);
			 diff_t = fabs(diff_t);
			 //cout<<diff_t<<endl;

	}

	//Si salio del while porque diff_t > 6 (y no porque lo cerre con un Join desde el Hilorecibir)
	if(alc->iniciar == true){
		printf("Se desconecto al cliente por falta de latidos \n");

		char buffer[40];
		std::string msjDesconexion = MENSAJE_DESCONEXION_CLIENTE + alc->idCliente;
		strcpy(buffer, msjDesconexion.c_str());
		alc->colaPaquete->agregar(buffer);
		//cout<<"VOY A CERRAR EL CLIENTE"<<endl;
		//cout<<"PARAMETROS ALC CLIENTES:::"<<alc->getSkt()<<endl;
		shutdown(alc->getSkt(), SHUT_RDWR);
		close(alc->getSkt());
		//cout<<"SE CERRO EL CLIENTE"<<endl;
	}

	//alc->colaPaquete->agregar("Servidor Desconectado");
	// comenzo = false;

//}
}
ConexCliente* AdministradorLatidoCliente::getconexcliente(){
	return this->cliente;
}

void AdministradorLatidoCliente::setconexcliente(ConexCliente *c){
	this->cliente = c;

}
void AdministradorLatidoCliente::setconexServidor(ConexServidor *s){

}
std::string AdministradorLatidoCliente::getCadena(){
	this->cadena;
}
void AdministradorLatidoCliente::setCadena(std::string c){
	this->cadena = c;
}
void *AdministradorLatidoCliente::iniciarContador(void *arg){

AdministradorLatidoCliente *alc = (AdministradorLatidoCliente*)arg;

 /* double diff_t;
  time_t start_t;
	time(&start_t);
	diff_t = difftime(alc->end_t,start_t);
	diff_t = fabs(diff_t);*/
	//cout<<"CADENAAA"<<endl;
	//cout<<alc->cadena<<endl;
		alc->actualizarTiempoLatido();
		alc->iniciar = true;
		double diff_t;
		time_t start_t;
		time(&start_t);
		diff_t = difftime(alc->end_t,start_t);
		diff_t = fabs(diff_t);

		while(diff_t < 6.0 && alc->iniciar){
			 time(&start_t);

			 diff_t = difftime(alc->end_t,start_t);
			 diff_t = fabs(diff_t);
			 //cout<<"la diferencia ::::::"<<diff_t<<endl;

		}

		if (alc->iniciar){
			printf("Se desconectara el cliente por falta de latidos \n");
		}

		alc->colaPaquete->agregar("Servidor Desconectado");

		shutdown(alc->getSkt(),SHUT_RDWR);
		close(alc->getSkt());

 // printf("Se desconectara el cliente por falta de latidos \n");

}
bool  AdministradorLatidoCliente::isIniciar(){
	return this->iniciar;
}
void AdministradorLatidoCliente::setIniciar(bool ini){
	this->iniciar = ini;
}
Hilo* AdministradorLatidoCliente::gethilo(){
	return this->h;
}
int AdministradorLatidoCliente::getSkt(){
	return this->skt;
}
void AdministradorLatidoCliente::setSkt(int s){
	this->skt  = s;
}
void AdministradorLatidoCliente::setH(Hilo *hil){
	this->h = hil;
}
std::string AdministradorLatidoCliente::getidCliente(){
	return this->idCliente;
}

void AdministradorLatidoCliente::setidCliente(std::string id){
	this->idCliente = id;
}

int AdministradorLatidoCliente::Join()
{
	this->iniciar = false;
	return h->Join();
}
} /* namespace std */
