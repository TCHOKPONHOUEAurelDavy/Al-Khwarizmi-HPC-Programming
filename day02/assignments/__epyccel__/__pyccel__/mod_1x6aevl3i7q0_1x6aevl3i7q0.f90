module mod_1x6aevl3i7q0_1x6aevl3i7q0


  use, intrinsic :: ISO_C_Binding, only : i64 => C_INT64_T
  implicit none

  contains

  !........................................
  recursive function factorial(n) result(Out_0001)

    implicit none

    integer(i64) :: Out_0001
    integer(i64), value :: n

    if (n == 1_i64 .or. n == 0_i64) then
      Out_0001 = 1_i64
      return
    end if
    Out_0001 = n * factorial(n - 1_i64)
    return

  end function factorial
  !........................................

end module mod_1x6aevl3i7q0_1x6aevl3i7q0
