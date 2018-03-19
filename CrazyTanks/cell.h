#ifndef CELL_H
#define CELL_H
#include <string>

class Cell
{
public:
    Cell(std::string c);
    std::string getCell() const;
    void setCell(std::string c);
    int id;
private:
    std::string code;
};

#endif // CELL_H
