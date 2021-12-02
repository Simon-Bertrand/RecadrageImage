#ifndef DEF_SCORINGSYSTEM
#define DEF_SCORINGSYSTEM

#include <iostream>
#include "Image.h"
#include "fctSimilarite.h"
#include "fctCout.h"


class Score{
  private:
  FonctionSimilarite *(similarityFct);
  FonctionCout *(costFct);
  public :
    Score(FonctionSimilarite *(sFct), FonctionCout *(cFct)) {
      this->similarityFct=sFct;
      this->costFct=cFct;
    }

    double valeur(Image& Iref, Image& Idef, Image& Mask) {
      unsigned int count_mask = 0;
        for(unsigned int i=0; i<Mask.getWidth();i++)
          for(unsigned int j=0; j<Mask.getHeight();j++) 
            if(Mask.getData()[i][j] == 0){ count_mask++;}

      NRvector<double> data(count_mask,0.0);
      if(Iref.getWidth() == Idef.getWidth() && Iref.getHeight() == Idef.getHeight() && Mask.getWidth()== Idef.getWidth() && Mask.getHeight()== Idef.getHeight()) {
        count_mask = 0;
        for(unsigned int i=0; i<Iref.getWidth();i++)
          for(unsigned int j=0; j<Iref.getHeight();j++) 
            if(Mask.getData()[i][j] == 0){
              data[count_mask] = this->costFct->fctCout(Iref.getData()[i][j], Idef.getData()[i][j]);
              count_mask++;
            }
        return this->similarityFct->fctSimilarite(data);
      }
      else {
        std::cout << "Erreur : Impossible de calculer la fonction coût, les dimensions ne sont pas les mêmes.";
        return 0.0;
      }

    };
};



#endif