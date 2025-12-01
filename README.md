
# TP4 - TP PLU noté

SEC 2

- Eloi Tourangin - <eloi.tourangin@eleves.ec-nantes.fr>
- Lucas Oros - <lucas.oros@eleves.ec-nantes.fr>
- Djamael Lahamion - <djamael.lahamion@eleves.ec-nantes.fr>
- Aloïs Guillon - <alois.guillon@eleves.ec-nantes.fr>

## Table des matières

1. [Compilation et Exécution](#compilation-et-exécution)
2. [Diagramme des classes](#diagramme-des-classes)
3. [Description des classes](#description-des-classes)

---

## Compilation et Exécution

### Méthode 1 : Utiliser make
```bash
# Compiler
make

# Exécuter
./build/main.out
```

### Méthode 2 : Utiliser le script bash
```bash
./build_and_execute.sh
```

---

## Diagramme des classes
![Diagramme des classes](diagramme_classes.png)

## Description des classes

### Classe Point2D

#### Description

texteici

#### code
```cpp

```

#### Tests

texte ici

---

### Classe Polygone

#### Description

La classe Polygone représente une figure géométrique définie par une série de sommets dans un espace bidimensionnel. Chaque sommet est représenté par un objet de la classe point2d, qui stocke les coordonnées x et y du point. La classe Polygone permet de créer des polygones en fournissant une liste de sommets, de copier des polygones existants, de manipuler les sommets du polygone et de calculer la surface d'un polygone. Elle offre des méthodes pour obtenir et définir la liste des sommets, ajouter de nouveaux sommets, et effectuer des translations sur l'ensemble du polygone en déplaçant tous ses sommets d'un certain décalage en x et y.


#### code
```cpp
-----------------------------------
TP PLU - Test de la classe Polygone
-----------------------------------
Sommets du polygone initial : [0;0] [1;0] [1;1]
Sommets du polygone copie : [0;0] [1;0] [1;1]
Sommets du polygone copie apres translation de (2.0, 3.0) : [2;3] [3;3] [3;4]
Verification que le polygone original na pas ete modifie : [0;0] [1;0] [1;1]

Calcul de la surface du polygone 5 sommets (attendu: 0.75) :
Sommets du polygone  : [0;0] [1;0] [1;1] [0;1] [0.5;1.5]
Surface du polygone : 0.75
```

#### Tests

Dans ce test, nous créons un polygone en utilisant une liste de sommets définis par des objets point2d. Nous affichons les sommets du polygone initial, puis nous créons une copie du polygone en utilisant le constructeur de recopie. Nous affichons les sommets du polygone copié pour vérifier qu'ils correspondent à ceux de l'original. Ensuite, nous appliquons une translation au polygone copié et affichons ses nouveaux sommets pour confirmer que la translation a été effectuée correctement. Enfin, nous vérifions que le polygone original n'a pas été modifié après la translation du polygone copié, assurant ainsi l'intégrité des données. Nous terminons par calculer la surface d'un polygone avec 5 sommets.


### Classe Parcelle

#### Description

#### code
```cpp

```

#### Tests

---

### Classe Constructible

#### Description

#### code
```cpp

```

#### Tests

---

### Classe zu

#### Description

#### code
```cpp

```

#### Tests

---

### Classe zau

#### Description

#### code
```cpp

```

#### Tests

---

### Classe zn

#### Description

#### code
```cpp

```

#### Tests

---

### Classe za

#### Description

#### code
```cpp

```

#### Tests

---

### Classe carte

#### Description

#### code
```cpp

```

#### Tests

---

