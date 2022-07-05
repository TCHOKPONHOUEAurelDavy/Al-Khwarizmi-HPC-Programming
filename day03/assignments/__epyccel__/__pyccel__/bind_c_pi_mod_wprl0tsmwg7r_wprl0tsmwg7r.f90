module bind_c_pi_mod_wprl0tsmwg7r_wprl0tsmwg7r

  use pi_mod_wprl0tsmwg7r_wprl0tsmwg7r, only: f
  use pi_mod_wprl0tsmwg7r_wprl0tsmwg7r, only: pi

  use, intrinsic :: ISO_C_Binding, only : i64 => C_INT64_T , f64 => &
        C_DOUBLE
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

end module bind_c_pi_mod_wprl0tsmwg7r_wprl0tsmwg7r
