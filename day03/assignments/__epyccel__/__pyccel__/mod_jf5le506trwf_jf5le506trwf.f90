module mod_jf5le506trwf_jf5le506trwf


  use, intrinsic :: ISO_C_Binding, only : f64 => C_DOUBLE , i64 => &
        C_INT64_T
  implicit none

  contains

  !........................................
  subroutine jacobi(a, b, x, n, eps, stand, iteration) 

    implicit none

    real(f64), intent(out) :: stand
    integer(i64), intent(out) :: iteration
    real(f64), intent(in) :: a(0:,0:)
    real(f64), intent(in) :: b(0:)
    real(f64), intent(inout) :: x(0:)
    integer(i64), value :: n
    real(f64), value :: eps
    real(f64), allocatable :: x_courant(:)
    integer(i64) :: i
    integer(i64) :: j
    real(f64) :: absmax
    real(f64) :: curr

    !print("Execution of Jacobi in parallel with", nb_tasks, "threads")
    !Jacobi method resolution
    allocate(x_courant(0:n - 1_i64))
    iteration = 0_i64
    !$omp parallel
    do while (1_i64 /= 0)
      iteration = iteration + 1_i64
      !$omp do
      do i = 0_i64, n - 1_i64, 1_i64
        x_courant(i) = 0.0_f64
        do j = 0_i64, i - 1_i64, 1_i64
          x_courant(i) = x_courant(i) + a(i, j) * x(j)
        end do
        do j = i + 1_i64, n - 1_i64, 1_i64
          x_courant(i) = x_courant(i) + a(i, j) * x(j)
        end do
        x_courant(i) = (b(i) - x_courant(i)) / a(i, i)
      end do
      !$omp end do
      !Convergence test
      absmax = 0.0_f64
      !omp for
      do i = 0_i64, n - 1_i64, 1_i64
        curr = abs(x(i) - x_courant(i))
        if (curr > absmax) then
          absmax = curr
        end if
      end do
      stand = absmax / n
      if (stand <= eps .or. iteration > n) then
        exit
      end if
      !copy x_courant into
      !omp for
      do i = 0_i64, n - 1_i64, 1_i64
        x(i) = x_courant(i)
      end do
    end do
    !$omp end parallel
    if (allocated(x_courant)) then
      deallocate(x_courant)
    end if
    return

  end subroutine jacobi
  !........................................

end module mod_jf5le506trwf_jf5le506trwf
