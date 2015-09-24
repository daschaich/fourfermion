// -----------------------------------------------------------------
// Defines and subroutine declarations for the three-dimensional
// four-fermion system with global SO(4) symmetry
#ifndef _SON_H
#define _SON_H

#include "../include/complex.h"
#include "../include/random.h"
// -----------------------------------------------------------------



// -----------------------------------------------------------------
// Fermions are SO(4) vectors
// Scalars are either antisymmetric or self-dual matrices
#define DIMF 4
#define NAS 6   // (DIMF / 2) * (DIMF - 1)
#define NSD 3   // (DIMF / 4) * (DIMF - 1)

typedef struct { float c[DIMF]; } fvector;
typedef struct { float e[NAS]; } fantisym;
typedef struct { float e[NSD]; } fselfdual;

typedef struct { double c[DIMF]; } dvector;
typedef struct { double e[NAS]; } dantisym;
typedef struct { double e[NSD]; } dselfdual;

#if (PRECISION == 1)
#define vector      fvector
#define antisym     fantisym
#define selfdual    fselfdual
#else
#define vector      dvector
#define antisym     dantisym
#define selfdual    dselfdual
#endif

#define PLUS 1          // Flags for selecting M or M_adjoint
#define MINUS -1
// -----------------------------------------------------------------



// -----------------------------------------------------------------
// Subroutine definitions
// Vector operations
// In file clearvec.c
void clearvec(vector *v);

// In file vec_copy.c
void vec_copy(vector *a, vector *b);

// In file dumpvec.c
void dumpvec(vector *v);

// In file msq_vec.c
Real magsq_vec(vector *v);

// In file dot.c
Real dot(vector *a, vector *b);

// In file addvec.c
void add_vec(vector *a, vector *b, vector *c);

// In file subvec.c
void sub_vec(vector *a, vector *b, vector *c);

// In file s_m_vec.c
void scalar_mult_vec(vector *src, Real scalar, vector *dest);

// In file s_m_a_vec.c
void scalar_mult_add_vec(vector *a, vector *b, Real scalar, vector *dest);

// In file s_m_s_vec.c
void scalar_mult_sub_vec(vector *a, vector *b, Real scalar, vector *dest);
// -----------------------------------------------------------------



// -----------------------------------------------------------------
// Matrix operations
// In file clear_mat.c
void clear_as(antisym *m);
void clear_sd(selfdual *m);

// In file mat_copy.c
void as_copy(antisym *a, antisym *b);
void sd_copy(selfdual *a, selfdual *b);

// In file dumpmat.c
void dumpas(antisym *m);
void dumpsd(selfdual *m);

// In file addmat.c
void add_as(antisym *a, antisym *b, antisym *c);
void add_sd(selfdual *a, selfdual *b, selfdual *c);

// In file submat.c
void sub_matrix(matrix *a, matrix *b, matrix *c);

// In file s_m_mat.c
void scalar_mult_as(antisym *src, Real scalar, antisym *dest);
void scalar_mult_sd(selfdual *src, Real scalar, selfdual *dest);

// In file s_m_a_mat.c
void scalar_mult_add_as(antisym *a, antisym *b, Real scalar, antisym *c);
void scalar_mult_add_sd(selfdual *a, selfdual *b, Real scalar, selfdual *c);

// In file s_m_s_mat.c
void scalar_mult_sub_matrix(matrix *src1, matrix *src2,
                                Real scalar, matrix *dest);

// In file m_mat_nn.c
void mult_nn(matrix *a, matrix *b, matrix *c);

// In file m_mat_na.c
void mult_na(matrix *a, matrix *b, matrix *c);

// In file m_mat_an.c
void mult_an(matrix *a, matrix *b, matrix *c);

// c <-- a * b, in file m_matvec.c
void mult_mat_vec(matrix *a, vector *b, vector *c);

// c <-- c + a * b, in file m_matvec_s.c
void mult_mat_vec_sum(matrix *a, vector *b, vector *c);

// c <-- c - a * b, in file m_matvec_ns.c
void mult_mat_vec_nsum(matrix *a, vector *b, vector *c);

// c <-- b * a, in file m_vecmat.c
void mult_vec_mat(vector *b, matrix *a, vector *c);
// -----------------------------------------------------------------



// -----------------------------------------------------------------
// Miscellaneous routines
// In file gaussrand.c
Real gaussian_rand_no(double_prn *prn_pt);

#include "../include/int32type.h"
void byterevn(int32type w[], int n);
void byterevn64(int32type w[], int n);

#endif
// -----------------------------------------------------------------