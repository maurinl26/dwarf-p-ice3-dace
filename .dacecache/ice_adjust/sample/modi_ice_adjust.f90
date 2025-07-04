! Created by  on 27/06/2025.

module modi_ice_adjust

    use, intrinsic :: iso_c_binding
    implicit none

    interface
        type(c_funptr) function c_dace_init_ice_adjust(I, J, K) bind(c, name='__dace_init_ice_adjust')
            use, intrinsic :: iso_c_binding, only: c_int, c_funptr
            integer(c_int), intent(in) :: I
            integer(c_int), intent(in) :: J
            integer(c_int), intent(in) :: K
        end function c_dace_init_ice_adjust

        subroutine c_program_ice_adjust(handle, cf_mf, cldfr, exn, hlc_hcf, hlc_hrc, hli_hcf,&
                &hli_hri, pabs, rc0, rc_mf, rcs0, rcs1, rg0, rhodref, ri0, ri_mf, ris0, ris1, rr0, rs0, rv0, rvs0,&
                &rvs1, sigqsat, sigrc, sigs, th0, ths0, ths1, ACRIAUTI, ALPI, ALPW, BCRIAUTI,  BETAI,  BETAW,&
                &CI, CL, CPD, CPV, CRIAUTC, CRIAUTI, FRAC_ICE_ADJUST, GAMI, GAMW, I, J, K, LAMBDA3, LSIGMAS,&
                &LSTATNW, LSTT, LSUBG_COND, LVTT, NRR, OCND2, RD, RV, SUBG_MF_PDF, TMAXMIX, TMINMIX, TT,&
                &dt) bind(c, name='__program_ice_adjust')

            use, intrinsic :: iso_c_binding, only: c_funptr, c_ptr, c_float, c_int, c_bool, c_double

            type(c_funptr), intent(in) :: handle
            integer(c_int), intent(in) :: I
            integer(c_int), intent(in) :: J
            integer(c_int), intent(in) :: K

            real(c_double), dimension(I, J, K), intent(in) :: cf_mf
            real(c_double), dimension(I, J, K), intent(in) :: cldfr
            real(c_double), dimension(I, J, K), intent(in) :: exn
            real(c_double), dimension(I, J, K), intent(in) :: hlc_hcf
            real(c_double), dimension(I, J, K), intent(in) :: hlc_hrc
            real(c_double), dimension(I, J, K), intent(in) :: hli_hcf
            real(c_double), dimension(I, J, K), intent(in) :: hli_hri
            real(c_double), dimension(I, J, K), intent(in) :: pabs
            real(c_double), dimension(I, J, K), intent(in) :: rc0
            real(c_double), dimension(I, J, K), intent(in) :: rc_mf
            real(c_double), dimension(I, J, K), intent(in) :: rcs0
            real(c_double), dimension(I, J, K), intent(in) :: rcs1
            real(c_double), dimension(I, J, K), intent(in) :: rg0
            real(c_double), dimension(I, J, K), intent(in) :: rhodref
            real(c_double), dimension(I, J, K), intent(in) :: ri0
            real(c_double), dimension(I, J, K), intent(in) :: ri_mf
            real(c_double), dimension(I, J, K), intent(in) :: ris0
            real(c_double), dimension(I, J, K), intent(in) :: ris1
            real(c_double), dimension(I, J, K), intent(in) :: rr0
            real(c_double), dimension(I, J, K), intent(in) :: rs0
            real(c_double), dimension(I, J, K), intent(in) :: rv0
            real(c_double), dimension(I, J, K), intent(in) :: rvs0
            real(c_double), dimension(I, J, K), intent(in) :: rvs1
            real(c_double), dimension(I, J, K), intent(in) :: sigqsat
            real(c_double), dimension(I, J, K), intent(in) :: sigrc
            real(c_double), dimension(I, J, K), intent(in) :: sigs
            real(c_double), dimension(I, J, K), intent(in) :: th0
            real(c_double), dimension(I, J, K), intent(in) :: ths0
            real(c_double), dimension(I, J, K), intent(in) :: ths1

            real(c_double), intent(in):: ACRIAUTI
            real(c_double), intent(in):: ALPI
            real(c_double), intent(in):: ALPW
            real(c_double), intent(in):: BCRIAUTI
            real(c_double), intent(in):: BETAI
            real(c_double), intent(in):: BETAW
            real(c_double), intent(in):: CI
            real(c_double), intent(in):: CL
            real(c_double), intent(in):: CPD
            real(c_double), intent(in):: CPV
            real(c_double), intent(in):: CRIAUTC
            real(c_double), intent(in):: CRIAUTI
            logical(c_bool), intent(in):: FRAC_ICE_ADJUST
            real(c_double), intent(in):: GAMI
            real(c_double), intent(in):: GAMW
            logical(c_bool), intent(in):: LAMBDA3
            logical(c_bool), intent(in):: LSIGMAS
            logical(c_bool), intent(in):: LSTATNW
            real(c_double), intent(in):: LSTT
            logical(c_bool), intent(in):: LSUBG_COND
            real(c_double), intent(in)::  LVTT
            integer(c_int), intent(in):: NRR
            logical(c_bool), intent(in):: OCND2
            real(c_double), intent(in):: RD
            real(c_double), intent(in):: RV
            integer(c_int), intent(in):: SUBG_MF_PDF
            real(c_double), intent(in):: TMAXMIX
            real(c_double), intent(in):: TMINMIX
            real(c_double), intent(in):: TT
            real(c_double), intent(in):: dt
        end subroutine c_program_ice_adjust

        subroutine c_dace_exit_ice_adjust(handle, err) bind(c, name='__dace_exit_ice_adjust')
            use, intrinsic :: iso_c_binding, only: c_funptr, c_int
            type(c_funptr), intent(in) :: handle
            integer(c_int), intent(out) :: err
        end subroutine c_dace_exit_ice_adjust

    end interface

end module modi_ice_adjust