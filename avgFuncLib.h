//
// MATLAB Compiler: 8.4 (R2022a)
// Date: Sun May 29 16:36:08 2022
// Arguments:
// "-B""macro_default""-W""cpplib:avgFuncLib,all""-T""link:lib""avgFunc.m"
//

#ifndef avgFuncLib_h
#define avgFuncLib_h 1

#if defined(__cplusplus) && !defined(mclmcrrt_h) && defined(__linux__)
#  pragma implementation "mclmcrrt.h"
#endif
#include "mclmcrrt.h"
#include "mclcppclass.h"
#ifdef __cplusplus
extern "C" { // sbcheck:ok:extern_c
#endif

/* This symbol is defined in shared libraries. Define it here
 * (to nothing) in case this isn't a shared library. 
 */
#ifndef LIB_avgFuncLib_C_API 
#define LIB_avgFuncLib_C_API /* No special import/export declaration */
#endif

/* GENERAL LIBRARY FUNCTIONS -- START */

extern LIB_avgFuncLib_C_API 
bool MW_CALL_CONV avgFuncLibInitializeWithHandlers(
       mclOutputHandlerFcn error_handler, 
       mclOutputHandlerFcn print_handler);

extern LIB_avgFuncLib_C_API 
bool MW_CALL_CONV avgFuncLibInitialize(void);

extern LIB_avgFuncLib_C_API 
void MW_CALL_CONV avgFuncLibTerminate(void);

extern LIB_avgFuncLib_C_API 
void MW_CALL_CONV avgFuncLibPrintStackTrace(void);

/* GENERAL LIBRARY FUNCTIONS -- END */

/* C INTERFACE -- MLX WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- START */

extern LIB_avgFuncLib_C_API 
bool MW_CALL_CONV mlxAvgFunc(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[]);

/* C INTERFACE -- MLX WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- END */

#ifdef __cplusplus
}
#endif


/* C++ INTERFACE -- WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- START */

#ifdef __cplusplus

/* On Windows, use __declspec to control the exported API */
#if defined(_MSC_VER) || defined(__MINGW64__)

#ifdef EXPORTING_avgFuncLib
#define PUBLIC_avgFuncLib_CPP_API __declspec(dllexport)
#else
#define PUBLIC_avgFuncLib_CPP_API __declspec(dllimport)
#endif

#define LIB_avgFuncLib_CPP_API PUBLIC_avgFuncLib_CPP_API

#else

#if !defined(LIB_avgFuncLib_CPP_API)
#if defined(LIB_avgFuncLib_C_API)
#define LIB_avgFuncLib_CPP_API LIB_avgFuncLib_C_API
#else
#define LIB_avgFuncLib_CPP_API /* empty! */ 
#endif
#endif

#endif

extern LIB_avgFuncLib_CPP_API void MW_CALL_CONV avgFunc(int nargout, mwArray& data_out, const mwArray& inputArg);

/* C++ INTERFACE -- WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- END */
#endif

#endif
