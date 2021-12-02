#ifndef DEF_COSTFUNCTION
#define DEF_COSTFUNCTION
#include <cmath>
#include <iostream>

class FonctionCout{
    //Cet objet permet la personnalisation de la fonction coût appliqué aux pixels de l'image 1 et 2. On réalise le calcul pixel par pixel, ces derniers ne sont pas issus de la même image.
  public :
    virtual double fctCout (double  pixel_a, double  pixel_b) const=0;
};




class NORM1 : public FonctionCout{
  public : 
    //Constructeur à créer
    double fctCout (double  pixel_a, double  pixel_b) const{
      return std::abs(pixel_a-pixel_b);
    }

};

class NORM2 : public FonctionCout{
  public : 
    double fctCout (double  pixel_a, double  pixel_b) const{
      return pow(pixel_a-pixel_b,2);
    }

};

class NORM3 : public FonctionCout{
  public : 
    double fctCout (double  pixel_a, double  pixel_b) const{
      return pow(pixel_a-pixel_b,3);
    }

};

/* On instancie un objet de la sorte :
  FonctionCout * Cout = new NORM1(); // ou EQM
  std::cout << (*Cout).fctCout(1.0,0.0);

  */

#endif