module mod_f67q85028ed2_f67q85028ed2


  use, intrinsic :: ISO_C_Binding, only : i64 => C_INT64_T , f64 => &
        C_DOUBLE
  implicit none

  contains

  !........................................
  function solve_2d_poisson_pyccel(p, pd, b, nx, ny, nt, dx, dy) result( &
        Out_0001)

    implicit none

    integer(i64) :: Out_0001
    real(f64), intent(inout) :: p(0:,0:)
    real(f64), intent(inout) :: pd(0:,0:)
    real(f64), intent(inout) :: b(0:,0:)
    integer(i64), value :: nx
    integer(i64), value :: ny
    integer(i64), value :: nt
    real(f64), value :: dx
    real(f64), value :: dy
    integer(i64) :: row
    integer(i64) :: col
    integer(i64) :: it
    integer(i64) :: i
    integer(i64) :: j

    row = size(p, 2_i64, i64)
    col = size(p, 1_i64, i64)
    !Source
    b(Int(Real(nx, f64) / 4.0_f64, i64), Int(Real(ny, f64) / 4.0_f64, &
          i64)) = 100_i64
    b(Int(Real(3_i64 * nx, f64) / 4.0_f64, i64), Int(Real(3_i64 * ny, &
          f64) / 4.0_f64, i64)) = -100_i64
    do it = 0_i64, nt - 1_i64, 1_i64
      do i = 0_i64, nx - 1_i64, 1_i64
        pd(:, i) = p(:, i)
      end do
      do j = 2_i64, row - 1_i64, 1_i64
        do i = 2_i64, col - 1_i64, 1_i64
          p(i - 1_i64, j - 1_i64) = ((pd(i, j - 1_i64) + pd(i - 2_i64, j &
                - 1_i64)) * dy ** 2_i64 + (pd(i - 1_i64, j) + pd(i - &
                1_i64, j - 2_i64)) * dx ** 2_i64 - b(i - 1_i64, j - &
                1_i64) * dx ** 2_i64 * dy ** 2_i64) / (2_i64 * (dx ** &
                2_i64 + dy ** 2_i64))
        end do
      end do
      p(:, 0_i64) = 0_i64
      p(:, ny - 1_i64) = 0_i64
      p(0_i64, :) = 0_i64
      p(nx - 1_i64, :) = 0_i64
    end do
    Out_0001 = 0_i64
    return

  end function solve_2d_poisson_pyccel
  !........................................

end module mod_f67q85028ed2_f67q85028ed2
