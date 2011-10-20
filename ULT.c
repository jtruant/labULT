#include <assert.h>
#include <stdlib.h>
/* We want the extra information from these definitions */
#ifndef __USE_GNU
#define __USE_GNU
#endif /* __USE_GNU */
#include <ucontext.h>
#include "ULT.h"
struct ThrdCtlBlk **queueHead;
Tid universalTid=0;


Tid 
ULT_CreateThread(void (*fn)(void *), void *parg)
{
  assert(0); /* TBD */
  return ULT_FAILED;
}


Tid ULT_Yield(Tid wantTid)
{
  
  if(wantTid>ULT_MAX_THREADS)
  {   
       /*The tid does not correspond to a valid thread*/ 
     return ULT_INVALID; 
  }
  
  /*assert(0);  TBD */
  /*return ULT_FAILED;*/
  ucontext_t currThread;
  getcontext(&currThread);
  
  /*build TCB*/
  struct ThrdCtlBlk *currBlock;
  /*allocate memory */
  currBlock=(struct ThrdCtlBlk*)malloc(sizeof(ThrdCtlBlk));
  currBlock->threadContext=currThread;
  currBlock->tid=universalTid;

  /*stick thread(TCB) on the ready queue*/
  currBlock->tcbPointerTail=*queueHead;  
  *queueHead=currBlock;
  /*change instruction pointer*/
  /*decide on new thread to run*/
  

}


Tid ULT_DestroyThread(Tid tid)
{
  assert(0); /* TBD */
  return ULT_FAILED;
}

struct ThrdCtlBlk fromQueue(Tid searchTid,struct ThrdCtlBlk **queueHead)
{
       // struct ThrdCtlBlk *tempBlock;
       struct ThrdCtlBlk *tempBlock;
       /*allocate memory */
       //tempBlock=(struct ThrdCtlBlk*)malloc(sizeof(ThrdCtlBlk));
       tempBlock=*queueHead;

	  while(tempBlock!=NULL)
          {
        	if(tempBlock->tid==searchTid)
		{
			return *tempBlock; 
		}
    		else
		{
			tempBlock=tempBlock->tcbPointerTail;
		}
          }

           	
}



