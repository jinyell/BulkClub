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
#include "MemberList.h"
/**************************************************************************
 * 					CONSTRUCTOR & DESTRUCTOR
 *************************************************************************/

/**************************************************************************
 * DEFAULT CONSTRUCTOR
 *************************************************************************/
MemberList::MemberList() {
	headMember = NULL;
	tailMember = NULL;
	memberSize = 0;

}

/**************************************************************************
 * DESTRUCTOR
 *************************************************************************/
MemberList::~MemberList() {
	ClearList();
}

/**************************************************************************
 * CreateMemberListFromFile
 * 		This method gets a file name that contains information about
 * 		the members that are to be added to Bulk Club. The information
 * 		about a member contains: first name, last name, member number,
 * 		member type (basic or preferred), and member expiration date.
 * 		The information about a member will be stored into a list of
 * 		members.
 *
 * 		Returns - nothing (Adds members to list)
 *************************************************************************/
void MemberList::AddMemberFromFile(string fileName)
{
	// Variable List
	ifstream inFile;		// CALC      - File input
	string 	 newName;		// IN & CALC - Full name
	int		 newMemberNum;	// IN & CALC - Member number
	int		 expMonth;		// IN & CALC - Expiration month
	int		 expDay;		// IN & CALC - Expiration day
	int		 expYear;		// IN & CALC - Expiration year
	string	 memberType;	// IN & CALC - Membership type
	Date	 *newDate;		// CALC		 - Full expiration date
	Member   *newNode;		// CALC		 - Adds a member to list of members

	inFile.open(fileName.c_str());

	// PROCESSING - Check if file exists
	if(!inFile)
	{
		cout << "Sorry! This file is not found.\n";
	}
	else
	{
		// PROCESSING - Keep looping until end of input file
		while(!inFile.eof())
		{
			// INPUT - Get first name, last name, member number, expiration date
			//		 - and membership type
			getline(inFile, newName);
			inFile >> newMemberNum;
			inFile.ignore(numeric_limits<streamsize>::max(), '\n');
			getline(inFile, memberType);
			inFile >> expMonth;
			inFile.ignore(numeric_limits<streamsize>::max(), '/');
			inFile >> expDay;
			inFile.ignore(numeric_limits<streamsize>::max(), '/');
			inFile >> expYear;
			inFile.ignore(numeric_limits<streamsize>::max(), '\n');

			newDate = new Date(expMonth, expDay, expYear);

			// PROCESSING - Check if member is a Basic or Preferred member
			if(memberType == "Basic")
			{
				// PROCESSING - Add a Basic member to the list in order
				newNode = new Member(newName, newMemberNum, *newDate);
				InsertInOrder(newNode);
			}
			else
			{
				// PROCESSING - Add a Preferred member to the list in order
				newNode = new PreferredMember(newName, newMemberNum, *newDate);
				InsertInOrder(newNode);
			}
		} // END - While loop (inFile)
	} // End of If-Else (inFile)

	inFile.close();
}

/**************************************************************************
 * AddMemberFromConsole
 * 		This method gets information about a member that is to be
 * 		added the list of members. The following information will be
 * 		received from the user: Full name, membership id, membership
 * 		card expiration date, and membership type.
 *
 * 		Returns - nothing (Puts a member in order in the list)
 *************************************************************************/
