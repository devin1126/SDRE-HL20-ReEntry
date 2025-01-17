//
// File: intrp2d_l_pwe.cpp
//
// Code generated for Simulink model 'HL20_Aerodynamics'.
//
// Model version                  : 1.13
// Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
// C/C++ source code generated on : Sun Dec 19 09:34:21 2021
//
#include "rtwtypes.h"
#include "intrp2d_l_pwe.h"

real_T intrp2d_l_pwe(const uint32_T bpIndex[], const real_T frac[], const real_T
                     table[], const uint32_T stride)
{
  real_T yL_0d0;
  real_T yL_0d1;
  uint32_T offset_1d;

  // Column-major Interpolation 2-D
  // Interpolation method: 'Linear point-slope'
  // Use last breakpoint for index at or above upper limit: 'off'
  // Overflow mode: 'portable wrapping'

  offset_1d = (bpIndex[1U] * stride) + bpIndex[0U];
  yL_0d0 = table[offset_1d];
  yL_0d0 += (table[offset_1d + 1U] - yL_0d0) * frac[0U];
  offset_1d += stride;
  yL_0d1 = table[offset_1d];
  return (((((table[offset_1d + 1U] - yL_0d1) * frac[0U]) + yL_0d1) - yL_0d0) *
          frac[1U]) + yL_0d0;
}

//
// File trailer for generated code.
//
// [EOF]
//
