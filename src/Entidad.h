#ifndef ENTIDAD
#define ENTIDAD

#include <string>
#include <iostream>
#include <sstream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Logger.h"

class Entidad {

private:
	unsigned int id;
	SDL_Color color;
	std::string rutaImagen;
	int x;
	int y;
	int indexZ;
	SDL_Texture *imagen;
	Logger *log;

public:
	Entidad();
	Entidad(unsigned int id, std::string color, std::string rutaImagen, int x, int y, unsigned int indexZ, Logger *log);
	virtual void dibujar(SDL_Renderer *renderer, SDL_Rect *camara) = 0;
	void setearColor(SDL_Renderer *renderer);
	virtual ~Entidad();
	int obtenerX();
	int obtenerY();
	SDL_Texture* obtenerImagen();
	bool tieneRutaImagen();
	int cargarImagen(SDL_Renderer *renderer, Logger *log);
	bool indexZMenorA(const Entidad *otraEntidad) const;
	bool indexZes(int otroIndexZ);
    Logger* getLog() const;
    void setLog(Logger *log);
	string toString();
    unsigned int getId() const;
    int getIndexZ() const;
    std::string getRutaImagen() const;
    int getX() const;
    int getY() const;


private:
	SDL_Color convertirColor(std::string color);
	void destruirImagen();
	std::string intToString(int number);

};

#endif
