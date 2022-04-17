module mod_eks4nudaput0_eks4nudaput0


  use, intrinsic :: ISO_C_Binding, only : f64 => C_DOUBLE , i64 => &
        C_INT64_T
  implicit none

  contains

  !........................................
  function solve_1d_diff_pyccel(u, un, nt, nx, dt, dx, nu) result( &
        Out_0001)

    implicit none

    integer(i64) :: Out_0001
    real(f64), intent(inout) :: u(0:)
    real(f64), intent(inout) :: un(0:)
    integer(i64), value :: nt
    integer(i64), value :: nx
    real(f64), value :: dt
    real(f64), value :: dx
    real(f64), value :: nu
    integer(i64) :: n
    integer(i64) :: i

    do n = 0_i64, nt - 1_i64, 1_i64
      do i = 0_i64, nx - 1_i64, 1_i64
        un(i) = u(i)
      end do
      do i = 1_i64, nx - 1_i64 - 1_i64, 1_i64
        u(i) = un(i) - nu * (dt / dx ** 2_i64) * (un(i + 1_i64) - 2_i64 &
              * un(i) + un(i - 1_i64))
      end do
    end do
    Out_0001 = 0_i64
    return

  end function solve_1d_diff_pyccel
  !........................................

end module mod_eks4nudaput0_eks4nudaput0
