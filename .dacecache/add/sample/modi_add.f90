! Created by  on 02/07/2025.

module modi_add

    use, intrinsic :: iso_c_binding
    implicit none

    interface
        type(c_funptr) function c_dace_init_add(I, J, K, NRR) bind(c, name='__dace_init_add')
            use, intrinsic :: iso_c_binding, only: c_int, c_funptr
            integer(c_int), intent(in) :: I
            integer(c_int), intent(in) :: J
            integer(c_int), intent(in) :: K
        end function c_dace_init_add

        subroutine c_program_add(handle, a, b, c, I, J, K) bind(c, name='__program_add')

            use, intrinsic :: iso_c_binding, only: c_funptr, c_ptr, c_float, c_int, c_bool, c_double

            type(c_funptr), value :: handle

            real(c_double) :: a(*)
            real(c_double) :: b(*)
            real(c_double) :: c(*)

            integer(c_int), value:: I
            integer(c_int), value :: J
            integer(c_int), value :: K

        end subroutine c_program_add

        subroutine c_dace_exit_add(handle, err) bind(c, name='__dace_exit_add')
            use, intrinsic :: iso_c_binding, only: c_funptr, c_int
            type(c_funptr), intent(in) :: handle
            integer(c_int), intent(out) :: err
        end subroutine c_dace_exit_add

    end interface

end module modi_add