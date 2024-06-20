# CPU Scheduler

## Project Description

This project simulates various CPU scheduling algorithms using C++. The primary objective is to demonstrate the functionality and efficiency of different scheduling techniques, including Shortest Job First (SJF), First-Come, First-Served (FCFS), and others.

## How to Run the Project

### Dependencies
To run this project, ensure you have:
- A C++ compiler (e.g., g++)
- Standard Template Library (STL) support in C++

### Compilation and Execution
1. **Obtain the Source Code**:
    - Clone the repository or download the code files.
2. **Compile the Code**:
    ```sh
    g++ cpu_scheduler.cpp -o cpu_scheduler
    ```
3. **Execute the Program**:
    ```sh
    ./cpu_scheduler
    ```

## Internal Working of the Project

### Theory
CPU scheduling involves determining which processes in the ready queue will be assigned to the CPU for execution. The primary goals of CPU scheduling include maximizing CPU utilization, increasing throughput, minimizing waiting time, and ensuring fairness among processes.

### Implemented Algorithms

#### Shortest Job First (SJF)
SJF schedules the process with the shortest burst time next. It is optimal for minimizing waiting time but can lead to the starvation of longer processes.

#### Longest Job First (LJF)
LJF schedules the process with the longest burst time next. It aims to reduce the number of context switches but can result in higher average waiting time.

#### Round Robin (RR)
RR assigns a fixed time quantum to each process in a cyclic order. This ensures fairness and responsiveness but can lead to higher average turnaround time.

#### Priority Scheduling (PS)
PS schedules processes based on priority, with higher priority processes executing first. This can lead to the starvation of lower priority processes unless aging is implemented.

#### Longest Remaining Job First (LRJF)
LRJF schedules the process with the longest remaining burst time. This approach can result in high turnaround times and is less commonly used in practice.

#### Shortest Remaining Job First (SRJF)
SRJF is a preemptive version of SJF that schedules the process with the shortest remaining burst time. It minimizes average turnaround time but can cause frequent context switches.

#### Multi-Level Feedback Queue (MLFQ)
MLFQ uses multiple queues with different priority levels. Processes move between queues based on their behavior and age, balancing responsiveness and throughput.

### Main Function
The `main` function initializes the tasks and invokes the scheduling functions based on user input or predefined conditions.

## Learning Takeaways

Working on this project provided insights into:
- The complexities of various CPU scheduling algorithms.
- Implementing and simulating scheduling logic in C++.
- The impact of different scheduling strategies on process performance metrics, such as waiting time and turnaround time.
- The significance of algorithm efficiency and optimization in systems programming.

## Resources and References

The following resources were essential in the development of this project:
- [GeeksforGeeks - CPU Scheduling Algorithms](https://www.geeksforgeeks.org/cpu-scheduling-in-operating-systems/)
- [Cplusplus.com - The C++ Resources Network](http://www.cplusplus.com/)
