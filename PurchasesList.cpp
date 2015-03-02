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

#include "PurchasesList.h"

PurchasesList::PurchasesList()
{
	head = NULL;
	tail = NULL;
}

PurchasesList::~PurchasesList() {}

void PurchasesList::AddPurchaseFromFile(string inputFileName)
{
	//VARIABLE DECLARATION
	ifstream inFile;
	Purchase *newPurchase;
	Date	 *transDate;
	int		 transMonth;
	int		 transDay;
	int		 transYear;
	int		 transMemberNum;
	string	 transItem;
	float	 transPrice;
	int		 transQty;

	inFile.open(inputFileName.c_str());

	while(!inFile.eof())
	{
		inFile >> transMonth;
		inFile.ignore(1);
		inFile >> transDay;
		inFile.ignore(1);
		inFile >> transYear;
		inFile.ignore(1);

		transDate = new Date(transMonth, transDay, transYear);

		inFile >> transMemberNum;
		inFile.ignore(1000, '\n');
		getline(inFile, transItem);
		inFile >> transPrice;
		inFile >> transQty;
		inFile.ignore(1000, '\n');

		newPurchase = new Purchase(*transDate, transMemberNum,
									transItem, transPrice,
									transQty);

		AddPurchase(newPurchase);
	}
	inFile.close();
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
	cout << left << setw(13) << "SALE DATE" << setw(10) << "MEMBER#"
			 << setw(32) << "ITEM PURCHASED" << setw(11) << "PRICE"
			 << setw(8) << "QTY" << endl
			 << setw(13) << "----------" << setw(10) << "-------"
			 << setw(32) << "-----------------------------" << setw(11)
			 << "--------" << setw(11) << "---" << endl;
	while(current != NULL)
	{

		cout << left << setw(13) << current->GetPurchaseDate().DisplayDate()
			 << setw(10) << current->GetMembershipNumber()
			 << setw(32) << current->GetPurchaseProduct() << "$" << right
			 << setw(7) << fixed << setprecision(2)
			 << current->GetPurchasePrice()
			 << setw(6) << current->GetPurchaseQty() << endl;
		current = current->GetNext();
	}
	cout << endl;
}
