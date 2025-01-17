//
// File: HL20_Aerodynamics.cpp
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
#include "HL20_Aerodynamics.h"
#include "HL20_Aerodynamics_private.h"
#include "intrp1d_l_pwe.h"
#include "intrp2d_l_pwe.h"
#include "look2_binlxpw.h"
#include "plook_s32dd_binxp.h"

// Output and update for atomic system: '<S2>/Actuator_Increments'
void HL20_AerodynamicsModelClass::HL20_Aerody_Actuator_Increments(real_T
  rtu_Alpha, real_T rtu_ActuatorDeflections, real_T rtu_ActuatorDeflections_e,
  real_T rtu_ActuatorDeflections_d, real_T rtu_ActuatorDeflections_k, real_T
  rtu_ActuatorDeflections_m, real_T rtu_ActuatorDeflections_c, real_T
  rty_Actuator_Increments[6], real_T *rty_AeroBus, real_T *rty_AeroBus_e, real_T
  *rty_AeroBus_d, real_T *rty_AeroBus_k, real_T *rty_AeroBus_m, real_T
  *rty_AeroBus_c, real_T *rty_AeroBus_d1, real_T *rty_AeroBus_dt, real_T
  *rty_AeroBus_e5, DW_Actuator_Increments_HL20_A_T *localDW)
{
  real_T rtb_Product[6];
  real_T rtb_Product2_c_0[6];
  real_T rtb_Product_a[6];
  real_T rtb_Product_d[6];
  real_T rty_AeroBus_m_0[6];
  real_T indexTmp_0d;
  real_T rtb_Cm_c;
  real_T rtb_Cm_m;
  real_T rtb_Cx_h;
  real_T rtb_Cx_m;
  real_T rtb_Cz_b;
  real_T rtb_Cz_n;
  real_T rtb_Product1;
  real_T rtb_Product2;
  real_T rtb_Product2_c;
  real_T rtb_Product2_o;
  real_T rtb_Product3_a;
  real_T rtb_Product5_b;
  real_T rtb_Product6;
  real_T rtb_Product7;
  real_T rtb_Product_bw;
  real_T rtb_utoInfConstantsHeldfixedf_0;
  real_T rtb_utoInfConstantsHeldfixedf_1;
  real_T scalarFraction;
  int32_T indexTmp_0d_0;
  int_T scalarIndex;
  uint32_T bpIndex;

  // S-Function (sfun_idxsearch): '<S4>/AlphaLookup'
  scalarIndex = static_cast<int_T>(plook_s32dd_binxp(rtu_Alpha,
    HL20_Aerodynamics_ConstP.pooled2, 40U, &scalarFraction,
    &localDW->AlphaLookup_MODE));

  // Saturate: '<S7>/(0 to Inf) Constants Held fixed for alpha<0'
  if ((static_cast<real_T>(scalarIndex)) > rtCP_pooled3) {
    rtb_utoInfConstantsHeldfixedf_1 = static_cast<real_T>(scalarIndex);
  } else {
    rtb_utoInfConstantsHeldfixedf_1 = rtCP_pooled3;
  }

  if (scalarFraction > rtCP_pooled3) {
    rtb_utoInfConstantsHeldfixedf_0 = scalarFraction;
  } else {
    rtb_utoInfConstantsHeldfixedf_0 = rtCP_pooled3;
  }

  // End of Saturate: '<S7>/(0 to Inf) Constants Held fixed for alpha<0'

  // S-Function (sfun_kflookupnd): '<S7>/Cl'
  indexTmp_0d = rtb_utoInfConstantsHeldfixedf_1;
  if (indexTmp_0d > 39.0) {
    indexTmp_0d = 39.0;
  } else {
    if (indexTmp_0d < 0.0) {
      indexTmp_0d = 0.0;
    }
  }

  bpIndex = static_cast<uint32_T>(indexTmp_0d);
  *rty_AeroBus = intrp1d_l_pwe(bpIndex, rtb_utoInfConstantsHeldfixedf_0,
    HL20_Aerodynamics_ConstP.Cl_tableData);

  // End of S-Function (sfun_kflookupnd): '<S7>/Cl'

  // S-Function (sfun_kflookupnd): '<S7>/Cm'
  indexTmp_0d = rtb_utoInfConstantsHeldfixedf_1;
  if (indexTmp_0d > 39.0) {
    indexTmp_0d = 39.0;
  } else {
    if (indexTmp_0d < 0.0) {
      indexTmp_0d = 0.0;
    }
  }

  bpIndex = static_cast<uint32_T>(indexTmp_0d);
  *rty_AeroBus_e = intrp1d_l_pwe(bpIndex, rtb_utoInfConstantsHeldfixedf_0,
    HL20_Aerodynamics_ConstP.Cm_tableData);

  // End of S-Function (sfun_kflookupnd): '<S7>/Cm'

  // S-Function (sfun_kflookupnd): '<S7>/Cn'
  indexTmp_0d = rtb_utoInfConstantsHeldfixedf_1;
  if (indexTmp_0d > 39.0) {
    indexTmp_0d = 39.0;
  } else {
    if (indexTmp_0d < 0.0) {
      indexTmp_0d = 0.0;
    }
  }

  bpIndex = static_cast<uint32_T>(indexTmp_0d);
  *rty_AeroBus_d = intrp1d_l_pwe(bpIndex, rtb_utoInfConstantsHeldfixedf_0,
    HL20_Aerodynamics_ConstP.Cn_tableData);

  // End of S-Function (sfun_kflookupnd): '<S7>/Cn'

  // S-Function (sfun_kflookupnd): '<S7>/Cx'
  indexTmp_0d = rtb_utoInfConstantsHeldfixedf_1;
  if (indexTmp_0d > 39.0) {
    indexTmp_0d = 39.0;
  } else {
    if (indexTmp_0d < 0.0) {
      indexTmp_0d = 0.0;
    }
  }

  bpIndex = static_cast<uint32_T>(indexTmp_0d);
  rtb_Product6 = intrp1d_l_pwe(bpIndex, rtb_utoInfConstantsHeldfixedf_0,
    HL20_Aerodynamics_ConstP.Cx_tableData);

  // End of S-Function (sfun_kflookupnd): '<S7>/Cx'

  // S-Function (sfun_kflookupnd): '<S7>/Cy'
  indexTmp_0d = rtb_utoInfConstantsHeldfixedf_1;
  if (indexTmp_0d > 39.0) {
    indexTmp_0d = 39.0;
  } else {
    if (indexTmp_0d < 0.0) {
      indexTmp_0d = 0.0;
    }
  }

  bpIndex = static_cast<uint32_T>(indexTmp_0d);
  rtb_Product2 = intrp1d_l_pwe(bpIndex, rtb_utoInfConstantsHeldfixedf_0,
    HL20_Aerodynamics_ConstP.Cy_tableData);

  // End of S-Function (sfun_kflookupnd): '<S7>/Cy'

  // S-Function (sfun_kflookupnd): '<S7>/Cz'
  if (rtb_utoInfConstantsHeldfixedf_1 > 39.0) {
    rtb_utoInfConstantsHeldfixedf_1 = 39.0;
  } else {
    if (rtb_utoInfConstantsHeldfixedf_1 < 0.0) {
      rtb_utoInfConstantsHeldfixedf_1 = 0.0;
    }
  }

  bpIndex = static_cast<uint32_T>(rtb_utoInfConstantsHeldfixedf_1);
  rtb_Product5_b = intrp1d_l_pwe(bpIndex, rtb_utoInfConstantsHeldfixedf_0,
    HL20_Aerodynamics_ConstP.Cz_tableData);

  // End of S-Function (sfun_kflookupnd): '<S7>/Cz'

  // S-Function (sfun_kflookupnd): '<S8>/Cm'
  indexTmp_0d_0 = static_cast<int32_T>(scalarIndex);
  if (indexTmp_0d_0 > 39) {
    indexTmp_0d_0 = 39;
  } else {
    if (indexTmp_0d_0 < 0) {
      indexTmp_0d_0 = 0;
    }
  }

  bpIndex = static_cast<uint32_T>(indexTmp_0d_0);
  *rty_AeroBus_c = intrp1d_l_pwe(bpIndex, scalarFraction,
    HL20_Aerodynamics_ConstP.Cm_tableData_j);

  // End of S-Function (sfun_kflookupnd): '<S8>/Cm'

  // S-Function (sfun_kflookupnd): '<S8>/Cx'
  indexTmp_0d_0 = static_cast<int32_T>(scalarIndex);
  if (indexTmp_0d_0 > 39) {
    indexTmp_0d_0 = 39;
  } else {
    if (indexTmp_0d_0 < 0) {
      indexTmp_0d_0 = 0;
    }
  }

  bpIndex = static_cast<uint32_T>(indexTmp_0d_0);
  *rty_AeroBus_k = intrp1d_l_pwe(bpIndex, scalarFraction,
    HL20_Aerodynamics_ConstP.Cx_tableData_b);

  // End of S-Function (sfun_kflookupnd): '<S8>/Cx'

  // S-Function (sfun_kflookupnd): '<S8>/Cz'
  indexTmp_0d_0 = static_cast<int32_T>(scalarIndex);
  if (indexTmp_0d_0 > 39) {
    indexTmp_0d_0 = 39;
  } else {
    if (indexTmp_0d_0 < 0) {
      indexTmp_0d_0 = 0;
    }
  }

  bpIndex = static_cast<uint32_T>(indexTmp_0d_0);
  *rty_AeroBus_m = intrp1d_l_pwe(bpIndex, scalarFraction,
    HL20_Aerodynamics_ConstP.Cz_tableData_o);

  // End of S-Function (sfun_kflookupnd): '<S8>/Cz'

  // Product: '<S8>/Product' incorporates:
  //   Constant: '<S8>/Constant1'

  rty_Actuator_Increments[0] = (*rty_AeroBus_k) * rtu_ActuatorDeflections;
  rty_Actuator_Increments[1] = rtCP_pooled3 * rtu_ActuatorDeflections;
  rty_Actuator_Increments[2] = (*rty_AeroBus_m) * rtu_ActuatorDeflections;
  rty_Actuator_Increments[3] = rtCP_pooled3 * rtu_ActuatorDeflections;
  rty_Actuator_Increments[4] = (*rty_AeroBus_c) * rtu_ActuatorDeflections;
  rty_Actuator_Increments[5] = rtCP_pooled3 * rtu_ActuatorDeflections;

  // Abs: '<S7>/Abs2'
  *rty_AeroBus_m = std::abs(rtu_ActuatorDeflections_e);

  // Product: '<S7>/Product1'
  *rty_AeroBus_m *= rtb_Product6;

  // Product: '<S7>/Product2'
  rtb_Product2 *= rtu_ActuatorDeflections_e;

  // Abs: '<S7>/Abs'
  *rty_AeroBus_k = std::abs(rtu_ActuatorDeflections_e);

  // Product: '<S7>/Product3'
  *rty_AeroBus_k *= rtb_Product5_b;

  // Product: '<S7>/Product4'
  *rty_AeroBus_c = rtu_ActuatorDeflections_e * (*rty_AeroBus);

  // Abs: '<S7>/Abs1'
  rtb_Product5_b = std::abs(rtu_ActuatorDeflections_e);

  // Product: '<S7>/Product5'
  rtb_Product5_b *= *rty_AeroBus_e;

  // Product: '<S7>/Product6'
  rtb_Product6 = rtu_ActuatorDeflections_e * (*rty_AeroBus_d);

  // Abs: '<S9>/Abs2'
  rtb_Product_bw = std::abs(rtu_ActuatorDeflections_d);

  // S-Function (sfun_kflookupnd): '<S9>/Cl'
  indexTmp_0d_0 = static_cast<int32_T>(scalarIndex);
  if (indexTmp_0d_0 > 39) {
    indexTmp_0d_0 = 39;
  } else {
    if (indexTmp_0d_0 < 0) {
      indexTmp_0d_0 = 0;
    }
  }

  bpIndex = static_cast<uint32_T>(indexTmp_0d_0);
  rtb_Product2_c = intrp1d_l_pwe(bpIndex, scalarFraction,
    HL20_Aerodynamics_ConstP.Cl_tableData_k);

  // End of S-Function (sfun_kflookupnd): '<S9>/Cl'

  // S-Function (sfun_kflookupnd): '<S9>/Cn'
  indexTmp_0d_0 = static_cast<int32_T>(scalarIndex);
  if (indexTmp_0d_0 > 39) {
    indexTmp_0d_0 = 39;
  } else {
    if (indexTmp_0d_0 < 0) {
      indexTmp_0d_0 = 0;
    }
  }

  bpIndex = static_cast<uint32_T>(indexTmp_0d_0);
  rtb_Product3_a = intrp1d_l_pwe(bpIndex, scalarFraction,
    HL20_Aerodynamics_ConstP.Cn_tableData_a);

  // End of S-Function (sfun_kflookupnd): '<S9>/Cn'

  // S-Function (sfun_kflookupnd): '<S9>/Cx'
  indexTmp_0d_0 = static_cast<int32_T>(scalarIndex);
  if (indexTmp_0d_0 > 39) {
    indexTmp_0d_0 = 39;
  } else {
    if (indexTmp_0d_0 < 0) {
      indexTmp_0d_0 = 0;
    }
  }

  bpIndex = static_cast<uint32_T>(indexTmp_0d_0);
  rtb_Product1 = intrp1d_l_pwe(bpIndex, scalarFraction,
    HL20_Aerodynamics_ConstP.Cx_tableData_p);

  // End of S-Function (sfun_kflookupnd): '<S9>/Cx'

  // Product: '<S9>/Product'
  rtb_Product_bw *= rtb_Product1;

  // S-Function (sfun_kflookupnd): '<S9>/Cy'
  indexTmp_0d_0 = static_cast<int32_T>(scalarIndex);
  if (indexTmp_0d_0 > 39) {
    indexTmp_0d_0 = 39;
  } else {
    if (indexTmp_0d_0 < 0) {
      indexTmp_0d_0 = 0;
    }
  }

  bpIndex = static_cast<uint32_T>(indexTmp_0d_0);
  rtb_Product1 = intrp1d_l_pwe(bpIndex, scalarFraction,
    HL20_Aerodynamics_ConstP.Cy_tableData_g);

  // End of S-Function (sfun_kflookupnd): '<S9>/Cy'

  // Product: '<S9>/Product1'
  rtb_Product1 *= rtu_ActuatorDeflections_d;

  // Product: '<S9>/Product2'
  rtb_Product2_c *= rtu_ActuatorDeflections_d;

  // Product: '<S9>/Product3'
  rtb_Product3_a *= rtu_ActuatorDeflections_d;

  // Abs: '<S12>/Abs2'
  rtb_Product2_o = std::abs(rtu_ActuatorDeflections_k);

  // Saturate: '<S12>/(0 to Inf) Constants Held fixed for alpha<0'
  if ((static_cast<real_T>(scalarIndex)) > rtCP_pooled3) {
    rtb_utoInfConstantsHeldfixedf_1 = static_cast<real_T>(scalarIndex);
  } else {
    rtb_utoInfConstantsHeldfixedf_1 = rtCP_pooled3;
  }

  if (scalarFraction > rtCP_pooled3) {
    rtb_utoInfConstantsHeldfixedf_0 = scalarFraction;
  } else {
    rtb_utoInfConstantsHeldfixedf_0 = rtCP_pooled3;
  }

  // End of Saturate: '<S12>/(0 to Inf) Constants Held fixed for alpha<0'

  // S-Function (sfun_kflookupnd): '<S10>/Cm'
  indexTmp_0d_0 = static_cast<int32_T>(scalarIndex);
  if (indexTmp_0d_0 > 39) {
    indexTmp_0d_0 = 39;
  } else {
    if (indexTmp_0d_0 < 0) {
      indexTmp_0d_0 = 0;
    }
  }

  bpIndex = static_cast<uint32_T>(indexTmp_0d_0);
  rtb_Cm_m = intrp1d_l_pwe(bpIndex, scalarFraction,
    HL20_Aerodynamics_ConstP.Cm_tableData_k);

  // End of S-Function (sfun_kflookupnd): '<S10>/Cm'

  // S-Function (sfun_kflookupnd): '<S10>/Cx'
  indexTmp_0d_0 = static_cast<int32_T>(scalarIndex);
  if (indexTmp_0d_0 > 39) {
    indexTmp_0d_0 = 39;
  } else {
    if (indexTmp_0d_0 < 0) {
      indexTmp_0d_0 = 0;
    }
  }

  bpIndex = static_cast<uint32_T>(indexTmp_0d_0);
  rtb_Cx_h = intrp1d_l_pwe(bpIndex, scalarFraction,
    HL20_Aerodynamics_ConstP.Cx_tableData_n);

  // End of S-Function (sfun_kflookupnd): '<S10>/Cx'

  // S-Function (sfun_kflookupnd): '<S10>/Cz'
  indexTmp_0d_0 = static_cast<int32_T>(scalarIndex);
  if (indexTmp_0d_0 > 39) {
    indexTmp_0d_0 = 39;
  } else {
    if (indexTmp_0d_0 < 0) {
      indexTmp_0d_0 = 0;
    }
  }

  bpIndex = static_cast<uint32_T>(indexTmp_0d_0);
  rtb_Cz_n = intrp1d_l_pwe(bpIndex, scalarFraction,
    HL20_Aerodynamics_ConstP.Cz_tableData_e);

  // End of S-Function (sfun_kflookupnd): '<S10>/Cz'

  // S-Function (sfun_kflookupnd): '<S11>/Cm'
  indexTmp_0d_0 = static_cast<int32_T>(scalarIndex);
  if (indexTmp_0d_0 > 39) {
    indexTmp_0d_0 = 39;
  } else {
    if (indexTmp_0d_0 < 0) {
      indexTmp_0d_0 = 0;
    }
  }

  bpIndex = static_cast<uint32_T>(indexTmp_0d_0);
  rtb_Cm_c = intrp1d_l_pwe(bpIndex, scalarFraction,
    HL20_Aerodynamics_ConstP.Cm_tableData_jp);

  // End of S-Function (sfun_kflookupnd): '<S11>/Cm'

  // S-Function (sfun_kflookupnd): '<S11>/Cx'
  indexTmp_0d_0 = static_cast<int32_T>(scalarIndex);
  if (indexTmp_0d_0 > 39) {
    indexTmp_0d_0 = 39;
  } else {
    if (indexTmp_0d_0 < 0) {
      indexTmp_0d_0 = 0;
    }
  }

  bpIndex = static_cast<uint32_T>(indexTmp_0d_0);
  rtb_Cx_m = intrp1d_l_pwe(bpIndex, scalarFraction,
    HL20_Aerodynamics_ConstP.Cx_tableData_f);

  // End of S-Function (sfun_kflookupnd): '<S11>/Cx'

  // S-Function (sfun_kflookupnd): '<S11>/Cz'
  if (scalarIndex > 39) {
    scalarIndex = 39;
  } else {
    if (scalarIndex < 0) {
      scalarIndex = 0;
    }
  }

  bpIndex = static_cast<uint32_T>(scalarIndex);
  rtb_Cz_b = intrp1d_l_pwe(bpIndex, scalarFraction,
    HL20_Aerodynamics_ConstP.Cz_tableData_a);

  // End of S-Function (sfun_kflookupnd): '<S11>/Cz'

  // S-Function (sfun_kflookupnd): '<S12>/Cl'
  indexTmp_0d = rtb_utoInfConstantsHeldfixedf_1;
  if (indexTmp_0d > 39.0) {
    indexTmp_0d = 39.0;
  } else {
    if (indexTmp_0d < 0.0) {
      indexTmp_0d = 0.0;
    }
  }

  bpIndex = static_cast<uint32_T>(indexTmp_0d);
  *rty_AeroBus_d1 = intrp1d_l_pwe(bpIndex, rtb_utoInfConstantsHeldfixedf_0,
    HL20_Aerodynamics_ConstP.Cl_tableData_f);

  // End of S-Function (sfun_kflookupnd): '<S12>/Cl'

  // S-Function (sfun_kflookupnd): '<S12>/Cm'
  indexTmp_0d = rtb_utoInfConstantsHeldfixedf_1;
  if (indexTmp_0d > 39.0) {
    indexTmp_0d = 39.0;
  } else {
    if (indexTmp_0d < 0.0) {
      indexTmp_0d = 0.0;
    }
  }

  bpIndex = static_cast<uint32_T>(indexTmp_0d);
  *rty_AeroBus_dt = intrp1d_l_pwe(bpIndex, rtb_utoInfConstantsHeldfixedf_0,
    HL20_Aerodynamics_ConstP.Cm_tableData_p);

  // End of S-Function (sfun_kflookupnd): '<S12>/Cm'

  // S-Function (sfun_kflookupnd): '<S12>/Cn'
  indexTmp_0d = rtb_utoInfConstantsHeldfixedf_1;
  if (indexTmp_0d > 39.0) {
    indexTmp_0d = 39.0;
  } else {
    if (indexTmp_0d < 0.0) {
      indexTmp_0d = 0.0;
    }
  }

  bpIndex = static_cast<uint32_T>(indexTmp_0d);
  *rty_AeroBus_e5 = intrp1d_l_pwe(bpIndex, rtb_utoInfConstantsHeldfixedf_0,
    HL20_Aerodynamics_ConstP.Cn_tableData_h);

  // End of S-Function (sfun_kflookupnd): '<S12>/Cn'

  // S-Function (sfun_kflookupnd): '<S12>/Cx'
  indexTmp_0d = rtb_utoInfConstantsHeldfixedf_1;
  if (indexTmp_0d > 39.0) {
    indexTmp_0d = 39.0;
  } else {
    if (indexTmp_0d < 0.0) {
      indexTmp_0d = 0.0;
    }
  }

  bpIndex = static_cast<uint32_T>(indexTmp_0d);
  indexTmp_0d = intrp1d_l_pwe(bpIndex, rtb_utoInfConstantsHeldfixedf_0,
    HL20_Aerodynamics_ConstP.Cx_tableData_o);

  // End of S-Function (sfun_kflookupnd): '<S12>/Cx'

  // Product: '<S12>/Product2'
  rtb_Product2_o *= indexTmp_0d;

  // S-Function (sfun_kflookupnd): '<S12>/Cy'
  indexTmp_0d = rtb_utoInfConstantsHeldfixedf_1;
  if (indexTmp_0d > 39.0) {
    indexTmp_0d = 39.0;
  } else {
    if (indexTmp_0d < 0.0) {
      indexTmp_0d = 0.0;
    }
  }

  bpIndex = static_cast<uint32_T>(indexTmp_0d);
  indexTmp_0d = intrp1d_l_pwe(bpIndex, rtb_utoInfConstantsHeldfixedf_0,
    HL20_Aerodynamics_ConstP.Cy_tableData_h);

  // End of S-Function (sfun_kflookupnd): '<S12>/Cy'

  // Product: '<S12>/Product3'
  indexTmp_0d *= rtu_ActuatorDeflections_k;

  // Abs: '<S12>/Abs1'
  scalarFraction = std::abs(rtu_ActuatorDeflections_k);

  // S-Function (sfun_kflookupnd): '<S12>/Cz'
  if (rtb_utoInfConstantsHeldfixedf_1 > 39.0) {
    rtb_utoInfConstantsHeldfixedf_1 = 39.0;
  } else {
    if (rtb_utoInfConstantsHeldfixedf_1 < 0.0) {
      rtb_utoInfConstantsHeldfixedf_1 = 0.0;
    }
  }

  bpIndex = static_cast<uint32_T>(rtb_utoInfConstantsHeldfixedf_1);
  rtb_utoInfConstantsHeldfixedf_1 = intrp1d_l_pwe(bpIndex,
    rtb_utoInfConstantsHeldfixedf_0, HL20_Aerodynamics_ConstP.Cz_tableData_c);

  // End of S-Function (sfun_kflookupnd): '<S12>/Cz'

  // Product: '<S12>/Product4'
  scalarFraction *= rtb_utoInfConstantsHeldfixedf_1;

  // Product: '<S12>/Product5'
  rtb_utoInfConstantsHeldfixedf_1 = rtu_ActuatorDeflections_k * (*rty_AeroBus_d1);

  // Abs: '<S12>/Abs3'
  rtb_utoInfConstantsHeldfixedf_0 = std::abs(rtu_ActuatorDeflections_k);

  // Product: '<S12>/Product6'
  rtb_utoInfConstantsHeldfixedf_0 *= *rty_AeroBus_dt;

  // Product: '<S12>/Product7'
  rtb_Product7 = rtu_ActuatorDeflections_k * (*rty_AeroBus_e5);

  // Product: '<S10>/Product' incorporates:
  //   Constant: '<S10>/Constant1'
  //   Constant: '<S10>/Constant2'
  //   Constant: '<S10>/Constant3'

  rtb_Product[0] = rtb_Cx_h * rtu_ActuatorDeflections_m;
  rtb_Product[1] = rtCP_pooled3 * rtu_ActuatorDeflections_m;
  rtb_Product[2] = rtb_Cz_n * rtu_ActuatorDeflections_m;
  rtb_Product[3] = rtCP_pooled3 * rtu_ActuatorDeflections_m;
  rtb_Product[4] = rtb_Cm_m * rtu_ActuatorDeflections_m;
  rtb_Product[5] = rtCP_pooled3 * rtu_ActuatorDeflections_m;

  // Product: '<S11>/Product' incorporates:
  //   Constant: '<S11>/Constant1'
  //   Constant: '<S11>/Constant2'
  //   Constant: '<S11>/Constant3'

  rtb_Product_d[0] = rtb_Cx_m * rtu_ActuatorDeflections_c;
  rtb_Product_d[1] = rtCP_pooled3 * rtu_ActuatorDeflections_c;
  rtb_Product_d[2] = rtb_Cz_b * rtu_ActuatorDeflections_c;
  rtb_Product_d[3] = rtCP_pooled3 * rtu_ActuatorDeflections_c;
  rtb_Product_d[4] = rtb_Cm_c * rtu_ActuatorDeflections_c;
  rtb_Product_d[5] = rtCP_pooled3 * rtu_ActuatorDeflections_c;

  // Sum: '<S4>/Sum' incorporates:
  //   Constant: '<S9>/Constant1'

  rtb_Cm_m = rty_Actuator_Increments[0];
  rtb_Cx_h = rty_Actuator_Increments[1];
  rtb_Cz_n = rty_Actuator_Increments[2];
  rtb_Cm_c = rty_Actuator_Increments[3];
  rtb_Cx_m = rty_Actuator_Increments[4];
  rtb_Cz_b = rty_Actuator_Increments[5];
  rty_AeroBus_m_0[0] = (*rty_AeroBus_m) + rtb_Cm_m;
  rty_AeroBus_m_0[1] = rtb_Product2 + rtb_Cx_h;
  rty_AeroBus_m_0[2] = (*rty_AeroBus_k) + rtb_Cz_n;
  rty_AeroBus_m_0[3] = (*rty_AeroBus_c) + rtb_Cm_c;
  rty_AeroBus_m_0[4] = rtb_Product5_b + rtb_Cx_m;
  rty_AeroBus_m_0[5] = rtb_Product6 + rtb_Cz_b;
  rtb_Product2_c_0[0] = rtb_Product2_o;
  rtb_Product2_c_0[1] = indexTmp_0d;
  rtb_Product2_c_0[2] = scalarFraction;
  rtb_Product2_c_0[3] = rtb_utoInfConstantsHeldfixedf_1;
  rtb_Product2_c_0[4] = rtb_utoInfConstantsHeldfixedf_0;
  rtb_Product2_c_0[5] = rtb_Product7;
  rtb_Product_a[0] = rtb_Product_bw;
  rtb_Product_a[1] = rtb_Product1;
  rtb_Product_a[2] = rtCP_pooled3;
  rtb_Product_a[3] = rtb_Product2_c;
  rtb_Product_a[4] = rtCP_pooled3;
  rtb_Product_a[5] = rtb_Product3_a;
  for (scalarIndex = 0; scalarIndex < 6; scalarIndex++) {
    rty_Actuator_Increments[scalarIndex] = (((rty_AeroBus_m_0[scalarIndex] +
      rtb_Product2_c_0[scalarIndex]) + rtb_Product_d[scalarIndex]) +
      rtb_Product[scalarIndex]) + rtb_Product_a[scalarIndex];
  }

  // End of Sum: '<S4>/Sum'
}

