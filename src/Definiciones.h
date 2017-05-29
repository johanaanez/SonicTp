/*
 * Definiciones.h
 *
 *  Created on: 21 abr. 2017
 *      Author: julieta
 */

#ifndef DEFINICIONES_H_
#define DEFINICIONES_H_

#define ANIMACION_QUIETO_DERECHA 	"AqD"
#define ANIMACION_CAMINAR_DERECHA 	"AcD"
#define ANIMACION_CORRER_DERECHA 	"AxD"
#define ANIMACION_SALTAR_DERECHA 	"AsD"

#define ANIMACION_QUIETO_IZQUIERDA 	"AqI"
#define ANIMACION_CAMINAR_IZQUIERDA "AcI"
#define ANIMACION_CORRER_IZQUIERDA 	"AxI"
#define ANIMACION_SALTAR_IZQUIERDA 	"AsI"

#define ANIMACION_CONGELADO			"Acg"

#define TECLA_ARRIBA_PRESIONADA 	"TuP"
#define TECLA_ABAJO_PRESIONADA 		"TdP"
#define TECLA_DERECHA_PRESIONADA 	"TrP"
#define TECLA_IZQUIERDA_PRESIONADA 	"TlP"
#define TECLA_CORRER_PRESIONADA 	"TcP"

#define TECLA_ARRIBA_LIBERADA	 	"TuL"
#define TECLA_ABAJO_LIBERADA 		"TdL"
#define TECLA_DERECHA_LIBERADA 		"TrL"
#define TECLA_IZQUIERDA_LIBERADA 	"TlL"
#define TECLA_CORRER_LIBERADA	 	"TcL"

#define MENSAJE_CAMARA				"CAM"
#define MENSAJE_POSICION			"POS"
#define MENSAJE_DESCONEXION_CLIENTE	"DES"
#define MENSAJE_ID					"IDi"

//Mensajes de entidades empiezan con E
#define ANILLOS                     "EA"
#define PIEDRA                      "PI"
#define BONUS						"EB"
#define BONUS_RING					"E0"
#define BONUS_ESCUDO				"E1"
#define BONUS_INVENCIBILIDAD		"E2"
#define RECTANGULO					"ER"
#define CIRCULO						"EC"

#define FIN_MENSAJE_ESCENARIO		"FIN_CARGA_ESCEN"

#define PADDING 						'-'
#define MAX_CANT_DIGITOS_POS 			4
#define LARGO_MENSAJE_POSICION_CLIENTE 	30
#define LARGO_MENSAJE_POSICION_SERVIDOR 17
#define INICIO_JUEGO 				"[INICIAR JUEGO]"
#define CONEXION_RECHAZADA 			"Conex rechazada"
#define SEPARADOR_DE_MENSAJE		"$"
#endif
