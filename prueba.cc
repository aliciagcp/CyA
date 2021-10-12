#include <iostream>
#include <vector>

int Longitud(std::string cadena, std::vector<std::string> alfabeto) {
  std::string cadena_auxiliar{""};
  int size{0};
  for (size_t i{0}; i < cadena.length(); ++i) {
    cadena_auxiliar += cadena.at(i);
    for (size_t j{0}; j < alfabeto.size(); ++j) {
      if (cadena_auxiliar == alfabeto[j]) {
        ++size;
        cadena_auxiliar.erase();
      }
    }
  }
  return size;
}

// adioshola - holaadios
std::string Inversa(std::string cadena, std::vector<std::string> simbolos) {
  std::string inversa_final{""};
  std::string inversa_cadena{""};
  std::string inversa{""};
  std::vector<std::string> inversa_simbolos;
  for (size_t j = 0; j < simbolos.size(); j++) {
    for (size_t i = simbolos[j].length() - 1; i > 0; i--) {
      inversa += simbolos[j].at(i);
    }
    inversa += simbolos[j].at(0);
    inversa_simbolos.push_back(inversa);
    inversa.erase();
  }
  for (size_t i = cadena.length() - 1; i > 0; i--) {
    inversa_cadena += cadena.at(i);
    for (size_t j = 0; j < simbolos.size(); j++) {
      std::string simbolo_invertido{inversa_simbolos[j]};
      if (inversa_cadena == simbolo_invertido) {
        inversa_final += simbolos[j];
        inversa_cadena = "";
      }
    }
  }
  inversa_cadena += cadena.at(0);
  for (size_t j = 0; j < simbolos.size(); j++) {
    if (inversa_cadena == inversa_simbolos[j]) {
      inversa_final += simbolos[j];
    }
  }
  return inversa_final;
}

// adioshola - adios / adioshola
// abbab - a / ab / abb / abba / abbab
std::string Prefijos(std::string cadena, std::vector<std::string> simbolos) {
  std::string prefijos{""};
  std::string prefijos_final{"& "};
  std::string complemento{""};
  for (size_t i = 0; i < cadena.length(); i++) {
    prefijos += cadena.at(i);
    for (size_t j = 0; j < simbolos.size(); j++) {
      if (prefijos == simbolos[j]) {
        prefijos_final += complemento;
        prefijos_final += prefijos;
        complemento += prefijos;
        prefijos_final += " ";
        prefijos.erase();
      }
    }
  }
  return prefijos_final;
}

// adioshola - hola / adioshola
// abbab - b / ab / bab / bbab / abbab
std::string Sufijos(std::string cadena, std::vector<std::string> simbolos) {
  std::string sufijos{""};
  std::string sufijos_final{"& "};
  std::string complemento{""};
  std::string complemento2{""};
  std::string inversa{""};
  std::vector<std::string> inversa_simbolos;
  for (size_t j = 0; j < simbolos.size(); j++) {
    for (size_t i = simbolos[j].length() - 1; i > 0; i--) {
      inversa += simbolos[j].at(i);
    }
    inversa += simbolos[j].at(0);
    inversa_simbolos.push_back(inversa);
    inversa.erase();
  }
  for (size_t i = cadena.length() - 1; i > 0; i--) {
    sufijos += cadena.at(i);
    for (size_t j = 0; j < simbolos.size(); j++) {
      if (sufijos == inversa_simbolos[j]) {
        sufijos_final += simbolos[j];
        sufijos_final += complemento2;
        complemento += simbolos[j];
        complemento2 = Inversa(complemento, simbolos);
        sufijos_final += " ";
        sufijos.erase();
      }
    }
  }
  sufijos += cadena.at(0);
  for (size_t j = 0; j < simbolos.size(); j++) {
    if (sufijos == inversa_simbolos[j]) {
      sufijos_final += simbolos[j];
      sufijos_final += complemento2;
      complemento += simbolos[j];
      complemento2 = Inversa(complemento, simbolos);
      sufijos_final += " ";
      sufijos.erase();
    }
  }
  return sufijos_final;
}

// abbab - a / ab / abb / abba / abbab / b / bb / bba / bbab / b / ba / bab / a/ ab / b 
// adioshola - adios / adioshola / hola

std::string Subcadenas(std::string cadena, std::vector<std::string> simbolos) {
  std::string complemento{""};
  std::string subcadena{""};
  std::string subcadena_final{"& "};
  std::vector<int> inicio{0};
  int inicio_i{0};
  int contador{0};
  while (contador != Longitud(cadena, simbolos)) {
    for (size_t i = inicio[0]; i < cadena.length(); i++) {
      subcadena += cadena.at(i);
      for (size_t j = 0; j < simbolos.size(); j++) {
        if (subcadena == simbolos[j]) {
          inicio[inicio_i] = i + 1;
          subcadena_final += complemento;
          subcadena_final += subcadena;
          complemento += simbolos[j];
          subcadena_final += " ";
          subcadena.erase();
          inicio_i++;
        }
      }
    }
    complemento.erase();
    inicio_i = 0;
    contador++;
  }
  return subcadena_final;
}

int main() {
  std::string cadena{"holaadios"};
  std::vector<std::string> simbolos{"hola", "adios"};

  std::cout << "Longitud: " << Longitud(cadena, simbolos) << std::endl;
  std::cout << "Inversa: " << Inversa(cadena, simbolos) << std::endl;
  std::cout << "Prefijos: " << Prefijos(cadena, simbolos) << std::endl;
  std::cout << "Sufijos: " << Sufijos(cadena, simbolos) << std::endl;
  std::cout << "Subcadenas: " << Subcadenas(cadena, simbolos) << std::endl;
  return 0;
}