// Output and update for atomic system: '<S2>/Body_Rate_Damping'
void HL20_AerodynamicsModelClass::HL20_Aerodyna_Body_Rate_Damping(real_T rtu_V,
  const real_T rtu_wb_bn_body[3], real_T rtu_Alpha, real_T
  rty_Body_Rate_Damping_Coefs[6], DW_Body_Rate_Damping_HL20_Aer_T *localDW)
{
  real_T rtb_ReferenceLength[6];
  real_T rtb_ReferenceSpan[6];
  real_T rtb_Cl_i;
  real_T rtb_Cnr;
  real_T scalarFraction;
  int32_T indexTmp_0d;
  int_T scalarIndex;
  uint32_T bpIndex;

  // S-Function (sfun_idxsearch): '<S5>/AlphaLookup'
  scalarIndex = static_cast<int_T>(plook_s32dd_binxp(rtu_Alpha,
    HL20_Aerodynamics_ConstP.AlphaLookup_bpData, 10U, &scalarFraction,
    &localDW->AlphaLookup_MODE));

  // S-Function (sfun_kflookupnd): '<S13>/Cl'
  indexTmp_0d = static_cast<int32_T>(scalarIndex);
  if (indexTmp_0d > 9) {
    indexTmp_0d = 9;
  } else {
    if (indexTmp_0d < 0) {
      indexTmp_0d = 0;
    }
  }

  bpIndex = static_cast<uint32_T>(indexTmp_0d);
  rtb_Cnr = intrp1d_l_pwe(bpIndex, scalarFraction,
    HL20_Aerodynamics_ConstP.Cl_tableData_j);

  // End of S-Function (sfun_kflookupnd): '<S13>/Cl'

  // S-Function (sfun_kflookupnd): '<S13>/Cn'
  indexTmp_0d = static_cast<int32_T>(scalarIndex);
  if (indexTmp_0d > 9) {
    indexTmp_0d = 9;
  } else {
    if (indexTmp_0d < 0) {
      indexTmp_0d = 0;
    }
  }

  bpIndex = static_cast<uint32_T>(indexTmp_0d);
  rtb_Cl_i = intrp1d_l_pwe(bpIndex, scalarFraction,
    HL20_Aerodynamics_ConstP.Cn_tableData_i);

  // End of S-Function (sfun_kflookupnd): '<S13>/Cn'

  // Product: '<S5>/Product' incorporates:
  //   Constant: '<S13>/Constant1'

  rty_Body_Rate_Damping_Coefs[0] = rtCP_pooled3 * rtu_wb_bn_body[0];
  rty_Body_Rate_Damping_Coefs[1] = rtCP_pooled3 * rtu_wb_bn_body[0];
  rty_Body_Rate_Damping_Coefs[2] = rtCP_pooled3 * rtu_wb_bn_body[0];
  rty_Body_Rate_Damping_Coefs[3] = rtb_Cnr * rtu_wb_bn_body[0];
  rty_Body_Rate_Damping_Coefs[4] = rtCP_pooled3 * rtu_wb_bn_body[0];
  rty_Body_Rate_Damping_Coefs[5] = rtb_Cl_i * rtu_wb_bn_body[0];

  // S-Function (sfun_kflookupnd): '<S14>/Cmq'
  indexTmp_0d = static_cast<int32_T>(scalarIndex);
  if (indexTmp_0d > 9) {
    indexTmp_0d = 9;
  } else {
    if (indexTmp_0d < 0) {
      indexTmp_0d = 0;
    }
  }

  bpIndex = static_cast<uint32_T>(indexTmp_0d);
  rtb_Cl_i = intrp1d_l_pwe(bpIndex, scalarFraction,
    HL20_Aerodynamics_ConstP.Cmq_tableData);

  // End of S-Function (sfun_kflookupnd): '<S14>/Cmq'

  // Product: '<S5>/Product1' incorporates:
  //   Constant: '<S14>/Constant3'

  rtb_ReferenceLength[0] = rtCP_pooled3 * rtu_wb_bn_body[1];
  rtb_ReferenceLength[1] = rtCP_pooled3 * rtu_wb_bn_body[1];
  rtb_ReferenceLength[2] = rtCP_pooled3 * rtu_wb_bn_body[1];
  rtb_ReferenceLength[3] = rtCP_pooled3 * rtu_wb_bn_body[1];
  rtb_ReferenceLength[4] = rtb_Cl_i * rtu_wb_bn_body[1];
  rtb_ReferenceLength[5] = rtCP_pooled3 * rtu_wb_bn_body[1];

  // S-Function (sfun_kflookupnd): '<S15>/Clr'
  indexTmp_0d = static_cast<int32_T>(scalarIndex);
  if (indexTmp_0d > 9) {
    indexTmp_0d = 9;
  } else {
    if (indexTmp_0d < 0) {
      indexTmp_0d = 0;
    }
  }

  bpIndex = static_cast<uint32_T>(indexTmp_0d);
  rtb_Cl_i = intrp1d_l_pwe(bpIndex, scalarFraction,
    HL20_Aerodynamics_ConstP.Clr_tableData);

  // End of S-Function (sfun_kflookupnd): '<S15>/Clr'

  // S-Function (sfun_kflookupnd): '<S15>/Cnr'
  if (scalarIndex > 9) {
    scalarIndex = 9;
  } else {
    if (scalarIndex < 0) {
      scalarIndex = 0;
    }
  }

  bpIndex = static_cast<uint32_T>(scalarIndex);
  rtb_Cnr = intrp1d_l_pwe(bpIndex, scalarFraction,
    HL20_Aerodynamics_ConstP.Cnr_tableData);

  // End of S-Function (sfun_kflookupnd): '<S15>/Cnr'

  // Product: '<S5>/Product2' incorporates:
  //   Constant: '<S15>/Constant'

  rtb_ReferenceSpan[0] = rtCP_pooled3 * rtu_wb_bn_body[2];
  rtb_ReferenceSpan[1] = rtCP_pooled3 * rtu_wb_bn_body[2];
  rtb_ReferenceSpan[2] = rtCP_pooled3 * rtu_wb_bn_body[2];
  rtb_ReferenceSpan[3] = rtb_Cl_i * rtu_wb_bn_body[2];
  rtb_ReferenceSpan[4] = rtCP_pooled3 * rtu_wb_bn_body[2];
  rtb_ReferenceSpan[5] = rtb_Cnr * rtu_wb_bn_body[2];
  for (scalarIndex = 0; scalarIndex < 6; scalarIndex++) {
    // Gain: '<S5>/Reference Length'
    scalarFraction = rtb_ReferenceLength[scalarIndex];

    // Gain: '<S5>/Reference Span '
    rtb_Cnr = rtb_ReferenceSpan[scalarIndex];

    // Gain: '<S5>/Reference Span'
    rty_Body_Rate_Damping_Coefs[scalarIndex] *= rtCP_pooled4;

    // Gain: '<S5>/Reference Length'
    scalarFraction *= rtCP_ReferenceLength_Gain;

    // Gain: '<S5>/Reference Span '
    rtb_Cnr *= rtCP_pooled4;

    // Sum: '<S5>/Sum1'
    rty_Body_Rate_Damping_Coefs[scalarIndex] =
      (rty_Body_Rate_Damping_Coefs[scalarIndex] + scalarFraction) + rtb_Cnr;

    // Product: '<S5>/Product3'
    rty_Body_Rate_Damping_Coefs[scalarIndex] /= rtu_V;

    // Gain: '<S5>/Reference Span '
    rtb_ReferenceSpan[scalarIndex] = rtb_Cnr;

    // Gain: '<S5>/Reference Length'
    rtb_ReferenceLength[scalarIndex] = scalarFraction;
  }
}

