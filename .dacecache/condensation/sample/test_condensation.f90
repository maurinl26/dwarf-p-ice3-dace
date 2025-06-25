! Created by  on 03/07/2025.

program test_condensation

    use modi_condensation
    implicit none

    integer(c_int) :: I, J, K

    real(c_double), allocatable :: cldfr
    real(c_double), allocatable :: cph
    real(c_double), allocatable :: ls
    real(c_double), allocatable :: lv
    real(c_double), allocatable :: pabs
    real(c_double), allocatable :: rc
    real(c_double), allocatable :: rc_out
    real(c_double), allocatable :: ri
    real(c_double), allocatable :: ri_out
    real(c_double), allocatable :: rv
    real(c_double), allocatable :: rv_out
    real(c_double), allocatable :: sigqsat
    real(c_double), allocatable :: sigrc
    real(c_double), allocatable :: sigs
    real(c_double), allocatable :: t

    real(c_double) :: ALPI = 1.0
    real(c_double) :: ALPW = 1.0
    real(c_double) :: BETAI = 1.0
    real(c_double) :: BETAW = 1.0
    logical(c_bool) :: FRAC_ICE_ADJUST = .true._c_bool
    real(c_double) :: GAMI = 1.0
    real(c_double) :: GAMW = 1.0
    logical(c_bool) :: LAMBDA3 = .true._c_bool
    logical(c_bool) :: LSIGMAS = .true._c_bool
    logical(c_bool) :: LSTATNW = .true._c_bool
    logical(c_bool) :: OCND2 = .true._c_bool
    real(c_double) :: RD = 1.0
    real(c_double) :: RV = 1.0
    real(c_double) :: TMAXMIX = 1.0
    real(c_double) :: TMINMIX = 1.0


    type(c_funptr) :: handle
    integer :: err

    I = 15
    J = 15
    K = 90

    print *, "Allocation"
    allocate(cldfr(I, J, K))
    allocate(cph(I, J, K))
    allocate(ls(I, J, K))
    allocate(lv(I, J, K))
    allocate(pabs(I, J, K))
    allocate(rc(I, J, K))
    allocate(ri(I, J, K))
    allocate(rv(I, J, K))
    allocate(sigqsat(I, J, K))
    allocate(sigrc(I, J, K))
    allocate(sigs(I, J, K))
    allocate(t(I, J, K))

    allocate(rc_out(I, J, K))
    allocate(ri_out(I, J, K))
    allocate(rv_out(I, J, K))

    print *, "Dummy values"
    cldfr(:,:,:) = 1.0
    cph(:,:,:) = 1.0
    ls(:,:,:) = 1.0
    lv(:,:,:) = 1.0
    pabs(:,:,:) = 1.0
    rc(:,:,:) = 1.0
    ri(:,:,:) = 1.0
    rv(:,:,:) = 1.0
    sigqsat(:,:,:) = 1.0
    sigrc(:,:,:) = 1.0
    sigs(:,:,:) = 1.0
    t(:,:,:) = 1.0

    rc_out(:,:,:) = 0.0
    ri_out(:,:,:) = 0.0
    rv_out(:,:,:) = 0.0

    print *, "debug : test_condensation.f90 - Call  handle"
    handle = c_dace_init_condensation(FRAC_ICE_ADJUST, I, J, K, LAMBDA3)

    print *, "debug : test_condensation.f90 - Call  program"
    call c_program_condensation(handle, cldfr, cph, ls, lv, pabs, rc, rc_out, ri, ri_out,&
            &rv, rv_out, sigqsat, sigrc, sigs, t,&
            &ALPI, ALPW, BETAI, BETAW, FRAC_ICE_ADJUST, GAMI, GAMW, &
            &I, J, K, LAMBDA3, LSIGMAS, LSTATNW, OCND2, RD, RV, TMAXMIX, TMINMIX)

    print *, "handle :", handle
    print *, "error :", err

    print *, "mean, pths1 :", sum(rc_out)/(I * J * K)
    print *, "mean, pris1 :", sum(ri_out)/(I * J * K)
    print *, "mean, prcs1 :", sum(rv_out)/(I * J * K)

end program test_condensation