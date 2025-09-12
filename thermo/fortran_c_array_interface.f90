! Fortran-C Array Interface Module
! This module provides utilities to pass Fortran arrays to C restricted pointers
! Created for dwarf-p-ice3-dace project

module fortran_c_array_interface
    use, intrinsic :: iso_c_binding
    implicit none

    ! Generic interface for array conversion
    interface fortran_to_c_ptr
        module procedure :: real64_1d_to_c_ptr
        module procedure :: real64_2d_to_c_ptr
        module procedure :: real64_3d_to_c_ptr
        module procedure :: real32_1d_to_c_ptr
        module procedure :: real32_2d_to_c_ptr
        module procedure :: real32_3d_to_c_ptr
        module procedure :: int32_1d_to_c_ptr
        module procedure :: int32_2d_to_c_ptr
        module procedure :: int32_3d_to_c_ptr
    end interface fortran_to_c_ptr

contains

    ! Convert 1D real64 array to C pointer
    function real64_1d_to_c_ptr(fortran_array) result(c_ptr_result)
        real(c_double), target, intent(in) :: fortran_array(:)
        type(c_ptr) :: c_ptr_result
        
        if (size(fortran_array) > 0) then
            c_ptr_result = c_loc(fortran_array(1))
        else
            c_ptr_result = c_null_ptr
        endif
    end function real64_1d_to_c_ptr

    ! Convert 2D real64 array to C pointer
    function real64_2d_to_c_ptr(fortran_array) result(c_ptr_result)
        real(c_double), target, intent(in) :: fortran_array(:,:)
        type(c_ptr) :: c_ptr_result
        
        if (size(fortran_array) > 0) then
            c_ptr_result = c_loc(fortran_array(1,1))
        else
            c_ptr_result = c_null_ptr
        endif
    end function real64_2d_to_c_ptr

    ! Convert 3D real64 array to C pointer
    function real64_3d_to_c_ptr(fortran_array) result(c_ptr_result)
        real(c_double), target, intent(in) :: fortran_array(:,:,:)
        type(c_ptr) :: c_ptr_result
        
        if (size(fortran_array) > 0) then
            c_ptr_result = c_loc(fortran_array(1,1,1))
        else
            c_ptr_result = c_null_ptr
        endif
    end function real64_3d_to_c_ptr

    ! Convert 1D real32 array to C pointer
    function real32_1d_to_c_ptr(fortran_array) result(c_ptr_result)
        real(c_float), target, intent(in) :: fortran_array(:)
        type(c_ptr) :: c_ptr_result
        
        if (size(fortran_array) > 0) then
            c_ptr_result = c_loc(fortran_array(1))
        else
            c_ptr_result = c_null_ptr
        endif
    end function real32_1d_to_c_ptr

    ! Convert 2D real32 array to C pointer
    function real32_2d_to_c_ptr(fortran_array) result(c_ptr_result)
        real(c_float), target, intent(in) :: fortran_array(:,:)
        type(c_ptr) :: c_ptr_result
        
        if (size(fortran_array) > 0) then
            c_ptr_result = c_loc(fortran_array(1,1))
        else
            c_ptr_result = c_null_ptr
        endif
    end function real32_2d_to_c_ptr

    ! Convert 3D real32 array to C pointer
    function real32_3d_to_c_ptr(fortran_array) result(c_ptr_result)
        real(c_float), target, intent(in) :: fortran_array(:,:,:)
        type(c_ptr) :: c_ptr_result
        
        if (size(fortran_array) > 0) then
            c_ptr_result = c_loc(fortran_array(1,1,1))
        else
            c_ptr_result = c_null_ptr
        endif
    end function real32_3d_to_c_ptr

    ! Convert 1D int32 array to C pointer
    function int32_1d_to_c_ptr(fortran_array) result(c_ptr_result)
        integer(c_int), target, intent(in) :: fortran_array(:)
        type(c_ptr) :: c_ptr_result
        
        if (size(fortran_array) > 0) then
            c_ptr_result = c_loc(fortran_array(1))
        else
            c_ptr_result = c_null_ptr
        endif
    end function int32_1d_to_c_ptr

    ! Convert 2D int32 array to C pointer
    function int32_2d_to_c_ptr(fortran_array) result(c_ptr_result)
        integer(c_int), target, intent(in) :: fortran_array(:,:)
        type(c_ptr) :: c_ptr_result
        
        if (size(fortran_array) > 0) then
            c_ptr_result = c_loc(fortran_array(1,1))
        else
            c_ptr_result = c_null_ptr
        endif
    end function int32_2d_to_c_ptr

    ! Convert 3D int32 array to C pointer
    function int32_3d_to_c_ptr(fortran_array) result(c_ptr_result)
        integer(c_int), target, intent(in) :: fortran_array(:,:,:)
        type(c_ptr) :: c_ptr_result
        
        if (size(fortran_array) > 0) then
            c_ptr_result = c_loc(fortran_array(1,1,1))
        else
            c_ptr_result = c_null_ptr
        endif
    end function int32_3d_to_c_ptr

end module fortran_c_array_interface
