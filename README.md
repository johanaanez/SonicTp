#  Taller de programación 1: 2017 1er Cuatrimestre, 1er tp.
#  Integrantes 
    Añez Johana 93042,
    Dimasi Patricia, 
    Ponce Julieta,
    Quino Julián 94224,
    Villani Cristian 93358,

# Sistema Operativo 
  Linux, Ubuntu.  
  
# Librerias
    SDL2 version 2.0.5, link : http://packages.ubuntu.com/search?keywords=sdl2
    SDL2_IMAGE version 2.0, link : https://www.libsdl.org/projects/SDL_image/
    Jannson, version 2.10, link : http://www.digip.org/jansson/releases/
    STL
  
# Compilación por consola
    g++ src/capas.cpp src/Circulo.cpp src/ConstructorEntidades.cpp src/Control.cpp src/Camara.cpp src/dimensiones.cpp 
    src/Entidad.cpp src/jcirculo.cpp src/jconfiguracion.cpp src/jentidades.cpp src/jescenario.cpp src/jescenarioJuego.cpp 
    src/jpruebas.cpp src/jrectangulo.cpp src/jventana.cpp  src/Logger.cpp src/Mensaje.cpp src/parseadorJson.cpp 
    src/Personaje.cpp src/Rectangulo.cpp src/Sonictp.cpp src/Textura.cpp  src/VistaSDL.cpp -lSDL2 -lSDL2_image -ljansson 
    -o sonictp

# Ejecución
    ./sonictp 1

1 es esl nivel del logger, puede ser 2 o 3.
Por default toma el valor 2.