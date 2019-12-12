#ifndef CLIENT_H
#define CLIENT_H

#include "iserializable.h"
#include "produit.h"

#include <string>
#include <vector>



class Client : public ISerializable {

private:
    int identifiantClient;
    std::string prenomClient;
    std::string nomClient;
    std::vector<Produit*> listeProduitsSelectionnes;
    std::vector<int> listeQuantitesProduitsSelectionnes;

    std::vector<std::string> listeNomProduitsSelectionnes;

public:
    Client();
    Client(int identifiantClient, std::string prenomClient, std::string nomClient);
    ~Client();
    int getIdentifiantClient() const;
    void setIdentifiantClient(int identifiantClient);
    std::string getPrenomClient() const;
    void setPrenomClient(std::string prenomClient);
    std::string getNomClient() const;
    void setNomClient(std::string prenomClient);
    std::vector<Produit*> getListeProduitsSelectionnes() const;
    std::vector<int> getListeQuantitesProduitsSelectionnes() const;
    std::vector<std::string> getListeNomProduitsSelectionnes() const;

    void ajouterProduitAuPanier(Produit *produit);
    void viderLePanier();
    void validerLePanier();
    void modifierQuantiteProduitSelectionne(std::string nomProduit, int nombreDeProduits);
    void supprimerProduit(std::string nomProduit);

    void initialiserListeProduitSelectionnes(std::vector<Produit*> listeProduitsSelectionnes);

    friend std::ostream& operator<< (std::ostream& out, const Client &client){
        out << "Identifiant Client : " << std::to_string(client.getIdentifiantClient()) << " Prenom : " << client.getPrenomClient() << " Nom : " << client.getNomClient() << std::endl;
        out << "La liste des produits du panier sont : " << std::endl;
        for (int i = 0; i < client.listeProduitsSelectionnes.size(); i++) {
            out << "Quantite : " << client.listeQuantitesProduitsSelectionnes.at(i) << " " << *client.listeProduitsSelectionnes.at(i);
        }
        return out;
    }

    // ISerializable interface
public:
    void setValeurAttribut(std::string nomAttribut, std::string valeurAttribut) override;
    std::string serializerObjet() override;
    void deserialiserObjet(ObjetSerialized objetSerialized) override;
    std::map<std::string, std::string> getMapAttributsNomAttributs() override;

};

#endif // CLIENT_H
