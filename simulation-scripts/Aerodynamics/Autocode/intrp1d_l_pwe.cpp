//
// File: intrp1d_l_pwe.cpp
//
// Code generated for Simulink model 'HL20_Aerodynamics'.
//
// Model version                  : 1.13
// Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
// C/C++ source code generated on : Sun Dec 19 09:34:21 2021
//
#include "rtwtypes.h"
#include "intrp1d_l_pwe.h"

real_T intrp1d_l_pwe(uint32_T bpIndex, real_T frac, const real_T table[])
{
  real_T yL_0d0;

  // Column-major Interpolation 1-D
  // Interpolation method: 'Linear point-slope'
  // Use last breakpoint for index at or above upper limit: 'off'
  // Overflow mode: 'portable wrapping'

  yL_0d0 = table[bpIndex];
  return ((table[bpIndex + 1U] - yL_0d0) * frac) + yL_0d0;
}

//
// File trailer for generated code.
//
// [EOF]
//
