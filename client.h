#ifndef CLIENT_H
#define CLIENT_H

#include "iserializable.h"
#include "produit.h"

#include <string>
#include <vector>



/**
 * @brief Client est la classe représentant un client.
 * Elle implémente les fonctionnalités de ISerializable et ObjetMapped.
 */
class Client : public ISerializable {

private:
    /**
     * @brief identifiantClient : L'identifiant du client.
     */
    int identifiantClient;
    /**
     * @brief prenomClient : Le prénom du client.
     */
    std::string prenomClient;
    /**
     * @brief nomClient : Le nom du client.
     */
    std::string nomClient;
    /**
     * @brief listeProduitsSelectionnes : La liste des produits sélectionnés par le client.
     */
    std::vector<Produit*> listeProduitsSelectionnes;
    /**
     * @brief listeQuantitesProduitsSelectionnes : La liste des quantités des produits sélectionnés par le client.
     */
    std::vector<int> listeQuantitesProduitsSelectionnes;

    /**
     * @brief listeNomProduitsSelectionnes : La liste des noms des produits selectionnes par le client pour la sérialisation.
     */
    std::vector<std::string> listeNomProduitsSelectionnes;

public:
    /**
     * @brief Client : Constructeur sans paramètres.
     */
    Client();
    /**
     * @brief Client : Constructeur prenant en paramètre l'identifiant, le prenom et le nom du client.
     * @param identifiantClient : L'identifiant du client.
     * @param prenomClient : Le prénom du clent.
     * @param nomClient : Le nom du client.
     */
    Client(int identifiantClient, std::string prenomClient, std::string nomClient);
    /**
     * @brief ~Client : Destructeur sans paramètres.
     */
    ~Client() override;
    /**
     * @brief getIdentifiantClient : Retourner l'identifiant du client.
     * @return L'identifiant du client.
     */
    int getIdentifiantClient() const;
    /**
     * @brief setIdentifiantClient : Modifier l'identifiant du client.
     * @param identifiantClient : Le nouvel identifiant du client.
     */
    void setIdentifiantClient(int identifiantClient);
    /**
     * @brief getPrenomClient : Retourner le prénom du client.
     * @return Le prénom du client.
     */
    std::string getPrenomClient() const;
    /**
     * @brief setPrenomClient : Modifier le prénom du client.
     * @param prenomClient : Le nouveau prénom du client.
     */
    void setPrenomClient(std::string prenomClient);
    /**
     * @brief getNomClient : Retourner le nom du client.
     * @return Le nom du client.
     */
    std::string getNomClient() const;
    /**
     * @brief setNomClient : Modifier le nom du client.
     * @param prenomClient : Le nouveau nom du client.
     */
    void setNomClient(std::string nomClient);
    /**
     * @brief getListeProduitsSelectionnes : Retourner la liste des produits sélectionnés.
     * @return La liste des produits sélectionnés.
     */
    std::vector<Produit*> getListeProduitsSelectionnes() const;
    /**
     * @brief getListeQuantitesProduitsSelectionnes : Retourner la liste des quantités des produits sélectionnés.
     * @return La liste des quantités des produits sélectionnés.
     */
    std::vector<int> getListeQuantitesProduitsSelectionnes() const;
    /**
     * @brief getListeNomProduitsSelectionnes : Retourner la liste des noms des produits sélectionnés pour la sérialisation.
     * @return La liste des noms des produits sélectionnés pour la sérialization.
     */
    std::vector<std::string> getListeNomProduitsSelectionnes() const;

    /**
     * @brief ajouterProduitAuPanier : Ajouter le produit à la liste des produits sélectionnés.
     * @param produit Le produit à ajouter à la liste des produits sélectionnés.
     */
    void ajouterProduitAuPanier(Produit *produit);
    /**
     * @brief viderLePanier : Vider la liste des produits sélectionnés en les rendant de nouveau disponible..
     */
    void viderLePanier();
    /**
     * @brief validerLePanier : Vider la liste des produits sélectionnés.
     */
    void validerLePanier();
    /**
     * @brief modifierQuantiteProduitSelectionne : Modifier la quantité d'un produit séletictionné.
     * @param nomProduit : Le nom du produit sélectionné.
     * @param nombreDeProduits : Le nombre de produit sélectionnés qui doivent être dans la liste des produits sélectionnés.
     */
    void modifierQuantiteProduitSelectionne(std::string nomProduit, int nombreDeProduits);
    /**
     * @brief supprimerProduit : Supprimer le produit sélectionné par le nom.
     * @param nomProduit : Le nom du produit à supprimer de la liste des produit sélectionnés.
     */
    void supprimerProduit(std::string nomProduit);

    /**
     * @brief initialiserListeProduitSelectionnes : Modifier la liste des produits sélectionnés.
     * @param listeProduitsSelectionnes : La nouvelle liste des produits sélectionnés.
     */
    void initialiserListeProduitSelectionnes(std::vector<Produit*> listeProduitsSelectionnes);

    /**
     * @brief affichageCourt : Renvoyer une chaine de carctère représentant un client pour un affichage simplifié.
     * @return Une chaine de carctère représentant un client pour un affichage simplifié.
     */
    std::string affichageCourt() const;

    /**
     * @brief operator << : Surcharge de l'opérateur de flux de sortie.
     * @param out : Le flux de sortie.
     * @param client : Le client à afficher.
     * @return Le nouveau flux de sortie.
     */
    friend std::ostream& operator<< (std::ostream& out, const Client &client){
        out << client.affichageCourt() << std::endl;
        out << "La liste des produits du panier sont : " << std::endl;
        for (int i = 0; i < client.listeProduitsSelectionnes.size(); i++) {
            out << "Quantite : " << client.listeQuantitesProduitsSelectionnes.at(i) << " " << *client.listeProduitsSelectionnes.at(i);
        }
        return out;
    }

    // ISerializable interface
public:
    /**
     * @brief serializerObjet : Sérialiser le client.
     * @return  Le client sérialiser au format string.
     */
    virtual std::string serializerObjet() override;
    /**
     * @brief deserialiserObjet : Désérialiser le client.
     * @param objetSerialized : Le objectSerialized représente le client désérialisé.
     */
    virtual void deserialiserObjet(ObjetSerialized objetSerialized) override;

    // ObjetMapped interface
public:
    /**
     * @brief initialisertMapAttributsNomAttributs :  Initialiser la map qui fait la correspondance entre les noms des attributs et les noms des attributs sérialisés.
     */
    virtual void initialisertMapAttributsNomAttributs() override;

};

#endif // CLIENT_H
