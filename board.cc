#include "property.h"
#include "board.h"
#include "square.h"
#include "player.h"
#include "game.h"
#include <iostream>
#include <string>

using namespace std;

Board::Board() {}

int impVal[40][6] = {
    {  0,   0,   0,   0,   0,   0},
    {  2,  10,  30,  90, 160, 250},
    {  0,   0,   0,   0,   0,   0},
    {  4,  20,  60, 180, 320, 450},
    {  0,   0,   0,   0,   0,   0},
    {  0,   0,   0,   0,   0,   0},
    {  6,  30,  90, 270, 400, 550},
    {  0,   0,   0,   0,   0,   0},
    {  6,  30,  90, 270, 400, 550},
    {  8,  40, 100, 300, 450, 600},
    {  0,   0,   0,   0,   0,   0},
    { 10,  50, 150, 450, 625, 750},
    {  0,   0,   0,   0,   0,   0},
    { 10,  50, 150, 450, 625, 750},
    { 12,  60, 180, 500, 700, 900},
    {  0,   0,   0,   0,   0,   0},
    { 14,  70, 200, 550, 750, 950},
    {  0,   0,   0,   0,   0,   0},
    { 14,  70, 200, 550, 750, 950},
    { 16,  80, 220, 600, 800,1000},
    {  0,   0,   0,   0,   0,   0},
    { 18,  90, 250, 700, 875,1050},
    {  0,   0,   0,   0,   0,   0},
    { 18,  90, 250, 700, 875,1050},
    { 20, 100, 300, 750, 925,1100},
    {  0,   0,   0,   0,   0,   0},
    { 22, 110, 330, 800, 975,1150},
    { 22, 110, 330, 800, 975,1150},
    {  0,   0,   0,   0,   0,   0},
    { 24, 120, 360, 850,1025,1200},
    {  0,   0,   0,   0,   0,   0},
    { 26, 130, 390, 900,1100,1275},
    { 26, 130, 390, 900,1100,1275},
    {  0,   0,   0,   0,   0,   0},
    { 28, 150, 450,1000,1200,1400},
    {  0,   0,   0,   0,   0,   0},
    {  0,   0,   0,   0,   0,   0},
    { 35, 175, 500,1100,1300,1500},
    {  0,   0,   0,   0,   0,   0},
    { 50, 200, 600,1400,1700,2000}
};

Square s[40] = {
    Square(false, Property("COLLECTOSAP",    0,   0,   impVal[ 0], "None"      )),
    Square(true,  Property("AL",            40,  50,   impVal[ 1], "Arts1"     )),
    Square(false, Property("SLC",            0,   0,   impVal[ 2], "None"      )),
    Square(true,  Property("ML",            60,  50,   impVal[ 3], "Arts1"     )),
    Square(false, Property("TUITION",        0,   0,   impVal[ 4], "None"      )),
    Square(false, Property("MKV",          200,   0,   impVal[ 5], "Residences")),
    Square(true,  Property("ECH",          100,  50,   impVal[ 6], "Arts2"     )),
    Square(false, Property("NEEDLESHALL",    0,   0,   impVal[ 7], "None"      )),
    Square(true,  Property("PAS",          100,  50,   impVal[ 8], "Arts2"     )),
    Square(true,  Property("HH",           120,  50,   impVal[ 9], "Arts2"     )),
    Square(false, Property("DCTIMSLINE",     0,   0,   impVal[10], "None"      )),
    Square(true,  Property("RCH",          140, 100,   impVal[11], "Eng"       )),
    Square(true,  Property("PAC",          150,   0,   impVal[12], "Gym"       )),
    Square(true,  Property("DWE",          140, 100,   impVal[13], "Eng"       )),
    Square(true,  Property("CPH",          160, 100,   impVal[14], "Eng"       )),
    Square(false, Property("UWP",          200,   0,   impVal[15], "Residences")),
    Square(true,  Property("LHI",          180, 100,   impVal[16], "Health"    )),
    Square(false, Property("SLC",            0,   0,   impVal[17], "None"      )),
    Square(true,  Property("BMH",          180, 100,   impVal[18], "Health"    )),
    Square(true,  Property("OPT",          200, 100,   impVal[19], "Health"    )),
    Square(false, Property("GOOSENESTING",   0,   0,   impVal[20], "None"      )),
    Square(true,  Property("EV1",          220, 150,   impVal[21], "Env"       )),
    Square(false, Property("NEEDLESHALL",    0,   0,   impVal[22], "None"      )),
    Square(true,  Property("EV2",          220, 150,   impVal[23], "Env"       )),
    Square(true,  Property("EV3",          240, 150,   impVal[24], "Env"       )),
    Square(true,  Property("V1",           200,   0,   impVal[25], "Residences")),
    Square(true,  Property("PHYS",         260, 150,   impVal[26], "Sci1"      )),
    Square(true,  Property("B1",           260, 150,   impVal[27], "Sci1"      )),
    Square(false, Property("CIF",          150,   0,   impVal[28], "Gym"       )),
    Square(true,  Property("B2",           280, 150,   impVal[29], "Sci1"      )),
    Square(false, Property("GOTOTIMS",       0,   0,   impVal[30], "None"      )),
    Square(true,  Property("EIT",          300, 200,   impVal[31], "Sci2"      )),
    Square(true,  Property("ESC",          300, 200,   impVal[32], "Sci2"      )),
    Square(false, Property("SLC",            0,   0,   impVal[33], "None"      )),
    Square(true,  Property("C2",           320, 200,   impVal[34], "Sci2"      )),
    Square(false, Property("REV",          200,   0,   impVal[35], "Residences")),
    Square(false, Property("NEEDLESHALL",    0,   0,   impVal[36], "None"      )),
    Square(true,  Property("MC",           350, 200,   impVal[37], "Math"      )),
    Square(false, Property("COOPFEE",        0,   0,   impVal[38], "None"      )),
    Square(true,  Property("DC",           400, 200,   impVal[39], "Math"      ))
};



