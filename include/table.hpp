/* Fichero que define la clase table */
#pragma once

#include <vector>
#include <iostream>

class table {
  private:
    std::vector<std::vector<int>> cells;
    int rowsNumber;
    int colsNumber;

  public:
    table(int rows, int cols);
    ~table();
    int getData(int i, int j);
    void setData (int data, int i, int j);

    std::ostream& write(std::ostream&);
    std::ostream& writeSize(std::ostream&);
};