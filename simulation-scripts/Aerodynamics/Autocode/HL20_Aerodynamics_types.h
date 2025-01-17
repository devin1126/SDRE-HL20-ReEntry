//
// File: HL20_Aerodynamics_types.h
//
// Code generated for Simulink model 'HL20_Aerodynamics'.
//
// Model version                  : 1.13
// Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
// C/C++ source code generated on : Sun Dec 19 09:34:21 2021
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Windows64)
// Code generation objectives:
//    1. MISRA C:2012 guidelines
//    2. Safety precaution
//    3. Traceability
// Validation result: Not run
//
#ifndef RTW_HEADER_HL20_Aerodynamics_types_h_
#define RTW_HEADER_HL20_Aerodynamics_types_h_
#include "rtwtypes.h"

// Model Code Variants
#ifndef DEFINED_TYPEDEF_FOR_ActuatorBus_
#define DEFINED_TYPEDEF_FOR_ActuatorBus_

typedef struct {
  real_T Aileron;
  real_T Elevator;
  real_T Rudder;
  real_T Flap_Pos;
  real_T Flap_Neg;
  real_T Flap_Dif;
} ActuatorBus;

#endif
#endif                                 // RTW_HEADER_HL20_Aerodynamics_types_h_

//
// File trailer for generated code.
//
// [EOF]
//
