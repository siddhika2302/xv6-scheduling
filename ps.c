#include "types.h"
#include "stat.h"
#include "user.h"
#include "param.h"
#include "mmu.h"
#include "proc.h"

int main(int argc, char *argv[]){  
  struct user_proc ptable[NPROC];
  struct user_proc *p;

  if (copystruct(NPROC, NPROC * sizeof(struct user_proc), &ptable) < 0) {
    printf(1, "Error getting ptable");
    exit();
  }
  

  printf(1, "PID\tPPID\tArrival time\tSTATE\t\tProcess\n");
  for(p = ptable; p != &ptable[NPROC-1]; p++) {      
        if (p->state == UNUSED) continue;

	// init does not have ppid!
	if (p->pid == 1)
	    printf(1, "%d\tN/A",p->pid);
	else
	    printf(1, "%d\t%d", p->pid, p->ppid);

        printf(1, "\t%d", p->arrival_time);

  	switch(p->state){
  	case UNUSED:
  		printf(1, "\t\t%s", "UNUSED  ");
  		break;
  	case EMBRYO:
  		printf(1, "\t\t%s", "EMBRYO  ");
  		break;
  	case SLEEPING:
  		printf(1, "\t\t%s", "SLEEPING");
  		break;
  	case RUNNABLE:
  		printf(1, "\t\t%s", "RUNNABLE");
  		break;
  	case RUNNING:
  		printf(1, "\t\t%s", "RUNNING ");
  		break;
  	case ZOMBIE:
  		printf(1, "\t\t%s", "ZOMBIE  ");
  		break;
  	} 
  	printf(1, "\t%s\n", p->name);
  }
  printf(1, "\n");
  exit();
}
