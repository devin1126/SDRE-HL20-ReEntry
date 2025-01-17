//
// File: plook_s32dd_binxp.cpp
//
// Code generated for Simulink model 'HL20_Aerodynamics'.
//
// Model version                  : 1.13
// Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
// C/C++ source code generated on : Sun Dec 19 09:34:21 2021
//
#include "rtwtypes.h"
#include "binsearch_s32d_prevIdx.h"
#include "plook_s32dd_binxp.h"

int32_T plook_s32dd_binxp(real_T u, const real_T bp[], uint32_T maxIndex, real_T
  *fraction, int32_T *prevIndex)
{
  int32_T bpIndex;

  // Prelookup - Index and Fraction
  // Index Search method: 'binary'
  // Extrapolation method: 'Linear'
  // Use previous index: 'on'
  // Use last breakpoint for index at or above upper limit: 'off'
  // Remove protection against out-of-range input in generated code: 'off'

  if (u <= bp[0U]) {
    bpIndex = 0;
    *fraction = (u - bp[0U]) / (bp[1U] - bp[0U]);
  } else if (u < bp[maxIndex]) {
    bpIndex = binsearch_s32d_prevIdx(u, bp, static_cast<uint32_T>(*prevIndex),
      maxIndex);
    *fraction = (u - bp[static_cast<uint32_T>(bpIndex)]) / (bp
      [(static_cast<uint32_T>(bpIndex)) + 1U] - bp[static_cast<uint32_T>(bpIndex)]);
  } else {
    bpIndex = static_cast<int32_T>(static_cast<uint32_T>(maxIndex - 1U));
    *fraction = (u - bp[maxIndex - 1U]) / (bp[maxIndex] - bp[maxIndex - 1U]);
  }

  *prevIndex = bpIndex;
  return bpIndex;
}

//
// File trailer for generated code.
//
// [EOF]
//
