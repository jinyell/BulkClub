/*
 * PurchasesList.h
 *
 *  Created on: Feb 20, 2015
 *      Author: piporuno
 */

#ifndef PURCHASESLIST_H_
#define PURCHASESLIST_H_

#include "Purchase.h"

class PurchasesList
{
	public:
		PurchasesList();
		virtual ~PurchasesList();

		//MUTATORS
		void AddPurchase(Purchase* newPurchase);

		//ACCESORS
		void DisplayPurchasesList() const;

	private:
		Purchase *head;
		Purchase *tail;
};

#endif /* PURCHASESLIST_H_ */
