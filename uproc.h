enum procstate { UNUSED, EMBRYO, SLEEPING, RUNNABLE, RUNNING, ZOMBIE };

//user process state information
struct uproc {
    uint sz;                        // Size of the process memory
    enum procstate state;           // Process state
    int pid;                        // Process Id
    int parent_pid;                 // Process Id of parent
    int channel_wait;               // check if the process is waiting on a channel
    int killed;                     // check if the process has been killed
    char name[16];                  // Process name
};
