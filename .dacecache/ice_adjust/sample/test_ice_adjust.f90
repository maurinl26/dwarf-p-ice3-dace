! Created by  on 27/06/2025.

program test_ice_adjust

    use modi_ice_adjust_dace
    implicit none

    integer(c_int) :: I, J, K


    real(c_double), allocatable :: pcf_mf(:,:,:)
    real(c_double), allocatable :: pcldfr(:,:,:)
    real(c_double), allocatable :: pexn(:,:,:)
    real(c_double), allocatable :: phlc_hcf(:,:,:)
    real(c_double), allocatable :: phlc_hrc(:,:,:)
    real(c_double), allocatable :: phli_hcf(:,:,:)
    real(c_double), allocatable :: phli_hri(:,:,:)
    real(c_double), allocatable :: ppabs(:,:,:)
    real(c_double), allocatable :: prc0(:,:,:)
    real(c_double), allocatable :: prc_mf(:,:,:)
    real(c_double), allocatable :: prcs0(:,:,:)
    real(c_double), allocatable :: prcs1(:,:,:)
    real(c_double), allocatable :: prg0(:,:,:)
    real(c_double), allocatable :: prhodref(:,:,:)
    real(c_double), allocatable :: pri0(:,:,:)
    real(c_double), allocatable :: pri_mf(:,:,:)
    real(c_double), allocatable :: pris0(:,:,:)
    real(c_double), allocatable :: pris1(:,:,:)
    real(c_double), allocatable :: prr0(:,:,:)
    real(c_double), allocatable :: prs0(:,:,:)
    real(c_double), allocatable :: prv0(:,:,:)
    real(c_double), allocatable :: prvs0(:,:,:)
    real(c_double), allocatable :: prvs1(:,:,:)
    real(c_double), allocatable :: psigqsat(:,:,:)
    real(c_double), allocatable :: psigrc(:,:,:)
    real(c_double), allocatable :: psigs(:,:,:)
    real(c_double), allocatable :: pth0(:,:,:)
    real(c_double), allocatable :: pths0(:,:,:)
    real(c_double), allocatable :: pths1(:,:,:)


    real(c_double) :: ACRIAUTI = 1.0
    real(c_double):: ALPI = 1.0
    real(c_double):: ALPW = 1.0
    real(c_double):: BCRIAUTI = 1.0
    real(c_double):: BETAI = 1.0
    real(c_double):: BETAW = 1.0
    real(c_double):: CI = 1.0
    real(c_double):: CL = 1.0
    real(c_double):: CPD = 1.0
    real(c_double):: CPV = 1.0
    real(c_double):: CRIAUTC = 1.0
    real(c_double):: CRIAUTI = 1.0
    logical(c_bool):: FRAC_ICE_ADJUST = .true.
    real(c_double):: GAMI = 1.0
    real(c_double):: GAMW = 1.0
    logical(c_bool):: LAMBDA3 = .true.
    logical(c_bool):: LSIGMAS = .true.
    logical(c_bool):: LSTATNW = .true.
    real(c_double):: LSTT = 1.0
    logical(c_bool):: LSUBG_COND = .true.
    real(c_double)::  LVTT = 1.0
    integer(c_int):: NRR = 6
    logical(c_bool):: OCND2 = .true.
    real(c_double):: RD = 1.0
    real(c_double):: RV = 1.0
    integer(c_int):: SUBG_MF_PDF = 0
    real(c_double):: TMAXMIX = 1.0
    real(c_double):: TMINMIX = 1.0
    real(c_double):: TT = 1.0
    real(c_double):: dt = 50.0

    type(c_funptr) :: handle
    integer :: err

    I = 15
    J = 15
    K = 90

    print *, "Allocation"
    allocate(pcf_mf(I, J, K))
    allocate(pcldfr(I, J, K))
    allocate(pexn(I, J, K))
    allocate(ppabs(I, J, K))
    allocate(prc0(I, J, K))
    allocate(prc_mf(I, J, K))
    allocate(prcs0(I, J, K))
    allocate(prg0(I, J, K))
    allocate(prhodref(I, J, K))
    allocate(pri0(I, J, K))
    allocate(pri_mf(I, J, K))
    allocate(pris0(I, J, K))
    allocate(prr0(I, J, K))
    allocate(prs0(I, J, K))
    allocate(prv0(I, J, K))
    allocate(prvs0(I, J, K))
    allocate(psigqsat(I, J, K))
    allocate(psigrc(I, J, K))
    allocate(psigs(I, J, K))
    allocate(pth0(I, J, K))
    allocate(pths0(I, J, K))

    allocate(pths1(I, J, K))
    allocate(pris1(I, J, K))
    allocate(prcs1(I, J, K))
    allocate(prvs1(I, J, K))

    allocate(phlc_hcf(I, J, K))
    allocate(phlc_hrc(I, J, K))
    allocate(phli_hcf(I, J, K))
    allocate(phli_hri(I, J, K))

    print *, "Dummy values"
    pcf_mf(:,:,:) = 1.0
    pcldfr(:,:,:) = 1.
    pexn(:,:,:) = 1.
    ppabs(:,:,:) = 1.
    prc0(:,:,:) = 1.
    prc_mf(:,:,:) = 1.
    prcs0(:,:,:) = 1.
    prg0(:,:,:) = 1.
    prhodref(:,:,:) = 1.
    pri0(:,:,:) = 1.
    pri_mf(:,:,:) = 1.
    pris0(:,:,:) = 1.
    prr0(:,:,:) = 1.
    prs0(:,:,:) = 1.
    prv0(:,:,:) = 1.
    prvs0(:,:,:) = 1.
    psigqsat(:,:,:) = 1.
    psigrc(:,:,:) = 1.
    psigs(:,:,:) = 1.
    pth0(:,:,:) = 1.
    pths0(:,:,:) = 1.

    pths1(:,:,:) = 0.
    pris1(:,:,:) = 0.
    prcs1(:,:,:) = 0.
    prvs1(:,:,:) = 0.

    phlc_hcf(:,:,:) = 0.
    phlc_hrc(:,:,:) = 0.
    phli_hcf(:,:,:) = 0.
    phli_hri(:,:,:) = 0.

    print *, "debug : main_ice_adjust.F90 - Call  handle"
    handle = c_dace_init_ice_adjust(I, J, K)

    print *, "debug : main_ice_adjust.F90 - Call  program"
    call c_program_ice_adjust(handle, pcf_mf, pcldfr, pexn, phlc_hcf, phlc_hrc, phli_hcf,&
                &phli_hri, ppabs, prc0, prc_mf, prcs0, prcs1, prg0, prhodref, pri0, pri_mf, pris0, pris1, prr0, prs0, prv0, prvs0,&
                &prvs1, psigqsat, psigrc, psigs, pth0, pths0, pths1, ACRIAUTI, ALPI, ALPW, BCRIAUTI,  BETAI,  BETAW,&
                &CI, CL, CPD, CPV, CRIAUTC, CRIAUTI, FRAC_ICE_ADJUST, GAMI, GAMW, I, J, K, LAMBDA3, LSIGMAS,&
                &LSTATNW, LSTT, LSUBG_COND, LVTT, NRR, OCND2, RD, RV, SUBG_MF_PDF, TMAXMIX, TMINMIX, TT,&
                &dt)

    print *, "handle :", handle
    print *, "error :", err
    print *, "mean, hlc_hrc :", sum(phlc_hcf)/(I * J * K)

    print *, "mean, pths1 :", sum(pths1)/(I * J * K)
    print *, "mean, pris1 :", sum(pris1)/(I * J * K)
    print *, "mean, prcs1 :", sum(prcs1)/(I * J * K)
    print *, "mean, prvs1 :", sum(prvs1)/(I * J * K)

end program test_ice_adjust