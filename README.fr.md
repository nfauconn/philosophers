[![en](https://img.shields.io/badge/lang-en-pink.svg)](https://github.com/nfauconn/philosophers/blob/master/README.md)
[![fr](https://img.shields.io/badge/lang-fr-purple.svg)](https://github.com/nfauconn/philosophers/blob/master/README.fr.md)

*Langage de programmation C* • *Multithreading* • *Mutexes* • *Résolution de problèmes* • *Gestion du temps et optimisation dans le code* • *Formatage des logs* • *Normes de codage (Conformité aux normes)* • *Gestion des erreurs et débogage* • *Automatisation de la compilation avec Makefile*

# Philosophes

Apprendre le processus de threading et les mutexes en résolvant le problème des philosophes qui dînent.

- Un ou plusieurs philosophes sont assis autour d'une table ronde. Il y a un grand bol de spaghetti au milieu de la table.
- Les philosophes mangent, pensent ou dorment alternativement.
  - En mangeant, ils ne pensent ni ne dorment ;
  - En pensant, ils ne mangent ni ne dorment ;
  - En dormant, ils ne mangent ni ne pensent.
- Il y a aussi des fourchettes sur la table. Il y a autant de fourchettes que de philosophes.
- Comme il est très inconfortable de servir et de manger des spaghettis avec une seule fourchette, un philosophe prend la fourchette à sa droite et celle à sa gauche pour manger, une dans chaque main.
- Lorsqu'un philosophe a fini de manger, il repose ses fourchettes sur la table et commence à dormir. Une fois réveillé, il se remet à penser. La simulation s'arrête lorsqu'un philosophe meurt de faim.
- Chaque philosophe doit manger et ne jamais mourir de faim.
- Les philosophes ne parlent pas entre eux.
- Les philosophes ne savent pas si un autre philosophe est sur le point de mourir.

| Clé | Valeur |
--|--|
Nom du programme | `philo` 
Langage | C
Fichiers à rendre | `Makefile`, `*.h`, `*.c`, dans le répertoire `philo/` 
Makefile  | `NAME`, `all`, `clean`, `fclean`, `re` 
Arguments  | `number_of_philosophers` `time_to_die` `time_to_eat` `time_to_sleep` [`number_of_times_each_philosopher_must_eat`]
Fonct. externes | `memset`, `printf`, `malloc`, `free`, `write`, `usleep`, `gettimeofday`, `pthread_create`, `pthread_detach`, `pthread_join`, `pthread_mutex_init`, `pthread_mutex_destroy`, `pthread_mutex_lock`, `pthread_mutex_unlock`

- Chaque philosophe est un thread.
- Pour éviter que les philosophes ne prennent deux fois la même fourchette, l'état des fourchettes est protégé par un mutex pour chacune d'elles.

- Tout changement d'état d'un philosophe sera consigné au format suivant :
	- timestamp_in_ms X has taken a fork
	- timestamp_in_ms X is eating
	- timestamp_in_ms X is sleeping
	- timestamp_in_ms X is thinking
	- timestamp_in_ms X died

- Un message indiquant l'état affiché ne sera jamais mélangé avec un autre message.

- Un message annonçant la mort d'un philosophe sera affiché au plus 10 ms après la mort réelle du philosophe.

- Le programme n'a aucune course de données.

## Utilisation

```shell
git clone git@github.com:nfauconn/philosophers.git
cd philosophers/philo
make
```

```shell
./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [<number_of_times_each_philosopher_must_eat>]
```

- `number_of_philosophers` : Le nombre de philosophes et aussi le nombre de fourchettes.
- `time_to_die` (ms) : Si un philosophe n'a pas commencé à manger dans les time_to_die millisecondes depuis le début de son dernier repas ou le début de la simulation, il meurt.
- `time_to_eat` (ms) : Le temps qu'il faut à un philosophe pour manger. Pendant ce temps, il doit tenir deux fourchettes.
- `time_to_sleep` (ms) : Le temps qu'un philosophe passera à dormir.
- [`number_of_times_each_philosopher_must_eat`] (optionnel) : Si tous les philosophes ont mangé au moins number_of_times_each_philosopher_must_eat fois, la simulation s'arrête. Si non spécifié, la simulation s'arrête lorsqu'un philosophe meurt.