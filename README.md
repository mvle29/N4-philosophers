*This project has been created as part of the 42 curriculum by mathvall.*

## DESCRIPTION

This project is a simulation, where multiple "people" (philosophers, which are represented as threads with a certain routine in the project) need to stay alive for the longest time possible. All of the philosophers live their lives by alternating between thinking, eating, sleeping. All of them take the same time to eat a meal and to sleep, but their thinking process may take as much time as they want. If a philosopher does not eat in a certain period of time determined at the beggining (time_to_die), he dies, and the simulation stops.<br>
Each philosopher has a fork to its right and to its left (except if it's just one philosopher, then he only has one fork), and they are seated on a rounded table : therefore the right fork of one philosopher is the left of another one (same exception as previously). To eat (and so : stay alive), they need 2 forks, so all the philosophers must take turn eating, and they mustn't communicate with eachother.

The difficulty here was
1. calculating an algorithm that would allow them to take turns eating in the most efficient way, so they don't die in the most possible cases
2. handling threads, and "mutexes" which is like a lock that only allows one thread (philosopher) to detain it at a time, just like the forks in the simulation. It can also be used to allow only one thread at a time to access a particular variable/data information.

## INSTRUCTIONS

run at the root of the cloned folder :<br>
cd philo

then run :<br>
make

you will then have to run the program with the following argument. Argument 4 (eat_limit) is optional :<br>
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep eat_limit

All of the arguments need to be non floating numbers ranging from 0 to 2147483647 to make the program start. Some values may still give no result if the logic behind it is not supposed to give you any (example : 0 philosopher at the table, so 0 as argument 1).

./philo is the name of the program and tells the computer to run it.<br>
number of philospher indicate how many philosophers you want which will participate to the simulation.<br>
time_to_die indicates the time span, in milliseconds, after which a philosopher dies if they have not started eating.<br>
time_to_eat indicates the time span, in milliseconds, a philosopher takes to eat its meal.<br>
eat_limit indicates the number of meals of philosophers must have eaten to end the simulation.<br>

## RESOURCES

https://medium.com/@ruinadd/philosophers-42-guide-the-dining-philosophers-problem-893a24bc0fe2<br>
https://fr.wikipedia.org/wiki/D%C3%AEner_des_philosophes<br>
man pages :<br>
https://man7.org/linux/man-pages/man3/pthread_create.3.html<br>
https://man7.org/linux/man-pages/man3/pthread_join.3.html<br>
http://manpagesfr.free.fr/man/man3/pthread_mutex_init.3.html<br>


AI was used in this project to help me understand the core principles of the functions allowed in the project, to understand their usage, to debug mutexes errors.
