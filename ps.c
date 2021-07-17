#include "types.h"
#include "stat.h"
#include "user.h"
#include "param.h"
#include "mmu.h"
#include "proc.h"

int main(int argc, char *argv[]){  
  struct proc_user ptable[NPROC];
  struct proc_user *p;

  if (copystruct(NPROC, NPROC * sizeof(struct proc_user), &ptable) < 0) {
    printf(1, "Error getting ptable");
    exit();
  }
  

  printf(1, "PID\tPRI\tSTATE\t\tNAME\tRuntime\n");
  for(p = ptable; p != &ptable[NPROC-1]; p++) {
  	if (p->state == UNUSED) continue;      
	printf(1, "%d",p->pid);
	printf(1, "\t%d", p->priority);
  	switch(p->state){ 
  	case RUNNABLE:
  		printf(1, "\t%s", "RUNNABLE");
  		break;
  	case RUNNING:
  		printf(1, "\t%s", "RUNNING ");
  		break;
  	case EMBRYO:
  		printf(1, "\t%s", "EMBRYO");
  		break;
  	case UNUSED:
  		printf(1, "\t%s", "UNUSED");
  		break;
  	case ZOMBIE:
  		printf(1, "\t%s", "ZOMBIE");
  		break; 	
  	case SLEEPING:
  		printf(1, "\t%s", "SLEEPING");
  		break;
  	
  	} 
  	printf(1, "\t%s", p->name);
  	printf(1, "\t%d\n", p->runtime);
  }

  printf(1, "\n");
  exit();
}
