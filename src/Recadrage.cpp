#include <iostream>
#include "../include/Recadrage.h"
#include "../lib/amoeba.h"
#include <cmath>
#include <sstream>
#include <stdlib.h>  

using namespace std;

class ScoreComputerAmoeba
  {	
    private:
    Image& Im_to_crop;
    Image& Imref;
    Interpol *(i);
    Score& score;
    int compt=0;
    
  public:
    ScoreComputerAmoeba(Image& Icrop, Image& Iref, Interpol * interpol, Score & score) : Im_to_crop(Icrop), Imref(Iref), i(interpol), score(score) {}

    double operator() (const VecDoub& params)  {
      Image Imask(Im_to_crop.getHeight(), Im_to_crop.getWidth(),0.0);
      Image Idef(Im_to_crop.getHeight(), Im_to_crop.getWidth(),0.0);

      ImageTransformation transformation;
      transformation.applyTransform(Im_to_crop, Idef, Imask, i , params);
      std::cout<<"Iteration :"<<compt << "\n";
      std::cout<<"Score :"<<score.valeur(Imref, Idef, Imask) << "\n";
      std::cout << "Tx:"<<params[0] << "; Ty:"<<params[1]<<"; Theta:"<<params[2]<<endl<<endl;
      stringstream ss;
      ss << string("results/img/results") <<  compt << string(".pgm");
      compt++;

      Idef.save(ss.str().c_str());
      

   
      ofstream myfile;
      myfile.open("results/plot/gnuplotsdata.txt",  std::ios_base::app);
      myfile << compt <<" "<< params[0] << " " << params[1]<< " " << params[2] << endl;
      myfile.close();

      return score.valeur(Imref, Idef, Imask); //minimisation de la fonction score pour l'image tout juste transformée
      }
  };

Image Recadrage::appliquer(Image& Im_to_crop) {
  Score score(this->sFct, this->cFct);

  ScoreComputerAmoeba foncteur(Im_to_crop,this->Iref, this->i, score);
  //0.01 est la taille du simplex minimale avant arrêt de l'algo
  Amoeba opt(0.00001);
  /*Point de départ*/
  VecDoub paramstart(3);
  //Initialisation
  paramstart[0]=0;
  paramstart[1]=0;
  paramstart[2]=0;
  /*resultat*/
  VecDoub paramsopt(3);

  system("rm ./results/plot/gnuplotsdata.txt && touch ./results/plot/gnuplotsdata.txt");
  system("rm -r ./results/img");
  system("mkdir ./results/img");
  paramsopt = opt.minimize(paramstart,20,foncteur); //2 est la taille du simplex au départ
  system("gnuplot -persist ./results/plot/gnuplotssettings.gp");
  system("zip -r -qq resultsauto.zip ./results");

  
  std::cout <<"Opti parameters : " <<"Tx:"<< paramsopt[0] << "; Ty:"<<paramsopt[1]<<"; Theta:"<<paramsopt[2]<<endl;

  ImageTransformation transformation;

  Image Idef(Im_to_crop.getHeight(), Im_to_crop.getWidth(),0.0); 
  Image Imask(Im_to_crop.getHeight(), Im_to_crop.getWidth(),0.0);

  transformation.applyTransform(Im_to_crop, Idef, Imask, this->i, paramsopt);

  std::cout << "Erreur après transformation : " << score.valeur(Idef, Iref, Imask);
  
  return Idef;
}