// Output and update for atomic system: '<S2>/Datum_Coefficients'
void HL20_AerodynamicsModelClass::HL20_Aerodyn_Datum_Coefficients(real_T
  rtu_Alpha, real_T rtu_Beta, real_T *rty_DatumCoefs, real_T *rty_DatumCoefs_o,
  real_T *rty_DatumCoefs_f, real_T *rty_DatumCoefs_i, real_T *rty_DatumCoefs_iy,
  real_T *rty_DatumCoefs_c, DW_Datum_Coefficients_HL20_Ae_T *localDW)
{
  real_T frac[2];
  real_T frac_0[2];
  real_T frac_1[2];
  real_T scalarFraction;
  real_T scalarFraction_0;
  int32_T indexTmp_0d;
  int_T scalarIndex;
  int_T scalarIndex_0;
  uint32_T bpIndex[2];
  uint32_T bpIndex_0[2];
  uint32_T bpIndex_1[2];

  // S-Function (sfun_idxsearch): '<S6>/AlphaLookup'
  scalarIndex = static_cast<int_T>(plook_s32dd_binxp(rtu_Alpha,
    HL20_Aerodynamics_ConstP.pooled2, 40U, &scalarFraction,
    &localDW->AlphaLookup_MODE));

  // S-Function (sfun_idxsearch): '<S6>/BetaLookup'
  scalarIndex_0 = static_cast<int_T>(plook_s32dd_binxp(rtu_Beta,
    HL20_Aerodynamics_ConstP.BetaLookup_bpData, 20U, &scalarFraction_0,
    &localDW->BetaLookup_MODE));

  // S-Function (sfun_kflookupnd): '<S6>/Cm'
  frac[0] = scalarFraction;
  frac[1] = scalarFraction_0;
  indexTmp_0d = static_cast<int32_T>(scalarIndex);
  if (indexTmp_0d > 39) {
    indexTmp_0d = 39;
  } else {
    if (indexTmp_0d < 0) {
      indexTmp_0d = 0;
    }
  }

  bpIndex[0] = static_cast<uint32_T>(indexTmp_0d);
  indexTmp_0d = static_cast<int32_T>(scalarIndex_0);
  if (indexTmp_0d > 19) {
    indexTmp_0d = 19;
  } else {
    if (indexTmp_0d < 0) {
      indexTmp_0d = 0;
    }
  }

  bpIndex[1] = static_cast<uint32_T>(indexTmp_0d);
  *rty_DatumCoefs_iy = intrp2d_l_pwe(bpIndex, frac,
    HL20_Aerodynamics_ConstP.Cm_tableData_i, 41U);

  // End of S-Function (sfun_kflookupnd): '<S6>/Cm'

  // S-Function (sfun_kflookupnd): '<S6>/Cx'
  frac_0[0] = scalarFraction;
  frac_0[1] = scalarFraction_0;
  indexTmp_0d = static_cast<int32_T>(scalarIndex);
  if (indexTmp_0d > 39) {
    indexTmp_0d = 39;
  } else {
    if (indexTmp_0d < 0) {
      indexTmp_0d = 0;
    }
  }

  bpIndex_0[0] = static_cast<uint32_T>(indexTmp_0d);
  indexTmp_0d = static_cast<int32_T>(scalarIndex_0);
  if (indexTmp_0d > 19) {
    indexTmp_0d = 19;
  } else {
    if (indexTmp_0d < 0) {
      indexTmp_0d = 0;
    }
  }

  bpIndex_0[1] = static_cast<uint32_T>(indexTmp_0d);
  *rty_DatumCoefs = intrp2d_l_pwe(bpIndex_0, frac_0,
    HL20_Aerodynamics_ConstP.Cx_tableData_a, 41U);

  // End of S-Function (sfun_kflookupnd): '<S6>/Cx'

  // S-Function (sfun_kflookupnd): '<S6>/Cz'
  frac_1[0] = scalarFraction;
  frac_1[1] = scalarFraction_0;
  if (scalarIndex > 39) {
    scalarIndex = 39;
  } else {
    if (scalarIndex < 0) {
      scalarIndex = 0;
    }
  }

  bpIndex_1[0] = static_cast<uint32_T>(scalarIndex);
  if (scalarIndex_0 > 19) {
    scalarIndex_0 = 19;
  } else {
    if (scalarIndex_0 < 0) {
      scalarIndex_0 = 0;
    }
  }

  bpIndex_1[1] = static_cast<uint32_T>(scalarIndex_0);
  *rty_DatumCoefs_f = intrp2d_l_pwe(bpIndex_1, frac_1,
    HL20_Aerodynamics_ConstP.Cz_tableData_b, 41U);

  // End of S-Function (sfun_kflookupnd): '<S6>/Cz'

  // Abs: '<S6>/Abs'
  *rty_DatumCoefs_c = std::abs(rtu_Beta);

  // Lookup_n-D: '<S6>/ Cn'
  *rty_DatumCoefs_c = look2_binlxpw(rtu_Alpha, *rty_DatumCoefs_c,
    HL20_Aerodynamics_ConstP.Cn_bp01Data, HL20_Aerodynamics_ConstP.Cn_bp02Data,
    HL20_Aerodynamics_ConstP.Cn_tableData_l,
    HL20_Aerodynamics_ConstP.Cn_maxIndex, 9U);

  // Signum: '<S6>/Sign'
  if (rtu_Beta < 0.0) {
    *rty_DatumCoefs_i = -1.0;
  } else if (rtu_Beta > 0.0) {
    *rty_DatumCoefs_i = 1.0;
  } else {
    *rty_DatumCoefs_i = rtu_Beta;
  }

  // End of Signum: '<S6>/Sign'

  // Product: '<S6>/Product'
  *rty_DatumCoefs_c *= *rty_DatumCoefs_i;

  // Gain: '<S6>/Cl'
  *rty_DatumCoefs_i = rtCP_Cl_Gain * rtu_Beta;

  // Gain: '<S6>/Cy'
  *rty_DatumCoefs_o = rtCP_Cy_Gain * rtu_Beta;
}

