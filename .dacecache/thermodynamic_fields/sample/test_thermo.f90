! Created by  on 02/07/2025.

program main

    use modi_thermo
    use, intrinsic :: iso_c_binding

    integer(c_int) :: I, J, K, NRR
    type(c_funptr) :: handle

    real(c_double) :: CI = 1.0
    real(c_double) :: CL = 1.0
    real(c_double) :: CPD = 1.0
    real(c_double) :: CPV = 1.0
    real(c_double) :: LSTT = 1.0
    real(c_double) :: LVTT = 1.0
    real(c_double) :: TT = 1.0

    real(c_double), allocatable :: cph(:,:,:)
    real(c_double), allocatable :: exn(:,:,:)
    real(c_double), allocatable :: ls(:,:,:)
    real(c_double), allocatable :: lv(:,:,:)
    real(c_double), allocatable :: rc(:,:,:)
    real(c_double), allocatable :: rg(:,:,:)
    real(c_double), allocatable :: ri(:,:,:)
    real(c_double), allocatable :: rr(:,:,:)
    real(c_double), allocatable :: rs(:,:,:)
    real(c_double), allocatable :: rv(:,:,:)
    real(c_double), allocatable :: t(:,:,:)
    real(c_double), allocatable :: th(:,:,:)

    I = 15
    J = 15
    K = 15
    NRR = 6

    allocate(cph(I, J, K))
    allocate(exn(I, J, K))
    allocate(ls(I, J, K))
    allocate(lv(I, J, K))
    allocate(rc(I, J, K))
    allocate(rg(I, J, K))
    allocate(ri(I, J, K))
    allocate(rr(I, J, K))
    allocate(rs(I, J, K))
    allocate(rv(I, J, K))
    allocate(t(I, J, K))
    allocate(th(I, J, K))

    cph(:,:,:) = 0.0
    exn(:,:,:) = 1.0
    ls(:,:,:) = 0.0
    lv(:,:,:) = 0.0
    rc(:,:,:) = 1.0
    rg(:,:,:) = 1.0
    ri(:,:,:) = 1.0
    rr(:,:,:) = 1.0
    rs(:,:,:) = 1.0
    rv(:,:,:) = 1.0
    t(:,:,:) = 0.0
    th(:,:,:) = 1.0

    handle = c_dace_init_thermodynamic_fields(I, J, K, NRR)

    call c_program_thermodynamic_fields(handle,&
        &cph, exn, ls, lv, rc, rg, ri, rr, rs, rv, t, th,&
        &CI, CL, CPD, CPV, I, J, K, LSTT, LVTT, NRR, TT)

    print *, "cph :", sum(cph)/(I * J * K)
    print *, "ls :", sum(ls)/(I * J * K)
    print *, "lv :", sum(lv)/(I * J * K)
    print *, "t :", sum(t)/(I * J * K)

end program main