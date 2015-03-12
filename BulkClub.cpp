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
				//			   membership number.
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

					cout << "Total spent: $" << fixed << setprecision(2)
						 <<	purchaseByMember.GetPurchaseTotal() << endl
						 << endl;
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

					cout << "Total spent: $" << fixed << setprecision(2)
						 <<	purchaseByMember.GetPurchaseTotal() << endl
						 << endl;
				}
				break;
	}
}

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

void BulkClub::SearchItemsSold(PurchasesList& purchases)
{
	//VARIABLE DECLARATIONS
	ProductList itemsSold;		//IN & OUT   - List to store the items sold
	Product	    *result;		//IN & OUT   - Stores search result
	string 		productKey;		//IN & OUT   - Product to search
	float		salesTotal;		//CALC & OUT - Product total sales price
	itemsSold.GetProductFromList(purchases);


	//INPUT - Prompts user to enter a product name to search
	cout << "Enter a product name to search: ";
	cin.ignore(1000, '\n');
	getline(cin, productKey);

	//SearchForProduct - Searches the list for a match
	result = itemsSold.SearchForProduct(productKey);

	//PROCESSING - IF-THEN-ELSE - Used to check if the result returned
	//			   anything
	if(result == NULL)
	{
		//OUTPUT - Message if no match was found
		cout << "Product was not found" << endl;
	}
	else
	{
		//PROCESSING - Calculates the total price for a product
		salesTotal = result->GetProductPrice() * result->GetProductQtySold();

		//OUTPUT - Displays the item's details
		cout << left << setw(ITEM_NAME_W) << "PRODUCT"
			 << setw(ITEM_PRICE_W) << "PRICE"
			 << setw(ITEM_QTY_W) << "QTY"
			 << setw(ITEM_TOTAL_W) << "TOTAL"
			 << endl
			 << setw(ITEM_NAME_W) << "-----------------------------"
			 << setw(ITEM_PRICE_W) << "--------"
			 << setw(ITEM_QTY_W) << "---"
			 << setw(ITEM_TOTAL_W) << "--------"
			 << endl;

		result->PrintProductInfo();
		cout << right << setw(4) << "$"
			 << setw(ITEM_TOTAL_W-2) << salesTotal << endl << endl;
	}
}

void BulkClub::ItemsSold(PurchasesList& purchases)
{
	//VARIABLE DECLARATION
	ProductList itemsSold; //IN & OUT - the list of products

	//GetProductFromList - Searches purchases list and adds products to
	//					   itemsSold list. Only adds a product once
	itemsSold.GetProductFromList(purchases);

	//OUTPUT - Displays the list of items sold
	cout << left << setw(ITEM_NAME_W) << "PRODUCT"
		 << setw(ITEM_QTY_W) << "QTY SOLD" << endl
		 << setw(ITEM_NAME_W) << "-----------------------------"
		 << setw(ITEM_QTY_W) << "--------" << endl;
	itemsSold.PrintProductAndQtyList();
}

void BulkClub::CheckConvertToPreferred(MemberList &memList)
{
	// Variable List
	int				choice;
	bool  			convert;
	float 			total;
	string			name;
	Member 			*tempBasic;
	PreferredMember tempPref;

	do
	{
		cout << "Change Basic to Preferred membership\n"
				"1 - Single Basic Member\n"
				"2 - All Basic members\n"
				"Enter selection: ";

		choice = GetAndCheckInt(1, 2);
	}while(choice == -1);

	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	if(choice == 1)
	{
		cout << "Please Enter a Name: ";
		getline(cin, name);

		// PROCESSING - Search for member in list
		tempBasic = memList.SearchForMember(name);

		// PROCESSING - If member is in list
		if(tempBasic != NULL)
		{
			if(tempBasic->GetMemberType() == "Basic")
			{
				// PROCESSING - Calculate if amount that would be saved if pref
				total = (tempBasic->GetTotalSpentNoTax() * tempPref.GetRebate());

				// PROCESSING - If basic member should convert to pref
				if(total > tempPref.GetAnnualDues())
				{
					cout << "Recommended to switch to a preferred customer\n\n";
					convert = true;
				}
				// PROCESSING - If basic member should remain as basic
				else
				{
					cout << "Not recommended to switch to a preferred customer\n\n";
					convert = false;
				}
			}
			else
			{
				cout << "Already a Preferred Member\n\n";
				convert = false;
			}
		}
		else
		{
			cout << "Sorry! " << name << "'s is not a Bulk Club Member!\n\n";
			convert = false;
		}
	}
	else
	{
		tempBasic = memList.GetHeadofList();

		while(tempBasic != NULL)
		{
			if(tempBasic->GetMemberType() == "Basic")
			{
				// PROCESSING - Calculate if amount that would be saved if pref
				total = (tempBasic->GetTotalSpentNoTax() * tempPref.GetRebate());

				// PROCESSING - If basic member should convert to pref
				if(total > tempPref.GetAnnualDues())
				{
					cout << tempBasic->GetName() << " is recommended to "
							"switch to a preferred customer\n\n";
					convert = true;
				}
				// PROCESSING - If basic member should remain as basic
				else
				{
					cout << tempBasic->GetName() << " is not recommended "
							"to switch to a preferred customer\n\n";
					convert = false;
				}
			}
			tempBasic = tempBasic->GetNext();
		}

	}
}

