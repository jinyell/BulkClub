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
#include "BulkClub.h"
#include "MyHeader.h"

BulkClub::BulkClub() {}

BulkClub::~BulkClub() {}

void BulkClub::CheckExpMembers(MemberList& list) //list to search
{
	//VARIABLE DECLARATIONS
	MemberList expiring;	// List that stores the expiring memberships
	int		   expMonth;	// IN - membership expiration month to search
	int		   expYear;		// IN - membership expiration year to search

	//PROCESSING - DO-WHILE LOOP - Used to prompt the user for a month to
	//			   search and validate. Exits once a valid input is entered
	do
	{
		cout << "Enter expiration month to search: ";
		expMonth = GetAndCheckInt(EXP_MONTH_MIN, EXP_MONTH_MAX);
		if(expMonth == -1)
		{
			cout << endl;
		}
	}while(expMonth == -1);

	//PROCESSING - DO-WHILE LOOP - Used to prompt the user for a year to
	//			   search and validate. Exits once a valid input is entered
	do
	{
		cout << "Enter expiration year to search: ";
		expYear = GetAndCheckInt(EXP_YEAR_MIN, EXP_YEAR_MAX);
		if(expYear == -1)
		{
			cout << endl;
		}
	}while(expYear == -1);

	cout << endl;

	//SearchByMonth - this will search a list for nodes that contain
	//				  both expMonth and expYear entered and add them to the
	//				  expiring list object
	list.SearchByMonth(expiring, expMonth, expYear);

	//PROCESSING - IF-THEN-ELSE - Used to check if the expiring list is
	//			   empty, display message if empty, and display the list's
	//			   nodes if not empty
	if(expiring.IsEmpty())
	{
		cout << "No memberships expiring on " << expMonth << "/" << expYear
			 << " found" << endl;
	}
	else
	{
		cout << "The following memberships expiring on " << expMonth << "/"
			 << expYear << " were found:" << endl;
		expiring.PrintExpMembers();
	}
	cout << endl;
}
