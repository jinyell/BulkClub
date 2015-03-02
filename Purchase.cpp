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
