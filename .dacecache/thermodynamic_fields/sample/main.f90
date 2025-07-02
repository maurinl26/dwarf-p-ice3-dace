! Created by  on 02/07/2025.

program main

    use modi_thermo
    use, intrinsic :: iso_c_binding

    integer(c_int) :: I, J, K, NRR

    I = 15
    J = 15
    K = 15
    NRR = 6



    handle = c_dace_init_thermodynamic_fields(I, J, K, NRR)

end program main