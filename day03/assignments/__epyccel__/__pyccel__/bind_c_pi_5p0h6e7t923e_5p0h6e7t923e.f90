module bind_c_pi_5p0h6e7t923e_5p0h6e7t923e

  use pi_5p0h6e7t923e_5p0h6e7t923e, only: f
  use pi_5p0h6e7t923e_5p0h6e7t923e, only: pi

  use, intrinsic :: ISO_C_Binding, only : f64 => C_DOUBLE , i64 => &
        C_INT64_T
  implicit none

  contains

  !........................................
  function bind_c_f(a) bind(c) result(Out_0001)

    implicit none

    real(f64), value :: a
    real(f64) :: Out_0001

    Out_0001 = f(a)

  end function bind_c_f
  !........................................

  !........................................
  function bind_c_pi(n, h) bind(c) result(Pi_calc)

    implicit none

    integer(i64), value :: n
    real(f64), value :: h
    real(f64) :: Pi_calc

    Pi_calc = pi(n, h)

  end function bind_c_pi
  !........................................

end module bind_c_pi_5p0h6e7t923e_5p0h6e7t923e
