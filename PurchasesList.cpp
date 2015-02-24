/*
 * PurchasesList.cpp
 *
 *  Created on: Feb 20, 2015
 *      Author: piporuno
 */

#include "PurchasesList.h"

PurchasesList::PurchasesList()
{
	head = NULL;
	tail = NULL;
}

PurchasesList::~PurchasesList() {
	// TODO Auto-generated destructor stub
}

void PurchasesList::AddPurchase(Purchase *newPurchase)
{
	newPurchase->SetNext(NULL);

	if(head == NULL)
	{
		head = newPurchase;
	}
	else
	{
		tail->SetNext(newPurchase);
	}
	tail = newPurchase;
}

void PurchasesList::DisplayPurchasesList() const
{
	Purchase *current;

	current = head;

	while(current != NULL)
	{
		cout << left << setw(12) << current->GetPurchaseDate()
			 << setw(8) << current->GetMembershipNumber()
			 << setw(30) << current->GetPurchaseProduct()
			 << "$" << setw(8) << current->GetPurchasePrice()
			 << setw(5) << current->GetPurchaseQty() << endl;
		current = current->GetNext();
	}
}