void BulkClub::Rebate(MemberList &memList) const
{
	Member *tempMem;
	PreferredMember tempPref;
	float total;
	int count;

	tempMem = memList.GetHeadofList();
	count = 0;

	while(tempMem != NULL)
	{
		if(tempMem->GetMemberType() == "Preferred")
		{
			count++;
			if(count == 1)
			{
				cout << left 			  << setfill(' ')
					 << setw(NUM_COL)     << "MEMBER ID" << " "
					 << setw(SPENT_COL+1) << "REBATE"    << "\n"
					 << setfill('-')
					 << setw(NUM_COL)  	  << "-" 		 << " "
					 << setw(SPENT_COL+1) << "-" 		 << "\n"
					 << setfill(' ');
			}
			total = (tempMem->GetTotalSpentNoTax() * tempPref.GetRebate());
			cout << left
				 << setw(NUM_COL) 	<< tempMem->GetMemberNumber() << " "
				 << fixed << setprecision(2) << "$" << right
				 << setw(SPENT_COL) << total << endl;
		}

		tempMem = tempMem->GetNext();
	}

	cout << setprecision(6) << endl;
	cout.unsetf(ios::fixed);
}

void BulkClub::PreferredToBasicConversion(MemberList& list)
{
	//VARIABLE DECLARATIONS
	int 	selection;	//IN & CALC  - The user selection from menu
	string 	nameKey;	//IN & OUT	 - The member name to search
	float 	rebate;		//CALC & OUT - The member's annual rebate
	Member 	*result;	//IN & OUT   - Stores member search result
	Member 	*tempPtr;	//CALC & OUT - To traverse member list

	//VARIABLE INITIALIZATION
	tempPtr = list.GetHeadofList();

	//PROCESSING - DO-WHILE - Used to print menu and get user selection.
	//			   exits once a valid input is entered
	do
	{
		cout << "Check preferred to basic membership conversion\n"
			 << "1 - Single Preferred member\n"
			 << "2 - All Preferred members\n"
			 << "Make a selection: ";

		selection = GetAndCheckInt(1, 2);
		cout << endl;
	}while(selection == -1);

	//PROCESSING - IF-THEN-ELSE - Used to branch out into the single or all
	//			   members
	if(selection == 1)
	{
		cout << "Enter a member name: ";
		cin.ignore(1000, '\n');
		getline(cin, nameKey);
		result = list.SearchForMember(nameKey);

		if(result == NULL)
		{
			cout << endl <<nameKey << " is not a member of Bulk Club"
				 << endl << endl;
		}
		else
		{
			if(result->GetMemberType() == "Preferred")
			{
				rebate = result->GetTotalSpentNoTax() * .06;

				if(rebate <= result->GetAnnualDues())
				{
					cout << endl << nameKey << " is not saving money and "
					     << "should convert to basic." << endl;
				}
				else
				{
					cout << endl << nameKey << " is saving money and "
						 <<	"should not convert to basic." << endl;
				}
				cout << nameKey << " has spent $"
					 << result->GetTotalSpentNoTax() << " and accumulated "
					 << "a rebate of $" << rebate << ". " << endl << endl;
			}
			else
			{
				cout << endl << nameKey << " is not a preferred member"
					 << endl << endl;
			}
		}
	}
	else
	{
		while(tempPtr != NULL)
		{
			if(tempPtr->GetMemberType() == "Preferred")
			{
				rebate = tempPtr->GetTotalSpentNoTax() * .06;

				if(rebate <= tempPtr->GetAnnualDues())
				{
					cout << endl << tempPtr->GetName() << " is not saving "
						 << "money and should convert to basic." << endl;
				}
				else
				{
					cout << endl << tempPtr->GetName() << " is saving "
						 << "money and should not convert to basic." << endl;
				}
				cout << tempPtr->GetName() << " has spent $"
					 << tempPtr->GetTotalSpentNoTax() << " and accumulated a "
					 << "rebate of $" << rebate << ". " << endl << endl;
			}
			tempPtr = tempPtr->GetNext();
		}
	}
}
