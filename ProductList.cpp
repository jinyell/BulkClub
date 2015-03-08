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
#include "ProductList.h"

ProductList::ProductList()
{
	head = NULL;
	tail = NULL;
	productCount = 0;
}

ProductList::~ProductList() {}


void ProductList::GetProductFromList(PurchasesList& purchases)
{
	Purchase *purchasesPtr;	//pointer to purchases list. to traverse it
	Product *tempPtr3;
	Product *newProduct;

	purchasesPtr  = purchases.GetHead();	//initializes to head of purchases list
	tempPtr3 = head;

	//adds to head of list if empty
	newProduct = new Product(purchasesPtr->GetPurchaseProduct(),
						   	 purchasesPtr->GetPurchasePrice(),
							 purchasesPtr->GetPurchaseQty());
	AddProductByName(newProduct);
	purchasesPtr = purchasesPtr->GetNext();


	tempPtr3 = head;

	while(purchasesPtr != NULL)
	{
		if(purchasesPtr->GetPurchaseProduct() != tempPtr3->GetProductName() && tempPtr3->GetNext() == NULL)
		{
			newProduct = new Product(purchasesPtr->GetPurchaseProduct(),
									 purchasesPtr->GetPurchasePrice(),
									 purchasesPtr->GetPurchaseQty());
			AddProductByName(newProduct);
			purchasesPtr = purchasesPtr->GetNext();
			tempPtr3 = head;
		}
		else
		{
			if(purchasesPtr->GetPurchaseProduct() == tempPtr3->GetProductName())
			{
				tempPtr3->SetProductQtySold(tempPtr3->GetProductQtySold() + purchasesPtr->GetPurchaseQty());
				purchasesPtr = purchasesPtr->GetNext();
			}
			tempPtr3 = tempPtr3->GetNext();
		}

	}

}


void ProductList::AddProductByName(Product *newProduct)
{
	Product *tempPtr;

	if(head == NULL)
	{
		head = newProduct;
		tail = newProduct;
	}
	else if(head->GetProductName() > newProduct->GetProductName())
	{
		newProduct->SetNext(head);
		head->SetPrevious(newProduct);
		head = newProduct;
	}
	else if(tail->GetProductName() < newProduct->GetProductName())
	{
		tail->SetNext(newProduct);
		newProduct->SetPrevious(tail);
		tail = newProduct;
	}

	else
	{
		tempPtr = head;

		while(tempPtr != NULL && tempPtr->GetProductName() < newProduct->GetProductName())
		{
			tempPtr = tempPtr->GetNext();
		}

		newProduct->SetPrevious(tempPtr->GetPrevious());
		newProduct->SetNext(tempPtr);

		tempPtr->GetPrevious()->SetNext(newProduct);
		tempPtr->SetPrevious(newProduct);
	}

	productCount++;
}

Product* ProductList::SearchForProduct(string productKey)
{
	Product *tempPtr;
	bool	found;

	tempPtr = head;
	found = false;

	while(tempPtr != NULL && !found)
	{
		if(tempPtr->GetProductName() == productKey)
		{
			found = true;
		}
		else
		{
			tempPtr = tempPtr->GetNext();
		}
	}

	return tempPtr;
}

Product* ProductList::GetHead() const
{
	return head;
}


Product* ProductList::GetTail() const
{
	return tail;
}

void ProductList::PrintProductAndQtyList() const
{
	Product *displayPtr;

	displayPtr = head;

	while(displayPtr != NULL)
	{
		cout << setw(ITEM_NAME_W) << displayPtr->GetProductName()
			 << setw(ITEM_QTY_W) << displayPtr->GetProductQtySold()
			 << endl;
		displayPtr = displayPtr->GetNext();
	}
	cout << endl;
}
