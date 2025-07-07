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
            integer(c_int), value :: I
            integer(c_int), value :: J
            integer(c_int), value :: K

            real(c_double):: cf_mf(*)
            real(c_double):: cldfr(*)
            real(c_double):: exn(*)
            real(c_double):: hlc_hcf(*)
            real(c_double):: hlc_hrc(*)
            real(c_double):: hli_hcf(*)
            real(c_double):: hli_hri(*)
            real(c_double):: pabs(*)
            real(c_double):: rc0(*)
            real(c_double):: rc_mf(*)
            real(c_double):: rcs0(*)
            real(c_double):: rcs1(*)
            real(c_double):: rg0(*)
            real(c_double):: rhodref(*)
            real(c_double):: ri0(*)
            real(c_double):: ri_mf(*)
            real(c_double):: ris0(*)
            real(c_double):: ris1(*)
            real(c_double):: rr0(*)
            real(c_double):: rs0(*)
            real(c_double):: rv0(*)
            real(c_double):: rvs0(*)
            real(c_double):: rvs1(*)
            real(c_double):: sigqsat(*)
            real(c_double):: sigrc(*)
            real(c_double):: sigs(*)
            real(c_double):: th0(*)
            real(c_double):: ths0(*)
            real(c_double):: ths1(*)

            real(c_double), value:: ACRIAUTI
            real(c_double), value:: ALPI
            real(c_double), value:: ALPW
            real(c_double), value:: BCRIAUTI
            real(c_double), value:: BETAI
            real(c_double), value:: BETAW
            real(c_double), value:: CI
            real(c_double), value:: CL
            real(c_double), value:: CPD
            real(c_double), value:: CPV
            real(c_double), value:: CRIAUTC
            real(c_double), value:: CRIAUTI
            logical(c_bool), value:: FRAC_ICE_ADJUST
            real(c_double), value:: GAMI
            real(c_double), value:: GAMW
            logical(c_bool), value:: LAMBDA3
            logical(c_bool), value:: LSIGMAS
            logical(c_bool), value:: LSTATNW
            real(c_double), value:: LSTT
            logical(c_bool), value:: LSUBG_COND
            real(c_double), value::  LVTT
            integer(c_int), value:: NRR
            logical(c_bool), value:: OCND2
            real(c_double), value:: RD
            real(c_double), value:: RV
            integer(c_int), value:: SUBG_MF_PDF
            real(c_double), value:: TMAXMIX
            real(c_double), value:: TMINMIX
            real(c_double), value:: TT
            real(c_double), value:: dt
        end subroutine c_program_ice_adjust

        subroutine c_dace_exit_ice_adjust(handle, err) bind(c, name='__dace_exit_ice_adjust')
            use, intrinsic :: iso_c_binding, only: c_funptr, c_int
            type(c_funptr), intent(in) :: handle
            integer(c_int), intent(out) :: err
        end subroutine c_dace_exit_ice_adjust

    end interface

end module modi_ice_adjust