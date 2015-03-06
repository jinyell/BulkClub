/**************************************************************************
*        __          PROGRAMMED BY       : Jinyoung Ko, Nicole Montecillo
*        \_}                             : Augusto Cabrejos, Andrew Gadbois
*       .-./--.      STUDENT ID          : 589855, 2
*     /# ^^     \                        : 3, 4
*    |           |   CLASS               : CS1C
*     \         /    SECTION             : TTH 12:30-4:20PM
*      \       /     CLASS PROJECT #1    : Bulk Club
*       `"`"`"`
*     TEAM APPLE
**************************************************************************/
#include "MyHeader.h"

/**************************************************************************
 * FUNCTION DisplayMainMenu
 * ------------------------------------------------------------------------
 * This function outputs the main menu to the screen.
 * -returns nothing
 * ------------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		none
 * POST-CONDITIONS
 * 		This function prints the main menu
 *************************************************************************/
void DisplayMainMenu()
{
	//OUTPUT - Displays the main menu
	cout << "WELCOME TO BULK CLUB\n"
			"MAIN MENU\n"
			"1 - Display List of Members\n"
			"2 - Display List of Purchases\n"
			"3 - Add member\n"
			"4 - Add Purchase\n"
			"5 - Check for expiring members\n"
			"6 - Sales Report: of a specific day\n"
			"7 - Sales Report: of a specific member\n"
			"8 - Sales Report: of all members\n"
			"0 - EXIT\n"
			"Please enter a command: ";
}
