/*
//@HEADER
// ************************************************************************
//
//               KokkosKernels 0.9: Linear Algebra and Graph Kernels
//                 Copyright 2017 Sandia Corporation
//
// Under the terms of Contract DE-AC04-94AL85000 with Sandia Corporation,
// the U.S. Government retains certain rights in this software.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
// 1. Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright
// notice, this list of conditions and the following disclaimer in the
// documentation and/or other materials provided with the distribution.
//
// 3. Neither the name of the Corporation nor the names of the
// contributors may be used to endorse or promote products derived from
// this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY SANDIA CORPORATION "AS IS" AND ANY
// EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
// PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL SANDIA CORPORATION OR THE
// CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
// EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
// PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
// LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
// NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// Questions? Contact Siva Rajamanickam (srajama@sandia.gov)
//
// ************************************************************************
//@HEADER
*/

#ifndef KOKKOSBLASLAPACK_TRTRI_TPL_SPEC_AVAIL_HPP_
#define KOKKOSBLASLAPACK_TRTRI_TPL_SPEC_AVAIL_HPP_

namespace KokkosBlas {
namespace Impl {

// Specialization struct which defines whether a specialization exists
template<class RVT, class AVT>
struct trtri_tpl_spec_avail {
  enum : bool { value = false };
};

// Generic Host side LAPACK (could be MKL or whatever)
#define KOKKOSBLAS_TRTRI_TPL_SPEC_AVAIL( SCALAR , LAYOUTA, MEMSPACE ) \
template<class ExecSpace> \
struct trtri_tpl_spec_avail< \
     Kokkos::View<int, LAYOUTA, Kokkos::HostSpace, \
                  Kokkos::MemoryTraits<Kokkos::Unmanaged> >, \
     Kokkos::View<const SCALAR**, LAYOUTA, Kokkos::Device<ExecSpace, MEMSPACE>, \
                  Kokkos::MemoryTraits<Kokkos::Unmanaged> >, \
     >  { enum : bool { value = true }; };

#ifdef KOKKOSKERNELS_ENABLE_TPL_LAPACK
#define KOKKOSBLAS_TRTRI_TPL_SPEC_AVAIL_LAPACK( SCALAR , LAYOUTA, MEMSPACE ) \
KOKKOSBLAS_TRTRI_TPL_SPEC_AVAIL(SCALAR, LAYOUTA, MEMSPACE)
#else
#define KOKKOSBLAS_TRTRI_TPL_SPEC_AVAIL_LAPACK( SCALAR , LAYOUTA, MEMSPACE )
#endif // KOKKOSKERNELS_ENABLE_TPL_LAPACK

#ifdef KOKKOSKERNELS_ENABLE_TPL_MAGMA
#define KOKKOSBLAS_TRTRI_TPL_SPEC_AVAIL_MAGMA( SCALAR , LAYOUTA, MEMSPACE ) \
KOKKOSBLAS_TRTRI_TPL_SPEC_AVAIL(SCALAR, LAYOUTA, MEMSPACE)
#else
#define KOKKOSBLAS_TRTRI_TPL_SPEC_AVAIL_MAGMA( SCALAR , LAYOUTA, MEMSPACE )
#endif // KOKKOSKERNELS_ENABLE_TPL_MAGMA

#if defined (KOKKOSKERNELS_INST_DOUBLE) \
 && defined (KOKKOSKERNELS_INST_LAYOUTLEFT)
 KOKKOSBLAS_TRTRI_TPL_SPEC_AVAIL_LAPACK( double,                  Kokkos::LayoutLeft, Kokkos::HostSpace) 
 KOKKOSBLAS_TRTRI_TPL_SPEC_AVAIL_MAGMA( double,                  Kokkos::LayoutLeft, Kokkos::CudaSpace)
 KOKKOSBLAS_TRTRI_TPL_SPEC_AVAIL_MAGMA( double,                  Kokkos::LayoutLeft, Kokkos::CudaUVMSpace)
#endif
#if defined (KOKKOSKERNELS_INST_FLOAT) \
 && defined (KOKKOSKERNELS_INST_LAYOUTLEFT)
 KOKKOSBLAS_TRTRI_TPL_SPEC_AVAIL_LAPACK( float,                   Kokkos::LayoutLeft, Kokkos::HostSpace)
 KOKKOSBLAS_TRTRI_TPL_SPEC_AVAIL_MAGMA( float,                   Kokkos::LayoutLeft, Kokkos::CudaSpace)
 KOKKOSBLAS_TRTRI_TPL_SPEC_AVAIL_MAGMA( float,                   Kokkos::LayoutLeft, Kokkos::CudaUVMSpace)
#endif
#if defined (KOKKOSKERNELS_INST_KOKKOS_COMPLEX_DOUBLE_) \
 && defined (KOKKOSKERNELS_INST_LAYOUTLEFT)
 KOKKOSBLAS_TRTRI_TPL_SPEC_AVAIL_LAPACK( Kokkos::complex<double>, Kokkos::LayoutLeft, Kokkos::HostSpace)
 KOKKOSBLAS_TRTRI_TPL_SPEC_AVAIL_MAGMA( Kokkos::complex<double>, Kokkos::LayoutLeft, Kokkos::CudaSpace)
 KOKKOSBLAS_TRTRI_TPL_SPEC_AVAIL_MAGMA( Kokkos::complex<double>, Kokkos::LayoutLeft, Kokkos::CudaUVMSpace)
#endif
#if defined (KOKKOSKERNELS_INST_KOKKOS_COMPLEX_FLOAT_) \
 && defined (KOKKOSKERNELS_INST_LAYOUTLEFT)
 KOKKOSBLAS_TRTRI_TPL_SPEC_AVAIL_LAPACK( Kokkos::complex<float>,  Kokkos::LayoutLeft, Kokkos::HostSpace)
 KOKKOSBLAS_TRTRI_TPL_SPEC_AVAIL_MAGMA( Kokkos::complex<float>,  Kokkos::LayoutLeft, Kokkos::CudaSpace)
 KOKKOSBLAS_TRTRI_TPL_SPEC_AVAIL_MAGMA( Kokkos::complex<float>,  Kokkos::LayoutLeft, Kokkos::CudaUVMSpace)
#endif

#if defined (KOKKOSKERNELS_INST_DOUBLE) \
 && defined (KOKKOSKERNELS_INST_LAYOUTRIGHT)
 KOKKOSBLAS_TRTRI_TPL_SPEC_AVAIL_LAPACK( double,                  Kokkos::LayoutRight, Kokkos::HostSpace)
 KOKKOSBLAS_TRTRI_TPL_SPEC_AVAIL_MAGMA( double,                  Kokkos::LayoutRight, Kokkos::CudaSpace)
 KOKKOSBLAS_TRTRI_TPL_SPEC_AVAIL_MAGMA( double,                  Kokkos::LayoutRight, Kokkos::CudaUVMSpace)
#endif
#if defined (KOKKOSKERNELS_INST_FLOAT) \
 && defined (KOKKOSKERNELS_INST_LAYOUTRIGHT)
 KOKKOSBLAS_TRTRI_TPL_SPEC_AVAIL_LAPACK( float,                   Kokkos::LayoutRight, Kokkos::HostSpace)
 KOKKOSBLAS_TRTRI_TPL_SPEC_AVAIL_MAGMA( float,                   Kokkos::LayoutRight, Kokkos::CudaSpace)
 KOKKOSBLAS_TRTRI_TPL_SPEC_AVAIL_MAGMA( float,                   Kokkos::LayoutRight, Kokkos::CudaUVMSpace)
#endif
#if defined (KOKKOSKERNELS_INST_KOKKOS_COMPLEX_DOUBLE_) \
 && defined (KOKKOSKERNELS_INST_LAYOUTRIGHT)
 KOKKOSBLAS_TRTRI_TPL_SPEC_AVAIL_LAPACK( Kokkos::complex<double>, Kokkos::LayoutRight, Kokkos::HostSpace)
 KOKKOSBLAS_TRTRI_TPL_SPEC_AVAIL_MAGMA( Kokkos::complex<double>, Kokkos::LayoutRight, Kokkos::CudaSpace)
 KOKKOSBLAS_TRTRI_TPL_SPEC_AVAIL_MAGMA( Kokkos::complex<double>, Kokkos::LayoutRight, Kokkos::CudaUVMSpace)
#endif
#if defined (KOKKOSKERNELS_INST_KOKKOS_COMPLEX_FLOAT_) \
 && defined (KOKKOSKERNELS_INST_LAYOUTRIGHT)
 KOKKOSBLAS_TRTRI_TPL_SPEC_AVAIL_LAPACK( Kokkos::complex<float>,  Kokkos::LayoutRight, Kokkos::HostSpace)
 KOKKOSBLAS_TRTRI_TPL_SPEC_AVAIL_MAGMA( Kokkos::complex<float>,  Kokkos::LayoutRight, Kokkos::CudaSpace)
 KOKKOSBLAS_TRTRI_TPL_SPEC_AVAIL_MAGMA( Kokkos::complex<float>,  Kokkos::LayoutRight, Kokkos::CudaUVMSpace)
#endif

} // namespace Impl
} // namespace KokkosBlas

#endif // KOKKOSBLASLAPACK_TRTRI_TPL_SPEC_AVAIL_HPP_
