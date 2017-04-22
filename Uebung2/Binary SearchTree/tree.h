#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

struct knoten
{
    int wert;                   // Daten
    struct knoten *links;       // Zeiger auf linken Teilbaum
    struct knoten *rechts;      // Zeiger auf rechten Teilbaum
};
typedef struct knoten KNOTEN;   // Alias f�r struct knoten -> KNOTEN


// 2. Interface (Zugriffsfunktionen) definieren

// Einf�gen
KNOTEN *einordnen(KNOTEN *, int);

// 3. Travesieren
void inorder_print(KNOTEN *);
void postorder_print(KNOTEN *);
void preorder_print(KNOTEN *);

// 4. Suchen
KNOTEN *suchen(KNOTEN *, int);


#endif // TREE_H_INCLUDED
