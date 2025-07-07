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

        subroutine c_program_condensation(handle, cldfr, cph, ls, lv, pabs, rc, &
                &rc_out, ri, ri_out, rv, rv_out, sigqsat, sigrc, sigs, t,&
                &ALPI, ALPW, BETAI, BETAW, FRAC_ICE_ADJUST, GAMI, GAMW, I, J, K,&
                &LAMBDA3, LSIGMAS, LSTATNW, OCND2, RD, RV, TMAXMIX, TMINMIX) bind(c, name='__program_condensation')

            use, intrinsic :: iso_c_binding, only: c_funptr, c_ptr, c_float, c_int, c_bool, c_double

            type(c_funptr), intent(in) :: handle

            real(c_double), dimension(I, J, K), intent(in) :: cldfr
            real(c_double), dimension(I, J, K), intent(in) :: cph
            real(c_double), dimension(I, J, K), intent(in) :: ls
            real(c_double), dimension(I, J, K), intent(in) :: lv
            real(c_double), dimension(I, J, K), intent(in) :: pabs
            real(c_double), dimension(I, J, K), intent(in) :: rc
            real(c_double), dimension(I, J, K), intent(in) :: rc_out
            real(c_double), dimension(I, J, K), intent(in) :: ri
            real(c_double), dimension(I, J, K), intent(in) :: ri_out
            real(c_double), dimension(I, J, K), intent(in) :: rv
            real(c_double), dimension(I, J, K), intent(in) :: rv_out
            real(c_double), dimension(I, J, K), intent(in) :: sigqsat
            real(c_double), dimension(I, J, K), intent(in) :: sigrc
            real(c_double), dimension(I, J, K), intent(in) :: sigs
            real(c_double), dimension(I, J, K), intent(in) :: t

            real(c_double) :: ALPI
            real(c_double) :: ALPW
            real(c_double) :: BETAI
            real(c_double) :: BETAW
            logical(c_bool) :: FRAC_ICE_ADJUST
            real(c_double) :: GAMI
            real(c_double) :: GAMW
            integer(c_int) :: I
            integer(c_int) :: J
            integer(c_int) :: K
            logical(c_bool) :: LAMBDA3
            logical(c_bool) :: LSIGMAS
            logical(c_bool) :: LSTATNW
            logical(c_bool) :: OCND2
            real(c_double) :: RD
            real(c_double) :: RV
            real(c_double) :: TMAXMIX
            real(c_double) :: TMINMIX

        end subroutine c_program_condensation

        subroutine c_dace_exit_condensation(handle, err) bind(c, name='__dace_exit_condensation')
            use, intrinsic :: iso_c_binding, only: c_funptr, c_int
            type(c_funptr), intent(in) :: handle
            integer(c_int), intent(out) :: err
        end subroutine c_dace_exit_condensation

    end interface

end module modi_condensation