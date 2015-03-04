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
	newPurchase->SetNext(NULL);

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
}

void PurchasesList::SearchForPurchaseDate(Date searchDate)
{
	// Variable List
	Purchase *tempPtr;

	tempPtr = head;

	DisplayPurchaseHeader();

	// PROCESSING - Loop through entire purchase list
	while(tempPtr != NULL)
	{
		if(tempPtr->GetPurchaseDate().GetDay() == searchDate.GetDay()
		   && tempPtr->GetPurchaseDate().GetMonth() == searchDate.GetMonth()
		   && tempPtr->GetPurchaseDate().GetYear() == searchDate.GetYear())
		{
			tempPtr->PrintPurchase();
		}
		tempPtr = tempPtr->GetNext();
	}
}

void PurchasesList::DisplayPurchaseHeader() const
{
	cout << left
		 << setw(13) << "SALE DATE" << setw(10) << "MEMBER#"
		 << setw(32) << "ITEM PURCHASED" << setw(11) << "PRICE"
		 << setw(8) << "QTY" << endl
		 << setw(13) << "----------" << setw(10) << "-------"			 << setw(32) << "-----------------------------" << setw(11)
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
