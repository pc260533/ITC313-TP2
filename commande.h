#ifndef COMMANDE_H
#define COMMANDE_H

#include "client.h"
#include "produit.h"

#include <string>
#include <vector>



/**
 * @brief Commande est la classe représentant une commande d'un client.
 * Elle implémente les fonctionnalités de ISerializable et ObjetMapped.
 */
class Commande : public ISerializable {

private:
    /**
     * @brief identifiantCommande : L'identifiant de la commande.
     */
    int identifiantCommande;
    /**
     * @brief clientCommande : Le client de la commande.
     */
    Client *clientCommande;
    /**
     * @brief listeProduitsCommandes : la liste des produits commandés par le client.
     */
    std::vector<Produit*> listeProduitsCommandes;
    /**
     * @brief listeQuantitesProduitsCommandes : la liste des quantités des produits commandés par le client.
     */
    std::vector<int> listeQuantitesProduitsCommandes;
    /**
     * @brief statutLivreeCommande : Le statut de la commande : livrée ou non livrée.
     */
    bool statutLivreeCommande;

    /**
     * @brief nomClient Le nom du client de la commande pour la sérialisation.
     */
    std::string nomClient;
    /**
     * @brief prenomClient Le prenom du client de la commande pour la sérialisation.
     */
    std::string prenomClient;
    /**
     * @brief listeNomProduitsCommandes : La liste des noms des produits commandés pour la sérialisation.
     */
    std::vector<std::string> listeNomProduitsCommandes;

public:
    /**
     * @brief Commande : Constructeur sans paramètres.
     */
    Commande();
    /**
     * @brief Commande : Constructeur prenant en paramètre l'identidiant, le client, la liste des produits commandés et la listes des quantités des produits commandés de la commande.
     * @param identifiantCommande
     * @param client
     * @param listeProduitsCommandes
     * @param listeQuantitesProduitsCommandes
     */
    Commande(int identifiantCommande, Client* client, std::vector<Produit*> listeProduitsCommandes, std::vector<int> listeQuantitesProduitsCommandes);
    /**
     * @brief ~Commande : Destructeur sans paramètres.
     */
    ~Commande() override;
    /**
     * @brief getIdentifiantCommande : Retourner l'identifiant de la commande.
     * @return L'identifiant de la commande.
     */
    int getIdentifiantCommande() const;
    /**
     * @brief setIdentifiantCommande : Modifier l'identifiant de la commande.
     * @param identifiantCommande Le nouvel l'identifiant de la commande.
     */
    void setIdentifiantCommande(int identifiantCommande);
    /**
     * @brief getClientCommande : Retourner le client de la commande.
     * @return Le client de la commande.
     */
    Client* getClientCommande() const;
    /**
     * @brief setClientCommande : Modifier le client de la commande.
     * @param clientCommande : Le nouveau client de la commande.
     */
    void setClientCommande(Client *clientCommande);
    /**
     * @brief getListeProduitsCommandes : Retourner la liste des produits commandés.
     * @return La liste des produits commandés.
     */
    std::vector<Produit*> getListeProduitsCommandes() const;
    /**
     * @brief getListeQuantitesProduitsCommandes : Retourner la liste des quantités des produits commandés.
     * @return La liste des quantités des produits commandés.
     */
    std::vector<int> getListeQuantitesProduitsCommandes() const;
    /**
     * @brief setListeProduitsCommandes : Modifier la liste des produits commandés.
     * @param listeProduitsCommandes : La liste des produits commandés.
     */
    void setListeProduitsCommandes(std::vector<Produit*> listeProduitsCommandes);
    /**
     * @brief getStatutLivreeCommande : Retourner le statut de la commande.
     * @return Le statut de la commande.
     */
    bool getStatutLivreeCommande() const;
    /**
     * @brief setStatutLivreeCommande : Modifier le statut de la commande.
     * @param statutLivreeCommande : Le nouveau statut de la commande.
     */
    void setStatutLivreeCommande(bool statutLivreeCommande);
    /**
     * @brief getListeNomProduitsCommandes : Retourner la liste des noms des produits commandés pour la sérialisation.
     * @return La liste des noms des produits commandés pour la sérialisation.
     */
    std::vector<std::string> getListeNomProduitsCommandes() const;
    /**
     * @brief getNomClient : Retourner le nom du client de la commande pour la sérialisation.
     * @return Le nom du client de la commande pour la sérialisation.
     */
    std::string getNomClient() const;
    /**
     * @brief getPrenomClient : Retourner le prénom du client de la commande pour la sérialisation.
     * @return Le prénom du client de la commande pour la sérialisation.
     */
    std::string getPrenomClient() const;

    /**
     * @brief initialiserClient : Modifier le client de la commande.
     * @param clientCommande : Le nouveau client de la commande.
     */
    void initialiserClient(Client *clientCommande);
    /**
     * @brief initialiserListeProduitsCommandes : Modifier la liste des produits commandés.
     * @param listeProduitsCommandes : La nouvelle liste des produits commandés.
     */
    void initialiserListeProduitsCommandes(std::vector<Produit*> listeProduitsCommandes);

    /**
     * @brief operator << : Surcharge de l'opérateur de flux de sortie.
     * @param out : Le flux de sortie.
     * @param commande : La commande à afficher.
     * @return Le nouveau flux de sortie.
     */
    friend std::ostream& operator<< (std::ostream& out, const Commande &commande){
        out << "Le client de la commande est : "  << std::endl << commande.getClientCommande()->affichageCourt() << std::endl;
        std::string statutLivreeCommande = "non livree";
        if (commande.getStatutLivreeCommande()) {
            statutLivreeCommande = "livree";
        }
        out << "La statut de la commande est : " << statutLivreeCommande << "." << std::endl;
        out << "La liste des produits de la commande sont : " << std::endl;
        for (int i = 0; i < commande.getListeProduitsCommandes().size(); i++) {
            out << "Quantite : " << commande.getListeQuantitesProduitsCommandes().at(i) << " " << *commande.getListeProduitsCommandes().at(i);
        }
        return out;
    }

    // ISerializable interface
public:
    /**
     * @brief serializerObjet : Sérialiser la commande.
     * @return  La commande sérialiser au format string.
     */
    virtual std::string serializerObjet() override;
    /**
     * @brief deserialiserObjet : Désérialiser la commande.
     * @param objetSerialized : Le objectSerialized représente la commande désérialisée.
     */
    virtual void deserialiserObjet(ObjetSerialized objetSerialized) override;


    // ObjetMapped interface
public:
    /**
     * @brief initialisertMapAttributsNomAttributs :  Initialiser la map qui fait la correspondance entre les noms des attributs et les noms des attributs sérialisés.
     */
    virtual void initialisertMapAttributsNomAttributs() override;

};

#endif // COMMANDE_H
