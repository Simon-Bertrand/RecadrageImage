#ifndef DEF_IMAGESIMILARITY
#define DEF_IMAGESIMILARITY

#include <iostream>
#include "Image.h"

class FonctionSimilarite{
  public :
    //Déclaration de la méthode de la classe FonctionSimilarite
    //Le calcul se réalise sur un tableau de données issu de l'application de la fonction de cout pixel par pixel des 2 images.
    //Cette objet permet de personnaliser si l'on souhaite une fonction somme, produit, moyenne de tous les coefficients issus de la fonction de cout
    virtual double fctSimilarite(NRvector<double>& data_transformed_with_costfct) 
    const=0; // Ici data_transformed_with_costfct répresente l'ensemble filtré par le masque des résultats de la fonction coût pour chaque pixel des deux images dans un vecteur colonne.
};

class SUM : public FonctionSimilarite {
  public:
  double fctSimilarite(NRvector<double>& data_transformed_with_costfct)  const {
    if (data_transformed_with_costfct.size() != 0) {
      double s=0;
      for(unsigned int i=0; i<data_transformed_with_costfct.size();i++)
          s+=data_transformed_with_costfct[i];
      return s;
    }
    else {
      return 255;
    }
    
  }
};

class MEAN : public FonctionSimilarite {
  public:
  double fctSimilarite(NRvector<double>& data_transformed_with_costfct) const {
    if (data_transformed_with_costfct.size() != 0) {
      SUM sum;
      return sum.fctSimilarite(data_transformed_with_costfct)/(data_transformed_with_costfct.size());
    }
    else {
      return 255;
    }  
  }
};

class MEANSQUAREROOT : public FonctionSimilarite {
  public:
  double fctSimilarite(NRvector<double>& data_transformed_with_costfct) const {
    if (data_transformed_with_costfct.size() != 0) {
      SUM sum;
      return sqrt(sum.fctSimilarite(data_transformed_with_costfct))/(data_transformed_with_costfct.size());
      }
    else {
      return 255;
    }
  }
  
};



/* On instancie un objet de la sorte :
  int main() {
  FonctionSimilarite * Similarity = new MEAN(); // ou MEAN
    NRmatrix<double> data(5,5,1);
    std::cout << (*Similarity).fctSimilarite(data);
  }
  */
#endif





