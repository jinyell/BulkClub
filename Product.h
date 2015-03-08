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
#ifndef PRODUCT_H_
#define PRODUCT_H_

#include "Member.h"

/*************************************************************************
 * GLOBAL CONSTANTS
 * -----------------------------------------------------------------------
 * ITEM_NAME_W		: Column width for product name
 * ITEM_QTY_W		: Column width for product quantity sold
 * ITEM_PRICE_W		: Column width for product price
 * ITEM_TOTAL_W		: Column width for product total price
 *************************************************************************/
const int ITEM_NAME_W  = 32;
const int ITEM_QTY_W   = 6;
const int ITEM_PRICE_W = 11;
const int ITEM_TOTAL_W = 9;

class Product
{
	public:
		//CONSTRUCTORS - DESTRUCTOR
		Product();
		Product(string itemName,
				float  intemPrice,
				int    itemQtySold);
		virtual ~Product();

		//MUTATORS
		void SetNext(Product* nextNode);			//Sets next pointer
		void SetPrevious(Product* previousNode);	//Sets previous pointer
		void SetProductQtySold(int saleQty);		//Sets product qty

		//ACCESSORS
		string 	 GetProductName() const;		//Gets product name
		float  	 GetProductPrice() const;		//Gets product price
		int		 GetProductQtySold() const;		//Gets qty sold
		Product* GetNext() const;				//Gets next pointer
		Product* GetPrevious() const;			//Gets previous pointer
		void PrintProductInfo() const;			//Prints single product

	private:
		string  productName;		//Product name
		float  	productPrice;		//Product price
		int	  	productQtySold;		//Product quantity sold
		Product *next;				//Pointer to next node
		Product *previous;			//Pointer to previous node
};

#endif /* PRODUCT_H_ */
