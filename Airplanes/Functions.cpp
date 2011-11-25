
/* Result Sets Interface */
#ifndef SQL_CRSR
#  define SQL_CRSR
  struct sql_cursor
  {
    unsigned int curocn;
    void *ptr1;
    void *ptr2;
    unsigned int magic;
  };
  typedef struct sql_cursor sql_cursor;
  typedef struct sql_cursor SQL_CURSOR;
#endif /* SQL_CRSR */

/* Thread Safety */
typedef void * sql_context;
typedef void * SQL_CONTEXT;

/* Object support */
struct sqltvn
{
  unsigned char *tvnvsn; 
  unsigned short tvnvsnl; 
  unsigned char *tvnnm;
  unsigned short tvnnml; 
  unsigned char *tvnsnm;
  unsigned short tvnsnml;
};
typedef struct sqltvn sqltvn;

struct sqladts
{
  unsigned int adtvsn; 
  unsigned short adtmode; 
  unsigned short adtnum;  
  sqltvn adttvn[1];       
};
typedef struct sqladts sqladts;

static struct sqladts sqladt = {
  1,1,0,
};

/* Binding to PL/SQL Records */
struct sqltdss
{
  unsigned int tdsvsn; 
  unsigned short tdsnum; 
  unsigned char *tdsval[1]; 
};
typedef struct sqltdss sqltdss;
static struct sqltdss sqltds =
{
  1,
  0,
};

/* File name & Package Name */
struct sqlcxp
{
  unsigned short fillen;
           char  filnam[13];
};
static const struct sqlcxp sqlfpn =
{
    12,
    "Functions.pc"
};


static unsigned int sqlctx = 307763;


static struct sqlexd {
   unsigned int   sqlvsn;
   unsigned int   arrsiz;
   unsigned int   iters;
   unsigned int   offset;
   unsigned short selerr;
   unsigned short sqlety;
   unsigned int   occurs;
      const short *cud;
   unsigned char  *sqlest;
      const char  *stmt;
   sqladts *sqladtp;
   sqltdss *sqltdsp;
            void  **sqphsv;
   unsigned int   *sqphsl;
            int   *sqphss;
            void  **sqpind;
            int   *sqpins;
   unsigned int   *sqparm;
   unsigned int   **sqparc;
   unsigned short  *sqpadto;
   unsigned short  *sqptdso;
   unsigned int   sqlcmax;
   unsigned int   sqlcmin;
   unsigned int   sqlcincr;
   unsigned int   sqlctimeout;
   unsigned int   sqlcnowait;
              int   sqfoff;
   unsigned int   sqcmod;
   unsigned int   sqfmod;
            void  *sqhstv[4];
   unsigned int   sqhstl[4];
            int   sqhsts[4];
            void  *sqindv[4];
            int   sqinds[4];
   unsigned int   sqharm[4];
   unsigned int   *sqharc[4];
   unsigned short  sqadto[4];
   unsigned short  sqtdso[4];
} sqlstm = {12,4};

// Prototypes
extern "C" {
  void sqlcxt (void **, unsigned int *,
               struct sqlexd *, const struct sqlcxp *);
  void sqlcx2t(void **, unsigned int *,
               struct sqlexd *, const struct sqlcxp *);
  void sqlbuft(void **, char *);
  void sqlgs2t(void **, char *);
  void sqlorat(void **, unsigned int *, void *);
}

// Forms Interface
static const int IAPSUCC = 0;
static const int IAPFAIL = 1403;
static const int IAPFTL  = 535;
extern "C" { void sqliem(unsigned char *, signed int *); }

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* cud (compilation unit data) array */
static const short sqlcud0[] =
{12,4130,178,0,0,
5,0,0,0,0,0,27,38,0,0,4,4,0,1,0,1,97,0,0,1,10,0,0,1,10,0,0,1,10,0,0,
36,0,0,2,0,0,30,55,0,0,0,0,0,1,0,
51,0,0,3,0,0,32,82,0,0,0,0,0,1,0,
66,0,0,4,107,0,4,114,0,0,2,1,0,1,0,2,97,0,0,1,97,0,0,
};


/******************************************************************************
* Filename    : Functions.cpp
* Author      : FTMK, UTeM
* Description : Contains the functions required for opening or closing database
*               connections.
*               Part of Programming Fundamentals file
* Modification Log: 
******************************************************************************/

/* Include files */
#include "stdafx.h"
#include <iostream>
#include <string.h>

