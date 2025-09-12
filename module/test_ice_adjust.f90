! Created by  on 27/06/2025.

program test_ice_adjust

   use modi_ice_adjust_dace
   use fortran_c_array_interface
   use, intrinsic :: iso_c_binding, only: c_double, c_int, c_funptr, c_bool

   implicit none

   integer(c_int), parameter :: IJK = 225000_c_int
   integer(c_int), parameter :: IJ = 2500_c_int
   integer(c_int), parameter :: K = 90_c_int
   integer(c_int), parameter :: I = 50_c_int
   integer(c_int), parameter :: J = 50_c_int 

   ! Fortran arrays
   real(c_double), dimension(IJK), target :: pcf_mf
   real(c_double), dimension(IJK), target :: pcldfr
   real(c_double), dimension(IJK), target :: pexn
   real(c_double), dimension(IJK), target :: phlc_hcf
   real(c_double), dimension(IJK), target :: phlc_hrc
   real(c_double), dimension(IJK), target :: phli_hcf
   real(c_double), dimension(IJK), target :: phli_hri
   real(c_double), dimension(IJK), target :: ppabs
   real(c_double), dimension(IJK), target :: prc0
   real(c_double), dimension(IJK), target :: prc_mf
   real(c_double), dimension(IJK), target :: prcs0
   real(c_double), dimension(IJK), target :: prcs1
   real(c_double), dimension(IJK), target :: prg0
   real(c_double), dimension(IJK), target :: prhodref
   real(c_double), dimension(IJK), target :: pri0
   real(c_double), dimension(IJK), target :: pri_mf
   real(c_double), dimension(IJK), target :: pris0
   real(c_double), dimension(IJK), target :: pris1
   real(c_double), dimension(IJK), target :: prr0
   real(c_double), dimension(IJK), target :: prs0
   real(c_double), dimension(IJK), target :: prv0
   real(c_double), dimension(IJK), target :: prvs0
   real(c_double), dimension(IJK), target :: prvs1
   real(c_double), dimension(IJK), target :: psigqsat
   real(c_double), dimension(IJK), target :: psigrc
   real(c_double), dimension(IJK), target :: psigs
   real(c_double), dimension(IJK), target :: pth0
   real(c_double), dimension(IJK), target :: pths0
   real(c_double), dimension(IJK), target :: pths1

   ! Constants
   real(c_double), parameter :: ACRIAUTI = 1.0
   real(c_double), parameter :: ALPI = 1.0
   real(c_double), parameter :: ALPW = 1.0
   real(c_double), parameter :: BCRIAUTI = 1.0
   real(c_double), parameter :: BETAI = 1.0
   real(c_double), parameter :: BETAW = 1.0
   real(c_double), parameter :: CI = 1.0
   real(c_double), parameter :: CL = 1.0
   real(c_double), parameter :: CPD = 1.0
   real(c_double), parameter :: CPV = 1.0
   real(c_double), parameter :: CRIAUTC = 1.0
   real(c_double), parameter :: CRIAUTI = 1.0
   logical(c_bool), parameter :: FRAC_ICE_ADJUST = .true.
   real(c_double), parameter :: GAMI = 1.0
   real(c_double), parameter :: GAMW = 1.0
   logical(c_bool), parameter :: LAMBDA3 = .true.
   logical(c_bool), parameter :: LSIGMAS = .true.
   logical(c_bool), parameter :: LSTATNW = .true.
   real(c_double), parameter :: LSTT = 1.0
   logical(c_bool), parameter :: LSUBG_COND = .true.
   real(c_double), parameter ::  LVTT = 1.0
   integer(c_int), parameter :: NRR = 6
   logical(c_bool), parameter :: OCND2 = .true.
   real(c_double), parameter :: RD = 1.0
   real(c_double), parameter :: RV = 1.0
   integer(c_int), parameter :: SUBG_MF_PDF = 0
   real(c_double), parameter :: TMAXMIX = 1.0
   real(c_double), parameter :: TMINMIX = 1.0
   real(c_double), parameter :: TT = 1.0
   real(c_double), parameter  :: dt = 50.0

   type(c_funptr) :: handle
   integer :: err

   print *, "debug : main_ice_adjust.F90 - Dummy values"
    !! Default values
   pcf_mf(:) = 1.0_c_double
   pcldfr(:) = 1.0_c_double
   pexn(:) = 1.0_c_double
   ppabs(:) = 1.0_c_double
   prc0(:) = 1.0_c_double
   prc_mf(:) = 1.0_c_double
   prcs0(:) = 1.0_c_double
   prg0(:) = 1.0_c_double
   prhodref(:) = 1.0_c_double
   pri0(:) = 1.0_c_double
   pri_mf(:) = 1.0_c_double
   pris0(:) = 1.0_c_double
   prr0(:) = 1.0_c_double
   prs0(:) = 1.0_c_double
   prv0(:) = 1.0_c_double
   prvs0(:) = 1.0_c_double
   psigqsat(:) = 1.0_c_double
   psigrc(:) = 1.0_c_double
   psigs(:) = 1.0_c_double
   pth0(:) = 1.0_c_double
   pths0(:) = 1.0_c_double

   pths1(:) = 0.0_c_double
   pris1(:) = 0.0_c_double
   prcs1(:) = 0.0_c_double
   prvs1(:) = 0.0_c_double

   phlc_hcf(:) = 0.0_c_double
   phlc_hrc(:) = 0.0_c_double
   phli_hcf(:) = 0.0_c_double
   phli_hri(:) = 0.0_c_double

   print *, "debug : main_ice_adjust.F90 - Call  handle"
   handle = c_dace_init_ice_adjust(IJ, K)

   print *, "debug : main_ice_adjust.F90 - Call  program"
   call c_program_ice_adjust(handle=handle, cldfr=pcldfr, exn=pexn, pabs=ppabs,&
           &rc0=prc0, rcs0=prcs0, rcs1=prcs1, rg0=prg0, ri0=pri0,&
           &ris0=pris0, ris1=pris1, rr0=prr0, rs0=prs0, rv0=prv0,&
           &rvs0=prvs0, rvs1=prvs1, sigqsat=psigqsat, sigrc=psigrc, sigs=psigs,&
           &th0=pth0, ths0=pths0, ths1=pths1, &
           &ALPI=ALPI, ALPW=ALPW, BETAI=BETAI, BETAW=BETAW, CI=CI, CL=CL,&
           &CPD=CPD, CPV=CPV, GAMI=GAMI, GAMW=GAMW, IJ=IJ, K=K, LSIGMAS=LSIGMAS,&
           &LSTATNW=LSTATNW, LSTT=LSTT, LVTT=LVTT, OCND2=OCND2, RD=RD, RV=RV, TMAXMIX=TMAXMIX,&
           &TMINMIX=TMINMIX, TT=TT, dt=dt)

   print *, "debug : main_ice_adjust.F90 - mean, hlc_hrc :", sum(phlc_hcf)/(IJK)
   print *, "debug : main_ice_adjust.F90 - mean, pths1 :", sum(pths1)/(IJK)
   print *, "debug : main_ice_adjust.F90 - mean, pris1 :", sum(pris1)/(IJK)
   print *, "debug : main_ice_adjust.F90 - mean, prcs1 :", sum(prcs1)/(IJK)
   print *, "debug : main_ice_adjust.F90 - mean, prvs1 :", sum(prvs1)/(IJK)

   print *, "Success"

end program test_ice_adjust
