#ifndef OBJETMAPPED_H
#define OBJETMAPPED_H

#include <string>
#include <map>



/**
 * @brief ObjetMapped est la classe représentan en objet dont les attributs sont mappés.
 */
class ObjetMapped {

private:
    /**
     * @brief mapAttributsNomAttributs : La map des attributs avec le nom des attributs mappés
     */
    std::map<std::string, std::string> mapAttributsNomAttributs;

public:
    /**
     * @brief ObjetMapped : Constructeur sans paramètres.
     */
    ObjetMapped();
    /**
     * @brief ~ObjetMapped : Destructeur sans paramètres.
     */
    virtual ~ObjetMapped();

    /**
     * @brief getMapAttributsNomAttributs : Retourner la map des attributs avec le nom des attributs mappés
     * @return
     */
    std::map<std::string, std::string> getMapAttributsNomAttributs();
    /**
     * @brief ajouterEntreeMapAttributsNomAttributs : Ajouter une entrée dans la map des attributs avec le nom des attributs mappés
     * @param attribut : L'attribut.
     * @param nomAttribut : Le nom de l'attribut mappé.
     */
    void ajouterEntreeMapAttributsNomAttributs(std::string attribut, std::string nomAttribut);

    /**
     * @brief initialisertMapAttributsNomAttributs :  Initialiser la map qui fait la correspondance entre les noms des attributs et les noms des attributs mappés.
     */
    virtual void initialisertMapAttributsNomAttributs() = 0;

};

#endif // OBJETMAPPED_H
