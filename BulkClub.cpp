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

void BulkClub::PurchasesbyMember(MemberList& list,
								 PurchasesList& purchases)
{
	//VARIABLE DECLARATION
	string memberName;				//IN - the member name to search
	int	   memberNumber;			//IN - the membership number to search
	int	   selection;				//IN - user's selection from menu
	Member *searchResult;			//IN - the member found from search
	PurchasesList purchaseByMember;	//IN - list of purchases by member

	//PROCESSING - DO-WHILE - Used to prompt user to select search by name
	//			   or number. Exits once a valid selection is input
	do
	{
		cout << "Sales report: of a specific member by:" << endl
			 << "1 - Membership Number" << endl
			 << "2 - Member Name" << endl
			 << "Enter a command: ";

		selection = GetAndCheckInt(1, 2);
		cout << endl;
	}while(selection == -1);

	//PROCESSING - SWITCH - Used to call different functions bases on user
	//			   selection
	switch(selection)
	{
		case 1:	//Searches purchases by membership number
				//PROCESSING - DO-WHILE - Used to prompt user for a 
				//			   memberhsip number.
				do
				{
					//INPUT - prompts user for membership number
					cout << "Enter Membership Number: ";
					memberNumber = GetAndCheckInt(1, 99999);
					cout << endl;
				}while(memberNumber == -1);
				
				//SearchForMember - Searches list for member number
				searchResult = list.SearchForMember(memberNumber);
				
				//PROCESSING - IF-THEN-ELSE - check if membership was found
				if(searchResult == NULL)
				{
					//Output - Not found message for membership not found
					cout << "Membership #" << memberNumber << " was not "
						 <<	"found" << endl << endl;
				}
				else
				{
					//Output - Found message for when member was found
					cout << "Purchases Report for membership #"
						 << memberNumber << ": " << endl;
					
					//FindPurchasesByMember - finds purchases by member
					purchases.FindPurchasesByMember(purchaseByMember,
													memberNumber);
					
					//DisplayPurchasesList - displays list of purchases
					purchaseByMember.DisplayPurchasesList();
				}
				break;
		case 2: //Searches purchases by member name
				//INPUT - prompts user for member name
				cout << "Enter Member Name: ";
				cin.ignore(1000, '\n');
				getline(cin, memberName);
				
				//SearchForMember - searches list for member name
				searchResult = list.SearchForMember(memberName);
				cout << endl;

				//PROCESSING - IF-THEN-ESLE - Checks if list is empty
				if(searchResult == NULL)
				{
					//OUTPUT - not found message for no member found
					cout << "Member " << memberName << " was not found"
						 << endl << endl;
				}
				else
				{
					//OUTPUT - found message when member was found
					cout << "Purchases Report for member " << memberName
						 << ": " << endl;
					
					//PurchasesByMember - finds purchases by member
					purchases.FindPurchasesByMember(purchaseByMember,
													searchResult->GetMemberNumber());
					
					//DisplayPurchaseList- displays list of purchases
					purchaseByMember.DisplayPurchasesList();
				}
				break;
	}
}
