/*
 * Purchase.cpp
 *
 *  Created on: Feb 20, 2015
 *      Author: piporuno
 */

#include "Purchase.h"

Purchase::Purchase()
{
	purchaseDate = "";
	membershipNumber = 0;
	purchaseProduct = "";
	purchasePrice = 0.0;
	purchaseQty 	= 0;
	next = NULL;
}

Purchase::Purchase(string saleDate,
		 	 	   int	membNum,
				   string saleProduct,
				   float	salePrice,
				   int	saleQty)
{
	purchaseDate 	 = saleDate;
	membershipNumber = membNum;
	purchaseProduct  = saleProduct;
	purchasePrice    = salePrice;
	purchaseQty	     = saleQty;
	next			 = NULL;
}

Purchase::~Purchase() {
	// TODO Auto-generated destructor stub
}

void Purchase::SetNext(Purchase *nextNode)
{
	next = nextNode;
}

string Purchase::GetPurchaseDate() const
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
