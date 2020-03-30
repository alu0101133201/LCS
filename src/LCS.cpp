/* Fichero que implementa la clase LCS
  Clase que implementará un algoritmo en programación
  dinámica para resolver el problema LCS */

#include "LCS.hpp"

// Función auxiliar para calcular el máximo
// int max (int first, int second) {
//   std::cout << "first: " << first << " second: " << second;
//   return ((first > second)? first : second);
// }

LCS::LCS(std::string sequence1, std::string sequence2):
  dinamicTable(sequence1.length(), sequence2.length()),
  firstSequence(sequence1),
  secondSequence(sequence2) {}


LCS::~LCS()
{}

void LCS::build() {
  for (int i = 0; i < firstSequence.size(); i++) {
    for (int j = 0; j < secondSequence.size(); j++) {
      if (firstSequence.at(i) == secondSequence.at(j)){
       dinamicTable.setData(dinamicTable.getData(i - 1, j - 1) + 1, i, j);
      }
      else {
        int currentData = std::max(dinamicTable.getData(i, j-1), dinamicTable.getData(i-1, j));
        dinamicTable.setData(currentData, i, j);
      }
    }
  }
}

std::string LCS::getSolution() {
  int iIndex = firstSequence.length() - 1;
  int jIndex = secondSequence.length() - 1;
  std::string result;

  while ((iIndex >= 0) && (jIndex >= 0)) {
    if (firstSequence.at(iIndex) == secondSequence.at(jIndex)) {
      result.push_back(firstSequence.at(iIndex));
      iIndex--;
      jIndex--;
    } else {
      if (dinamicTable.getData(iIndex - 1, jIndex) < dinamicTable.getData(iIndex, jIndex - 1))
        jIndex--;
      else
        iIndex--;
    }
  }
  return(result);
}


std::string LCS::solve() {
  build();
  return(getSolution());
}

std::ostream& LCS::write(std::ostream& os) {
  dinamicTable.write(os) << "\n";
  return(os);
}
