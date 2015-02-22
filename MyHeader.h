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
#ifndef MYHEADER_H_
#define MYHEADER_H_

#include <iostream>
#include <iomanip>
using namespace std;

/**************************************************************************
 * PrintHeader
 * 		This function receives four programmers name and student id number.
 * 		It also receives the programmers' assignment, lab, or group project
 * 		name, type (assignment, lab, or group), and assignment/lab/group
 * 		number. This prints the heading output for Team Apple.
 *
 * 	Returns : nothing (Displays header to console)
 *************************************************************************/
void PrintHeader(const string programmer1, // IN & OUT 		 - Programmer 1
				 const string programmer2, // IN & OUT 		 - Programmer 2
				 const string programmer3, // IN & OUT 		 - Programmer 3
				 const string programmer4, // IN & OUT 		 - Programmer 4
				 const int    sidNum1,	   // IN & OUT 		 - SID # 1
				 const int    sidNum2,	   // IN & OUT 		 - SID # 2
				 const int    sidNum3,	   // IN & OUT 		 - SID # 3
				 const int    sidNum4,	   // IN & OUT 		 - SID # 4
				 const string assgName,	   // IN & OUT       - Assg Name
				 const char   assgType,    // IN, CALC & OUT - Assg Type
				 const int    assgNum);	   // IN & OUT		 - Assg #

#endif /* MYHEADER_H_ */
