! Created by  on 02/07/2025.

program main

    use modi_cloud_fraction_2
    use, intrinsic :: iso_c_binding

    integer(c_int) :: I, J, K, SUBG_MF_PDF
    type(c_funptr) :: handle

    real(c_double), allocatable :: cf_mf(:,:,:)
    real(c_double), allocatable :: cldfr(:,:,:)
    real(c_double), allocatable :: cph(:,:,:)
    real(c_double), allocatable :: exnref(:,:,:)
    real(c_double), allocatable :: hlc_hcf(:,:,:)
    real(c_double), allocatable :: hlc_hrc(:,:,:)
    real(c_double), allocatable :: hli_hcf(:,:,:)
    real(c_double), allocatable :: hli_hri(:,:,:)
    real(c_double), allocatable :: ls(:,:,:)
    real(c_double), allocatable :: lv(:,:,:)
    real(c_double), allocatable :: rc_mf(:,:,:)
    real(c_double), allocatable :: rcs1(:,:,:)
    real(c_double), allocatable :: rhodref(:,:,:)
    real(c_double), allocatable :: ri_mf(:,:,:)
    real(c_double), allocatable :: ris1(:,:,:)
    real(c_double), allocatable :: rvs1(:,:,:)
    real(c_double), allocatable :: t(:,:,:)
    real(c_double), allocatable :: ths1(:,:,:)

    real(c_double) :: ACRIAUTI = 1.0
    real(c_double) :: BCRIAUTI = 1.0
    real(c_double) :: CRIAUTC = 1.0
    real(c_double) :: CRIAUTI = 1.0

    logical(c_bool) :: LSUBG_COND = .TRUE.
    real(c_double) :: TT = 1.0
    real(c_double) :: dt = 50.0

    I = 15
    J = 15
    K = 15
    SUBG_MF_PDF = 0

    allocate(cf_mf(I, J, K))
    allocate(cldfr(I, J, K))
    allocate(cph(I, J, K))
    allocate(exnref(I, J, K))
    allocate(hlc_hcf(I, J, K))
    allocate(hlc_hrc(I, J, K))
    allocate(hli_hcf(I, J, K))
    allocate(hli_hri(I, J, K))
    allocate(ls(I, J, K))
    allocate(lv(I, J, K))
    allocate(rc_mf(I, J, K))
    allocate(rcs1(I, J, K))
    allocate(rhodref(I, J, K))
    allocate(ri_mf(I, J, K))
    allocate(ris1(I, J, K))
    allocate(rvs1(I, J, K))
    allocate(t(I, J, K))
    allocate(ths1(I, J, K))

    handle = c_dace_init_cloud_fraction_2(I, J, K, SUBG_MF_PDF)

    call c_program_cloud_fraction_2(handle, cf_mf, cldfr, cph, exnref, hlc_hcf, hlc_hrc, hli_hcf, hli_hri,&
            &ls, lv, rc_mf, rcs1, rhodref, ri_mf, ris1, rvs1, t, ths1,&
            &ACRIAUTI, BCRIAUTI, CRIAUTC, CRIAUTI, I, J, K, LSUBG_COND, SUBG_MF_PDF,&
            &TT,  dt)

    print *, "hlc_hrc :", sum(hlc_hrc)/(I * J * K)
    print *, "hlc_hcf :", sum(hlc_hcf)/(I * J * K)
    print *, "hli_hri :", sum(hli_hri)/(I * J * K)
    print *, "hli_hcf :", sum(hli_hcf)/(I * J * K)

end program main