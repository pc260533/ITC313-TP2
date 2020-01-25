#include <iostream>

#include "magasin.h"
#include "produit.h"
#include "client.h"
#include "commande.h"
#include "serializer.h"
#include "exceptionentreeincorrecte.h"
#include "exceptionserialization.h"
#include "exceptionfichiersauvegarde.h"

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
    magasin.ajouterProduit("NomProduit1", "DescriptionProduit1", 1, 1.0);
    magasin.ajouterProduit("NomProduit2", "DescriptionProduit2", 2, 2.0);
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
    magasin.ajouterProduit("NomProduit1", "DescriptionProduit1", 2, 1.0);
    magasin.ajouterProduit("NomProduit2", "DescriptionProduit2", 2, 2.0);
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
    magasin.ajouterProduit("NomProduit1", "DescriptionProduit1", 2, 1.0);
    magasin.ajouterProduit("NomProduit2", "DescriptionProduit2", 2, 2.0);
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
    Magasin *magasin = new Magasin();
    Serializer serializer;
    std::string cheminFichierSauvegarde = "sauvegardeMagasin.txt";
    bool quit = false;
    std::string choixMenu = "";
    std::regex regexIntegerPositif("[[:digit:]]+");
    std::regex regexDoublePositif("([[:digit:]]+)(\\.(([[:digit:]]+)?))?");
    while (!quit) {
        try {
            choixMenu = "";
            std::cout << "Taper 0 pour afficher la gestion des produits." << std::endl;
            std::cout << "Taper 1 pour afficher la gestion des clients." << std::endl;
            std::cout << "Taper 2 pour afficher la getion des commandes." << std::endl;
            std::cout << "Taper 3 pour afficher la gestion du magasin." << std::endl;
            std::cout << "Taper 4 pour sauvegarder le magasin." << std::endl;
            std::cout << "Taper 5 pour charger une sauvegarde de magasin." << std::endl;
            std::cout << "Taper q pour quitter." << std::endl;
            std::cin >> choixMenu;
            if (choixMenu == "q") {
                quit = true;
            }
            else if (choixMenu == "0") {
                std::string choixMenuGestionProduits = "";
                std::cout << "Taper 0 pour ajouter un produit." << std::endl;
                std::cout << "Taper 1 pour afficher tous les produits." << std::endl;
                std::cout << "Taper 2 pour afficher un produit avec son nom." << std::endl;
                std::cout << "Taper 3 pour mettre a jour la quantite disponible d'un produit avec le nom." << std::endl;
                std::cin >> choixMenuGestionProduits;
                if (choixMenuGestionProduits == "0") {
                    std::string titreProduit = "";
                    std::string descriptionProduit = "";
                    std::string quantiteDisponibleProduit = "";
                    int quantiteDisponibleProduitInt = 0;
                    std::string prixUnitaireProduit = "";
                    double prixUnitaireProduitDouble = 0.0;
                    std::cout << "Entrer le titre du produit :" << std::endl;
                    std::cin >> titreProduit;
                    std::cout << "Entrer la description du produit :" << std::endl;
                    std::cin >> descriptionProduit;
                    std::cout << "Entrer la quantite disponible du produit :" << std::endl;

                    std::cin >> quantiteDisponibleProduit;
                    try {
                        quantiteDisponibleProduitInt = std::stoi(quantiteDisponibleProduit);
                    }
                    catch (std::exception &exception) {
                        throw ExceptionEntreeIncorrecte();
                    }

                    std::cout << "Entrer le prix unitaire du produit :" << std::endl;
                    std::cin >> prixUnitaireProduit;
                    try {
                        prixUnitaireProduitDouble = std::stod(prixUnitaireProduit);
                    }
                    catch (std::exception &exception) {
                        throw ExceptionEntreeIncorrecte();
                    }

                    magasin->ajouterProduit(titreProduit, descriptionProduit, quantiteDisponibleProduitInt, prixUnitaireProduitDouble);
                }
                else if (choixMenuGestionProduits == "1") {
                    magasin->afficherListeProduits();
                }
                else if (choixMenuGestionProduits == "2") {
                    std::string titreProduit = "";
                    std::cout << "Entrer le titre du produit :" << std::endl;
                    std::cin >> titreProduit;
                    magasin->afficherProduitAvecNom(titreProduit);
                }
                else if (choixMenuGestionProduits == "3") {
                    std::string titreProduit = "";
                    std::string nouvelleQuantiteProduit;
                    int nouvelleQuantiteProduitInt = 0;
                    std::cout << "Entrer le titre du produit :" << std::endl;
                    std::cin >> titreProduit;
                    std::cout << "Entrer la nouvelle quantite du produit :" << std::endl;
                    std::cin >> nouvelleQuantiteProduit;
                    try {
                        nouvelleQuantiteProduitInt = std::stoi(nouvelleQuantiteProduit);
                    }
                    catch (std::exception &exception) {
                        throw ExceptionEntreeIncorrecte();
                    }
                    magasin->mettreAJourQuantiteDisponibleProduitAvecNom(titreProduit, nouvelleQuantiteProduitInt);
                }
            }
            else if (choixMenu == "1") {
                std::string choixMenuGestionClients = "";
                std::cout << "Taper 0 pour ajouter un client." << std::endl;
                std::cout << "Taper 1 pour afficher tous les clients." << std::endl;
                std::cout << "Taper 2 pour afficher un client avec son nom." << std::endl;
                std::cout << "Taper 3 pour afficher un client avec son identifiant." << std::endl;
                std::cin >> choixMenuGestionClients;
                if (choixMenuGestionClients == "0") {
                    std::string nomClient = "";
                    std::string prenomClient = "";
                    std::cout << "Entrer le nom du client :" << std::endl;
                    std::cin >> nomClient;
                    std::cout << "Entrer la prenom du client :" << std::endl;
                    std::cin >> prenomClient;
                    magasin->ajouterClient(nomClient, prenomClient);
                }
                else if (choixMenuGestionClients == "1") {
                    magasin->afficherListeClients();
                }
                else if (choixMenuGestionClients == "2") {
                    std::string nomClient = "";
                    std::cout << "Entrer le nom du client :" << std::endl;
                    std::cin >> nomClient;
                    magasin->afficherClient(nomClient);
                }
                else if (choixMenuGestionClients == "3") {
                    std::string identifiantClient = "";
                    int identifiantClientInt = 0;
                    std::cout << "Entrer l'identifiant du client :" << std::endl;
                    std::cin >> identifiantClient;
                    try {
                        identifiantClientInt = std::stoi(identifiantClient);
                    }
                    catch (std::exception &exception) {
                        throw ExceptionEntreeIncorrecte();
                    }
                    magasin->afficherClient(identifiantClientInt);
                }
            }
            else if (choixMenu == "2") {
                std::string choixMenuGestionCommandes = "";
                std::cout << "Taper 0 pour valider la commande d'un client." << std::endl;
                std::cout << "Taper 1 pour changer le statut d'une commande." << std::endl;
                std::cout << "Taper 2 pour afficher toutes les commandes." << std::endl;
                std::cout << "Taper 3 pour afficher les commandes d'un clients." << std::endl;
                std::cin >> choixMenuGestionCommandes;
                if (choixMenuGestionCommandes == "0") {
                    std::string nomClient = "";
                    std::cout << "Entrer le nom du client :" << std::endl;
                    std::cin >> nomClient;
                    magasin->validerCommandeDUnClient(nomClient);
                }
                else if (choixMenuGestionCommandes == "1") {
                    std::string identifiantClient = "";
                    int identifiantClientInt = 0;
                    std::cout << "Entrer l'identifiant du client :" << std::endl;
                    std::cin >> identifiantClient;
                    try {
                        identifiantClientInt = std::stoi(identifiantClient);
                    }
                    catch (std::exception &exception) {
                        throw ExceptionEntreeIncorrecte();
                    }
                    magasin->mettreAJourStatutCommande(identifiantClientInt);
                }
                else if (choixMenuGestionCommandes == "2") {
                    magasin->afficherListeCommandes();
                }
                else if (choixMenuGestionCommandes == "3") {
                    std::string nomClient = "";
                    std::cout << "Entrer le nom du client :" << std::endl;
                    std::cin >> nomClient;
                    magasin->afficherCommandeAvecNom(nomClient);
                }
            }
            else if (choixMenu == "3") {
                std::string choixMenuGestionMagasin = "";
                std::cout << "Taper 0 pour ajouter un produit dans le panier d'un client." << std::endl;
                std::cout << "Taper 1 pour supprimer un produit dans le panier d'un client." << std::endl;
                std::cout << "Taper 2 pour modifier la quantite d'un produit selectionne dans le panier d'u client." << std::endl;
                std::cin >> choixMenuGestionMagasin;
                if (choixMenuGestionMagasin == "0") {
                    std::string nomProduit = "";
                    std::string nomClient = "";
                    std::cout << "Entrer le nom du produit :" << std::endl;
                    std::cin >> nomProduit;
                    std::cout << "Entrer le nom du client :" << std::endl;
                    std::cin >> nomClient;
                    magasin->ajouterProduitDansPanierClient(nomProduit, nomClient);
                }
                else if (choixMenuGestionMagasin == "1") {
                    std::string nomProduit = "";
                    std::string nomClient = "";
                    std::cout << "Entrer le nom du produit :" << std::endl;
                    std::cin >> nomProduit;
                    std::cout << "Entrer le nom du client :" << std::endl;
                    std::cin >> nomClient;
                    magasin->supprimerProduitDansPanierClient(nomProduit, nomClient);
                }
                else if (choixMenuGestionMagasin == "2") {
                    std::string nomProduit = "";
                    std::string nomClient = "";
                    std::string nouvelleQuantiteProduit;
                    int nouvelleQuantiteProduitInt = 0;
                    std::cout << "Entrer le nom du produit :" << std::endl;
                    std::cin >> nomProduit;
                    std::cout << "Entrer la nouvelle quantité du produit " << nomProduit << " à ajouter dans le panier du client.";
                    std::cin >> nouvelleQuantiteProduit;
                    try {
                        nouvelleQuantiteProduitInt = std::stoi(nouvelleQuantiteProduit);
                    }
                    catch (std::exception &exception) {
                        throw ExceptionEntreeIncorrecte();
                    }
                    std::cout << "Entrer le nom du client :" << std::endl;
                    std::cin >> nomClient;
                    magasin->modifierQuantiteProduitDansPanierClient(nomProduit, nouvelleQuantiteProduitInt, nomClient);
                }
            }
            else if (choixMenu == "4") {
                std::string magasinSerialise = "";
                magasinSerialise = serializer.serializeObjetISerializable(magasin);
                std::ofstream magasinSerialiseOffStream(cheminFichierSauvegarde);
                magasinSerialiseOffStream << magasinSerialise;
                magasinSerialiseOffStream.close();
            }
            else if (choixMenu == "5") {
                delete magasin;
                magasin = new Magasin();
                std::string magasinDeserialise = "";
                std::string ligne = "";
                std::ifstream magasinDeserialiseOffStream(cheminFichierSauvegarde);
                if (magasinDeserialiseOffStream) {
                    std::getline(magasinDeserialiseOffStream, ligne);
                    magasinDeserialise += ligne + "\n";
                    while (!magasinDeserialiseOffStream.eof()) {
                        std::getline(magasinDeserialiseOffStream, ligne);
                        magasinDeserialise += ligne + "\n";
                    }
                }
                else {
                    std::ofstream magasinSerialiseOffStream(cheminFichierSauvegarde);
                    magasinSerialiseOffStream.close();
                    throw ExceptionFichierSauvegarde();
                }
                magasinDeserialise.pop_back();
                magasinDeserialiseOffStream.close();
                serializer.deserializeObjetISerializable(magasinDeserialise, magasin);
            }
            std::cout << std::endl;
        }
        catch (ExceptionEntreeIncorrecte &exceptionEntreeIncorrecte) {
            std::cout << exceptionEntreeIncorrecte.what() << std::endl;
        }
        catch (ExceptionSerialization &exceptionSerialization) {
            std::cout << exceptionSerialization.what();
            if (choixMenu == "4") {
                std::cout << " : la sauvegarde du magasin n'a pas pu etre effectuee.";
            }
            else if (choixMenu == "5") {
                delete magasin;
                magasin = new Magasin();
                std::cout << " : le chargement de la sauvegarde magasin n'a pas pu etre effectue.";
            }
            std::cout << std::endl;
        }
        catch (ExceptionFichierSauvegarde &exceptionFichierSauvegarde) {
            std::cout << exceptionFichierSauvegarde.what();
            if (choixMenu == "4") {
                std::cout << " : le fichier de sauvegarde est inaccessible en ecriture.";
            }
            else if (choixMenu == "5") {
                delete magasin;
                magasin = new Magasin();
                std::cout << " : le fichier de sauvegarde est inaccessible en lecture." << std::endl;
                std::cout << "Si le fichier n'existait pas, il a ete cree.";
            }
            std::cout << std::endl;
        }
        catch (std::exception &exception) {
            std::cout << exception.what() << std::endl;
            std::cin.clear();
        }
    }
    delete magasin;
    return 0;
}
