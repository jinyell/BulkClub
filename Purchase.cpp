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

#include "Purchase.h"

Purchase::Purchase()
{
	membershipNumber = 0;
	purchaseProduct  = "";
	purchasePrice  	 = 0.0;
	purchaseQty 	 = 0;
	next 			 = NULL;
}

Purchase::Purchase(Date	  saleDate,
		 	 	   int	  saleMembNum,
				   string saleProduct,
				   float  salePrice,
				   int	  saleQty)
{
	purchaseDate 	 = saleDate;
	membershipNumber = saleMembNum;
	purchaseProduct  = saleProduct;
	purchasePrice    = salePrice;
	purchaseQty	     = saleQty;
	next			 = NULL;
}

Purchase::~Purchase() {}

void Purchase::SetNext(Purchase *nextNode)
{
	next = nextNode;
}

Date Purchase::GetPurchaseDate() const
{
	return purchaseDate;
}

int Purchase::GetMembershipNumber() const
{
	return membershipNumber;
}

string Purchase::GetPurchaseProduct() const
{
	return purchaseProduct;
}

float Purchase::GetPurchasePrice() const
{
	return purchasePrice;
}

int Purchase::GetPurchaseQty() const
{
	return purchaseQty;
}

Purchase* Purchase::GetNext() const
{
	return next;
}

bool Purchase::ValidateItemQuantity(const int CHECK_INT)
{
	bool 		  valid;
	ostringstream oss;

	cout << left;
	valid = true;

	if(!CHECK_INT)
	{
		oss  << "***** Invalid Item Quantity ";
		cout << endl << setw(ERROR_COL) << oss.str()   << " *****\n";
		oss.str("");

		oss  << "***** Total quantity of all items on a given day is between "
			 << QTY_MIN  << " and " << QTY_MAX;
		cout << setw(ERROR_COL) << oss.str()   << " *****\n\n";
		oss.str("");
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		valid = false;
	}
	else if(CHECK_INT < QTY_MIN || CHECK_INT > QTY_MAX)
	{
		oss  << "***** The number " << CHECK_INT << " is not a valid entry";
		cout << endl << setw(ERROR_COL) << oss.str() << " *****\n";
		oss.str("");

		oss  << "***** Total quantity of all items on a given day is between "
			 << QTY_MIN  << " and " << QTY_MAX;
		cout << setw(ERROR_COL) << oss.str()   << " *****\n\n";
		oss.str("");
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		valid = false;
	}

	cout << right;

	return valid;
}

bool Purchase::ValidateItemPrice(const int CHECK_FLOAT)
{
	bool 		  valid;
	ostringstream oss;

	cout << left;
	valid = true;

	if(!CHECK_FLOAT)
	{
		oss  << "***** Invalid Item Cost ";
		cout << endl << setw(ERROR_COL) << oss.str()   << " *****\n";
		oss.str("");

		oss  << "***** Cost of items are between "
			 << COST_MIN  << " and " << COST_MAX;
		cout << setw(ERROR_COL) << oss.str()   << " *****\n\n";
		oss.str("");
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		valid = false;
	}
	else if(CHECK_FLOAT < COST_MIN || CHECK_FLOAT > COST_MAX)
	{
		oss  << "***** The number " << CHECK_FLOAT << " is not a valid entry";
		cout << endl << setw(ERROR_COL) << oss.str() << " *****\n";
		oss.str("");

		oss  << "***** Total quantity of all items on a given day is between "
			 << COST_MIN  << " and " << COST_MAX;
		cout << setw(ERROR_COL) << oss.str()   << " *****\n\n";
		oss.str("");
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		valid = false;
	}

	cout << right;

	return valid;
}
