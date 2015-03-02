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
#include "Member.h"

#ifndef PURCHASE_H_
#define PURCHASE_H_

class Purchase
{
	public:
		//CONSTRUCTORS & DECONSTRUCTOR
		Purchase();
		Purchase(Date	saleDate,
				 int	salemembNum,
				 string saleProduct,
				 float	salePrice,
				 int	saleQty);
		virtual ~Purchase();

		//MUTATORS
		void SetNext(Purchase *nextNode);

		//ACCESSORS
		Date 	  GetPurchaseDate() const;
		int	   	  GetMembershipNumber() const;
		string 	  GetPurchaseProduct() const;
		float  	  GetPurchasePrice() const;
		int	   	  GetPurchaseQty() const;
		Purchase* GetNext() const;

	private:
		Date   	 purchaseDate;		//Date of purchase
		int	   	 membershipNumber;	//Member number
		string 	 purchaseProduct;	//Product purchased
		float 	 purchasePrice;		//Price of product
		int	   	 purchaseQty;		//Product quantity
		Purchase *next;				//Pointer to next purchase
};

#endif /* PURCHASE_H_ */
