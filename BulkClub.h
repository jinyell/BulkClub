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
#ifndef BULKCLUB_H_
#define BULKCLUB_H_

#include "MemberList.h"
#include "PurchasesList.h"
#include "ProductList.h"

class BulkClub
{
	public:
		//CONSTRUCTOR/DESTRUCTOR
		BulkClub();
		virtual ~BulkClub();

		//Requirement #2
		void PurchasesbyMember(MemberList& list, //Gets purchases by member
				       	   	   PurchasesList& purchases);

		//Requirement #3
		void TotalPurchasesByAllMembers(MemberList    &list,
										PurchasesList &purchases);

		//Requirement #4
		void SearchItemsSold(PurchasesList& purchases);

		//Requirement #5
		void ItemsSold(PurchasesList& purchases);

		// Requirement #6
		void Rebate(MemberList& list) const;

		//Requirement #8
		void CheckExpMembers(MemberList& list); //Checks expiring membership

		// Requirement #10
		void CheckConvertToPreferred(MemberList &memList);
		
		//Requirement #11
		void PreferredToBasicConversion(MemberList& list);
};

#endif /* BULKCLUB_H_ */
