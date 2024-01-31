[![en](https://img.shields.io/badge/lang-en-pink.svg)](https://github.com/nfauconn/philosophers/blob/master/README.md)
[![fr](https://img.shields.io/badge/lang-fr-purple.svg)](https://github.com/nfauconn/philosophers/blob/master/README.fr.md)

*C programming language* • *Multithreading* • *Mutexes* • *Problem-Solving* • *Time Management and Optimization in Code* • *Log Formatting* • *Coding standards (Norm compliance)*  • *Error handling and debugging* • *Compilation Automation with Makefile*

# Philosophers

Learn threading process and mutexes by saving the dining philosophers problem.

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

Program name | `philo` 
--|--|
Language | C
Turn in files | `Makefile`, `*.h`, `*.c`, in directory `philo/` 
Makefile  | `NAME`, `all`, `clean`, `fclean`, `re` 
Arguments  | `number_of_philosophers` `time_to_die` `time_to_eat` `time_to_sleep` [`number_of_times_each_philosopher_must_eat`]
External functs. | `memset`, `printf`, `malloc`, `free`, `write`, `usleep`, `gettimeofday`, `pthread_create`, `pthread_detach`, `pthread_join`, `pthread_mutex_init`, `pthread_mutex_destroy`, `pthread_mutex_lock`, `pthread_mutex_unlock`

- Each philosopher is a thread.
- To prevent philosophers from duplicating forks, the forks state are protected with a mutex for each of them.

- Any state change of a philosopher will be logged formatted as follows:
	- timestamp_in_ms X has taken a fork
	- timestamp_in_ms X is eating
	- timestamp_in_ms X is sleeping
	- timestamp_in_ms X is thinking
	- timestamp_in_ms X died

- A displayed state message will never be mixed up with another message.

- A message announcing a philosopher died will be displayed no more than 10 ms after the actual death of the philosopher.

- The program does not have any data races.

## Usage

```shell
git clone git@github.com:nfauconn/philosophers.git
cd philosophers/philo
make
```

```shell
./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [<number_of_times_each_philosopher_must_eat>]
```

- `number_of_philosophers`: : The number of philosophers and also the number of forks.
- `time_to_die` (ms): If a philosopher didn’t start eating time_to_die milliseconds since the beginning of their last meal or the beginning of the simulation, they die.
- `time_to_eat` (ms): The time it takes for a philosopher to eat.  During that time, they will need to hold two forks.
- `time_to_sleep` (ms): The time a philosopher will spend sleeping.
- [`number_of_times_each_philosopher_must_eat`] (optional): If all philosophers have eaten at least number_of_times_each_philosopher_must_eat times, the simulation stops. If not specified, the simulation stops when a philosopher dies.