// improvements and owners array values will be replaced with corresponding square class values once implemented
void Board::updateBoard() {
    board = "_________________________________________________________________________________________\n"
    "|GOOSE  |" + s[11].getProperty().getOwner() + " " + viewImprovements(11) + 
    "|NEEDLES|" + s[12].getProperty().getOwner() + " " + viewImprovements(12) + 
    "|" + s[13].getProperty().getOwner() + " " + viewImprovements(13) + 
    "|V1     |" + s[14].getProperty().getOwner() + " " + viewImprovements(14) + 
    "|" + s[15].getProperty().getOwner() + " " + viewImprovements(15) + 
    "|CIF    |" + s[16].getProperty().getOwner() + " " + viewImprovements(16) + 
    "|GOTO   |\n"
    "|NESTING|-------|HALL   |-------|-------|       |-------|-------|       |-------|TIMS   |\n"
    "|       |EV1    |       |EV2    |EV3    |       |PHYS   |B1     |       |B2     |       |\n"
    "|" + s[20].getPlayers() + "|" + s[21].getPlayers() + "|" + s[22].getPlayers() + "|" + s[23].getPlayers() + 
    "|" + s[24].getPlayers() + "|" + s[25].getPlayers() + "|" + s[26].getPlayers() + "|" + s[27].getPlayers() + 
    "|" + s[28].getPlayers() + "|" + s[29].getPlayers() + "|" + s[30].getPlayers() + "|\n"
    "|_______|_______|_______|_______|_______|_______|_______|_______|_______|_______|_______|\n"
    "|" + s[10].getProperty().getOwner() + " " + viewImprovements(10) + 
    "|                                                                       |" + 
    s[17].getProperty().getOwner() + " " + viewImprovements(17) + "|\n"
    "|-------|                                                                       |-------|\n"
    "|OPT    |                                                                       |EIT    |\n"
    "|" + s[19].getPlayers() + "|                                                                       |" + 
    s[31].getPlayers() + "|\n"
    "|_______|                                                                       |_______|\n"
    "|" + s[9].getProperty().getOwner() + " " + viewImprovements(9) + 
    "|                                                                       |"  + 
    s[18].getProperty().getOwner() + " "+ viewImprovements(18) + "|\n"
    "|-------|                                                                       |-------|\n"
    "|BMH    |                                                                       |ESC    |\n"
    "|" + s[18].getPlayers() + "|                                                                       |" + 
    s[32].getPlayers() + "|\n"
    "|_______|                                                                       |_______|\n"
    "|SLC    |                                                                       |SLC    |\n"
    "|       |                                                                       |       |\n"
    "|       |                                                                       |       |\n"
    "|" + s[17].getPlayers() + "|                                                                       |" + 
    s[33].getPlayers() + "|\n"
    "|_______|                                                                       |_______|\n"
    "|" + s[8].getProperty().getOwner() + " " + viewImprovements(8) + 
    "|                                                                       |" + 
    s[19].getProperty().getOwner() + " " + viewImprovements(19) + "|\n"
    "|-------|                                                                       |-------|\n"
    "|LHI    |                                                                       |C2     |\n"
    "|" + s[16].getPlayers() + "|           _________________________________________________           |" + 
    s[34].getPlayers() + "|\n"
    "|_______|          |                                                 |          |_______|\n"
    "|UWP    |          | #   #  ###  #####  ###  ####   ###  #     #   # |          |REV    |\n"
    "|       |          | #   # #   #   #   #   # #   # #   # #     #   # |          |       |\n"
    "|       |          | # # # #####   #   #   # ####  #   # #      # #  |          |       |\n"
    "|" + s[15].getPlayers() + "|          | # # # #   #   #   #   # #     #   # #       #   |          |" + 
    s[35].getPlayers() + "|\n"
    "|_______|          | ##### #   #   #    ###  #      ###  #####   #   |          |_______|\n"
    "|" + s[7].getProperty().getOwner() + " " + viewImprovements(7) + 
    "|          |_________________________________________________|          |NEEDLES|\n"
    "|-------|                                                                       |HALL   |\n"
    "|CPH    |                                                                       |       |\n"
    "|" + s[14].getPlayers() + "|                                                                       |" + 
    s[36].getPlayers() + "|\n"
    "|_______|                                                                       |_______|\n"
    "|" + s[6].getProperty().getOwner() + " " + viewImprovements(6) + 
    "|                                                                       |" + 
    s[20].getProperty().getOwner() + " " + viewImprovements(20) + "|\n"
    "|-------|                                                                       |-------|\n"
    "|DWE    |                                                                       |MC     |\n"
    "|" + s[13].getPlayers() + "|                                                                       |" + 
    s[37].getPlayers() + "|\n"
    "|_______|                                                                       |_______|\n"
    "|PAC    |                                                                       |COOP   |\n"
    "|       |                                                                       |FEE    |\n"
    "|       |                                                                       |       |\n"
    "|" + s[12].getPlayers() + "|                                                                       |" + 
    s[38].getPlayers() + "|\n"
    "|_______|                                                                       |_______|\n"
    "|" + s[5].getProperty().getOwner() + " " + viewImprovements(5) + 
    "|                                                                       |" + 
    s[21].getProperty().getOwner() + " " + viewImprovements(21) + "|\n"
    "|-------|                                                                       |-------|\n"
    "|RCH    |                                                                       |DC     |\n"
    "|" + s[11].getPlayers() + "|                                                                       |" + 
    s[39].getPlayers() + "|\n"
    "|_______|_______________________________________________________________________|_______|\n"
    "|DCTIMS |" + s[4].getProperty().getOwner() + " " + viewImprovements(4) + 
    "|" + s[3].getProperty().getOwner() + " " + viewImprovements(3) + 
    "|NEEDLES|" + s[2].getProperty().getOwner() + " " + viewImprovements(2) + 
    "|MKV    |TUITION|" + s[1].getProperty().getOwner() + " " + viewImprovements(1) + 
    "|SLC    |" + s[0].getProperty().getOwner() + " " + viewImprovements(0) + "|COLLECT|\n"
    "|LINE   |-------|-------|HALL   |-------|       |       |-------|       |-------|OSAP   |\n"
    "|       |HH     |PAS    |       |ECH    |       |       |ML     |       |AL     |       |\n"
    "|" + s[10].getPlayers() + "|" + s[9].getPlayers() + "|" + s[8].getPlayers() + "|" + s[7].getPlayers() + 
    "|" + s[6].getPlayers() + "|" + s[5].getPlayers() + "|" + s[4].getPlayers() + "|" + s[3].getPlayers() + 
    "|" + s[2].getPlayers() + "|" + s[1].getPlayers() + "|" + s[0].getPlayers() + "|\n"
    "|_______|_______|_______|_______|_______|_______|_______|_______|_______|_______|_______|";
}

void Board::drawBoard() {
    updateBoard();   
    cout << board << endl;
}

void auction(vector<Player> players) {
    int value = 0;
    int round = 0;
    int lastbid = 0;
    bool isPurchased = false;

    while (!isPurchased) {
        if (round == (int) players.size()) {
            players[lastbid].paySchool(value);
        }
        cout << "Bid" + to_string(value + 10) + "? (Y/N)" << endl;
        string choice;
        while (true) {
            std::cin >> choice;
            if (choice == "Y") {
                round = 0;
                value += 10;
                break;
            }
            else if (choice == "N") {
                round++;
                // pass to next player
                break;
            }
            std::cout << "Invalid choice. Enter Y or N: ";
        }
    }
}

string Board::viewImprovements(int index) {
    int level = s[index].getProperty().getImprovements();
    string out(level, 'X');
    string outToo(5-level, ' ');
    
    return out + outToo;
}

// for testing
// int main() {
//     Board plank;
//     plank.drawBoard();
// }