// Output and update for atomic system: '<S1>/Aerodynamic_Coefficients'
void HL20_AerodynamicsModelClass::HL20_A_Aerodynamic_Coefficients(real_T
  rtu_Actuators, real_T rtu_Actuators_f, real_T rtu_Actuators_c, real_T
  rtu_Actuators_f2, real_T rtu_Actuators_k, real_T rtu_Actuators_l, real_T
  rtu_airspeed, const real_T rtu_wb_bn_body[3], real_T rtu_Alpha, real_T
  rtu_Beta, real_T rty_AeroCoefs[6], B_Aerodynamic_Coefficients_HL_T *localB,
  DW_Aerodynamic_Coefficients_H_T *localDW)
{
  real_T rtb_Actuator_Increments[6];
  real_T rtb_Cl;
  real_T rtb_Cm;
  real_T rtb_Cn;
  real_T rtb_Cx;
  real_T rtb_Cy;
  real_T rtb_Cz;
  real_T rty_AeroCoefs_0;
  real_T rty_AeroCoefs_1;
  real_T rty_AeroCoefs_2;
  real_T rty_AeroCoefs_3;
  real_T rty_AeroCoefs_4;
  real_T rty_AeroCoefs_5;

  // Gain: '<S2>/r-->d2'
  localB->alpha_deg = rtCP_pooled5 * rtu_Alpha;

  // Outputs for Atomic SubSystem: '<S2>/Actuator_Increments'
  HL20_Aerody_Actuator_Increments(localB->alpha_deg, rtu_Actuators,
    rtu_Actuators_f, rtu_Actuators_c, rtu_Actuators_f2, rtu_Actuators_k,
    rtu_Actuators_l, rtb_Actuator_Increments, &rtb_Cy, &rtb_Cl, &rtb_Cn, &rtb_Cx,
    &rtb_Cm, &rtb_Cz, &rtb_Cy, &rtb_Cl, &rtb_Cn, &localDW->Actuator_Increments);

  // End of Outputs for SubSystem: '<S2>/Actuator_Increments'

  // Outputs for Atomic SubSystem: '<S2>/Body_Rate_Damping'
  HL20_Aerodyna_Body_Rate_Damping(rtu_airspeed, rtu_wb_bn_body,
    localB->alpha_deg, rty_AeroCoefs, &localDW->Body_Rate_Damping);

  // End of Outputs for SubSystem: '<S2>/Body_Rate_Damping'

  // Gain: '<S2>/r-->d1'
  localB->beta_deg = rtCP_pooled5 * rtu_Beta;

  // Outputs for Atomic SubSystem: '<S2>/Datum_Coefficients'
  HL20_Aerodyn_Datum_Coefficients(localB->alpha_deg, localB->beta_deg, &rtb_Cx,
    &rtb_Cy, &rtb_Cz, &rtb_Cl, &rtb_Cm, &rtb_Cn, &localDW->Datum_Coefficients);

  // End of Outputs for SubSystem: '<S2>/Datum_Coefficients'

  // Sum: '<S2>/Sum1'
  rty_AeroCoefs_0 = rty_AeroCoefs[0];
  rty_AeroCoefs_1 = rty_AeroCoefs[1];
  rty_AeroCoefs_2 = rty_AeroCoefs[2];
  rty_AeroCoefs_3 = rty_AeroCoefs[3];
  rty_AeroCoefs_4 = rty_AeroCoefs[4];
  rty_AeroCoefs_5 = rty_AeroCoefs[5];
  rty_AeroCoefs[0] = (rty_AeroCoefs_0 + rtb_Cx) + rtb_Actuator_Increments[0];
  rty_AeroCoefs[1] = (rty_AeroCoefs_1 + rtb_Cy) + rtb_Actuator_Increments[1];
  rty_AeroCoefs[2] = (rty_AeroCoefs_2 + rtb_Cz) + rtb_Actuator_Increments[2];
  rty_AeroCoefs[3] = (rty_AeroCoefs_3 + rtb_Cl) + rtb_Actuator_Increments[3];
  rty_AeroCoefs[4] = (rty_AeroCoefs_4 + rtb_Cm) + rtb_Actuator_Increments[4];
  rty_AeroCoefs[5] = (rty_AeroCoefs_5 + rtb_Cn) + rtb_Actuator_Increments[5];
}

