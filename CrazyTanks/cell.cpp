#include "cell.h"

Cell::Cell(std::string c) : code(c)
{

}

std::string Cell::getCell() const
{
    return code;
}

void Cell::setCell(std::string c)
{
    code = c;
}
