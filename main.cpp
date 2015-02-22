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
#include "MemberList.h"
/**************************************************************************
 * BULK CLUB CLASS PROJECT
 * ------------------------------------------------------------------------
 * This program
 * ------------------------------------------------------------------------
 * INPUTS:
 *
 * OUTPUTS:
 *
 *************************************************************************/
int main()
{
	MemberList list;

	// OUTPUT - Print header to console
	PrintHeader("Jinyoung Ko", "Nicole Montecillo", "Augusto Cabrejos",
				"Andrew Gadbois", 589855, 02, 03, 04, "Bulk Club", 'G', 1);

	// PROCESSING - Create members list & print members list
	list.AddMemberFromFile("warehouse shoppers.txt");
	list.PrintMemberList();

	list.AddMemberFromConsole();
	list.PrintMemberList();


	return 0;
}
