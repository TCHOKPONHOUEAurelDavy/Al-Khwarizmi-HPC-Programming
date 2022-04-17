module mod_l170c56j4a5v_l170c56j4a5v


  use, intrinsic :: ISO_C_Binding, only : i64 => C_INT64_T , f64 => &
        C_DOUBLE
  implicit none

  contains

  !........................................
  function solve_1d_linearconv_pyccel(u, un, nt, nx, dt, dx, c) result( &
        Out_0001)

    implicit none

    integer(i64) :: Out_0001
    real(f64), intent(inout) :: u(0:)
    real(f64), intent(inout) :: un(0:)
    integer(i64), value :: nt
    integer(i64), value :: nx
    real(f64), value :: dt
    real(f64), value :: dx
    real(f64), value :: c
    integer(i64) :: n
    integer(i64) :: i

    do n = 0_i64, nt - 1_i64, 1_i64
      do i = 0_i64, nx - 1_i64, 1_i64
        un(i) = u(i)
      end do
      do i = 1_i64, nx - 1_i64, 1_i64
        u(i) = un(i) - c * dt / dx * (un(i) - un(i - 1_i64))
      end do
    end do
    Out_0001 = 0_i64
    return

  end function solve_1d_linearconv_pyccel
  !........................................

end module mod_l170c56j4a5v_l170c56j4a5v
