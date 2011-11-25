/******************************************************************************
* Filename    : Functions.h
* Author      : FTMK, UTeM
* Description : Declaration of functions and constants required to use the
*               functions defined in Functions.cpp
* Modification Log: 
******************************************************************************/

/* Pre-defined constants */

/* Oracle error code for 'table or view does not exist'. */
#define NON_EXISTENT  -942
#define NOT_FOUND     1403

/* Function declarations */
void fnConnectDB();
void fnCloseDBConnection();
void sql_error(char *);
char fnLogin(CString ,CString);

/******************************************************************************
* End of FileFunctions.h
******************************************************************************/
