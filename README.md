
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

La classe Point2D représente un point dans le plan cartésien défini par deux coordonnées x et y. Elle fournit les opérations élémentaires pour accéder et modifier ces coordonnées, ainsi qu’une translation du point. Cette classe sert de brique de base pour la définition des sommets des polygones et supporte l’affichage via la surcharge de l’opérateur <<.

#### code
```cpp
pas de test necessaire
```

#### Tests

pas de test necessaire

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

La classe Parcelle modélise une unité foncière du cadastre. Chaque parcelle possède un numéro, un propriétaire, une forme géométrique décrite par un Polygone<int>, une surface calculée automatiquement, un pourcentage constructible et un type. C’est une classe abstraite, car elle impose l’implémentation de la méthode setType() par ses sous-classes. Elle assure la validation des données (surface strictement positive) et permet l’affichage détaillé des informations d’une parcelle

#### code
```cpp
pas de test possible
```

#### Tests

pas de test possible

---

### Classe Constructible

La classe abstraite Constructible représente une parcelle sur laquelle une construction est possible. Elle ajoute une méthode virtuelle pure surfaceConstructible() que les classes dérivées doivent implémenter afin de calculer la surface effectivement constructible selon les règles du PLU.

#### Description

#### code
```cpp
pas de test possible
```

#### Tests

pas de test possible

---

### Classe zu

#### Description

La classe ZU décrit une parcelle en zone urbaine. Elle est constructible et possède en plus une surface déjà construite. Sa méthode surfaceConstructible() renvoie la surface encore disponible pour la construction, en tenant compte du pourcentage constructible et de la surface déjà bâtie. L’affichage mentionne explicitement qu’il s’agit d’une ZU.

#### code
```cpp
--------------------
Test de la classe ZU
--------------------
Parcelle n°43 :
    Type : ZU
    Polygone : [10;10] [14;10] [14;13] [10;13]
    Propriétaire : Robert
    Surface : 12 m²
    % constructible : 15 %
    Surface construite : 0.448686 m2
    Surface a construire restante : 1.35131 m2
```

#### Tests

Ce test vérifie le bon fonctionnement d’une parcelle de type ZU (Zone Urbaine), notamment la gestion de sa surface construite et de sa surface constructible restante.
Une parcelle n°43 est créée avec un polygone rectangulaire simple, permettant de valider le calcul automatique de la surface (12 m²). Le pourcentage constructible fixé à 15 % est appliqué pour déterminer la surface maximale autorisée.
On attribue ensuite une surface déjà construite (0,448686 m²), puis le test affiche la surface encore disponible pour la construction.
L’ensemble permet de confirmer :
- le calcul correct de la surface géométrique,
- la prise en compte du pourcentage constructible,
- le calcul de la surface restante disponible,
- l’affichage complet et cohérent des informations propres à une ZU.

---

### Classe zau

#### Description

La classe ZAU représente une zone à urbaniser. Elle est également constructible mais ne possède pas de surface construite initiale. La surface constructible correspond à la proportion autorisée par le PLU appliquée à la surface totale. L’affichage la distingue clairement comme ZAU.

#### code
```cpp
--------------------
Test de la classe ZAU
--------------------
Parcelle n°14 :
    Type : ZAU
    Polygone : [0;0] [4;0] [4;3]
    Propriétaire : Alice
    Surface : 6 m²
    % constructible : 11 %
```

#### Tests

Ce test valide le comportement d’une parcelle de type ZAU (Zone à Urbaniser), dont la surface constructible correspond uniquement au pourcentage autorisé, puisqu’aucune surface n’est déjà bâtie dans ce type de zone.
La parcelle n°14 est définie à partir d’un polygone triangulaire simple, ce qui permet de vérifier correctement le calcul automatique de la surface (6 m²).
Le pourcentage constructible fixé à 11 % est ensuite appliqué pour déduire la surface totale disponible pour la future urbanisation.
Le test permet ainsi de confirmer :
- le calcul correct de la surface géométrique,
- la prise en compte du pourcentage constructible propre aux ZAU,
- l’affichage cohérent des informations spécifiques au type ZAU.

---

### Classe zn

#### Description

La classe ZN représente une zone naturelle ou forestière. Elle n’est pas constructible. L’affichage indique explicitement son statut de zone non constructible.

#### code
```cpp
--------------------
Test de la classe ZN
--------------------
Parcelle n°67 :
    Type : ZN
    Polygone : [20;20] [29;20] [29;33]
    Propriétaire : Jean
    Surface : 58 m²
```

#### Tests

Ce test vérifie le comportement d’une parcelle de type ZN (Zone Naturelle), zone dans laquelle aucune construction n’est autorisée.
La parcelle n°67 est définie à partir d’un polygone rectangulaire, permettant de valider le calcul automatique de la surface (58 m²).
L’objectif du test est principalement de s’assurer que :
- la surface est correctement calculée à partir des sommets fournis,
- le type ZN est correctement identifié et affiché,
- aucune information relative à la constructibilité n’apparaît, conformément au statut non constructible des ZN.
- Ce test confirme ainsi le comportement attendu d’une parcelle naturelle dans le cadre du PLU.

---

### Classe za

#### Description

La classe ZA décrit une zone agricole, dérivant d’une ZN mais avec un type de culture associé. Elle n'est généralement pas constructible, sauf pour des bâtiments agricoles sous contraintes strictes (≤10 % de la surface et ≤200 m²). La méthode surfaceConstructible() applique ces règles spécifiques. L’affichage inclut le type de culture.

#### code
```cpp
--------------------
Test de la classe ZA
--------------------
Parcelle n°92 :
    Type : ZA
    Polygone : [40;40] [50;40] [50;55]
    Propriétaire : Marie
    Surface : 75 m²
    Type de culture : Céréales
```

#### Tests

Ce test évalue le fonctionnement d’une parcelle de type ZA (Zone Agricole), caractérisée par l’ajout d’un type de culture et par un régime spécifique de constructibilité très limité.
La parcelle n°92 est définie à partir d’un polygone rectangulaire afin de valider le calcul automatique de la surface (75 m²). Le test vérifie également la bonne prise en compte de l’attribut supplémentaire propre aux ZA : ici, la culture déclarée est Céréales.
L’objectif est de confirmer que :
- la surface est correctement calculée,
- le type ZA est identifié et affiché correctement,
- les informations agricoles spécifiques sont bien intégrées,
- aucune surface constructible n’est indiquée (sauf règles particulières pour bâtiments agricoles, non sollicitées dans ce test).
- Ce test assure ainsi la conformité de l’implémentation d’une zone agricole dans le PLU.

---

### Classe carte

#### Description

La classe Carte regroupe un ensemble de parcelles et gère la surface totale représentée. Elle permet de construire une carte à partir d’un fichier de description, en interprétant automatiquement les différents types de parcelles. Elle offre également la fonctionnalité de sauvegarde dans un fichier au même format. Cette classe constitue le niveau global d’organisation du cadastre.

#### code
```cpp

```

#### Tests

---

