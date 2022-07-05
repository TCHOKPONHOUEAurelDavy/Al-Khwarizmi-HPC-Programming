module mod_yeimyg5d8lch_yeimyg5d8lch


  use, intrinsic :: ISO_C_Binding, only : i64 => C_INT64_T , f64 => &
        C_DOUBLE
  implicit none

  contains

  !........................................
  subroutine jacobi(a, b, x, n, eps, stand, iteration) 

    implicit none

    integer(i64), intent(out) :: stand
    integer(i64), intent(out) :: iteration
    real(f64), intent(in) :: a(0:,0:)
    real(f64), intent(in) :: b(0:,0:)
    real(f64), intent(in) :: x(0:)
    integer(i64), value :: n
    real(f64), value :: eps
    real(f64), allocatable :: x_courant(:)
    integer(i64) :: i
    integer(i64) :: j

    !print("Execution of Jacobi in parallel with", nb_tasks, "threads")
    !Jacobi method resolution
    allocate(x_courant(0:n - 1_i64))
    iteration = 0_i64
    do while (1_i64 /= 0)
      iteration = iteration + 1_i64
      !#$ omp parallel
      !#$ omp for
      do i = 0_i64, n - 1_i64, 1_i64
        x_courant(i) = 0.0_f64
        do j = 0_i64, i - 1_i64, 1_i64
          x_courant(i) = x_courant(i) + a(i, j) * x(j)
        end do
        do j = i + 1_i64, n - 1_i64, 1_i64
          x_courant(i) = x_courant(i) + a(i, j) * x(j)
        end do
        x_courant(i) = (b(:, i) - x_courant(i)) / a(i, i)
      end do
      stand = 0_i64
      !__________________CommentBlock__________________!
      !                                                !
      !        # Convergence test                      !
      !        absmax = 0.                             !
      !        #omp for                                !
      !        for i in range(n):                      !
      !            curr = math.fabs(x[i] - x_courant[i])!
      !            if curr > absmax:                   !
      !                absmax = curr                   !
      !        stand = absmax / n                      !
      !        if stand <= eps or iteration > n:       !
      !            break                               !
      !                                                !
      !        # copy x_courant into x                 !
      !        #omp for                                !
      !        for i in range(n):                      !
      !            x [i] = x_courant[i]                !
      !                                                !
      !        #$ omp end parallel                     !
      !                                                !
      !________________________________________________!
      !Convergence test
      !omp for
      !copy x_courant into x
      !omp for
      !$omp end parallel
    end do
    if (allocated(x_courant)) then
      deallocate(x_courant)
    end if
    return

  end subroutine jacobi
  !........................................

end module mod_yeimyg5d8lch_yeimyg5d8lch
