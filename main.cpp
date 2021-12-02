#include <iostream>
#include "lib/nr3.h"

#include "include/Image.h"
#include "include/ImageTransformation.h"
#include "include/ScoringSystem.h"
#include "include/Recadrage.h"

#include "include/fctInterpolation.h"
#include "include/fctSimilarite.h"
#include "include/fctCout.h"


int main() {
  Image ImRef("data/reference.pgm");
  Image Im("data/floating.pgm");

  Image ImMask(Im.getHeight(), Im.getWidth(),0.0);

  Interpol * interpol = new InterpolBase();
  FonctionSimilarite * fctSimilarity = new MEANSQUAREROOT();
  FonctionCout * fctCout = new NORM2();


  Score score(fctSimilarity, fctCout);
  
  Recadrage recadrage(interpol,fctCout, fctSimilarity,ImRef);
  Image ImResult = recadrage.appliquer(Im);
  std::cout<<endl;
  std::cout << "Erreur avant transformation : " << score.valeur(ImRef,Im,ImMask);

  ImResult.save("result.pgm");


  return 0;
}