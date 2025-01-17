//
// File: binsearch_s32d_prevIdx.cpp
//
// Code generated for Simulink model 'HL20_Aerodynamics'.
//
// Model version                  : 1.13
// Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
// C/C++ source code generated on : Sun Dec 19 09:34:21 2021
//
#include "rtwtypes.h"
#include "binsearch_s32d_prevIdx.h"

int32_T binsearch_s32d_prevIdx(real_T u, const real_T bp[], uint32_T startIndex,
  uint32_T maxIndex)
{
  uint32_T bpIdx;
  uint32_T found;
  uint32_T iLeft;
  uint32_T iRght;

  // Binary Search using Previous Index
  bpIdx = startIndex;
  iLeft = 0U;
  iRght = maxIndex;
  found = 0U;
  while (found == 0U) {
    if (u < bp[bpIdx]) {
      iRght = bpIdx - 1U;
      bpIdx = (((bpIdx + iLeft) - 1U) >> 1U);
    } else if (u < bp[bpIdx + 1U]) {
      found = 1U;
    } else {
      iLeft = bpIdx + 1U;
      bpIdx = (((bpIdx + iRght) + 1U) >> 1U);
    }
  }

  return static_cast<int32_T>(bpIdx);
}

//
// File trailer for generated code.
//
// [EOF]
//
