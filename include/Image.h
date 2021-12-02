#ifndef DEF_IMAGE
#define DEF_IMAGE
#include "../lib/nr3.h"
#include <iostream>

//Gère les entrées sorties des Images
class Image{
  private : 
    int a_width, a_height; //Dimensions de l'image
    NRmatrix<double> a_data; //Données de la matrice de l'image
    
  public :
    Image(NRmatrix<double> data, int h, int w);//constructeur originem
    Image(int h, int w, double val);//constructeur originem

    Image(const char* filename);//constructeur par ouverture de fichier 
    Image(Image& Im);//constructeur de recopie 
    
    int getHeight() const;
    int getWidth() const;
    NRmatrix<double>& getData();
    void save(const char* filename);//sauvegarde de l'image dans un fichier 
};




#endif





