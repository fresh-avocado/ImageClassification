#ifndef VECTORCARACTERISTICO
#define VECTORCARACTERISTICO

#define cimg_use_png 1
#include <CImg.h>
#include <math.h>
#include <bits/stdc++.h>

using namespace std;
using namespace cimg_library;

template <typename T>
class VC {
    vector<T>* vc;
    char imgPath[200];
    float size = 48.0;
public:
    VC(const char* imgPath, uint8_t ncortes = 1) {
        strcpy(this->imgPath, imgPath);
        CImg<T> A(imgPath);
        CImg<T> B = A.haar(false, ncortes);
        CImg<T> C = B.crop(0, 0, 23, 23);
        this->vc = vectorizar4(C);
    }

    void printImgPath() {
        cout << imgPath << "\n";
    }

    char* getImgPath() {
         return imgPath;
    }

    vector<T> get() {
        return *vc;
    }

private:

    vector<T>* vectorizar1(CImg<T>& img) {
        vector<T>* r = new vector<T>();
        for(int i=0; i<size; ++i){
            T aux = 0;
            for(int j=0; j<size; ++j){
                aux += (img(i, j, 0) +img(i, j, 1) +img(i, j, 2))/3.0;
            } 
           // aux = aux/size;
            r->push_back(aux);
        }
        return r;
    }

    vector<T>* vectorizar2(CImg<T>& img) {
        vector<T>* r = new vector<T>();
        for(int i=0; i<size; ++i){
            T aux = 1;
            for(int j=0; j<size; ++j){
                aux *= log2(img(i, j, 0) * img(i, j, 1) * img(i, j, 2));
            } 
            aux = sqrt(aux);
            r->push_back(aux);
        }
        return r;
    }

    vector<T>* vectorizar3(CImg<T>& img) {
        vector<T>* r = new vector<T>(255,0);
        vector<T>* a = new vector<T>();

        for(int i=0; i<size; ++i){
            
            for(int j=0; j<size; ++j){
               T aux = img(i, j, 0)*0.21 + img(i, j, 1)*0.72 + img(i, j, 2)*0.07 ;
               a->push_back(aux);
            } 
           
        }

        for(auto it:*a){

             (*r)[(int) floor(it)] =  (*r)[(int) floor(it)] + 1;
            
        }

        return r;
    }
    
    vector<T>* vectorizar4(CImg<T>& img) {
          vector<T>* r = new vector<T>();
          cimg_forXY (img, x, y) {
               r->push_back(		(
                                   img(x, y, 0) + 
                                   img(x, y, 1) + 
                                   img(x, y, 2) 
                                   )/3.0f
                              );
          }
          return r;
     }


};

#endif