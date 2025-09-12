! Created by  on 27/06/2025.

module modi_thermo

    use, intrinsic :: iso_c_binding
    implicit none

    interface
        type(c_funptr) function c_dace_init_thermo(IJ,&
            &K, NRR) bind(c, name='__dace_init_thermodynamic_fields')
            use, intrinsic :: iso_c_binding, only: c_int, c_funptr
            integer(c_int) :: IJ
            integer(c_int) :: K
            integer(c_int) :: NRR
        end function c_dace_init_thermo

        subroutine c_program_thermo(handle, cph, exn, ls, lv, rc, rg, ri,&
            & rr, rs, rv, t, th, CI, CL, CPD, CPV, IJ, K, LSTT,&
            & LVTT, NRR, TT) bind(c, name='__program_thermodynamic_fields')

            use, intrinsic :: iso_c_binding

            type(c_funptr) :: handle
            integer(c_int), value :: IJ
            integer(c_int), value :: K
            integer(c_int), value :: NRR

            real(c_double) ::cph(*)
            real(c_double) ::exn(*)
            real(c_double) ::ls(*)
            real(c_double) ::lv(*)
            real(c_double) ::rc(*)
            real(c_double) ::rg(*)
            real(c_double) ::ri(*)
            real(c_double) ::rr(*)
            real(c_double) ::rs(*)
            real(c_double) ::rv(*)
            real(c_double) ::t(*)
            real(c_double) ::th(*)
             
             
            real(c_double), value ::  CI
            real(c_double), value ::  CL
            real(c_double), value ::  CPD
            real(c_double), value ::  CPV
            real(c_double), value ::  LSTT
            real(c_double), value ::  LVTT
            real(c_double), value ::  TT

           
        end subroutine c_program_thermo

        subroutine c_dace_exit_thermo(handle, err) bind(c, name='__dace_exit_thermodynamic_fields')
            use, intrinsic :: iso_c_binding, only: c_funptr, c_int
            type(c_funptr) :: handle
            integer(c_int) :: err
        end subroutine c_dace_exit_thermo

    end interface

end module modi_thermo