! Created by  on 20/05/2025.

module add_main
    use, intrinsic :: iso_c_binding
    implicit none

    include '../include/add.h'

    interface

         type(c_funptr) function __dace_init_add(I, J, K) bind(c, name='__dace_init_add')
            use, intrinsic :: iso_c_binding, only: c_int
            integer(c_int), intent(in) :: I
            integer(c_int), intent(in) :: J
            integer(c_int), intent(in) :: K
        end function __dace_init_add

        pure function __program_add(handle, __return, a, b, I, J, K) bind(c, name='__program_add')
            use, intrinsic :: iso_c_binding, only: c_funptr, c_ptr, c_float, c_int
            type(c_funptr), intent(in) :: handle
            real(c_ptr), intent(in) :: __return
            real(c_ptr), intent(in) :: a
            real(c_ptr), intent(in) :: b
            integer(c_int), value :: I
            integer(c_int), value :: J
            integer(c_int), value :: K
        end function __program_add

        integer(c_int) function __dace_exit_add(handle) bind(c, name='__dace_exit_add')
            use, intrinsic :: iso_c_binding, only: c_funptr
            type(c_funptr), intent(in) :: handle
        end function __dace_exit_add

    end interface

contains



end module add_main