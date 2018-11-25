#include "types.h"
#include "stat.h"
#include "uproc.h"
#include "user.h"

int
main(int argc, char *argv[])
{
    struct uproc p;
    char *p_states[5] = {"embryo", "sleeping", "runnable", "running", "zombie"};
    int b = getprocinfo(0,&p); 
    if (b != -1) {
        printf(1, "\tID\tP_ID\tSZ\tC_W\tK\tName\tState\n");
        printf(1, "\t%d\t%d\t%d\t%d\t%d\t%s\t%s\n", p.pid, p.parent_pid, p.sz, p.channel_wait,p.killed,p.name, p_states[p.state]);
        printf(1, "\n|LEGEND|\nID    --> Process ID\nP_ID  --> Process ID of Parent if present else 0\nSZ    --> Process Size\nC_W   --> 1 if Process is waiting on channel 0 otherwise\nK     --> 1 if the process has been killed\nName  --> Name of the process\nState --> State of the process\n\n");
        //printf(1, "Process size: %d\n", p.sz);
        //printf(1, "CHannel Wait: %d\n", p.channel_wait);
        //printf(1, "Killed: %d\n", p.killed);
        //printf(1, "Name: %s\n", p.name);
    }
    exit();
}
