/* Fichero que implementa la clase table */

#include "table.hpp"

table::table(int rows, int cols) {
  rowsNumber = rows;
  colsNumber = cols;
  cells.resize(rows);
  for (int i = 0; i < rows; i++) {
    cells[i].resize(cols);
  }
}

table::~table() {}

int table::getData(int i, int j) {
  if ((i < rowsNumber) && (i >= 0) && (j < colsNumber) && (j >= 0)){
    return (cells[i][j]);
  }
  else
    return 0;
}

void table::setData(int data, int i, int j) {
  cells[i][j] = data;
}

std::ostream& table::write(std::ostream& os) {
  for (int i = 0; i < rowsNumber; i++) {
    os << "\n";
    for (int j = 0; j < colsNumber; j++) {
      os << cells[i][j] << " ";
    }
  }
  return(os);
}

std::ostream& table::writeSize(std::ostream& os) {
  os << "Dimensiones de la tabla: " << rowsNumber << " x " << colsNumber << "\n";
  return os;
}
