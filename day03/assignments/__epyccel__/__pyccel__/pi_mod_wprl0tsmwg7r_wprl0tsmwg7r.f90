module pi_mod_wprl0tsmwg7r_wprl0tsmwg7r


  use, intrinsic :: ISO_C_Binding, only : i64 => C_INT64_T , f64 => &
        C_DOUBLE
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

  !........................................
  function pi(n, h) result(Pi_calc)

    implicit none

    real(f64) :: Pi_calc
    integer(i64), value :: n
    real(f64), value :: h
    integer(i64) :: k
    integer(i64) :: i
    real(f64) :: x

    !print("Execution of PI in parallel with", nb_tasks,"threads")
    !#$ omp parallel
    !#$ omp for
    do k = 0_i64, 99_i64, 1_i64
      Pi_calc = 0.0_f64
      do i = 0_i64, n - 1_i64, 1_i64
        x = h * (i + 0.5_f64)
        Pi_calc = Pi_calc + f(x)
      end do
      Pi_calc = h * Pi_calc
    end do
    !# omp end parallel
    return

  end function pi
  !........................................

end module pi_mod_wprl0tsmwg7r_wprl0tsmwg7r
