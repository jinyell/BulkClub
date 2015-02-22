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
#include "Member.h"

/**************************************************************************
 * DEFAULT CONSTRUCTOR
 *************************************************************************/
Member::Member()
{
	nextMember   = NULL;
	prevMember   = NULL;
	name.clear();
	memberNumber = 0;
	totalSpent   = 0;

}

/**************************************************************************
 * OVERLOADED CONSTRUCTOR
 *************************************************************************/
Member::Member(string setName,			// IN & CALC - Name
			   int	  setMemberNumber,	// IN & CALC - Member #
			   Date	  setDate)
{
	nextMember   = NULL;
	prevMember   = NULL;
	name 		 = setName;
	memberNumber = setMemberNumber;
	expDate		 = setDate;
	totalSpent   = 0;
}

/**************************************************************************
 * DESTRUCTOR
 *************************************************************************/
Member::~Member() {
}

/**************************************************************************
 * SetNext
 * 		This method sets the next node in the members list.
 *
 * 		Returns - nothing
 *************************************************************************/
void Member::SetNext(Member *nextNode) // IN & CALC - Next member
{
	nextMember = nextNode;
}

/**************************************************************************
 * SetPrev
 * 		This method sets the previous node in the members list.
 *
 * 		Returns - nothing
 *************************************************************************/
void Member::SetPrev(Member *prevNode)	// IN & CALC - Previous member
{
	prevMember = prevNode;
}

/**************************************************************************
 * SetName
 * 		This method sets the name of the member.
 *
 * 		Returns - nothing
 *************************************************************************/
void Member::SetName(string setName) // IN & CALC - Name of member
{
	name = setName;
}

/**************************************************************************
 * SetMemberNumber
 * 		This method sets the member number for a member.
 *
 * 		Returns - nothing
 *************************************************************************/
void Member::SetMemberNumber(int setMemberNum) // IN & CALC - Member number
{
	memberNumber = setMemberNum;
}

/**************************************************************************
 * GetNext
 * 		This method gets the next node in the members list.
 *
 * 		Returns - nextMember (Member)
 *************************************************************************/
Member* Member::GetNext() const
{
	return nextMember;
}

/**************************************************************************
 * SetPrev
 * 		This method gets the previous node in the members list
 *
 * 		Returns - prevMember (Member)
 *************************************************************************/
Member* Member::GetPrev() const
{
	return prevMember;
}

/**************************************************************************
 * GetName
 * 		This method gets the name of the member.
 *
 * 		Returns - name (string)
 *************************************************************************/
string Member::GetName() const
{
	return name;
}

/**************************************************************************
 * GetMemberNumber
 * 		This method gets the member number of a member.
 *
 * 		Returns - memberNumber (int)
 *************************************************************************/
int Member::GetMemberNumber() const
{
	return memberNumber;
}

/**************************************************************************
 * GetMemberType
 * 		This method gets the member type.
 *
 * 		Returns - "Basic" (string)
 *************************************************************************/
string Member::GetMemberType() const
{
	return "Basic";
}

/**************************************************************************
 * Print
 * 		This method prints out information about a member which is
 * 		essentially a Basic member. The following information is printed
 * 		the full name of the member, the member type, the member number,
 * 		and total spent.
 *
 * 		Returns - nothing (Prints Basic member info to console)
 *************************************************************************/
void Member::Print() const
{
	// OUTPUT - Display Basic member info to console
	cout << left;
	cout << setw(NAME_COL)  << name 		   << setw(COL_SPACE) << " ";
	cout << setw(TYPE_COL)  << GetMemberType() << setw(COL_SPACE) << " ";
	cout << setw(NUM_COL)   << memberNumber    << setw(COL_SPACE) << " ";
	cout << right 			<< fixed 		   << setprecision(2);
	cout << "$"  			<< setw(SPENT_COL) << totalSpent
		 << setw(COL_SPACE) << " ";
	cout << left 			<< setprecision(6);
	cout.unsetf(ios::fixed);
	cout << setw(DATE_COL)  << expDate.DisplayDate()
		 << setw(COL_SPACE) << " ";
	cout << right;
}
