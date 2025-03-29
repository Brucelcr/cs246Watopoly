import <iostream>;
import <string>;

using namespace std;

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

// improvements and owners array values will be replaced with corresponding square class values once implemented
string updateBoard() {
    return "_________________________________________________________________________________________\n"
    "|Goose  |" + owner[11] + " " + improvements[11] + 
    "|NEEDLES|" + owner[12] + " " + improvements[12] + 
    "|" + owner[13] + " " + improvements[13] + 
    "|V1     |" + owner[14] + " " + improvements[14] + 
    "|" + owner[15] + " " + improvements[15] + 
    "|CIF    |" + owner[16] + " " + improvements[16] + 
    "|GOTO   |\n"
    "|Nesting|-------|HALL   |-------|-------|       |-------|-------|       |-------|TIMS   |\n"
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
    "|DCTims |" + owner[4] + " " + improvements[4] + 
    "|" + owner[3] + " " + improvements[3] + 
    "|NEEDLES|" + owner[2] + " " + improvements[2] + 
    "|MKV    |TUITION|" + owner[1] + " " + improvements[1] + 
    "|SLC    |" + owner[0] + " " + improvements[0] + "|COLLECT|\n"
    "|Line   |-------|-------|HALL   |-------|       |       |-------|       |-------|OSAP   |\n"
    "|       |HH     |PAS    |       |ECH    |       |       |ML     |       |AL     |       |\n"
    "|       |       |       |       |       |       |       |       |       |       |       |\n"
    "|_______|_______|_______|_______|_______|_______|_______|_______|_______|_______|_______|";
}

void drawboard() {
    string board = updateBoard();   
    cout << board << endl;
}

// for testing
int main() {
    drawboard();
}
