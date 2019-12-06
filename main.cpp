#include <iostream>

#include "magasin.h"
#include "produit.h"

using namespace std;

int main() {
    /* Partie 1 Question 1
    Magasin magasin;
    */

    /* Question 2
    Produit produit("NomProduit", "DescriptionProduit", 2, 1.0);
    std::cout << "Le produit est : " << produit << std::endl;
    */

    /* Question 3 */
    Magasin magasin;
    magasin.ajouterProduit(new Produit("NomProduit1", "DescriptionProduit1", 1, 1.0));
    magasin.ajouterProduit(new Produit("NomProduit2", "DescriptionProduit2", 2, 2.0));
    magasin.afficherListeProduits();
    magasin.mettreAJourQuantiteDisponibleProduitAvecNom("NomProduit1", 10);
    magasin.affcherProduitAvecNom("NomProduit1");



    return 0;
}
