#include "cell.h"

Cell::Cell(std::string c) : code(c)
{
    id = -1;
}

std::string Cell::getCell() const
{
    return code;
}

void Cell::setCell(std::string c)
{
    code = c;
}
