#include "Personaje.h"

const int POSICION_INICIALX = 0;
const int POSICION_INICIALY = 0;
const float REGULADOR_ALTURA_SALTO = 0.04; //Regula la altura del salto (Es como un "promedio" de tiempoDeJuego)

Personaje::Personaje(int velocidad,SDL_Renderer *render,int altoEscenario, Logger *log)
{
	this->texturaSonic = new Textura();
	this->texturaSonic->cargarImagen("images/sonicSprite.png",render, log);

	//dimensiones del personaje por defecto
	this->personajeAncho = 50;
	this->personajeAlto= 50;

	this->personajeVelocidad = velocidad;
	this->personajeAceleracion = velocidad/20;
	//posicion por defecto
    this->posicionX = POSICION_INICIALX;
    this->posicionY = altoEscenario / 2;

    this->velocidadX = 0;
    this->velocidadY = personajeVelocidad;

    this->orientacion = DERECHA;

    this->saltando = true;
    this->corriendo = false;
    this->estaQuieto = true;
    cargarSpriteSonic();

    this->log = log;

}

void Personaje::mover(int maximoAncho,int maximoAlto, float tiempoDeJuego )
{
	/*---Limite en el suelo. Luego borrarlo!---*/
	maximoAlto -= (maximoAlto/5);
	/*-----------------------------------------*/

    //mueve al personaje
    this->posicionX += this->velocidadX * tiempoDeJuego;

    //se fija si se paso los limites de la pantalla
    if( posicionX < 0 )
    {
        posicionX = 0;
    }
    else if (posicionX + this->personajeAncho >  maximoAncho){
		//this->posicionX -= velocidadX;
		this->posicionX = maximoAncho-this->personajeAncho;
	}

    //Si esta saltando lo afecta la gravedad
    if (saltando){
    	this->velocidadY += GRAVEDAD;
    }

    this->posicionY += this->velocidadY * REGULADOR_ALTURA_SALTO;

	//se fija si se paso los limites de la pantalla
	if( posicionY < 0 )
	{
		posicionY = 0;
	}
	else if (posicionY + this->personajeAlto >  maximoAlto){
		//this->posicionX -= velocidadX;
		this->posicionY = maximoAlto-this->personajeAlto;
		saltando = false; //Al tocar el piso deja de saltar
		parar();
	}
    /*posicionY += velocidadY;

    //se fija si se paso los limites
    if( ( posicionY < 0 ) || ( posicionY + this->personajeAlto > maximoAlto ) )
    {

        this->posicionY -= velocidadY;
    }*/

	//cout << "Mover: " << velocidadX << " " << velocidadY << '\n';

}

void Personaje::cargarSpriteSonic(){
	if (texturaSonic == NULL){
		return;
	}

	animacionQuietoDer = Animacion(texturaSonic, personajeAncho, 7);
	animacionCaminarDer = Animacion(texturaSonic, personajeAncho, 2);
	animacionCorrerDer = Animacion(texturaSonic, personajeAncho, 2);
	animacionSaltarDer = Animacion(texturaSonic, personajeAncho, 2);
	animacionQuietoIzq = Animacion(texturaSonic, personajeAncho, 7);
	animacionCaminarIzq = Animacion(texturaSonic, personajeAncho, 2);
	animacionCorrerIzq = Animacion(texturaSonic, personajeAncho, 2);
	animacionSaltarIzq = Animacion(texturaSonic, personajeAncho, 2);


	for (int i=0; i<10; i++){
		animacionQuietoDer.cargarSprites(0, 0, 1);
	} //Agrega el primer sprite varias veces para que se quede quieto mas tiempo
	for (int i=0; i<5; i++){
			animacionQuietoDer.cargarSprites(1, 0, 2);
	}  //Agrega los sprites moviendo el pie varias veces

	animacionCaminarDer.cargarSprites(0, 3, 8);
	animacionCorrerDer.cargarSprites(4, 1, 5);
	animacionSaltarDer.cargarSprites(4, 1, 5);

	for (int i=0; i<10; i++){
		animacionQuietoIzq.cargarSprites(9, 0, 1);
	}
	for (int i=0; i<5; i++){
		animacionQuietoIzq.cargarSprites(10, 0, 2);
	}

	animacionCaminarIzq.cargarSprites(9, 3, 8);
	animacionCorrerIzq.cargarSprites(13, 1, 5);
	animacionSaltarIzq.cargarSprites(13, 1, 5);

	animacionActual = &animacionQuietoDer;

}

