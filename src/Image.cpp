#include "../include/Image.h"
#include <iostream>
#include <algorithm>

using namespace std;


Image::Image(NRmatrix<double> data_ext, int h, int w) {
  this->a_data=data_ext;
  this->a_width = w;
  this->a_height = h;
}

Image::Image(int h, int w, double val) {
  NRmatrix<double> data(h,w,val);
  this->a_data=data;
  this->a_width = w;
  this->a_height = h;
}

Image:: Image(Image& Im){
  NRmatrix<double> data;
  this->a_width=Im.a_width;
  this->a_height=Im.a_height;
  data.assign(a_width, a_height, 0.0);

  for( int i=0; i<this->a_height; i++ ){
    for(int j=0; j<this->a_width; j++){
      data[i][j] = Im.a_data[i][j];
    }
  }
  this->a_data = data;
}
  
Image::Image(const char * filename){
  NRmatrix<double> data;

  std::string buffer,firstline;
  std::ifstream f(filename);
  f.seekg(0, std::ios::end); buffer.resize(f.tellg()); f.seekg(0);
  f.read(buffer.data(), buffer.size());
  f.close();

  firstline=buffer.substr(0,buffer.find("\n") + 1);
  this->a_width = stoi(firstline.substr(3,3));
  this->a_height = stoi(firstline.substr(7,3));
  data.assign(this->a_width,this->a_height, 0);
  buffer.erase(0, buffer.find("\n") + 1);

  int idxlin=0; int val; unsigned int ind_find;
  std::replace( buffer.begin(), buffer.end(), '\n', ' ');
    while(idxlin<this->a_width*this->a_height){

      if(buffer.find(' ')==0) {buffer.erase(0,1);}
      ind_find = buffer.find(' ');
      data[idxlin/this->a_width][idxlin%this->a_width]=stoi(buffer.substr(0,ind_find));
      buffer.erase(0,ind_find+1);
      idxlin++;
    }
  
  this->a_data=data;
}

NRmatrix<double>& Image::getData() {
  return this->a_data;
}
int Image::getHeight() const{
  return this->a_height;
}

int Image::getWidth() const{
  return this->a_width;
}



void Image::save(const char * filename) {

  ofstream myfile;
  unsigned int compt=0;
  myfile.open(filename);

  myfile << "P2 "<<this->getWidth()<<" "<<this->getHeight()<<" 255\n";

  for(unsigned int i=0; i<this->a_height; i++) {
    for(unsigned int j=0; j<this->a_width; j++) {
      compt++;
      myfile<<(int)this->getData()[i][j]<<" ";
      if (compt == 17) {
        myfile<<"\n";
        compt=0;
      }
    }  
  }
  myfile.close();
}

