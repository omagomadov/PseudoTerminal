# Présentation des pseudo-terminaux pour le cours de SYG5 à l'ESI

## Description

Ce projet réunit un rapport détaillé et une présentation approfondie sur l'utilisation et la gestion des pseudo-terminaux sous Linux. De plus, un programme en C est fourni pour la mise en pratique. Les pseudo-terminaux constituent des éléments essentiels du système (Linux/Unix), employés notamment par des émulateurs de terminal tels que xterm.

## Contenu

- **Introduction :** Cette section offre une brève explication historique sur l'émergence des premiers terminaux physiques, soulignant la nécessité de leur utilisation.

- **Le terminal virtuel :** Explore le fonctionnement des terminaux virtuels sur le système d'exploitation Linux, mettant en lumière leur rôle dans la gestion des interfaces utilisateur.

- **Le pseudo-terminal :** Cette partie offre une explication approfondie sur les pseudo-terminaux, mettant en évidence leur importance dans le contexte des systèmes Linux/Unix. Il peut inclure des exemples concrets de situations où l'utilisation de pseudo-terminaux est cruciale, tels que les émulateurs de terminal comme xterm.

- **Mise en pratique :** Cette section propose une expérience pratique en manipulant différents appels système liés aux pseudo-terminaux.

## Prérequis

- Une distribution Linux
- LaTeX (pdftex & bibtex)
- GCC

## Utilisation

### Pour générer le PDF du rapport:
- Premiere lancer pdftex pour générer le pdf
```
pdftex Magomadov_PseudoTerminal.tex
```
- Ensuite lancer bibtex pour mettre à jour la bibliographie
```
bibtex Magomadov_PseudoTerminal.aux
```
- Et pour terminer, relancer pdftex pour inclure la bibliographie dans le pdf
```
pdftex Magomadov_PseudoTerminal.tex
```

### Pour compiler le Makefile
- Il faut se rendre dans le répertoire `codes` qui contient les codes pour la mise en pratique. Ensuite utiliser la commande `make`.
```
cd codes/
```
```
make
```

### Pour faire fonctionner l'automatisation (utiliser sudo)
- Il tout simplement lancer l'exécutable `run`, spécifier le chemin vers le pseudo-terminal esclave & fournis le type de d'option qu'on souhaite effectuer (input ou output)
```
sudo ./run /dev/pts/N input
```

```
sudo ./run /dev/pts/N output
```

# Auteurs
Oumar Magomadov (54516)
