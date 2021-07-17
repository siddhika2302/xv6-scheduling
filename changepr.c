#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main(int argc, char *argv[])
{
  int priority, pid;

  if (argc < 3) {
    printf(2, "Usage: changepr pid priority\n" );
    exit();
  }

  pid = atoi(argv[1]);
  priority = atoi(argv[2]);
  if (priority <= 0 || priority > 20){
    printf(2, "Warning : Priority should be > 1 and < 20\n" );
    exit();
  }
  setpriority(pid, priority);
  exit();
}
