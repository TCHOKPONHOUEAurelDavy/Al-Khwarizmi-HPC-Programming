module bind_c_mod_u1bcz0f45jwm_u1bcz0f45jwm

  use mod_u1bcz0f45jwm_u1bcz0f45jwm, only: f

  use, intrinsic :: ISO_C_Binding, only : f64 => C_DOUBLE
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

end module bind_c_mod_u1bcz0f45jwm_u1bcz0f45jwm
