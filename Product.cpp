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
#include "Product.h"

Product::Product()
{
	productName  	= "";
	productPrice 	= 0.0;
	productQtySold 	= 0;
	next 			= NULL;
	previous 		= NULL;
}

Product::Product(string itemName,
				 float 	itemPrice,
				 int 	itemQtySold)
{
	productName		= itemName;
	productPrice 	= itemPrice;
	productQtySold 	= itemQtySold;
	next 			= NULL;
	previous 		= NULL;
}

Product::~Product() {}

void Product::SetNext(Product* nextNode)
{
	next = nextNode;
}

void Product::SetPrevious(Product* previousNode)
{
	previous = previousNode;
}

void Product::SetProductQtySold(int saleQty)
{
	productQtySold = saleQty;
}

string Product::GetProductName() const
{
	return productName;
}

float Product::GetProductPrice() const
{
	return productPrice;
}

int Product::GetProductQtySold() const
{
	return productQtySold;
}

Product* Product::GetNext() const
{
	return next;
}

Product* Product::GetPrevious() const
{
	return previous;
}

void Product::PrintProductInfo() const
{
	cout << left
		 << setw(ITEM_NAME_W) << productName << "$"
		 << right << setw(ITEM_PRICE_W-4) << fixed << setprecision(2)
		 << productPrice
		 << setw(ITEM_QTY_W) << productQtySold;
}