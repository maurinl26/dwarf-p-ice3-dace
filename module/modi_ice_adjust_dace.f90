! Created by  on 27/06/2025.

module modi_ice_adjust_dace

    use, intrinsic :: iso_c_binding
    implicit none

    interface
        type(c_funptr) function c_dace_init_ice_adjust(IJ,&
            &K) bind(c, name='__dace_init_ice3_components_ice_adjust_split_ice_adjust')
            use, intrinsic :: iso_c_binding, only: c_int, c_funptr
            integer(c_int) :: IJ
            integer(c_int) :: K
        end function c_dace_init_ice_adjust

        subroutine c_program_ice_adjust(handle, cldfr, exn, pabs, rc0, rcs0, rcs1, rg0,&
                &ri0, ris0, ris1, rr0, rs0, rv0, rvs0, rvs1,&
                &sigqsat, sigrc, sigs, th0, ths0, ths1,&
                &ALPI, ALPW, BETAI, BETAW, CI, CL, CPD, CPV, GAMI, GAMW,&
                &IJ, K, LSIGMAS, LSTATNW, LSTT, LVTT, OCND2, RD, RV, TMAXMIX,&
                &TMINMIX, TT, dt) bind(c, name='__program_ice3_components_ice_adjust_split_ice_adjust')

            use, intrinsic :: iso_c_binding

            type(c_funptr), value :: handle
            integer(c_int) :: IJ
            integer(c_int) :: K

            type(c_ptr), value :: cldfr
            type(c_ptr), value :: exn
            type(c_ptr), value :: pabs
            type(c_ptr), value :: rc0
            type(c_ptr), value :: rcs0
            type(c_ptr), value :: rcs1
            type(c_ptr), value :: rg0
            type(c_ptr), value :: ri0
            type(c_ptr), value :: ris0
            type(c_ptr), value :: ris1
            type(c_ptr), value :: rr0
            type(c_ptr), value :: rs0
            type(c_ptr), value :: rv0
            type(c_ptr), value :: rvs0
            type(c_ptr), value :: rvs1
            type(c_ptr), value :: sigqsat
            type(c_ptr), value :: sigrc
            type(c_ptr), value :: sigs
            type(c_ptr), value :: th0
            type(c_ptr), value :: ths0
            type(c_ptr), value :: ths1

            real(c_double) :: ALPI
            real(c_double) :: ALPW
            real(c_double) :: BETAI
            real(c_double) :: BETAW
            real(c_double) :: CI
            real(c_double) :: CL
            real(c_double) :: CPD
            real(c_double) :: CPV
            real(c_double) :: GAMI
            real(c_double) :: GAMW
            logical(c_bool) :: LSIGMAS
            logical(c_bool) :: LSTATNW
            real(c_double) :: LSTT
            real(c_double) ::  LVTT
            integer(c_int) :: NRR
            logical(c_bool) :: OCND2
            real(c_double) :: RD
            real(c_double) :: RV
            real(c_double) :: TMAXMIX
            real(c_double) :: TMINMIX
            real(c_double) :: TT
            real(c_double) :: dt
        end subroutine c_program_ice_adjust

        subroutine c_dace_exit_ice_adjust(handle, err) bind(c, name='__dace_exit_ice3_components_ice_adjust_split_ice_adjust')
            use, intrinsic :: iso_c_binding, only: c_funptr, c_int
            type(c_funptr) :: handle
            integer(c_int) :: err
        end subroutine c_dace_exit_ice_adjust

    end interface

end module modi_ice_adjust_dace