void MemberList::AddMemberFromConsole()
{
	// Variable List
	string 	addName;		// IN & CALC - Member's name
	int		addMemNum;		// IN & CALC - Membership #
	int		addExpMonth;	// IN & CALC - Expiration month
	int		addExpDay;		// IN & CALC - Expiration day
	int		addExpYear;		// IN & CALC - Expiration year
	char	addMemType;		// IN & CALC - Membership type
	Date	*addDate;		// CALC		 - Full Date
	Member  *addMem;		// CALC		 - Member to add

	cout << "Information to Add a Bulk Club Member\n";
	cout << "Membership Type\n"
			"---------------------\n"
			"B - Basic Member\n"
			"P - Preferred Member\n"
			"Enter Member Type: ";
	cin.get(addMemType);
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << "Enter Full Name: ";
	getline(cin, addName);

	cout << "Enter Membership ID: ";
	cin  >> addMemNum;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << "Enter Expiration Date (i.e. MM/DD/YYYY): ";
	cin  >> addExpMonth;
	cin.ignore(numeric_limits<streamsize>::max(), '/');
	cin  >> addExpDay;
	cin.ignore(numeric_limits<streamsize>::max(), '/');
	cin  >> addExpYear;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	addDate = new Date(addExpMonth, addExpDay, addExpYear);

	// PROCESSING - Check if member is a Basic or Preferred member
	if(addMemType == 'B')
	{
		// PROCESSING - Add a Basic member to the list in order
		addMem = new Member(addName, addMemNum, *addDate);
		InsertInOrder(addMem);
	}
	else
	{
		// PROCESSING - Add a Preferred member to the list in order
		addMem = new PreferredMember(addName, addMemNum, *addDate);
		InsertInOrder(addMem);
	}

}

/**************************************************************************
 * InsertInOrder
 * 		This method gets information about a member that is to be
 * 		added the list of members. The list is ordered by the membership
 * 		number. The member size is also incremented (which counts the
 * 		number of members in the list).
 *
 * 		Returns - nothing (Puts a member in order in the list)
 *************************************************************************/
void MemberList::InsertInOrder(Member *addNode) // IN & CALC - A member
{
	// Variable List
	Member *tempPtr;	// CALC - Temporary pointer to insert in order

	// PROCESSING - If the list of members is empty add new member to
	//			  - head (beginning) and tail (end) of list
	if(headMember == NULL)
	{
		headMember = addNode;
		tailMember = addNode;
	}
	// PROCESSING - If adding to the head of the list
	else if(headMember->GetMemberNumber() > addNode->GetMemberNumber())
	{
		addNode->SetNext(headMember);
		headMember->SetPrev(addNode);
		headMember = addNode;
	}
	// PROCESSING - If adding to the tail of the list
	else if(tailMember->GetMemberNumber() < addNode->GetMemberNumber())
	{
		tailMember->SetNext(addNode);
		addNode->SetPrev(tailMember);
		tailMember = addNode;
	}
	// PROCESSING - If adding in the middle of the list
	else
	{
		tempPtr = headMember;

		// PROCESSING = Keep looping through until placement spot found
		while(tempPtr != NULL &&
			  tempPtr->GetMemberNumber() < addNode->GetMemberNumber())
		{
			tempPtr = tempPtr->GetNext();
		}

		// PROCESSING - Add new node to the list of members
		addNode->SetPrev(tempPtr->GetPrev());
		addNode->SetNext(tempPtr);

		tempPtr->GetPrev()->SetNext(addNode);
		tempPtr->SetPrev(addNode);
	}

	// PROCESSING - Increment member size
	memberSize++;
	tempPtr = NULL;
}

/**************************************************************************
 * ClearList
 * 		This method clears the entire list of members. This returns
 * 		a bool to indicate that the list of members has been cleared.
 *
 * 		Returns - cleared (bool)
 *************************************************************************/
bool MemberList::ClearList()
{
	// Variable List
	Member *tempPtr;	// CALC 	  - Temp ptr to clear list
	bool	cleared;	// CALC & OUT - Cleared list or not

	tempPtr = headMember;
	cleared = false;

	// PROCESSING - If list of members is already cleared
	if(headMember == NULL)
	{
		cleared = true;
	}
	// PROCESSING - Clear list
	else
	{
		// PROCESSING - Keep looping until each member is removed
		//			  - Also decrement list of member size
		while(tempPtr != NULL)
		{
			tempPtr = tempPtr->GetNext();
			delete headMember;
			headMember = tempPtr;
			memberSize--;
		}

		// PROCESSING - Ensure list of members is thoroughly cleared
		headMember = NULL;
		tailMember = NULL;
		memberSize = 0;
		cleared	   = true;
	}

	// PROCESSING - Delete temp ptr
	delete tempPtr;

	return cleared;
}

