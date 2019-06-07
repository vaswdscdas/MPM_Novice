#ifndef _ACE_MATERIALS_HPP_
#define _ACE_MATERIALS_HPP_

#include "sms.h"


void SmallStrainHookePlaneStrain2D(double MaterialData[2],double Eps[3],double Exp[16]);

void SmallStrainHookePlaneStress2D(double MaterialData[2],double Eps[3],double Exp[16]);

void STVKPlaneStress2D(double MaterialData[2],double F[9],double Sig[9],double Cmat[9][9]);

void STVKPlaneStrain2D(double MaterialData[2],double F[9],double Sig[9],double Cmat[9][9]);

void J2FiniteStrain3D(double d[6],double F[9],double h[10],double Sig[9],double Cmat[9][9]);

#endif