void Personaje::render( int camX, int camY){

	SDL_Rect cuadroDeVentana;

	cuadroDeVentana.x=(this->posicionX-camX);
	cuadroDeVentana.y=(this->posicionY-camY);
	cuadroDeVentana.w=this->personajeAncho;
	cuadroDeVentana.h=this->personajeAlto;
	animacionActual->dibujar(cuadroDeVentana);
}

int Personaje::getPosicionX()
{
	return this->posicionX;
}

int Personaje::getPosicionY()
{
	return this->posicionY;
}
int Personaje::getAncho(){
	return this->personajeAncho;
}
int Personaje::getAlto(){
	return this->personajeAlto;
}

Personaje::~Personaje(){
	if (texturaSonic != NULL)
	{
		delete texturaSonic;
	}
}

void Personaje::dejarDeEstarQuieto()
{
	if (estaQuieto)
	{
		estaQuieto = false;
		animacionActual->detener();
	}
}

void Personaje::animarSalto()
{
	if (saltando)
	{
		switch (orientacion)
		{
			case IZQUIERDA:
				animacionActual = &animacionSaltarIzq;
				break;
			case DERECHA:
				animacionActual = &animacionSaltarDer;
				break;
		}
	}
}

void Personaje::saltar()
{
	if (!saltando)
	{
		velocidadY = -personajeVelocidad;
		saltando = true;
	}
}

void Personaje::dejarDeSaltar()
{
	if(velocidadY < (-personajeVelocidad/2))
	{
		velocidadY = (-personajeVelocidad/2);
	}
}

void Personaje::correr(bool estaCorriendo)
{
	corriendo = estaCorriendo;
}

void Personaje::irArriba()
{
	dejarDeEstarQuieto();
	animarSalto();
	animacionActual->comenzar();
}

void Personaje::irAbajo()
{
	/*this->velocidadY = this->personajeVelocidad;
	saltando = true;
	animarSalto();
	animacionActual->comenzar();*/
}

void Personaje::irIzquierda()
{
	dejarDeEstarQuieto();

	if ((corriendo) && (!saltando)){
		//this->velocidadX = -2*this->personajeVelocidad;
		this->velocidadX -= 2*personajeAceleracion;
		if(velocidadX < (-2*personajeVelocidad))
		{
			velocidadX = -2*personajeVelocidad;
		}
		animacionActual = &animacionCorrerIzq;
	}
	else{
		//this->velocidadX = -this->personajeVelocidad;
		this->velocidadX -= personajeAceleracion;
		if(velocidadX < (-personajeVelocidad))
		{
			velocidadX = -personajeVelocidad;
		}
		animacionActual = &animacionCaminarIzq;
	}

	orientacion = IZQUIERDA;
	animarSalto();
	animacionActual->comenzar();
}

void Personaje::irDerecha()
{
	dejarDeEstarQuieto();

	if ((corriendo) && (!saltando)){
		//this->velocidadX = 2*this->personajeVelocidad;
		this->velocidadX += 2*personajeAceleracion;
		if(velocidadX > 2*personajeVelocidad)
		{
			velocidadX = 2*personajeVelocidad;
		}
		animacionActual = &animacionCorrerDer;
	}
	else{
		//this->velocidadX = this->personajeVelocidad;
		this->velocidadX += personajeAceleracion;
		if(velocidadX > personajeVelocidad)
		{
			velocidadX = personajeVelocidad;
		}
		animacionActual = &animacionCaminarDer;
	}

	orientacion = DERECHA;
	animarSalto();
	animacionActual->comenzar();
}

void Personaje::parar()
{
	if (velocidadX < 0)
	{
		velocidadX += 2*personajeAceleracion;
		if (velocidadX >= 0)
			velocidadX = 0;
	}
	else if(velocidadX > 0)
	{
		velocidadX -= 2*personajeAceleracion;
		if (velocidadX <= 0)
			velocidadX = 0;
	}

	if (saltando)
		return;

	if (estaQuieto)
		return;

	velocidadY = 0;
	if (velocidadX == 0){
		estaQuieto = true;

		saltando = false;
		corriendo = false;
		animacionActual->detener();

		switch (orientacion)
		{
			case IZQUIERDA:
				animacionActual = &animacionQuietoIzq;
				break;
			case DERECHA:
				animacionActual = &animacionQuietoDer;
				break;
		}
		animacionActual->comenzar();
	}
}
