! Created by  on 03/07/2025.

module modi_condensation

    use, intrinsic :: iso_c_binding
    implicit none

    interface
        type(c_funptr) function c_dace_init_condensation(FRAC_ICE_ADJUST, I, J, K, LAMBDA3) bind(c, name='__dace_init_condensation')
            use, intrinsic :: iso_c_binding, only: c_int, c_funptr, c_bool
            logical(c_bool), intent(in) :: FRAC_ICE_ADJUST
            integer(c_int), intent(in) :: I
            integer(c_int), intent(in) :: J
            integer(c_int), intent(in) :: K
            logical(c_bool), intent(in) :: LAMBDA3
        end function c_dace_init_condensation

        subroutine c_program_condensation(handle, cldfr, cph, ls, lv, pabs, rc0, rc_out, ri0, ri_out,&
                &rv0, rv_out, sigqsat, sigrc, sigs, t,&
                &ALPI, ALPW, BETAI, BETAW, FRAC_ICE_ADJUST, GAMI, GAMW, I, J, K, LAMBDA3, LSIGMAS, LSTATNW, OCND2,&
                &RD, RV, TMAXMIX, TMINMIX) bind(c, name='__program_condensation')

            use, intrinsic :: iso_c_binding, only: c_funptr, c_ptr, c_float, c_int, c_bool, c_double

            type(c_funptr), intent(in) :: handle

            real(c_double) :: cldfr(*)
            real(c_double) :: cph(*)
            real(c_double) :: ls(*)
            real(c_double) :: lv(*)
            real(c_double) :: pabs(*)
            real(c_double) :: rc0(*)
            real(c_double) :: rc_out(*)
            real(c_double) :: ri0(*)
            real(c_double) :: ri_out(*)
            real(c_double) :: rv0(*)
            real(c_double) :: rv_out(*)
            real(c_double) :: sigqsat(*)
            real(c_double) :: sigrc(*)
            real(c_double) :: sigs(*)
            real(c_double) :: t(*)

            real(c_double), value :: ALPI
            real(c_double), value :: ALPW
            real(c_double), value :: BETAI
            real(c_double), value :: BETAW
            logical(c_bool), value :: FRAC_ICE_ADJUST
            real(c_double), value :: GAMI
            real(c_double), value :: GAMW
            integer(c_int), value :: I
            integer(c_int), value :: J
            integer(c_int), value :: K
            logical(c_bool), value :: LAMBDA3
            logical(c_bool), value :: LSIGMAS
            logical(c_bool), value :: LSTATNW
            logical(c_bool), value :: OCND2
            real(c_double), value :: RD
            real(c_double), value :: RV
            real(c_double), value :: TMAXMIX
            real(c_double), value :: TMINMIX

        end subroutine c_program_condensation

        subroutine c_dace_exit_condensation(handle, err) bind(c, name='__dace_exit_condensation')
            use, intrinsic :: iso_c_binding, only: c_funptr, c_int
            type(c_funptr), intent(in) :: handle
            integer(c_int), intent(out) :: err
        end subroutine c_dace_exit_condensation

    end interface

end module modi_condensation