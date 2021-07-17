#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"
#include "param.h"
#include "mmu.h"
#include "proc.h"

int
main(int argc, char *argv[])
{
  struct proc_user ptable[NPROC];
  struct proc_user *ps;
  int x, z;
    for(int k = 0; k < 5; k++) {
        int id = fork();
        if (id == 0) {
            setpriority(15-k, 10);
            for (int i = 0; i < 20; ++i) {
                sleep(10);
                for(z = 0; z < 200; z+=1)
	           x = x + 3.14*68.45; //cpu time consumption
            }
            if (copystruct(NPROC, NPROC * sizeof(struct proc_user), &ptable) < 0) {
               printf(1, "Error getting ptable");
               exit();
            }
            for(ps = ptable; ps != &ptable[NPROC-1]; ps++) {
            printf(1, "\nPID = %d", ps->pid);
            printf(1, "\nPID = %d", ps->name);
            printf(1, "\nState = %d", ps->state);
            printf(1, "\nPriority = %d",  ps->priority);
            printf(1,"\n");
            printf(1, "test %d ended\n", k+1);
            exit();
           }
        }
    }
    for(int k = 0; k < 5; k++) {
        wait();
    }
    exit();
}
