! Created by  on 27/06/2025.

program test_ice_adjust

    use modi_ice_adjust_dace
    use fortran_c_array_interface
    use, intrinsic :: iso_c_binding, only : c_double, c_int, c_funptr, c_bool

    implicit none

    integer(c_int) :: I, J, IJ, K

    ! Fortran arrays
    real(c_double), allocatable, target :: pcf_mf(:,:)
    real(c_double), allocatable, target :: pcldfr(:,:)
    real(c_double), allocatable, target :: pexn(:,:)
    real(c_double), allocatable, target :: phlc_hcf(:,:)
    real(c_double), allocatable, target :: phlc_hrc(:,:)
    real(c_double), allocatable, target :: phli_hcf(:,:)
    real(c_double), allocatable, target :: phli_hri(:,:)
    real(c_double), allocatable, target :: ppabs(:,:)
    real(c_double), allocatable, target :: prc0(:,:)
    real(c_double), allocatable, target :: prc_mf(:,:)
    real(c_double), allocatable, target :: prcs0(:,:)
    real(c_double), allocatable, target :: prcs1(:,:)
    real(c_double), allocatable, target :: prg0(:,:)
    real(c_double), allocatable, target :: prhodref(:,:)
    real(c_double), allocatable, target :: pri0(:,:)
    real(c_double), allocatable, target :: pri_mf(:,:)
    real(c_double), allocatable, target :: pris0(:,:)
    real(c_double), allocatable, target :: pris1(:,:)
    real(c_double), allocatable, target :: prr0(:,:)
    real(c_double), allocatable, target :: prs0(:,:)
    real(c_double), allocatable, target :: prv0(:,:)
    real(c_double), allocatable, target :: prvs0(:,:)
    real(c_double), allocatable, target :: prvs1(:,:)
    real(c_double), allocatable, target :: psigqsat(:,:)
    real(c_double), allocatable, target :: psigrc(:,:)
    real(c_double), allocatable, target :: psigs(:,:)
    real(c_double), allocatable, target :: pth0(:,:)
    real(c_double), allocatable, target :: pths0(:,:)
    real(c_double), allocatable, target :: pths1(:,:)

    ! C pointers
    type(c_ptr) :: pcf_mf_ptr, pcldfr_ptr, pexn_ptr
    type(c_ptr) :: phlc_hcf_ptr, phlc_hrc_ptr, phli_hcf_ptr, phli_hri_ptr
    type(c_ptr) :: ppabs_ptr, prc0_ptr, prc_mf_ptr, prcs0_ptr, prcs1_ptr
    type(c_ptr) :: prg0_ptr, prhodref_ptr, pri0_ptr, pri_mf_ptr, pris0_ptr
    type(c_ptr) :: pris1_ptr, prr0_ptr, prs0_ptr, prv0_ptr, prvs0_ptr, prvs1_ptr
    type(c_ptr) :: psigqsat_ptr, psigrc_ptr, psigs_ptr, pth0_ptr, pths0_ptr, pths1_ptr

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

    I = 15
    J = 15
    K = 90
    IJ = I * J

    print *, "debug : main_ice_adjust.F90 - Allocation"
    !! Allocation
    allocate(pcf_mf(IJ, K))
    allocate(pcldfr(IJ, K))
    allocate(pexn(IJ, K))
    allocate(ppabs(IJ, K))
    allocate(prc0(IJ, K))
    allocate(prc_mf(IJ, K))
    allocate(prcs0(IJ, K))
    allocate(prg0(IJ, K))
    allocate(prhodref(IJ, K))
    allocate(pri0(IJ, K))
    allocate(pri_mf(IJ, K))
    allocate(pris0(IJ, K))
    allocate(prr0(IJ, K))
    allocate(prs0(IJ, K))
    allocate(prv0(IJ, K))
    allocate(prvs0(IJ, K))
    allocate(psigqsat(IJ, K))
    allocate(psigrc(IJ, K))
    allocate(psigs(IJ, K))
    allocate(pth0(IJ, K))
    allocate(pths0(IJ, K))

    allocate(pths1(IJ, K))
    allocate(pris1(IJ, K))
    allocate(prcs1(IJ, K))
    allocate(prvs1(IJ, K))

    allocate(phlc_hcf(IJ, K))
    allocate(phlc_hrc(IJ, K))
    allocate(phli_hcf(IJ, K))
    allocate(phli_hri(IJ, K))

    print *, "debug : main_ice_adjust.F90 - Dummy values"
    !! Default values
    pcf_mf(:,:) = 1.0_c_double
    pcldfr(:,:) = 1.0_c_double
    pexn(:,:) = 1.0_c_double
    ppabs(:,:) = 1.0_c_double
    prc0(:,:) = 1.0_c_double
    prc_mf(:,:) = 1.0_c_double
    prcs0(:,:) = 1.0_c_double
    prg0(:,:) = 1.0_c_double
    prhodref(:,:) = 1.0_c_double
    pri0(:,:) = 1.0_c_double
    pri_mf(:,:) = 1.0_c_double
    pris0(:,:) = 1.0_c_double
    prr0(:,:) = 1.0_c_double
    prs0(:,:) = 1.0_c_double
    prv0(:,:) = 1.0_c_double
    prvs0(:,:) = 1.0_c_double
    psigqsat(:,:) = 1.0_c_double
    psigrc(:,:) = 1.0_c_double
    psigs(:,:) = 1.0_c_double
    pth0(:,:) = 1.0_c_double
    pths0(:,:) = 1.0_c_double

    pths1(:,:) = 0.0_c_double
    pris1(:,:) = 0.0_c_double
    prcs1(:,:) = 0.0_c_double
    prvs1(:,:) = 0.0_c_double

    phlc_hcf(:,:) = 0.0_c_double
    phlc_hrc(:,:) = 0.0_c_double
    phli_hcf(:,:) = 0.0_c_double
    phli_hri(:,:) = 0.0_c_double

    print *, "debug : main_ice_adjust.F90 - Pointer association"
    !! Association
    pcf_mf_ptr = fortran_to_c_ptr(pcf_mf)
    pcldfr_ptr = fortran_to_c_ptr(pcldfr)
    pexn_ptr = fortran_to_c_ptr(pexn)
    phlc_hcf_ptr = fortran_to_c_ptr(phlc_hcf)
    phlc_hrc_ptr = fortran_to_c_ptr(phlc_hrc) 
    phli_hcf_ptr = fortran_to_c_ptr(phli_hcf)
    phli_hri_ptr = fortran_to_c_ptr(phli_hri)
    ppabs_ptr = fortran_to_c_ptr(ppabs) 
    prc0_ptr = fortran_to_c_ptr(prc0) 
    prc_mf_ptr = fortran_to_c_ptr(prc_mf) 
    prcs0_ptr = fortran_to_c_ptr(prcs0) 
    prcs1_ptr = fortran_to_c_ptr(prcs1)
    prg0_ptr = fortran_to_c_ptr(prg0) 
    prhodref_ptr = fortran_to_c_ptr(prhodref)
    pri0_ptr = fortran_to_c_ptr(pri0)
    pri_mf_ptr = fortran_to_c_ptr(pri_mf)
    pris0_ptr = fortran_to_c_ptr(pris0)
    pris1_ptr = fortran_to_c_ptr(pris1) 
    prr0_ptr = fortran_to_c_ptr(prr0) 
    prs0_ptr = fortran_to_c_ptr(prs0) 
    prv0_ptr = fortran_to_c_ptr(prv0) 
    prvs0_ptr = fortran_to_c_ptr(prvs0) 
    prvs1_ptr = fortran_to_c_ptr(prvs1)
    psigqsat_ptr = fortran_to_c_ptr(psigqsat) 
    psigrc_ptr = fortran_to_c_ptr(psigrc) 
    psigs_ptr = fortran_to_c_ptr(psigs) 
    pth0_ptr = fortran_to_c_ptr(pth0) 
    pths0_ptr = fortran_to_c_ptr(pths0)
    pths1_ptr = fortran_to_c_ptr(pths1)

    print *, "debug : main_ice_adjust.F90 - Call  handle"
    handle = c_dace_init_ice_adjust(IJ, K)

    print *, "debug : main_ice_adjust.F90 - Call  program"
    call c_program_ice_adjust(handle=handle, cldfr=pcldfr_ptr, exn=pexn_ptr, pabs=ppabs_ptr,&
            &rc0=prc0_ptr, rcs0=prcs0_ptr, rcs1=prcs1_ptr, rg0=prg0_ptr, ri0=pri0_ptr,&
            &ris0=pris0_ptr, ris1=pris1_ptr, rr0=prr0_ptr, rs0=prs0_ptr, rv0=prv0_ptr,&
            &rvs0=prvs0_ptr, rvs1=prvs1_ptr, sigqsat=psigqsat_ptr, sigrc=psigrc_ptr, sigs=psigs_ptr,&
            &th0=pth0_ptr, ths0=pths0_ptr, ths1=pths1_ptr, &
            &ALPI=ALPI, ALPW=ALPW, BETAI=BETAI, BETAW=BETAW, CI=CI, CL=CL,&
            &CPD=CPD, CPV=CPV, GAMI=GAMI, GAMW=GAMW, IJ=IJ, K=K, LSIGMAS=LSIGMAS,&
            &LSTATNW=LSTATNW, LSTT=LSTT, LVTT=LVTT, OCND2=OCND2, RD=RD, RV=RV, TMAXMIX=TMAXMIX,&
            &TMINMIX=TMINMIX, TT=TT, dt=dt)

    print *, "debug : main_ice_adjust.F90 - mean, hlc_hrc :", sum(phlc_hcf)/(I * J * K)
    print *, "debug : main_ice_adjust.F90 - mean, pths1 :", sum(pths1)/(I * J * K)
    print *, "debug : main_ice_adjust.F90 - mean, pris1 :", sum(pris1)/(I * J * K)
    print *, "debug : main_ice_adjust.F90 - mean, prcs1 :", sum(prcs1)/(I * J * K)
    print *, "debug : main_ice_adjust.F90 - mean, prvs1 :", sum(prvs1)/(I * J * K)

    print *, "debug : main_ice_adjust.F90 - Deallocation values"
    deallocate(pcf_mf)
    deallocate(pcldfr)
    deallocate(pexn)
    deallocate(ppabs)
    deallocate(prc0)
    deallocate(prc_mf)
    deallocate(prcs0)
    deallocate(prg0)
    deallocate(prhodref)
    deallocate(pri0)
    deallocate(pri_mf)
    deallocate(pris0)
    deallocate(prr0)
    deallocate(prs0)
    deallocate(prv0)
    deallocate(prvs0)
    deallocate(psigqsat)
    deallocate(psigrc)
    deallocate(psigs)
    deallocate(pth0)
    deallocate(pths0)

    deallocate(pths1)
    deallocate(pris1)
    deallocate(prcs1)
    deallocate(prvs1)

    deallocate(phlc_hcf)
    deallocate(phlc_hrc)
    deallocate(phli_hcf)
    deallocate(phli_hri)

    print *, "Success"

end program test_ice_adjust