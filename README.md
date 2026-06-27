*This project has been created as part of the 42 curriculum by mathvall.*

## DESCRIPTION

This project is a simulation, where multiple "people" (philosophers, which are represented as threads with a certain routine in the project) must try to avoid dying by starvation. All of the philosophers live their lives by alternating between thinking, eating, sleeping. If a philosopher does not eat in a certain period of time determined at the beginning (time_to_die), he dies, and the simulation stops.<br>
Each philosopher has a fork to his right and to his left (except if it's just one philosopher, then he only has one fork), and they are seated on a rounded table : therefore the right fork of one philosopher is the left of another one (same exception as previously). To eat (and so : stay alive), they need 2 forks, so all the philosophers must take turns eating, and they mustn't communicate with each other. All of them take the same time to eat a meal and to sleep, but their thinking process may take as much time as they want.

The difficulty here was
1. designing an algorithm that would allow them to take turns eating in the most efficient way, so they don't die in the most possible cases.
2. handling threads, and "mutexes" which is like a lock that only allows one thread (philosopher) to detain it at a time, just like the forks in the simulation. It can also be used to allow only one thread at a time to access a particular variable/data information.

## INSTRUCTIONS

run at the root of the cloned folder :<br>
```bash
cd philo
```

then run :<br>
```bash
make
```

you will then have to run the program with the following arguments. Argument 4 (eat_limit) is optional :<br>
```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep eat_limit
```

All of the arguments need to be non floating numbers ranging from 0 to 2147483647 to make the program start. Some values may still give no result if the logic behind it is not supposed to give you any (example : 0 philosopher at the table, so 0 as argument 1).

- ./philo is the name of the program, and tells the computer to run it.
- number_of_philosophers indicates how many philosophers take part in the simulation.
- time_to_die indicates the time span, in milliseconds, after which a philosopher dies if they have not started eating.
- time_to_eat indicates the time span, in milliseconds, a philosopher takes to eat his meal.
- time_to_sleep indicates the time span, in milliseconds, a philosopher takes to rest/sleep.
- eat_limit indicates the number of meals each philosopher must have eaten.

## RESOURCES

https://medium.com/@ruinadd/philosophers-42-guide-the-dining-philosophers-problem-893a24bc0fe2<br>
https://fr.wikipedia.org/wiki/D%C3%AEner_des_philosophes<br>
man pages :<br>
https://man7.org/linux/man-pages/man3/pthread_create.3.html<br>
https://man7.org/linux/man-pages/man3/pthread_join.3.html<br>
http://manpagesfr.free.fr/man/man3/pthread_mutex_init.3.html<br>


AI was used in this project to help me understand the core principles of the functions allowed in the project, to understand their usage, to debug mutexes errors.
