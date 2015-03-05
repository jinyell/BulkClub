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
#include "PurchasesList.h"
#include "BulkClub.h"
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
	//VARIABLE DECLARATIONS
	MemberList 	  list;			// list of members
	PurchasesList purchases;	// list of purchases
	BulkClub	  theClub;		// BulkClub object for operations/reports
	int			  selection;	// user's selection for main menu
	bool		  run;			// T/F for program run
	Date		  aDate;
	int aMonth;
	int aDay;
	int aYear;

	//VARIABLE INITIALIZATIONS
	run = true;

	// OUTPUT - Print header to console
	PrintHeader("Jinyoung Ko", "Nicole Montecillo", "Augusto Cabrejos",
				"Andrew Gadbois", 589855, 02, 03, 04, "Bulk Club", 'G', 1);

	// PROCESSING - Create members list & print members list
	list.AddMemberFromFile("InvalidMembers.txt");
	list.PrintMemberList();
	if(list.IsEmpty())
	{
		cout << "LIST IS EMPTY\n";
	}

	list.AddMemberFromFile("warehouse shoppers.txt");
	list.PrintMemberList();

	cout << endl;

	//Adds contents of purchase files to the list. Hard coded for now
	//All contents are added into a single list called purchases
	purchases.AddPurchaseFromFile("day1.txt", list);
	purchases.AddPurchaseFromFile("day2.txt", list);
	purchases.AddPurchaseFromFile("day3.txt", list);
	purchases.AddPurchaseFromFile("day4.txt", list);
	purchases.AddPurchaseFromFile("day5.txt", list);

	//PROCESSING - DO-WHILE LOOP - Used to output the main menu, prompt for
	//			   user input, and go into the different operations.
	do
	{
		//DisplayMainMenu - this will display the main menu
		DisplayMainMenu();

		//GetAndCheckInt - this will prompt for user input and validate it
		selection = GetAndCheckInt(MAIN_MENU_MIN, MAIN_MENU_MAX);
		cout << endl;

		//PROCESSING - SWITCH - Used to route the program into different
		//			   operations based on user's selection from menu
		switch(selection)
		{
		case EXIT: 			//Program ends
							cout << "PROGRAM ENDED" << endl;
							run = false;
							break;

		case MEMBERS: 		//Prints a list of members
							cout << "LIST OF MEMBERS:" << endl;
							list.PrintMemberList();
							break;

		case PURCHASES: 	//Prints a list of purchases
							cout << "LIST OF PURCHASES:" << endl;
							purchases.DisplayPurchasesList();
							break;

		case ADD_MEMBER: 	//Adds member
							list.AddMemberFromConsole();
							break;

		case ADD_PURCHASE:	// Purchase from console
							purchases.AddPurchaseFromConsole(list);
							break;

		case EXPIRING:  	//Prints a report of memberships expiring on
							//a give date (prompts the user)
							cout << "CHECK FOR EXPIRING MEMBERSHIPS" << endl;
							theClub.CheckExpMembers(list);
							break;

		case SALES_REPORT:	// Prints a sales report of a particular day
							purchases.GetASearchDate(aMonth, aDay, aYear);
							purchases.SearchForPurchase(list, aMonth, aDay, aYear);
		}
	}while(run);

	return 0;
}
