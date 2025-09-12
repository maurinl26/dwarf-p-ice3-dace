program test_thermo

    use fortran_c_array_interface
    use modi_thermo
    use, intrinsic :: iso_c_binding
    implicit none

    integer(c_int), parameter :: IJK = 250000_c_int

    integer(c_int) :: IJ, K, NRR

    type(c_funptr) :: handle
    
    real(c_double), dimension(250000), target :: cph
    real(c_double), dimension(250000), target :: exn 
    real(c_double), dimension(250000), target :: ls
    real(c_double), dimension(250000), target :: lv
    real(c_double), dimension(250000), target :: rc
    real(c_double), dimension(250000), target :: rg
    real(c_double), dimension(250000), target :: ri
    real(c_double), dimension(250000), target :: rr
    real(c_double), dimension(250000), target :: rs 
    real(c_double), dimension(250000), target :: rv
    real(c_double), dimension(250000), target :: t
    real(c_double), dimension(250000), target :: th

    type(c_ptr):: cph_ptr
    type(c_ptr):: exn_ptr 
    type(c_ptr):: ls_ptr
    type(c_ptr):: lv_ptr
    type(c_ptr):: rc_ptr
    type(c_ptr):: rg_ptr
    type(c_ptr):: ri_ptr
    type(c_ptr):: rr_ptr
    type(c_ptr):: rs_ptr 
    type(c_ptr):: rv_ptr
    type(c_ptr):: t_ptr
    type(c_ptr):: th_ptr
    
    real(c_double) :: CI, CL, CPD, CPV, LSTT
    real(c_double) :: LVTT, TT

    ! allocate(cph(IJK))
    ! allocate(exn(IJK)) 
    ! allocate(ls(IJK))
    ! allocate(lv(IJK))
    ! allocate(rc(IJK))
    ! allocate(rg(IJK))
    ! allocate(ri(IJK))
    ! allocate(rr(IJK))
    ! allocate(rs(IJK)) 
    ! allocate(rv(IJK))
    ! allocate(t(IJK))
    ! allocate(th(IJK))

    cph(:) = 1.0_c_double
    exn(:) = 1.0_c_double 
    ls(:) = 1.0_c_double
    lv(:) = 1.0_c_double
    rc(:) = 1.0_c_double
    rg(:) = 1.0_c_double
    ri(:) = 1.0_c_double
    rr(:) = 1.0_c_double
    rs(:) = 1.0_c_double 
    rv(:) = 1.0_c_double
    t(:) = 1.0_c_double
    th(:) = 1.0_c_double

    ! cph_ptr = fortran_to_c_ptr(cph)
    ! exn_ptr = fortran_to_c_ptr(exn) 
    ! ls_ptr = fortran_to_c_ptr(ls)
    ! lv_ptr = fortran_to_c_ptr(lv)
    ! rc_ptr = fortran_to_c_ptr(rc)
    ! rg_ptr = fortran_to_c_ptr(rg)
    ! ri_ptr = fortran_to_c_ptr(ri)
    ! rr_ptr = fortran_to_c_ptr(rr)
    ! rs_ptr = fortran_to_c_ptr(rs) 
    ! rv_ptr = fortran_to_c_ptr(rv)
    ! t_ptr = fortran_to_c_ptr(t)
    ! th_ptr = fortran_to_c_ptr(th)

    IJ = 2500
    K = 90
    NRR = 6

    handle = c_dace_init_thermo(IJ, K, NRR)

    call c_program_thermo(handle, cph, exn, ls, lv,&
        & rc, rg, ri, rr, rs, rv,&
        & t, th, CI, CL, CPD, CPV, IJ, K, LSTT,&
        & LVTT, NRR, TT)

    print *, "mean, cph : ", sum(cph)/IJK
    print *, "mean, lv : ", sum(lv)/IJK
    print *, "mean, ls : ", sum(ls)/IJK
    print *, "mean, t : ", sum(t)/IJK

end program test_thermo