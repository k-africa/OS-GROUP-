# OS-GROUP-
 ERNEST AGYEMANG       219IT01000038
 JANET    OPPONG       219EI01000035
 BROMINI OGHENEYOMA    214IT02002403
 
 In operating systems, memory management is the function responsible for managing the computer's primary memory. The memory management function keeps track of the status of each memory location, either allocated or free. It tracks when memory is freed or unallocated and updates the status.


Fixed Partitioning:
This is the oldest and simplest technique used to put more than one processes in the main memory. In this partitioning, number of partitions (non-overlapping) in RAM are fixed but size of each partition may or may not be same. As it is contiguous allocation, hence no spanning is allowed.

Variable Partitioning
In variable Partitioning, space in main memory is allocated strictly according to the need of process, hence there is no case of internal fragmentation. There will be no unused space left in the partition.


Priority scheduling algorithm
Priority Scheduling is a method of scheduling processes that is based on priority. In this algorithm, the scheduler selects the tasks to work as per the priority. The processes with higher priority should be carried out first, whereas jobs with equal priorities are carried out on a round-robin or FCFS basis.

Shortest Job First (SJF) is an algorithm in which the process having the smallest execution time is chosen for the next execution. This scheduling method can be preemptive or non-preemptive. It significantly reduces the average waiting time for other processes awaiting execution


Round robin is a pre-emptive algorithm. The CPU is shifted to the next process after fixed interval time, which is called time quantum/time slice. The process that is preempted is added to the end of the queue. Round robin is a hybrid model which is clock-driven.

Multi-level queueing, used at least since the late 1950s/early 1960s, is a queue with a predefined number of levels. Unlike the multilevel feedback queue, items get assigned to a particular level at insert, and thus cannot be moved to another level.


The banker's algorithm is a resource allocation and deadlock avoidance algorithm that tests for safety by simulating the allocation for predetermined maximum possible amounts of all resources, then makes an “s-state” check to test for possible activities, before deciding whether allocation should be allowed to continue 
