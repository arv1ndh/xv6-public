#include "types.h"
#include "stat.h"
#include "uproc.h"
#include "user.h"

int
main(int argc, char *argv[])
{
    struct uproc p;
    int b = getprocinfo(0,&p); 
    if (b != -1) {
        printf(1, "Process ID: %d\n", p.pid);
        printf(1, "Parent Process ID: %d\n", p.parent_pid);
        printf(1, "Process size: %d\n", p.sz);
        printf(1, "CHannel Wait: %d\n", p.channel_wait);
        printf(1, "Killed: %d\n", p.killed);
        printf(1, "Name: %s\n", p.name);
    }
    exit();
}
