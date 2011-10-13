#ifndef _ULT_H_
#define _ULT_H_
#include <ucontext.h>

typedef int Tid;
#define ULT_MAX_THREADS 1024
#define ULT_MIN_STACK 32768



typedef struct ThrdCtlBlk
{
  Tid tid;
  ucontext_t threadContext;
  struct ThrdCtlBlk *tcbPointer;
} ThrdCtlBlk;


/*
 * waiting queue of threads
   ucontext_t ** ppThread;
*/


/*
 * Tids between 0 and ULT_MAX_THREADS-1 may
 * refer to specific threads and negative Tids
 * are used for error codes or control codes.
 * The first thread to run (before ULT_CreateThread
 * is called for the first time) must be Tid 0.
 */
static const Tid ULT_ANY = -1;
static const Tid ULT_SELF = -2;
static const Tid ULT_INVALID = -3;
static const Tid ULT_NONE = -4;
static const Tid ULT_NOMORE = -5;
static const Tid ULT_NOMEMORY = -6;
static const Tid ULT_FAILED = -7;

static inline int ULT_isOKRet(Tid ret)
{
  return (ret >= 0 ? 1 : 0);
}

/*
stub(void(*root)(void*),void *arg)
{
	fill this in
	Tid ret;
	root(arg); //call root fucntion
	ret = ULT_DestroyThread(ULT_SELF);
	assert(ret == ULT_NONE); //we should only get here if we are the last thread
	exit(0); //all threads are done so process should exit	
}
*/
Tid ULT_CreateThread(void (*fn)(void *), void *parg);
Tid ULT_Yield(Tid tid);
Tid ULT_DestroyThread(Tid tid);


 




#endif



