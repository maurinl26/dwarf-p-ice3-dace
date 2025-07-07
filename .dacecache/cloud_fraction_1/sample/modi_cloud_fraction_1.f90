! Created by  on 02/07/2025.

module modi_thermo

    use, intrinsic :: iso_c_binding
    implicit none

    interface
        type(c_funptr) function c_dace_init_cloud_fraction_1(I, J, K) bind(c, name='__dace_init_cloud_fraction_1')
            use, intrinsic :: iso_c_binding, only: c_int, c_funptr
            integer(c_int), value :: I
            integer(c_int), value :: J
            integer(c_int), value :: K
        end function c_dace_init_cloud_fraction_1

        subroutine c_program_cloud_fraction_1(handle, cph, exnref, ls, lv, rc, rc_tmp, rcs0, rcs1, ri, ri_tmp, ris0,&
                &ris1, rvs0, rvs1, ths0, ths1, I, J, K, &
                &dt) bind(c, name='__program_cloud_fraction_1')

            use, intrinsic :: iso_c_binding, only: c_funptr, c_ptr, c_float, c_int, c_bool, c_double

            type(c_funptr), value :: handle

            real(c_double) :: cph(*)
            real(c_double) :: exnref(*)
            real(c_double) :: ls(*)
            real(c_double) :: lv(*)
            real(c_double) :: rc(*)
            real(c_double) :: rc_tmp(*)
            real(c_double) :: rcs0(*)
            real(c_double) :: rcs1(*)
            real(c_double) :: ri(*)
            real(c_double) :: ri_tmp(*)
            real(c_double) :: ris0(*)
            real(c_double) :: ris1(*)
            real(c_double) :: rvs0(*)
            real(c_double) :: rvs1(*)
            real(c_double) :: ths0(*)
            real(c_double) :: ths1(*)

            integer(c_int), value :: I
            integer(c_int), value :: J
            integer(c_int), value :: K
            real(c_double), value :: dt


        end subroutine c_program_cloud_fraction_1

        subroutine c_dace_exit_cloud_fraction_1(handle, err) bind(c, name='__dace_exit_cloud_fraction_1')
            use, intrinsic :: iso_c_binding, only: c_funptr, c_int
            type(c_funptr), intent(in) :: handle
            integer(c_int), intent(out) :: err
        end subroutine c_dace_exit_cloud_fraction_1

    end interface

end module modi_thermo