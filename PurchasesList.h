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

#ifndef PURCHASESLIST_H_
#define PURCHASESLIST_H_

#include "Purchase.h"

/**************************************************************************
 * GLOBAL CONSTANTS
 * ------------------------------------------------------------------------
 * YES_BUY		: To make more purchases
 * NO_BUY		: Stop making more purchases
 *************************************************************************/
const char YES_BUY = 'Y';
const char NO_BUY  = 'N';

class PurchasesList
{
	public:
		/******************************
		 ***CONSTRUCTOR & DESTRUCTOR***
	 	 ******************************/
		PurchasesList();
		virtual ~PurchasesList();

		bool ValidateToBuyMore(const char CHECK_CHAR);

		/**************
		 ***MUTATORS***
		 **************/
		void AddPurchaseFromFile(string inputFileName, MemberList &tempMemList);
		void AddPurchaseFromConsole(MemberList &tempMemList);
		void AddPurchase(Purchase* newPurchase);

		/***************
		 ***ACCESSORS***
		 ***************/
		void DisplayPurchasesList() const; //Displays the purchases list
		int GetPurchaseCount() const;	//Gets total number of purchases

	private:
		Purchase *head;			//head pointer for the list
		Purchase *tail;			//tail pointer for the list
		int	 purchaseCount;		//keeps a count of number of purchases

};

#endif /* PURCHASESLIST_H_ */
