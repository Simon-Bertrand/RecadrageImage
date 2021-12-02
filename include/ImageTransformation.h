
#ifndef DEF_IMAGETRANSFORMATION
#define DEF_IMAGETRANSFORMATION

#include "Image.h"
#include "fctInterpolation.h"

class ImageTransformation{
  private : 
    void unitaryTransform(const VecDoub & params, double x, double y, double& xres, double& yres,bool & masked_pixel, int size1_Iref, int size2_Iref);// transforme un pixel de l'image en fonction du vecteur paramètres contenant l'angle tetha et les paramètres de translations t_x et t_y
    
  public :
    void applyTransform(Image& Idef0, Image& Idef, Image& Imask, Interpol * interpol, const VecDoub & params);//applique la transformation et retourne l'image déformée Idef et le Masque qui servira à rogner les pixels en dehors de l'image 

};




#endif





