! Created by  on 02/07/2025.

module modi_thermo

    use, intrinsic :: iso_c_binding
    implicit none

    interface
        type(c_funptr) function c_dace_init_thermodynamic_fields(I, J, K, NRR) bind(c, name='__dace_init_thermodynamic_fields')
            use, intrinsic :: iso_c_binding, only: c_int, c_funptr
            integer(c_int), intent(in) :: I
            integer(c_int), intent(in) :: J
            integer(c_int), intent(in) :: K
            integer(c_int), intent(in) :: NRR
        end function c_dace_init_thermodynamic_fields

        subroutine c_program_thermodynamic_fields(handle, cph, exn, ls, lv, rc, rg, ri, rr, rs, rv, t, th, CI, CL, CPD,&
                &CPV, I, J, K, LSTT, LVTT, NRR, TT) bind(c, name='__program_thermodynamic_fields')

            use, intrinsic :: iso_c_binding, only: c_funptr, c_ptr, c_float, c_int, c_bool, c_double

            type(c_funptr), intent(in) :: handle

            real(c_double):: cph(*)
            real(c_double):: exn(*)
            real(c_double):: ls(*)
            real(c_double):: lv(*)
            real(c_double):: rc(*)
            real(c_double):: rg(*)
            real(c_double):: ri(*)
            real(c_double):: rr(*)
            real(c_double):: rs(*)
            real(c_double):: rv(*)
            real(c_double):: t(*)
            real(c_double):: th(*)

            real(c_double), value :: CI
            real(c_double), value :: CL
            real(c_double), value :: CPD
            real(c_double), value :: CPV
            integer(c_int), value :: I
            integer(c_int), value :: J
            integer(c_int), value :: K
            real(c_double), value :: LSTT
            real(c_double), value :: LVTT
            integer(c_int), value :: NRR
            real(c_double), value :: TT

        end subroutine c_program_thermodynamic_fields

        subroutine c_dace_exit_thermodynamic_fields(handle, err) bind(c, name='__dace_exit_thermodynamic_fields')
            use, intrinsic :: iso_c_binding, only: c_funptr, c_int
            type(c_funptr), intent(in) :: handle
            integer(c_int), intent(out) :: err
        end subroutine c_dace_exit_thermodynamic_fields

    end interface

end module modi_thermo