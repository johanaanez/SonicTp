/*
 * Animacion.h
 *
 *  Created on: 14 abr. 2017
 *      Author: julieta
 */

#ifndef ANIMACION_H_
#define ANIMACION_H_

#include <SDL2/SDL_image.h>
#include "Textura.h"
#include <vector>
#include <string>

class Animacion {

private:
	Textura *spriteSheet = NULL;
	std::vector<SDL_Rect> sprites;
	int dimension; //Dimension en pixeles de un tile
	int fotogramaMaximo;
	bool detenido;
	int fotogramaActual;
	unsigned int indiceSprite;
	SDL_Rect spriteActual;
	std::string nombre;

public:
	Animacion();
	Animacion(Textura *spriteSheet, int dimension, int retardo, std::string nombre);
	void cargarSprites(int x, int y, int cantidad);
	void cargarSpritesAlReves(int x, int y, int cantidad);
	void comenzar();
	void detener();
	void dibujar(SDL_Rect cuadroDeVentana);
	std::string obtenerNombre();
	int obtenerIndiceSprite();
	void cambiarSprite(int indice);
	virtual ~Animacion();

private:
	void renderizar(SDL_Rect cuadroDeVentana);
};

#endif
