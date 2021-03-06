#include "Entidad.h"
#define MODULO 'ENTIDAD'

Entidad::Entidad() : id(), rutaImagen(""), x(), y(), indexZ(), imagen(NULL), log()
{

}

Entidad::Entidad(unsigned int id, std::string color, std::string rutaImagen, int x, int y, unsigned int indexZ, Logger *log)
: id(id), rutaImagen(rutaImagen), x(x), y(y), indexZ(indexZ), imagen(NULL)
{
	SDL_Color colorSDL = convertirColor(color);
	this->color=colorSDL;
	this->log = log;
	this->log->setModulo("ENTIDAD");
}

Entidad::~Entidad()
{
	destruirImagen();
}

SDL_Color Entidad::convertirColor(std::string color)
{
	SDL_Color colorSDL = {0, 0, 0, 0};
	if (color == "amarillo"){
		colorSDL.r = 255; colorSDL.g = 255; colorSDL.b = 0; colorSDL.a = 255;
	}
	else if (color == "azul"){
		colorSDL.r = 0; colorSDL.g = 0; colorSDL.b = 255; colorSDL.a = 255;
	}
	else if (color == "rojo"){
		colorSDL.r = 255; colorSDL.g = 0; colorSDL.b = 0; colorSDL.a = 255;
	}
	else if (color == "verde"){
		colorSDL.r = 0; colorSDL.g = 255; colorSDL.b = 0; colorSDL.a = 255;
	}
	else
	{
		//Color por default: rojo
		colorSDL.r = 255; colorSDL.g = 0; colorSDL.b = 0; colorSDL.a = 255;
	}
	return colorSDL;
}

void Entidad::setearColor(SDL_Renderer *renderer)
{
	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
}

int Entidad::obtenerX()
{
	return x;
}

int Entidad::obtenerY()
{
	return y;
}

SDL_Texture* Entidad::obtenerImagen()
{
	return imagen;
}

bool Entidad::tieneRutaImagen()
{
	if (rutaImagen == "")
		return false;
	else
		return true;
}

int Entidad::cargarImagen(SDL_Renderer *renderer, Logger *log)
{
	int error = 0;
	this->log->setModulo("ENTIDAD");
	this->log->addLogMessage("[CARGAR IMAGEN] Iniciado.",2);
	if ((rutaImagen != "") && (imagen != NULL))
	{
		//Imagen ya cargada
		this->log->addLogMessage("[CARGAR IMAGEN] Error cargando imagen en ruta: "+rutaImagen,1);
		return error;
	}

	SDL_Surface *imagenCargada = NULL;
	std::string rutaSinBarra;
	const char* barra = "/";

	//Si la rutaImagen empieza con una / se la saca
	if (strncmp(rutaImagen.c_str(), barra, 1) == 0)
	{
		rutaSinBarra = rutaImagen.substr(1, rutaImagen.length() - 1);
		imagenCargada=IMG_Load(rutaSinBarra.c_str());
	}
	else
	{
		imagenCargada=IMG_Load(rutaImagen.c_str());
	}

	if(imagenCargada == NULL)
	{
		std::string mensaje = "[CARGAR IMAGEN ENTIDAD] No existe imagen. Se muestra de color solido. Id: "+id;
		log->addLogMessage(mensaje, 1);
		rutaImagen = "";
		error = 1;
	}

	imagen = SDL_CreateTextureFromSurface(renderer, imagenCargada);
	SDL_FreeSurface(imagenCargada);
	this->log->addLogMessage("[CARGAR IMAGEN] Imagen cargada en ruta:"+rutaImagen,3);
	this->log->addLogMessage("[CARGAR IMAGEN] Terminado.",2);
	return error;
}

Logger* Entidad::getLog() const
{
    return log;
}

void Entidad::setLog(Logger *log)
{
    this->log = log;
    this->log->setModulo("ENTIDAD");
}

unsigned int Entidad::getId() const
{
    return id;
}

int Entidad::getIndexZ() const
{
    return indexZ;
}

std::string Entidad::getRutaImagen() const
{
    return rutaImagen;
}

int Entidad::getX() const
{
    return x;
}

int Entidad::getY() const
{
    return y;
}

void Entidad::destruirImagen()
{
	if (imagen != NULL)
	{
		SDL_DestroyTexture(imagen);
	}
}

bool Entidad::indexZMenorA(const Entidad *otraEntidad) const
{
	if (indexZ < otraEntidad->indexZ)
	{
		return true;
	}
	return false;
}

bool Entidad::indexZes(int otroIndexZ)
{
	return (indexZ == otroIndexZ);
}

std::string Entidad::intToString(int number)
{
  ostringstream oss;
  oss<< number;
  return oss.str();
}

string Entidad::toString(){
	return "id: " + intToString(id)
			+ ", coordenadas-> x:"+intToString(x)+
	", y: "+intToString(y)+", index_z: "+ intToString(indexZ)+", ruta_imagen: "+ rutaImagen;
}

