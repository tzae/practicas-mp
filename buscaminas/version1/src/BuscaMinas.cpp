#include "CampoMinas.h" // Tablero.h, iostream
using namespace std;

/* Módulo principal del programa */

int main()
{
  // Valores iniciales para el tablero (en esta versión no se comprueban)
  int filas, columnas, minas;

  cout << "Dimensiones del tablero (filas y columnas): ";
  cin >> filas >> columnas;
  cout << "Número de minas (no debe ser menor que 5 ni mayor que la mitad que el número de casillas): ";
  do
  {
    cin >> minas;
  } while (minas < 5 || minas > filas*columnas/2);

  CampoMinas campo(filas, columnas, minas);
  bool algo_ha_pasado = true; // Almacena si ha pasado algo tras cada acción

  // Hasta que el juego termine, se pide una acción al usuario
  while (!campo.Explotado() && !campo.Ganado())
  {
    if (algo_ha_pasado)
      campo.PrettyPrint();

    char accion;
    int fila, columna;
    cout << "Acción: ";
    cin >> accion >> fila >> columna;
    if (accion == 'a')
      algo_ha_pasado = campo.Abre(fila, columna);
    else  // (accion == 'm'). En esta versión no comprobamos la validez
      algo_ha_pasado = campo.Marca(fila, columna);
  }

  // Se muestra si el jugador ha ganado o perdido
  campo.ImprimeTablero();
  if (campo.Explotado())
    cout << "¡Has perdido!" << endl;
  else  // (campo.Ganado())
    cout << "¡Has ganado!" << endl;
}
