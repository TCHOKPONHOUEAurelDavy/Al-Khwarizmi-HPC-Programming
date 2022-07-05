module mod_u1bcz0f45jwm_u1bcz0f45jwm


  use, intrinsic :: ISO_C_Binding, only : f64 => C_DOUBLE
  implicit none

  contains

  !........................................
  function f(a) result(Out_0001)

    implicit none

    real(f64) :: Out_0001
    real(f64), value :: a

    Out_0001 = 4.0_f64 / (1.0_f64 + a * a)
    return

  end function f
  !........................................

end module mod_u1bcz0f45jwm_u1bcz0f45jwm