#include <sqlca.h>
#include <sqlcpr.h>

/* Declaration of functions and constants used */
#include "Functions.h"

using namespace std;

/******************************************************************************
* Function: fnConnectDB
* Description: Connect to Oracle 10g Database
******************************************************************************/
void fnConnectDB()
{	
	/*host variable declaration*/
	/* EXEC SQL BEGIN DECLARE SECTION; */ 

        char connection_name[128];
	/* EXEC SQL END DECLARE SECTION; */ 

	/*copy the connection string to host variable*/
    strcpy_s(connection_name, "tokwan/abc123@orcl");

	/*redirect to display error if database error occurs*/
	/* EXEC SQL WHENEVER SQLERROR DO sql_error("do_connect():CONNECT"); */ 

	/* EXEC SQL CONNECT :connection_name; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 4;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )10;
 sqlstm.offset = (unsigned int  )5;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (         void  *)connection_name;
 sqlstm.sqhstl[0] = (unsigned int  )128;
 sqlstm.sqhsts[0] = (         int  )128;
 sqlstm.sqindv[0] = (         void  *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned int  )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlstm.sqlcmax = (unsigned int )100;
 sqlstm.sqlcmin = (unsigned int )2;
 sqlstm.sqlcincr = (unsigned int )1;
 sqlstm.sqlctimeout = (unsigned int )0;
 sqlstm.sqlcnowait = (unsigned int )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("do_connect():CONNECT");
}


	
	/*********/
	/* this code is to print the connection statement to verify the connection
	 * is successful. Uncomment this if you want to verify whether the 
	 * connection to database is successful
	 * this is not needed in the system*/
	//printf("Connected to database.\n");
}

/******************************************************************************
* Function: fnCloseConnectionDB
* Description: Closes and commits the database connection
******************************************************************************/
void fnCloseDBConnection()
{
	/*close database connection*/
	/* EXEC SQL COMMIT WORK RELEASE; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 4;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )36;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("do_connect():CONNECT");
}


}

/******************************************************************************
* Function: sql_error
* Description:  Generic error handler.  The 'routine' parameter should contain 
* the name of the routine executing when the error occured.  This would be 
* specified in the 'EXEC SQL WHENEVER SQLERROR DO sql_error()' statement.
* Input Parameters: 
*                 char *routine
******************************************************************************/
 void sql_error(char *routine)
{
	char message_buffer[512];
	size_t buffer_size;
	//size_t message_length;

	/* Turn off the call to sql_error() to avoid a possible infinite loop */
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	
	cout<<"\nOracle error while executing "<<routine<<"!\n";

	/* Use sqlglm() to get the full text of the error message. */
	buffer_size = sizeof(message_buffer);
	//sqlglm(message_buffer, &buffer_size, &message_length);
	//cout<<message_length<<", "<<message_buffer<<"\n";

	/* EXEC SQL ROLLBACK WORK RELEASE; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 4;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )51;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	exit(1);
}

/******************************************************************************
* Function: toChar
* Description:  Convert CString to char *
* Input Parameters: 
*                 CString string
******************************************************************************/
char* toChar(CString string){
	char *str = (char *) malloc (sizeof(char)*25);
	wcstombs(str, string.GetBuffer(0), 25);
	return str;
}

 /******************************************************************************
* Function: login
* Description:  Login into the database
* Input Parameters: 
*                 CString _username,CString _password
******************************************************************************/
char fnLogin(CString _username,CString _password)
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		char username[25],password[25];
		char position[15];
	/* EXEC SQL END DECLARE SECTION; */ 


	strcpy_s(username,toChar(_username));
	strcpy_s(password,toChar(_password));

	/* EXEC SQL SELECT UPPER(ST_POSITION) INTO :position FROM STAFF 
		WHERE ST_ID = (SELECT ST_ID FROM LOGIN WHERE LG_USERNAME = :username); */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 4;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select UPPER(ST_POSITION) into :b0  from STAFF where ST_ID=(\
select ST_ID  from LOGIN where LG_USERNAME=:b1)";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )66;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (         void  *)position;
 sqlstm.sqhstl[0] = (unsigned int  )15;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         void  *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned int  )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (         void  *)username;
 sqlstm.sqhstl[1] = (unsigned int  )25;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         void  *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned int  )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



	return position[0];
}

/******************************************************************************
* End of DBFunctions.c
******************************************************************************/