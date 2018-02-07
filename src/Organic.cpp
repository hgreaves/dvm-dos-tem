#include "../include/Organic.h"

Organic::Organic() {
};

Organic::~Organic() {
};

void Organic::ShlwThickScheme(const double & totthickness) {
  shlwthick = totthickness;

  if (totthickness<0.) {
    shlwthick = 0.;
  }

  shlwnum   = 0;

  //These values are from Shuhua Yi's paper, 2010
  if(totthickness<=0.00) {
    shlwdz[0]=MISSING_D;
    shlwdz[1]=MISSING_D;
    shlwdz[2]=MISSING_D;
    shlwnum =0;
  } else if (totthickness<0.04) {
    shlwdz[0]=totthickness;
    shlwdz[1]=MISSING_D;
    shlwdz[2]=MISSING_D;
    shlwnum =1;
  } else if (totthickness<0.06) {
    shlwdz[0]=0.02;
    shlwdz[1]=totthickness-0.02;
    shlwdz[2]=MISSING_D;
    shlwnum =2;
  } else if (totthickness<0.10) {
    shlwdz[0]=0.03;
    shlwdz[1]=totthickness-0.03;
    shlwdz[2]=MISSING_D;
    shlwnum =2;
  } else if (totthickness<0.15) {
    shlwdz[0]=0.02;
    shlwdz[1]=0.04;
    shlwdz[2]=totthickness-0.06;
    shlwnum =3;
  } else if (totthickness<0.20) {
    shlwdz[0]=0.03;
    shlwdz[1]=0.06;
    shlwdz[2]=totthickness -0.09;
    shlwnum =3;
  } else if (totthickness<0.28) {
    shlwdz[0]=0.04;
    shlwdz[1]=0.08;
    shlwdz[2]=totthickness -0.12;
    shlwnum =3;
  } else if (totthickness<0.40) {
    shlwdz[0]=0.05;
    shlwdz[1]=0.11;
    shlwdz[2]=totthickness -0.16;
    shlwnum =3;
  } else if (totthickness >=0.4) {
    shlwdz[0]=0.1;
    shlwdz[1]=0.2;
    shlwdz[2]=totthickness -0.3;
    shlwnum =3;
  }

  if (shlwnum>0) {
    lstshlwdz = shlwdz[shlwnum-1];
  }
};



