#ifndef CLIENT_H
#define CLIENT_H

#include "produit.h"

#include <string>
#include <vector>



class Client {

private:
    int identifiantClient;
    std::string prenomClient;
    std::string nomClient;
    std::vector<Produit*> listeProduitsSelectionnes;

public:
    Client();

};

#endif // CLIENT_H
