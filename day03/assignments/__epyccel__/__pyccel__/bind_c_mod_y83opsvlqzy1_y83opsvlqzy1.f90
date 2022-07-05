module bind_c_mod_y83opsvlqzy1_y83opsvlqzy1

  use mod_y83opsvlqzy1_y83opsvlqzy1, only: jacobi

  use, intrinsic :: ISO_C_Binding, only : i64 => C_INT64_T , f64 => &
        C_DOUBLE
  implicit none

  contains

  !........................................
  subroutine bind_c_jacobi(n0_a, n1_a, a, n0_b, n1_b, b, n0_x, x, n, eps &
        , stand, iteration) bind(c)

    implicit none

    integer(i64), value :: n0_a
    integer(i64), value :: n1_a
    real(f64), intent(in) :: a(0:n1_a - 1_i64,0:n0_a - 1_i64)
    integer(i64), value :: n0_b
    integer(i64), value :: n1_b
    real(f64), intent(in) :: b(0:n1_b - 1_i64,0:n0_b - 1_i64)
    integer(i64), value :: n0_x
    real(f64), intent(in) :: x(0:n0_x - 1_i64)
    integer(i64), value :: n
    real(f64), value :: eps
    integer(i64), intent(out) :: stand
    integer(i64), intent(out) :: iteration

    call jacobi(a, b, x, n, eps, stand = stand, iteration = iteration)

  end subroutine bind_c_jacobi
  !........................................

end module bind_c_mod_y83opsvlqzy1_y83opsvlqzy1
