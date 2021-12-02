
#include <iostream>
#include "../include/ImageTransformation.h"
#include <cmath>


void ImageTransformation::unitaryTransform(const VecDoub& param, double x, double y, double& xres, double& yres, bool & masked_pixel, int size1_Iref, int size2_Iref){
  xres =  (x-size1_Iref/2)*cos(param[2]*2*3.1415/360)-(y-size2_Iref/2)*sin(param[2]*2*3.1415/360)+param[0];
  yres = (x-size1_Iref/2)*sin(param[2]*2*3.1415/360)+(y-size2_Iref/2)*cos(param[2]*2*3.1415/360)+param[1];

  if (xres >= size2_Iref || xres < 0 || yres < 0 || yres >= size1_Iref) {
    masked_pixel=true;
  }
  else{
    masked_pixel=false;
  }
}

void ImageTransformation::applyTransform(Image& Idef0, Image& Idef, Image& Imask, Interpol * interpol, const VecDoub& param){
  double x,y;
  bool masked_pixel=false;
  for (int i=0; i<Idef0.getHeight(); i++){
    for (int j=0; j<Idef0.getWidth(); j++){
      this->unitaryTransform(param, i, j, x, y,masked_pixel,Idef0.getHeight(), Idef0.getWidth());
      Imask.getData()[i][j] = masked_pixel;
      if (!masked_pixel) {Idef.getData()[i][j] = interpol->fctInterpol(Idef0,x,y);}
    }
  }
}






