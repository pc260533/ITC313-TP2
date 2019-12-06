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

    /* Question 3
    Magasin magasin;
    magasin.ajouterProduit(new Produit("NomProduit1", "DescriptionProduit1", 1, 1.0));
    magasin.ajouterProduit(new Produit("NomProduit2", "DescriptionProduit2", 2, 2.0));
    magasin.afficherListeProduits();
    magasin.mettreAJourQuantiteDisponibleProduitAvecNom("NomProduit1", 10);
    magasin.afficherProduitAvecNom("NomProduit1");
    */

    /* Question 4
    Client client(0, "Chassagne", "Pierre-Nicolas");
    Produit *produit1 = new Produit("NomProduit1", "DescriptionProduit1", 2, 1.0);
    Produit *produit2 = new Produit("NomProduit2", "DescriptionProduit2", 2, 2.0);
    client.ajouterProduitAuPanier(produit1);
    client.ajouterProduitAuPanier(produit2);
    std::cout << "Le client est : " << client << std::endl;
    client.modifierQuantiteProduitSelectionne("NomProduit1", 2);
    std::cout << "Le client est : " << client << std::endl;
    client.supprimerProduit("NomProduit2");
    std::cout << "Le client est : " << client << std::endl;
    client.viderLePanier();
    std::cout << "Le client est : " << client << std::endl;
    std::cout << "Le produit est : " << *produit1 << std::endl;
    std::cout << "Le produit est : " << *produit2 << std::endl;
    delete produit1;
    delete produit2;
    */

    /* Question 5
    Magasin magasin;
    magasin.ajouterProduit(new Produit("NomProduit1", "DescriptionProduit1", 2, 1.0));
    magasin.ajouterProduit(new Produit("NomProduit2", "DescriptionProduit2", 2, 2.0));
    magasin.ajouterClient("Chassagne", "Pierre-Nicolas");
    magasin.ajouterClient("Forgeron", "Nicolas");
    magasin.afficherListeClients();
    magasin.afficherClient("Chassagne");
    magasin.afficherClient(1);
    magasin.ajouterProduitDansPanierClient("NomProduit1", "Chassagne");
    magasin.ajouterProduitDansPanierClient("NomProduit2", "Chassagne");
    magasin.supprimerProduitDansPanierClient("NomProduit2", "Chassagne");
    magasin.modifierQuantiteProduitDansPanierClient("NomProduit1", 2, "Chassagne");
    magasin.afficherListeProduits();
    */

    /* Question 6
    Client client(0, "Chassagne", "Pierre-Nicolas");
    Produit *produit1 = new Produit("NomProduit1", "DescriptionProduit1", 2, 1.0);
    Produit *produit2 = new Produit("NomProduit2", "DescriptionProduit2", 2, 2.0);
    client.ajouterProduitAuPanier(produit1);
    client.ajouterProduitAuPanier(produit2);
    Commande commande(&client, client.getListeProduitsSelectionnes());
    std::cout << "La commande est : " << commande << std::endl;
    delete produit1;
    delete produit2;
    */

    /* Question 7
    Magasin magasin;
    magasin.ajouterProduit(new Produit("NomProduit1", "DescriptionProduit1", 2, 1.0));
    magasin.ajouterProduit(new Produit("NomProduit2", "DescriptionProduit2", 2, 2.0));
    magasin.ajouterClient("Chassagne", "Pierre-Nicolas");
    magasin.ajouterClient("Forgeron", "Nicolas");
    magasin.ajouterProduitDansPanierClient("NomProduit1", "Chassagne");
    magasin.ajouterProduitDansPanierClient("NomProduit2", "Chassagne");
    magasin.supprimerProduitDansPanierClient("NomProduit2", "Chassagne");
    magasin.modifierQuantiteProduitDansPanierClient("NomProduit1", 2, "Chassagne");
    magasin.validerCommandeDUnClient("Chassagne");
    magasin.afficherListeCommandes();
    magasin.ajouterProduitDansPanierClient("NomProduit2", "Forgeron");
    magasin.validerCommandeDUnClient("Forgeron");
    magasin.afficherCommandeAvecNom("Forgeron");
    magasin.afficherListeProduits();
    */

    /* Question 8 */


    return 0;
}
