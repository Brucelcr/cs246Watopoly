#include "property.h"
#include "board.h"
#include "square.h"
#include <iostream>
#include <string>

using namespace std;

Board::Board() {}

Square s[40] = { // if you're checking for square name, note that the name is allcaps no spaces. 
    Square("COLLECTOSAP", false), 
    Square("AL", true), 
    Square("SLC", false), 
    Square("ML", true), 
    Square("TUITION", false), 
    Square("MKV", false), 
    Square("ECH", true), 
    Square("NEEDLESHALL", false), 
    Square("PAS", true), 
    Square("HH", true), 
    Square("DCTIMSLINE", false), 
    Square("RCH", true), 
    Square("PAC", false), 
    Square("DWE", true), 
    Square("CPH", true), 
    Square("UWP", false), 
    Square("LHI", true), 
    Square("SLC", false), 
    Square("BMH", true), 
    Square("OPT", true), 
    Square("GOOSENESTING", false), 
    Square("EV1", true), 
    Square("NEEDLESHALL", false), 
    Square("EV2", true), 
    Square("EV3", true), 
    Square("V1", false), 
    Square("PHYS", true), 
    Square("B1", true), 
    Square("CIF", false), 
    Square("B2", true), 
    Square("GOTOTIMS", false), 
    Square("EIT", true), 
    Square("ESC", true), 
    Square("SLC", false), 
    Square("C2", true), 
    Square("REV", false), 
    Square("NEEDLESHALL", false), 
    Square("MC", true), 
    Square("COOPFEE", false), 
    Square("DC", true)    
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
    "|       |       |       |       |       |       |       |       |       |       |       |\n"
    "|_______|_______|_______|_______|_______|_______|_______|_______|_______|_______|_______|\n"
    "|" + s[10].getProperty().getOwner() + " " + viewImprovements(10) + 
    "|                                                                       |" + 
    s[17].getProperty().getOwner() + " " + viewImprovements(17) + "|\n"
    "|-------|                                                                       |-------|\n"
    "|OPT    |                                                                       |EIT    |\n"
    "|       |                                                                       |       |\n"
    "|_______|                                                                       |_______|\n"
    "|" + s[9].getProperty().getOwner() + " " + viewImprovements(9) + 
    "|                                                                       |"  + 
    s[18].getProperty().getOwner() + " "+ viewImprovements(18) + "|\n"
    "|-------|                                                                       |-------|\n"
    "|BMH    |                                                                       |ESC    |\n"
    "|       |                                                                       |       |\n"
    "|_______|                                                                       |_______|\n"
    "|SLC    |                                                                       |SLC    |\n"
    "|       |                                                                       |       |\n"
    "|       |                                                                       |       |\n"
    "|       |                                                                       |       |\n"
    "|_______|                                                                       |_______|\n"
    "|" + s[8].getProperty().getOwner() + " " + viewImprovements(8) + 
    "|                                                                       |" + 
    s[19].getProperty().getOwner() + " " + viewImprovements(19) + "|\n"
    "|-------|                                                                       |-------|\n"
    "|LHI    |                                                                       |C2     |\n"
    "|       |           _________________________________________________           |       |\n"
    "|_______|          |                                                 |          |_______|\n"
    "|UWP    |          | #   #  ###  #####  ###  ####   ###  #     #   # |          |REV    |\n"
    "|       |          | #   # #   #   #   #   # #   # #   # #     #   # |          |       |\n"
    "|       |          | # # # #####   #   #   # ####  #   # #      # #  |          |       |\n"
    "|       |          | # # # #   #   #   #   # #     #   # #       #   |          |       |\n"
    "|_______|          | ##### #   #   #    ###  #      ###  #####   #   |          |_______|\n"
    "|" + s[7].getProperty().getOwner() + " " + viewImprovements(7) + 
    "|          |_________________________________________________|          |NEEDLES|\n"
    "|-------|                                                                       |HALL   |\n"
    "|CPH    |                                                                       |       |\n"
    "|       |                                                                       |       |\n"
    "|_______|                                                                       |_______|\n"
    "|" + s[6].getProperty().getOwner() + " " + viewImprovements(6) + 
    "|                                                                       |" + 
    s[20].getProperty().getOwner() + " " + viewImprovements(20) + "|\n"
    "|-------|                                                                       |-------|\n"
    "|DWE    |                                                                       |MC     |\n"
    "|       |                                                                       |       |\n"
    "|_______|                                                                       |_______|\n"
    "|PAC    |                                                                       |COOP   |\n"
    "|       |                                                                       |FEE    |\n"
    "|       |                                                                       |       |\n"
    "|       |                                                                       |       |\n"
    "|_______|                                                                       |_______|\n"
    "|" + s[5].getProperty().getOwner() + " " + viewImprovements(5) + 
    "|                                                                       |" + 
    s[21].getProperty().getOwner() + " " + viewImprovements(21) + "|\n"
    "|-------|                                                                       |-------|\n"
    "|RCH    |                                                                       |DC     |\n"
    "|       |                                                                       |       |\n"
    "|_______|_______________________________________________________________________|_______|\n"
    "|DCTIMS |" + s[4].getProperty().getOwner() + " " + viewImprovements(4) + 
    "|" + s[3].getProperty().getOwner() + " " + viewImprovements(3) + 
    "|NEEDLES|" + s[2].getProperty().getOwner() + " " + viewImprovements(2) + 
    "|MKV    |TUITION|" + s[1].getProperty().getOwner() + " " + viewImprovements(1) + 
    "|SLC    |" + s[0].getProperty().getOwner() + " " + viewImprovements(0) + "|COLLECT|\n"
    "|LINE   |-------|-------|HALL   |-------|       |       |-------|       |-------|OSAP   |\n"
    "|       |HH     |PAS    |       |ECH    |       |       |ML     |       |AL     |       |\n"
    "|       |       |       |       |       |       |       |       |       |       |       |\n"
    "|_______|_______|_______|_______|_______|_______|_______|_______|_______|_______|_______|";
}

void Board::drawBoard() {
    updateBoard();   
    cout << board << endl;
}

string viewImprovements(int index) {
    int level = s[index].getProperty().improvements;
    string out(level, 'X');
    string outToo(5-level, ' ');
    
    return out + outToo;
}

// for testing
int main() {
    Board plank;
    plank.drawBoard();
}
