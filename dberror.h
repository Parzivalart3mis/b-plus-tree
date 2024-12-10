#ifndef DBERROR_H
#define DBERROR_H

#include "stdio.h"

/* module wide constants */
#define PAGE_SIZE 4096

/* return code definitions */
typedef int RC;

#define RC_OK 0
#define RC_FILE_NOT_FOUND 1
#define RC_FILE_HANDLE_NOT_INIT 2
#define RC_WRITE_FAILED 3
#define RC_READ_NON_EXISTING_PAGE 4

// Custom error codes
#define RC_PINNED_PAGES                  10
#define RC_BUFFER_POOL_ALREADY_INIT     101
#define RC_BUFFER_POOL_NOT_INIT         102
#define RC_BUFFER_POOL_SHUTDOWN         103
#define RC_PINNED_PAGES_IN_POOL         104
#define RC_PAGE_NOT_FOUND               105
#define RC_PAGE_ALREADY_PINNED          106
#define RC_PAGE_NOT_PINNED              107
#define RC_BUFFER_POOL_FULL             108
#define RC_REPLACEMENT_STRATEGY_NOT_IMPLEMENTED 109

#define RC_RM_COMPARE_VALUE_OF_DIFFERENT_DATATYPE 200
#define RC_RM_EXPR_RESULT_IS_NOT_BOOLEAN 201
#define RC_RM_BOOLEAN_EXPR_ARG_IS_NOT_BOOLEAN 202
#define RC_RM_NO_MORE_TUPLES 203
#define RC_RM_NO_PRINT_FOR_DATATYPE 204
#define RC_RM_UNKOWN_DATATYPE 205

#define RC_IM_KEY_NOT_FOUND 300
#define RC_IM_KEY_ALREADY_EXISTS 301
#define RC_IM_N_TO_LAGE 302
#define RC_IM_NO_MORE_ENTRIES 303

#define RC_IM_SCAN_NOT_OPEN 601
#define RC_IM_TREE_NOT_INITIALIZED 602
#define RC_READ_FAILED 603
#define RC_NULL_ARGUMENT 604
#define RC_FILE_CREATION_FAILED 605
#define RC_MEMORY_ALLOCATION_FAIL 606
#define RC_INVALID_HANDLE 607
#define RC_MEMORY_ALLOCATION_FAILED 608
#define RC_IM_TREE_EMPTY 609

/* holder for error messages */
extern char *RC_message;

/* print a message to standard out describing the error */
extern void printError (RC error);
extern char *errorMessage (RC error);

#define THROW(rc,message) \
		do {			  \
			RC_message=message;	  \
			return rc;		  \
		} while (0)		  \

// check the return code and exit if it is an error
#define CHECK(code)							\
		do {									\
			int rc_internal = (code);						\
			if (rc_internal != RC_OK)						\
			{									\
				char *message = errorMessage(rc_internal);			\
				printf("[%s-L%i-%s] ERROR: Operation returned error: %s\n",__FILE__, __LINE__, __TIME__, message); \
				free(message);							\
				exit(1);							\
			}									\
		} while(0);


#endif
