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
#ifndef MEMBER_H_
#define MEMBER_H_

#include "Date.h"
#include <iostream>
#include <iomanip>
using namespace std;

/**************************************************************************
 * GLOBAL CONSTANTS
 * ------------------------------------------------------------------------
 * NAME_COL	 : Formatting column for printing name
 * TYPE_COL  : Formatting column for printing membership type
 * NUM_COL   : Formatting column for printing membership number
 * SPENT_COL : Formatting column for printing total spent
 * DATE_COL	 : Formatting column for printing Date
 * COL_SPACE : Formatting spaces between columns
 *************************************************************************/
const int NAME_COL  = 20;
const int TYPE_COL  = 15;
const int NUM_COL   = 10;
const int SPENT_COL = 12;
const int DATE_COL  = 12;
const int COL_SPACE = 3;

class Member {
public:
	/***************************
	 ***CONSTRUCTOR & DESTRUCTOR
	 ***************************/
	Member();					// Default Constructor
	Member(string setName, 		// Overloaded Constructor
		   int    setMemberNum,
		   Date   setDate);
	virtual ~Member();			// Destructor

	/**************
	 ***MUTATORS***
	 **************/
	void SetName(string setName);				// Set name of member
	void SetMemberNumber(int setMemberNum);		// Set member number
	void SetNext(Member *nextNode);				// Set next node
	void SetPrev(Member *prevNode);				// Set prev node
	void UpdateTotalSpent(float addToTotal);	// Update total spent

	/***************
	 ***ACCESSORS***
	 ***************/
	string  GetName() const;					// Get name of member
	int     GetMemberNumber() const;			// Get member number
	float	GetTotalSpent() const;				// Get total amount spent
	Member* GetNext() const;					// Get next node
	Member* GetPrev() const;					// Get prev node
	virtual string GetMemberType() const;		// Get membership type
	virtual void   Print() const;				// Print member info

private:
	string	name;			// Name of member
	int		memberNumber;	// Member number
	float   totalSpent;		// Total amount spent
	Date	expDate;		// Membership expiration date
	Member *nextMember;		// Next member
	Member *prevMember;		// Previous member
};

#endif /* MEMBER_H_ */
