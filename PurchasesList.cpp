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
		cout << current->GetPurchaseDate() << endl
			 << current->GetMembershipNumber() << endl
			 << current->GetPurchaseProduct() << endl
			 << current->GetPurchasePrice() << endl
			 << current->GetPurchasePoints() << endl << endl;
		current = current->GetNext();
	}
}