// Output and update for atomic system: '<S1>/Forces_Moments'
void HL20_AerodynamicsModelClass::HL20_Aerodynamic_Forces_Moments(const real_T
  rtu_Coeff[6], real_T rtu_qbar, real_T rty_ftot_body[3], real_T rty_mtot_body[3])
{
  real_T rtb_Product3_idx_0;
  real_T rtb_Product3_idx_1;
  real_T rtb_Product3_idx_2;
  real_T rtb_ixj;
  real_T rtb_ixk;
  real_T rtb_jxi;
  real_T rtb_jxk;
  real_T rtb_kxi;
  real_T rtb_kxj;

  // Gain: '<S3>/reference area'
  rtb_ixj = rtCP_referencearea_Gain * rtu_qbar;

  // Product: '<S3>/Product'
  rty_ftot_body[0] = rtu_Coeff[0] * rtb_ixj;

  // Gain: '<S3>/reference length'
  rtb_Product3_idx_2 = rtCP_referencelength_Gain_EL_0 * rtb_ixj;

  // Product: '<S3>/Product3'
  rtb_Product3_idx_2 *= rtu_Coeff[3];

  // Gain: '<S3>/reference length'
  rtb_Product3_idx_0 = rtb_Product3_idx_2;

  // Product: '<S3>/Product'
  rty_ftot_body[1] = rtu_Coeff[1] * rtb_ixj;

  // Gain: '<S3>/reference length'
  rtb_Product3_idx_2 = rtCP_referencelength_Gain_EL_1 * rtb_ixj;

  // Product: '<S3>/Product3'
  rtb_Product3_idx_2 *= rtu_Coeff[4];

  // Gain: '<S3>/reference length'
  rtb_Product3_idx_1 = rtb_Product3_idx_2;

  // Product: '<S3>/Product'
  rty_ftot_body[2] = rtu_Coeff[2] * rtb_ixj;

  // Gain: '<S3>/reference length'
  rtb_Product3_idx_2 = rtCP_referencelength_Gain_EL_2 * rtb_ixj;

  // Product: '<S3>/Product3'
  rtb_Product3_idx_2 *= rtu_Coeff[5];

  // Product: '<S17>/i x j' incorporates:
  //   Constant: '<S3>/Moments about Center of Gravity'

  rtb_ixj = rty_ftot_body[0] * rtCP_MomentsaboutCenterofG_EL_1;

  // Product: '<S17>/j x k' incorporates:
  //   Constant: '<S3>/Moments about Center of Gravity'

  rtb_jxk = rty_ftot_body[1] * rtCP_MomentsaboutCenterofG_EL_2;

  // Product: '<S17>/k x i' incorporates:
  //   Constant: '<S3>/Moments about Center of Gravity'

  rtb_kxi = rty_ftot_body[2] * rtCP_MomentsaboutCenterofG_EL_0;

  // Product: '<S18>/i x k' incorporates:
  //   Constant: '<S3>/Moments about Center of Gravity'

  rtb_ixk = rty_ftot_body[0] * rtCP_MomentsaboutCenterofG_EL_2;

  // Product: '<S18>/j x i' incorporates:
  //   Constant: '<S3>/Moments about Center of Gravity'

  rtb_jxi = rty_ftot_body[1] * rtCP_MomentsaboutCenterofG_EL_0;

  // Product: '<S18>/k x j' incorporates:
  //   Constant: '<S3>/Moments about Center of Gravity'

  rtb_kxj = rty_ftot_body[2] * rtCP_MomentsaboutCenterofG_EL_1;

  // Sum: '<S16>/Sum'
  rty_mtot_body[0] = rtb_jxk - rtb_kxj;
  rty_mtot_body[1] = rtb_kxi - rtb_ixk;
  rty_mtot_body[2] = rtb_ixj - rtb_jxi;

  // Sum: '<S3>/Sum1'
  rty_mtot_body[0] += rtb_Product3_idx_0;
  rty_mtot_body[1] += rtb_Product3_idx_1;
  rty_mtot_body[2] += rtb_Product3_idx_2;
}

