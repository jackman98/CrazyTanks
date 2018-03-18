#include "tank.h"

Tank::Tank(vector<vector<Cell> > &field, int x, int y, int id, Type type) : x(x), y(y), id(id), type(type)
{
    string displaySymbol;
    switch (type) {
    case ENEMY:
        displaySymbol = "@";
        paintEnemyTank(field, Direction::NONE);
        break;
    case MAIN:
        displaySymbol = "#";
        paintMainTank(field, Direction::UP);
        break;
    default:
        break;
    }
}

void Tank::move(vector<vector<Cell> > &field, Direction direction)
{

    std::string codeBlock, codeBlock2, codeBlock3;
    switch (direction) {
    case LEFT:
        codeBlock = field.at(y).at(x - 2).getCell();
        codeBlock2 = field.at(y - 1).at(x - 2).getCell();
        codeBlock3 = field.at(y + 1).at(x - 2).getCell();

        if (codeBlock != "$" && codeBlock2 != "$" && codeBlock3 != "$" &&
                codeBlock != "@"  && codeBlock2 != "@" && codeBlock3 != "@"&&
                codeBlock != "#"  && codeBlock2 != "#" && codeBlock3 != "#") {
            field.at(y).at(x).id = -1;
            if (type == MAIN) paintMainTank(field, LEFT);
            else paintEnemyTank(field, LEFT);
        }
        else return;
        break;
    case RIGHT:
        codeBlock = field.at(y).at(x + 2).getCell();
        codeBlock2 = field.at(y - 1).at(x + 2).getCell();
        codeBlock3 = field.at(y + 1).at(x + 2).getCell();
        if (codeBlock != "$" && codeBlock2 != "$" && codeBlock3 != "$" &&
                codeBlock != "@"  && codeBlock2 != "@" && codeBlock3 != "@"&&
                codeBlock != "#"  && codeBlock2 != "#" && codeBlock3 != "#") {
            field.at(y).at(x).id = -1;
            if (type == MAIN) paintMainTank(field, RIGHT);
            else paintEnemyTank(field, RIGHT);
        }
        else return;
        break;
    case UP:
        codeBlock = field.at(y - 2).at(x).getCell();
        codeBlock2 = field.at(y - 2).at(x - 1).getCell();
        codeBlock3 = field.at(y - 2).at(x + 1).getCell();
        if (codeBlock != "$" && codeBlock2 != "$" && codeBlock3 != "$" &&
                codeBlock != "@"  && codeBlock2 != "@" && codeBlock3 != "@"&&
                codeBlock != "#"  && codeBlock2 != "#" && codeBlock3 != "#") {
            field.at(y).at(x).id = -1;
            if (type == MAIN) paintMainTank(field, UP);
            else paintEnemyTank(field, UP);
        }
        else return;
        break;
    case DOWN:
        codeBlock = field.at(y + 2).at(x).getCell();
        codeBlock2 = field.at(y + 2).at(x - 1).getCell();
        codeBlock3 = field.at(y + 2).at(x + 1).getCell();
        if (codeBlock != "$" && codeBlock2 != "$" && codeBlock3 != "$" &&
                codeBlock != "@"  && codeBlock2 != "@" && codeBlock3 != "@"&&
                codeBlock != "#"  && codeBlock2 != "#" && codeBlock3 != "#") {
            field.at(y).at(x).id = -1;
            if (type == MAIN) paintMainTank(field, DOWN);
            else paintEnemyTank(field, DOWN);
        }
        else return;
        break;
    default:
        break;
    }
    this->direction = direction;
}

void Tank::paintMainTank(vector<vector<Cell> > &field, Direction d)
{
    //Clear old tank place
    for(int i(y - 1); i <= y + 1; i++) {
        for(int j(x - 1); j <= x + 1; j++) {
            if (field.at(i).at(j).getCell() == "#") {
                field.at(i).at(j).setCell(" ");
                field.at(i).at(j).id = -1;
            }
        }
    }
    vector<string> turn;
    switch (d) {
    case LEFT:
        turn = { " ", "#", "#",
                 "#", "#", " ",
                 " ", "#", "#" };
         x--;
        break;
    case RIGHT:
        turn = { "#", "#", " ",
                 " ", "#", "#",
                 "#", "#", " " };
         x++;
        break;
    case UP:
        turn = { " ", "#", " ",
                 "#", "#", "#",
                 "#", " ", "#" };
        y--;
        break;
    case DOWN:
        turn = { "#", " ", "#",
                 "#", "#", "#",
                 " ", "#", " " };
         y++;
        break;
    case NONE:
        turn = { " ", "#", " ",
                 "#", "#", "#",
                 "#", " ", "#" };
        break;
    default:
        break;
    }

    int count = 0;
    for(int i(y - 1); i <= y + 1; i++) {
        for(int j(x - 1); j <= x + 1; j++) {
            field.at(i).at(j).setCell(turn[count++]);
            field.at(i).at(j).id = id;
        }
    }
}

void Tank::paintEnemyTank(vector<vector<Cell> > &field, Direction d)
{
    //Clear old tank place
    for(int i(y - 1); i <= y + 1; i++) {
        for(int j(x - 1); j <= x + 1; j++) {
            if (field.at(i).at(j).getCell() == "@") {
                field.at(i).at(j).setCell(" ");
                field.at(i).at(j).id = -1;
            }
        }
    }
    vector<string> turn;
    switch (d) {
    case LEFT:
        turn = { " ", "@", "@",
                 "@", "@", " ",
                 " ", "@", "@" };
         x--;
        break;
    case RIGHT:
        turn = { "@", "@", " ",
                 " ", "@", "@",
                 "@", "@", " " };
         x++;
        break;
    case UP:
        turn = { " ", "@", " ",
                 "@", "@", "@",
                 "@", " ", "@" };
        y--;
        break;
    case DOWN:
        turn = { "@", " ", "@",
                 "@", "@", "@",
                 " ", "@", " " };
         y++;
        break;
    case NONE:
        turn = { " ", "@", " ",
                 "@", "@", "@",
                 "@", " ", "@" };
        break;
    default:
        break;
    }

    int count = 0;
    for(int i(y - 1); i <= y + 1; i++) {
        for(int j(x - 1); j <= x + 1; j++) {
            field.at(i).at(j).setCell(turn[count++]);
            field.at(i).at(j).id = id;
        }
    }
}
