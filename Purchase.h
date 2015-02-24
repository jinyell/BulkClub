/*
 * Purchase.h
 *
 *  Created on: Feb 20, 2015
 *      Author: piporuno
 */

#include "Member.h"

#ifndef PURCHASE_H_
#define PURCHASE_H_

class Purchase
{
	public:
		Purchase();
		Purchase(string saleDate,
				 int	membNum,
				 string saleProduct,
				 float	salePrice,
				 int	saleQty);
		virtual ~Purchase();

		//MUTATORS
		void SetNext(Purchase *nextNode);

		//ACCESSORS
		string GetPurchaseDate() const;
		int	   GetMembershipNumber() const;
		string GetPurchaseProduct() const;
		float  GetPurchasePrice() const;
		int	   GetPurchaseQty() const;
		Purchase* GetNext() const;

	private:
		string   purchaseDate;
		int	   	 membershipNumber;
		string 	 purchaseProduct;
		float 	 purchasePrice;
		int	   	 purchaseQty;
		Purchase *next;
};

#endif /* PURCHASE_H_ */
