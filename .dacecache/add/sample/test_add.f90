! Created by  on 02/07/2025.

program main

    use modi_add
    use, intrinsic :: iso_c_binding

    integer(c_int) :: I, J, K
    type(c_funptr) :: handle

    real(c_double), allocatable :: a(:,:,:)
    real(c_double), allocatable :: b(:,:,:)
    real(c_double), allocatable :: c(:,:,:)

    I = 15
    J = 15
    K = 15

    allocate(a(I, J, K))
    allocate(b(I, J, K))
    allocate(c(I, J, K))

    a(:,:,:) = 1.0
    b(:,:,:) = 1.0
    c(:,:,:) = 0.0

    handle = c_dace_init_add(I, J, K, NRR)

    call c_program_add(handle,&
        &a, b, c, I, J, K)

    print *, "c :", sum(c)/(I * J * K)


end program main