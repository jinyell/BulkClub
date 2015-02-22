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
#ifndef MEMBERLIST_H_
#define MEMBERLIST_H_

#include "PreferredMember.h"
#include <fstream>
#include <ios>
#include <limits>

class MemberList {
public:
	/***************************
	 ***CONSTRUCTOR & DESTRUCTOR
	 ***************************/
	MemberList();			// Default Constructor
	virtual ~MemberList();	// Destructor

	/**************
	 ***MUTATORS***
	 **************/
	void AddMemberFromFile(string fileName);	// Add members from file
	void AddMemberFromConsole();				// Add member from console
	void InsertInOrder(Member *addNode);		// Insert a member
	bool RemoveMember(string fullName);			// Remove a member
	bool ClearList();							// Clear all members

	/***************
	 ***ACCESSORS***
	 ***************/
	bool    IsEmpty() const;					// Check if list is empty
	Member* SearchForMember(string key) const;	// Search for a member
	void    PrintMemberList() const;			// Print members in list

private:
	Member *headMember;	// Head of list
	Member *tailMember;	// Tail of list
	int		memberSize;	// Number of members in list
};

#endif /* MEMBERLIST_H_ */
