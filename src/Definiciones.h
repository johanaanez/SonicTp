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
#define ANIMACION_ATAQUE_DERECHA	"AaD"

#define ANIMACION_QUIETO_IZQUIERDA 	"AqI"
#define ANIMACION_CAMINAR_IZQUIERDA "AcI"
#define ANIMACION_CORRER_IZQUIERDA 	"AxI"
#define ANIMACION_SALTAR_IZQUIERDA 	"AsI"
#define ANIMACION_ATAQUE_IZQUIERDA 	"AaI"

#define ANIMACION_ESCUDO			"AEs"
#define ANIMACION_INVENCIBLE		"AIn"
#define ANIMACION_SIN_BONUS			"Axx"

#define ANIMACION_CONGELADO			"Acg"
#define ANIMACION_PUNTAJE			"Apj"

#define ANIMACION_TITILAR			"ATs"
#define ANIMACION_NO_TITILAR		"ATn"

#define TECLA_ARRIBA_PRESIONADA 	"TuP"
#define TECLA_ABAJO_PRESIONADA 		"TdP"
#define TECLA_DERECHA_PRESIONADA 	"TrP"
#define TECLA_IZQUIERDA_PRESIONADA 	"TlP"
#define TECLA_CORRER_PRESIONADA 	"TcP"
#define TECLA_ATAQUE_PRESIONADA 	"TaP"

#define TECLA_INMORTAL_PRESIONADA	"TiP"

#define TECLA_ARRIBA_LIBERADA	 	"TuL"
#define TECLA_ABAJO_LIBERADA 		"TdL"
#define TECLA_DERECHA_LIBERADA 		"TrL"
#define TECLA_IZQUIERDA_LIBERADA 	"TlL"
#define TECLA_CORRER_LIBERADA	 	"TcL"
#define TECLA_ATAQUE_LIBERADA	 	"TaL"

#define MENSAJE_CAMARA				"CAM"
#define MENSAJE_POSICION			"POS"
#define MENSAJE_DESCONEXION_CLIENTE	"DES"
#define MENSAJE_ID					"IDi"
#define MENSAJE_PERDIO_JUGADOR		"LOS"
#define MENSAJE_MODO				"MOD"
#define MENSAJE_EQUIPO				"EQU"

//Mensajes de entidades empiezan con E
#define ANILLOS                     "EA"
#define PIEDRA                      "PI"
#define PINCHE                      "PN"
#define BONUS						"EB"
#define BONUS_RING					"E0"
#define BONUS_ESCUDO				"E1"
#define BONUS_INVENCIBILIDAD		"E2"
#define PLATAFORMA					"EP"
#define RECTANGULO					"ER"
#define CIRCULO						"EC"

#define FIN_MENSAJE_ESCENARIO		"FIN_CARGA_ESCEN"

#define PADDING 						'-'
//#define MAX_CANT_DIGITOS_POS 			4
#define MAX_DIGITOS_POSICION			5
#define LARGO_MENSAJE_POSICION_CLIENTE 	30
#define LARGO_MENSAJE_POSICION_SERVIDOR 19
#define INICIO_JUEGO 				"[INICIAR JUEGO]"
#define CONEXION_RECHAZADA 			"Conex rechazada"
#define SEPARADOR_DE_MENSAJE		"$"
#define FIN_MENSAJES_ENEMIGOS		"FIN_CARGA_ENEMI"

#define MAXIMO_ENEMIGOS_EN_MAPA			30
#define MAX_CANT_CANGREJOS 				10
#define MAX_CANT_PECES					10
#define MAX_CANT_MOSCAS 				20
#define DURACION_INVENCIBLE_HERIDO	3
#define DURACION_INVENCIBLE_BONUS	20
#define DURACION_HERIDA				3
#define DURACION_ATAQUE				2

#define CANTIDAD_NIVELES			3
#define PI 							3.14159265

#endif
