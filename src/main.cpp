/* Fichero main cuya principal función es la prueba de la clase LCS 
   Autor: Sergio Guerra Arencibia
   Asignatura: DAA
*/

#include <iostream>
#include <string>
#include <stdlib.h>

#include "table.hpp"
#include "LCS.hpp"

std::string reverse(std::string sequence) {
  std::string result;
  for (int i = sequence.length() - 1; i >= 0; i--) {
    result.push_back(sequence.at(i));
  }
  return(result);
}

bool testSolution(std::string firstSequence, std::string secondSequence,
    std::string currentResult) {
  LCS prueba(firstSequence, secondSequence);
  std::string result = prueba.solve();
  if (result.size() == currentResult.size()) 
    return true;
  else 
    return false;
}

int main (void) {
  srand(time(NULL));
  int option;


  do {
      std::string firstSequence;
      std::string secondSequence;
      std::string result;
      std::cout << "\n---MENU---\n";
      std::cout << "1.- Introducción de cadenas manual\n";
      std::cout << "2.- Generación de cadenas aleatorias\n";
      std::cout << "0.- Salir\n> ";
      std::cin >> option;
      std::cout << "\n";

    if (option == 1) {
      std::cout << "Introduzca la primera cadena: ";
      std::cin >> firstSequence;
      std::cout << "Introduzca la segunda cadena: ";
      std::cin >> secondSequence;

      LCS prueba(secondSequence, firstSequence);
      result = prueba.solve();
      std::cout <<  "Subcadena más larga: " <<  reverse(result) << "\n";
      if (testSolution(firstSequence, secondSequence, result)) {
        std::cout << "La solución ha pasado el test\n";
      }
    }
    if (option == 2) {

      int firstLength;
      int secondLength;
      std::cout << "Introduzca la lognitud de la primera cadena: ";
      std::cin >> firstLength;
      std::cout << "Introduzca la longitud de la segunda cadena: " ;
      std::cin >> secondLength;
      std::cout << "\n---CADENAS GENERADAS---\n\n";
      for (int i = 0; i < firstLength; i++) {
        char dummy = ('0' + rand() % 10);
        firstSequence.push_back(dummy);
        std::cout << dummy;
      }
      std::cout << "\n\n";
      for (int i = 0; i < secondLength; i++) {
        char dummy = ('0' + rand() % 10);
        secondSequence.push_back(dummy);
        std::cout << dummy;
      }
      std::cout << "\n";
      LCS prueba(secondSequence, firstSequence);
      result = prueba.solve();
      std::cout << "\nSubcadena más larga: " <<  reverse(result) << "\n";
      if (testSolution(firstSequence, secondSequence, result)) {
        std::cout << "La solución ha pasado el test\n";
      }
    }
  } while(option != 0);
  return(0);
}