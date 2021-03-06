#ifndef PERSONAJE_H_
#define PERSONAJE_H_

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include <string>
#include <SDL2/SDL_image.h>
#include "Textura.h"
#include "Animacion.h"
#include "ConexCliente.h"
#include "HiloEnviarCliente.h"
#include "Definiciones.h"

#define GRAVEDAD 9
#define IMAGEN_POR_DEFECTO "images/sonicSprite.png"
#define REGULADOR_ALTURA_SALTO 0.04 //Regula la altura del salto (Es como un "promedio" de tiempoDeJuego)

class Personaje
{
	public:
		enum Orientacion {IZQUIERDA, DERECHA};

	private:

		Textura *texturaSonic;
		Textura *texturaCongelado;

		int id;
		int personajeAncho;
		int personajeAlto;
		int personajeVelocidad;
		int personajeAceleracion;
		int posicionX, posicionY;
		int velocidadX, velocidadY;

		Animacion animacionQuietoDer;
		Animacion animacionCaminarDer;
		Animacion animacionCorrerDer;
		Animacion animacionSaltarDer;
		Animacion animacionQuietoIzq;
		Animacion animacionCaminarIzq;
		Animacion animacionCorrerIzq;
		Animacion animacionSaltarIzq;
		Animacion animacionCongelado;

		Animacion *animacionActual;

		Orientacion orientacion;

		bool saltando;
		bool corriendo;
		bool estaQuieto;
		bool congelado;

		Logger *log;

		void animarSalto();
		void cargarSpriteSonic();
		void dejarDeEstarQuieto();

		std::string intToStringConPadding(int number);

		ConexCliente *cliente; //<-------- Borrarlo cuando el enviar del hilo ande bien!

    public:

		Personaje(int id, int velocidad,SDL_Renderer *render, int altoEscenario, Logger *log);
		Personaje(int id, int velocidad,SDL_Renderer *render, int altoEscenario, Logger *log, ConexCliente *cliente);
		virtual ~Personaje();

		void mover(SDL_Rect *limites, float tiempoDeJuego);

		void render(int camX, int camY);
		std::string intToString(int number);
		void posicionarseEn(int x, int y);
		void posicionarseConAnimacion(int x, int y, std::string animacion, int indiceAnimacion);
		int getPosicionX();
		int getPosicionY();
		int getVelocidadX();
		int getAlto();
		int getAncho();
		int getId();
		std::string getNombreAnimacion();
		std::string getEstadoAnimacion();

		void saltar();
		void dejarDeSaltar();
		void correr(bool estaCorriendo);
		void irArriba();
		void irAbajo();
		void irIzquierda();
		void irDerecha();
		void parar();
		void congelar();
		void descongelar();

		bool bloqueaCamara(SDL_Rect *limites);
		bool bloqueaCamaraADerecha(SDL_Rect *limites);
		bool bloqueaCamaraAIzquierda(SDL_Rect *limites);
		bool estaCongelado();
		bool estaParado();

		void enviarAServer(HiloEnviarCliente *hiloEnviar, std::string mensaje);
		std::string obtenerMensajeEstado();

};

#endif