/**************************************************************************
 * RemoveMember
 * 		This function receives a name that is to be removed from the
 * 		list of members. This method calls the SearchForMember method
 * 		to find the location of the member to be deleted. Then the member
 * 		is removed while simultaneously updated the list of members
 * 		and updating the list of members size.
 *
 * 		Returns - found (bool)
 *************************************************************************/
bool MemberList::RemoveMember(string fullName)	// IN & CALC - Remove name
{
	// Variable List
	bool    found;		// CALC & OUT - If removed or not
	Member *tempPtr;	// CALC		  - Temp ptr to remove from list
	Member *toRemove;	// CALC		  - Ptr of member to remove

	// PROCESSING - Remove member not found & search for member to remove
	found = false;
	toRemove = SearchForMember(fullName);

	// PROCESSING - Check that list is not empty
	if(toRemove != NULL)
	{
		tempPtr = headMember;

		// PROCESSING - Keep looping until end of list or remove item found
		while(tempPtr != NULL && !found)
		{
			// PROCESSING - If remove member is found or go to next in list
			if(tempPtr == toRemove)
			{
				found = true;
			}
			else
			{
				tempPtr = tempPtr->GetNext();
			}
		} // END - While loop
	} // END - If (toRemove != NULL)

	// PROCESSING - If member to remove is found
	if(found)
	{
		// PROCESSING - If member to remove is at the front of the list
		if(tempPtr == headMember)
		{
			headMember = headMember->GetNext();
			headMember->SetPrev(NULL);
		}
		// PROCESSING - If member to remove is at the end of the list
		else if(tempPtr == tailMember)
		{
			tailMember = tailMember->GetPrev();
			tailMember->SetNext(NULL);
		}
		// PROCESSING - If member to remove is in middle of list
		else
		{
			tempPtr->GetPrev()->SetNext(tempPtr->GetNext());
			tempPtr->GetNext()->SetNext(tempPtr->GetPrev());
		}

		delete tempPtr;
		memberSize--;
	}

	return found;
}

/**************************************************************************
 * IsEmpty
 * 		This method determines whether or not the list of members is
 * 		empty or not.
 *
 * 		Returns - empty (bool)
 *************************************************************************/
bool MemberList::IsEmpty() const
{
	// Variable List
	bool empty;	// CALC & OUT - List empty or not

	empty = false;

	// PROCESSING - Check if front of list is empty
	if(headMember == NULL)
	{
		empty = true;
	}

	return empty;
}

/**************************************************************************
 *	SearchForMember
 *		This method searches for a member in the list. It receives a
 *		name that is to be searched for. Then it loops through the
 *		entire list of members until the member is found or the end
 *		of the list has been reached.
 *
 *		Returns - tempPtr (Member)
 *************************************************************************/
Member* MemberList::SearchForMember(string key) const // IN & CALC - Name
{
	// Variable List
	Member *tempPtr;	// CALC & OUT - Temp ptr to index list

	tempPtr = headMember;

	// Processing - Keep looping until member found or end of list
	while(tempPtr != NULL && tempPtr->GetName() != key)
	{
		tempPtr = tempPtr->GetNext();
	}

	return tempPtr;
}

/**************************************************************************
 * Print
 * 		This method prints information about all the members in the list.
 * 		It will index through until all members have been printed.
 *
 * 		Returns - nothing (Prints list of members to console)
 *************************************************************************/
void MemberList::PrintMemberList() const
{
	// Variable List
	Member *currPtr; // CALC & OUT - Prints list of members

	currPtr = headMember;

	// PROCESSING - Loop until all members in list are printed
	while(currPtr != NULL)
	{
		currPtr->Print();
		cout << endl;
		currPtr = currPtr->GetNext();
	}

	cout << endl;
}