// Model step function
void HL20_AerodynamicsModelClass::step()
{
  real_T rtb_AeroCoefs[6];

  // Outputs for Atomic SubSystem: '<S1>/Aerodynamic_Coefficients'

  // Inport: '<Root>/Actuators' incorporates:
  //   Inport: '<Root>/Alpha'
  //   Inport: '<Root>/Beta'
  //   Inport: '<Root>/airspeed'
  //   Inport: '<Root>/wb_bn_body'

  HL20_A_Aerodynamic_Coefficients(HL20_Aerodynamics_U.Actuators.Elevator,
    HL20_Aerodynamics_U.Actuators.Aileron,
    HL20_Aerodynamics_U.Actuators.Flap_Dif, HL20_Aerodynamics_U.Actuators.Rudder,
    HL20_Aerodynamics_U.Actuators.Flap_Neg,
    HL20_Aerodynamics_U.Actuators.Flap_Pos, HL20_Aerodynamics_U.airspeed,
    HL20_Aerodynamics_U.wb_bn_body, HL20_Aerodynamics_U.Alpha,
    HL20_Aerodynamics_U.Beta, rtb_AeroCoefs,
    &HL20_Aerodynamics_B.Aerodynamic_Coefficients,
    &HL20_Aerodynamics_DW.Aerodynamic_Coefficients);

  // End of Outputs for SubSystem: '<S1>/Aerodynamic_Coefficients'

  // Outputs for Atomic SubSystem: '<S1>/Forces_Moments'

  // Inport: '<Root>/qbar' incorporates:
  //   Outport: '<Root>/ftot_body'
  //   Outport: '<Root>/mtot_body'

  HL20_Aerodynamic_Forces_Moments(rtb_AeroCoefs, HL20_Aerodynamics_U.qbar,
    HL20_Aerodynamics_Y.ftot_body, HL20_Aerodynamics_Y.mtot_body);

  // End of Outputs for SubSystem: '<S1>/Forces_Moments'
}

// Model initialize function
void HL20_AerodynamicsModelClass::initialize()
{
  // (no initialization code required)
}

// Model terminate function
void HL20_AerodynamicsModelClass::terminate()
{
  // (no terminate code required)
}

// Constructor
HL20_AerodynamicsModelClass::HL20_AerodynamicsModelClass() :
  HL20_Aerodynamics_U(),
  HL20_Aerodynamics_Y(),
  HL20_Aerodynamics_B(),
  HL20_Aerodynamics_DW(),
  HL20_Aerodynamics_M()
{
  // Currently there is no constructor body generated.
}

// Destructor
HL20_AerodynamicsModelClass::~HL20_AerodynamicsModelClass()
{
  // Currently there is no destructor body generated.
}

// Real-Time Model get method
HL20_AerodynamicsModelClass::RT_MODEL_HL20_Aerodynamics_T
  * HL20_AerodynamicsModelClass::getRTM()
{
  return (&HL20_Aerodynamics_M);
}

//
// File trailer for generated code.
//
// [EOF]
//
