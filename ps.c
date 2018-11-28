#include "types.h"
#include "stat.h"
#include "uproc.h"
#include "user.h"
#include "param.h"

int
main(int argc, char *argv[])
{
    struct uproc p;
    int i;
    char *p_states[5] = {"embryo", "sleeping", "runnable", "running", "zombie"};
    printf(1, "\tID\tP_ID\tSZ\tC_W\tK\tName\tState\n");
    for (i = 0; i<NPROC; i++)
    {
        int b = getprocinfo(i,&p); 
        if (b != -1) {
            printf(1, "\t%d", p.pid);
            printf(1, "\t%d", p.parent_pid);
            printf(1, "\t%d", p.sz);
            printf(1, "\t%s", p.channel_wait == 0 ? "No":"Yes");
            printf(1, "\t%s",p.killed == 0 ? "No": "Yes");
            printf(1, "\t%s",p.name);
            printf(1,"\t%s\n", p_states[p.state-1]);
        }
    }
    printf(1, "\n|LEGEND|\nID    --> Process ID\n");
    printf(1,"P_ID  --> Process ID of Parent if present else 0\n");
    printf(1,"SZ    --> Process Size\n");
    printf(1,"C_W   --> Is the Process waiting on channel?\n");
    printf(1,"K     --> Is the Process killed?\n");
    printf(1,"Name  --> Name of the process\n");
    printf(1,"State --> State of the process\n\n");
    exit();
}
