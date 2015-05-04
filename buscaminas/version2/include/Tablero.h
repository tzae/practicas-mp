#ifndef _TABLERO_H_
#define _TABLERO_H_

// Estructura con información para cada casilla
struct Casilla
{
  bool bomba;
  bool abierta;
  bool marcada;

  Casilla()
  :bomba(false),abierta(false),marcada(false)
  {}
};


// Clase Tablero y cabeceras
class Tablero
{
  Casilla* datos;
  Casilla matriz[20][20];
  int filas, columnas;

public:
  Tablero(int f, int c)
  :filas(f), columnas(c)
  {
    datos = new Casilla[filas*columnas];
  }

  // Constructor de copia
  Tablero(const Tablero& t)
  :filas(t.filas), columnas(t.columnas)
  {
    datos = new Casilla(filas*columnas);
    for (int i = 0; i < filas*columnas; i++)
      datos[i] = t.datos[i];
  }

  // Sobrecarga de operador de asignación
  &Tablero operator=(const Tablero& t)
  :filas(t.filas), columnas(t.columnas)
  {
    datos = new Casilla(filas*columnas);
    for (int i = 0; i < filas*columnas; i++)
      datos[i] = t.datos[i];
  }

  // Destructor
  ~Tablero()
  {
    delete [] datos;
  }

  // Devuelve el número de filas del tablero
  int Filas() const;

  // Devuelve el número de filas del tablero
  int Columnas() const;

  // Obtiene la estructura de una casilla
  // Prec: fila <= 0 < filas, columna <= 0 < columnas
  Casilla Get(int fila, int columna) const;

  // Fija la estructura de una casilla
  // Prec: fila <= 0 < filas, columna <= 0 < columnas
  void Set(int fila, int columna, const Casilla &c);
};

#endif