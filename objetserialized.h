#ifndef OBJETSERIALIZED_H
#define OBJETSERIALIZED_H

#include <string>
#include <vector>
#include <map>
#include <vector>
#include <iostream>
#include <bits/stdc++.h>



/**
 * @brief ObjetSerialized est la classe représentant un objet sérialisé.
 */
class ObjetSerialized {

private:
    /**
     * @brief objetString : La chaine de caractères qui représente l'objet sérialisé.
     */
    std::string objetString;
    /**
     * @brief mapNomAttributValeurAttribut : La map contenant le nom des attributs mappés et la valeur de ces attributs.
     */
    std::map<std::string, std::string> mapNomAttributValeurAttribut;

public:
    /**
     * @brief ObjetSerialized : Constructeur sans paramètres.
     */
    ObjetSerialized();
    /**
     * @brief ObjetSerialized : Constructeur prenant en paramètre une chaine de caractères représentant l'objet sérialisé.
     * @param objetString
     */
    ObjetSerialized(std::string objetString);
    /**
     * @brief ~ObjetSerialized : Destructeur sans paramètres.
     */
    ~ObjetSerialized();
    /**
     * @brief getObjetString : Retourner la chaine de caractères qui représente l'objet sérialisé.
     * @return La chaine de caractères qui représente l'objet sérialisé.
     */
    std::string getObjetString() const;
    /**
     * @brief setObjetString Modifier la chaine de caractères qui représente l'objet sérialisé.
     * @param objetString : La nouvelle chaine de caractères qui représente l'objet sérialisé.
     */
    void setObjetString(std::string objetString);
    /**
     * @brief getMapNomAttributValeurAttribut : Retourner la map contenant le nom des attributs mappés et la valeur de ces attributs.
     * @return La map contenant le nom des attributs mappés et la valeur de ces attributs.
     */
    std::map<std::string, std::string> getMapNomAttributValeurAttribut();

    /**
     * @brief remplirMapNomAttributValeurAttribut : Remplir la map contenant le nom des attributs mappés avec les valeurs de ces attributs contenues dans la chaine de caractère.
     */
    void remplirMapNomAttributValeurAttribut();
    /**
     * @brief getValeurAttribut : Retourner la valeur d'un attribut de l'objet sérialisé.
     * @param nomAttribut : Le nom de l'attribut.
     * @return La valeur d'un attribut de l'objet sérialisé.
     */
    std::string getValeurAttribut(std::string nomAttribut);
    /**
     * @brief ajouterAttributString : Ajouter un nom d'attribut et une valeur dans la map.
     * @param nomAttribut : Le nom de l'attribut.
     * @param valeurAttribut : La valeur de l'attribut.
     */
    void ajouterAttributString(std::string nomAttribut, std::string valeurAttribut);
    /**
     * @brief serialiserLesAttributs : Sérialiser les noms et les valeurs des atttibuts contenus dans la map.
     */
    void serialiserLesAttributs();

    /**
     * @brief getObjetStringEncapsule : Retourner les objets sérialisé au format string des objets contenus dans une chaine de caractère représentant un objet sérialisé.
     * @param nomEncapsulation : Le nom du type de l'objet sérialisé à récupérer.
     * @return Les objets de ce type.
     */
    std::vector<std::string> getObjetStringEncapsule(std::string nomEncapsulation);

};

#endif // OBJETSERIALIZED_H
