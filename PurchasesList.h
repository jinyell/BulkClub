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

class PurchasesList
{
	public:
		//CONSTRUCTORS & DESTRUCTOR
		PurchasesList();
		virtual ~PurchasesList();

		//MUTATORS
		void AddPurchaseFromFile(string inputFileName);
		void AddPurchase(Purchase* newPurchase);

		//ACCESORS
		void DisplayPurchasesList() const;

	private:
		Purchase *head;
		Purchase *tail;
};

#endif /* PURCHASESLIST_H_ */
