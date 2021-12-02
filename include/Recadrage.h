#ifndef DEF_RECADRAGE
#define DEF_RECADRAGE
#include <iostream>
#include <cmath>
#include "Image.h"
#include "ImageTransformation.h"
#include "ScoringSystem.h"
#include "fctInterpolation.h"
#include "fctSimilarite.h"
#include "fctCout.h"

using namespace std;

//Gère les entrées sorties des Images
class Recadrage{
  private:
    Interpol * (i);
    FonctionCout * (cFct);
    FonctionSimilarite * (sFct);
    Image& Iref;
  public :
    Recadrage(Interpol * interpol, FonctionCout * costFct, FonctionSimilarite * similarityFct, Image& Imageref) : i(interpol), cFct(costFct), sFct(similarityFct), Iref(Imageref) {}
    Image appliquer(Image& Im_to_crop);

};




#endif





