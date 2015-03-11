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
	nextMember   		= NULL;
	prevMember  		= NULL;
	name.clear();
	memberNumber 		= 0;
	annualDues   		= 55;
	totalSpentNoTax   	= 0;
	totalSpentPlusTax 	= 0;
}

/**************************************************************************
 * OVERLOADED CONSTRUCTOR
 *************************************************************************/
Member::Member(string setName,			// IN & CALC - Name
			   int	  setMemberNumber,	// IN & CALC - Member #
			   Date	  setDate)
{
	nextMember   	  = NULL;
	prevMember   	  = NULL;
	name 		 	  = setName;
	memberNumber 	  = setMemberNumber;
	expDate		 	  = setDate;
	annualDues   	  = 55;
	totalSpentNoTax   = 0;
	totalSpentPlusTax = 0;
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

bool Member::ValidateMemberNumFromFile(const int CHECK_INT)
{
	bool	 valid;

	valid = true;

	if(!CHECK_INT)
	{
		valid = false;
	}
	else if(CHECK_INT < MIN_MEM_NUM || CHECK_INT > MAX_MEM_NUM)
	{
		valid = false;
	}

	return valid;
}

bool Member::ValidateMemberNumFromConsole(const int CHECK_INT)
{
	bool 		  valid;
	ostringstream oss;

	cout << left;
	valid = true;

	if(!CHECK_INT)
	{
		oss  << "***** Invalid Member Number ";
		cout << endl << setw(ERROR_COL) << oss.str()   << " *****\n";
		oss.str("");

		oss  << "***** Member Number's are between " << MIN_MEM_NUM
			 << " and " << MAX_MEM_NUM;
		cout << setw(ERROR_COL) << oss.str()   << " *****\n\n";
		oss.str("");
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		valid = false;
	}
	else if(CHECK_INT < MIN_MEM_NUM || CHECK_INT > MAX_MEM_NUM)
	{
		oss  << "***** The number " << CHECK_INT << " is not a valid entry";
		cout << endl << setw(ERROR_COL) << oss.str() << " *****\n";
		oss.str("");

		oss  << "***** Member Number's are between " << MIN_MEM_NUM
			 << " and " << MAX_MEM_NUM;
		cout << setw(ERROR_COL) << oss.str()   << " *****\n\n";
		oss.str("");
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		valid = false;
	}

	cout << right;

	return valid;
}

bool Member::ValidateMemberTypeFromFile(const char CHECK_CHAR)
{
	bool 	 valid;

	valid = true;

	if(CHECK_CHAR != TYPE_BASIC && CHECK_CHAR != TYPE_PREF)
	{
		valid = false;
	}

	return valid;
}

bool Member::ValidateMemberTypeFromConsole(const char CHECK_CHAR)
{
	bool 		  valid;
	ostringstream oss;

	valid = true;
	cout << left;

	if(CHECK_CHAR != TYPE_BASIC && CHECK_CHAR != TYPE_PREF)
	{
		oss  << "***** The membership type " << CHECK_CHAR << " is invalid";
		cout << endl << setw(ERROR_COL) << oss.str() << " *****\n\n";
		oss.str("");
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		valid = false;
	}

	cout << right;

	return valid;
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

Date Member::GetExpDate() const
{
	return expDate;
}

float Member::GetAnnualDues() const
{
	return annualDues;
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
	cout << setfill(' ');
	cout << setw(NAME_COL)  << name 		   << setw(COL_SPACE) << " ";
	cout << setw(TYPE_COL)  << GetMemberType() << setw(COL_SPACE) << " ";
	cout << setw(NUM_COL)   << memberNumber    << setw(COL_SPACE) << " ";
	cout << right 			<< fixed 		   << setprecision(2);
	cout << "$"  			<< setw(SPENT_COL) << totalSpentPlusTax
		 << setw(COL_SPACE) << " ";
	cout << left 			<< setprecision(6);
	cout.unsetf(ios::fixed);
	cout << setw(DATE_COL)  << expDate.DisplayDate()
		 << setw(COL_SPACE) << " ";
	cout << right;
}

/**************************************************************************
 * UpdateTotalSpentNoTax
 * 		This method updates the total amount spent for a user without
 * 		including tax.
 *
 * 		Returns - nothing (Updates total spent without tax)
 *************************************************************************/
void Member::UpdateTotalSpentNoTax(float addToTotal)
{
	totalSpentNoTax += addToTotal;
}


/**************************************************************************
 * UpdateTotalSpentPlusTax
 * 		This method updates the total amount spent for a member
 * 		including tax.
 *
 * 		Returns - nothing (Updates total spent with tax)
 *************************************************************************/
void Member::UpdateTotalSpentPlusTax(float addToTotal)
{
	totalSpentPlusTax += addToTotal;
}

/**************************************************************************
 * GetTotalSpentNoTax
 * 		This method returns the total amount spent by a member that
 * 		does not include any of the tax.
 *
 * 		Returns - totalSpentNoTax (float)
 *************************************************************************/
float Member::GetTotalSpentNoTax() const
{
	return totalSpentNoTax;
}

/**************************************************************************
 * GetTotalSpentPlusTax
 * 		This method returns the total amount spent by a member that
 * 		does include tax.
 *
 * 		Returns - totalSpentPlusTax (float)
 *************************************************************************/
float Member::GetTotalSpentPlusTax() const
{
	return totalSpentPlusTax;
}
