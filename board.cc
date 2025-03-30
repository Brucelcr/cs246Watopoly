#include "board.h";
#include "square.h";
#include <iostream>;
#include <string>;

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


// starting from go (collect OSAP), goes clockwise, ignoring non-property spaces
// up to five I's in a row
// 0: AL, 1: ML, 2: ECH, 3: PAS, 4: HH, 5: RCH, 6: DWE, 7: CPH, 8: LHI, 9: BMH, 10: OPT, 11: EV1, 
// 12: EV2, 13: EV3, 14: PHYS, 15: B1, 16: B2, 17: EIT, 18: ESC, 19: C2, 20: MC, 21: DC
string improvements[22] = {
    "     ", "     ", "     ", "     ", "     ", "     ", "     ", "     ", 
    "     ", "     ", "     ", "     ", "     ", "     ", "     ", 
    "     ", "     ", "     ", "     ", "     ", "     ", "     "
};

// following the above formatting, indexes contain the string for the owner.
string owner[22] = {
    " ", " ", " ", " ", " ", " ", " ", " ", 
    " ", " ", " ", " ", " ", " ", " ", 
    " ", " ", " ", " ", " ", " ", " "
};

// player one takes index 0, player two takes index 1, etc, etc...
// thus, the first index is only ever filled in once at a time.
// current player cap is 6, we can increase to 7, and 8 if we change the board.
// probably  would be easier to just list the players on square, but we'll see what happens.
string players[40] = {
    "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ",
    "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ",
    "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ",
    "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      "
};

// improvements and owners array values will be replaced with corresponding square class values once implemented
void Board::updateBoard() {
    board = "_________________________________________________________________________________________\n"
    "|GOOSE  |" + owner[11] + " " + improvements[11] + 
    "|NEEDLES|" + owner[12] + " " + improvements[12] + 
    "|" + owner[13] + " " + improvements[13] + 
    "|V1     |" + owner[14] + " " + improvements[14] + 
    "|" + owner[15] + " " + improvements[15] + 
    "|CIF    |" + owner[16] + " " + improvements[16] + 
    "|GOTO   |\n"
    "|NESTING|-------|HALL   |-------|-------|       |-------|-------|       |-------|TIMS   |\n"
    "|       |EV1    |       |EV2    |EV3    |       |PHYS   |B1     |       |B2     |       |\n"
    "|       |       |       |       |       |       |       |       |       |       |       |\n"
    "|_______|_______|_______|_______|_______|_______|_______|_______|_______|_______|_______|\n"
    "|" + owner[10] + " " + improvements[10] + 
    "|                                                                       |" + owner[17] + " " + improvements[17] + "|\n"
    "|-------|                                                                       |-------|\n"
    "|OPT    |                                                                       |EIT    |\n"
    "|       |                                                                       |       |\n"
    "|_______|                                                                       |_______|\n"
    "|" + owner[9] + " " + improvements[9] + 
    "|                                                                       |"  + owner[18] + " "+ improvements[18] + "|\n"
    "|-------|                                                                       |-------|\n"
    "|BMH    |                                                                       |ESC    |\n"
    "|       |                                                                       |       |\n"
    "|_______|                                                                       |_______|\n"
    "|SLC    |                                                                       |SLC    |\n"
    "|       |                                                                       |       |\n"
    "|       |                                                                       |       |\n"
    "|       |                                                                       |       |\n"
    "|_______|                                                                       |_______|\n"
    "|" + owner[8] + " " + improvements[8] + 
    "|                                                                       |" + owner[19] + " " + improvements[19] + "|\n"
    "|-------|                                                                       |-------|\n"
    "|LHI    |                                                                       |C2     |\n"
    "|       |           _________________________________________________           |       |\n"
    "|_______|          |                                                 |          |_______|\n"
    "|UWP    |          | #   #  ###  #####  ###  ####   ###  #     #   # |          |REV    |\n"
    "|       |          | #   # #   #   #   #   # #   # #   # #     #   # |          |       |\n"
    "|       |          | # # # #####   #   #   # ####  #   # #      # #  |          |       |\n"
    "|       |          | # # # #   #   #   #   # #     #   # #       #   |          |       |\n"
    "|_______|          | ##### #   #   #    ###  #      ###  #####   #   |          |_______|\n"
    "|" + owner[7] + " " + improvements[7] + 
    "|          |_________________________________________________|          |NEEDLES|\n"
    "|-------|                                                                       |HALL   |\n"
    "|CPH    |                                                                       |       |\n"
    "|       |                                                                       |       |\n"
    "|_______|                                                                       |_______|\n"
    "|" + owner[6] + " " + improvements[6] + 
    "|                                                                       |" + owner[20] + " " + improvements[20] + "|\n"
    "|-------|                                                                       |-------|\n"
    "|DWE    |                                                                       |MC     |\n"
    "|       |                                                                       |       |\n"
    "|_______|                                                                       |_______|\n"
    "|PAC    |                                                                       |COOP   |\n"
    "|       |                                                                       |FEE    |\n"
    "|       |                                                                       |       |\n"
    "|       |                                                                       |       |\n"
    "|_______|                                                                       |_______|\n"
    "|" + owner[5] + " " + improvements[5] + 
    "|                                                                       |" + owner[21] + " " + improvements[21] + "|\n"
    "|-------|                                                                       |-------|\n"
    "|RCH    |                                                                       |DC     |\n"
    "|       |                                                                       |       |\n"
    "|_______|_______________________________________________________________________|_______|\n"
    "|DCTIMS |" + owner[4] + " " + improvements[4] + 
    "|" + owner[3] + " " + improvements[3] + 
    "|NEEDLES|" + owner[2] + " " + improvements[2] + 
    "|MKV    |TUITION|" + owner[1] + " " + improvements[1] + 
    "|SLC    |" + owner[0] + " " + improvements[0] + "|COLLECT|\n"
    "|LINE   |-------|-------|HALL   |-------|       |       |-------|       |-------|OSAP   |\n"
    "|       |HH     |PAS    |       |ECH    |       |       |ML     |       |AL     |       |\n"
    "|       |       |       |       |       |       |       |       |       |       |       |\n"
    "|_______|_______|_______|_______|_______|_______|_______|_______|_______|_______|_______|";
}

void Board::drawBoard() {
    updateBoard();   
    cout << board << endl;
}

// for testing
int main() {
    Board plank;
    plank.drawBoard();
}