void Organic::DeepThickScheme(const double & totthickness) {
  deepthick = totthickness;

  if(totthickness<=0.0) {
    deepthick =0.0;
    deepdz[0]=MISSING_D;
    deepdz[1]=MISSING_D;
    deepdz[2]=MISSING_D;
    deepdz[3]=MISSING_D;
    deepdz[4]=MISSING_D;
    deepdz[5]=MISSING_D;
    deepdz[6]=MISSING_D;
    deepdz[7]=MISSING_D;
    deepdz[8]=MISSING_D;
    deepnum =0;
    return;
  }

  deepnum = 0;
// Increased number of possible layers to improve the vertical resolution of soil column in wetlands
  if(lstshlwdz>0.0) {
      if(deepthick < 2* lstshlwdz) {
        deepdz[0]=deepthick;
        deepdz[1]=MISSING_D;
        deepdz[2]=MISSING_D;
        deepdz[3]=MISSING_D;
        deepdz[4]=MISSING_D;
        deepdz[5]=MISSING_D;
        deepdz[6]=MISSING_D;
        deepdz[7]=MISSING_D;
        deepdz[8]=MISSING_D;
        deepnum =1;
      } else if(deepthick >= 2* lstshlwdz && deepthick<4*lstshlwdz) {
        deepdz[0]=1./3. * deepthick;
        deepdz[1]=2./3. * deepthick;
        deepdz[2]=MISSING_D;
        deepdz[3]=MISSING_D;
        deepdz[4]=MISSING_D;
        deepdz[5]=MISSING_D;
        deepdz[6]=MISSING_D;
        deepdz[7]=MISSING_D;
        deepdz[8]=MISSING_D;
        deepnum =2;
      } else if(deepthick >= 4* lstshlwdz && deepthick<6*lstshlwdz) {
        deepdz[0]=1./6. * deepthick;
        deepdz[1]=2./6. * deepthick;
        deepdz[2]=3./6. * deepthick;
        deepdz[3]=MISSING_D;
        deepdz[4]=MISSING_D;
        deepdz[5]=MISSING_D;
        deepdz[6]=MISSING_D;
        deepdz[7]=MISSING_D;
        deepdz[8]=MISSING_D;
        deepnum =3;
      } else if(deepthick >= 6* lstshlwdz && deepthick<8*lstshlwdz) {
        deepdz[0]=1./10. * deepthick;
        deepdz[1]=2./10. * deepthick;
        deepdz[2]=3./10. * deepthick;
        deepdz[3]=4./10. * deepthick;
        deepdz[4]=MISSING_D;
        deepdz[5]=MISSING_D;
        deepdz[6]=MISSING_D;
        deepdz[7]=MISSING_D;
        deepdz[8]=MISSING_D;
        deepnum =4;
      } else if(deepthick >= 8* lstshlwdz && deepthick<10*lstshlwdz) {
        deepdz[0]=1./15. * deepthick;
        deepdz[1]=2./15. * deepthick;
        deepdz[2]=3./15. * deepthick;
        deepdz[3]=4./15. * deepthick;
        deepdz[4]=5./15. * deepthick;
        deepdz[5]=MISSING_D;
        deepdz[6]=MISSING_D;
        deepdz[7]=MISSING_D;
        deepdz[8]=MISSING_D;
        deepnum =5;
      } else if(deepthick >=10* lstshlwdz && deepthick<12*lstshlwdz) {
        deepdz[0]=1./21. * deepthick;
        deepdz[1]=2./21. * deepthick;
        deepdz[2]=3./21. * deepthick;
        deepdz[3]=4./21. * deepthick;
        deepdz[4]=5./21. * deepthick;
        deepdz[5]=6./21. * deepthick;
        deepdz[6]=MISSING_D;
        deepdz[7]=MISSING_D;
        deepdz[8]=MISSING_D;
        deepnum =6;
      } else if(deepthick >=12* lstshlwdz && deepthick<14*lstshlwdz) {
        deepdz[0]=1./28. * deepthick;
        deepdz[1]=2./28. * deepthick;
        deepdz[2]=3./28. * deepthick;
        deepdz[3]=4./28. * deepthick;
        deepdz[4]=5./28. * deepthick;
        deepdz[5]=6./28. * deepthick;
        deepdz[6]=7./28. * deepthick;
        deepdz[7]=MISSING_D;
        deepdz[8]=MISSING_D;
        deepnum =7;
      } else if(deepthick >=14* lstshlwdz && deepthick<16*lstshlwdz) {
        deepdz[0]=1./36. * deepthick;
        deepdz[1]=2./36. * deepthick;
        deepdz[2]=3./36. * deepthick;
        deepdz[3]=4./36. * deepthick;
        deepdz[4]=5./36. * deepthick;
        deepdz[5]=6./36. * deepthick;
        deepdz[6]=7./36. * deepthick;
        deepdz[7]=8./36. * deepthick;
        deepdz[8]=MISSING_D;
        deepnum =8;
      } else{
        deepdz[0]=1./45. * deepthick;
        deepdz[1]=2./45. * deepthick;
        deepdz[2]=3./45. * deepthick;
        deepdz[3]=4./45. * deepthick;
        deepdz[4]=5./45. * deepthick;
        deepdz[5]=6./45. * deepthick;
        deepdz[6]=7./45. * deepthick;
        deepdz[7]=8./45. * deepthick;
        deepdz[8]=9./45. * deepthick;
        deepnum =9;
      }
  } else {
    if(deepthick <= 0.02) {
      deepdz[0]=deepthick;
      deepdz[1]=MISSING_D;
      deepdz[2]=MISSING_D;
      deepdz[3]=MISSING_D;
      deepdz[4]=MISSING_D;
      deepdz[5]=MISSING_D;
      deepdz[6]=MISSING_D;
      deepdz[7]=MISSING_D;
      deepdz[8]=MISSING_D;
      deepnum =1;
    } else if(deepthick<=0.06) {
      deepdz[0]=1./3. * deepthick;
      deepdz[1]=2./3. * deepthick;
      deepdz[2]=MISSING_D;
      deepdz[3]=MISSING_D;
      deepdz[4]=MISSING_D;
      deepdz[5]=MISSING_D;
      deepdz[6]=MISSING_D;
      deepdz[7]=MISSING_D;
      deepdz[8]=MISSING_D;
      deepnum =2;
    } else if(deepthick <=0.20){
      deepdz[0]=1./6. * deepthick;
      deepdz[1]=2./6. * deepthick;
      deepdz[2]=3./6. * deepthick;
      deepdz[3]=MISSING_D;
      deepdz[4]=MISSING_D;
      deepdz[5]=MISSING_D;
      deepdz[6]=MISSING_D;
      deepdz[7]=MISSING_D;
      deepdz[8]=MISSING_D;
      deepnum =3;
    } else if(deepthick <= 0.35){
      deepdz[0]=1./10. * deepthick;
      deepdz[1]=2./10. * deepthick;
      deepdz[2]=3./10. * deepthick;
      deepdz[3]=4./10. * deepthick;
      deepdz[4]=MISSING_D;
      deepdz[5]=MISSING_D;
      deepdz[6]=MISSING_D;
      deepdz[7]=MISSING_D;
      deepdz[8]=MISSING_D;
      deepnum =4;
    } else if(deepthick <= 0.50) {
      deepdz[0]=1./15. * deepthick;
      deepdz[1]=2./15. * deepthick;
      deepdz[2]=3./15. * deepthick;
      deepdz[3]=4./15. * deepthick;
      deepdz[4]=5./15. * deepthick;
      deepdz[5]=MISSING_D;
      deepdz[6]=MISSING_D;
      deepdz[7]=MISSING_D;
      deepdz[8]=MISSING_D;
      deepnum =5;
    } else if(deepthick <= 0.65) {
      deepdz[0]=1./21. * deepthick;
      deepdz[1]=2./21. * deepthick;
      deepdz[2]=3./21. * deepthick;
      deepdz[3]=4./21. * deepthick;
      deepdz[4]=5./21. * deepthick;
      deepdz[5]=6./21. * deepthick;
      deepdz[6]=MISSING_D;
      deepdz[7]=MISSING_D;
      deepdz[8]=MISSING_D;
      deepnum =6;
    } else if(deepthick <= 0.80) {
      deepdz[0]=1./28. * deepthick;
      deepdz[1]=2./28. * deepthick;
      deepdz[2]=3./28. * deepthick;
      deepdz[3]=4./28. * deepthick;
      deepdz[4]=5./28. * deepthick;
      deepdz[5]=6./28. * deepthick;
      deepdz[6]=7./28. * deepthick;
      deepdz[7]=MISSING_D;
      deepdz[8]=MISSING_D;
      deepnum =7;
    } else if(deepthick <= 0.95) {
      deepdz[0]=1./36. * deepthick;
      deepdz[1]=2./36. * deepthick;
      deepdz[2]=3./36. * deepthick;
      deepdz[3]=4./36. * deepthick;
      deepdz[4]=5./36. * deepthick;
      deepdz[5]=6./36. * deepthick;
      deepdz[6]=7./36. * deepthick;
      deepdz[7]=8./36. * deepthick;
      deepdz[8]=MISSING_D;
      deepnum =8;
    } else {
      deepdz[0]=1./45. * deepthick;
      deepdz[1]=2./45. * deepthick;
      deepdz[2]=3./45. * deepthick;
      deepdz[3]=4./45. * deepthick;
      deepdz[4]=5./45. * deepthick;
      deepdz[5]=6./45. * deepthick;
      deepdz[6]=7./45. * deepthick;
      deepdz[7]=8./45. * deepthick;
      deepdz[8]=9./45. * deepthick;
      deepnum =9;
    }
  }
};

// if shlw peat thickness from input soil profile
void Organic::assignShlwThicknesses(int soiltype[], double soildz[],
                                    const int & soilmaxnum) {
  shlwnum   = 0;
  shlwthick = 0;

  for(int i=0; i<soilmaxnum; i++) {
    if(soiltype[i] ==1) {
      shlwdz[shlwnum] = soildz[i];
      shlwnum ++;
      shlwthick += soildz[i];
    } else {
      if(soiltype[i]>2) {
        break;
      }
    }
  }
};

// if deep peat thickness from input soil profile
void Organic::assignDeepThicknesses(int soiltype[], double soildz[],
                                    const int & soilmaxnum) {
  deepnum =0;
  deepthick =0;

  for(int i=0; i<soilmaxnum; i++) {
    if(soiltype[i] ==2) {
      deepdz[deepnum] = soildz[i];
      deepnum ++;
      deepthick += soildz[i];
    } else {
      if(soiltype[i]>2) {
        break;
      }
    }
  }
};

