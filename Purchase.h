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
#ifndef PURCHASE_H_
#define PURCHASE_H_

#include "Member.h"

/*************************************************************************
 * GLOBAL CONSTANTS
 * -----------------------------------------------------------------------
 * QTY_MIN		: Minimum quantity to purchase
 * QTY_MAX		: Maximum quantity to purchase
 * COST_MIN		: Minimum cost of a product
 * COST_MAX		: Maximum cost of a product
 * PRODUCT_COL	: Formatting output column for product name
 * QTY_COL		: Formatting output column for quantity of product bought
 *************************************************************************/
const int   QTY_MIN  	= 0;
const int   QTY_MAX 	= 200;
const float COST_MIN 	= 0.00;
const float COST_MAX 	= 1000.00;
const int   PRODUCT_COL = 32;
const int   QTY_COL 	= 8;

class Purchase
{
	public:
		/******************************
		 ***CONSTRUCTOR & DESTRUCTOR***
		 ******************************/
		Purchase();						// Constructor
		Purchase(Date	saleDate,		// Overloaded Constructor
				 int	salemembNum,
				 string saleProduct,
				 float	salePrice,
				 int	saleQty);
		virtual ~Purchase();

		/**************
		 ***MUTATORS***
		 **************/
		void SetNext(Purchase *nextNode);	// Set Next in purchase list

		// Validates item quantity & price from file & console
		bool ValidateItemQuantityFromConsole(const int CHECK_INT);
		bool ValidateItemPriceFromConsole(const int CHECK_FLOAT);
		bool ValidateItemQuantityFromFile(const int CHECK_INT);
		bool ValidateItemPriceFromFile(const int CHECK_FLOAT);


		/***************
		 ***ACCESSORS***
		 ***************/
		Date 	  GetPurchaseDate() const;		// Get Purchase Date
		int	   	  GetMembershipNumber() const;	// Get Membership #
		string 	  GetPurchaseProduct() const;	// Get Product name
		float  	  GetPurchasePrice() const;		// Get product price
		int	   	  GetPurchaseQty() const;		// Get product quantity
		Purchase* GetNext() const;				// Get Next in purchase list
		void	  PrintPurchase() const;		// Print purchase list

	private:
		Date   	 purchaseDate;		// Date of purchase
		int	   	 membershipNumber;	// Member number
		string 	 purchaseProduct;	// Product purchased
		float 	 purchasePrice;		// Price of product
		int	   	 purchaseQty;		// Product quantity
		Purchase *next;				// Pointer to next purchase
};

#endif /* PURCHASE_H_ */
