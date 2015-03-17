/**
  * @file revelar.cpp
  * @brief Fichero para revelar mensajes en imágenes.
  *
  */

#include <iostream>
#include "codificar.h"
#include "imagenES.h"
using namespace std;

const int MAX_BUFFER  = 1000000;
const int MAX_MENSAJE = MAX_BUFFER/8;
const int MAX_NOMBRES = 256;

// Devuelve el número de píxeles de una imagen
int Dimension(TipoImagen tipo, int filas, int columnas)
{
  return filas*columnas*(1+2*(tipo == IMG_PPM));
}

// Calcula el número de bytes ocultables en una imagen
int Bytes(TipoImagen tipo, int filas, int columnas)
{
  return Dimension(tipo, filas, columnas)/8;
}

int main()
{
   char nombre[MAX_NOMBRES];
   int filas, columnas;

   /* Lectura del tipo de imagen */

   cout << "Introduzca la imagen de entrada: ";
   cin >> nombre;

   TipoImagen tipo = LeerTipoImagen(nombre, filas, columnas);
   unsigned char buffer[MAX_BUFFER];

  if(tipo == IMG_DESCONOCIDO){
    cerr << "revelar: Tipo de imagen desconocido";
    return 1;
  }

  if (tipo == IMG_PGM)
  {
    if(!LeerImagenPGM(nombre, filas, columnas, buffer))
    {
      cerr << "revelar: Fallo en la lectura de la imagen.";
      return 1;
    }
  }
  else
  {
     if(!LeerImagenPPM(nombre, filas, columnas, buffer))
     {
       cerr << "revelar: Fallo en la lectura de la imagen.";
       return 1;
     }
  }

  /* Revelar mensaje */

  int bytes = filas*columnas*(1+2*(tipo == IMG_PPM))/8;
  char mensaje[MAX_MENSAJE];

  cout << "Revelando..." << endl;
  if (Revelar(buffer, bytes, mensaje))
     cout << mensaje;
  else
  {
     cerr << "revelar: Error al intentar revelar el mensaje.";
     return 1;
  }
}

/* Fin fichero: revelar.cpp */
