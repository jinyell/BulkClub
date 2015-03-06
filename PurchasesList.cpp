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

#include "PurchasesList.h"

PurchasesList::PurchasesList()
{
	head 		  = NULL;
	tail 		  = NULL;
	purchaseCount = 0;
	purchaseTotal = 0.0;
}

PurchasesList::~PurchasesList() {}

void PurchasesList::AddPurchaseFromFile(string inputFileName,
										MemberList &theMemList)
{
	//VARIABLE DECLARATION
	ifstream inFile;
	Member	 *tempMem;
	Purchase *newPurchase;
	Date	 *transDate;
	int		 transMonth;
	int		 transDay;
	int		 transYear;
	int		 transMemberNum;
	string	 transItem;
	float	 transPrice;
	int		 transQty;
	bool	 validCost;		// CALC		 - Check valid cost
	bool	 validQty;		// CALC		 - Check valid quantity
	bool	 validDate;
	bool	 validMemNum;

	tempMem = NULL;

	inFile.open(inputFileName.c_str());

	// PROCESSING - Check if file exists
	if(!inFile)
	{
		cout << "Sorry! This file is not found.\n";
	}
	else
	{
		// PROCESSING - Read & get info until end of file
		while(!inFile.eof())
		{
			// INPUT - Get purchase month
			if(!(inFile >> transMonth))
			{
				inFile.clear();
				validDate = false;
			}
			inFile.ignore(numeric_limits<streamsize>::max(), '/');

			// INPUT - Get purchase day
			if(!(inFile >> transDay))
			{
				inFile.clear();
				validDate = false;
			}
			inFile.ignore(numeric_limits<streamsize>::max(), '/');

			// INPUT - Get purchase year
			if(!(inFile >> transYear))
			{
				inFile.clear();
				validDate = false;
			}
			inFile.ignore(numeric_limits<streamsize>::max(), '\n');

			validDate = transDate->CheckDate(transMonth, transDay, transYear);

			// PROCESSING - If the input date is not valid
			if(!validDate)
			{
				if(!transMonth || !transDay || !transYear)
				{
					inFile.clear();
					inFile.ignore(numeric_limits<streamsize>::max(), '\n');
				}
			}
			else
			{
				transDate = new Date(transMonth, transDay, transYear);
			}

			if(!(inFile >> transMemberNum))
			{
				inFile.clear();
				validMemNum = false;
			}
			validMemNum = tempMem->ValidateMemberNumFromFile(transMemberNum);
			inFile.ignore(numeric_limits<streamsize>::max(), '\n');

			if(validMemNum)
			{
				// PROCESSING - Check if member exists in member list
				tempMem = theMemList.SearchForMember(transMemberNum);

				// PROCESSING - If member does NOT exist in list
				if(tempMem == NULL)
				{
					validMemNum = false;
					inFile.ignore(numeric_limits<streamsize>::max(), '\n');
				}
				else
				{
					validMemNum = true;
				}
			}

			getline(inFile, transItem);

			if(!(inFile >> transPrice))
			{
				inFile.clear();
				inFile.ignore(numeric_limits<streamsize>::max(), '\n');
			}

			validCost = newPurchase->ValidateItemPriceFromFile(transPrice);

			if(!(inFile >> transQty))
			{
				inFile.clear();
				inFile.ignore(numeric_limits<streamsize>::max(), '\n');
			}

			inFile.ignore(numeric_limits<streamsize>::max(), '\n');

			validQty = newPurchase->ValidateItemQuantityFromFile(transQty);

			if(validDate && validQty && validCost && validMemNum)
			{
				newPurchase = new Purchase(*transDate, transMemberNum,
											transItem, transPrice,
											transQty);

				AddPurchase(newPurchase);
			} // END IF
		} // END WHILE
	} // END IF-ELSE
	inFile.close();
}

/**************************************************************************
 * AddPurchaseFromConsole
 * 		This method allows a member to make a purchase from the console.
 * 		First the membership number is required. If the member number
 * 		does not exist then the user will be notified until the member
 * 		number is correct. Then the member will input information
 * 		including: transaction/purchase date (month, day, year), the
 * 		name of the item the member would like to purchase, the quantity
 * 		of that item the user would like to purchase, and the cost
 * 		of that item. The member can make as many purchases so long as
 * 		the total quantity purchase amount (200) is not exceeded.
 *
 * 		Returns - nothing (Add purchase(s) to the purchase list)
 *************************************************************************/
