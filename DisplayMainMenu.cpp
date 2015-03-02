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
	cout << "WELCOME TO BULK CLUB" << endl
		 << "MAIN MENU" << endl
		 << "1 - Display List of Members" << endl
		 << "2 - Display List of Purchases" << endl
		 << "3 - Add member" << endl
		 << "4 - Check for expiring members" << endl
		 << "0 - EXIT" << endl
		 << "Please enter a command: ";
}
