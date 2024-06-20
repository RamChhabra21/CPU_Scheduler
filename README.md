# CPU_Scheduler

## Project Description

This project implements a CPU scheduler in C++ that simulates various CPU scheduling algorithms. The objective is to demonstrate the functionality and efficiency of different scheduling techniques, including Shortest Job First (SJF), First-Come, First-Served (FCFS), and potentially others.

## How to Run the Project

### Dependencies
To run this project, you need the following:
- C++ compiler (e.g., g++)
- Standard Template Library (STL) support in C++

### Compilation and Execution
1. **Clone the repository or download the source code.**
2. **Compile the code**:
    ```sh
    g++ cpu_scheduler.cpp -o cpu_scheduler
    ```
3. **Run the executable**:
    ```sh
    ./cpu_scheduler
    ```

## Internal Working of the Project

### Theory
CPU scheduling is the process of deciding which processes in the ready queue will be allocated to the CPU for execution. The main goals of CPU scheduling are to maximize CPU utilization, increase throughput, minimize waiting time, and ensure fairness among processes.

### Implemented Algorithms

#### Shortest Job First (SJF)
SJF schedules the process with the shortest burst time next. It is optimal for minimizing waiting time but can lead to the starvation of longer processes.

#### Longest Job First (LJF)
LJF schedules the process with the longest burst time next. It aims to reduce the number of context switches but can result in poor average waiting time.

#### Round Robin (RR)
RR assigns a fixed time quantum to each process in a cyclic order. It ensures fairness and responsiveness but can lead to higher average turnaround time.

#### Priority Scheduling (PS)
PS schedules processes based on priority, with higher priority processes executing first. It can lead to the starvation of lower priority processes unless aging is implemented.

#### Longest Remaining Job First (LRJF)
LRJF schedules the process with the longest remaining burst time. This can result in high turnaround times and is less commonly used in practice.

#### Shortest Remaining Job First (SRJF)
SRJF is a preemptive version of SJF that schedules the process with the shortest remaining burst time. It minimizes average turnaround time but can cause frequent context switches.

#### Multi-Level Feedback Queue (MLFQ)
MLFQ uses multiple queues with different priority levels. Processes move between queues based on their behavior and age, balancing responsiveness and throughput.

3. **Main Function**:
    The `main` function initializes the tasks and calls the scheduling functions based on user input or predefined conditions.

## Learning Takeaways

Working on this project provided insights into:
- The intricacies of various CPU scheduling algorithms.
- Implementing and simulating scheduling logic in C++.
- The impact of different scheduling strategies on process performance metrics such as waiting time and turnaround time.
- The importance of algorithm efficiency and optimization in systems programming.

## Resources and References

The following resources were instrumental in the development of this project:
- [GeeksforGeeks - CPU Scheduling Algorithms](https://www.geeksforgeeks.org/cpu-scheduling-in-operating-systems/)
- [Cplusplus.com - The C++ Resources Network](http://www.cplusplus.com/)
