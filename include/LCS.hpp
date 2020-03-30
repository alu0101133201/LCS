/* Fichero que define la clase LCS
  Clase que implementará un algoritmo en programación
  dinámica para resolver el problema LCS */
#pragma once

#include <string>
#include "table.hpp"

class LCS {
  private:
    table dinamicTable;
    std::string firstSequence;
    std::string secondSequence;

    void build();
    std::string getSolution();

  public:
    LCS(std::string, std::string);
    ~LCS();

    std::string solve();


    std::ostream& write(std::ostream&);

};