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

class BulkClub
{
	public:
		//CONSTRUCTOR/DESTRUCTOR
		BulkClub();
		virtual ~BulkClub();

		void CheckExpMembers(MemberList& list); //Checks expiring membership
};

#endif /* BULKCLUB_H_ */
