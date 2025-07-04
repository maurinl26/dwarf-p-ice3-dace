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

            real(c_double), dimension(I, J, K), intent(in) :: cph
            real(c_double), dimension(I, J, K), intent(in) :: exn
            real(c_double), dimension(I, J, K), intent(in) :: ls
            real(c_double), dimension(I, J, K), intent(in) :: lv
            real(c_double), dimension(I, J, K), intent(in) :: rc
            real(c_double), dimension(I, J, K), intent(in) :: rg
            real(c_double), dimension(I, J, K), intent(in) :: ri
            real(c_double), dimension(I, J, K), intent(in) :: rr
            real(c_double), dimension(I, J, K), intent(in) :: rs
            real(c_double), dimension(I, J, K), intent(in) :: rv
            real(c_double), dimension(I, J, K), intent(in) :: t
            real(c_double), dimension(I, J, K), intent(in) :: th

            real(c_double), intent(in) :: CI
            real(c_double), intent(in) :: CL
            real(c_double), intent(in) :: CPD
            real(c_double), intent(in) :: CPV
            integer(c_int), intent(in) :: I
            integer(c_int), intent(in) :: J
            integer(c_int), intent(in) :: K
            real(c_double), intent(in) :: LSTT
            real(c_double), intent(in) :: LVTT
            integer(c_int), intent(in) :: NRR
            real(c_double), intent(in) :: TT

        end subroutine c_program_thermodynamic_fields

        subroutine c_dace_exit_thermodynamic_fields(handle, err) bind(c, name='__dace_exit_thermodynamic_fields')
            use, intrinsic :: iso_c_binding, only: c_funptr, c_int
            type(c_funptr), intent(in) :: handle
            integer(c_int), intent(out) :: err
        end subroutine c_dace_exit_thermodynamic_fields

    end interface

end module modi_thermo