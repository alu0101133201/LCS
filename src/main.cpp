/* Fichero main cuya principal función es la prueba de la clase LCS 
   Autor: Sergio Guerra Arencibia
   Asignatura: DAA
*/

#include <iostream>
#include <string>

#include "table.hpp"
#include "LCS.hpp"

std::string reverse(std::string sequence) {
  std::string result;
  for (int i = sequence.length() - 1; i >= 0; i--) {
    result.push_back(sequence.at(i));
  }
  return(result);
}

int main (int argc, char *argv[]) {
  if (argc < 3) {
    std::cerr << "Parámetros suministrados insuficiente\n";
    std::cerr << "./LCS <cadena> <cadena>\n";
    return (1);
  }
  std::string firstSequence = argv[1];
  std::string secondSequence = argv[2];

  // std::cout << "Primera secuencia a estudiar: " << firstSequence << "\n";
  // std::cout << "Segunda secuencia a estudiar: " << secondSequence  << "\n";
  // std::cout << "Primera secuencia a estudiar: " << firstSequence.size() << "\n";
  // std::cout << "Segunda secuencia a estudiar: " << secondSequence.size()  << "\n";

  LCS prueba(secondSequence, firstSequence);
  std::cout << reverse(prueba.solve()) << "\n";
  prueba.write(std::cout);


  return(0);
}