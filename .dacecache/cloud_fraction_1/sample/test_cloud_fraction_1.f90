! Created by  on 02/07/2025.

program main

    use modi_cloud_fraction_1
    use, intrinsic :: iso_c_binding

    integer(c_int) :: I, J, K
    type(c_funptr) :: handle

    real(c_double) :: dt = 50.0


    real(c_double), allocatable :: cph(:,:,:)
    real(c_double), allocatable :: exnref(:,:,:)
    real(c_double), allocatable :: ls(:,:,:)
    real(c_double), allocatable :: lv(:,:,:)
    real(c_double), allocatable :: rc0(:,:,:)
    real(c_double), allocatable :: rc_tmp(:,:,:)
    real(c_double), allocatable :: rcs0(:,:,:)
    real(c_double), allocatable :: rcs1(:,:,:)
    real(c_double), allocatable :: ri0(:,:,:)
    real(c_double), allocatable :: ri_tmp(:,:,:)
    real(c_double), allocatable :: ris0(:,:,:)
    real(c_double), allocatable :: ris1(:,:,:)
    real(c_double), allocatable :: rvs0(:,:,:)
    real(c_double), allocatable :: rvs1(:,:,:)
    real(c_double), allocatable :: ths0(:,:,:)
    real(c_double), allocatable :: ths1(:,:,:)

    allocate(cph(I, J, K))
    allocate(exnref(I, J, K))
    allocate(ls(I, J, K))
    allocate(lv(I, J, K))
    allocate(rc0(I, J, K))
    allocate(rc_tmp(I, J, K))
    allocate(rcs0(I, J, K))
    allocate(rcs1(I, J, K))
    allocate(ri0(I, J, K))
    allocate(ri_tmp(I, J, K))
    allocate(ris0(I, J, K))
    allocate(ris1(I, J, K))
    allocate(rvs0(I, J, K))
    allocate(rvs1(I, J, K))
    allocate(ths0(I, J, K))
    allocate(ths1(I, J, K))

    cph(:,:,:) = 1.0
    exnref(:,:,:) = 1.0
    ls(:,:,:) = 1.0
    lv(:,:,:) = 1.0
    rc0(:,:,:) = 1.0
    rc_tmp(:,:,:) = 1.0
    rcs0(:,:,:) = 1.0
    rcs1(:,:,:) = 1.0
    ri0(:,:,:) = 1.0
    ri_tmp(:,:,:) = 1.0
    ris0(:,:,:) = 1.0
    ris1(:,:,:) = 0.0
    rvs0(:,:,:) = 1.0
    rvs1(:,:,:) = 0.0
    ths0(:,:,:) = 1.0
    ths1(:,:,:) = 0.0

    handle = c_dace_init_cloud_fraction_1(I, J, K)

    call c_program_cloud_fraction_1(handle, cph, exnref, ls, lv,&
            &rc, rc_tmp, rcs0, rcs1, ri, ri_tmp, ris0,&
            &ris1, rvs0, rvs1, ths0, ths1, I, J, K, &
            &dt)

    print *, "rvs1 :", sum(rvs1)/(I * J * K)
    print *, "rcs1 :", sum(rcs1)/(I * J * K)
    print *, "ris1 :", sum(ris1)/(I * J * K)

end program main