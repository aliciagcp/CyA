// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Inforḿatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Pŕactica 2: Símbolos, alfabetos y cadenas
// Autor: Alicia Guadalupe Cruz Pérez
// Correo: alu0101420868@ull.es
// Fecha: 07/10/2021
// Archivo cya-P02-Strings.cc: programa cliente.
//         Contiene la función main del proyecto que usa las clases X e Y
//         que realizan el trabajo de leer el fichero de entrada
//         identificando patrones en el texto que dan lugar
//         al fichero de salida.
// Referencias:
//          Enlaces de inteŕes
//
// Historial de revisiones
//          04/10/2021 - Creacíon (primera versíon) del ćodigo

#include "alfabetos.h"

#include <iostream>
#include <vector>

int Cadena::Longitud() { return cadena_.length(); }

std::string Cadena::Inversa() {
  std::string inversa{""};
  std::string cadena{cadena_};
  for (size_t i = cadena.length() - 1; i > 0; i--) {
    inversa += cadena.at(i);
  }
  inversa.push_back(cadena[0]);
  return inversa;
}

std::string Cadena::Prefijos() {
  std::string cadena{cadena_};
  std::string cambio_prefijos{""};
  std::string prefijos{""};
  for (size_t i = 0; i < cadena.length(); i++) {
    cambio_prefijos.push_back(cadena.at(i));
    prefijos += cambio_prefijos;
    prefijos += " ";
  }
  return prefijos;
}

std::string Cadena::Sufijos() {
  std::string cadena{cadena_};
  Cadena cambio_sufijos{""};
  std::string sufijos{""};
  for (size_t i = cadena.length() - 1; i > 0; i--) {
    cambio_sufijos.cadena_.push_back(cadena.at(i));
    sufijos += cambio_sufijos.Inversa();
    sufijos += " ";
  }
  cambio_sufijos.cadena_.push_back(cadena.at(0));
  sufijos += cambio_sufijos.Inversa();
  return sufijos;
}

std::string Cadena::Subcadenas() {
  std::string cadena{cadena_};
  std::string cambio_subcadenas{""};
  std::string subcadenas{""};
  size_t contador{0};
  while (contador != cadena.length()) {
    for (size_t i = contador; i < cadena.length(); i++) {
      cambio_subcadenas.push_back(cadena.at(i));
      subcadenas += cambio_subcadenas;
      subcadenas += " ";
    }
    cambio_subcadenas.erase();
    contador++;
  }
  return subcadenas;
}
