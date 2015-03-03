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
#include "MemberList.h"

#ifndef PURCHASE_H_
#define PURCHASE_H_

/*************************************************************************
 * GLOBAL CONSTANTS
 * -----------------------------------------------------------------------
 * QTY_MIN		: Minimum quantity to purchase
 * QTY_MAX		: Maximum quantity to purchase
 * COST_MIN		: Minimum cost of a product
 * COST_MAX		: Maximum cost of a product
 *************************************************************************/
const int   QTY_MIN  = 0;
const int   QTY_MAX  = 200;
const float COST_MIN = 0.00;
const float COST_MAX = 1000.00;


class Purchase
{
	public:
		/******************************
		 ***CONSTRUCTOR & DESTRUCTOR***
		 ******************************/
		Purchase();
		Purchase(Date	saleDate,
				 int	salemembNum,
				 string saleProduct,
				 float	salePrice,
				 int	saleQty);
		virtual ~Purchase();

		/**************
		 ***MUTATORS***
		 **************/
		void SetNext(Purchase *nextNode);

		bool ValidateItemQuantity(const int CHECK_INT);
		bool ValidateItemPrice(const int CHECK_FLOAT);


		/***************
		 ***ACCESSORS***
		 ***************/
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
