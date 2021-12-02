#ifndef DEF_INTERPOLATION
#define DEF_INTERPOLATION

#include <iostream>
#include "Image.h"

class Interpol {
  public :
    virtual double fctInterpol (Image& Idef, double  x, double y) const=0;
};

class InterpolBase : public Interpol{
  public : 
    double fctInterpol (Image& Im, double  x, double  y) const{
      int i1 , i2 , j1, j2;
      double dx,dy,dfy,dfx,dfxy;
      i1 = floor(x);
      j1 = floor(y);
      if (i1==Im.getHeight()-1)
        i1--;
      if ( j1==Im.getWidth()-1)
        j1--;
      i2 = i1+1 ;
      j2 = j1+1 ;
      //Le point (x,y) est dans le carr´e d´efini par les points discrets (i1 , j1) ,( i1 ,j2) ,( i2 , j2) ,( i2 , j1).
      dx = x - i1;
      dy = y - j1;

      dfx = Im.getData()[i2][j1]-Im.getData()[i1][j1];
      dfy = Im.getData()[i1][j2]-Im.getData()[i1][j1];
      dfxy = Im.getData()[i1][j1]+Im.getData()[i2][j2]-Im.getData()[i2][j1]-Im.getData()[i1][j2];
      return Im.getData()[i1][j1] + dfx * dx + dfy * dy + dx*dy*dfxy;
  
    }

};


/* On instancie un objet de la sorte :
  FonctionCout * Cout = new NORM1(); // ou EQM
  std::cout << (*Cout).fctCout(1.0,0.0);

  */

#endif