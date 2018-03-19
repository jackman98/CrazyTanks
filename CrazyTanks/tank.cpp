#include "tank.h"


Tank::Tank(vector<vector<Cell> > &field, int x, int y, int id, Type type) : x(x), y(y), id(id), type(type)
{
    //init tank
    paintTank(field, Direction::NONE);
    if (type == MAIN)
        health = MY_HEALTH;
    else if (type == ENEMY)
        health = ENEMY_HEALTH;
}

bool Tank::Tank::checkingFreePlaceBeforeTank(vector<vector<Cell> > &field, Direction direction)
{
    //symbols for checking
    string codeCell, codeCell2, codeCell3;

    //definition this symbols
    switch (direction) {
    case LEFT:
        codeCell = field.at(y).at(x - 2).getCell();
        codeCell2 = field.at(y - 1).at(x - 2).getCell();
        codeCell3 = field.at(y + 1).at(x - 2).getCell();
        break;
    case RIGHT:
        codeCell = field.at(y).at(x + 2).getCell();
        codeCell2 = field.at(y - 1).at(x + 2).getCell();
        codeCell3 = field.at(y + 1).at(x + 2).getCell();
        break;
    case UP:
        codeCell = field.at(y - 2).at(x).getCell();
        codeCell2 = field.at(y - 2).at(x - 1).getCell();
        codeCell3 = field.at(y - 2).at(x + 1).getCell();
        break;
    case DOWN:
        codeCell = field.at(y + 2).at(x).getCell();
        codeCell2 = field.at(y + 2).at(x - 1).getCell();
        codeCell3 = field.at(y + 2).at(x + 1).getCell();
        break;
    case NONE:
        break;
    }

    //checking symbols
    if (codeCell != "$" && codeCell2 != "$" && codeCell3 != "$" &&
            codeCell != "@"  && codeCell2 != "@" && codeCell3 != "@"&&
            codeCell != "#"  && codeCell2 != "#" && codeCell3 != "#") {
        //if free place
        return true;
    }

    return false;
}

void Tank::move(vector<vector<Cell> > &field, Direction direction)
{
    switch (direction) {
    case LEFT:
        if (checkingFreePlaceBeforeTank(field, LEFT)) {
            paintTank(field, LEFT);
        }
        else return;
        break;
    case RIGHT:
        if (checkingFreePlaceBeforeTank(field, RIGHT)) {
            paintTank(field, RIGHT);
        }
        else return;
        break;
    case UP:
        if (checkingFreePlaceBeforeTank(field, UP)) {
            paintTank(field, UP);
        }
        else return;
        break;
    case DOWN:
        if (checkingFreePlaceBeforeTank(field, DOWN)) {
            paintTank(field, DOWN);
        }
        else return;
        break;
    default:
        break;
    }
    this->direction = direction;
}

void Tank::paintTank(vector<vector<Cell> > &field, Direction d)
{
    //clear old tank place
    string fillingSymbol;
    if (type == MAIN)
        fillingSymbol = "#";
    else if (type == ENEMY)
        fillingSymbol = "@";

    for(int i(y - 1); i <= y + 1; i++) {
        for(int j(x - 1); j <= x + 1; j++) {
            if (field.at(i).at(j).getCell() == fillingSymbol) {
                field.at(i).at(j).setCell(" ");
                field.at(i).at(j).id = -1;///why
            }
        }
    }

    //tank direction
    vector<string> turn;
    switch (d) {
    case LEFT:
        turn = { " ", fillingSymbol, fillingSymbol,
                 fillingSymbol, fillingSymbol, " ",
                 " ", fillingSymbol, fillingSymbol };/////////
         x--;
        break;
    case RIGHT:
        turn = { fillingSymbol, fillingSymbol, " ",
                 " ", fillingSymbol, fillingSymbol,
                 fillingSymbol, fillingSymbol, " " };
         x++;
        break;
    case UP:
        turn = { " ", fillingSymbol, " ",
                 fillingSymbol, fillingSymbol, fillingSymbol,
                 fillingSymbol, " ", fillingSymbol };
        y--;
        break;
    case DOWN:
        turn = { fillingSymbol, " ", fillingSymbol,
                 fillingSymbol, fillingSymbol, fillingSymbol,
                 " ", fillingSymbol, " " };
         y++;
        break;
    case NONE:
        turn = { " ", fillingSymbol, " ",
                 fillingSymbol, fillingSymbol, fillingSymbol,
                 fillingSymbol, " ", fillingSymbol };
        break;
    default:
        break;
    }

    //set new position on the field
    int count = 0;
    for(int i(y - 1); i <= y + 1; i++) {
        for(int j(x - 1); j <= x + 1; j++) {
            field.at(i).at(j).setCell(turn[count++]);
            field.at(i).at(j).id = id;
        }
    }
}
