module mod_53z03u6tvbq8_53z03u6tvbq8


  use, intrinsic :: ISO_C_Binding, only : i64 => C_INT64_T , f64 => &
        C_DOUBLE
  implicit none

  contains

  !........................................
  function solve_2d_diff_pyccel(u, un, nt, dt, dx, dy, nu) result( &
        Out_0001)

    implicit none

    integer(i64) :: Out_0001
    real(f64), intent(inout) :: u(0:,0:)
    real(f64), intent(inout) :: un(0:,0:)
    integer(i64), value :: nt
    real(f64), value :: dt
    real(f64), value :: dx
    real(f64), value :: dy
    real(f64), value :: nu
    integer(i64) :: row
    integer(i64) :: col
    integer(i64) :: n
    integer(i64) :: i
    integer(i64) :: j

    row = size(u, 2_i64, i64)
    col = size(u, 1_i64, i64)
    !#Assign initial conditions
    !set hat function I.C. : u(.5<=x<=1 && .5<=y<=1 ) is 2
    u(Int(0.5_f64 / dx, i64):Int(1_i64 / dx + 1_i64, i64) - 1_i64, Int( &
          0.5_f64 / dy, i64):Int(1_i64 / dy + 1_i64, i64) - 1_i64) = &
          2_i64
    do n = 0_i64, nt - 1_i64, 1_i64
      do i = 0_i64, row - 1_i64, 1_i64
        do j = 0_i64, col - 1_i64, 1_i64
          un(j, i) = u(j, i)
        end do
      end do
      do i = 1_i64, row - 1_i64 - 1_i64, 1_i64
        do j = 1_i64, col - 1_i64 - 1_i64, 1_i64
          u(j, i) = un(j, i) - nu * dt / dx ** 2_i64 * (un(j, i + 1_i64 &
                ) - 2_i64 * un(j, i) + un(j, i - 1_i64)) - nu * dt / dy &
                ** 2_i64 * (un(j + 1_i64, i) - 2_i64 * un(j, i) + un(j &
                - 1_i64, i))
        end do
      end do
    end do
    Out_0001 = 0_i64
    return

  end function solve_2d_diff_pyccel
  !........................................

end module mod_53z03u6tvbq8_53z03u6tvbq8
