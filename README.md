[![en](https://img.shields.io/badge/lang-en-pink.svg)](https://github.com/nfauconn/philosophers/blob/master/README.md)
[![fr](https://img.shields.io/badge/lang-fr-purple.svg)](https://github.com/nfauconn/philosophers/blob/master/README.fr.md)

# Project: Philosophers

## 🏁 Goal 🏁

Learn threading process and mutexes by saving the dining philosophers problem.

## 🚀 Usage 🚀

```shell
git clone git@github.com:nfauconn/philosophers.git
cd philosophers/philo
make
```

```shell
./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [<number_of_times_each_philosopher_must_eat>]
```

## 💡 Skills 💡

- **Multithreading**: Creating, managing, and synchronizing threads using the pthreads library

- **Mutexes**: Using mutexes to control thread access to shared resources, preventing race conditions and ensuring data integrity

- **Problem-solving**: Implementing a solution to the dining philosophers problem, focusing on resource allocation, deadlock prevention, and synchronization.

- **Time management and optimization in code**: Optimizing performance to meet the real-time constraints of the project.

- **Log formatting**: Reflect the real-time state of the application, ensuring that output is synchronized and accurate.

- **Knowledge of standard library functions**: for memory, I/O operations, and thread management

- **C programming language**: C syntax, semantics, and data structures. Efficient, clean, and maintainable code.

- **Coding standards (Norm compliance)**: Code readability (clean code)

- **Error handling and debugging**: To prevent unexpected program exits. `valgrind` and `fsanitize` to diagnose and fix issues efficiently

- **Memory management and prevention of leaks**: Managed memory manually, including dynamic memory allocation and deallocation

## 📋 Project Instructions 📋

### Common Instructions

- **Language**: The project must be written in C.
- **Norm Compliance**: Code must adhere to the Norm of the school.
- **Error Handling**: Programs should not exit unexpectedly (e.g., segmentation fault, bus error, double free). Such incidents will render the project non-functional and result in a score of 0.
- **Memory Management**: All heap allocated memory must be properly freed. Memory leaks are not tolerated.
- **Makefile Requirements**:
   - Must compile source files to the required output with flags `-Wall`, `-Wextra`, and `-Werror`.
   - Must not relink.
   - Must contain the rules `$(NAME)`, `all`, `clean`, `fclean`, and `re`.

### Mandatory Part

#### Overview

- One or more philosophers sit at a round table. There is a large bowl of spaghetti in the middle of the table.
- The philosophers alternatively eat, think, or sleep.
  - While eating, they are not thinking nor sleeping;
  - While thinking, they are not eating nor sleeping;
  - While sleeping, they are not eating nor thinking.
- There are also forks on the table. There are as many forks as philosophers.
- Because serving and eating spaghetti with only one fork is very inconvenient, a philosopher takes their right and their left forks to eat, one in each hand.
- When a philosopher has finished eating, they put their forks back on the table and start sleeping. Once awake, they start thinking again. The simulation stops when a philosopher dies of starvation.
- Every philosopher needs to eat and should never starve.
- Philosophers don’t speak with each other.
- Philosophers don’t know if another philosopher is about to die.
- Philosophers should avoid dying.

#### Global rules

- Global variables are forbidden
- The program should take the following arguments:
	- `number_of_philosophers`: : The number of philosophers and also the number of forks.
	- `time_to_die` (ms): If a philosopher didn’t start eating time_to_die milliseconds since the beginning of their last meal or the beginning of the simulation, they die.
	- `time_to_eat` (ms): The time it takes for a philosopher to eat.  During that time, they will need to hold two forks.
	- `time_to_sleep` (ms): The time a philosopher will spend sleeping.
	- [`number_of_times_each_philosopher_must_eat`] (optional): If all philosophers have eaten at least number_of_times_each_philosopher_must_eat times, the simulation stops. If not specified, the simulation stops when a philosopher dies.

- Each philosopher has a number ranging from 1 to number_of_philosophers.
- Philosopher number 1 sits next to philosopher number number_of_philosophers.  Any other philosopher number N sits between philosopher number N - 1 and philosopher number N + 1.

- Any state change of a philosopher must be logged formatted as follows:
	- timestamp_in_ms X has taken a fork
	- timestamp_in_ms X is eating
	- timestamp_in_ms X is sleeping
	- timestamp_in_ms X is thinking
	- timestamp_in_ms X died

- A displayed state message should not be mixed up with another message.

- A message announcing a philosopher died should be displayed no more than 10 ms after the actual death of the philosopher.

- The program must not have any data races.

| | |
--|--|
Program name | `philo` 
Turn in files | `Makefile`, `*.h`, `*.c`, in directory `philo/` 
Makefile  | `NAME`, `all`, `clean`, `fclean`, `re` 
Arguments  | `number_of_philosophers` `time_to_die` `time_to_eat` `time_to_sleep` [`number_of_times_each_philosopher_must_eat`]
External functs. | `memset`, `printf`, `malloc`, `free`, `write`, `usleep`, `gettimeofday`, `pthread_create`, `pthread_detach`, `pthread_join`, `pthread_mutex_init`, `pthread_mutex_destroy`, `pthread_mutex_lock`, `pthread_mutex_unlock`
Libft authorized | No
Description | Philosophers with threads and mutexes

- Each philosopher should be a thread.
- There is one fork between each pair of philosophers. Therefore, if there are several philosophers, each philosopher has a fork on their left side and a fork on their right side. If there is only one philosopher, there should be only one fork on the table.
- To prevent philosophers from duplicating forks, the forks state must be protected with a mutex for each of them.