void PurchasesList::AddPurchaseFromConsole(MemberList &tempMemList)
{
	// Variable List
	Member		*tempMem;		// CALC 	 - Temp member to check inputs
	Purchase 	*newPurchase;	// CALC 	 - Add new purchase
	int  	 	memNum;			// IN & CALC - Membership #
	int  	 	addTrnMonth;	// IN & CALC - Transaction month
	int  	 	addTrnDay;		// IN & CALC - Transaction day
	int  	 	addTrnYear;		// IN & CALC - Transaction year
	string	 	itemName;		// IN & CALC - Item name to purchase
	int		 	itemQty;		// IN & CALC - Quantity of item to buy
	float	 	itemCost;		// IN & CALC - Cost of item
	Date 	 	*addTrnDate;	// CALC		 - Full transaction date
	char		answer;			// CALC		 - Member response to buy more
	bool	 	buyMore;		// CALC		 - Check to buy more
	bool	 	validCost;		// CALC		 - Check valid cost
	bool	 	validQty;		// CALC		 - Check valid quantity
	bool 	 	validDate;		// CALC		 - Check valid date
	bool 	 	validMemNum;	// CALC		 - Check member number

	tempMem     = NULL;
	addTrnDate  = NULL;

	/*
	 * NOTE MEMBER CANNOT EXCEED MORE THAN A 200 ITEM TRANSACTION
	 * PER DAY. SO FIRST WE NEED TO GET A TOTAL COUNT. AND THEN UPDATE
	 * AROUND THAT. (: GETTING THERE YEE
	 */

	cout << "Information to purchase an item\n";

	// INPUT - Get valid member number from member & member is in list
	do
	{
		validMemNum = true;

		cout << "Membership number (5 digit #): ";
		cin >> memNum;

		// PROCESSING - Check if input is valid
		validMemNum = tempMem->ValidateMemberNumFromConsole(memNum);

		if(validMemNum)
		{
			// PROCESSING - Check if member exists in member list
			tempMem = tempMemList.SearchForMember(memNum);

			// PROCESSING - If member does NOT exist in list
			if(tempMem == NULL)
			{
				validMemNum = false;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			else
			{
				validMemNum = true;
			}
		}
	}while(!validMemNum || tempMem == NULL);

	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	// INPUT - Get valid purchase date from member
	do
	{
		cout << "PurchaseDate Date (i.e. MM/DD/YYYY): ";
		cin  >> addTrnMonth;
		cin.ignore(numeric_limits<streamsize>::max(), '/');
		cin  >> addTrnDay;
		cin.ignore(numeric_limits<streamsize>::max(), '/');
		cin  >> addTrnYear;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		validDate = addTrnDate->CheckDate(addTrnMonth, addTrnDay, addTrnYear);

		// PROCESSING - If the input date is not valid
		if(!validDate)
		{
			if(!addTrnMonth || !addTrnDay || !addTrnYear)
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		}
	}while(!validDate);

	// PROCESSING - Add transaction date since valid
	addTrnDate = new Date(addTrnMonth, addTrnDay, addTrnYear);

	// PROCESSING - Initialize variables
	buyMore = true;
	answer  = 'Y';

	// PROCESSING - Keep adding items to purchase
	while(buyMore && answer == 'Y')
	{
		// INPUT - Get name of item member would like to purcahse
		cout << "Item Name: ";
		getline(cin, itemName);

		// INPUT - Get valid quantity of item member would like to purchase
		do
		{
			validQty = true;

			cout << "Quantity of item: ";
			cin  >> itemQty;
			validQty = newPurchase->ValidateItemQuantityFromConsole(itemQty);
		}while(!validQty);

		// INPUT - Get valid price of item member would like to purchase
		do
		{
			validCost = true;

			cout << "Price of item: ";
			cin  >> itemCost;
			validCost = newPurchase->ValidateItemPriceFromConsole(itemCost);
		}while(!validCost);

		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		// PROCESSING - Only add purchase if information is valid
		if(validMemNum && validDate && validQty && validCost )
		{
			newPurchase = new Purchase(*addTrnDate, memNum, itemName,
										itemCost, itemQty);

			AddPurchase(newPurchase);
		}

		// INPUT - Check if member would like to purchase more items (y/n)
		do
		{
			cout << "Would you like to purchase more items (Y/N) ";
			cin.get(answer);
			answer = toupper(answer);
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			buyMore = ValidateToBuyMore(answer);
		}while(!buyMore);
	} // END WHILE
}

void PurchasesList::AddPurchase(Purchase *newPurchase)
{
	//VARIABLE DECLARATION
	float total;		//CALC - result of item price * item quantity

	newPurchase->SetNext(NULL);

	//PROCESSING - IF-THEN-ELSE - Used to check if the list is empty and
	//			   insert node in correct place
	if(head == NULL)
	{
		head = newPurchase;
	}
	else
	{
		tail->SetNext(newPurchase);
	}
	tail = newPurchase;

	purchaseCount++; //Increments purchase count
	total = newPurchase->GetPurchasePrice() * newPurchase->GetPurchaseQty();
	purchaseTotal = purchaseTotal + total;
}

void PurchasesList::SearchForPurchase(MemberList &tempMemList,
									  int 		 searchMonth,
									  int 		 searchDay,
									  int 		 searchYear)
{
	// Variable List
	Member		*tempMem;
	Purchase 	*tempPtr;
	bool     	found;
	int		 	countTotMem;
	int			countBasic;
	int			countPref;

	tempPtr 	= head;
	tempMem 	= NULL;
	found    	= false;
	countTotMem = 0;
	countBasic 	= 0;
	countPref 	= 0;

	// PROCESSING - Loop through entire purchase list
	while(tempPtr != NULL)
	{
		if(tempPtr->GetPurchaseDate().GetDay()   == searchDay   &&
		   tempPtr->GetPurchaseDate().GetMonth() == searchMonth &&
		   tempPtr->GetPurchaseDate().GetYear()  == searchYear)
		{
			countTotMem++;
			if(countTotMem == 1)
			{
				cout << left
					 << setfill(' ')
					 << setw(32) 	   	<< "ITEM PURCHASED" << " "
					 << setw(12) 	   	<< "QUANTITY" 		 << " "
					 << setw(NAME_COL) 	<< "MEMBER NAME" << " "
					 << setw(TYPE_COL)  << "MEMBER TYPE" << "\n"
					 << setfill('-')
					 << setw(32) << "-" << " "
					 << setw(12) << "-" << " "
					 << setw(NAME_COL) << "-" << " "
					 << setw(TYPE_COL) 	<< "-" << "\n"
					 << setfill(' ');
			}
			cout << setw(32) << tempPtr->GetPurchaseProduct() << " "
				 << setw(12) << tempPtr->GetPurchaseQty() << " ";

			tempMem = tempMemList.SearchForMember(tempPtr->GetMembershipNumber());

			if(tempMem == NULL)
			{
				cout << setw(NAME_COL) << "Name D.N.E" << " ";
				cout << setw(TYPE_COL) << "Type D.N.E" << endl;
			}
			else
			{
				cout << setw(NAME_COL) << tempMem->GetName() << " ";
				cout << setw(TYPE_COL) << tempMem->GetMemberType() << endl;

				if(tempMem->GetMemberType() == "Basic")
				{
					countBasic++;
				}
				else
				{
					countPref++;
				}
			}

			found = true;
		}
		tempPtr = tempPtr->GetNext();
	}

	cout << "Total Basic Customers: " << countBasic << endl;
	cout << "Total Preferred Customers: " << countPref << endl;

	if(!found)
	{
		cout << "No sales report of that date\n\n";
	}
}

void PurchasesList::DisplayPurchaseHeader() const
{
	cout << left
		 << setw(13) << "SALE DATE" << setw(10) << "MEMBER#"
		 << setw(32) << "ITEM PURCHASED" << setw(11) << "PRICE"
		 << setw(8) << "QTY" << endl
		 << setw(13) << "----------" << setw(10) << "-------"
		 << setw(32) << "-----------------------------" << setw(11)
		 << "--------" << setw(11) << "---" << endl;
}

void PurchasesList::DisplayPurchasesList() const
{
	Purchase *current;

	current = head;

	DisplayPurchaseHeader();

	while(current != NULL)
	{
		current->PrintPurchase();
		current = current->GetNext();
	}
	cout << endl;
}

/**************************************************************************
 * ValidateToBuyMore
 * 		This method checks a character to see whether or not the member
 * 		entered a valid character. This character should be either 'Y'
 * 		or 'N' to indicate whether or not the member would like to purchase
 * 		more items.
 *
 * 		Returns - valid (bool)
 *************************************************************************/
bool PurchasesList::ValidateToBuyMore(const char CHECK_CHAR)
{
	// Variable List
	bool valid;		// CALC & OUT - Check if valid buy more input

	valid = true;

	// PROCESSING - Check if member input was either 'Y' or 'N'
	if(CHECK_CHAR != YES_BUY && CHECK_CHAR != NO_BUY)
	{
		valid = false;
	}

	return valid;
}

int PurchasesList::GetPurchaseCount() const
{
	return purchaseCount;
}

float PurchasesList::GetPurchaseTotal() const
{
	return purchaseTotal;
}

void PurchasesList::GetASearchDate(int &searchMonth, int &searchDay, int &searchYear)
{
	Date *tempDate;
	bool validDate;

	tempDate = NULL;

	// INPUT - Get a valid expiration date
	do
	{
		validDate = true;

		cout << "Enter Expiration Date (i.e. MM/DD/YYYY): ";
		cin  >> searchMonth;
		cin.ignore(numeric_limits<streamsize>::max(), '/');
		cin  >> searchDay;
		cin.ignore(numeric_limits<streamsize>::max(), '/');
		cin  >> searchYear;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		validDate = tempDate->CheckDate(searchMonth, searchDay, searchYear);

		if(!validDate)
		{
			if(!searchMonth || !searchDay || !searchYear)
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		}
	}while(!validDate);
}

void PurchasesList::FindPurchasesByMember(PurchasesList& purchasesFound,
									  int membershipNum) const
{
	//VARIABLE DECLARATIONS
	Purchase *tempPtr;		//temporary pointer to traverse the list
	Purchase *newPurchase;	//pointer to create nodes for found purchases

	//VARIABLE INITIALIZATION
	tempPtr = head;

	//PROCESSING - DO-WHILE - Used to traverse the list. Exits once end of
	//			   list is reached
	while(tempPtr != NULL)
	{
		//PROCESSING - IF-THEN - Used to check if the current's node
		//			   membership number matches the search key
		if(tempPtr->GetMembershipNumber() == membershipNum)
		{
			//Creates a new purchase node
			newPurchase = new Purchase(tempPtr->GetPurchaseDate(),
									   tempPtr->GetMembershipNumber(),
									   tempPtr->GetPurchaseProduct(),
									   tempPtr->GetPurchasePrice(),
									   tempPtr->GetPurchaseQty());
			//AddPurchase - adds node to the list
			purchasesFound.AddPurchase(newPurchase);
		}
		//Moves to the next node of the list
		tempPtr = tempPtr->GetNext();
	}
}


void PurchasesList::PrintAllMemberPurchases(MemberList &tempMemList) const
{
	// Variable List
	Member		*tempMem;
	Purchase 	*tempPur;
	int countPur;

	tempMem		= tempMemList.GetHeadofList();

	while(tempMem != NULL)
	{
		countPur = 0;
		tempPur 	= head;
		cout << "Purchase(s) By Member: "
			 << setw(NUM_COL) << tempMem->GetMemberNumber() << endl;
		while(tempPur != NULL)
		{
			if(tempMem->GetMemberNumber() == tempPur->GetMembershipNumber())
			{
				cout << setw(32) << tempPur->GetPurchaseProduct() << " "
					 << setw(8) << tempPur->GetPurchasePrice() <<  " "
					 << setw(8) << tempPur->GetPurchaseQty() << " ";
					tempPur->GetPurchaseDate();
					cout << endl;
					countPur++;
			}
			tempPur = tempPur->GetNext();

		}

		cout << endl;
		if(countPur == 0)
		{
			cout << tempMem->GetMemberNumber() << " did not make any purchases\n\n";
		}
		tempMem = tempMem->GetNext();
	}


}
