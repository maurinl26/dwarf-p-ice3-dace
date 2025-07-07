! Created by  on 02/07/2025.

module modi_cloud_fraction_2
    use, intrinsic :: iso_c_binding
    implicit none

    interface
        type(c_funptr) function c_dace_init_cloud_fraction_2(I, J, K, SUBG_MF_PDF) bind(c, name='__dace_init_cloud_fraction_2')
            use, intrinsic :: iso_c_binding, only: c_int, c_funptr
            integer(c_int), intent(in) :: I
            integer(c_int), intent(in) :: J
            integer(c_int), intent(in) :: K
            integer(c_int), intent(in) :: SUBG_MF_PDF
        end function c_dace_init_cloud_fraction_2

        subroutine c_program_cloud_fraction_2(handle, cf_mf, cldfr, cph, exnref, hlc_hcf, hlc_hrc, hli_hcf, hli_hri,&
                &ls, lv, rc_mf, rcs1, rhodref, ri_mf, ris1, rvs1, t, ths1,&
                &ACRIAUTI, BCRIAUTI, CRIAUTC, CRIAUTI, I, J, K, LSUBG_COND, SUBG_MF_PDF,&
                &TT,  dt) bind(c, name='__program_cloud_fraction_2')

            use, intrinsic :: iso_c_binding, only: c_funptr, c_ptr, c_float, c_int, c_bool, c_double

            type(c_funptr), value :: handle

            real(c_double) :: cf_mf(*)
            real(c_double) :: cldfr(*)
            real(c_double) :: cph(*)
            real(c_double) :: exnref(*)
            real(c_double) :: hlc_hcf(*)
            real(c_double) :: hlc_hrc(*)
            real(c_double) :: hli_hcf(*)
            real(c_double) :: hli_hri(*)
            real(c_double) :: ls(*)
            real(c_double) :: lv(*)
            real(c_double) :: rc_mf(*)
            real(c_double) :: rcs1(*)
            real(c_double) :: rhodref(*)
            real(c_double) :: ri_mf(*)
            real(c_double) :: ris1(*)
            real(c_double) :: rvs1(*)
            real(c_double) :: t(*)
            real(c_double) :: ths1(*)

            real(c_double), value :: ACRIAUTI
            real(c_double), value :: BCRIAUTI
            real(c_double), value :: CRIAUTC
            real(c_double), value :: CRIAUTI
            integer(c_int), value :: I
            integer(c_int), value :: J
            integer(c_int), value :: K

            logical(c_bool), value :: LSUBG_COND
            integer(c_int), value :: SUBG_MF_PDF
            real(c_double), value :: TT
            real(c_double), value :: dt


        end subroutine c_program_cloud_fraction_2

        subroutine c_dace_exit_cloud_fraction_2(handle, err) bind(c, name='__dace_exit_cloud_fraction_2')
            use, intrinsic :: iso_c_binding, only: c_funptr, c_int
            type(c_funptr), intent(in) :: handle
            integer(c_int), intent(out) :: err
        end subroutine c_dace_exit_cloud_fraction_2

    end interface

end module modi_cloud_fraction_2