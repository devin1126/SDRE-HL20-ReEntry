//
// File: HL20_Aerodynamics_private.h
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
#ifndef RTW_HEADER_HL20_Aerodynamics_private_h_
#define RTW_HEADER_HL20_Aerodynamics_private_h_
#include "rtwtypes.h"

// Pooled Parameter (Expression: 0)
//  Referenced by:
//    '<S7>/(0 to Inf) Constants Held fixed for alpha<0'
//    '<S8>/Constant1'
//    '<S9>/Constant1'
//    '<S10>/Constant1'
//    '<S10>/Constant2'
//    '<S10>/Constant3'
//    '<S11>/Constant1'
//    '<S11>/Constant2'
//    '<S11>/Constant3'
//    '<S12>/(0 to Inf) Constants Held fixed for alpha<0'
//    '<S13>/Constant1'
//    '<S14>/Constant3'
//    '<S15>/Constant'

#define rtCP_pooled3                   (0.0)

// Pooled Parameter (Expression: b_ref/2)
//  Referenced by:
//    '<S5>/Reference Span'
//    '<S5>/Reference Span '

#define rtCP_pooled4                   (2.1168359322612504)

// Expression: d_ref/2
//  Referenced by: '<S5>/Reference Length'

#define rtCP_ReferenceLength_Gain      (4.3037758622791724)

// Expression: Clbeta
//  Referenced by: '<S6>/Cl'

#define rtCP_Cl_Gain                   (-0.00787)

// Expression: CYbeta
//  Referenced by: '<S6>/Cy'

#define rtCP_Cy_Gain                   (-0.01242)

// Pooled Parameter (Expression: 1/d2r)
//  Referenced by:
//    '<S2>/r-->d1'
//    '<S2>/r-->d2'

#define rtCP_pooled5                   (57.295779513082323)

// Expression: [-(x_cg - x_ref) 0 0]
//  Referenced by: '<S3>/Moments about Center of Gravity'

#define rtCP_MomentsaboutCenterofG_EL_0 (-0.29134307067702103)
#define rtCP_MomentsaboutCenterofG_EL_1 (0.0)
#define rtCP_MomentsaboutCenterofG_EL_2 (0.0)

// Expression: S_ref
//  Referenced by: '<S3>/reference area'

#define rtCP_referencearea_Gain        (26.612074104827229)

// Expression: [b_ref d_ref b_ref]
//  Referenced by: '<S3>/reference length'

#define rtCP_referencelength_Gain_EL_0 (4.2336718645225009)
#define rtCP_referencelength_Gain_EL_1 (8.6075517245583448)
#define rtCP_referencelength_Gain_EL_2 (4.2336718645225009)
#endif                               // RTW_HEADER_HL20_Aerodynamics_private_h_

//
// File trailer for generated code.
//
// [EOF]
//
