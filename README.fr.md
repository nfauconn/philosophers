[![en](https://img.shields.io/badge/lang-en-pink.svg)](https://github.com/nfauconn/philosophers/blob/master/README.md)
[![fr](https://img.shields.io/badge/lang-fr-purple.svg)](https://github.com/nfauconn/philosophers/blob/master/README.fr.md)

# Projet : Philosophers

## 🏁 Objectif 🏁

Apprendre les processus de threading et les mutex en résolvant le problème du dîner des philosophes.

## 🚀 Utilisation 🚀

```shell
git clone git@github.com:nfauconn/philosophers.git
cd philosophers/philo
make
```

```shell
./philo <nombre_de_philosophes> <temps_avant_de_mourir> <temps_pour_manger> <temps_pour_dormir> [<nombre_de_fois_que_chaque_philosophe_doit_manger>]
```

## 💡 Compétences 💡

- **Multithreading** : Créer, gérer et synchroniser des threads en utilisant la bibliothèque pthreads

- **Mutexes** : Utiliser des mutex pour contrôler l'accès des threads aux ressources partagées, prévenir les conditions de concurrence et assurer l'intégrité des données

- **Résolution de problèmes** : Implémentation d'une solution au problème du dîner des philosophes, en se concentrant sur l'allocation des ressources, la prévention des interblocages (data race) et la synchronisation

- **Gestion du temps et optimisation du code** : Optimisation des performances pour répondre aux contraintes de temps réel du projet

- **Formattage de logs** : Refléter l'état en temps réel de l'application, en garantissant que la sortie est synchronisée et précise

- **Connaissance des fonctions de la bibliothèque standard** : pour la gestion de la mémoire, des opérations d'entrée/sortie et de la gestion des threads

- **Langage C** : Syntaxe, sémantique et structures de données en C. Code efficace, propre et maintenable

- **Normes de codage** : Lisibilité du code (clean code)

- **Gestion des erreurs et débogage** : Pour éviter des sorties inattendues du programme. `valgrind` et `fsanitize` pour diagnostiquer et résoudre efficacement les problèmes

- **Gestion de la mémoire et prévention des leaks** : Gestion manuelle de la mémoire, y compris l'allocation et la désallocation dynamiques de la mémoire

## 📋 Instructions du projet 📋

### Instructions communes

- **Langage** : Le projet doit être écrit en C.
- **Conformité aux normes** : Le code doit adhérer aux normes de l'école.
- **Gestion des erreurs** : Les programmes ne doivent pas se terminer de manière inattendue (par exemple, faute de segmentation, bus error, double free). De tels incidents rendront le projet non fonctionnel et entraîneront une note de 0.
- **Gestion de la mémoire** : Toute la mémoire allouée sur le tas doit être correctement libérée. Les fuites de mémoire ne sont pas tolérées.
- **Exigences du Makefile** :
   - Doit compiler les fichiers sources pour obtenir le résultat requis avec les drapeaux `-Wall`, `-Wextra`, et `-Werror`.
   - Ne doit pas relink.
   - Doit contenir les règles `$(NAME)`, `all`, `clean`, `fclean`, et `re`.

### Partie obligatoire

#### Vue d'ensemble

- Un ou plusieurs philosophes s'assoient autour d'une table ronde. Il y a un grand bol de spaghetti au milieu de la table.
- Les philosophes mangent, pensent ou dorment alternativement.
  - Pendant qu'ils mangent, ils ne pensent ni ne dorment ;
  - Pendant qu'ils pensent, ils ne mangent ni ne dorment ;
  - Pendant qu'ils dorment, ils ne mangent ni ne pensent.
- Il y a aussi des fourchettes sur la table. Il y a autant de fourchettes que de philosophes.
- Comme il est très inconfortable de servir et de manger des spaghetti avec une seule fourchette, un philosophe prend les fourchettes de droite et de gauche pour manger, une dans chaque main.
- Lorsqu'un philosophe a fini de manger, il remet ses fourchettes sur la table et commence à dormir. Une fois réveillé, il recommence à penser. La simulation s'arrête lorsqu'un philosophe meurt de faim.
- Chaque philosophe doit manger et ne doit jamais mourir de faim.
- Les philosophes ne parlent pas entre eux.
- Les philosophes ne savent pas si un autre philosophe est sur le point de mourir.
- Les philosophes doivent éviter de mourir.

#### Règles globales

- Les variables globales sont interdites
- Le programme doit prendre les arguments suivants :
	- `nombre_de_philosophes` : Le nombre de philosophes et également le nombre de fourchettes.
	- `temps_avant_de_mourir` (ms) : Si un philosophe n'a pas commencé à manger `temps_avant_de_mourir` millisecondes depuis le début de son dernier repas ou le début de la simulation, il meurt.
	- `temps_pour_manger` (ms) : Le temps qu'il faut à un philosophe pour manger. Pendant ce temps, il devra tenir deux fourchettes.
	- `temps_pour_dormir` (ms) : Le temps qu'un philosophe passera à dormir.
	- [`nombre_de_fois_que_chaque_philosophe_doit_manger`] (optionnel) : Si tous les philosophes ont mangé au moins `nombre_de_fois_que_chaque_philosophe_doit_manger` fois, la simulation s'arrête. Si non spécifié, la simulation s'arrête lorsqu'un philosophe meurt.

- Chaque philosophe a un numéro allant de 1 à `nombre_de_philosophes`.
- Le philosophe numéro 1 est assis à côté du philosophe numéro `nombre_de_philosophes`. Tout autre philosophe numéro N est assis entre le philosophe numéro N - 1 et le philosophe numéro N + 1.

- Tout changement d'état d'un philosophe doit être consigné de la manière suivante :
	- timestamp_in_ms X has taken a fork
	- timestamp_in_ms X is eating
	- timestamp_in_ms X is sleeping
	- timestamp_in_ms X is thinking
	- timestamp_in_ms X died

- Un message d'état affiché ne doit pas être mélangé avec un autre message.

- Un message annonçant la mort d'un philosophe doit être affiché au plus 10 ms après la mort réelle du philosophe.

- Le programme ne doit pas avoir de data race

| | |
--|--|
Nom du programme | `philo` 
Fichiers à rendre | `Makefile`, `*.h`, `*.c`, dans le répertoire `philo/` 
Makefile  | `NAME`, `all`, `clean`, `fclean`, `re` 
Arguments  | `nombre_de_philosophes` `temps_avant_de_mourir` `temps_pour_manger` `temps_pour_dormir` [`nombre_de_fois_que_chaque_philosophe_doit_manger`]
Fonctions externes | `memset`, `printf`, `malloc`, `free`, `write`, `usleep`, `gettimeofday`, `pthread_create`, `pthread_detach`, `pthread_join`, `pthread_mutex_init`, `pthread_mutex_destroy`, `pthread_mutex_lock`, `pthread_mutex_unlock`
Libft autorisé | Non
Description | Philosophes avec threads et mutexes

- Chaque philosophe doit être un thread.
- Il y a une fourchette entre chaque paire de philosophes. Par conséquent, s'il y a plusieurs philosophes, chaque philosophe a une fourchette à sa gauche et une fourchette à sa droite. S'il n'y a qu'un seul philosophe, il ne doit y avoir qu'une seule fourchette sur la table.
- Pour éviter que les philosophes ne dupliquent les fourchettes, l'état des fourchettes doit être protégé par un mutex pour chacune d'entre elles.